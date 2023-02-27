#include <cassert>
#include <vector>
#include <functional>

class Node {
  public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    ~Node() {
        delete topLeft;
        delete topRight;
        delete bottomLeft;
        delete bottomRight;
    }
};

Node *construct(const std::vector<std::vector<int>> &grid) {
    std::function<Node *(int n, int x, int y)> f;
    f = [&](int n, int x, int y) -> Node * {
        Node *ret = new Node;
        int val = grid[x][y];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[x + i][y + j] != val) {
                    val = -1;
                    break;
                }
            }
        }

        if (val != -1) {
            ret->isLeaf = true;
            ret->val = val;
        } else {
            ret->isLeaf = false;
            ret->val = 1;

            int m = n / 2;
            ret->topLeft = f(m, x + 0, y + 0);
            ret->topRight = f(m, x + 0, y + m);
            ret->bottomLeft = f(m, x + m, y + 0);
            ret->bottomRight = f(m, x + m, y + m);
        }

        return ret;
    };

    return f(grid.size(), 0, 0);
}

int main() {
    {
        std::vector<std::vector<int>> grid{{0, 1}, {1, 0}};
        auto ret = construct(grid);
        assert(!ret->isLeaf);
        assert(ret->val == 1);
        assert(ret->topLeft->isLeaf);
        assert(ret->topLeft->val == 0);
        assert(ret->topRight->isLeaf);
        assert(ret->topRight->val == 1);
        assert(ret->bottomLeft->isLeaf);
        assert(ret->bottomLeft->val == 1);
        assert(ret->bottomRight->isLeaf);
        assert(ret->bottomRight->val == 0);

        delete ret;
    }
    {
        std::vector<std::vector<int>> grid{
            {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0},
        };
        auto ret = construct(grid);
        assert(!ret->isLeaf);
        assert(ret->val == 1);
        assert(ret->topLeft->isLeaf);
        assert(ret->topLeft->val == 1);
        assert(!ret->topRight->isLeaf);
        assert(ret->topRight->val == 1);
        assert(ret->topRight->topLeft->isLeaf);
        assert(ret->topRight->topLeft->val == 0);
        assert(ret->topRight->topRight->isLeaf);
        assert(ret->topRight->topRight->val == 0);
        assert(ret->topRight->bottomLeft->isLeaf);
        assert(ret->topRight->bottomLeft->val == 1);
        assert(ret->topRight->bottomRight->isLeaf);
        assert(ret->topRight->bottomRight->val == 1);
        assert(ret->bottomLeft->isLeaf);
        assert(ret->bottomLeft->val == 1);
        assert(ret->bottomRight->isLeaf);
        assert(ret->bottomRight->val == 0);

        delete ret;
    }
    {
        std::vector<std::vector<int>> grid{{1, 1}, {1, 1}};
        auto ret = construct(grid);
        assert(ret->isLeaf);
        assert(ret->val == 1);
        delete ret;
    }
    return 0;
}
