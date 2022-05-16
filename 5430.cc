#include <cstdio>
#include <cstring>
#include <cstdlib>

int T, n;
int deque[100001], front, rear;
bool reverse, error;
char cmd[100001], temp[500000];

int main()
{
  scanf("%d", &T);
  for(int t = 0; t < T; ++t) {
    reverse = false;
    scanf("%s %d %s", cmd, &n, temp);

    front = rear = 0;  
    char *s = strtok(temp, "[,]");
    while(s != NULL) {
      deque[rear++] = atoi(s);
      s = strtok(NULL, "[,]");
    }

    for(int i = 0; cmd[i] != 0; ++i) {
      if(cmd[i] == 'R')
        reverse = !reverse;
      else {
        if(n == 0) {
          error = true;
          break;
        }
        if(reverse) rear -= 1;
        else front += 1;
        --n;
      }
    }

    if(error) {
      printf("error\n");
      error = false;
      continue;
    }

    printf("[");
    if(reverse) {
      for(int i = rear - 1; i >= front; --i) {
        printf("%d", deque[i]);
        if(i > front)
          printf(",");
      }
    } else {
      for(int i = front; i < rear; ++i) {
        printf("%d", deque[i]);
        if(i < rear - 1)
          printf(",");
      }
    }
    printf("]\n");
  }

  return 0;
}