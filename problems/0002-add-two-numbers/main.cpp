#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode *next) : val(x), next(next) {
    }

    ~ListNode() {
        delete next;
    }
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (l1->val == 0 && l1->next == nullptr) {
        return l2;
    }
    if (l2->val == 0 && l2->next == nullptr) {
        return l1;
    }

    int add = l1->val + l2->val;
    int carry = add >= 10 ? 1 : 0;
    ListNode *ret = new ListNode(add % 10);

    ListNode *a = l1->next;
    ListNode *b = l2->next;

    ListNode *p = ret;
    while (a != nullptr || b != nullptr) {
        int aVal = a != nullptr ? a->val : 0;
        int bVal = b != nullptr ? b->val : 0;

        add = aVal + bVal + carry;
        carry = add >= 10 ? 1 : 0;

        p->next = new ListNode(add % 10);
        p = p->next;

        a = a != nullptr ? a->next : nullptr;
        b = b != nullptr ? b->next : nullptr;
    }

    if (carry == 1) {
        p->next = new ListNode(carry);
    }

    return ret;
}

int main() {
    ListNode a(2, new ListNode(4, new ListNode(3)));
    ListNode b(5, new ListNode(6, new ListNode(4)));

    ListNode *c = addTwoNumbers(&a, &b);
    assert(c->val == 7 && c->next->val == 0 && c->next->next->val == 8);
    delete c;

    ListNode d(5);
    ListNode e(5);
    c = addTwoNumbers(&d, &e);
    assert(c->val == 0 && c->next->val == 1);
    delete c;
    return 0;
}