#include <cassert>
#include <functional>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode *reverseBetween(ListNode *head, int left, int right) {
    int i = 1;
    ListNode *p = head;
    ListNode *prev = nullptr;
    while (i < left) {
        prev = p;
        p = p->next;
        ++i;
    }

    std::stack<ListNode *> stack;
    while (i < right) {
        stack.push(p);
        p = p->next;
        ++i;
    }

    if (prev != nullptr) {
        prev->next = p;
    } else {
        head = p;
    }

    ListNode *end = p->next;
    while (!stack.empty()) {
        ListNode *tmp = stack.top();
        stack.pop();
        p->next = tmp;
        p = tmp;
    }

    p->next = end;
    return head;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);
        auto ret = reverseBetween(r, 2, 4);
        assert(ret->val == 1);
        assert(ret->next->val == 4);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 2);
        assert(ret->next->next->next->next->val == 5);
        assert(ret->next->next->next->next->next == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);
        auto ret = reverseBetween(r, 1, 5);
        assert(ret->val == 5);
        assert(ret->next->val == 4);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 2);
        assert(ret->next->next->next->next->val == 1);
        assert(ret->next->next->next->next->next == nullptr);
    }
    {
        ListNode *r = new ListNode(5);
        auto ret = reverseBetween(r, 1, 1);
        assert(ret->val == 5);
        assert(ret->next == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        auto ret = reverseBetween(r, 3, 3);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next == nullptr);
    }
    return 0;
}
