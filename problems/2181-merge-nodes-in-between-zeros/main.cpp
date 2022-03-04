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

ListNode *mergeNode(ListNode *head) {
    ListNode *prev_zero2 = nullptr;
    ListNode *prev_zero = head;
    ListNode *p = prev_zero->next;
    ListNode *prev = nullptr;

    int sum = 0;
    while (p != nullptr) {
        if (p->val == 0) {
            prev->next = nullptr;
            delete prev_zero->next;

            prev_zero->val = sum;
            prev_zero->next = p;

            prev_zero2 = prev_zero;
            prev_zero = p;
            sum = 0;
        } else {
            sum += p->val;
        }

        prev = p;
        p = p->next;
    }

    delete prev_zero;
    prev_zero2->next = nullptr;
    return head;
}

int main() {
    {
        ListNode *p = new ListNode(0);
        p->next = new ListNode(3);
        p->next->next = new ListNode(1);
        p->next->next->next = new ListNode(0);
        p->next->next->next->next = new ListNode(4);
        p->next->next->next->next->next = new ListNode(5);
        p->next->next->next->next->next->next = new ListNode(2);
        p->next->next->next->next->next->next->next = new ListNode(0);
        auto ret = mergeNode(p);
        assert(ret->val == 4);
        assert(ret->next->val == 11);
        assert(ret->next->next == nullptr);

        delete ret;
    }
    {
        ListNode *p = new ListNode(0);
        p->next = new ListNode(1);
        p->next->next = new ListNode(0);
        p->next->next->next = new ListNode(3);
        p->next->next->next->next = new ListNode(0);
        p->next->next->next->next->next = new ListNode(2);
        p->next->next->next->next->next->next = new ListNode(2);
        p->next->next->next->next->next->next->next = new ListNode(0);
        auto ret = mergeNode(p);
        assert(ret->val == 1);
        assert(ret->next->val == 3);
        assert(ret->next->next->val == 4);
        assert(ret->next->next->next == nullptr);

        delete ret;
    }
    return 0;
}
