#include "games/GuessPlane/main.h"

int main() {
  printf("Choose game to start:\n\t1. GuessPlane\n");
  int x;
  scanf("%d", &x);
  if (x == 1) {
    GuessPlane plane;
    plane.startConsole();
  }
}
