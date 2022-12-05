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

ListNode *middleNode(ListNode *head) {
    std::function<std::pair<int, ListNode *>(ListNode * node, int n)> f;
    f = [&f](ListNode *node, int n) -> std::pair<int, ListNode *> {
        if (node == nullptr) {
            return {n, nullptr};
        }

        auto d = f(node->next, n + 1);
        if (d.second != nullptr) {
            return d;
        }

        if (n == d.first / 2) {
            return {n, node};
        }

        return d;
    };

    auto d = f(head, 0);
    return d.second;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);

        auto ret = middleNode(r);
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

        auto ret = middleNode(r);
        assert(ret == r->next->next->next);

        delete r;
    }
    return 0;
}
