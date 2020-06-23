#include <cassert>
#include <string>

std::string reformat(const std::string &s) {
    std::string al;
    std::string num;

    for (const char c : s) {
        if (c >= '0' && c <= '9') {
            num.push_back(c);
        } else {
            al.push_back(c);
        }
    }

    int al_size = static_cast<int>(al.size());
    int num_size = static_cast<int>(num.size());

    int diff = al_size > num_size ? al_size - num_size : num_size - al_size;
    if (diff >= 2) {
        return "";
    }

    std::string ret(s.size(), 0);
    if (diff == 0) {
        for (size_t i = 0; i < al.size(); ++i) {
            ret[2 * i] = al[i];
            ret[2 * i + 1] = num[i];
        }
    } else if (diff == 1 && al_size > num_size) {
        for (size_t i = 0; i < al.size(); ++i) {
            ret[2 * i] = al[i];
        }
        for (size_t i = 0; i < num.size(); ++i) {
            ret[2 * i + 1] = num[i];
        }
    } else {
        for (size_t i = 0; i < num.size(); ++i) {
            ret[2 * i] = num[i];
        }
        for (size_t i = 0; i < al.size(); ++i) {
            ret[2 * i + 1] = al[i];
        }
    }

    return ret;
}

bool check(const std::string &got) {
    std::string al;
    std::string num;

    for (const char c : got) {
        if (c >= '0' && c <= '9') {
            num.push_back(c);
        } else {
            al.push_back(c);
        }
    }

    int diff;
    if (al.size() > num.size()) {
        diff = static_cast<int>(al.size()) - static_cast<int>(num.size());
    } else {
        diff = static_cast<int>(num.size()) - static_cast<int>(al.size());
    }

    if (diff >= 2) {
        return got.empty();
    }

    const auto isNum = [](char c) -> bool { return c >= '0' && c < '9'; };
    const auto isAl = [](char c) -> bool { return c >= 'a' && c < 'z'; };

    if (diff == 0) {
        return (isNum(got[0]) && isAl(got[1])) || (isAl(got[0]) || isNum(got[1]));
    }

    if (al.size() > num.size()) {
        return isAl(got[0]) && isNum(got[1]);
    }

    return isNum(got[0]) && isAl(got[1]);
}

int main() {
    auto ret = reformat("a0b1c2");
    assert(check(ret));

    ret = reformat("leetcode");
    assert(ret.empty());

    ret = reformat("18093409390580919");
    assert(ret.empty());

    ret = reformat("covid2019");
    assert(check(ret));

    ret = reformat("ab123");
    assert(check(ret));
    return 0;
}
