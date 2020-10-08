#include <cassert>
#include <vector>
#include <cstdio>

bool validMountainArray(const std::vector<int> &A) {
    if (A.size() < 3) {
        return false;
    }

    enum class State {
        kNone,
        kUp,
        kDown,
    };

    State prev = State::kNone;
    for (size_t i = 1; i < A.size(); ++i) {
        if (A[i - 1] < A[i]) {
            if (prev == State::kDown) {
                return false;
            }
            prev = State::kUp;
        } else if (A[i - 1] == A[i]) {
            return false;
        } else {
            if (prev == State::kNone) {
                return false;
            }
            prev = State::kDown;
        }
    }

    return prev == State::kDown;
}

int main() {
    assert((!validMountainArray(std::vector<int>{2, 1})));
    assert((!validMountainArray(std::vector<int>{3, 5, 5})));
    assert((validMountainArray(std::vector<int>{0, 3, 2, 1})));
    assert((!validMountainArray(std::vector<int>{0, 1, 2, 3, 4, 5})));
    return 0;
}
