#include <cassert>
#include <string>

int minimumLength(const std::string &s) {
    int len = s.size();
    int left = 0;
    int right = len - 1;

    while (left < right) {
        char left_end = s[left];
        char right_end = s[right];

        if (left_end != right_end) {
            break;
        }

        ++left;
        --right;

        while (left <= right && s[left] == left_end) {
            ++left;
        }

        while (left <= right && s[right] == right_end) {
            --right;
        }
    }

    if (left > right) {
        return 0;
    }

    return right - left + 1;
}

int main() {
    assert(minimumLength("ca") == 2);
    assert(minimumLength("cabaabac") == 0);
    assert(minimumLength("aabccabba") == 3);
    assert(minimumLength("abbbbbbbbbbbbbbbbbbba") == 0);
    return 0;
}
