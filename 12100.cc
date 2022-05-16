#include <iostream>

int map[21][21], N, ans;
int distinctBlock[21], distinctCnt, prev;

void moveUp()
{
  for(int c = 1; c <= N; ++c) {
    int r = 1;
    distinctCnt = prev = 0;
    
    while(r <= N + 1) {
      if(map[r][c] == 0 && r < N + 1) {
        ++r;
        continue;
      }

      if (prev == 0) {
        prev = map[r][c];
      } else if(prev == map[r][c]) {
        if((prev << 1) > ans)
          ans = (prev << 1);
        distinctBlock[distinctCnt++] = (prev << 1);
        prev = 0;
      } else {
        distinctBlock[distinctCnt++] = prev;
        prev = map[r][c];
      }
      ++r;
    }

    int i = 0;
    for(r = 1; i < distinctCnt; ++r, ++i)
      map[r][c] = distinctBlock[i];
    for(; r <= N; ++r)
      map[r][c] = 0;
  }
}
void moveDown()
{
  for(int c = 1; c <= N; ++c) {
    int r = N;
    distinctCnt = prev = 0;
    
    while(r >= 0) {
      if(map[r][c] == 0 && r > 0) {
        --r;
        continue;
      }

      if (prev == 0) {
        prev = map[r][c];
      } else if(prev == map[r][c]) {
        if((prev << 1) > ans)
          ans = (prev << 1);
        distinctBlock[distinctCnt++] = (prev << 1);
        prev = 0;
      } else {
        distinctBlock[distinctCnt++] = prev;
        prev = map[r][c];
      }
      --r;
    }
    
    int i = 0;
    for(r = N; i < distinctCnt; --r, ++i)
      map[r][c] = distinctBlock[i];
    for(; r > 0; --r)
      map[r][c] = 0;
  }
}
void moveLeft()
{
  for(int r = 1; r <= N; ++r) {
    int c = 1;
    distinctCnt = prev = 0;
    
    while(c <= N + 1) {
      if(map[r][c] == 0 && c < N + 1) {
        ++c;
        continue;
      }

      if (prev == 0) {
        prev = map[r][c];
      } else if(prev == map[r][c]) {
        if((prev << 1) > ans)
          ans = (prev << 1);
        distinctBlock[distinctCnt++] = (prev << 1);
        prev = 0;
      } else {
        distinctBlock[distinctCnt++] = prev;
        prev = map[r][c];
      }
      ++c;
    }

    int i = 0;
    for(c = 1; i < distinctCnt; ++c, ++i)
      map[r][c] = distinctBlock[i];
    for(; c <= N; ++c)
      map[r][c] = 0;
  }
}
void moveRight()
{
  for(int r = 1; r <= N; ++r) {
    int c = N;
    distinctCnt = prev = 0;
    
    while(c >= 0) {
      if(map[r][c] == 0 && c > 0) {
        --c;
        continue;
      }

      if (prev == 0) {
        prev = map[r][c];
      } else if(prev == map[r][c]) {
        if((prev << 1) > ans)
          ans = (prev << 1);
        distinctBlock[distinctCnt++] = (prev << 1);
        prev = 0;
      } else {
        distinctBlock[distinctCnt++] = prev;
        prev = map[r][c];
      }
      --c;
    }

    int i = 0;
    for(c = N; i < distinctCnt; --c, ++i)
      map[r][c] = distinctBlock[i];
    for(; c > 0; --c)
      map[r][c] = 0;
  }
}

void DFS(int actionCnt)
{
  if(actionCnt == 5)
    return;

  int map_copy[21][21];
  for(int i = 1; i <= N; ++i)
    for(int j = 1; j <= N; ++j)
      map_copy[i][j] = map[i][j];

  moveUp();
  DFS(actionCnt + 1);
  for(int i = 1; i <= N; ++i)
    for(int j = 1; j <= N; ++j)
      map[i][j] = map_copy[i][j];

  moveDown();
  DFS(actionCnt + 1);
  for(int i = 1; i <= N; ++i)
    for(int j = 1; j <= N; ++j)
      map[i][j] = map_copy[i][j];

  moveLeft();
  DFS(actionCnt + 1);
  for(int i = 1; i <= N; ++i)
    for(int j = 1; j <= N; ++j)
      map[i][j] = map_copy[i][j];
  
  moveRight();
  DFS(actionCnt + 1);
  for(int i = 1; i <= N; ++i)
    for(int j = 1; j <= N; ++j)
      map[i][j] = map_copy[i][j];
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N;
  for(int i = 1; i <= N; ++i) {
    for(int j = 1; j <= N; ++j) {
      std::cin >> map[i][j];
      if(map[i][j] > ans)
        ans = map[i][j];
    }
  }

  DFS(0);

  std::cout << ans << std::endl;

  return 0;
}