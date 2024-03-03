#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *ret = new ListNode(0);
    ret->next = head;

    ListNode *p = head;
    int len = 0;
    while (p != nullptr) {
        ++len;
        p = p->next;
    }

    p = ret;
    int pos = len - n;
    while (pos > 0) {
        --pos;
        p = p->next;
    }

    p->next = p->next->next;
    return ret->next;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);

        auto ret = removeNthFromEnd(r, 2);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 5);
        assert(ret->next->next->next->next == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        auto ret = removeNthFromEnd(r, 1);
        assert(ret == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);

        auto ret = removeNthFromEnd(r, 1);
        assert(ret->val == 1);
        assert(ret->next == nullptr);
    }
    return 0;
}
