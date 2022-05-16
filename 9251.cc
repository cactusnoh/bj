#include <iostream>
#include <string>

std::string s1, s2;
int LCS[1001][1001];

int max(int a, int b)
{
  return a > b ? a : b;
}

void solve()
{
  for(int i = 0; i < s1.length(); ++i) {
    for(int j = 0; j < s2.length(); ++j) {
      if(s1[i] == s2[j]) LCS[i + 1][j + 1] = LCS[i][j] + 1;
      else LCS[i + 1][j + 1] = max(LCS[i][j + 1], LCS[i + 1][j]);
    }
  }
}

int main()
{
  std::cin >> s1 >> s2;

  solve();
  std::cout << LCS[s1.length()][s2.length()] << std::endl;;

  return 0;
}