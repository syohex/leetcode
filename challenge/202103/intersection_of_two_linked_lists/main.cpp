#include <cassert>
#include <set>

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {
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
        ListNode *l1 = new ListNode(4);
        l1->next = new ListNode(1);
        l1->next->next = new ListNode(8);
        l1->next->next->next = new ListNode(4);
        l1->next->next->next->next = new ListNode(5);

        ListNode *l2 = new ListNode(5);
        l2->next = new ListNode(6);
        l2->next->next = new ListNode(1);
        l2->next->next->next = l1->next->next;

        auto ret = getIntersectionNode(l1, l2);
        assert(ret == l1->next->next);
    }
    {
        ListNode *l1 = new ListNode(1);
        l1->next = new ListNode(9);
        l1->next->next = new ListNode(1);
        l1->next->next->next = new ListNode(2);
        l1->next->next->next->next = new ListNode(4);

        ListNode *l2 = new ListNode(3);
        l2->next = l1->next->next->next;

        auto ret = getIntersectionNode(l1, l2);
        assert(ret == l1->next->next->next);
    }
    {
        ListNode *l1 = new ListNode(2);
        l1->next = new ListNode(6);
        l1->next->next = new ListNode(4);

        ListNode *l2 = new ListNode(1);
        l2->next = new ListNode(5);

        auto ret = getIntersectionNode(l1, l2);
        assert(ret == nullptr);
    }
    return 0;
}
