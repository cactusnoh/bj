#include <iostream>

typedef std::pair<int, int> pii;

int N, ansB, ansW;
pii blackCheck[50], whiteCheck[50]; int blackCnt, whiteCnt;
bool down_right[21], up_right[21];

void blackDFS(int idx, int cnt)
{
  if(idx == blackCnt) {
    if(ansB < cnt)
      ansB = cnt;
    return;
  }

  int r = blackCheck[idx].first, c = blackCheck[idx].second;

  if(down_right[c - r + (N - 1)] || up_right[r + c]) {
    blackDFS(idx + 1, cnt);
    return;
  }
  
  blackDFS(idx + 1, cnt);
  down_right[c - r + (N - 1)] = up_right[r + c] = true;
  blackDFS(idx + 1, cnt + 1);
  down_right[c - r + (N - 1)] = up_right[r + c] = false;
}

void whiteDFS(int idx, int cnt)
{
  if(idx == whiteCnt) {
    if(ansW < cnt)
      ansW = cnt;
    return;
  }

  int r = whiteCheck[idx].first, c = whiteCheck[idx].second;

  if(down_right[c - r + (N - 1)] || up_right[r + c]) {
    whiteDFS(idx + 1, cnt);
    return;
  }
  
  whiteDFS(idx + 1, cnt);
  down_right[c - r + (N - 1)] = up_right[r + c] = true;
  whiteDFS(idx + 1, cnt + 1);
  down_right[c - r + (N - 1)] = up_right[r + c] = false;
}


int main()
{
  std::cin >> N;

  int temp;
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      std::cin >> temp;
      if(temp && (i + j) % 2)
        blackCheck[blackCnt++] = pii(i, j);
      if(temp && (i + j) % 2 == 0)
        whiteCheck[whiteCnt++] = pii(i, j);
    }
  }

  blackDFS(0, 0);
  whiteDFS(0, 0);

  std::cout << ansB + ansW << std::endl;

  return 0;
}