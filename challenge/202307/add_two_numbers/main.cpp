#include <cassert>
#include <functional>
#include <vector>
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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    const auto f = [](ListNode *node) {
        ListNode *prev = nullptr;
        ListNode *p = node;
        while (p != nullptr) {
            ListNode *tmp = p->next;
            p->next = prev;
            prev = p;
            p = tmp;
        }
        return prev;
    };

    ListNode *r1 = f(l1);
    ListNode *r2 = f(l2);

    ListNode *p = r1;
    ListNode *q = r2;

    ListNode *ret = nullptr;
    ListNode **r = &ret;
    int carry = 0;
    while (p != nullptr || q != nullptr) {
        int v1 = p != nullptr ? p->val : 0;
        int v2 = q != nullptr ? q->val : 0;

        int v = v1 + v2 + carry;
        if (v >= 10) {
            carry = 1;
            v %= 10;
        } else {
            carry = 0;
        }

        *r = new ListNode(v);
        r = &((*r)->next);

        p = p != nullptr ? p->next : nullptr;
        q = q != nullptr ? q->next : nullptr;
    }

    if (carry >= 1) {
        *r = new ListNode(1);
    }

    delete r1;
    delete r2;
    return f(ret);
}

int main() {
    {
        ListNode *l1 = new ListNode(7);
        l1->next = new ListNode(2);
        l1->next->next = new ListNode(4);
        l1->next->next->next = new ListNode(3);

        ListNode *l2 = new ListNode(5);
        l2->next = new ListNode(6);
        l2->next->next = new ListNode(4);

        auto *ret = addTwoNumbers(l1, l2);
        assert(ret->val == 7);
        assert(ret->next->val == 8);
        assert(ret->next->next->val == 0);
        assert(ret->next->next->next->val == 7);
        assert(ret->next->next->next->next == nullptr);

        delete ret;
    }
    {
        ListNode *l1 = new ListNode(2);
        l1->next = new ListNode(4);
        l1->next->next = new ListNode(3);

        ListNode *l2 = new ListNode(5);
        l2->next = new ListNode(6);
        l2->next->next = new ListNode(4);

        auto *ret = addTwoNumbers(l1, l2);
        assert(ret->val == 8);
        assert(ret->next->val == 0);
        assert(ret->next->next->val == 7);
        assert(ret->next->next->next == nullptr);

        delete ret;
    }
    {
        ListNode *l1 = new ListNode(0);
        ListNode *l2 = new ListNode(0);

        auto *ret = addTwoNumbers(l1, l2);
        assert(ret->val == 0);
        assert(ret->next == nullptr);

        delete ret;
    }
    {
        ListNode *l1 = new ListNode(5);
        ListNode *l2 = new ListNode(5);

        auto *ret = addTwoNumbers(l1, l2);
        assert(ret->val == 1);
        assert(ret->next->val == 0);
        assert(ret->next->next  == nullptr);

        delete ret;
    }
    return 0;
}
