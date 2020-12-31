#include <cassert>
#include <vector>
#include <string>

std::vector<bool> camelMatch(const std::vector<std::string> &queries, const std::string &pattern) {
    std::vector<bool> ret;
    for (const auto &query : queries) {
        size_t pos = 0;
        bool ok = true;
        for (size_t i = 0; i < query.size(); ++i) {
            char c = query[i];
            if (c >= 'A' && c <= 'Z') {
                if (pattern[pos] >= 'a' && pattern[pos] <= 'z') {
                    ok = false;
                    break;
                }

                if (pos >= pattern.size()) {
                    ok = false;
                    break;
                }

                if (c == pattern[pos]) {
                    ++pos;
                } else {
                    ok = false;
                    break;
                }
            } else {
                if (c == pattern[pos]) {
                    ++pos;
                }
            }
        }

        ret.push_back(ok && pos == pattern.size());
    }
    return ret;
}

int main() {
    // {
    //     std::vector<std::string> queries{"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"};
    //     std::vector<bool> expected{true, false, true, true, false};
    //     auto ret = camelMatch(queries, "FB");
    //     assert(ret == expected);
    // }
    // {
    //     std::vector<std::string> queries{"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"};
    //     std::vector<bool> expected{true, false, true, false, false};
    //     auto ret = camelMatch(queries, "FoBa");
    //     assert(ret == expected);
    // }
    {
        std::vector<std::string> queries{"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"};
        std::vector<bool> expected{false, true, false, false, false};
        auto ret = camelMatch(queries, "FoBaT");
        assert(ret == expected);
    }
    return 0;
}
