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

ListNode *mergetTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr && l2 == nullptr) {
        return nullptr;
    }
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }

    ListNode *p;
    ListNode *ret;
    if (l1->val <= l2->val) {
        p = ret = l1;
        l1 = l1->next;
    } else {
        p = ret = l2;
        l2 = l2->next;
    }

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val <= l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }

        p = p->next;
    }

    if (l1 == nullptr) {
        p->next = l2;
    } else {
        p->next = l1;
    }

    return ret;
}

int main() {
    {
        ListNode *l1 = new ListNode(1);
        l1->next = new ListNode(2);
        l1->next->next = new ListNode(4);

        ListNode *l2 = new ListNode(1);
        l2->next = new ListNode(3);
        l2->next->next = new ListNode(4);

        auto ret = mergetTwoLists(l1, l2);
        assert(ret->val == 1);
        assert(ret->next->val == 1);
        assert(ret->next->next->val == 2);
        assert(ret->next->next->next->val == 3);
        assert(ret->next->next->next->next->val == 4);
        assert(ret->next->next->next->next->next->val == 4);
        assert(ret->next->next->next->next->next->next == nullptr);

        delete ret;
    }
    {
        auto ret = mergetTwoLists(nullptr, nullptr);
        assert(ret == nullptr);
    }
    {
        ListNode *l2 = new ListNode(0);
        auto ret = mergetTwoLists(nullptr, l2);
        assert(ret->val == 0);
        assert(ret->next == nullptr);

        delete ret;
    }
    return 0;
}
