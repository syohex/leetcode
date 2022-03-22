#include <cassert>
#include <vector>
#include <queue>

int halveArray(const std::vector<int> &nums) {
    std::priority_queue<double, std::vector<double>> q;
    double sum = 0;
    for (int num : nums) {
        q.push(num);
        sum += num;
    }

    double half = sum / 2.0;
    int ret = 0;
    while (true) {
        double d = q.top();
        q.pop();

        ++ret;

        double d_half = d / 2.0;
        sum -= d_half;
        if (sum <= half) {
            return ret;
        }

        q.push(d_half);
    }

    // never reach here
    return -1;
}

int main() {
    {
        std::vector<int> nums{5, 19, 8, 1};
        assert(halveArray(nums) == 3);
    }
    {
        std::vector<int> nums{3, 8, 20};
        assert(halveArray(nums) == 3);
    }
    {
        std::vector<int> nums{1};
        assert(halveArray(nums) == 1);
    }
    return 0;
}