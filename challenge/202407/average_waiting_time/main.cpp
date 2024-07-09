#include <cassert>
#include <vector>
#include <algorithm>

double averageWaitingTime(const std::vector<std::vector<int>> &customers) {
    int finish_time = 0;
    long long wait_time = 0;
    for (const auto &customer : customers) {
        finish_time = std::max(finish_time, customer[0]) + customer[1];
        wait_time += finish_time - customer[0];
    }

    return static_cast<double>(wait_time) / customers.size();
}

int main() {
    {
        std::vector<std::vector<int>> customers{{1, 2}, {2, 5}, {4, 3}};
        double ret = averageWaitingTime(customers);
        assert(ret == 5.0);
    }
    {
        std::vector<std::vector<int>> customers{{5, 2}, {5, 4}, {10, 3}, {20, 1}};
        double ret = averageWaitingTime(customers);
        assert(ret == 3.25);
    }
    return 0;
}
