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

ListNode *removeNthFromEnd(ListNode *head, int n) {
    struct Data {
        int last_pos;
        ListNode *next;
    };

    std::function<Data(ListNode * node, ListNode * prev, int pos, int n)> f;
    f = [&](ListNode *node, ListNode *prev, int pos, int n) -> Data {
        if (node == nullptr) {
            return Data{pos, nullptr};
        }

        Data d = f(node->next, node, pos + 1, n);
        if (d.last_pos - pos == n) {
            if (prev != nullptr) {
                prev->next = d.next;
            }

            node->next = nullptr;
            delete node;

            return Data{d.last_pos, d.next};
        }

        return Data{d.last_pos, node};
    };

    Data d = f(head, nullptr, 0, n);
    return d.next;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);

        auto ret = removeNthFromEnd(r, 2);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 5);
        assert(ret->next->next->next->next == nullptr);

        delete ret;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);

        auto ret = removeNthFromEnd(r, 5);
        assert(ret->val == 2);
        assert(ret->next->val == 3);
        assert(ret->next->next->val == 4);
        assert(ret->next->next->next->val == 5);
        assert(ret->next->next->next->next == nullptr);

        delete ret;
    }
    {
        ListNode *r = new ListNode(1);

        auto ret = removeNthFromEnd(r, 1);
        assert(ret == nullptr);

        delete ret;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);

        auto ret = removeNthFromEnd(r, 1);
        assert(ret->val == 1);
        assert(ret->next == nullptr);

        delete ret;
    }
    return 0;
}
