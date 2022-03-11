#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
    }
};

ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr) {
        return nullptr;
    }

    int len = 0;
    ListNode *p = head;
    ListNode *last = nullptr;
    while (p != nullptr) {
        ++len;

        last = p;
        p = p->next;
    }

    k %= len;
    if (len == 1 || k == 0) {
        return head;
    }

    int num = len - k;
    p = head;
    ListNode *prev = nullptr;
    for (int i = 0; i < num; ++i) {
        prev = p;
        p = p->next;
    }

    prev->next = nullptr;
    last->next = head;

    return p;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);

        auto ret = rotateRight(r, 2);
        assert(ret->val == 4);
        assert(ret->next->val == 5);
        assert(ret->next->next->val == 1);
        assert(ret->next->next->next->val == 2);
        assert(ret->next->next->next->next->val == 3);
        assert(ret->next->next->next->next->next == nullptr);

        delete r;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);

        auto ret = rotateRight(r, 10000002);
        assert(ret->val == 4);
        assert(ret->next->val == 5);
        assert(ret->next->next->val == 1);
        assert(ret->next->next->next->val == 2);
        assert(ret->next->next->next->next->val == 3);
        assert(ret->next->next->next->next->next == nullptr);

        delete r;
    }
    {
        ListNode *r = new ListNode(0);
        r->next = new ListNode(1);
        r->next->next = new ListNode(2);

        auto ret = rotateRight(r, 4);
        assert(ret->val == 2);
        assert(ret->next->val == 0);
        assert(ret->next->next->val == 1);
        assert(ret->next->next->next == nullptr);

        delete r;
    }
    {
        ListNode *r = new ListNode(1);

        auto ret = rotateRight(r, 0);
        assert(ret->val == 1);
        assert(ret->next == nullptr);

        delete r;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);

        auto ret = rotateRight(r, 0);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next == nullptr);

        delete r;
    }

    assert(rotateRight(nullptr, 100) == nullptr);
    return 0;
}