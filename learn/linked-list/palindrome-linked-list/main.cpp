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

bool isPalindrome(ListNode *head) {
    if (head == nullptr) {
        return true;
    }

    ListNode *p = head;
    std::function<bool(ListNode * node)> f;
    f = [&f, &p](ListNode *node) {
        if (node == nullptr) {
            return true;
        }

        if (f(node->next)) {
            if (p->val != node->val) {
                return false;
            }

            p = p->next;
            return true;
        }

        return false;
    };

    return f(head);
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        assert(!isPalindrome(r));
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(2);
        r->next->next->next = new ListNode(1);
        assert(isPalindrome(r));
    }
    return 0;
}
