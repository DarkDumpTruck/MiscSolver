#include <algorithm>
#include <atomic>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

#pragma warning(disable : 6031)

using namespace std;

namespace GuessPlane {

const double eps = 1e-8;
const int N = 10;
const int PLANE = 3;
#define pos(i, j) ((i) * N + (j))

typedef bitset<N * N> board;
typedef int action;
typedef vector<pair<double, action>> mixed_action;

board masks[N * N][4] = {};
bool valid[N * N][4] = {};

void init_masks() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // dir 0: left
      if (i >= 2 && i < N - 2 && j <= N - 4) {
        valid[pos(i, j)][0] = true;
        masks[pos(i, j)][0].set(pos(i, j), true);
        masks[pos(i, j)][0].set(pos(i - 2, j + 1), true);
        masks[pos(i, j)][0].set(pos(i - 1, j + 1), true);
        masks[pos(i, j)][0].set(pos(i, j + 1), true);
        masks[pos(i, j)][0].set(pos(i + 1, j + 1), true);
        masks[pos(i, j)][0].set(pos(i + 2, j + 1), true);
        masks[pos(i, j)][0].set(pos(i, j + 2), true);
        masks[pos(i, j)][0].set(pos(i - 1, j + 3), true);
        masks[pos(i, j)][0].set(pos(i, j + 3), true);
        masks[pos(i, j)][0].set(pos(i + 1, j + 3), true);
      }
      // dir 1: right
      if (i >= 2 && i < N - 2 && j >= 3) {
        valid[pos(i, j)][1] = true;
        masks[pos(i, j)][1].set(pos(i, j), true);
        masks[pos(i, j)][1].set(pos(i - 2, j - 1), true);
        masks[pos(i, j)][1].set(pos(i - 1, j - 1), true);
        masks[pos(i, j)][1].set(pos(i, j - 1), true);
        masks[pos(i, j)][1].set(pos(i + 1, j - 1), true);
        masks[pos(i, j)][1].set(pos(i + 2, j - 1), true);
        masks[pos(i, j)][1].set(pos(i, j - 2), true);
        masks[pos(i, j)][1].set(pos(i - 1, j - 3), true);
        masks[pos(i, j)][1].set(pos(i, j - 3), true);
        masks[pos(i, j)][1].set(pos(i + 1, j - 3), true);
      }
      // dir 2: down
      if (j >= 2 && j < N - 2 && i >= 3) {
        valid[pos(i, j)][2] = true;
        masks[pos(i, j)][2].set(pos(i, j), true);
        masks[pos(i, j)][2].set(pos(i - 1, j - 2), true);
        masks[pos(i, j)][2].set(pos(i - 1, j - 1), true);
        masks[pos(i, j)][2].set(pos(i - 1, j), true);
        masks[pos(i, j)][2].set(pos(i - 1, j + 1), true);
        masks[pos(i, j)][2].set(pos(i - 1, j + 2), true);
        masks[pos(i, j)][2].set(pos(i - 2, j), true);
        masks[pos(i, j)][2].set(pos(i - 3, j - 1), true);
        masks[pos(i, j)][2].set(pos(i - 3, j), true);
        masks[pos(i, j)][2].set(pos(i - 3, j + 1), true);
      }
      // dir 3: up
      if (j >= 2 && j < N - 2 && i <= N - 4) {
        valid[pos(i, j)][3] = true;
        masks[pos(i, j)][3].set(pos(i, j), true);
        masks[pos(i, j)][3].set(pos(i + 1, j - 2), true);
        masks[pos(i, j)][3].set(pos(i + 1, j - 1), true);
        masks[pos(i, j)][3].set(pos(i + 1, j), true);
        masks[pos(i, j)][3].set(pos(i + 1, j + 1), true);
        masks[pos(i, j)][3].set(pos(i + 1, j + 2), true);
        masks[pos(i, j)][3].set(pos(i + 2, j), true);
        masks[pos(i, j)][3].set(pos(i + 3, j - 1), true);
        masks[pos(i, j)][3].set(pos(i + 3, j), true);
        masks[pos(i, j)][3].set(pos(i + 3, j + 1), true);
      }
    }
  }
}

