#include <cassert>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

ListNode *doubleIt(ListNode *head) {
    std::vector<ListNode *> stack;
    ListNode *p = head;
    while (p != nullptr) {
        stack.push_back(p);
        p = p->next;
    }

    int carry = 0;
    int len = stack.size();
    for (int i = len - 1; i >= 0; --i) {
        int val = stack[i]->val * 2 + carry;
        if (val >= 10) {
            stack[i]->val = val % 10;
            carry = 1;
        } else {
            stack[i]->val = val;
            carry = 0;
        }
    }

    if (carry == 0) {
        return head;
    }

    ListNode *ret = new ListNode(carry);
    ret->next = head;
    return ret;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(8);
        r->next->next = new ListNode(9);

        auto *ret = doubleIt(r);
        assert(ret->val == 3);
        assert(ret->next->val == 7);
        assert(ret->next->next->val == 8);
        assert(ret->next->next->next == nullptr);

        delete ret;
    }
    {
        ListNode *r = new ListNode(9);
        r->next = new ListNode(9);
        r->next->next = new ListNode(9);

        auto *ret = doubleIt(r);
        assert(ret->val == 1);
        assert(ret->next->val == 9);
        assert(ret->next->next->val == 9);
        assert(ret->next->next->next->val == 8);
        assert(ret->next->next->next->next == nullptr);

        delete ret;
    }
    return 0;
}
