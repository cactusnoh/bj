#include <iostream>
#include <vector>

inline int min(int a, int b)
{
  return a < b ? a : b;
}

#define INF 10000000

std::pair<int, int> heap[300001];
int heapSize;

void fixDown(int idx)
{
  while(2 * idx <= heapSize) {
    int smallest = 2 * idx;
    if(2 * idx < heapSize && heap[2 * idx + 1] < heap[smallest])
      ++smallest;
    if(heap[idx] < heap[smallest]) break;

    auto temp = heap[idx];
    heap[idx] = heap[smallest];
    heap[smallest] = temp;
    idx = smallest;
  }
}

void fixUp(int idx)
{
  while(idx > 0 && heap[idx] < heap[idx >> 1]) {
    auto temp = heap[idx];
    heap[idx] = heap[idx >> 1];
    heap[idx >> 1] = temp;
    idx = idx >> 1;
  }
}

void heapInsert(std::pair<int, int> p)
{
  heap[++heapSize] = p;
  fixUp(heapSize);
}

std::pair<int, int> heapTop()
{
  return heap[1];
}

void heapPop()
{
  heap[1] = heap[heapSize--];
  fixDown(1);
}

int V, E, S;
int dist[20001];
std::vector<std::pair<int, int>> adj_list[20001];

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

  heapInsert({0, S});
  dist[S] = 0;

  while(heapSize) {
    auto p = heapTop();
    heapPop();
    int curr_node = p.second, curr_cost = p.first;
    for(auto next : adj_list[p.second]) {
      int next_node = next.first, next_cost = next.second;
      if(dist[next_node] < next_cost + curr_cost) continue;
      dist[next_node] = next_cost + curr_cost;
      heapInsert(std::pair<int, int>(curr_cost + next_cost, next_node));
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