#include <iostream>
#include <string>
#include <vector>

void tokenizer(std::vector<std::string> &token, const std::string &s, const char *delim) {
    size_t prev = 0;
    size_t curr = 0;
    while ((curr = s.find_first_of(delim, prev)) != std::string::npos) {
        if (curr - prev > 0) {
            token.emplace_back(s.substr(prev, curr - prev));
        }
        prev = curr + 1;
    }
    if (prev < s.size()) {
        token.emplace_back(s.substr(prev));
    }
}

int main() {
    std::string s = "21101393394093490";
    std::vector<std::string> token;

    tokenizer(token, s, "01");
    
    for (const auto &t : token) {
        std::cout << t << "\n";
    }

    return 0;
}