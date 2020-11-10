#include <cassert>
#include <set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode *detectCycle(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }

    std::set<ListNode *> s;
    ListNode *p = head;
    while (p != nullptr) {
        s.insert(p);

        auto it = s.find(p->next);
        if (it != s.end()) {
            return *it;
        }

        p = p->next;
    }

    return nullptr;
}

int main() {
    {
        ListNode *lst = new ListNode(3);
        lst->next = new ListNode(2);
        lst->next->next = new ListNode(0);
        lst->next->next->next = new ListNode(-4);
        lst->next->next->next->next = lst->next;
        auto ret = detectCycle(lst);
        assert(ret == lst->next);
    }
    {
        ListNode *lst = new ListNode(1);
        lst->next = new ListNode(2);
        lst->next->next = lst;
        auto ret = detectCycle(lst);
        assert(ret == lst);
    }
    {
        ListNode *lst = new ListNode(1);
        auto ret = detectCycle(lst);
        assert(ret == nullptr);
    }
    return 0;
}
