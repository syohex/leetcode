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
    std::function<bool(ListNode * node, ListNode * *p)> f;
    f = [&f](ListNode *node, ListNode **p) -> bool {
        if (node == nullptr) {
            return true;
        }

        bool ret = f(node->next, p);
        if (!ret || (*p)->val != node->val) {
            return false;
        }

        *p = (*p)->next;
        return true;
    };

    ListNode **p = &head;
    return f(head, p);
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
