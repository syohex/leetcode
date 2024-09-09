#include <cassert>
#include <vector>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

std::vector<std::vector<int>> spiralMatrix(int m, int n, ListNode *head) {
    enum class Direction {
        Right,
        Down,
        Left,
        Up,
    };

    std::vector<std::vector<int>> ret(m, std::vector<int>(n, -1));

    ListNode *p = head;
    int row = 0;
    int col = 0;
    Direction dir = Direction::Right;
    while (p != nullptr) {
        ret[row][col] = p->val;

        switch (dir) {
        case Direction::Right:
            if (col + 1 < n && ret[row][col + 1] == -1) {
                col += 1;
            } else {
                dir = Direction::Down;
                row += 1;
            }
            break;
        case Direction::Down:
            if (row + 1 < m && ret[row + 1][col] == -1) {
                row += 1;
            } else {
                dir = Direction::Left;
                col -= 1;
            }
            break;
        case Direction::Left:
            if (col - 1 >= 0 && ret[row][col - 1] == -1) {
                col -= 1;
            } else {
                dir = Direction::Up;
                row -= 1;
            }
            break;
        case Direction::Up:
            if (row - 1 >= 0 && ret[row - 1][col] == -1) {
                row -= 1;
            } else {
                dir = Direction::Right;
                col += 1;
            }
            break;
        }
        p = p->next;
    }
    return ret;
}

ListNode *toList(const std::vector<int> &v) {
    ListNode *ret = nullptr;
    ListNode **p = &ret;
    for (int n : v) {
        *p = new ListNode(n);
        p = &((*p)->next);
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{3, 0, 2, 6, 8, 1, 7, 9, 4, 2, 5, 5, 0};
        std::vector<std::vector<int>> expected{{3, 0, 2, 6, 8}, {5, 0, -1, -1, 1}, {5, 2, 4, 9, 7}};
        ListNode *head = toList(nums);
        auto ret = spiralMatrix(3, 5, head);
        assert(ret == expected);
        delete head;
    }
    {
        std::vector<int> nums{0, 1, 2};
        std::vector<std::vector<int>> expected{{0, 1, 2, -1}};
        ListNode *head = toList(nums);
        auto ret = spiralMatrix(1, 4, head);
        assert(ret == expected);
        delete head;
    }
    return 0;
}
