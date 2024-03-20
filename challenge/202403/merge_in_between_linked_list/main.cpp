#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    ListNode *p1 = nullptr;
    ListNode *p2 = list1;

    for (int i = 0; i < b; ++i) {
        if (i == a - 1) {
            p1 = p2;
        }

        p2 = p2->next;
    }

    ListNode *p3 = list2;
    while (p3->next != nullptr) {
        p3 = p3->next;
    }

    p1->next = list2;
    p3->next = p2->next;
    p2->next = nullptr;

    return list1;
}

int main() {
    {
        ListNode *r1 = new ListNode(10);
        r1->next = new ListNode(1);
        r1->next->next = new ListNode(13);
        r1->next->next->next = new ListNode(6);
        r1->next->next->next->next = new ListNode(9);
        r1->next->next->next->next->next = new ListNode(5);

        ListNode *r2 = new ListNode(1001);
        r2->next = new ListNode(1002);
        r2->next->next = new ListNode(1003);

        auto *ret = mergeInBetween(r1, 3, 4, r2);
        assert(ret->val == 10);
        assert(ret->next->val == 1);
        assert(ret->next->next->val == 13);
        assert(ret->next->next->next->val == 1001);
        assert(ret->next->next->next->next->val == 1002);
        assert(ret->next->next->next->next->next->val == 1003);
        assert(ret->next->next->next->next->next->next->val == 5);
        assert(ret->next->next->next->next->next->next->next == nullptr);
    }
    {
        ListNode *r1 = new ListNode(0);
        r1->next = new ListNode(1);
        r1->next->next = new ListNode(2);
        r1->next->next->next = new ListNode(3);
        r1->next->next->next->next = new ListNode(4);
        r1->next->next->next->next->next = new ListNode(5);
        r1->next->next->next->next->next->next = new ListNode(6);

        ListNode *r2 = new ListNode(1000);
        r2->next = new ListNode(1001);
        r2->next->next = new ListNode(1002);
        r2->next->next->next = new ListNode(1003);
        r2->next->next->next->next = new ListNode(1004);

        auto *ret = mergeInBetween(r1, 2, 5, r2);
        assert(ret->val == 0);
        assert(ret->next->val == 1);
        assert(ret->next->next->val == 1000);
        assert(ret->next->next->next->val == 1001);
        assert(ret->next->next->next->next->val == 1002);
        assert(ret->next->next->next->next->next->val == 1003);
        assert(ret->next->next->next->next->next->next->val == 1004);
        assert(ret->next->next->next->next->next->next->next->val == 6);
        assert(ret->next->next->next->next->next->next->next->next == nullptr);
    }
    return 0;
}
