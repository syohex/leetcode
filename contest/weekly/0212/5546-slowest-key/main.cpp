#include <cassert>
#include <vector>
#include <cstdio>
#include <string>

char slowestKey(const std::vector<int> &releaseTimes, const std::string &keysPressed) {
    int max_time = -1;
    char ret = 0;
    int prev = 0;
    for (size_t i = 0; i < keysPressed.size(); ++i) {
        int t = releaseTimes[i] - prev;
        if (t > max_time) {
            ret = keysPressed[i];
            max_time = t;
        } else if (t == max_time && keysPressed[i] > ret) {
            ret = keysPressed[i];
        }

        prev = releaseTimes[i];
    }

    return ret;
}

int main() {
    {
        std::vector<int> times{9, 29, 49, 50};
        assert(slowestKey(times, "cbcd") == 'c');
    }
    {
        std::vector<int> times{12, 23, 36, 46, 62};
        assert(slowestKey(times, "spuda") == 'a');
    }
    return 0;
}
