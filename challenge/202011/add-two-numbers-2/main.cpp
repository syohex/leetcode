#include <cassert>
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

ListNode *addTwoNumber(ListNode *l1, ListNode *l2) {
    std::vector<int> v1, v2;
    ListNode *p = l1;
    while (p != nullptr) {
        v1.push_back(p->val);
        p = p->next;
    }

    p = l2;
    while (p != nullptr) {
        v2.push_back(p->val);
        p = p->next;
    }

    ListNode *ret = nullptr;
    int carry = 0;

    auto it1 = v1.rbegin();
    auto it2 = v2.rbegin();
    while (true) {
        if (it1 == v1.rend() && it2 == v2.rend()) {
            break;
        }

        int n1 = it1 != v1.rend() ? *it1 : 0;
        int n2 = it2 != v2.rend() ? *it2 : 0;
        int val = n1 + n2 + carry;
        carry = val >= 10 ? 1 : 0;

        ListNode *tmp = ret;
        ret = new ListNode(val % 10);
        ret->next = tmp;

        if (it1 != v1.rend()) {
            ++it1;
        }
        if (it2 != v2.rend()) {
            ++it2;
        }
    }

    if (carry != 0) {
        ListNode *tmp = ret;
        ret = new ListNode(carry);
        ret->next = tmp;
    }

    return ret;
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

        auto ret = addTwoNumber(l1, l2);
        assert(ret->val == 7);
        assert(ret->next->val == 8);
        assert(ret->next->next->val == 0);
        assert(ret->next->next->next->val == 7);

        delete l1;
        delete l2;
        delete ret;
    }
    {
        ListNode *l1 = new ListNode(7);
        ListNode *l2 = new ListNode(3);

        auto ret = addTwoNumber(l1, l2);
        assert(ret->val == 1);
        assert(ret->next->val == 0);
        assert(ret->next->next == nullptr);

        delete l1;
        delete l2;
        delete ret;
    }
    return 0;
}
