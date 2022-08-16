#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

std::string smallestNumber(const std::string &pattern) {
    std::string ret;
    int len = pattern.size();
    std::vector<bool> nums(10, false);
    nums[0] = true;
    int min = 1;

    for (int i = 0; i < len; ++i) {
        if (pattern[i] == 'I') {
            ret.push_back(min + '0');
            nums[min] = true;

            for (int j = min + 1; j < 10; ++j) {
                if (!nums[j]) {
                    min = j;
                    break;
                }
            }
        } else {
            int smallers = 1;
            for (int j = i + 1; j < len; ++j) {
                if (pattern[j] == 'D') {
                    ++smallers;
                } else {
                    break;
                }
            }

            for (int j = min + smallers; j < 10; ++j) {
                if (!nums[j]) {
                    ret.push_back(j + '0');
                    nums[j] = true;
                    break;
                }
            }
        }
    }

    for (int i = 1; i < 10; ++i) {
        if (!nums[i]) {
            ret.push_back(i + '0');
            break;
        }
    }

    return ret;
}

int main() {
    assert(smallestNumber("IIIDIDDD") == "123549876");
    assert(smallestNumber("DDD") == "4321");
    assert(smallestNumber("D") == "21");
    assert(smallestNumber("DDII") == "32145");
    return 0;
}
