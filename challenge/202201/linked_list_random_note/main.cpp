#include <cassert>
#include <random>
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

class Solution {
  public:
    Solution(ListNode *head) : head_(head), len_(0) {
        ListNode *p = head;
        while (p != nullptr) {
            ++len_;
            p = p->next;
        }
    }

    int getRandom() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, len_ - 1);
        int target = dist(gen);

        ListNode *p = head_;
        for (int i = 0; i < target; ++i) {
            p = p->next;
        }

        return p->val;
    }

    ListNode *head_;
    size_t len_;
};

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);

        Solution s(r);
        for (int i = 0; i < 5; ++i) {
            printf("return %d\n", s.getRandom());
        }

        delete r;
    }
    return 0;
}
