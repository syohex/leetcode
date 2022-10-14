#include <cassert>
#include <functional>
#include <utility>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

ListNode *deleteMiddle(ListNode *head) {
    std::function<int(ListNode * node, ListNode * prev, int i)> f;
    f = [&](ListNode *node, ListNode *prev, int i) -> int {
        if (node == nullptr) {
            return i;
        }

        int len = f(node->next, node, i + 1);
        if (i == len / 2) {
            if (prev != nullptr) {
                prev->next = node->next;
            }

            node->next = nullptr;
            delete node;
        }

        return len;
    };

    int ret = f(head, nullptr, 0);
    if (ret == 1) {
        return nullptr;
    }

    return head;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(3);
        r->next->next = new ListNode(4);
        r->next->next->next = new ListNode(7);
        r->next->next->next->next = new ListNode(1);
        r->next->next->next->next->next = new ListNode(2);
        r->next->next->next->next->next->next = new ListNode(6);

        auto ret = deleteMiddle(r);
        assert(ret->val == 1);
        assert(ret->next->val == 3);
        assert(ret->next->next->val == 4);
        assert(ret->next->next->next->val == 1);
        assert(ret->next->next->next->next->val == 2);
        assert(ret->next->next->next->next->next->val == 6);
        assert(ret->next->next->next->next->next->next == nullptr);

        delete r;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);

        auto ret = deleteMiddle(r);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 4);
        assert(ret->next->next->next == nullptr);

        delete r;
    }
    {
        ListNode *r = new ListNode(2);
        r->next = new ListNode(1);

        auto ret = deleteMiddle(r);
        assert(ret->val == 2);
        assert(ret->next == nullptr);

        delete r;
    }
    {
        ListNode *r = new ListNode(1);

        auto ret = deleteMiddle(r);
        assert(ret == nullptr);

        delete r;
    }
    return 0;
}
