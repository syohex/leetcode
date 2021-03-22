#include <cassert>
#include <string>
#include <queue>
#include <set>

int secondHighest(const std::string &s) {
    std::set<int> set;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            set.insert(c - '0');
        }
    }

    if (set.size() <= 1) {
        return -1;
    }

    std::priority_queue<int> q;
    for (int n : set) {
        q.push(n);
    }

    q.pop();
    return q.top();
}

int main() {
    assert(secondHighest("dfa12321afd") == 2);
    assert(secondHighest("abc1111") == -1);
    assert(secondHighest("abc98") == 8);
    assert(secondHighest("abc33333444") == 3);
    return 0;
}
