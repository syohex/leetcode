#include <cassert>
#include <string>
#include <vector>
#include <functional>

class CominationIterator {
  public:
    CombinationIterator(const std::string &characters, int combinationLength) {
        index_ = 0;
        std::function<void(size_t start, std::string acc)> f;
        f = [&](size_t start, std::string acc) {
            if (acc.size() >= static_cast<size_t>(combinationLength)) {
                v_.push_back(acc);
                return;
            }

            for (size_t i = start; i < characters.size(); ++i) {
                acc.push_back(characters[i]);
                f(i + 1, acc);
                acc.pop_back();
            }
        };

        f(0, "");
    }

    std::string next() {
        return v_[index_++];
    }

    bool hasNext() {
        return index_ < v_.size();
    }

    std::vector<std::string> v_;
    size_t index_;
};

int main() {
    {
        CombinationIterator c("abc", 2);
        assert(c.next() == "ab");
        assert(c.hasNext());
        assert(c.next() == "ac");
        assert(c.hasNext());
        assert(c.next() == "bc");
        assert(!c.hasNext());
    }
    return 0;
}
