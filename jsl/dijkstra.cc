#include <iostream>
#include <queue>
#include <vector>

inline int min(int a, int b)
{
  return a < b ? a : b;
}

#define INF 1000000000
#define pii std::pair<int, int>

struct MinHeap {
  bool empty() { return size == 0; }
  void fixUp(int idx);
  void fixDown(int idx);
  void push(pii p);
  void pop();
  pii top();

  pii heap[300001];
  int size = 0;
};

void MinHeap::fixDown(int idx)
{
  while(2 * idx <= size) {
    int smallest = 2 * idx;
    if(2 * idx < size && heap[2 * idx + 1] < heap[smallest])
      ++smallest;
    if(heap[idx] < heap[smallest]) break;

    auto temp = heap[idx];
    heap[idx] = heap[smallest];
    heap[smallest] = temp;
    idx = smallest;
  }
}

void MinHeap::fixUp(int idx)
{
  while(idx > 0 && heap[idx] < heap[idx >> 1]) {
    auto temp = heap[idx];
    heap[idx] = heap[idx >> 1];
    heap[idx >> 1] = temp;
    idx = idx >> 1;
  }
}

void MinHeap::push(pii p)
{
  heap[++size] = p;
  fixUp(size);
}

pii MinHeap::top()
{
  return heap[1];
}

void MinHeap::pop()
{
  heap[1] = heap[size--];
  fixDown(1);
}

int V, E, S;
int dist[20001];
std::vector<pii> adj_list[20001];
MinHeap Q;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL); std::cout.tie(NULL);

  std::cin >> V >> E >> S;
  for(int i = 1; i <= V; ++i)
    dist[i] = INF;

  for(int i = 0; i < E; ++i) {
    int src, dst, weight;
    std::cin >> src >> dst >> weight;
    adj_list[src].push_back({dst, weight});
  }

  Q.push({0, S});
  dist[S] = 0;

  while(!Q.empty()) {
    auto curr = Q.top(); Q.pop();
    int u = curr.second, d_u = curr.first;

    // skip those with higher cost than currently known.
    if(dist[u] < d_u) continue;

    for(auto next : adj_list[u]) {
      // relaxation
      int v = next.first, weight_uv = next.second;
      if(dist[v] <= d_u + weight_uv) continue;
      dist[v] = d_u + weight_uv;
      Q.push(pii(dist[v], v));
    }
  }

  for(int i = 1; i <= V; ++i) {
    if(dist[i] == INF)
      std::cout << "INF" << "\n";
    else
      std::cout << dist[i] << "\n";
  }
  std::cout << std::endl;

  return 0;
}

/* partial dijkstra for S -> D
void dijkstra(int S, int D)
{
  std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;

  for(int j = 1; j <= V; ++j)
    dist[j] = INF;

  dist[S] = 0;
  Q.push(pii(0, S));

  while(!Q.empty()) {
    auto curr = Q.top(); Q.pop();
    int u = curr.second, d_u = curr.first;

    if(u == D) return dist[u];
    if(dist[u] < d_u) continue;

    for(auto next : adj_list[u]) {
      int v = next.first, weight_uv = next.second;
      if(dist[v] <= d_u + weight_uv) continue;
      dist[v] = d_u + weight_uv;
      Q.push(pii(d_u + weight_uv, v));
    }
  }
}
*/