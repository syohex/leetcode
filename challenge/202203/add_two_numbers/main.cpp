#include <cassert>

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
    int carry = 0;
    ListNode *p = l1;
    ListNode *q = l2;

    ListNode *ret = nullptr;
    ListNode **z = nullptr;
    while (p != nullptr || q != nullptr) {
        int v1 = p == nullptr ? 0 : p->val;
        int v2 = q == nullptr ? 0 : q->val;
        int sum = v1 + v2 + carry;
        int v = sum % 10;
        carry = sum / 10;

        if (ret == nullptr) {
            ret = new ListNode(v);
            z = &ret;
        } else {
            *z = new ListNode(v);
        }

        p = p == nullptr ? nullptr : p->next;
        q = q == nullptr ? nullptr : q->next;
        z = &((*z)->next);
    }

    if (carry != 0) {
        *z = new ListNode(carry);
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

        delete l1;
        delete l2;
        delete ret;
    }
    {
        ListNode *l1 = new ListNode(0);
        ListNode *l2 = new ListNode(0);
        auto ret = addTwoNumbers(l1, l2);
        assert(ret->val == 0);
        assert(ret->next == nullptr);
        delete l1;
        delete l2;
        delete ret;
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
        delete l1;
        delete l2;
        delete ret;
    }
    return 0;
}
