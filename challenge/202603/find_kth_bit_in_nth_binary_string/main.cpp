#include <cassert>
#include <string>

using namespace std;

char findKthBit(int n, int k) {
    string s{"0"};

    for (int i = 2; i <=n; ++i) {
        string tmp{s};
        tmp.push_back('1');
        for (int j = s.size() - 1; j >= 0; --j) {
            tmp.push_back(s[j] == '1' ? '0' : '1');
        }

        s = std::move(tmp);
    }

    return s[k - 1];
}

int main() {
    assert(findKthBit(3, 1) == '0');
    assert(findKthBit(4, 11) == '1');
    return 0;
}
