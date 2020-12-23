#include <cassert>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

ListNode *reverseList(ListNode *head) {
    if (head == nullptr) {
        return head;
    }
    std::stack<ListNode *> s;
    ListNode *node = head;

    while (node != nullptr) {
        s.push(node);
        node = node->next;
    }

    ListNode *ret = s.top();
    s.pop();
    node = ret;
    while (!s.empty()) {
        ListNode *tmp = s.top();
        s.pop();
        node->next = tmp;
        node = tmp;
    }

    node->next = nullptr;
    return ret;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        auto ret = reverseList(r);
        assert(ret->val == 1);
        assert(ret->next == nullptr);
        delete ret;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);
        auto ret = reverseList(r);
        assert(ret->val == 5);
        assert(ret->next->val == 4);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 2);
        assert(ret->next->next->next->next->val == 1);
        assert(ret->next->next->next->next->next == nullptr);
        delete ret;
    }
    assert(reverseList(nullptr) == nullptr);
    return 0;
}
