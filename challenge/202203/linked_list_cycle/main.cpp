#include <cassert>
#include <set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }

    ~ListNode() {
        delete next;
    }
};

bool hasCycle(ListNode *head) {
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
        ListNode *r = new ListNode(3);
        r->next = new ListNode(2);
        r->next->next = new ListNode(0);
        r->next->next->next = new ListNode(-4);
        r->next->next->next->next = r->next;

        assert(hasCycle(r));

        r->next->next->next->next = nullptr;
        delete r;
    }
    {
        ListNode *r = new ListNode(3);
        r->next = new ListNode(2);
        r->next->next = r;

        assert(hasCycle(r));

        r->next->next = nullptr;
        delete r;
    }
    {
        ListNode *r = new ListNode(3);
        assert(!hasCycle(r));
        delete r;
    }
    return 0;
}