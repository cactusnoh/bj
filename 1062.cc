#include <iostream>
#include <string>

int N, K, max;
std::string words[50];
bool alpha[26], inWords[26];
int alphaCnt;

bool canRead(const std::string &s)
{
  for(char c : s)
    if(!alpha[c - 'a'])
      return false;
  return true;
}

void solve(int pickCnt, char lastPicked)
{
  if(pickCnt >= K - 5 || pickCnt + 5 >= alphaCnt) {
    int cnt = 0;
    for(int i = 0; i < N; ++i)
      if(canRead(words[i]))
        ++cnt;
    if(max < cnt)
      max = cnt;
    return;
  }

  for(int i = lastPicked + 1; i <= 'z'; ++i) {
    if(alpha[i - 'a'] || !inWords[i - 'a']) continue;
    alpha[i - 'a'] = true;
    solve(pickCnt + 1, i);
    alpha[i - 'a'] = false;
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cin >> N >> K;

  if(K < 5) {
    std::cout << 0 << std::endl;
    return 0;
  }

  alpha['a' - 'a'] = alpha['n' - 'a'] = alpha['t' - 'a'] = alpha['i' - 'a'] = alpha['c' - 'a'] = true;

  for(int i = 0; i < N; ++i) {
    std::cin >> words[i];
    for(auto c : words[i]) {
      if(inWords[c - 'a'] == false) {
        inWords[c - 'a'] = true;
        ++alphaCnt;
      }
    }
  }

  solve(0, 'a');
  std::cout << max << std::endl;

  return 0;
}