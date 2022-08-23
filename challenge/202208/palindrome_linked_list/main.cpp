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
    ListNode *p = head;

    std::function<bool(ListNode * node)> f;
    f = [&](ListNode *node) -> bool {
        if (node == nullptr) {
            return true;
        }

        if (!f(node->next)) {
            return false;
        }

        if (node->val != p->val) {
            return false;
        }

        p = p->next;
        return true;
    };

    return f(head);
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(2);
        r->next->next->next = new ListNode(1);
        assert(isPalindrome(r));
        delete r;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        assert(!isPalindrome(r));
        delete r;
    }
    return 0;
}