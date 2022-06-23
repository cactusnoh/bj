#include <vector>
#include <algorithm>

using namespace std;

long long min(long long a, long long b) {
    return a < b ? a : b;
}

long long solution(int n, vector<int> times) {
    long long left = 1, right = *std::max_element(times.begin(), times.end()) * static_cast<long long>(n);
    long long answer = right;

    while (right >= left) {
        long long mid = left + ((right - left) >> 1);
        long long cnt = 0;

        for (int i : times) {
            cnt += mid / i;
        }

        if (cnt < n) {
            left = mid + 1;
        } else {
            answer = mid;
            right = mid - 1;
        }
    }

    return answer;
}