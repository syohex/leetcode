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

ListNode *partition(ListNode *head, int x) {
    ListNode *smaller = nullptr;
    ListNode *larger = nullptr;

    ListNode *p = head;
    ListNode *smaller_head = nullptr;
    ListNode *larger_head = nullptr;
    while (p != nullptr) {
        if (p->val < x) {
            if (smaller == nullptr) {
                smaller_head = p;
            } else {
                smaller->next = p;
            }

            smaller = p;
        } else {
            if (larger == nullptr) {
                larger_head = p;
            } else {
                larger->next = p;
            }

            larger = p;
        }

        p = p->next;
    }

    if (smaller == nullptr && larger == nullptr) {
        return nullptr;
    }
    
    if (smaller == nullptr) {
        larger->next = nullptr;
        return larger_head;
    }

    if (larger == nullptr) {
        smaller->next = nullptr;
        return smaller_head;
    }

    smaller->next = larger_head;
    larger->next = nullptr;

    return smaller_head;
}

int main() {
    {
        ListNode *r1 = new ListNode(1);
        ListNode *r2 = new ListNode(4);
        ListNode *r3 = new ListNode(3);
        ListNode *r4 = new ListNode(2);
        ListNode *r5 = new ListNode(5);
        ListNode *r6 = new ListNode(2);

        r1->next = r2;
        r2->next = r3;
        r3->next = r4;
        r4->next = r5;
        r5->next = r6;

        auto *ret = partition(r1, 3);
        assert(ret == r1);
        assert(ret->next == r4);
        assert(ret->next->next == r6);
        assert(ret->next->next->next == r2);
        assert(ret->next->next->next->next == r3);
        assert(ret->next->next->next->next->next == r5);
        assert(ret->next->next->next->next->next->next == nullptr);

        delete ret;
    }
    {
        ListNode *r1 = new ListNode(2);
        ListNode *r2 = new ListNode(1);

        r1->next = r2;

        auto *ret = partition(r1, 2);
        assert(ret == r2);
        assert(ret->next == r1);
        assert(ret->next->next == nullptr);

        delete ret;
    }
    {
        ListNode *r1 = new ListNode(1);
        ListNode *r2 = new ListNode(4);
        ListNode *r3 = new ListNode(3);
        ListNode *r4 = new ListNode(2);
        ListNode *r5 = new ListNode(5);
        ListNode *r6 = new ListNode(2);

        r1->next = r2;
        r2->next = r3;
        r3->next = r4;
        r4->next = r5;
        r5->next = r6;

        auto *ret = partition(r1, 10);
        assert(ret == r1);
        assert(ret->next == r2);
        assert(ret->next->next == r3);
        assert(ret->next->next->next == r4);
        assert(ret->next->next->next->next == r5);
        assert(ret->next->next->next->next->next == r6);
        assert(ret->next->next->next->next->next->next == nullptr);

        delete ret;
    }
    {
        ListNode *r1 = new ListNode(1);
        ListNode *r2 = new ListNode(4);
        ListNode *r3 = new ListNode(3);
        ListNode *r4 = new ListNode(2);
        ListNode *r5 = new ListNode(5);
        ListNode *r6 = new ListNode(2);

        r1->next = r2;
        r2->next = r3;
        r3->next = r4;
        r4->next = r5;
        r5->next = r6;

        auto *ret = partition(r1, -1);
        assert(ret == r1);
        assert(ret->next == r2);
        assert(ret->next->next == r3);
        assert(ret->next->next->next == r4);
        assert(ret->next->next->next->next == r5);
        assert(ret->next->next->next->next->next == r6);
        assert(ret->next->next->next->next->next->next == nullptr);

        delete ret;
    }
    {
        auto *ret = partition(nullptr, 10);
        assert(ret == nullptr);
    }
    return 0;
}
