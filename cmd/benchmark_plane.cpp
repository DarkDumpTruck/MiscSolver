#include "games/GuessPlane/main.h"
/*

Case 1: 2 random given body and 3 random given empty
Result:  
  alpha = 4.0,     avg = 3.811833,  with_head_avg = 3.709742
  alpha = 8.0,     avg = 3.777135,  with_head_avg = 3.735320
  alpha = 12.0,    avg = 3.764457,  with_head_avg = 3.756228
  alpha = 16.0,    avg = 3.789591
  alpha = 8/16/24, avg = 3.780916
  alpha = 4/8/12,  avg = 3.785587

*/
int main() {
  srand(time(0));

  double alpha = 8.0;

  GuessPlane plane;
  plane.benchmark(alpha);

  return 0;
}
