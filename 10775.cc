#include <iostream>

int G, P, ans;
int parent[100001];

int getParent(int n)
{
  if(parent[n] == n)
    return n;
  return (parent[n] = getParent(parent[n]));
}

void unionize(int a, int b)
{
  a = getParent(a);
  b = getParent(b);

  if(a > b) {
    int temp = a;
    a = b;
    b = temp;
  }
  parent[b] = a;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> G >> P;

  for(int i = 1; i <= G; ++i)
    parent[i] = i;
  
  int maxGate;
  for(int i = 0; i < P; ++i) {
    std::cin >> maxGate;
    int target = getParent(maxGate);
    if(target == 0)
      break;
    ++ans;
    unionize(target - 1, target);
    if(ans == G)
      break;
  }

  std::cout << ans << "\n";

  return 0;
}