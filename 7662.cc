#include <iostream>
#include <cstring>

struct Node {
  Node(int _key = 0, int _tStamp = 0) : key(_key), tStamp(_tStamp) {}
  int key;
  int tStamp;
};

bool operator<(const Node &lhs, const Node &rhs)
{
  return lhs.key < rhs.key;
}

// MODIFY MAX_SIZE!!!!!
#define MAX_SIZE 1000000

template <typename T>
struct MinHeap {
  bool empty() { return size == 0; }
  void clear() { size = 0; }
  void fixUp(int);
  void fixDown(int);
  void push(T);
  void pop();
  T top();

  T heap[MAX_SIZE];
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

template <typename T>
struct MaxHeap {
  bool empty() { return size == 0; }
  void clear() { size = 0; }
  void fixUp(int);
  void fixDown(int);
  void push(T);
  void pop();
  T top();

  T heap[MAX_SIZE];
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

int T, k;
int nodeCnt;

Node pool[1000010];
bool deleted[1000010];

MinHeap<Node> min;
MaxHeap<Node> max;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL); std::cout.tie(NULL);

  std::cin >> T;
  for(int test_case = 1; test_case <= T; ++test_case) {
    max.clear(); min.clear();
    nodeCnt = 0;
    memset(deleted, 0, sizeof(deleted));

    std::cin >> k;
    for(int i = 0; i < k; ++i) {
      char cmd;
      int input;
      std::cin >> cmd;
      switch(cmd) {
        case 'I':
        std::cin >> input;
        pool[nodeCnt] = Node(input, nodeCnt);
        max.push(pool[nodeCnt]); min.push(pool[nodeCnt]);
        ++nodeCnt;
        break;
        case 'D':
        std::cin >> input;
        if(input == 1) {
          while(!max.empty() && deleted[max.top().tStamp])
            max.pop();
          if(!max.empty()) {
            deleted[max.top().tStamp] = true;
            max.pop();
          }
        } else {
          while(!min.empty() && deleted[min.top().tStamp])
            min.pop();
          if(!min.empty()) {
            deleted[min.top().tStamp] = true;
            min.pop();
          }
        }
        break;
      }
    }

    while(!max.empty() && deleted[max.top().tStamp])
      max.pop();
    while(!min.empty() && deleted[min.top().tStamp])
      min.pop();
    
    if(max.empty()) {
      std::cout << "EMPTY" << std::endl;
      continue;
    }

    std::cout << max.top().key << " " << min.top().key << "\n";
  }

  return 0;
}