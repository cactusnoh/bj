#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using Millisec = int;
using pmm = std::pair<Millisec, Millisec>;

Millisec ConvertTime(std::string timestamp) {
  size_t first_colon = timestamp.find_first_of(':');
  size_t second_colon = timestamp.find_first_of(':', first_colon + 1);

  double hour = std::stod(timestamp.substr(0, first_colon));
  double minute = std::stod(timestamp.substr(first_colon + 1, second_colon - first_colon));
  double second = std::stod(timestamp.substr(second_colon + 1));

  return (hour * 3600 + minute * 60 + second) * 1000;
}

int solution(std::vector<std::string> lines) {
  std::vector<pmm> requests;
  int answer = 0;

  for (int i = 0; i < lines.size(); ++i) {
    size_t first_space = lines[i].find_first_of(' ');
    size_t last_space = lines[i].find_last_of(' ');
    size_t s_idx = lines[i].find_last_of('s');

    Millisec timestamp = ConvertTime(lines[i].substr(first_space + 1, 12));
    Millisec duration = std::stod(lines[i].substr(last_space + 1, s_idx - last_space)) * 1000;

    requests.push_back(pmm(timestamp - duration + 1, timestamp));
  }

  for (int i = 0; i < requests.size(); ++i) {
    int count = 1;
    Millisec interval_end = requests[i].second + 1000;

    for (int j = i + 1; j < requests.size(); ++j) {
      if (interval_end > requests[j].first) {
        count++;
      }
    }

    if (answer < count) {
      answer = count;
    }
  }
  
  return answer;
}