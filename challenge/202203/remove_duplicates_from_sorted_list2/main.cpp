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

ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode *ret = nullptr;
    ListNode *prev = nullptr;
    ListNode *p = head->next;
    ListNode *q = head;
    int count = 1;

    while (p != nullptr) {
        if (p->val == q->val) {
            ++count;
        } else {
            if (count == 1) {
                if (ret == nullptr) {
                    ret = q;
                } else {
                    prev->next = q;
                }

                prev = q;
            }
            count = 1;
        }

        q = p;
        p = p->next;
    }

    if (count == 1) {
        if (ret == nullptr) {
            return q;
        }

        prev->next = q;
        prev = q;
    }

    if (prev != nullptr) {
        prev->next = nullptr;
    }
    return ret;
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
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(1);
        r->next->next = new ListNode(1);
        r->next->next->next = new ListNode(2);

        auto ret = deleteDuplicates(r);
        assert(ret->val == 2);
        assert(ret->next == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(2);
        r->next->next->next = new ListNode(2);

        auto ret = deleteDuplicates(r);
        assert(ret->val == 1);
        assert(ret->next == nullptr);
    }
    {
        ListNode *r = new ListNode(2);
        r->next = new ListNode(2);
        r->next->next = new ListNode(2);
        r->next->next->next = new ListNode(2);

        auto ret = deleteDuplicates(r);
        assert(ret == nullptr);
    }
    return 0;
}
