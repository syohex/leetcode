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

ListNode *partition(ListNode *head, int x) {
    ListNode *head_p = nullptr;
    ListNode *head_q = nullptr;
    ListNode *p = nullptr;
    ListNode *q = nullptr;

    while (head != nullptr) {
        if (head->val < x) {
            if (p == nullptr) {
                p = head;
                head_p = head;
            } else {
                p->next = head;
                p = p->next;
            }
        } else {
            if (q == nullptr) {
                q = head;
                head_q = head;
            } else {
                q->next = head;
                q = q->next;
            }
        }

        head = head->next;
    }

    if (p != nullptr) {
        if (q != nullptr) {
            p->next = head_q;
            q->next = nullptr;
        }

        return head_p;
    }

    if (q != nullptr) {
        q->next = nullptr;
        return head_q;
    }

    return nullptr;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(4);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(2);
        r->next->next->next->next = new ListNode(5);
        r->next->next->next->next->next = new ListNode(2);
        auto ret = partition(r, 3);

        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 2);
        assert(ret->next->next->next->val == 4);
        assert(ret->next->next->next->next->val == 3);
        assert(ret->next->next->next->next->next->val == 5);
        assert(ret->next->next->next->next->next->next == nullptr);
    }
    {
        ListNode *r = new ListNode(2);
        r->next = new ListNode(1);
        auto ret = partition(r, 2);

        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(4);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(2);
        r->next->next->next->next = new ListNode(5);
        r->next->next->next->next->next = new ListNode(2);
        auto ret = partition(r, 1);

        assert(ret->val == 1);
        assert(ret->next->val == 4);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 2);
        assert(ret->next->next->next->next->val == 5);
        assert(ret->next->next->next->next->next->val == 2);
        assert(ret->next->next->next->next->next->next == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(4);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(2);
        r->next->next->next->next = new ListNode(5);
        r->next->next->next->next->next = new ListNode(2);
        auto ret = partition(r, 5);

        assert(ret->val == 1);
        assert(ret->next->val == 4);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 2);
        assert(ret->next->next->next->next->val == 2);
        assert(ret->next->next->next->next->next->val == 5);
        assert(ret->next->next->next->next->next->next == nullptr);
    }
    return 0;
}
