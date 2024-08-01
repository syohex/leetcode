#include <cassert>
#include <vector>
#include <string>

int countSeniors(const std::vector<std::string> &details) {
    int ret = 0;
    for (const auto &detail : details) {
        int age = (detail[11] - '0') * 10 + (detail[12] - '0');
        if (age > 60) {
            ++ret;
        }
    }
    return ret;
}

int main() {
    {
        std::vector<std::string> details{"7868190130M7522", "5303914400F9211", "9273338290F4010"};
        int ret = countSeniors(details);
        assert(ret == 2);
    }
    {
        std::vector<std::string> details{"1313579440F2036", "2921522980M5644"};
        int ret = countSeniors(details);
        assert(ret == 0);
    }
    return 0;
}