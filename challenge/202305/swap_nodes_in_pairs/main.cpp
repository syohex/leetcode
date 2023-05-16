#include <cassert>
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

ListNode *swapPairs(ListNode *head) {
    ListNode *p = head;
    ListNode *prev1 = nullptr;
    ListNode *prev2 = nullptr;
    ListNode *ret = head;
    bool even = false;

    while (p != nullptr) {
        ListNode *next = p->next;

        if (even) {
            if (ret == head) {
                ret = p;
            }

            prev1->next = next;

            if (prev2 != nullptr) {
                prev2->next = p;
            }

            p->next = prev1;

            prev2 = p;
        } else {
            prev2 = prev1;
            prev1 = p;
        }

        p = next;

        even = !even;
    }

    return ret;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        auto ret = swapPairs(r);
        assert(ret->val == 2);
        assert(ret->next->val == 1);
        assert(ret->next->next->val == 4);
        assert(ret->next->next->next->val == 3);
        assert(ret->next->next->next->next == nullptr);

        delete ret;
    }
    {
        ListNode *r = new ListNode(1);
        auto ret = swapPairs(r);
        assert(ret->val == 1);
        assert(ret->next == nullptr);
        delete ret;
    }
    {
        auto ret = swapPairs(nullptr);
        assert(ret == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        auto ret = swapPairs(r);
        assert(ret->val == 2);
        assert(ret->next->val == 1);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next == nullptr);

        delete ret;
    }
    return 0;
}
