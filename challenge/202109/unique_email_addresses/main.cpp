#include <cassert>
#include <vector>
#include <string>
#include <set>

int numUniqueEmails(const std::vector<std::string> &emails) {
    std::set<std::string> s;
    for (const auto &email : emails) {
        std::string tmp;
        size_t i = 0;
        size_t limit = email.size();
        bool read_atmark = false;
        while (i < limit) {
            if (!read_atmark) {
                if (email[i] == '.') {
                    ++i;
                    continue;
                }
                if (email[i] == '+') {
                    ++i;
                    while (i < limit && email[i] != '@') {
                        ++i;
                    }

                    if (i >= limit) {
                        continue;
                    }
                }
            }

            if (email[i] == '@') {
                read_atmark = true;
            }
            tmp.push_back(email[i]);
            ++i;
        }

        s.insert(tmp);
    }

    return static_cast<int>(s.size());
}

int main() {
    {
        std::vector<std::string> emails{"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com",
                                        "testemail+david@lee.tcode.com"};
        assert(numUniqueEmails(emails) == 2);
    }
    {
        std::vector<std::string> emails{"a@leetcode.com", "b@leetcode.com", "c@leetcode.com"};
        assert(numUniqueEmails(emails) == 3);
    }
    return 0;
}
