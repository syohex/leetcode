#include <cassert>
#include <string>

std::string removeTrailingZeros(std::string num) {
    int len = num.size();
    for (int i = len - 1; i >= 0; --i) {
        if (num[i] != '0')  {
            num.resize(i + 1);
            return num;
        }
    }

    return num;
}

int main() {
    assert(removeTrailingZeros("51230100") == "512301");
    assert(removeTrailingZeros("123") == "123");
    return 0;
}
