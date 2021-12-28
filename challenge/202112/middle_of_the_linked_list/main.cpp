#include <cassert>
#include <functional>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

ListNode *middleNode(ListNode *head) {
    ListNode *ret;
    std::function<int(ListNode * node, int count)> f;
    f = [&](ListNode *node, int count) -> int {
        if (node == nullptr) {
            return count;
        }

        int len = f(node->next, count + 1);
        if (count == len / 2) {
            ret = node;
        }
        return len;
    };

    f(head, 0);
    return ret;
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
