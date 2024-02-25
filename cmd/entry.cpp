#include "games/GuessPlane/main.h"
#include "games/MeetInMiddle/main.h"

int main() {
  printf("Choose game to start:\n\t1. GuessPlane\n\t2. MeetInMiddle\n");
  int x;
  scanf("%d", &x);
  if (x == 1) {
    GuessPlane::startConsole();
  } else if(x==2) {
    MeetInMiddle::startConsole();
  }
}
