#include <cassert>
#include <vector>
#include <string>
#include <cstdio>
#include <set>

int numUniqueEmails(const std::vector<std::string> &emails) {
    std::set<std::string> uniques;
    for (const auto &email : emails) {
        std::string s;
        bool beforeAt = true;
        bool afterPlus = false;
        for (const auto c : email) {
            if (beforeAt) {
                if (c == '+') {
                    afterPlus = true;
                    continue;
                }
                if (c == '.') {
                    continue;
                }
                if (c == '@') {
                    beforeAt = false;
                    s.push_back(c);
                    continue;
                }
                if (afterPlus) {
                    continue;
                }
            }

            s.push_back(c);
        }

        uniques.insert(s);
    }

    return uniques.size();
}

int main() {
    {
        std::vector<std::string> input{
            "test.email+alex@leetcode.com",
            "test.e.mail+bob.catchy@leetcode.com",
            "testemail+david@lee.tcode.com",
        };
        assert(numUniqueEmails(input) == 2);
    }
    return 0;
}
