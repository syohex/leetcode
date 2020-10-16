#include <cassert>
#include <cstdio>
#include <set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {
    }
};

bool hasCycle(ListNode *head) {
    if (head == nullptr) {
        return false;
    }

    ListNode *p1 = head;
    ListNode *p2 = head->next;
    while (p1 != p2) {
        if (p1 == nullptr || p2 == nullptr || p2->next == nullptr) {
            return false;
        }

        p1 = p1->next;
        p2 = p2->next->next;
    }

    return true;
}

bool hasCycle2(ListNode *head) {
    if (head == nullptr) {
        return false;
    }

    std::set<ListNode *> s;
    ListNode *p = head;
    while (p != nullptr) {
        if (s.find(p) != s.end()) {
            return true;
        }

        s.insert(p);
        p = p->next;
    }

    return false;
}

int main() {
    {
        ListNode *ln = new ListNode(3);
        ln->next = new ListNode(2);
        ln->next->next = new ListNode(0);
        ln->next->next->next = new ListNode(-4);
        ln->next->next->next->next = ln->next;
        assert(hasCycle(ln));
        assert(hasCycle2(ln));
        delete ln;
    }
    {
        ListNode *ln = new ListNode(1);
        ln->next = new ListNode(2);
        ln->next->next = ln;
        assert(hasCycle(ln));
        assert(hasCycle2(ln));
        delete ln;
    }
    {
        ListNode *ln = new ListNode(1);
        assert(!hasCycle(ln));
        assert(!hasCycle2(ln));
        delete ln;
    }
    return 0;
}
