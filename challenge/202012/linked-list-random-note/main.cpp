#include <cassert>
#include <random>

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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head) {
        head_ = head;
    }

    int getRandom() {
        ListNode *p = head_;
        int ret = 0;
        int count = 1;

        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist(0, 1.0);

        while (p != nullptr) {
            double val = dist(mt);
            if (val < 1.0 / count) {
                ret = p->val;
            }

            ++count;
            p = p->next;
        }

        return ret;
    }

    ListNode *head_;
};

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);

        Solution s(r);
        for (int i = 0; i < 20; ++i) {
            printf("[%d] %d\n", i, s.getRandom());
        }
    }
    return 0;
}
