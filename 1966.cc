#include <iostream>

struct Doc {
  Doc(int _key = 0, int _imp = 0) : key(_key), imp(_imp) {}
  int key, imp;
};

int T, N, M;
Doc queue[101]; 
int rear, front, size;

int main()
{
  std::cin >> T;
  for(int i = 0; i < T; ++i) {
    std::cin >> N >> M;
    front = rear = 0;
    size = N;

    for(int j = 0; j < N; ++j) {
      int tmp;
      std::cin >> tmp;
      queue[rear] = Doc(j, tmp);
      rear = (rear + 1) % 101;
    }

    int order = 0, maxPriority;
    while(size > 0) {
      maxPriority = 0;
      for(int j = front; j != rear; j = (j + 1) % 101)
        if(maxPriority < queue[j].imp)
          maxPriority = queue[j].imp;
      
      if(queue[front].imp < maxPriority) {
        queue[rear] = queue[front];
        rear = (rear + 1) % 101;
        front = (front + 1) % 101;
      } else {
        ++order;
        if(queue[front].key == M)
          break;
        front = (front + 1) % 101;
        --size;
      }
    }
    std::cout << order << "\n";
  }
  return 0;
}