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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *p = list1;
    ListNode *q = list2;

    ListNode *r = new ListNode(-1);
    ListNode *head = r;

    while (p != nullptr || q != nullptr) {
        if (p != nullptr && q != nullptr) {
            if (p->val <= q->val) {
                r->next = p;
                p = p->next;
            } else {
                r->next = q;
                q = q->next;
            }
        } else if (p != nullptr && q == nullptr) {
            r->next = p;
            break;
        } else {
            r->next = q;
            break;
        }

        r = r->next;
    }

    ListNode *ret = head->next;
    head->next = nullptr;
    delete head;

    return ret;
}

int main() {
    {
        ListNode *r1 = new ListNode(1);
        r1->next = new ListNode(2);
        r1->next->next = new ListNode(4);

        ListNode *r2 = new ListNode(1);
        r2->next = new ListNode(3);
        r2->next->next = new ListNode(4);

        auto ret = mergeTwoLists(r1, r2);
        assert(ret->val == 1);
        assert(ret->next->val == 1);
        assert(ret->next->next->val == 2);
        assert(ret->next->next->next->val == 3);
        assert(ret->next->next->next->next->val == 4);
        assert(ret->next->next->next->next->next->val == 4);
        assert(ret->next->next->next->next->next->next == nullptr);

        delete ret;
    }
    {
        auto ret = mergeTwoLists(nullptr, nullptr);
        assert(ret == nullptr);
    }
    {
        auto ret = mergeTwoLists(nullptr, new ListNode(0));
        assert(ret->val == 0);
        assert(ret->next == nullptr);
    }
    return 0;
}
