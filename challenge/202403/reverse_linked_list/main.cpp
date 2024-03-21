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

ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *p = head;
    while (p != nullptr) {
        ListNode *next = p->next;

        p->next = prev;
        prev = p;
        p = next;
    }

    return prev;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);

        auto *ret = reverseList(r);
        assert(ret->val == 5);
        assert(ret->next->val == 4);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 2);
        assert(ret->next->next->next->next->val == 1);
        assert(ret->next->next->next->next->next == nullptr);

        delete ret;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);

        auto *ret = reverseList(r);
        assert(ret->val == 2);
        assert(ret->next->val == 1);
        assert(ret->next->next == nullptr);

        delete ret;
    }
    {
        auto *ret = reverseList(nullptr);
        assert(ret == nullptr);
    }
    return 0;
}
