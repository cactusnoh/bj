#include <iostream>

int n;
int stack[100001], stackSize;
int operations[200001], opCnt;

void push(int x)
{
  stack[stackSize++] = x;
}

int pop()
{
  return stack[--stackSize];
}

int top()
{
  return stack[stackSize - 1];
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL); std::cout.tie(NULL);

  bool fail = false;
  std::cin >> n;

  int toPush = 1;

  for(int i = 0; i < n; ++i) {
    int in;
    std::cin >> in;

    while(stackSize == 0 || in > top()) {
      operations[opCnt++] = 1;
      push(toPush++);
    }

    if(top() == in) {
      operations[opCnt++] = 0;
      pop();
    } else {
      fail = true;
      break;
    }
  }

  if(fail) {
    std::cout << "NO" << std::endl;
    return 0;
  }

  for(int i = 0; i < opCnt; ++i)
    std::cout << (operations[i] ? "+" : "-") << "\n";

  return 0;
}