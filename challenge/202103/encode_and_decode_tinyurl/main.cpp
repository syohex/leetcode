#include <cassert>
#include <string>
#include <map>
#include <random>

class Solution {
  public:
    std::string encode(const std::string &longUrl) {
        constexpr size_t LENGTH = 8;
        static std::string characters("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> dist(0, characters.size() - 1);
        std::string ret("http://tinyurl.com/");
        for (size_t i = 0; i < LENGTH; ++i) {
            int index = dist(generator);
            ret += characters[index];
        }

        table_[longUrl] = ret;
        return ret;
    }

    std::string decode(const std::string &shortUrl) {
        for (const auto &it : table_) {
            if (it.second == shortUrl) {
                return it.first;
            }
        }

        return "";
    }

    std::map<std::string, std::string> table_;
};

int main() {
    {
        Solution s;
        const std::string input("https://leetcode.com/problems/design-tinyurl");

        auto tiny_url = s.encode(input);
        assert(input == s.decode(tiny_url));
    }
    return 0;
}
