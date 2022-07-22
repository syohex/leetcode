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

ListNode *partion(ListNode *head, int x) {
    ListNode *smaller = nullptr;
    ListNode *larger = nullptr;

    ListNode *p = head;
    ListNode *larger_head = nullptr;
    while (p != nullptr) {
        if (p->val < x) {
            if (smaller != nullptr) {
                smaller->next = p;
            } else {
                head = p;
            }
            smaller = p;
        } else {
            if (larger != nullptr) {
                larger->next = p;
            } else {
                larger_head = p;
            }
            larger = p;
        }

        p = p->next;
    }

    if (larger != nullptr) {
        larger->next = nullptr;
    }

    if (smaller != nullptr) {
        smaller->next = larger_head;
        return head;
    }

    return larger_head;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(4);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(2);
        r->next->next->next->next = new ListNode(5);
        r->next->next->next->next->next = new ListNode(2);

        auto ret = partion(r, 3);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 2);
        assert(ret->next->next->next->val == 4);
        assert(ret->next->next->next->next->val == 3);
        assert(ret->next->next->next->next->next->val == 5);
        assert(ret->next->next->next->next->next->next == nullptr);

        delete ret;
    }
    {
        ListNode *r = new ListNode(2);
        r->next = new ListNode(1);

        auto ret = partion(r, 2);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next == nullptr);

        delete ret;
    }
    return 0;
}