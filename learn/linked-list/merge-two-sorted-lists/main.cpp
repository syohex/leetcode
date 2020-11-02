#include <cassert>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr && l2 == nullptr) {
        return nullptr;
    }

    if (l1 != nullptr && l2 == nullptr) {
        return l1;
    }

    if (l1 == nullptr && l2 != nullptr) {
        return l2;
    }

    ListNode *head;
    if (l1->val <= l2->val) {
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;
    }

    ListNode *p = head;
    while (true) {
        if (l1 == nullptr) {
            p->next = l2;
            break;
        }

        if (l2 == nullptr) {
            p->next = l1;
            break;
        }

        if (l1->val <= l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }

        p = p->next;
    }

    return head;
}

int main() {
    {
        ListNode *l1 = new ListNode(1);
        l1->next = new ListNode(2);
        l1->next->next = new ListNode(4);
        ListNode *l2 = new ListNode(1);
        l2->next = new ListNode(3);
        l2->next->next = new ListNode(4);

        auto ret = mergeTwoLists(l1, l2);
        assert(ret->val == 1);
        assert(ret->next->val == 1);
        assert(ret->next->next->val == 2);
        assert(ret->next->next->next->val == 3);
        assert(ret->next->next->next->next->val == 4);
        assert(ret->next->next->next->next->next->val == 4);
        assert(ret->next->next->next->next->next->next == nullptr);
    }
    { assert(mergeTwoLists(nullptr, nullptr) == nullptr); }
    {
        ListNode *l2 = new ListNode(0);
        auto ret = mergeTwoLists(nullptr, l2);
        assert(ret->val == 0);
        assert(ret->next == nullptr);
    }

    return 0;
}
