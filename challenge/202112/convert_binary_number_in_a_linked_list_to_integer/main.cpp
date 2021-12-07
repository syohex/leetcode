#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

int getDecimalValue(ListNode *head) {
    int ret = 0;
    ListNode *p = head;
    while (p != nullptr) {
        ret = 2 * ret + p->val;
        p = p->next;
    }
    return ret;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(0);
        r->next->next = new ListNode(1);
        assert(getDecimalValue(r) == 5);
        delete r;
    }
    {
        ListNode *r = new ListNode(0);
        assert(getDecimalValue(r) == 0);
        delete r;
    }
    {
        ListNode *r = new ListNode(1);
        assert(getDecimalValue(r) == 1);
        delete r;
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
        delete r;
    }
    {
        ListNode *r = new ListNode(0);
        r->next = new ListNode(0);
        assert(getDecimalValue(r) == 0);
        delete r;
    }
    return 0;
}