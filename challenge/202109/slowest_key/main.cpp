#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

char slowestKey(const std::vector<int> &releaseTimes, const std::string &keysPressed) {
    char ret = keysPressed[0];
    int max_diff = releaseTimes[0];
    int len = releaseTimes.size();

    for (int i = 1; i < len; ++i) {
        int diff = releaseTimes[i] - releaseTimes[i - 1];
        if (max_diff < diff) {
            max_diff = diff;
            ret = keysPressed[i];
        } else if (max_diff == diff) {
            ret = std::max(ret, keysPressed[i]);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> releaseTimes{9, 29, 49, 50};
        const std::string keysPressed("cbcd");
        assert(slowestKey(releaseTimes, keysPressed) == 'c');
    }
    {
        std::vector<int> releaseTimes{12, 23, 36, 46, 62};
        const std::string keysPressed("spuda");
        assert(slowestKey(releaseTimes, keysPressed) == 'a');
    }
    return 0;
}