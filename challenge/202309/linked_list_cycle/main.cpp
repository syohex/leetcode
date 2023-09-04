#include <cassert>
#include <set>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        s_.insert(this);
        if (s_.find(next) != s_.end()) {
            return;
        }
        delete next;
    }

    static std::set<ListNode *> s_;
};

std::set<ListNode *> ListNode::s_ = {};

bool hasCycle(ListNode *head) {
    ListNode *p = head;
    ListNode *q = head;

    while (p != nullptr && q != nullptr && q->next != nullptr) {
        p = p->next;
        q = q->next->next;

        if (p == q) {
            return true;
        }
    }

    return false;
}

int main() {
    {
        ListNode *p1 = new ListNode(3);
        ListNode *p2 = new ListNode(2);
        ListNode *p3 = new ListNode(0);
        ListNode *p4 = new ListNode(-4);

        p1->next = p2;
        p2->next = p3;
        p3->next = p4;
        p4->next = p2;

        assert(hasCycle(p1));
        delete p1;
    }
    {
        ListNode *p1 = new ListNode(3);
        ListNode *p2 = new ListNode(2);

        p1->next = p2;
        p2->next = p1;

        assert(hasCycle(p1));
        delete p1;
    }
    {
        ListNode *p1 = new ListNode(-1);
        assert(!hasCycle(p1));
        delete p1;
    }
    {
        ListNode *p1 = new ListNode(1);
        ListNode *p2 = new ListNode(2);
        p1->next = p2;
        assert(!hasCycle(p1));
        delete p1;
    }
    return 0;
}
