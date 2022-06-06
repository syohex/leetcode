#include <cassert>
#include <set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
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
        if (s.find(p) != s.end()) {
            return p;
        }

        p = p->next;
    }

    return nullptr;
}

int main() {
    {
        ListNode *r1 = new ListNode(4);
        r1->next = new ListNode(1);
        r1->next->next = new ListNode(8);
        r1->next->next->next = new ListNode(4);
        r1->next->next->next->next = new ListNode(5);

        ListNode *r2 = new ListNode(5);
        r2->next = new ListNode(6);
        r2->next->next = new ListNode(6);
        r2->next->next->next = r1->next->next;

        auto ret = getIntersectionNode(r1, r2);
        assert(ret == r1->next->next);
    }
    {
        ListNode *r1 = new ListNode(1);
        r1->next = new ListNode(9);
        r1->next->next = new ListNode(1);
        r1->next->next->next = new ListNode(2);
        r1->next->next->next->next = new ListNode(4);

        ListNode *r2 = new ListNode(3);
        r2->next = r1->next->next->next;

        auto ret = getIntersectionNode(r1, r2);
        assert(ret == r2->next);
    }
    {
        ListNode *r1 = new ListNode(2);
        r1->next = new ListNode(6);
        r1->next->next = new ListNode(4);

        ListNode *r2 = new ListNode(1);
        r2->next = new ListNode(5);

        auto ret = getIntersectionNode(r1, r2);
        assert(ret == nullptr);
    }
    return 0;
}
