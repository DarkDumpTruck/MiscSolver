#include "games/GuessPlane/main.h"
/*

Case 1: 2 random given body and 3 random given empty
Result:
  alpha = 4.0,     avg = 3.811833
  alpha = 8.0,     avg = 3.777135
  alpha = 12.0,    avg = 3.764457
  alpha = 16.0,    avg = 3.789591
  alpha = 8/16/24, avg = 3.780916
  alpha = 4/8/12,  avg = 3.785587

With head reault:
  alpha = 2.0,     avg = 3.730872
  alpha = 3.0,     avg = 3.703292
  alpha = 4.0,     avg = 3.694395
  alpha = 8.0,     avg = 3.735320
  alpha = 12.0,    avg = 3.756228
  
Case 2: 3 random given empty
With head result:

*/
int main() {
  srand(time(0));

  // GuessPlane::benchmark2();

  for(double alpha = 2.0; alpha <= 6.0; alpha += 0.1) {
    GuessPlane::benchmark(alpha);
  }

  return 0;
}
