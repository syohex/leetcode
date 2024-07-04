#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *mergeNodes(ListNode *head) {
    ListNode *p = head->next;
    ListNode *merged = p;

    while (p != nullptr) {
        int sum = 0;
        while (p->val != 0) {
            sum += p->val;
            p = p->next;
        }

        merged->val = sum;
        merged->next = p->next;
        merged = p->next;
        p = p->next;
    }

    return head->next;
}

int main() {
    {
        ListNode *r = new ListNode(0);
        r->next = new ListNode(3);
        r->next->next = new ListNode(1);
        r->next->next->next = new ListNode(0);
        r->next->next->next->next = new ListNode(4);
        r->next->next->next->next->next = new ListNode(5);
        r->next->next->next->next->next->next = new ListNode(2);
        r->next->next->next->next->next->next->next = new ListNode(0);

        auto *ret = mergeNodes(r);
        assert(ret->val == 4);
        assert(ret->next->val == 11);
        assert(ret->next->next == nullptr);
    }
    {
        ListNode *r = new ListNode(0);
        r->next = new ListNode(1);
        r->next->next = new ListNode(0);
        r->next->next->next = new ListNode(3);
        r->next->next->next->next = new ListNode(0);
        r->next->next->next->next->next = new ListNode(2);
        r->next->next->next->next->next->next = new ListNode(2);
        r->next->next->next->next->next->next->next = new ListNode(0);

        auto *ret = mergeNodes(r);
        assert(ret->val == 1);
        assert(ret->next->val == 3);
        assert(ret->next->next->val == 4);
        assert(ret->next->next->next == nullptr);
    }
    return 0;
}
