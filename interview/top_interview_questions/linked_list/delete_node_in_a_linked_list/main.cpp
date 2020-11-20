#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

void deleteNode(ListNode *node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

int main() {
    {
        ListNode *r = new ListNode(4);
        r->next = new ListNode(5);
        r->next->next = new ListNode(1);
        r->next->next->next = new ListNode(9);

        deleteNode(r->next->next);

        assert(r->val == 4);
        assert(r->next->val == 5);
        assert(r->next->next->val == 9);
        assert(r->next->next->next == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);

        deleteNode(r->next->next);

        assert(r->val == 1);
        assert(r->next->val == 2);
        assert(r->next->next->val == 4);
        assert(r->next->next->next == nullptr);
    }
    {
        ListNode *r = new ListNode(0);
        r->next = new ListNode(1);

        deleteNode(r);

        assert(r->val == 1);
        assert(r->next == nullptr);
    }
    {
        ListNode *r = new ListNode(-3);
        r->next = new ListNode(5);
        r->next->next = new ListNode(-99);

        deleteNode(r);

        assert(r->val == 5);
        assert(r->next->val == -99);
        assert(r->next->next == nullptr);
    }
    return 0;
}
