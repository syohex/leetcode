#include <cassert>
#include <vector>
#include <map>
#include <queue>

double maxProbability(int n, const std::vector<std::vector<int>> &edges, const std::vector<double> &succProb, int start_node,
                      int end_node) {
    std::map<int, std::vector<std::pair<int, double>>> graph;

    for (std::size_t i = 0; i < edges.size(); ++i) {
        const auto edge = edges[i];
        double score = succProb[i];
        graph[edge[0]].push_back({edge[1], score});
        graph[edge[1]].push_back({edge[0], score});
    }

    std::vector<double> max_scores(n, 0);
    std::priority_queue<std::pair<int, double>> q;
    q.push({start_node, 1.0});

    while (!q.empty()) {
        const auto [node, current_score] = q.top();
        q.pop();

        for (const auto &[next, score] : graph[node]) {
            double next_score = current_score * score;
            if (next_score > max_scores[next]) {
                max_scores[next] = next_score;
                q.push({next, next_score});
            }
        }
    }

    return max_scores[end_node];
}

int main() {
    {
        std::vector<std::vector<int>> edges{{0, 1}, {1, 2}, {0, 2}};
        std::vector<double> succProb{0.5, 0.5, 0.2};
        double ret = maxProbability(3, edges, succProb, 0, 2);
        assert(ret == 0.25);
    }
    {
        std::vector<std::vector<int>> edges{{0, 1}, {1, 2}, {0, 2}};
        std::vector<double> succProb{0.5, 0.5, 0.3};
        double ret = maxProbability(3, edges, succProb, 0, 2);
        assert(ret == 0.3);
    }
    {
        std::vector<std::vector<int>> edges{{0, 1}};
        std::vector<double> succProb{0.5};
        double ret = maxProbability(3, edges, succProb, 0, 2);
        assert(ret == 0.0);
    }
    return 0;
}