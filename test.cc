#include <iostream>

#define MASK 15

int N;

inline int abs(int a)
{
  return a < 0 ? -a : a;
}

int upper_bound(int arr[], int beg, int end, int x)
{
  int mid;
  while(beg < end) {
    mid = beg + ((end - beg) >> 1);
    if(arr[mid] > x)
      end = mid;
    else
      beg = mid + 1;
  }
  return end;
}

int main()
{
  std::cin >> N;
  int arr[10] = {1, 1, 2, 3, 3, 3, 4, 5, 19, 19};
  std::cout << upper_bound(arr, 0, 9, N) << std::endl;
  return 0;
}