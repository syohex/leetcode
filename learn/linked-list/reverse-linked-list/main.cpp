#include <cassert>
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

ListNode *reverseList(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode *p = head;
    while (head->next != nullptr) {
       auto *tmp = head->next;
       head->next = tmp->next; 
       tmp->next = p;
       p = tmp;
    }

    return p;
}

int main() {
    {
        ListNode *lst = new ListNode(1);
        lst->next = new ListNode(2);
        lst->next->next = new ListNode(3);
        lst->next->next->next = new ListNode(4);
        lst->next->next->next->next = new ListNode(5);
        auto ret = reverseList(lst);
        assert(ret->val == 5);
        assert(ret->next->val == 4);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 2);
        assert(ret->next->next->next->next->val == 1);
        assert(ret->next->next->next->next->next == nullptr);
    }
    return 0;
}
