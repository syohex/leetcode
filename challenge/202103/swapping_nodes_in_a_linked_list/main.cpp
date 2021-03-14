#include <cassert>
#include <vector>
#include <algorithm>

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

    std::swap(v[k - 1], v[v.size() - k]);
    for (size_t i = 0; i < v.size() - 1; ++i) {
        v[i]->next = v[i + 1];
    }

    v.back()->next = nullptr;
    return v[0];
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
