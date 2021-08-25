#include <cassert>
#include <set>

bool judgeSquareSum(int c) {
    std::set<int> s;
    for (long i = 0;; ++i) {
        auto tmp = i * i;
        if (tmp > c) {
            break;
        }

        s.insert(static_cast<int>(tmp));
    }

    for (int i : s) {
        int v = c - i;
        if (s.find(v) != s.end()) {
            return true;
        }
    }

    return false;
}

int main() {
	assert(judgeSquareSum(5));
	assert(!judgeSquareSum(3));
	assert(judgeSquareSum(4));
	assert(judgeSquareSum(2));
	assert(judgeSquareSum(1));
	assert(judgeSquareSum(37));
	assert(judgeSquareSum(40));
	return 0;
}
