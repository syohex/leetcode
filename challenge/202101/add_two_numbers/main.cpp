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
    ListNode *head = nullptr;
    ListNode **p = &head;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr) {
        int v1 = l1 == nullptr ? 0 : l1->val;
        int v2 = l2 == nullptr ? 0 : l2->val;

        int v = v1 + v2 + carry;
        carry = v / 10;
        *p = new ListNode(v % 10);

        l1 = l1 == nullptr ? nullptr : l1->next;
        l2 = l2 == nullptr ? nullptr : l2->next;
        p = &((*p)->next);
    }

    if (carry > 0) {
        *p = new ListNode(carry);
    }

    return head;
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
