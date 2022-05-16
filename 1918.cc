#include <iostream>
#include <string>

std::string equation;
char stack[100]; int top = -1;

int main()
{
  std::cin >> equation;

  for(int i = 0; i < equation.size(); ++i) {
    if('A' <= equation[i] && equation[i] <= 'Z')
      std::cout << equation[i];
    else if(equation[i] == '(')
      stack[++top] = '(';
    else if(equation[i] == ')') {
      char c;
      while((c = stack[top--]) != '(')
        std::cout << c;
    } else {
      if(top == -1 || stack[top] == '(') {
        stack[++top] = equation[i];
        continue;
      }
      
      if(equation[i] == '*' || equation[i] == '/') {
        while(top != -1 && (stack[top] == '*' || stack[top] == '/') && stack[top] != '(')
          std::cout << stack[top--];
        stack[++top] = equation[i];
      } else {
        while(top != -1 && stack[top] != '(')
          std::cout << stack[top--];
        stack[++top] = equation[i];
      }
    }
  }

  while(top != -1)
    std::cout << stack[top--];
  std::cout << std::endl;

  return 0;
}