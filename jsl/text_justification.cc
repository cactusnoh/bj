#include <iostream>
#include <string>
#include <vector>

#define INF 2147000000

inline int min(int a, int b)
{
  return a < b ? a : b;
}

int L, N;
std::vector<std::string> words;
int parent[1000];
int memo[1000];

int TJ(int s)
{
  if(memo[s] != INF)
    return memo[s];
  if(s >= N)
    return 0;

  int words_len = 0;
  for(int i = s; i < N; ++i) {
    words_len += words[i].length();

    if(words_len + (i - s) > L)
      continue;

    int temp = L - (words_len + (i - s));
    int badness = temp * temp * temp + TJ(i + 1);

    if(memo[s] > badness) {
      memo[s] = badness;
      parent[s] = i + 1;
    }
  }

  return memo[s];
}

int main()
{
  std::cin >> L;

  std::string input;
  while(std::cin >> input) {
    memo[N++] = INF;
    words.push_back(input);
  }

  TJ(0);

  int line_start = 0;
  while(line_start < N) {
    int word_cnt = parent[line_start] - line_start;

    if(word_cnt == 1) {
      std::cout << words[line_start] << "\n";
      line_start = parent[line_start];
      continue;
    }

    int tot_space = L;
    for(int i = line_start; i < parent[line_start]; ++i)
      tot_space -= words[i].length();

    int divided_space = tot_space / (word_cnt - 1), remaining_space = tot_space % (word_cnt - 1);
    for(int i = line_start; i < parent[line_start] - 1; ++i) {
      std::cout << words[i] << std::string(divided_space, ' ');
      if(remaining_space) {
        std::cout << " ";
        --remaining_space;
      }
    }
    std::cout << words[parent[line_start] - 1] << "\n";
    line_start = parent[line_start];
  }

  return 0;
}