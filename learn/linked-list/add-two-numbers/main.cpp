#include <cassert>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *ret = nullptr;
    ListNode **p = &ret;

    int carry = 0;
    while (l1 != nullptr || l2 != nullptr) {
        int add;
        if (l1 == nullptr) {
            add = l2->val;
        } else if (l2 == nullptr) {
            add = l1->val;
        } else {
            add = l1->val + l2->val;
        }

        if (carry != 0) {
            add += carry;
        }

        if (add >= 10) {
            add %= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        *p = new ListNode(add);

        if (l1 != nullptr) {
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            l2 = l2->next;
        }

        p = &((*p)->next);
    }

    if (carry != 0) {
        *p = new ListNode(carry);
    }

    return ret;
}

int main() {
    {
        ListNode *l1 = new ListNode(2);
        l1->next = new ListNode(4);
        l1->next->next = new ListNode(3);
        ListNode *l2 = new ListNode(5);
        l2->next = new ListNode(6);
        l2->next->next = new ListNode(4);

        auto ret = addTwoNumbers(l1, l2);
        assert(ret->val == 7);
        assert(ret->next->val == 0);
        assert(ret->next->next->val == 8);
        assert(ret->next->next->next == nullptr);
    }
    {
        ListNode *l1 = new ListNode(0);
        ListNode *l2 = new ListNode(0);

        auto ret = addTwoNumbers(l1, l2);
        assert(ret->val == 0);
        assert(ret->next == nullptr);
    }
    {
        ListNode *l1 = new ListNode(9);
        l1->next = new ListNode(9);
        l1->next->next = new ListNode(9);
        l1->next->next->next = new ListNode(9);
        l1->next->next->next->next = new ListNode(9);
        l1->next->next->next->next->next = new ListNode(9);
        l1->next->next->next->next->next->next = new ListNode(9);

        ListNode *l2 = new ListNode(9);
        l2->next = new ListNode(9);
        l2->next->next = new ListNode(9);
        l2->next->next->next = new ListNode(9);

        auto ret = addTwoNumbers(l1, l2);
        assert(ret->val == 8);
        assert(ret->next->val == 9);
        assert(ret->next->next->val == 9);
        assert(ret->next->next->next->val == 9);
        assert(ret->next->next->next->next->val == 0);
        assert(ret->next->next->next->next->next->val == 0);
        assert(ret->next->next->next->next->next->next->val == 0);
        assert(ret->next->next->next->next->next->next->next->val == 1);
        assert(ret->next->next->next->next->next->next->next->next == nullptr);
    }
    return 0;
}
