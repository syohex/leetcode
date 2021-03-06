#include <cassert>
#include <vector>
#include <string>

std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> ret;
    for (int i = 1; i <= n; ++i) {
        if (i % 3 == 0 && i % 5 == 0) {
            ret.emplace_back("FizzBuzz");
        } else if (i % 5 == 0) {
            ret.emplace_back("Buzz");
        } else if (i % 3 == 0) {
            ret.emplace_back("Fizz");
        } else {
            ret.emplace_back(std::to_string(i));
        }
    }
    return ret;
}

int main() {
    {
        std::vector<std::string> expected{"1",    "2",    "Fizz", "4",    "Buzz", "Fizz", "7",       "8",
                                          "Fizz", "Buzz", "11",   "Fizz", "13",   "14",   "FizzBuzz"};
        auto ret = fizzBuzz(15);
        assert(ret == expected);
    }
    {
        auto ret = fizzBuzz(0);
        assert(ret.empty());
    }
    return 0;
}
