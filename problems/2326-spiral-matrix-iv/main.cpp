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
    std::vector<std::vector<int>> ret(m, std::vector<int>(n, -1));

    enum class Way {
        kRight,
        kDown,
        kLeft,
        kUp,
    };

    int row = 0;
    int col = 0;
    Way way = Way::kRight;

    ListNode *p = head;
    while (p != nullptr) {
        ret[row][col] = p->val;

        switch (way) {
        case Way::kRight:
            if (col == n - 1 || ret[row][col + 1] != -1) {
                way = Way::kDown;
                row += 1;
            } else {
                col += 1;
            }
            break;
        case Way::kDown:
            if (row == m - 1 || ret[row + 1][col] != -1) {
                way = Way::kLeft;
                col -= 1;
            } else {
                row += 1;
            }
            break;
        case Way::kLeft:
            if (col == 0 || ret[row][col - 1] != -1) {
                way = Way::kUp;
                row -= 1;
            } else {
                col -= 1;
            }
            break;
        case Way::kUp:
            if (ret[row - 1][col] != -1) {
                way = Way::kRight;
                col += 1;
            } else {
                row -= 1;
            }
            break;
        }

        p = p->next;
    }

    return ret;
}

int main() {
    {
        ListNode *r = new ListNode(3);
        r->next = new ListNode(0);
        r->next->next = new ListNode(2);
        r->next->next->next = new ListNode(6);
        r->next->next->next->next = new ListNode(8);
        r->next->next->next->next->next = new ListNode(1);
        r->next->next->next->next->next->next = new ListNode(7);
        r->next->next->next->next->next->next->next = new ListNode(9);
        r->next->next->next->next->next->next->next->next = new ListNode(4);
        r->next->next->next->next->next->next->next->next->next = new ListNode(2);
        r->next->next->next->next->next->next->next->next->next->next = new ListNode(5);
        r->next->next->next->next->next->next->next->next->next->next->next = new ListNode(5);
        r->next->next->next->next->next->next->next->next->next->next->next->next = new ListNode(0);

        std::vector<std::vector<int>> expected{
            {3, 0, 2, 6, 8},
            {5, 0, -1, -1, 1},
            {5, 2, 4, 9, 7},
        };

        auto ret = spiralMatrix(3, 5, r);
        assert(ret == expected);

        delete r;
    }
    {
        ListNode *r = new ListNode(0);
        r->next = new ListNode(1);
        r->next->next = new ListNode(2);

        std::vector<std::vector<int>> expected{
            {0, 1, 2, -1},
        };

        auto ret = spiralMatrix(1, 4, r);
        assert(ret == expected);

        delete r;
    }
    return 0;
}
