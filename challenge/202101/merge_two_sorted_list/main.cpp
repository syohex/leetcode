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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = nullptr;
    ListNode *prev = nullptr;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            if (prev != nullptr) {
                prev->next = l1;
            }

            prev = l1;
            l1 = l1->next;
        } else {
            if (prev != nullptr) {
                prev->next = l2;
            }

            prev = l2;
            l2 = l2->next;
        }

        if (head == nullptr) {
            head = prev;
        }
    }

    if (l1 != nullptr) {
        if (prev == nullptr) {
            return l1;
        }
        prev->next = l1;
    } else if (l2 != nullptr) {
        if (prev == nullptr) {
            return l2;
        }
        prev->next = l2;
    }

    return head;
}

int main() {
    {
        ListNode *r1 = new ListNode(1);
        r1->next = new ListNode(2);
        r1->next->next = new ListNode(4);

        ListNode *r2 = new ListNode(1);
        r2->next = new ListNode(3);
        r2->next->next = new ListNode(4);

        auto ret = mergeTwoLists(r1, r2);
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
        auto ret = mergeTwoLists(nullptr, nullptr);
        assert(ret == nullptr);
    }
    {
        ListNode *r2 = new ListNode(0);

        auto ret = mergeTwoLists(nullptr, r2);
        assert(ret->val == 0);
        assert(ret->next == nullptr);

        delete ret;
    }
    {
        ListNode *r1 = new ListNode(0);

        auto ret = mergeTwoLists(r1, nullptr);
        assert(ret->val == 0);
        assert(ret->next == nullptr);

        delete ret;
    }

    return 0;
}
