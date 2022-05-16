#include <iostream>
#include <string>

#define NUM 1
#define POP 2
#define INV 3
#define DUP 4
#define SWP 5
#define ADD 6
#define SUB 7
#define MUL 8
#define DIV 9
#define MOD 10
#define END 11

#define INF 1000000000

inline long long abs(long long a)
{
  return a < 0 ? -a : a;
}

int commands[100000][2], cmdCnt;
long long stack[1000]; int stackSize;

void push(long long i)
{
  stack[stackSize++] = i;
}

void pop()
{
  --stackSize;
}

long long top()
{
  return stack[stackSize - 1];
}

void executeCommands(int firstNum)
{
  stackSize = 0;
  push(firstNum);

  for(int c = 0; c < cmdCnt; ++c) {
    if(commands[c][0] == END) {
      if(stackSize != 1) {std::cout << "ERROR" << std::endl; return; }
      else std::cout << top() << std::endl;
    } else if(commands[c][0] == NUM) {
      push(commands[c][1]);
    } else if(commands[c][0] == POP) {
      if(stackSize == 0) {std::cout << "ERROR" << std::endl; return; }
      else pop();
    } else if(commands[c][0] == INV) {
      if(stackSize == 0) {std::cout << "ERROR" << std::endl; return; }
      else stack[stackSize - 1] = -stack[stackSize - 1];
    } else if(commands[c][0] == DUP) {
      if(stackSize == 0) {std::cout << "ERROR" << std::endl; return; }
      else push(stack[stackSize - 1]);
    } else if(commands[c][0] == SWP) {
      if(stackSize < 2) {std::cout << "ERROR" << std::endl; return; }
      else {
        int first = top(); pop();
        int second = top(); pop();
        push(first); push(second);
      }
    } else if(commands[c][0] == ADD) {
      if(stackSize < 2) {std::cout << "ERROR" << std::endl; return; }
      else {
        int first = top(); pop();
        int second = top(); pop();
        if(abs(first + second) > INF) {std::cout << "ERROR" << std::endl; return; }
        push(first + second);
      }
    } else if(commands[c][0] == SUB) {
      if(stackSize < 2) {std::cout << "ERROR" << std::endl; return; }
      else {
        int first = top(); pop();
        int second = top(); pop();
        if(abs(second - first) > INF) {std::cout << "ERROR" << std::endl; return; }
        push(second - first);
      }
    } else if(commands[c][0] == MUL) {
      if(stackSize < 2) {std::cout << "ERROR" << std::endl; return; }
      else {
        long long first = top(); pop();
        long long second = top(); pop();
        if(abs(first * second) > INF) {std::cout << "ERROR" << std::endl; return; }
        push(second * first);
      }
    } else if(commands[c][0] == DIV) {
      if(stackSize < 2) {std::cout << "ERROR" << std::endl; return; }
      else {
        int first = top(); pop();
        int second = top(); pop();
        if(first == 0) {std::cout << "ERROR" << std::endl; return; }
        push(second / first);
      }
    } else if(commands[c][0] == MOD) {
      if(stackSize < 2) {std::cout << "ERROR" << std::endl; return; }
      else {
        int first = top(); pop();
        int second = top(); pop();
        if(first == 0) {std::cout << "ERROR" << std::endl; return; }
        push(second - first * (second / first));
      }
    }
  }
}

int main()
{
  std::string temp;

  while(1) {
    cmdCnt = 0;
    while(1) {
      std::cin >> temp;
      if(temp == "QUIT") return 0;
      if(temp == "END") {
        commands[cmdCnt++][0] = END;
        break;
      } else if(temp == "NUM") {
        int i;
        std::cin >> i;
        commands[cmdCnt][0] = NUM;
        commands[cmdCnt++][1] = i;
      } else if(temp == "POP")
        commands[cmdCnt++][0] = POP;
        else if(temp == "INV")
        commands[cmdCnt++][0] = INV;
        else if(temp == "DUP")
        commands[cmdCnt++][0] = DUP;
        else if(temp == "SWP")
        commands[cmdCnt++][0] = SWP;
        else if(temp == "ADD")
        commands[cmdCnt++][0] = ADD;
        else if(temp == "SUB")
        commands[cmdCnt++][0] = SUB;
        else if(temp == "MUL")
        commands[cmdCnt++][0] = MUL;
        else if(temp == "DIV")
        commands[cmdCnt++][0] = DIV;
        else if(temp == "MOD")
        commands[cmdCnt++][0] = MOD;
    }

    int execute;
    std::cin >> execute;
    for(int i = 0; i < execute; ++i) {
      int firstNum;
      std::cin >> firstNum;
      executeCommands(firstNum);
    }
    std::cout << "\n";
  }

  return 0;
}