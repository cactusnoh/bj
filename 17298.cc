#include <iostream>

int N;
int stack[1000001], stackSize;
int seq[1000000];
int result[1000000];

void push(int i)
{
  stack[stackSize++] = i;
}

void pop()
{
  --stackSize;
}

int top()
{
  if(stackSize == 0)
    return -1;
  return stack[stackSize - 1];
}

int main()
{
  std::cin >> N;

  for(int i = 0; i < N; ++i)
    std::cin >> seq[i];

  for(int i = N - 1; i >= 0; --i) {
    while(stackSize != 0 && top() <= seq[i])
      pop();
    result[i] = top();
    push(seq[i]);
  }

  for(int i = 0; i < N; ++i)
    std::cout << result[i] << " ";
  std::cout << std::endl;

  return 0;
}