#include <iostream>

int N;
int rectangle[1001][4];
int parent[1001];

/**
 * @brief Tell whether two rectangles a and b are intersecting
 * @param a rectangle a
 * @param b rectangle b
 * @return true if intersecting
 * @return false if not
 */
bool intersect(const int *a, const int *b) {
  if (a[2] < b[0] || b[2] < a[0] || b[3] < a[1] || a[3] < b[1] ||
      (a[0] < b[0] && b[2] < a[2] && a[1] < b[1] && b[3] < a[3]) ||
      (b[0] < a[0] && a[2] < b[2] && b[1] < a[1] && a[3] < b[3])) {
    return false;
  }
  return true;
}

// Disjoint Union Set

int get_parent(int x) {
  if (parent[x] == x) {
    return x;
  }
  return (parent[x] = get_parent(parent[x]));
}

void merge(int a, int b) {
  a = get_parent(a);
  b = get_parent(b);

  if (a > b) {
    int temp = a;
    a = b;
    b = temp;
  }

  parent[b] = a;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  // Origin
  rectangle[0][0] = 0;
  rectangle[0][1] = 0;
  rectangle[0][2] = 0;
  rectangle[0][3] = 0;

  // Check if rectangles are intersecting. If they are, merge them.
  int x1, y1, x2, y2;
  for (int i = 1; i <= N; ++i) {
    std::cin >> x1 >> y1 >> x2 >> y2;
    rectangle[i][0] = x1;
    rectangle[i][1] = y1;
    rectangle[i][2] = x2;
    rectangle[i][3] = y2;
    parent[i] = i;
    for (int j = 0; j < i; ++j) {
      if (intersect(rectangle[j], rectangle[i])) {
        merge(j, i);
      }
    }
  }

  // Find number of disjoint sets 
  int ret = 0;
  for (int i = 0; i <= N; ++i) {
    if (get_parent(i) == i) {
      ++ret;
    }
  }

  // Subtracting 1 because of origin
  std::cout << ret - 1 << "\n";

  return 0;
}