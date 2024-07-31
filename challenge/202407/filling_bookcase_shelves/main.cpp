#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>
#include <map>
#include <limits>

int minHeightshelves(const std::vector<std::vector<int>> &books, int shelfWidth) {
    int len = books.size();

    std::function<int(int i, int remaining_width, int row_height, std::map<std::pair<int, int>, int> &cache)> f;
    f = [&](int i, int remaining_width, int row_height, std::map<std::pair<int, int>, int> &cache) -> int {
        const auto &book = books[i];
        int new_row_height = std::max(row_height, book[1]);

        if (i == len - 1) {
            if (book[0] <= remaining_width) {
                return new_row_height;
            }

            return row_height + book[1];
        }

        std::pair<int, int> key{i, remaining_width};
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        // put current book in next row
        int ret1 = row_height + f(i + 1, shelfWidth - book[0], book[1], cache);
        int ret2 = std::numeric_limits<int>::max();
        if (book[0] <= remaining_width) {
            // put current book in current row
            ret2 = f(i + 1, remaining_width - book[0], new_row_height, cache);
        }

        int ret = std::min(ret1, ret2);
        cache[key] = ret;
        return ret;
    };

    std::map<std::pair<int, int>, int> cache;
    return f(0, shelfWidth, 0, cache);
}

int main() {
    {
        std::vector<std::vector<int>> books{{1, 1}, {2, 3}, {2, 3}, {1, 1}, {1, 1}, {1, 1}, {1, 2}};
        int ret = minHeightshelves(books, 4);
        assert(ret == 6);
    }
    {
        std::vector<std::vector<int>> books{{1, 3}, {2, 4}, {3, 2}};
        int ret = minHeightshelves(books, 6);
        assert(ret == 4);
    }
    return 0;
}