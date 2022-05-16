#include <iostream>

int N;
int a[1000000];

int partition(int l, int r)
{
  if(l >= r)
    return l;

  int temp;
  int i = l - 1, j = r, v = a[r];

  while(1) {
    while(a[++i] < v);
    while(a[--j] > v)
      if(j == l) 
        break;
    if(i >= j) break;

    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
  }

  temp = a[i];
  a[i] = a[r];
  a[r] = temp;

  return i;
}

void quick_sort(int l, int r)
{
  if(l >= r)
    return;

  int temp, mid = (l + r) / 2;
  temp = a[mid];
  a[mid] = a[r - 1];
  a[r - 1] = temp;
  if(a[l] > a[r - 1]) {
    temp = a[l];
    a[l] = a[r - 1];
    a[r - 1] = temp;
  }
  if(a[r - 1] > a[r]) {
    temp = a[r - 1];
    a[r - 1] = a[r];
    a[r] = temp;
  }
  if(a[l] > a[r - 1]) {
    temp = a[l];
    a[l] = a[r - 1];
    a[r - 1] = temp;
  }
  int i = partition(l + 1, r - 1);
  quick_sort(l, i - 1);
  quick_sort(i + 1, r);
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N;
  for(int i = 0; i < N; ++i)
    std::cin >> a[i];

  quick_sort(0, N - 1);

  for(int i = 0; i < N; ++i)
    std::cout << a[i] << "\n";

  return 0;
}