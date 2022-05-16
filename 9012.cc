#include <iostream>
#include <string>

struct Stack {
  void push(int x) { arr[_size++] = x; }
  int pop() { return (empty() ? -1 : arr[--_size]); }
  int size() { return _size; }
  bool empty() { return _size == 0; }
  int top() { return (empty() ? -1 : arr[_size - 1]); }
  void clear() { _size = 0; }

  int arr[50];
  int _size = 0;
};

Stack s;
std::string in;
int T;

int main()
{
  std::cin >> T;
  for(int i = 0; i < T; ++i) {
    bool correct = true;
    s.clear();
    std::cin >> in;
    for(auto c : in) {
      switch(c) {
      case '(':
        s.push('(');
        break;
      case ')':
        if(s.pop() == -1)
          correct = false;
        break;
      }
    }
    std::cout << (correct && s.empty() ? "YES" : "NO") << std::endl;
  }

  return 0;
}