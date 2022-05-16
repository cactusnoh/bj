#include <iostream>

struct Stack {
  void push(int x) { arr[_size++] = x; }
  int pop() { return (empty() ? -1 : arr[--_size]); }
  int size() { return _size; }
  bool empty() { return _size == 0; }
  int top() { return (empty() ? -1 : arr[_size - 1]); }

  int arr[100000];
  int _size = 0;
};

int K;
Stack s;

int main()
{
  int temp;
  long long ret = 0;
  std::cin >> K;

  for(int i = 0; i < K; ++i) {
    std::cin >> temp;
    if(temp == 0) {
      ret -= s.pop();
    } else {
      ret += temp;
      s.push(temp);
    }
  }

  std::cout << ret << std::endl;

  return 0;
}