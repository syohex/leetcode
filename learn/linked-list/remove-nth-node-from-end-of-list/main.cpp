#include <cassert>
#include <vector>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
    std::vector<ListNode *> v;
    ListNode *p = head;
    while (p != nullptr) {
        v.push_back(p);
        p = p->next;
    }

    if (n == 1) {
        if (v.size() == 1) {
            return nullptr;
        }

        v[v.size() - 2]->next = nullptr;
        return head;
    }

    if (n == static_cast<int>(v.size())) {
        return v[1];
    }

    v[v.size() - n - 1]->next = v[v.size() - n + 1];
    return head;
}

int main() {
    {
        ListNode *lst = new ListNode(1);

        auto ret = removeNthFromEnd(lst, 1);
        assert(ret == nullptr);
    }
    {
        ListNode *lst = new ListNode(1);
        lst->next = new ListNode(2);

        auto ret = removeNthFromEnd(lst, 1);
        assert(ret->val == 1);
        assert(ret->next == nullptr);
    }
    {
        ListNode *lst = new ListNode(1);
        lst->next = new ListNode(2);
        lst->next->next = new ListNode(3);
        lst->next->next->next = new ListNode(4);
        lst->next->next->next->next = new ListNode(5);

        auto ret = removeNthFromEnd(lst, 2);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 5);
        assert(ret->next->next->next->next == nullptr);
    }
    return 0;
}
