#include <cassert>
#include <vector>

int findCenter(const std::vector<std::vector<int>> &edges) {
    const auto &edge1 = edges[0];
    const auto &edge2 = edges[1];

    if (edge1[0] == edge2[0] || edge1[0] == edge2[1]) {
        return edge1[0];
    }

    return edge1[1];
}

int main() {
    {
        std::vector<std::vector<int>> edges{{1, 2}, {2, 3}, {4, 2}};
        int ret = findCenter(edges);
        assert(ret == 2);
    }
    {
        std::vector<std::vector<int>> edges{{1, 2}, {5, 1}, {1, 3}, {1, 4}};
        int ret = findCenter(edges);
        assert(ret == 1);
    }
    return 0;
}
