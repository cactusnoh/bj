#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  
  int N;
  std::cin >> N;

  char cmd[10];

  int front = -1, back = -1;
  int queue[10'000];
  for (int i = 0; i < N; ++i) {
    std::cin >> cmd;
    if (cmd[0] == 'p' && cmd[1] == 'u') {
      std::cin >> queue[++back];
    } else if (cmd[0] == 'p' && cmd[1] == 'o') {
      if (front == back) {
        std::cout << -1 << "\n";
        continue;
      }
      std::cout << queue[++front] << "\n";
    } else if (cmd[0] == 's') {
      std::cout << back - front << "\n";
    } else if (cmd[0] == 'e') {
      std::cout << (front == back ? 1 : 0) << "\n";
    } else if (cmd[0] == 'f') {
      if (front == back) {
        std::cout << -1 << "\n";
      } else {
        std::cout << queue[front + 1] << "\n";
      }
    } else if (cmd[0] == 'b') {
      if (front == back) {
        std::cout << -1 << "\n";
      } else {
        std::cout << queue[back] << "\n";
      }
    }
  }

  return 0;
}