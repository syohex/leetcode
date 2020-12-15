#include <cassert>
#include <functional>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

ListNode *plusOne(ListNode *head) {
    int carry = 1;
    std::function<void(ListNode * node)> f;
    f = [&f, &carry](ListNode *node) {
        if (node == nullptr) {
            return;
        }

        f(node->next);
        int val = node->val + carry;
        node->val = val % 10;
        carry = val / 10;
    };

    f(head);

    if (carry == 0) {
        return head;
    }

    ListNode *new_head = new ListNode(carry);
    new_head->next = head;
    return new_head;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);

        auto ret = plusOne(r);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 4);
        assert(ret->next->next->next == nullptr);

        delete r;
    }
    {
        ListNode *r = new ListNode(0);
        auto ret = plusOne(r);
        assert(ret->val == 1);
        assert(ret->next == nullptr);
        delete r;
    }
    {
        ListNode *r = new ListNode(9);
        auto ret = plusOne(r);
        assert(ret->val == 1);
        assert(ret->next->val == 0);
        assert(ret->next->next == nullptr);
        delete r;
    }
    return 0;
}
