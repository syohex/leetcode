#include <cassert>
#include <vector>
#include <random>
#include <cmath>

class Solution {
  public:
    Solution(double radius, double x_center, double y_center) : radius_(radius), x_center_(x_center), y_center_(y_center) {
    }

    std::vector<double> randPoint() {
        std::mt19937 gen(rd_());
        std::uniform_real_distribution<> distribution(-radius_, radius_);

        double r1 = 0, r2 = 0;
        do {
            r1 = distribution(gen);
            r2 = distribution(gen);
        } while (std::sqrt(r1 * r1 + r2 * r2) > radius_);

        return std::vector<double>{r1 + x_center_, r2 + y_center_};
    }

    std::random_device rd_;
    double radius_;
    double x_center_;
    double y_center_;
};

int main() {
    {
        Solution s(1, 0, 0);
        for (int i = 0; i < 1000; ++i) {
            auto ret = s.randPoint();
            auto dist = std::sqrt(ret[0] * ret[0] + ret[1] * ret[1]);
            assert(dist <= 1.0);
        }
    }
    {
        Solution s(10, 5, -7.5);
        for (int i = 0; i < 1000; ++i) {
            auto ret = s.randPoint();
            auto x = ret[0] - 5;
            auto y = ret[1] + 7.5;
            auto dist = std::sqrt(x * x + y * y);
            assert(dist <= 10);
        }
    }
}
