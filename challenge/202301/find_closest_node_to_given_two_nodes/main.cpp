#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>

int closestMeetingNode(const std::vector<int> &edges, int node1, int node2) {
    const auto distance = [&](int node) -> std::vector<int> {
        std::vector<int> distances(edges.size(), -1);
        int dist = 0;
        distances[node] = dist++;

        while (true) {
            node = edges[node];
            if (node == -1 || distances[node] != -1) {
                break;
            }

            distances[node] = dist++;
        }

        return distances;
    };

    auto distances1 = distance(node1);
    auto distances2 = distance(node2);

    int min_dist = std::numeric_limits<int>::max();
    int ret = -1;
    for (size_t i = 0; i < edges.size(); ++i) {
        if (distances1[i] != -1 && distances2[i] != -1) {
            int d = std::max(distances1[i], distances2[i]);
            if (d < min_dist) {
                ret = i;
                min_dist = d;
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> edges{2, 2, 3, -1};
        int ret = closestMeetingNode(edges, 0, 1);
        assert(ret == 2);
    }
    {
        std::vector<int> edges{1, 2, -1};
        int ret = closestMeetingNode(edges, 0, 2);
        assert(ret == 2);
    }
    {
        std::vector<int> edges{1, -1, -1};
        int ret = closestMeetingNode(edges, 0, 2);
        assert(ret == -1);
    }
    return 0;
}
