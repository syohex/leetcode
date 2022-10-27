#include <cassert>
#include <vector>
#include <string>

bool haveConflict(const std::vector<std::string> &event1, const std::vector<std::string> &event2) {
    const auto toSeconds = [](const std::string &s) -> int {
        int min10 = s[0] - '0';
        int min1 = s[1] - '0';

        int sec10 = s[3] - '0';
        int sec1 = s[4] - '0';

        return (min10 * 10 + min1) * 60 + (sec10 * 10) + sec1;
    };

    int start1 = toSeconds(event1[0]);
    int end1 = toSeconds(event1[1]);
    int start2 = toSeconds(event2[0]);
    int end2 = toSeconds(event2[1]);

    if (start1 <= start2) {
        return start2 <= end1;
    } else {
        return start1 <= end2;
    }
}

int main() {
    {
        std::vector<std::string> event1{"01:15", "02:00"};
        std::vector<std::string> event2{"02:00", "03:00"};
        assert(haveConflict(event1, event2));
    }
    {
        std::vector<std::string> event1{"02:00", "03:00"};
        std::vector<std::string> event2{"01:15", "02:00"};
        assert(haveConflict(event1, event2));
    }
    {
        std::vector<std::string> event1{"01:00", "02:00"};
        std::vector<std::string> event2{"01:20", "03:00"};
        assert(haveConflict(event1, event2));
    }
    {
        std::vector<std::string> event1{"10:15", "11:00"};
        std::vector<std::string> event2{"14:00", "15:00"};
        assert(!haveConflict(event1, event2));
    }
    {
        std::vector<std::string> event1{"14:00", "15:00"};
        std::vector<std::string> event2{"10:15", "11:00"};
        assert(!haveConflict(event1, event2));
    }
    return 0;
}
