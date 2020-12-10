#include <cassert>
#include <vector>

bool validMountainArray(const std::vector<int> &arr) {
    enum class State {
        kUp,
        kDown,
    };

    if (arr.size() < 3) {
        return false;
    }

    if (arr[0] >= arr[1]) {
        return false;
    }

    State state = State::kUp;
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] < arr[i]) {
            if (state == State::kDown) {
                return false;
            }
        } else if (arr[i - 1] == arr[i]) {
            return false;
        } else {
            if (state == State::kUp) {
                state = State::kDown;
            }
        }
    }

    return state == State::kDown;
}

int main() {
    {
        std::vector<int> arr{2, 1};
        assert(!validMountainArray(arr));
    }
    {
        std::vector<int> arr{3, 5, 5};
        assert(!validMountainArray(arr));
    }
    {
        std::vector<int> arr{0, 3, 2, 1};
        assert(validMountainArray(arr));
    }
    {
        std::vector<int> arr{0, 2, 3, 4, 5, 2, 1, 0};
        assert(validMountainArray(arr));
    }
    {
        std::vector<int> arr{0, 2, 3, 3, 5, 2, 1, 0};
        assert(!validMountainArray(arr));
    }
    {
        std::vector<int> arr{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        assert(!validMountainArray(arr));
    }
    return 0;
}
