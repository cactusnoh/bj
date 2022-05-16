#include <iostream>
#include <string>

struct Stack {
  void push(int x) { arr[_size++] = x; }
  int pop() { return (empty() ? -1 : arr[--_size]); }
  int size() { return _size; }
  bool empty() { return _size == 0; }
  int top() { return (empty() ? -1 : arr[_size - 1]); }

  int arr[10000];
  int _size = 0;
};

int arr[10000];
int _size = 0;
int N;
std::string cmd;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL); std::cout.tie(NULL);
  std::cin >> N;

  for(int i = 0; i < N; ++i) {
    std::cin >> cmd;
    if(cmd[1] == 'u') {
      int x;
      std::cin >> x;
      arr[_size++] = x;
    } else if(cmd[0] == 'p') {
      std::cout << (_size == 0 ? -1 : arr[--_size]) << std::endl;
    } else if(cmd[0] == 's') {
      std::cout << _size << std::endl;
    } else if(cmd[0] == 'e') {
      std::cout << (_size == 0) << std::endl;
    } else if(cmd[0] == 't') {
      std::cout << (_size == 0 ? -1 : arr[_size - 1]) << std::endl;
    }
  }

  return 0;
}