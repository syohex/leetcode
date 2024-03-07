#include <cassert>
#include <functional>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

ListNode *middleNode(ListNode *head) {
    std::function<ListNode *(ListNode * node, int i, int &len)> f;
    f = [&](ListNode *node, int i, int &len) -> ListNode * {
        if (node == nullptr) {
            len = i;
            return nullptr;
        }

        ListNode *p = f(node->next, i + 1, len);
        if (p != nullptr) {
            return p;
        }

        if (i == len / 2) {
            return node;
        }

        return nullptr;
    };

    int len = -1;
    return f(head, 0, len);
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);

        auto *ret = middleNode(r);
        assert(ret == r->next->next);
        delete r;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);
        r->next->next->next->next->next = new ListNode(6);

        auto *ret = middleNode(r);
        assert(ret == r->next->next->next);
        delete r;
    }
    return 0;
}
