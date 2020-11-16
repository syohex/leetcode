#include <cassert>
#include <vector>

int longestMountain(const std::vector<int> &A) {
    enum class State {
        kNone,
        kUp,
        kDown,
    };

    State s = State::kNone;
    int max = 0;
    int start = -1;
    int limit = static_cast<int>(A.size());
    for (int i = 0; i < limit; ++i) {
        switch (s) {
        case State::kNone: {
            if (i + 1 < limit) {
                if (A[i] < A[i + 1]) {
                    s = State::kUp;
                    start = i;
                }
            }
            break;
        }
        case State::kUp: {
            if (i + 1 < limit) {
                if (A[i] > A[i + 1]) {
                    s = State::kDown;
                } else if (A[i] == A[i + 1]) {
                    s = State::kNone;
                    start = -1;
                }
            }
            break;
        }
        case State::kDown: {
            if (i == limit - 1 || A[i] <= A[i + 1]) {
                int length = i - start + 1;
                if (length > max) {
                    max = length;
                }

                if (i + 1 < limit) {
                    if (A[i] == A[i + 1]) {
                        s = State::kNone;
                        start = -1;
                    } else {
                        s = State::kUp;
                        start = i;
                    }
                }
            }
            break;
        }
        }
    }

    return max;
}

int main() {
    {
        std::vector<int> input{2, 1, 4, 7, 3, 2, 5};
        assert(longestMountain(input) == 5);
    }
    {
        std::vector<int> input{2, 2, 2};
        assert(longestMountain(input) == 0);
    }
    {
        std::vector<int> input{0, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0};
        assert(longestMountain(input) == 11);
    }
    return 0;
}