void print_board(const board &bd, const board &hd, const board &empty = {}) {
  printf("   ");
  for (int i = 0; i < N; i++) {
    printf(" %c", 'A' + i);
  }
  printf("\n  +-");
  for (int i = 0; i < N; i++) {
    printf("--");
  }
  printf("+\n");
  for (int j = 0; j < N; j++) {
    printf("%2d| ", j + 1);
    for (int i = 0; i < N; i++) {
      putchar(hd.test(i * N + j)      ? 'x'
              : bd.test(i * N + j)    ? 'o'
              : empty.test(i * N + j) ? '-'
                                      : ' ');
      putchar(' ');
    }
    puts("|");
  }
  printf("  +-");
  for (int i = 0; i < N; i++) {
    printf("--");
  }
  printf("+\n");
}

double entropy(const vector<int> &p) {
  double total = 0, result = 0;
  for (int i = 0; i < p.size(); i++) total += p[i];
  for (int i = 0; i < p.size(); i++) {
    if (!p[i]) continue;
    double tmp = p[i] / total;
    result -= tmp * log2(tmp);
  }
  return result;
}

void dfs(int x, int start, const board &bodys, const board &heads,
         vector<shared_ptr<board>> &bodys_list,
         vector<shared_ptr<board>> &heads_list, const board &info_head,
         const board &info_body, const board &info_empty) {
  if (x == PLANE) {
    if ((info_body & bodys) != info_body) return;
    if ((info_head & heads) != info_head) return;
    if ((info_body & heads).any()) return;
    if ((info_empty & bodys).any()) return;
    if ((info_empty & heads).any()) return;
    bodys_list.emplace_back(make_shared<board>(bodys));
    heads_list.emplace_back(make_shared<board>(heads));
  }
  for (int i = start; i < N * N;
       i++) {  // TODO: maybe give weight to each plane by its head position
    for (int di = 0; di < 4; di++) {
      if (valid[i][di]) {
        if (x && (bodys & masks[i][di]).any()) {
          continue;
        }
        auto h = heads;
        h.set(i);
        dfs(x + 1, i + 1, bodys | masks[i][di], h, bodys_list, heads_list,
            info_head, info_body, info_empty);
      }
    }
  }
}

double cases(int pos, int depth, vector<int> &result, board &selected,
             const vector<shared_ptr<board>> &bodys_list,
             const vector<shared_ptr<board>> &heads_list, double alpha) {
  vector<shared_ptr<board>> empty_bodys_list, empty_heads_list;
  int head_cnt = 0, body_cnt = 0, empty_cnt = 0;
  for (int i = 0; i < bodys_list.size(); i++) {
    if (heads_list[i]->test(pos)) {
      head_cnt++;
    } else if (bodys_list[i]->test(pos)) {
      body_cnt++;
    } else {
      empty_cnt++;
      if (depth > 0) {
        empty_bodys_list.emplace_back(bodys_list[i]);
        empty_heads_list.emplace_back(heads_list[i]);
      }
    }
  }
  double head_rate = (double)head_cnt / bodys_list.size();
  result.push_back(head_cnt);
  result.push_back(body_cnt);
  if (depth <= 0) {
    result.push_back(empty_cnt);
  } else {
    double best_pp = 0;
    double best_wr = 0;
    vector<int> best_result;
    for (int i = 0; i < N * N; i++) {
      if (selected.test(i)) continue;
      vector<int> sub_result;
      selected.set(i);
      double sub_wr = cases(i, depth - 1, sub_result, selected,
                            empty_bodys_list, empty_heads_list, alpha);
      selected.reset(i);
      double sub_pp = sub_wr * alpha + entropy(sub_result);
      if (sub_pp > best_pp) {
        best_pp = sub_pp;
        best_wr = sub_wr;
        best_result = sub_result;
      }
    }
    head_rate += empty_cnt * best_wr / bodys_list.size();
    for (int i : best_result) {
      result.push_back(i);
    }
  }
  return head_rate;
}

