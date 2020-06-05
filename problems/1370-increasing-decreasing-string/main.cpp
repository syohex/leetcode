#include <cassert>
#include <string>
#include <vector>

std::string sortString(const std::string &s) {
    std::string ret(s.size(), '0');
    size_t index = 0;
    std::vector<bool> indexes(s.size(), true);

    while (index < s.size()) {
        char last_appended = 'a' - 1;
        while (true) {
            char smallest = 'z' + 1;
            size_t min_index = 0;

            for (size_t i = 0; i < s.size(); ++i) {
                if (!indexes[i]) {
                    continue;
                }

                if (last_appended < s[i] && s[i] < smallest) {
                    smallest = s[i];
                    min_index = i;
                }
            }

            if (smallest == 'z' + 1) {
                break;
            }

            ret[index++] = smallest;
            indexes[min_index] = false;
            last_appended = smallest;
        }

        last_appended = 'z' + 1;
        while (true) {
            char largest = 'a' - 1;
            size_t max_index = 0;

            for (size_t i = 0; i < s.size(); ++i) {
                if (!indexes[i]) {
                    continue;
                }

                if (s[i] < last_appended && s[i] > largest) {
                    largest = s[i];
                    max_index = i;
                }
            }

            if (largest == 'a' - 1) {
                break;
            }

            ret[index++] = largest;
            indexes[max_index] = false;
            last_appended = largest;
        }
    }

    return ret;
}

int main() {
    assert((sortString("aaaabbbbcccc") == "abccbaabccba"));
    assert((sortString("rat") == "art"));
    assert((sortString("leetcode") == "cdelotee"));
    assert((sortString("gggggggg") == "gggggggg"));
    assert((sortString("spo") == "ops"));
    return 0;
}