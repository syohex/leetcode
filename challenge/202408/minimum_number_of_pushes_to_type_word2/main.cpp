#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

int minimumPushes(const std::string &word) {
    std::vector<int> v(26, 0);
    for (char c : word) {
        ++v[c - 'a'];
    }

    std::sort(v.begin(), v.end(), std::greater<int>{});

    int ret = 0;
    int ones = 8;
    int twos = 8;
    int threes = 8;
    for (int count : v) {
        if (count == 0) {
            break;
        }

        if (ones > 0) {
            ret += count;
            --ones;
        } else if (twos > 0) {
            ret += 2 * count;
            --twos;
        } else if (threes > 0) {
            ret += 3 * count;
            --threes;
        } else {
            ret += 4 * count;
        }
    }

    return ret;
}

int main() {
    assert(minimumPushes("abcde") == 5);
    assert(minimumPushes("xyzxyzxyzxyz") == 12);
    assert(minimumPushes("aabbccddeeffgghhiiiiii") == 24);
    assert(minimumPushes("aremgjnptohswfdkyuzvicqxb") == 52);
    return 0;
}