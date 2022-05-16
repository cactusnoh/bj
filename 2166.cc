#include <cstdio>

inline double abs(double a)
{
  return a < 0 ? -a : a;
}

int N;
double pos[10001][2];

int main()
{
  scanf("%d", &N);

  for(int i = 0; i < N; ++i)
    scanf("%lf%lf", &pos[i][0], &pos[i][1]);
  pos[N][0] = pos[0][0]; pos[N][1] = pos[0][1];

  double sum1 = 0, sum2 = 0;
  for(int i = 0; i < N; ++i) {
    sum1 += pos[i][0] * pos[i + 1][1];
    sum2 += pos[i][1] * pos[i + 1][0];
  }
  
  printf("%.1lf\n", abs(sum1 - sum2) / 2);

  return 0;
}