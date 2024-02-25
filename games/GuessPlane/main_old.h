#include <algorithm>
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
      putchar(bd.test(i * N + j)      ? hd.test(i * N + j) ? 'x' : 'o'
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

int dfs(int x, int start, const board &bodys, const board &heads,
        const board &info_head, const board &info_body, const board &info_empty,
        vector<int> &p_head, vector<int> &p_body, vector<int> &p_empty) {
  if (x == PLANE) {
    if ((info_body & bodys) != info_body) return 0;
    if ((info_head & heads) != info_head) return 0;
    if ((info_body & heads).any()) return 0;
    if ((info_empty & bodys).any()) return 0;
    if ((info_empty & heads).any()) return 0;
    // print_board(bodys, heads);
    // getchar();
    for (int h = 0; h < N * N; h++) {
      if (heads.test(h))
        p_head[h]++;
      else if (bodys.test(h))
        p_body[h]++;
      else
        p_empty[h]++;
    }
    return 1;
  }
  int count = 0;
  for (int i = start; i < N * N; i++) {
    for (int di = 0; di < 4; di++) {
      if (valid[i][di]) {
        if (x && (bodys & masks[i][di]).any()) {
          continue;
        }
        auto h = heads;
        h.set(i);
        count += dfs(x + 1, i + 1, bodys | masks[i][di], h, info_head,
                     info_body, info_empty, p_head, p_body, p_empty);
      }
    }
  }
  return count;
}

void dfs2(int x, int start, const board &bodys, const board &heads,
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
        dfs2(x + 1, i + 1, bodys | masks[i][di], h, bodys_list, heads_list,
             info_head, info_body, info_empty);
      }
    }
  }
}

pair<mixed_action, pair<double, double>> calculate(const board &info_head,
                                                   const board &info_body,
                                                   const board &info_empty,
                                                   double alpha = 1,
                                                   double beta = 0) {
  vector<int> p_head(N * N, 0), p_body(N * N, 0), p_empty(N * N, 0);

  int count = dfs(0, 0, {}, {}, info_head, info_body, info_empty, p_head,
                  p_body, p_empty);

  vector<double> p_calc(N * N);
  for (int i = 0; i < N * N; i++) {
    double ph = 1. * p_head[i] / count;
    double pb = 1. * p_body[i] / count;
    double pe = 1. * p_empty[i] / count;
    double pph = ph < eps ? 0 : ph * log2(ph);
    double ppb = pb < eps ? 0 : pb * log2(pb);
    double ppe = pe < eps ? 0 : pe * log2(pe);
    p_calc[i] = ph * alpha - (pph + ppb + ppe) * (1 - beta * pb);
  }
  board selected = info_body | info_empty | info_head;
  double max_p = 0;
  double max_ph;
  double max_pp;
  for (int i = 0; i < N * N; i++)
    if (!selected.test(i)) {
      if (p_calc[i] > max_p) {
        max_p = p_calc[i];
        double ph = 1. * p_head[i] / count;
        double pb = 1. * p_body[i] / count;
        double pe = 1. * p_empty[i] / count;
        double pph = ph < eps ? 0 : ph * log2(ph);
        double ppb = pb < eps ? 0 : pb * log2(pb);
        double ppe = pe < eps ? 0 : pe * log2(pe);
        max_ph = ph;
        max_pp = -(pph + ppb + ppe) * ((1 - beta) + beta * pe);
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

  return {result, {max_ph, max_pp}};
}

double expected_times(const board &current_info_head,
                      const board &current_info_body,
                      const board &current_info_empty, const board &target_bd,
                      const board &target_hd, int depth, double alpha,
                      double beta) {
  auto mixed_actions = calculate(current_info_head, current_info_body,
                                 current_info_empty, alpha, depth ? beta : 0);
  double result = 0;
  auto [p, a] = mixed_actions.first[0];
  if (target_hd.test(a)) {
    if (current_info_head.count() == PLANE - 1) {
      result += 1;
    } else {
      auto info_head = current_info_head;
      info_head.set(a, true);
      // print_board(current_info_body, info_head, current_info_empty);
      result += expected_times(info_head, current_info_body, current_info_empty,
                               target_bd, target_hd, 2, alpha, beta);
    }
  } else if (target_bd.test(a)) {
    auto info_body = current_info_body;
    info_body.set(a, true);
    // print_board(info_body, current_info_head, current_info_empty);
    result +=
        1 + expected_times(current_info_head, info_body, current_info_empty,
                           target_bd, target_hd, 2, alpha, beta);
  } else {
    auto info_empty = current_info_empty;
    info_empty.set(a, true);
    // print_board(current_info_body, current_info_head, info_empty);
    if (depth == 0) {
      result +=
          1 + expected_times(current_info_head, current_info_body, info_empty,
                             target_bd, target_hd, 2, alpha, beta);
    } else {
      result += expected_times(current_info_head, current_info_body, info_empty,
                               target_bd, target_hd, depth - 1, alpha, beta);
    }
  }
  return result;
}

void benchmark(double alpha, double beta) {
  init_masks();

  // Case 1: 2 random given body and 3 random given empty
  board info_head = {}, info_body = {}, info_empty = {};
  info_empty.set(0);
  info_empty.set(N - 1);
  info_empty.set(N * N - N);
  info_empty.set(N * N - 1);
  info_empty.set(77);
  info_empty.set(82);
  info_empty.set(96);
  info_body.set(33);
  info_body.set(56);

  vector<shared_ptr<board>> bodys_list, heads_list;
  dfs2(0, 0, {}, {}, bodys_list, heads_list, info_head, info_body, info_empty);

  print_board(info_body, info_head, info_empty);

  int count = bodys_list.size();
  printf("Total cases: %d\n", count);
  double total_exp = 0;

  for (int i = 0; i < count; i++) {
    // print_board(*bodys_list[i], *heads_list[i]);
    double exp = expected_times(info_head, info_body, info_empty,
                                *bodys_list[i], *heads_list[i], 2, alpha, beta);
    total_exp += exp;
    // printf("Expect turns = %lf\n", exp);
  }

  printf("Total expect turns = %lf\n", total_exp / count);
}
};  // namespace GuessPlane
