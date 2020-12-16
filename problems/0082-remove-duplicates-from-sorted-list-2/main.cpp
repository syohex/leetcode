#include <cassert>
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

ListNode *deleteDuplicates(ListNode *head) {
    ListNode *p = head;
    ListNode *tail = nullptr;
    while (p != nullptr) {
        ListNode *tmp = p;
        int val = p->val;
        int i = 0;
        while (p != nullptr && p->val == val) {
            p = p->next;
            ++i;
        }

        if (i == 1) {
            if (tail == nullptr) {
                head = tmp;
            } else {
                tail->next = tmp;
            }

            tail = tmp;
        }
    }

    if (tail == nullptr) {
        return nullptr;
    }

    tail->next = nullptr;
    return head;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(3);
        r->next->next->next->next = new ListNode(4);
        r->next->next->next->next->next = new ListNode(4);
        r->next->next->next->next->next->next = new ListNode(5);

        auto ret = deleteDuplicates(r);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 5);
        assert(ret->next->next->next == nullptr);
        delete ret;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(1);
        r->next->next = new ListNode(1);
        r->next->next->next = new ListNode(2);
        r->next->next->next->next = new ListNode(3);

        auto ret = deleteDuplicates(r);
        assert(ret->val == 2);
        assert(ret->next->val == 3);
        assert(ret->next->next == nullptr);
        delete ret;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(1);
        r->next->next = new ListNode(1);
        r->next->next->next = new ListNode(2);
        r->next->next->next->next = new ListNode(2);

        auto ret = deleteDuplicates(r);
        assert(ret == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(1);
        r->next->next = new ListNode(2);
        r->next->next->next = new ListNode(2);
        r->next->next->next->next = new ListNode(3);

        auto ret = deleteDuplicates(r);
        assert(ret->val == 3);
        assert(ret->next == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(2);

        auto ret = deleteDuplicates(r);
        assert(ret->val == 1);
        assert(ret->next == nullptr);
    }
    return 0;
}
