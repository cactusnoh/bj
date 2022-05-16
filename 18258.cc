#include <iostream>
#include <string>

#define SIZE 2000000

int N;
int queue[SIZE], front, rear;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL); std::cout.tie(NULL);

  std::string cmd;
  std::cin >> N;
  for(int i = 0; i < N; ++i) {
    std::cin >> cmd;
    if(cmd[1] == 'u') {
      std::cin >> queue[rear];
      rear = (rear + 1) % SIZE;
    } else if(cmd[1] == 'o') {
      if(rear == front)
        std::cout << -1 << "\n";
      else {
        std::cout << queue[front] << "\n";
        front = (front + 1) % SIZE;
      }
    } else if(cmd[0] == 's') {
      std::cout << rear - front << "\n";
    } else if(cmd[0] == 'e') {
      std::cout << (rear == front) << "\n";
    } else if(cmd[0] == 'f') {
      std::cout << (rear == front ? -1 : queue[front]) << "\n";
    } else if(cmd[0] == 'b') {
      std::cout << (rear == front ? -1 : queue[rear - 1]) << "\n";
    }
  }

  return 0;
}