pair<mixed_action, pair<double, double>> calculate(const board &info_head,
                                                   const board &info_body,
                                                   const board &info_empty,
                                                   int depth,
                                                   double alpha = 1.0) {
  vector<shared_ptr<board>> bodys_list, heads_list;
  dfs(0, 0, {}, {}, bodys_list, heads_list, info_head, info_body, info_empty);
  // printf("count = %d\n", (int)bodys_list.size());

  board selected = info_body | info_empty | info_head;
  vector<double> p_calc(N * N), p_hit(N * N);
  for (int pos = 0; pos < N * N; pos++) {
    vector<int> result;
    p_hit[pos] =
        cases(pos, depth, result, selected, bodys_list, heads_list, alpha);
    p_calc[pos] = p_hit[pos] * alpha + entropy(result);
  }
  double max_p = 0;
  double max_ph;
  for (int i = 0; i < N * N; i++)
    if (!selected.test(i)) {
      if (p_calc[i] > max_p) {
        max_p = p_calc[i];
        max_ph = p_hit[i];
      }
    }
  int max_count = 0;
  for (int i = 0; i < N * N; i++) {
    if (!selected.test(i)) {
      if (max_p - p_calc[i] < eps) {
        max_count++;
      }
    }
  }
  mixed_action result;
  for (int i = 0; i < N * N; i++) {
    if (!selected.test(i)) {
      if (max_p - p_calc[i] < eps) {
        result.emplace_back(1. / max_count, i);
      }
    }
  }

  return {result, {max_ph, max_p}};
}

pair<action, pair<double, double>> calculate_simple(const board &info_head,
                                                    const board &info_body,
                                                    const board &info_empty,
                                                    int depth,
                                                    double alpha = 1.0) {
  vector<shared_ptr<board>> bodys_list, heads_list;
  dfs(0, 0, {}, {}, bodys_list, heads_list, info_head, info_body, info_empty);
  // printf("count = %d\n", (int)bodys_list.size());

  board selected = info_body | info_empty | info_head;
  vector<double> p_calc(N * N), p_hit(N * N);
  for (int pos = 0; pos < N * N; pos++) {
    vector<int> result;
    p_hit[pos] =
        cases(pos, depth, result, selected, bodys_list, heads_list, alpha);
    p_calc[pos] = p_hit[pos] * alpha + entropy(result);
  }
  double max_p = 0;
  double max_ph;
  int max_count = 0;
  action result;
  for (int i = 0; i < N * N; i++) {
    if (!selected.test(i)) {
      if (p_calc[i] > max_p + eps) {
        result = i;
        max_p = p_calc[i];
        max_ph = p_hit[i];
        max_count = 1;
      } else if (p_calc[i] > max_p - eps) {
        max_count++;
        if (rand() % max_count == 0) {
          result = i;
          max_ph = p_hit[i];
        }
      }
    }
  }

  return {result, {max_ph, max_p}};
}

double expected_times(const board &current_info_head,
                      const board &current_info_body,
                      const board &current_info_empty, const board &target_bd,
                      const board &target_hd, int depth, double alpha = 1.0, int __fast_path = 0) {
  auto a = __fast_path ? __fast_path : calculate_simple(current_info_head, current_info_body,
                                 current_info_empty, depth, alpha).first;
  // printf("Action: %c%d\n", a % N + 'A', a / N);
  // printf("Action: %d\n", a);
  double result = 0;
  if (target_hd.test(a)) {
    if (current_info_head.count() == PLANE - 1) {
      result += 1;
    } else {
      auto info_head = current_info_head;
      info_head.set(a, true);
      // print_board(current_info_body, info_head, current_info_empty);
      result += expected_times(info_head, current_info_body, current_info_empty,
                               target_bd, target_hd, 2, alpha);
    }
  } else if (target_bd.test(a)) {
    auto info_body = current_info_body;
    info_body.set(a, true);
    // print_board(info_body, current_info_head, current_info_empty);
    result +=
        1 + expected_times(current_info_head, info_body, current_info_empty,
                           target_bd, target_hd, 2, alpha);
  } else {
    auto info_empty = current_info_empty;
    info_empty.set(a, true);
    // print_board(current_info_body, current_info_head, info_empty);
    if (depth == 0) {
      result += 1 + expected_times(current_info_head, current_info_body,
                                   info_empty, target_bd, target_hd, 2, alpha);
    } else {
      result += expected_times(current_info_head, current_info_body, info_empty,
                               target_bd, target_hd, depth - 1, alpha);
    }
  }
  return result;
}

