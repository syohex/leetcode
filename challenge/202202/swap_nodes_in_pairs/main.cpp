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

ListNode *swapPairs(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode *ret = head;
    ListNode *p = head;

    ListNode *prev = nullptr;
    while (p != nullptr) {
        ListNode *first = p;
        ListNode *second = p->next;
        if (second == nullptr) {
            break;
        }

        if (ret == head) {
            ret = second;
        }

        p = second->next;
        first->next = second->next;
        second->next = first;

        if (prev != nullptr) {
            prev->next = second;
        }

        prev = first;
    }

    return ret;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);

        auto ret = swapPairs(r);
        assert(ret->val == 2);
        assert(ret->next->val == 1);
        assert(ret->next->next->val == 4);
        assert(ret->next->next->next->val == 3);
        assert(ret->next->next->next->next == nullptr);
        delete ret;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);

        auto ret = swapPairs(r);
        assert(ret->val == 2);
        assert(ret->next->val == 1);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next == nullptr);
        delete ret;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        auto ret = swapPairs(r);
        assert(ret->val == 2);
        assert(ret->next->val == 1);
        assert(ret->next->next == nullptr);
        delete ret;
    }
    {
        auto ret = swapPairs(nullptr);
        assert(ret == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        auto ret = swapPairs(r);
        assert(ret->val == 1);
        assert(ret->next == nullptr);
        delete ret;
    }
    return 0;
}