#include <cassert>
#include <functional>
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

ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (left == right) {
        return head;
    }

    ListNode *p = head;
    ListNode *prev = nullptr;
    int i = 1;

    while (p != nullptr) {
        if (i >= left) {
            std::stack<ListNode *> stack;
            while (i <= right) {
                stack.push(p);
                p = p->next;
                ++i;
            }

            ListNode *next = p;

            if (prev == nullptr) {
                prev = stack.top();
                head = prev;
                stack.pop();
            }

            while (!stack.empty()) {
                prev->next = stack.top();
                stack.pop();

                prev = prev->next;
            }

            if (prev != nullptr) {
                prev->next = next;
            }

            return head;
        } else {
            prev = p;
            p = p->next;
        }

        ++i;
    }

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

        delete ret;
    }
    {
        ListNode *r = new ListNode(5);
        auto ret = reverseBetween(r, 1, 1);

        assert(ret->val == 5);

        delete ret;
    }
    return 0;
}