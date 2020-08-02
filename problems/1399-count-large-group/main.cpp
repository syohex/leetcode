#include <cassert>
#include <vector>
#include <map>

int countLargestGroup(int n) {
    if (n < 10) {
        return n;
    }

    std::map<int, std::vector<int>> m;
    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        int j = i;
        while (j > 0) {
            sum += (j % 10);
            j /= 10;
        }

        m[sum].push_back(i);
    }

    size_t max = 0;
    int ret = 0;
    for (const auto &it : m) {
        size_t size = it.second.size();
        if (size > max) {
            max = size;
            ret = 1;
        } else if (size == max) {
            ++ret;
        }
    }

    return ret;
}

int main() {
    assert(countLargestGroup(13) == 4);
    assert(countLargestGroup(2) == 2);
    assert(countLargestGroup(15) == 6);
    assert(countLargestGroup(24) == 5);
    assert(countLargestGroup(46) == 6);
    return 0;
}
