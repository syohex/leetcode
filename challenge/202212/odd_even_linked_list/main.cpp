#include <cassert>
#include <functional>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

ListNode *oddEvenList(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == nullptr) {
        return head;
    }

    ListNode *odds = head;
    ListNode *evens = head->next;
    ListNode *odds_head = odds;
    ListNode *evens_head = evens;
    ListNode *p = head->next->next;
    int i = 1;
    while (p != nullptr) {
        if (i % 2 == 1) {
            odds->next = p;
            odds = p;
        } else {
            evens->next = p;
            evens = p;
        }

        p = p->next;
        ++i;
    }

    evens->next = nullptr;

    odds->next = evens_head;
    return odds_head;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);

        auto ret = oddEvenList(r);
        assert(ret->val == 1);
        assert(ret->next->val == 3);
        assert(ret->next->next->val == 5);
        assert(ret->next->next->next->val == 2);
        assert(ret->next->next->next->next->val == 4);
        assert(ret->next->next->next->next->next == nullptr);
    }
    {
        ListNode *r = new ListNode(2);
        r->next = new ListNode(1);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(5);
        r->next->next->next->next = new ListNode(6);
        r->next->next->next->next->next = new ListNode(4);
        r->next->next->next->next->next->next = new ListNode(7);

        auto ret = oddEvenList(r);
        assert(ret->val == 2);
        assert(ret->next->val == 3);
        assert(ret->next->next->val == 6);
        assert(ret->next->next->next->val == 7);
        assert(ret->next->next->next->next->val == 1);
        assert(ret->next->next->next->next->next->val == 5);
        assert(ret->next->next->next->next->next->next->val == 4);
        assert(ret->next->next->next->next->next->next->next == nullptr);
    }
    return 0;
}
