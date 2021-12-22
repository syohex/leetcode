#include <cassert>
#include <list>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

void reorderList(ListNode *head) {
    std::list<ListNode *> q;

    ListNode *p = head;
    while (p != nullptr) {
        q.push_back(p);
        p = p->next;
    }

    q.pop_front();

    bool is_front = false;
    p = head;
    while (!q.empty()) {
        if (is_front) {
            p->next = q.front();
            q.pop_front();
        } else {
            p->next = q.back();
            q.pop_back();
        }

        p = p->next;
        is_front = !is_front;
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

    return 0;
}