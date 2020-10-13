#include <cassert>
#include <map>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

ListNode *sortList(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode *node = head;
    std::map<int, int> m;

    while (node != nullptr) {
        ++m[node->val];
        node = node->next;
    }

    ListNode *ret = nullptr;
    ListNode **n = &ret;
    for (const auto &it : m) {
        for (int i = 0; i < it.second; ++i) {
            (*n) = new ListNode(it.first);
            n = &((*n)->next);
        }
    }

    return ret;
}

int main() {
    {
        ListNode *lst = new ListNode(4);
        lst->next = new ListNode(2);
        lst->next->next = new ListNode(1);
        lst->next->next->next = new ListNode(3);
        auto ret = sortList(lst);

        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 4);
        assert(ret->next->next->next->next == nullptr);

        delete ret;
        delete lst;
    }
    {
        ListNode *lst = new ListNode(-1);
        lst->next = new ListNode(5);
        lst->next->next = new ListNode(3);
        lst->next->next->next = new ListNode(4);
        lst->next->next->next->next = new ListNode(0);
        auto ret = sortList(lst);

        assert(ret->val == -1);
        assert(ret->next->val == 0);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 4);
        assert(ret->next->next->next->next->val == 5);
        assert(ret->next->next->next->next->next == nullptr);

        delete ret;
        delete lst;
    }
    return 0;
}
