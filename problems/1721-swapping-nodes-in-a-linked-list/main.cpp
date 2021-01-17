#include <cassert>
#include <vector>
#include <cstdio>
#include <cmath>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

ListNode *swapNodes(ListNode *head, int k) {
    std::vector<ListNode *> v;
    ListNode *p = head;

    while (p != nullptr) {
        v.push_back(p);
        p = p->next;
    }

    if (v.size() == 1) {
        return head;
    }

    ListNode *n1 = nullptr, *prev1 = nullptr;
    ListNode *n2 = nullptr, *prev2 = nullptr;
    int limit = v.size();
    for (int i = 0; i < limit; ++i) {
        if (i == k - 1) {
            n1 = v[i];
            if (k != 1) {
                prev1 = v[i - 1];
            }
        }
        if (limit - i == k) {
            n2 = v[i];
            if (i > 0) {
                prev2 = v[i - 1];
            }
        }
    }

    if (n1 == n2) {
        return head;
    }

    if (k > limit / 2) {
        std::swap(n1, n2);
        std::swap(prev1, prev2);
    }

    if (prev1 != nullptr) {
        prev1->next = n2;
    } else {
        head = n2;
    }

    ListNode *tmp = n2->next;
    if (std::abs(k - (limit - k + 1)) != 1) {
        if (prev2 != nullptr) {
            prev2->next = n1;
        }
        n2->next = n1->next;
    } else {
        n2->next = n1;
    }
    n1->next = tmp;

    return head;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);

        auto ret = swapNodes(r, 2);
        assert(ret->val == 1);
        assert(ret->next->val == 4);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 2);
        assert(ret->next->next->next->next->val == 5);
        assert(ret->next->next->next->next->next == nullptr);
        delete ret;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);

        auto ret = swapNodes(r, 5);
        assert(ret->val == 5);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 4);
        assert(ret->next->next->next->next->val == 1);
        assert(ret->next->next->next->next->next == nullptr);
        delete ret;
    }
    {
        ListNode *r = new ListNode(7);
        r->next = new ListNode(9);
        r->next->next = new ListNode(6);
        r->next->next->next = new ListNode(6);
        r->next->next->next->next = new ListNode(7);
        r->next->next->next->next->next = new ListNode(8);
        r->next->next->next->next->next->next = new ListNode(3);
        r->next->next->next->next->next->next->next = new ListNode(0);
        r->next->next->next->next->next->next->next->next = new ListNode(9);
        r->next->next->next->next->next->next->next->next->next = new ListNode(5);

        auto ret = swapNodes(r, 5);
        assert(ret->val == 7);
        assert(ret->next->val == 9);
        assert(ret->next->next->val == 6);
        assert(ret->next->next->next->val == 6);
        assert(ret->next->next->next->next->val == 8);
        assert(ret->next->next->next->next->next->val == 7);
        assert(ret->next->next->next->next->next->next->val == 3);
        assert(ret->next->next->next->next->next->next->next->val == 0);
        assert(ret->next->next->next->next->next->next->next->next->val == 9);
        assert(ret->next->next->next->next->next->next->next->next->next->val == 5);
        assert(ret->next->next->next->next->next->next->next->next->next->next == nullptr);
        delete ret;
    }
    {
        ListNode *r = new ListNode(1);

        auto ret = swapNodes(r, 1);
        assert(ret->val == 1);
        assert(ret->next == nullptr);
        delete ret;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);

        auto ret = swapNodes(r, 1);
        assert(ret->val == 2);
        assert(ret->next->val == 1);
        assert(ret->next->next == nullptr);

        delete ret;
    }
    {
        ListNode *r = new ListNode(100);
        r->next = new ListNode(90);

        auto ret = swapNodes(r, 2);
        assert(ret->val == 90);
        assert(ret->next->val == 100);
        assert(ret->next->next == nullptr);

        delete ret;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);

        auto ret = swapNodes(r, 2);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next == nullptr);

        delete ret;
    }
    return 0;
}
