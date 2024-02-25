#include <bits/stdc++.h>

using namespace std;

namespace OneTwoPoker {

const int N = 13;
const int STATE_SIZE = 1 << N;

unsigned char win[STATE_SIZE][STATE_SIZE][2];

bool can_win(int flag0, int flag1, bool odd, bool debug = false) {
  if (debug) {
    putchar('(');
    for (int i = 0; i < N; i++) {
      if (flag0 & (1 << i)) {
        cout << i + 1 << " ";
      }
    }
    cout << ") vs (";
    for (int i = 0; i < N; i++) {
      if (flag1 & (1 << i)) {
        cout << i + 1 << " ";
      }
    }
    cout << ") odd = " << odd
         << " can_win = " << (win[flag0][flag1][odd] ? 1 : 0) << endl;
  }
  return win[flag0][flag1][odd];
}

string vector_to_string(const vector<int>& v) {
  string s;
  for (int i = 0; i < v.size(); i++) {
    s += to_string(v[i]);
    if (i != v.size() - 1) {
      s += " ";
    }
  }
  return s;
}

void precalc() {
  win[0][0][0] = 0;
  win[0][0][1] = 1;  // odd player wins when game ends.

  for (int size = 1; size <= N; size++)
    for (int flag0 = 1; flag0 < STATE_SIZE; flag0++) {
      int remain = __builtin_popcount(flag0);
      if (remain != size) {
        continue;
      }
      for (int flag1 = 1; flag1 < STATE_SIZE; flag1++) {
        if (remain != __builtin_popcount(flag1)) {
          continue;
        }
        win[flag0][flag1][0] = false;
        win[flag0][flag1][1] = false;
        // for every possible action of player 0
        for (int i = 0; i < N; i++) {
          if (flag0 & (1 << i)) {
            bool player_1_can_win[2] = {false, false};
            // for every possible action of player 1
            for (int j = 0; j < N; j++) {
              if (flag1 & (1 << j)) {
                // if i > j, player 0 wins, that means odd changes. Playerid
                // doesn't change.
                if (i > j) {
                  player_1_can_win[0] |=
                      !can_win(flag0 ^ (1 << i), flag1 ^ (1 << j), 1);
                  player_1_can_win[1] |=
                      !can_win(flag0 ^ (1 << i), flag1 ^ (1 << j), 0);
                }
                // if i == j, odd doesn't change. Playerid change.
                else if (i == j) {
                  // if remain is even (remain&1 == 0), player1 amount =
                  // ~(player0 amount)
                  player_1_can_win[0] |=
                      can_win(flag1 ^ (1 << j), flag0 ^ (1 << i), ~remain & 1);
                  player_1_can_win[1] |=
                      can_win(flag1 ^ (1 << j), flag0 ^ (1 << i), remain & 1);
                }
                // if i < j, odd change. Playerid change.
                else {
                  player_1_can_win[0] |=
                      can_win(flag1 ^ (1 << j), flag0 ^ (1 << i), remain & 1);
                  player_1_can_win[1] |=
                      can_win(flag1 ^ (1 << j), flag0 ^ (1 << i), ~remain & 1);
                }
              }
            }
            win[flag0][flag1][0] |= !player_1_can_win[0];
            win[flag0][flag1][1] |= !player_1_can_win[1];
          }
        }
      }
    }
}

int startConsole() {
  precalc();

  int flag0 = (1 << N) - 1, flag1 = (1 << N) - 1;
  int score0 = 0, score1 = 0;
  int last0, last1;

  while (true) {
    cout << "Player 0 score: " << score0 << ", cards: ";
    for (int i = 0; i < N; i++) {
      if (flag0 & (1 << i)) {
        cout << i + 1 << " ";
      }
    }
    cout << endl;
    cout << "Player 1 score: " << score1 << ", cards: ";
    for (int i = 0; i < N; i++) {
      if (flag1 & (1 << i)) {
        cout << i + 1 << " ";
      }
    }
    cout << endl;
    if (__builtin_popcount(flag0) == __builtin_popcount(flag1)) {
      int remain = __builtin_popcount(flag0);
      cout << "Player 0 winstate = " << can_win(flag0, flag1, score0 & 1)
           << endl;

      for (int i = 0; i < N; i++) {
        if (flag0 & (1 << i)) {
          vector<int> player_1_can_win[2];
          // for every possible action of player 1
          for (int j = 0; j < N; j++) {
            if (flag1 & (1 << j)) {
              // if i > j, player 0 wins, that means odd changes. Playerid
              // doesn't change.
              if (i > j) {
                if (!can_win(flag0 ^ (1 << i), flag1 ^ (1 << j), 1))
                  player_1_can_win[0].push_back(j + 1);
                if (!can_win(flag0 ^ (1 << i), flag1 ^ (1 << j), 0))
                  player_1_can_win[1].push_back(j + 1);
              }
              // if i == j, odd doesn't change. Playerid change.
              else if (i == j) {
                if (can_win(flag1 ^ (1 << j), flag0 ^ (1 << i), ~remain & 1))
                  player_1_can_win[0].push_back(j + 1);
                if (can_win(flag1 ^ (1 << j), flag0 ^ (1 << i), remain & 1))
                  player_1_can_win[1].push_back(j + 1);
              }
              // if i < j, odd change. Playerid change.
              else {
                if (can_win(flag1 ^ (1 << j), flag0 ^ (1 << i), remain & 1))
                  player_1_can_win[0].push_back(j + 1);
                if (can_win(flag1 ^ (1 << j), flag0 ^ (1 << i), ~remain & 1))
                  player_1_can_win[1].push_back(j + 1);
              }
            }
          }
          cout << "If Player 0 = " << i + 1 << ", Player 1 can win = "
               << vector_to_string(player_1_can_win[score0 & 1]) << endl;
        }
      }
    } else if (__builtin_popcount(flag0) + 1 == __builtin_popcount(flag1)) {
      // for every possible action of player 1
      vector<int> player_1_can_win;
      for (int j = 0; j < N; j++) {
        if (flag1 & (1 << j)) {
          int i = last0;
          if (i > j) {
            // if i > j, player 0 wins, that means odd changes. Playerid doesn't
            // change.
            if (!can_win(flag0, flag1 ^ (1 << j), ~score0 & 1))
              player_1_can_win.push_back(j + 1);
          } else if (i == j) {
            // if i == j, odd doesn't change. Playerid change.
            if (can_win(flag1 ^ (1 << j), flag0, score1 & 1))
              player_1_can_win.push_back(j + 1);
          } else {
            // if i < j, odd change. Playerid change.
            if (can_win(flag1 ^ (1 << j), flag0, ~score1 & 1))
              player_1_can_win.push_back(j + 1);
          }
        }
      }
      cout << "If Player 0 = " << last0 + 1
           << ", Player 1 can win = " << vector_to_string(player_1_can_win)
           << endl;
    }

    string input;
    cin >> input;
    if (input == "swap") {
      swap(flag0, flag1);
      swap(score0, score1);
      swap(last0, last1);
    }
    if (input == "0") {
      int i;
      cin >> i;
      i--;
      flag0 ^= (1 << i);
      last0 = i;
    }
    if (input == "1") {
      int i;
      cin >> i;
      i--;
      flag1 ^= (1 << i);
      last1 = i;
    }
    if (input == "win") {
      score0++;
    }
    if (input == "unwin") {
      score0--;
    }
    if (input == "lose") {
      swap(flag0, flag1);
      swap(score0, score1);
      swap(last0, last1);
      score0++;
    }
    if (input == "unlose") {
      score0--;
      swap(flag0, flag1);
      swap(score0, score1);
      swap(last0, last1);
    }
    if (input == "draw") {
      swap(flag0, flag1);
      swap(score0, score1);
      swap(last0, last1);
      score1++;
    }
    if (input == "undraw") {
      score1--;
      swap(flag0, flag1);
      swap(score0, score1);
      swap(last0, last1);
    }
  }
}

};  // namespace OneTwoPoker