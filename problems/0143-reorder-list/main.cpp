#include <cassert>
#include <vector>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

void reorderList(ListNode *head) {
    if (head == nullptr) {
        return;
    }

    std::vector<ListNode *> v;
    ListNode *p = head->next;
    while (p != nullptr) {
        v.push_back(p);
        p = p->next;
    }

    p = head;
    bool front = false;
    size_t f = 0, e = v.size() - 1;
    for (size_t i = 0; i < v.size(); ++i) {
        if (front) {
            p->next = v[f];
            ++f;
        } else {
            p->next = v[e];
            --e;
        }

        p = p->next;
        front = !front;
    }
    p->next = nullptr;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        reorderList(r);
        assert(r->val == 1);
        assert(r->next->val == 4);
        assert(r->next->next->val == 2);
        assert(r->next->next->next->val == 3);
        assert(r->next->next->next->next == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);
        reorderList(r);
        assert(r->val == 1);
        assert(r->next->val == 5);
        assert(r->next->next->val == 2);
        assert(r->next->next->next->val == 4);
        assert(r->next->next->next->next->val == 3);
        assert(r->next->next->next->next->next == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        reorderList(r);
        assert(r->val == 1);
        assert(r->next == nullptr);
    }
    return 0;
}
