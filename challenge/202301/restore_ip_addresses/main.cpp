#include <cassert>
#include <string>
#include <vector>
#include <set>
#include <functional>
#include <algorithm>
#include <cstdio>

std::vector<std::string> restoreIpAddresses(const std::string &s) {
    std::vector<int> nums;
    for (char c : s) {
        nums.push_back(c - '0');
    }

    size_t len = s.size();
    std::function<void(int num, size_t pos, std::vector<int> &acc, std::set<std::string> &ret)> f;
    f = [&](int num, size_t pos, std::vector<int> &acc, std::set<std::string> &ret) {
        if (acc.size() == 4) {
            if (pos < len) {
                return;
            }
            std::string tmp;
            for (size_t i = 0; i < 4; ++i) {
                if (i != 0) {
                    tmp.push_back('.');
                }
                tmp += std::to_string(acc[i]);
            }
            ret.insert(tmp);
            return;
        }

        for (size_t i = pos; i < len; ++i) {
            num = num * 10 + nums[i];
            if (num > 255) {
                break;
            }

            acc.push_back(num);
            f(0, i + 1, acc, ret);
            acc.pop_back();

            if (num == 0) {
                break;
            }
        }
    };

    std::set<std::string> ret;
    std::vector<int> acc;
    f(0, 0, acc, ret);
    return std::vector<std::string>(ret.begin(), ret.end());
}

void check(std::vector<std::string> &a, std::vector<std::string> &b) {
    std::set<std::string> sa(a.begin(), a.end());
    std::set<std::string> sb(b.begin(), b.end());
    assert(sa == sb);
}

int main() {
    {
        std::string s("25525511135");
        std::vector<std::string> expected{"255.255.11.135", "255.255.111.35"};
        auto ret = restoreIpAddresses(s);
        check(ret, expected);
    }
    {
        std::string s("0000");
        std::vector<std::string> expected{"0.0.0.0"};
        auto ret = restoreIpAddresses(s);
        check(ret, expected);
    }
    {
        std::string s("101023");
        std::vector<std::string> expected{"1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"};
        auto ret = restoreIpAddresses(s);
        check(ret, expected);
    }
    return 0;
}
