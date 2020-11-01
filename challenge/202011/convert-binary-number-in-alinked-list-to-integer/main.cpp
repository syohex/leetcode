#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

int getDecimalValue(ListNode *head) {
    int ret = 0;

    ListNode *p = head;
    while (p != nullptr) {
        ret += p->val;
        p = p->next;
        if (p != nullptr) {
            ret *= 2;
        }
    }

    return ret;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(0);
        r->next->next = new ListNode(1);
        assert(getDecimalValue(r) == 5);
    }
    {
        ListNode *r = new ListNode(0);
        assert(getDecimalValue(r) == 0);
    }
    {
        ListNode *r = new ListNode(1);
        assert(getDecimalValue(r) == 1);
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(0);
        r->next->next = new ListNode(0);
        r->next->next->next = new ListNode(1);
        r->next->next->next->next = new ListNode(0);
        r->next->next->next->next->next = new ListNode(0);
        r->next->next->next->next->next->next = new ListNode(1);
        r->next->next->next->next->next->next->next = new ListNode(1);
        r->next->next->next->next->next->next->next->next = new ListNode(1);
        r->next->next->next->next->next->next->next->next->next = new ListNode(0);
        r->next->next->next->next->next->next->next->next->next->next = new ListNode(0);
        r->next->next->next->next->next->next->next->next->next->next->next = new ListNode(0);
        r->next->next->next->next->next->next->next->next->next->next->next->next = new ListNode(0);
        r->next->next->next->next->next->next->next->next->next->next->next->next->next = new ListNode(0);
        r->next->next->next->next->next->next->next->next->next->next->next->next->next->next = new ListNode(0);
        assert(getDecimalValue(r) == 18880);
    }
    {
        ListNode *r = new ListNode(0);
        r->next = new ListNode(0);
        assert(getDecimalValue(r) == 0);
    }
    return 0;
}
