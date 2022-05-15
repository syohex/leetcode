#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int divisorSubstring(int num, int k) {
    int n = num;
    std::vector<int> v;
    while (n > 0) {
        v.push_back(n % 10);
        n /= 10;
    }

    std::reverse(v.begin(), v.end());

    int ret = 0;
    int len = v.size();
    for (int i = 0; i <= len - k; ++i) {
        int sum = 0;
        for (int j = 0; j < k; ++j) {
            sum = sum * 10 + v[i + j];
        }

        if (sum != 0 && num % sum == 0) {
            ++ret;
        }
    }

    return ret;
}

int main() {
    assert(divisorSubstring(240, 2) == 2);
    assert(divisorSubstring(430043, 2) == 2);
    return 0;
}
