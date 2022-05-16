#include <iostream>
#include <algorithm>
#include <queue>

#define INF 2147000000
#define HEAP_SIZE 300001

typedef std::pair<int, int> pii;

template <typename T>
struct MaxHeap {
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
void MaxHeap<T>::fixDown(int idx)
{
  while((idx << 1) <= size) {
    int largest = (idx << 1);
    if(largest < size && heap[largest] < heap[largest + 1])
      ++largest;
    if(!(heap[idx] < heap[largest])) break;

    auto temp = heap[idx];
    heap[idx] = heap[largest];
    heap[largest] = temp;
    idx = largest;
  }
}
template <typename T>
void MaxHeap<T>::fixUp(int idx)
{
  while(idx > 1 && heap[(idx >> 1)] < heap[idx]) {
    auto temp = heap[idx];
    heap[idx] = heap[(idx >> 1)];
    heap[(idx >> 1)] = temp;
    idx = (idx >> 1);
  }
}
template <typename T>
void MaxHeap<T>::push(T p)
{
  heap[++size] = p;
  fixUp(size);
}
template <typename T>
T MaxHeap<T>::top()
{
  return heap[1];
}
template <typename T>
void MaxHeap<T>::pop()
{
  heap[1] = heap[size--];
  fixDown(1);
}

int N, K;
pii gems[300000];
int bag_mass[300000];

MaxHeap<int> Q;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N >> K;

  for(int i = 0; i < N; ++i)
    std::cin >> gems[i].first >> gems[i].second;
  std::sort(gems, gems + N);
  for(int i = 0; i < K; ++i)
    std::cin >> bag_mass[i];
  std::sort(bag_mass, bag_mass + K);

  long long ans = 0;
  int idx = 0;
  for(int i = 0; i < K; ++i) {
    while(idx < N && gems[idx].first <= bag_mass[i])
      Q.push(gems[idx++].second);
    if(!Q.empty()) {
      ans += Q.top();
      Q.pop();
    }
  }

  std::cout << ans << std::endl;

  return 0;
}