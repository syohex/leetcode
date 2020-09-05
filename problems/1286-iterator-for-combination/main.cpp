#include <cassert>
#include <string>
#include <vector>
#include <functional>
#include <cstdio>

class CombinationIterator {
  public:
    CombinationIterator(std::string characters, int combinationLength) {
        index_ = 0;
        collectCombinations(characters, combinationLength);
    }

    std::string next() {
        return v_[index_++];
    }

    bool hasNext() {
        return index_ < v_.size();
    }

    void collectCombinations(const std::string &s, size_t len) {
        std::function<void(size_t pos, const std::string &comb)> f;
        f = [this, &f, &s, &len](size_t pos, const std::string &comb) {
            if (comb.size() == len) {
                v_.push_back(comb);
                return;
            }

            if (pos >= s.size()) {
                return;
            }

            f(pos + 1, comb + s[pos]);
            if (s.size() - pos + comb.size() < len) {
                return;
            }
            f(pos + 1, comb);
        };

        f(0, "");
    }

    std::vector<std::string> v_;
    size_t index_;
};

int main() {
    {
        auto iterator = CombinationIterator("abc", 2);
        assert(iterator.next() == "ab");
        assert(iterator.hasNext());
        assert(iterator.next() == "ac");
        assert(iterator.hasNext());
        assert(iterator.next() == "bc");
        assert(!iterator.hasNext());
    }
    return 0;
}
