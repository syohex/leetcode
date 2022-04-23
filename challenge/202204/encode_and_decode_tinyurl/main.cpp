#include <cassert>
#include <string>
#include <map>
#include <random>

class Solution {
  public:
    // Encodes a URL to a shortened URL.
    std::string encode(const std::string &longUrl) {
        static std::string chars{"0123456789ABCDEFGHIJKLMNOPQRSTUXYZabcdefghijklmnopqrstuvwxyz"};
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<size_t> dist(0, chars.size());

        std::string tmp(6, 0);
        while (true) {
            for (int i = 0; i < 6; ++i) {
                tmp[i] = chars[dist(mt)];
            }

            if (cache_.find(tmp) == cache_.end()) {
                std::string tiny("http://tinyurl.com/" + tmp);
                cache_[tiny] = longUrl;
                return tiny;
            }
        }

        // never reach here
        return "";
    }

    // Decodes a shortened URL to its original URL.
    std::string decode(const std::string &shortUrl) {
        return cache_[shortUrl];
    }

    std::map<std::string, std::string> cache_;
};

int main() {
    {
        std::string url("https://leetcode.com/problems/design-tinyurl");
        Solution s;
        auto tiny = s.encode(url);
        assert(url != tiny);
        auto orig = s.decode(tiny);
        assert(url == orig);
    }
    return 0;
}
