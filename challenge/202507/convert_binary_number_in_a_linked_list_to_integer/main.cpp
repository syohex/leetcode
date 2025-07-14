#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ~ListNode() {
        delete next;
    }
};

int getDecimalValue(ListNode *head) {
    int ret = 0;
    for (auto *p = head; p != nullptr; p = p->next) {
        ret = ret * 2 + p->val;
    }

    return ret;
}

int main() {
    {
        ListNode *n = new ListNode(1);
        n->next = new ListNode(1);
        n->next->next = new ListNode(0);
        n->next->next->next = new ListNode(0);
        auto ret = getDecimalValue(n);
        assert(ret == 12);
        delete n;
    }
    {
        ListNode *n = new ListNode(0);
        auto ret = getDecimalValue(n);
        assert(ret == 0);
        delete n;
    }
    return 0;
}