void benchmark(double alpha) {
  init_masks();

  printf("Alpha = %lf\n", alpha);

  // Case 2: 3 random given empty
  board info_head = {}, info_body = {}, info_empty = {};
  info_empty.set(0);
  info_empty.set(N - 1);
  info_empty.set(N * N - N);
  info_empty.set(N * N - 1);
  info_empty.set(37);
  info_empty.set(53);
  info_empty.set(80);

  vector<shared_ptr<board>> bodys_list, heads_list;
  dfs(0, 0, {}, {}, bodys_list, heads_list, info_head, info_body, info_empty);
  // print_board(info_body, info_head, info_empty);

  int count = bodys_list.size();
  atomic<double> total_exp(0);

  printf("Total cases: %d\n", count);

  auto first_step = calculate_simple(info_head, info_body, info_empty, 2, alpha).first;

  vector<thread> threads;
  int THREAD_CNT = 16;
  for (int t = 0; t < THREAD_CNT; t++) {
    threads.emplace_back([&, t]() {
      for (int i = 0; i < count; i++) {
        if (i % THREAD_CNT == t) {
          // print_board(*bodys_list[i], *heads_list[i]);
          double exp = expected_times(info_head, info_body, info_empty,
                                      *bodys_list[i], *heads_list[i], 2, alpha, first_step);
          total_exp = total_exp + exp;
          // printf("Expect turns = %lf\n", exp);
        }
      }
    });
  }
  for (int t = 0; t < THREAD_CNT; t++) {
    threads[t].join();
  }

  printf("Total expect turns = %lf\n", total_exp.load() / count);
}

void benchmark2() {
  init_masks();

  board info_head = {}, info_body = {}, info_empty = {};
  info_empty.set(0);
  info_empty.set(N - 1);
  info_empty.set(N * N - N);
  info_empty.set(N * N - 1);
  info_empty.set(77);
  info_empty.set(82);
  info_body.set(56);

  auto start = chrono::high_resolution_clock::now();
  auto action = calculate_simple(info_head, info_body, info_empty, 2, 4.0).first;
  auto end = chrono::high_resolution_clock::now();
  cout << "Action: " << action << endl;
  cout << "Time: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
}

int startConsole() {
  init_masks();

  vector<board> info_heads{{}}, info_bodys{{}}, info_emptys{{}};
  info_emptys[0].set(0);
  info_emptys[0].set(N - 1);
  info_emptys[0].set(N * N - N);
  info_emptys[0].set(N * N - 1);

  double alpha = 3.0;

  while (true) {
    board info_head = info_heads.back();
    board info_body = info_bodys.back();
    board info_empty = info_emptys.back();
    puts("\n");
    print_board(info_body, info_head, info_empty);

    char s[16], s2[16];
    int a, b;
    puts(
        "1. [position] + {head,body,empty}\n"
        "2. cal + {1,2,3}\n"
        "3. alpha + [alpha]\n"
        "4. undo\n");
    s2[2] = 0;
    scanf("%s", s2);
    if (strcmp(s2, "undo") == 0) {
      info_bodys.pop_back();
      info_heads.pop_back();
      info_emptys.pop_back();
      continue;
    }
    scanf("%s", s);
    if (strcmp(s2, "alpha") == 0) {
      sscanf(s, "%lf", &alpha);
      continue;
    }
    if (strcmp(s2, "cal") == 0) {
      int count = 0;
      sscanf(s, "%d", &count);
      auto result =
          calculate(info_head, info_body, info_empty, count - 1, alpha);
      printf("alpha=%lf, head_rate=%lf , entropy=%lf\n", alpha,
             result.second.first, result.second.second);
      printf("\n     Best position: ");
      for (int i = 0; i < result.first.size(); i++) {
        printf("%c%d ", (result.first[i].second / N) + 'A',
               result.first[i].second % N + 1);
      }
      puts("\n");
      continue;
    }
    a = s2[0] <= 'Z' ? s2[0] - 'A' : s2[0] - 'a';
    sscanf(s2 + 1, "%d", &b);
    b--;
    if (a < 0 || a >= N || b < 0 || b >= N) {
      puts("Invalid input.");
      continue;
    }
    if (s[0] == 'h') {
      info_head.set(a * N + b, true);
    } else if (s[0] == 'b') {
      info_body.set(a * N + b, true);
    } else if (s[0] == 'e') {
      info_empty.set(a * N + b, true);
    } else {
      puts("Invalid input.");
      continue;
    }

    info_bodys.push_back(info_body);
    info_heads.push_back(info_head);
    info_emptys.push_back(info_empty);
  }

  return 0;
}
};  // namespace GuessPlane
