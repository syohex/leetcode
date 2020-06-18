#include <cassert>
#include <string>
#include <set>

int numJewelsInStones(const std::string &J, const std::string &S) {
    std::set<char> js;
    for (char c : J) {
        js.insert(c);
    }

    int ret = 0;
    for (char c : S) {
        if (js.find(c) != js.end()) {
            ++ret;
        }
    }
    return ret;
}

int main() {
    assert(numJewelsInStones("aA", "aAAbbbb") == 3);
    assert(numJewelsInStones("z", "ZZ") == 0);
    return 0;
}
