#include <cassert>
#include <functional>
#include <algorithm>
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

ListNode *swapNodes(ListNode *head, int k) {
    ListNode *target = nullptr;

    std::function<int(ListNode * node, ListNode * prev, int i, int k)> f;
    f = [&](ListNode *node, ListNode *prev, int i, int k) -> int {
        if (node == nullptr) {
            return 1;
        }

        if (i == k) {
            target = node;
        }

        int ret = f(node->next, node, i + 1, k);
        if (ret == k) {
            std::swap(node->val, target->val);
        }

        return ret + 1;
    };

    (void)f(head, nullptr, 1, k);
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
        auto ret = swapNodes(r, 4);
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
        auto ret = swapNodes(r, 1);
        assert(ret->val == 2);
        assert(ret->next->val == 1);

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
    return 0;
}
