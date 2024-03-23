#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

ListNode *reorderList(ListNode *head) {
    ListNode *p = head;
    ListNode *q = head;

    while (q != nullptr && q->next != nullptr) {
        p = p->next;
        q = q->next->next;
    }

    ListNode *r = p;
    ListNode *prev = nullptr;
    while (r != nullptr) {
        ListNode *tmp = r->next;

        r->next = prev;
        prev = r;
        r = tmp;
    }

    p = head;
    q = prev;
    while (q->next != nullptr) {
        ListNode *tmp = p->next;
        p->next = q;
        p = tmp;

        tmp = q->next;
        q->next = p;
        q = tmp;
    }

    return head;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        auto *ret = reorderList(r);
        assert(ret->val == 1);
        assert(ret->next->val == 4);
        assert(ret->next->next->val == 2);
        assert(ret->next->next->next->val == 3);
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);
        auto *ret = reorderList(r);
        assert(ret->val == 1);
        assert(ret->next->val == 5);
        assert(ret->next->next->val == 2);
        assert(ret->next->next->next->val == 4);
        assert(ret->next->next->next->next->val == 3);
    }
    return 0;
}
