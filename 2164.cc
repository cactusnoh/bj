#include <iostream>

#define SIZE 500001

int N;
int queue[SIZE], front, rear, size;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL); std::cout.tie(NULL);

  std::cin >> N;
  for(int i = 0; i < N; ++i)
    queue[i] = i + 1;
  rear = N; size = N;

  while(size != 1) {
    front = (front + 1) % SIZE;
    queue[rear] = queue[front];
    rear = (rear + 1) % SIZE;
    front = (front + 1) % SIZE;
    --size;
  }

  std::cout << queue[front] << std::endl;

  return 0;
}