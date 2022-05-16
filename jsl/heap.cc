// MODIFY MAX_HEAP_SIZE!!!!!
#define HEAP_SIZE 1000000

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
