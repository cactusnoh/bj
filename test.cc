#include <vector>

inline int max(int a, int b)
{
  return a < b ? b : a;
}

int memo[100'000];

int solution(std::vector<int> sticker)
{
    int answer = 0;
    int N = sticker.size();

    if (N == 1) {
      return sticker[0];
    }

    memo[0] = sticker[0];
    memo[1] = sticker[0];

    for (int curr = 2; curr < N - 1; ++curr) {
      memo[curr] = max(sticker[curr] + memo[curr - 2], memo[curr - 1]);
    }
    memo[N - 1] = memo[N - 2];
    answer = memo[N - 1];

    memo[0] = 0;
    memo[1] = sticker[1];

    for (int curr = 2; curr < N; ++curr) {
      memo[curr] = max(sticker[curr] + memo[curr - 2], memo[curr - 1]);
    }
    answer = max(answer, memo[N - 1]);

    return answer;
}