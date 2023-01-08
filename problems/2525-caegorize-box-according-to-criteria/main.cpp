#include <cassert>
#include <string>
#include <cstdint>

std::string categorizeBox(int length, int width, int height, int mass) {
    const auto is_bulky = [](int64_t length, int64_t width, int64_t height) -> bool {
        constexpr int64_t BULKY_VOLUME = 1'000'000'000;
        constexpr int64_t BULKY_LENGTH = 10'000;

        if (length >= BULKY_LENGTH || width >= BULKY_LENGTH || height >= BULKY_LENGTH) {
            return true;
        }

        return (length * width * height) >= BULKY_VOLUME;
    };

    bool bulky = is_bulky(length, width, height);
    bool heavy = mass >= 100;

    if (bulky && heavy) {
        return "Both";
    }
    if (bulky && !heavy) {
        return "Bulky";
    }
    if (!bulky && heavy) {
        return "Heavy";
    }

    return "Neither";
}

int main() {
    assert(categorizeBox(1000, 35, 700, 300) == "Heavy");
    assert(categorizeBox(200, 50, 800, 50) == "Neither");
    assert(categorizeBox(10000, 50, 800, 50) == "Bulky");
    assert(categorizeBox(10000, 50, 800, 1000) == "Both");
    return 0;
}
