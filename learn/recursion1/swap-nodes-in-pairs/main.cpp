#include <cassert>
#include <functional>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode *swapPairs(ListNode *head) {
    std::function<ListNode *(ListNode * node)> f;
    f = [&f](ListNode *node) -> ListNode * {
        if (node == nullptr || node->next == nullptr) {
            return node;
        }

        ListNode *next = node->next;
        node->next = f(next->next);
        next->next = node;
        return next;
    };

    return f(head);
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        auto ret = swapPairs(r);
        assert(ret->val == 2);
        assert(ret->next->val == 1);
        assert(ret->next->next->val == 4);
        assert(ret->next->next->next->val == 3);
        assert(ret->next->next->next->next == nullptr);
    }
    {
        swapPairs(nullptr);
        // check don't panic
    }
    {
        ListNode *r = new ListNode(1);
        auto ret = swapPairs(r);
        assert(ret->val == 1);
        assert(ret->next == nullptr);
    }
    return 0;
}
