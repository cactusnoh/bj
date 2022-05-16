#include <iostream>
#include <string>

struct Stack {
  void push(int x) { arr[_size++] = x; }
  int pop() { return (empty() ? -1 : arr[--_size]); }
  int size() { return _size; }
  bool empty() { return _size == 0; }
  int top() { return (empty() ? -1 : arr[_size - 1]); }
  void clear() { _size = 0; }

  int arr[100];
  int _size = 0;
};

Stack s;
std::string in;

int main()
{
  char c;
  bool correct = true;

  while(std::getline(std::cin, in)) {
    if(in[0] == '.')
      break;
    for(auto c : in) {
      if(c == '(') {
        s.push('(');
      } else if(c == ')') {
        if(s.pop() != '(')
          correct = false;
      } else if(c == '[') {
        s.push('[');
      } else if(c == ']') {
        if(s.pop() != '[')
          correct = false;
      } else if(c == '.') {
        std::cout << (correct && s.empty() ? "yes" : "no") << std::endl;
        s.clear();
        correct = true;
      }
    }
  }

  return 0;
}