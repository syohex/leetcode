#include <cassert>
#include <set>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {
    }
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    std::set<ListNode *> s;
    ListNode *p = headA;
    while (p != nullptr) {
        s.insert(p);
        p = p->next;
    }

    p = headB;
    while (p != nullptr) {
        auto it = s.find(p);
        if (it != s.end()) {
            return *it;
        }

        p = p->next;
    }
    return nullptr;
}

int main() {
    {
        ListNode *a = new ListNode(4);
        a->next = new ListNode(1);
        a->next->next = new ListNode(8);
        a->next->next->next = new ListNode(4);
        a->next->next->next->next = new ListNode(5);

        ListNode *b = new ListNode(5);
        b->next = new ListNode(6);
        b->next->next = new ListNode(1);
        b->next->next->next = a->next->next;

        auto ret = getIntersectionNode(a, b);
        assert(ret == a->next->next);
    }
    {
        ListNode *a = new ListNode(1);
        a->next = new ListNode(9);
        a->next->next = new ListNode(1);
        a->next->next->next = new ListNode(2);
        a->next->next->next->next = new ListNode(4);

        ListNode *b = new ListNode(3);
        b->next = a->next->next->next;

        auto ret = getIntersectionNode(a, b);
        assert(ret == b->next);
    }
    {
        ListNode *a = new ListNode(2);
        a->next = new ListNode(6);
        a->next->next = new ListNode(4);

        ListNode *b = new ListNode(1);
        b->next = new ListNode(5);

        auto ret = getIntersectionNode(a, b);
        assert(ret == nullptr);
    }
    return 0;
}
