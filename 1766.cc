#include <iostream>
#include <vector>
#include <queue>

#define HEAP_SIZE 32001

int N, M;
std::vector<int> adj_list[32001];
int indegree[32001];

template <typename T>
struct MinHeap {
  bool empty() { return size == 0; }
  void clear() { size = 0; }
  void fixUp(int);
  void fixDown(int);
  void push(T);
  void pop();
  T top();

  T heap[HEAP_SIZE];
  int size = 0;
};
template <typename T>
void MinHeap<T>::fixDown(int idx)
{
  while((idx << 1) <= size) {
    int smallest = (idx << 1);
    if(smallest < size && heap[smallest + 1] < heap[smallest])
      ++smallest;
    if(!(heap[smallest] < heap[idx])) break;

    auto temp = heap[idx];
    heap[idx] = heap[smallest];
    heap[smallest] = temp;
    idx = smallest;
  }
}
template <typename T>
void MinHeap<T>::fixUp(int idx)
{
  while(idx > 1 && heap[idx] < heap[(idx >> 1)]) {
    auto temp = heap[idx];
    heap[idx] = heap[(idx >> 1)];
    heap[(idx >> 1)] = temp;
    idx = (idx >> 1);
  }
}
template <typename T>
void MinHeap<T>::push(T p)
{
  heap[++size] = p;
  fixUp(size);
}
template <typename T>
T MinHeap<T>::top()
{
  return heap[1];
}
template <typename T>
void MinHeap<T>::pop()
{
  heap[1] = heap[size--];
  fixDown(1);
}

MinHeap<int> Q;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  
  std::cin >> N >> M;
  for(int i = 0; i < M; ++i) {
    int A, B;
    std::cin >> A >> B;
    adj_list[A].push_back(B);
    ++indegree[B];
  }

  for(int i = 1; i <= N; ++i)
    if(!indegree[i])
      Q.push(i);

  while(!Q.empty()) {
    int i = Q.top(); Q.pop();
    std::cout << i << " ";
    for(auto v : adj_list[i])
      if(--indegree[v] == 0)
        Q.push(v);
  }
  std::cout << std::endl;

  return 0;
}