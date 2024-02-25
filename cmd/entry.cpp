#include "games/GuessPlane/main.h"
#include "games/MeetInMiddle/main.h"
#include "games/OneTwoPoker/main.h"

int main() {
  printf("Choose game to start:\n\t1. GuessPlane\n\t2. MeetInMiddle\n\t3. OneTwoPoker\n");
  int x;
  scanf("%d", &x);
  if (x == 1) {
    GuessPlane::startConsole();
  } else if (x == 2) {
    MeetInMiddle::startConsole();
  } else if (x == 3) {
    OneTwoPoker::startConsole();
  }
}
