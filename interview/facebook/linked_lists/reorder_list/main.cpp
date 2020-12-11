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

void reorderList(ListNode *head) {
    ListNode *p = head;
    while (p != nullptr && p->next != nullptr) {
        ListNode *q = p->next;
        ListNode *prev = nullptr;
        while (q->next != nullptr) {
            prev = q;
            q = q->next;
        }

        if (prev != nullptr) {
            prev->next = nullptr;
            q->next = p->next;
        }

        p->next = q;
        p = q->next;
    }
}

int main() {
    {
        ListNode *r = nullptr;
        reorderList(r);
        assert(r == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        reorderList(r);
        assert(r->val == 1);
        assert(r->next == nullptr);
        delete r;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        reorderList(r);
        assert(r->val == 1);
        assert(r->next->val == 4);
        assert(r->next->next->val == 2);
        assert(r->next->next->next->val == 3);
        assert(r->next->next->next->next == nullptr);
        delete r;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);
        reorderList(r);
        assert(r->val == 1);
        assert(r->next->val == 5);
        assert(r->next->next->val == 2);
        assert(r->next->next->next->val == 4);
        assert(r->next->next->next->next->val == 3);
        assert(r->next->next->next->next->next == nullptr);
        delete r;
    }
    return 0;
}
