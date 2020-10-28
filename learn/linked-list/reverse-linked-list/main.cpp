#include <cassert>
#include <functional>
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

    ListNode *current_head = head;
    while (head->next != nullptr) {
        auto *tmp = head->next;
        head->next = tmp->next;
        tmp->next = current_head;
        current_head = tmp;
    }

    return current_head;
}

ListNode *reverseList2(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode *new_head;
    std::function<ListNode *(ListNode * node, ListNode * prev)> f;
    f = [&f, &new_head](ListNode *node, ListNode *prev) -> ListNode * {
        if (node->next == nullptr) {
            node->next = prev;
            new_head = node;
            return node->next;
        }

        ListNode *p = f(node->next, node);
        p->next = prev;
        return prev;
    };

    (void)f(head, nullptr);
    return new_head;
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
    {
        ListNode *lst = new ListNode(1);
        lst->next = new ListNode(2);
        lst->next->next = new ListNode(3);
        lst->next->next->next = new ListNode(4);
        lst->next->next->next->next = new ListNode(5);
        auto ret = reverseList2(lst);
        assert(ret->val == 5);
        assert(ret->next->val == 4);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 2);
        assert(ret->next->next->next->next->val == 1);
        assert(ret->next->next->next->next->next == nullptr);
    }
    return 0;
}
