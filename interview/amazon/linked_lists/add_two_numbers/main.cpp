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

ListNode *addTwoNumber(ListNode *l1, ListNode *l2) {
    ListNode *head1 = l1, *head2 = l2;
    bool return_v1 = true;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr) {
        int v1 = l1 != nullptr ? l1->val : 0;
        int v2 = l2 != nullptr ? l2->val : 0;

        int v = v1 + v2 + carry;
        if (v >= 10) {
            v -= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        ListNode *prev = nullptr;
        if (l1 != nullptr) {
            prev = l1;
            l1->val = v;
            return_v1 = true;
            l1 = l1->next;
        }

        if (l2 != nullptr) {
            prev = l2;
            l2->val = v;
            return_v1 = false;
            l2 = l2->next;
        }

        if (carry != 0 && l1 == nullptr && l2 == nullptr && prev != nullptr) {
            prev->next = new ListNode(carry);
            break;
        }
    }

    return return_v1 ? head1 : head2;
}

int main() {
    {
        ListNode *r1 = new ListNode(2);
        r1->next = new ListNode(4);
        r1->next->next = new ListNode(3);

        ListNode *r2 = new ListNode(5);
        r2->next = new ListNode(6);
        r2->next->next = new ListNode(4);

        auto ret = addTwoNumber(r1, r2);
        assert(ret->val == 7);
        assert(ret->next->val == 0);
        assert(ret->next->next->val == 8);
        assert(ret->next->next->next == nullptr);

        delete r1;
        delete r2;
    }
    {
        ListNode *r1 = new ListNode(1);
        ListNode *r2 = new ListNode(9);
        auto ret = addTwoNumber(r1, r2);
        assert(ret->val == 0);
        assert(ret->next->val == 1);
        assert(ret->next->next == nullptr);

        delete r1;
        delete r2;
    }
    {
        ListNode *r1 = new ListNode(9);
        r1->next = new ListNode(9);
        r1->next->next = new ListNode(9);
        r1->next->next->next = new ListNode(9);
        r1->next->next->next->next = new ListNode(9);
        r1->next->next->next->next->next = new ListNode(9);
        r1->next->next->next->next->next->next = new ListNode(9);

        ListNode *r2 = new ListNode(9);
        r2->next = new ListNode(9);
        r2->next->next = new ListNode(9);
        r2->next->next->next = new ListNode(9);

        auto ret = addTwoNumber(r1, r2);
        assert(ret->val == 8);
        assert(ret->next->val == 9);
        assert(ret->next->next->val == 9);
        assert(ret->next->next->next->val == 9);
        assert(ret->next->next->next->next->val == 0);
        assert(ret->next->next->next->next->next->val == 0);
        assert(ret->next->next->next->next->next->next->val == 0);
        assert(ret->next->next->next->next->next->next->next->val == 1);
        assert(ret->next->next->next->next->next->next->next->next == nullptr);

        delete r1;
        delete r2;
    }
    return 0;
}
