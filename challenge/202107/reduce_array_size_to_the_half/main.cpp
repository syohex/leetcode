#include <cassert>
#include <vector>
#include <algorithm>

int minSetSize(const std::vector<int> &arr) {
    struct Data {
        int num;
        int count;
    };

    std::vector<Data> v;
    for (int num : arr) {
        bool found = false;
        for (Data &d : v) {
            if (d.num == num) {
                found = true;
                ++d.count;
                break;
            }
        }

        if (!found) {
            v.push_back(Data{num, 1});
        }
    }

    if (v.size() == 1) {
        return 1;
    }

    std::sort(v.begin(), v.end(), [](const Data &a, const Data &b) { return a.count > b.count; });

    int len = v.size();
    int ret = arr.size();
    int half = ret / 2;

    for (int i = 0; i < len - 1; ++i) {
        int sum = v[i].count;
        if (sum >= half) {
            return 1;
        }

        int count = 1;
        bool ok = false;
        for (int j = i + 1; j < len; ++j) {
            sum += v[j].count;
            ++count;
            if (sum >= half) {
                ok = true;
                break;
            }
        }

        if (ok) {
            ret = std::min(ret, count);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> arr{3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
        assert(minSetSize(arr) == 2);
    }
    {
        std::vector<int> arr{7, 7, 7, 7, 7, 7};
        assert(minSetSize(arr) == 1);
    }
    {
        std::vector<int> arr{1, 9};
        assert(minSetSize(arr) == 1);
    }
    {
        std::vector<int> arr{1000, 1000, 3, 7};
        assert(minSetSize(arr) == 1);
    }
    {
        std::vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        assert(minSetSize(arr) == 5);
    }
    return 0;
}
