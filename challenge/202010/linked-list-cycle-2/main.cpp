#include <cassert>
#include <set>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode *detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    std::set<ListNode *> s;
    ListNode *p = head;
    while (true) {
        if (p == nullptr) {
            return nullptr;
        }

        if (s.find(p) != s.end()) {
            return p;
        }

        s.insert(p);
        p = p->next;
    }

    return nullptr;
}

int main() {
    {
        ListNode *r = new ListNode(3);
        r->next = new ListNode(2);
        r->next->next = new ListNode(0);
        r->next->next->next = new ListNode(-4);
        r->next->next->next->next = r->next;

        auto ret = detectCycle(r);
        assert(ret == r->next);
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = r;

        auto ret = detectCycle(r);
        assert(ret == r);
    }
    {
        ListNode *r = new ListNode(1);
        auto ret = detectCycle(r);
        assert(ret == nullptr);
    }
    return 0;
}
