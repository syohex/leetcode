#include <cassert>
#include <cstdio>

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

ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    ListNode *p = list1;
    ListNode *ret = p;
    ListNode *prev = nullptr;

    ListNode *start = nullptr;
    ListNode *end = nullptr;
    while (start == nullptr || end == nullptr) {
        if (start == nullptr && p->val == a) {
            if (prev != nullptr) {
                start = prev;
            } else {
                start = list2;
                ret = start;
            }
        }
        if (start != nullptr && p->val == b) {
            end = p->next;
            p->next = nullptr;
            break;
        }

        prev = p;
        p = p->next;
    }

    if (start == list2) {
        delete list1;
    } else {
        delete start->next;
        start->next = list2;
    }

    p = list2;
    while (p->next != nullptr) {
        p = p->next;
    }

    p->next = end;
    return ret;
}

int main() {
    {
        ListNode *r = new ListNode(0);
        r->next = new ListNode(1);
        r->next->next = new ListNode(2);
        r->next->next->next = new ListNode(3);
        r->next->next->next->next = new ListNode(4);
        r->next->next->next->next->next = new ListNode(5);

        ListNode *r2 = new ListNode(1000);
        r2->next = new ListNode(1001);
        r2->next->next = new ListNode(1002);

        auto ret = mergeInBetween(r, 3, 4, r2);
        assert(ret->val == 0);
        assert(ret->next->val == 1);
        assert(ret->next->next->val == 2);
        assert(ret->next->next->next->val == 1000);
        assert(ret->next->next->next->next->val == 1001);
        assert(ret->next->next->next->next->next->val == 1002);
        assert(ret->next->next->next->next->next->next->val == 5);
        assert(ret->next->next->next->next->next->next->next == nullptr);
        delete ret;
    }
    {
        ListNode *r = new ListNode(0);
        r->next = new ListNode(1);
        r->next->next = new ListNode(2);
        r->next->next->next = new ListNode(3);
        r->next->next->next->next = new ListNode(4);
        r->next->next->next->next->next = new ListNode(5);
        r->next->next->next->next->next->next = new ListNode(6);

        ListNode *r2 = new ListNode(1000);
        r2->next = new ListNode(1001);
        r2->next->next = new ListNode(1002);
        r2->next->next->next = new ListNode(1003);
        r2->next->next->next->next = new ListNode(1004);

        auto ret = mergeInBetween(r, 2, 5, r2);
        assert(ret->val == 0);
        assert(ret->next->val == 1);
        assert(ret->next->next->val == 1000);
        assert(ret->next->next->next->val == 1001);
        assert(ret->next->next->next->next->val == 1002);
        assert(ret->next->next->next->next->next->val == 1003);
        assert(ret->next->next->next->next->next->next->val == 1004);
        assert(ret->next->next->next->next->next->next->next->val == 6);
        assert(ret->next->next->next->next->next->next->next->next == nullptr);

        delete ret;
    }
    {
        ListNode *r = new ListNode(0);
        r->next = new ListNode(1);
        r->next->next = new ListNode(2);
        r->next->next->next = new ListNode(3);
        r->next->next->next->next = new ListNode(4);

        ListNode *r2 = new ListNode(1000);
        r2->next = new ListNode(1001);

        auto ret = mergeInBetween(r, 0, 4, r2);
        assert(ret->val == 1000);
        assert(ret->next->val == 1001);
        assert(ret->next->next == nullptr);
        delete ret;
    }
    {
        ListNode *r = new ListNode(0);
        r->next = new ListNode(1);
        r->next->next = new ListNode(2);

        ListNode *r2 = new ListNode(1000);
        r2->next = new ListNode(1001);

        auto ret = mergeInBetween(r, 1, 1, r2);
        assert(ret->val == 0);
        assert(ret->next->val == 1000);
        assert(ret->next->next->val == 1001);
        assert(ret->next->next->next->val == 2);
        assert(ret->next->next->next->next == nullptr);
        delete ret;
    }
    return 0;
}
