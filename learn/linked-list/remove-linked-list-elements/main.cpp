#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode *removeElements(ListNode *head, int val) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode *ret = head;
    ListNode *p = head;
    ListNode *prev = nullptr;
    while (p != nullptr) {
        if (p->val == val) {
            if (prev == nullptr) {
                ret = p->next;
            } else {
                prev->next = p->next;
            }
        } else {
            prev = p;
        }

        p = p->next;
    }

    return ret;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(6);
        r->next->next->next = new ListNode(3);
        r->next->next->next->next = new ListNode(4);
        r->next->next->next->next->next = new ListNode(5);
        r->next->next->next->next->next->next = new ListNode(6);
        auto ret = removeElements(r, 6);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 4);
        assert(ret->next->next->next->next->val == 5);
        assert(ret->next->next->next->next->next == nullptr);
    }
    return 0;
}
