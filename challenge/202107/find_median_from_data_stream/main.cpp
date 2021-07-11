#include <cassert>
#include <vector>
#include <algorithm>

class MedianFinder {
  public:
    MedianFinder() {
    }

    void addNum(int num) {
        if (v_.empty()) {
            v_.push_back(num);
            return;
        }

        auto it = std::lower_bound(v_.begin(), v_.end(), num);
        v_.insert(it, num);
    }

    double findMedian() {
        int len = v_.size();
        if (len % 2 == 0) {
            return (v_[len / 2 - 1] + v_[len / 2]) / 2.0;
        } else {
            return v_[len / 2];
        }
    }

    std::vector<int> v_;
};

int main() {
    {
        MedianFinder mf;
        mf.addNum(1);
        mf.addNum(2);
        assert(mf.findMedian() == 1.5);
        mf.addNum(3);
        assert(mf.findMedian() == 2.0);
    }
    return 0;
}
