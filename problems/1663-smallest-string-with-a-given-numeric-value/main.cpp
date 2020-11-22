#include <cassert>
#include <string>

std::string getSmallestString(int n, int k) {
    std::string ret(n, 0);

    while (true) {
        if (k - (n - 1) >= 26) {
            ret[n - 1] = 'z';
            k -= 26;
        } else {
            ret[n - 1] = k - (n - 1) + 'a' - 1;
            --n;
            break;
        }

        --n;
    }

    for (int i = n; i > 0; --i) {
        ret[i - 1] = 'a';
    }

    return ret;
}

int main() {
    assert(getSmallestString(3, 27) == "aay");
    assert(getSmallestString(5, 73) == "aaszz");
    return 0;
}
