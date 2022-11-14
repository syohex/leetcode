#include <cassert>
#include <vector>

std::vector<double> convertTemperature(double celsius) {
    return {celsius + 273.15, celsius * 1.8 + 32.0};
}

int main() {
    {
        std::vector<double> expected{309.65, 97.7};
        auto ret = convertTemperature(36.5);
        assert(ret == expected);
    }
    {
        std::vector<double> expected{395.26, 251.798};
        auto ret = convertTemperature(122.11);
        assert(ret == expected);
    }

    return 0;
}
