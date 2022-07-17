#include <iostream>
#include <iomanip>

struct Point {
  Point(double x = 0, double y = 0) : x_(x), y_(y) {}
  double x_;
  double y_;
};
bool operator<(const Point &lhs, const Point &rhs) {
  return (lhs.x_ == rhs.x_ ? lhs.y_ < rhs.y_ : lhs.x_ < rhs.x_);
}
bool operator>(const Point &lhs, const Point &rhs) {
  return (lhs.x_ == rhs.x_ ? lhs.y_ > rhs.y_ : lhs.x_ > rhs.x_);
}
bool operator<=(const Point &lhs, const Point &rhs) {
  return !(lhs > rhs);
}
bool operator>=(const Point &lhs, const Point &rhs) {
  return !(lhs < rhs);
}
bool operator==(const Point &lhs, const Point &rhs) {
  return lhs.x_ == rhs.x_ && lhs.y_ == rhs.y_;
}

int ccw(const Point &a, const Point &b, const Point &c) {
  double outer = (b.x_ - a.x_) * (c.y_ - a.y_) - (c.x_ - a.x_) * (b.y_ - a.y_);
  return (outer == 0 ? 0 : (outer > 0 ? 1 : -1));
}

Point intersection(Point p1, Point p2, Point p3, Point p4) {
  if (p1.x_ == p2.x_) {
    double b0 = (p4.y_ - p3.y_) / (p4.x_ - p3.x_);
    double b1 = p3.y_ - b0 * p3.x_;
    return Point(p1.x_, b0 * p1.x_ + b1);
  } else if (p3.x_ == p4.x_) {
    double a0 = (p2.y_ - p1.y_) / (p2.x_ - p1.x_);
    double a1 = p2.y_ - a0 * p2.x_;
    return Point(p3.x_, a0 * p3.x_ + a1);
  } else {
    double a0 = (p2.y_ - p1.y_) / (p2.x_ - p1.x_);
    double a1 = p2.y_ - a0 * p2.x_;
    double b0 = (p4.y_ - p3.y_) / (p4.x_ - p3.x_);
    double b1 = p3.y_ - b0 * p3.x_;
    return Point(- (a1 - b1) / (a0 - b0), (a0 * b1 - b0 * a1) / (a0 - b0));
  }
}

Point p1, p2, p3, p4;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cout << std::fixed << std::setprecision(9);

  std::cin >> p1.x_ >> p1.y_ >> p2.x_ >> p2.y_;
  std::cin >> p3.x_ >> p3.y_ >> p4.x_ >> p4.y_;

  if (p1 > p2) {
    Point temp = p1;
    p1 = p2;
    p2 = temp;
  }
  if (p3 > p4) {
    Point temp = p3;
    p3 = p4;
    p4 = temp;
  }
    
  int ans1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
  int ans2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

  if (ans1 == 0 && ans2 == 0) {
    if (p2 >= p3 && p1 <= p4) {
      std::cout << 1 << "\n";
      if (ccw(p1, p2, p3) == 0 && ccw(p1, p2, p4) == 0) {
        if (p2 == p3) {
          std::cout << p2.x_ << " " << p2.y_ << "\n";
        } else if (p4 == p1) {
          std::cout << p1.x_ << " " << p1.y_ << "\n";
        }
      } else {
        Point I = intersection(p1, p2, p3, p4); 
        std::cout << I.x_ << " " << I.y_ << "\n";
      }
    } else {
      std::cout << 0 << "\n";
    }
  } else if (ans1 <= 0 && ans2 <= 0) {
    std::cout << 1 << "\n";
    Point I = intersection(p1, p2, p3, p4); 
    std::cout << I.x_ << " " << I.y_ << "\n";
  } else {
    std::cout << 0 << "\n";
  }

  return 0;
}