#include <iostream>
#include <queue>
#include <string>
#include <cstring>

typedef std::pair<int, std::string> pis;

int T, A, B;

std::queue<pis> Q;
bool visited[10000];

void BFS()
{
  while(!Q.empty())
    Q.pop();

  visited[A] = true;
  Q.push({A, ""});
  while(1) {
    auto curr = Q.front(); Q.pop();
    int u = curr.first;

    if(u == B) {
      std::cout << curr.second << "\n";
      return;
    }
    
    int d = (2 * u) % 10000, 
        s = (u > 0 ? u - 1 : 9999), 
        l = (u - (u / 1000) * 1000) * 10 + (u / 1000), 
        r = (u / 10) + (u % 10) * 1000;

    if(!visited[d]) {
      visited[d] = true;
      Q.push(pis(d, curr.second + "D"));
    }
    
    if(!visited[s]) {
      visited[s] = true;
      Q.push(pis(s, curr.second + "S"));
    }

    if(!visited[l]) {
      visited[l] = true;
      Q.push(pis(l, curr.second + "L"));
    }

    if(!visited[r]) {
      visited[r] = true;
      Q.push(pis(r, curr.second + "R"));
    }
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> T;
  for(int t = 0; t < T; ++t) {
    memset(visited, 0, sizeof(visited));
    std::cin >> A >> B;
    BFS();
  }

  return 0;
}