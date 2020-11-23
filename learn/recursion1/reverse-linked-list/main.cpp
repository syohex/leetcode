#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *current = head;
    while (current != nullptr) {
        ListNode *tmp = current->next;
        current->next = prev;
        prev = current;
        current = tmp;
    }

    return prev;
}

ListNode *reverseList2(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    auto *r = reverseList2(head->next);
    head->next->next = head;
    head->next = nullptr;
    return r;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);
        auto ret = reverseList(r);
        assert(ret->val == 5);
        assert(ret->next->val == 4);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 2);
        assert(ret->next->next->next->next->val == 1);
        assert(ret->next->next->next->next->next == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);
        auto ret = reverseList2(r);
        assert(ret->val == 5);
        assert(ret->next->val == 4);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 2);
        assert(ret->next->next->next->next->val == 1);
        assert(ret->next->next->next->next->next == nullptr);
    }
    return 0;
}
