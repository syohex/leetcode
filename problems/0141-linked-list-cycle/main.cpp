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
    ListNode *p = head;
    std::set<ListNode *> s;
    while (true) {
        if (p == nullptr) {
            return false;
        }

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
        ListNode *list = new ListNode(3);
        list->next = new ListNode(2);
        list->next->next = new ListNode(0);
        list->next->next->next = new ListNode(-4);
        list->next->next->next->next = list->next;
        assert(hasCycle(list));
    }
    {
        ListNode *list = new ListNode(1);
        list->next = new ListNode(2);
        list->next->next = list;
        assert(hasCycle(list));
    }
    {
        ListNode *list = new ListNode(1);
        assert(!hasCycle(list));
    }
    return 0;
}
