#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

bool hasCycle(ListNode *head) {
    ListNode *p = head;
    ListNode *q = head;

    while (p != nullptr && q != nullptr && q->next != nullptr) {
        p = p->next;
        q = q->next->next;

        if (p == q) {
            return true;
        }
    }

    return false;
}

int main() {
    {
        ListNode *r = new ListNode(3);
        r->next = new ListNode(2);
        r->next->next = new ListNode(0);
        r->next->next->next = new ListNode(-4);
        r->next->next->next->next = r->next;
        assert(hasCycle(r));
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = r;
        assert(hasCycle(r));
    }
    {
        ListNode *r = new ListNode(1);
        assert(!hasCycle(r));
    }
    return 0;
}
