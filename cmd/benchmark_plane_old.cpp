#include "games/GuessPlane/main_old.h"

/*

Case 1: 2 random given body and 3 random given empty
Result:
  alpha=1.0, beta=0.6,  result = 3.973087
  alpha=2.0, beta=0.6,  result = 3.938835
  alpha=4.0, beta=0.6,  result = 4.078069

  alpha=1.0, beta=0.3,  result = 4.194395
  alpha=2.0, beta=0.3,  result = 4.144573
  alpha=4.0, beta=0.3,  result = 4.152802

  alpha=1.0, beta=0.7,  result = 3.954404
  alpha=2.0, beta=0.7,  result = 3.923932
  alpha=4.0, beta=0.7,  result = 3.947509

  alpha=1.0, beta=0.8,  result = 3.958852
  alpha=2.0, beta=0.8,  result = 3.917260
  alpha=3.0, beta=0.8,  result = 3.925712
  alpha=4.0, beta=0.8,  result = 3.937278
*/


int main() {
  srand(time(0));

  double alpha = 2.0, beta = 0.8;

  for(int i = 1; i <= 10; i++) {
    alpha = i;

    printf("alpha = %lf, beta = %lf\n", alpha, beta);

    GuessPlane::benchmark(alpha, beta);
  }

  return 0;
}
