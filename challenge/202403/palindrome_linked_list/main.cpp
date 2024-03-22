#include <cassert>
#include <functional>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ~ListNode() {
        delete next;
    }
};

bool isPalindrome(ListNode *head) {
    struct Data {
        int len;
        ListNode *node;
        bool ok;
    };

    std::function<Data (ListNode *node, int i)> f;
    f = [&](ListNode *node, int i) -> Data {
        if (node == nullptr) {
            return {i, head, true};
        }

        auto d = f(node->next, i + 1);
        if (!d.ok || i < d.len / 2) {
            return d;
        }

        bool ok = node->val == d.node->val;
        return {d.len, d.node->next, ok};
    };

    return f(head, 0).ok;
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
        r->next->next = new ListNode(1);

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
