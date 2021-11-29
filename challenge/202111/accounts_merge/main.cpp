#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

std::vector<std::vector<std::string>> accountsMerge(const std::vector<std::vector<std::string>> &accounts) {
    std::map<std::string, std::vector<std::set<std::string>>> m;

    for (const auto &account : accounts) {
        const std::string &name = account[0];
        std::set<std::string> tmp;
        for (size_t i = 1; i < account.size(); ++i) {
            tmp.insert(account[i]);
        }

        m[name].push_back(tmp);
    }

    std::vector<std::vector<std::string>> ret;
    for (auto &it : m) {
        const auto &name = it.first;

        auto &addresses = it.second;
        int len = addresses.size();
        std::vector<bool> checked(len, false);
        while (true) {
            std::vector<std::vector<std::string>> candidates;
            bool no_merges = true;
            for (int i = 0; i < len; ++i) {
                if (checked[i]) {
                    continue;
                }

                auto &addrs1 = addresses[i];
                for (int j = i + 1; j < len; ++j) {
                    if (checked[j]) {
                        continue;
                    }

                    const auto &addrs2 = addresses[j];
                    bool can_merge = false;
                    for (const auto &addr1 : addrs1) {
                        if (addrs2.find(addr1) != addrs2.end()) {
                            can_merge = true;
                            break;
                        }
                    }

                    if (can_merge) {
                        no_merges = false;
                        checked[j] = true;
                        for (const auto &addr : addrs2) {
                            addrs1.insert(addr);
                        }
                    }
                }

                if (!no_merges) {
                    continue;
                }

                std::vector<std::string> tmp(addrs1.begin(), addrs1.end());
                std::sort(tmp.begin(), tmp.end());

                std::vector<std::string> candidate{name};
                std::copy(tmp.begin(), tmp.end(), std::back_inserter(candidate));
                candidates.push_back(std::move(candidate));
            }

            if (no_merges) {
                std::copy(candidates.begin(), candidates.end(), std::back_inserter(ret));
                break;
            }
        }
    }

    return ret;
}

void check(const std::vector<std::vector<std::string>> &got, const std::vector<std::vector<std::string>> &expected) {
#ifndef NEVER
    for (const auto &v : got) {
        printf("[");
        for (const auto &s : v) {
            printf(" %s ", s.c_str());
        }
        printf("]\n");
    }
#endif
    assert(got.size() == expected.size());

    std::set<std::vector<std::string>> a(got.begin(), got.end());
    std::set<std::vector<std::string>> b(expected.begin(), expected.end());
    assert(a == b);
}

int main() {
    {
        std::vector<std::vector<std::string>> accounts{
            {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
            {"John", "johnsmith@mail.com", "john00@mail.com"},
            {"Mary", "mary@mail.com"},
            {"John", "jonnybravo@gmail.com"},
        };
        std::vector<std::vector<std::string>> expected{
            {"John", "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com"},
            {"Mary", "mary@mail.com"},
            {"John", "jonnybravo@gmail.com"},
        };
        auto got = accountsMerge(accounts);
        check(got, expected);
    }
    {
        std::vector<std::vector<std::string>> accounts{
            {"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"},     {"Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"},
            {"Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"}, {"Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"},
            {"Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"},
        };
        std::vector<std::vector<std::string>> expected{
            {"Gabe", "Gabe0@m.co", "Gabe1@m.co", "Gabe3@m.co"},     {"Kevin", "Kevin0@m.co", "Kevin3@m.co", "Kevin5@m.co"},
            {"Ethan", "Ethan0@m.co", "Ethan4@m.co", "Ethan5@m.co"}, {"Hanzo", "Hanzo0@m.co", "Hanzo1@m.co", "Hanzo3@m.co"},
            {"Fern", "Fern0@m.co", "Fern1@m.co", "Fern5@m.co"},
        };
        auto got = accountsMerge(accounts);
        check(got, expected);
    }
    {
        std::vector<std::vector<std::string>> accounts{
            {"David", "David0@m.co", "David1@m.co"}, {"David", "David3@m.co", "David4@m.co"},
            {"David", "David4@m.co", "David5@m.co"}, {"David", "David2@m.co", "David3@m.co"},
            {"David", "David1@m.co", "David2@m.co"},
        };
        std::vector<std::vector<std::string>> expected{
            {"David", "David0@m.co", "David1@m.co", "David2@m.co", "David3@m.co", "David4@m.co", "David5@m.co"},
        };
        auto got = accountsMerge(accounts);
        check(got, expected);
    }
    return 0;
}