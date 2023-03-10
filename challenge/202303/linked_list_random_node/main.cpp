#include <cassert>
#include <cstdlib>

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
    Solution(ListNode *head) : head_(head) {
    }

    ~Solution() {
        delete head_;
    }

    int getRandom() {
        double n = 1;
        ListNode *p = head_, *ret = head_;
        while (p != nullptr) {
            double b = rand() / static_cast<double>(RAND_MAX);
            if (b <= 1.0 / n) {
                ret = p;
            }
            p = p->next;
            n += 1.0;
        }
        return ret->val;
    }

    ListNode *head_;
};

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        Solution s(r);
        for (int i = 0; i < 1000; ++i) {
            int v = s.getRandom();
            assert(v == 1 || v == 2 || v == 3);
        }
    }
    return 0;
}
