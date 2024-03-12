#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode *removeZeroSumSublists(ListNode *head) {
    ListNode *ret = new ListNode(0);
    ret->next = head;

    ListNode *prev = ret;
    while (prev != nullptr) {
        ListNode *q = prev->next;
        int sum = 0;
        while (q != nullptr) {
            sum += q->val;
            if (sum == 0) {
                prev->next = q->next;
            }

            q = q->next;
        }

        prev = prev->next;
    }

    return ret->next;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(-3);
        r->next->next->next = new ListNode(3);
        r->next->next->next->next = new ListNode(1);

        auto *ret = removeZeroSumSublists(r);
        assert(ret->val == 3);
        assert(ret->next->val == 1);
        assert(ret->next->next == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(-3);
        r->next->next->next->next = new ListNode(4);

        auto *ret = removeZeroSumSublists(r);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 4);
        assert(ret->next->next->next == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(-3);
        r->next->next->next->next = new ListNode(-2);

        auto *ret = removeZeroSumSublists(r);
        assert(ret->val == 1);
        assert(ret->next == nullptr);
    }
    return 0;
}
