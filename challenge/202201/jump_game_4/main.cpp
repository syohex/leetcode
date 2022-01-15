#include <cassert>
#include <vector>
#include <queue>
#include <map>

int minJumps(const std::vector<int> &arr) {
    int len = arr.size();
    std::map<int, std::vector<int>> m;
    for (int i = 0; i < len; ++i) {
        m[arr[i]].push_back(i);
    }

    struct Data {
        int pos;
        int count;
    };

    const auto cmp = [](const Data &a, const Data &b) { return a.count > b.count; };

    std::priority_queue<Data, std::vector<Data>, decltype(cmp)> q(cmp);
    q.push({0, 0});

    std::vector<bool> checked(len, false);
    while (!q.empty()) {
        auto d = q.top();
        q.pop();

        if (d.pos == len - 1) {
            return d.count;
        }

        if (checked[d.pos]) {
            continue;
        }
        checked[d.pos] = true;

        if (d.pos + 1 < len) {
            q.push({d.pos + 1, d.count + 1});
        }
        if (d.pos - 1 >= 0) {
            q.push({d.pos - 1, d.count + 1});
        }

        auto it = m.find(arr[d.pos]);
        if (it != m.end()) {
            for (int p : m[arr[d.pos]]) {
                if (p != d.pos) {
                    q.push({p, d.count + 1});
                }
            }
            m.erase(it);
        }
    }

    // never reach here
    return 0;
}

int main() {
    {
        std::vector<int> arr{100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
        assert(minJumps(arr) == 3);
    }
    {
        std::vector<int> arr{7};
        assert(minJumps(arr) == 0);
    }
    {
        std::vector<int> arr{7, 6, 9, 6, 9, 6, 9, 7};
        assert(minJumps(arr) == 1);
    }
    return 0;
}
