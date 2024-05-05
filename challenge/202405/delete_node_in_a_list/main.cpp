#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

void deleteNode(ListNode *node) {
    ListNode *next = node->next;
    node->val = next->val;
    node->next = next->next;
    next->next = nullptr;
}

int main() {
    {
        ListNode *r = new ListNode(4);
        r->next = new ListNode(5);
        r->next->next = new ListNode(1);
        r->next->next->next = new ListNode(9);
        deleteNode(r->next);

        assert(r->val == 4);
        assert(r->next->val == 1);
        assert(r->next->next->val == 9);
    }
    {
        ListNode *r = new ListNode(4);
        r->next = new ListNode(5);
        r->next->next = new ListNode(1);
        r->next->next->next = new ListNode(9);
        deleteNode(r->next->next);

        assert(r->val == 4);
        assert(r->next->val == 5);
        assert(r->next->next->val == 9);
    }
    return 0;
}
