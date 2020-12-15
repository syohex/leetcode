#include <cassert>
#include <cstdio>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (head == nullptr) {
        return head;
    }

    int i = 1;
    ListNode *p = head;
    ListNode *prev = nullptr;
    while (i < m) {
        prev = p;
        p = p->next;
        ++i;
    }

    std::stack<ListNode *> st;
    while (i < n) {
        st.push(p);
        p = p->next;
        ++i;
    }

    if (prev != nullptr) {
        prev->next = p;
    } else {
        head = p;
    }

    ListNode *next = p->next;
    while (!st.empty()) {
        ListNode *tmp = st.top();
        st.pop();
        p->next = tmp;
        p = tmp;
    }

    p->next = next;
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
        delete ret;
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
        delete ret;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);

        auto ret = reverseBetween(r, 1, 2);
        assert(ret->val == 2);
        assert(ret->next->val == 1);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 4);
        assert(ret->next->next->next->next->val == 5);
        assert(ret->next->next->next->next->next == nullptr);
        delete ret;
    }
    return 0;
}
