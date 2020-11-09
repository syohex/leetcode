#include <cassert>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == nullptr) {
        return head;
    }

    std::vector<ListNode *> v;
    ListNode *p = head;
    while (p != nullptr) {
        v.push_back(p);
        p = p->next;
    }

    k = k % static_cast<int>(v.size());
    int start = (static_cast<int>(v.size()) - k) % static_cast<int>(v.size());
    head = v[start];
    p = head;
    for (size_t i = 1; i <= v.size(); ++i) {
        p->next = v[(start + i) % v.size()];
        if (p->next == head) {
            p->next = nullptr;
        }
        p = p->next;
    }

    return head;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);

        auto ret = rotateRight(r, 2);

        assert(ret->val == 4);
        assert(ret->next->val == 5);
        assert(ret->next->next->val == 1);
        assert(ret->next->next->next->val == 2);
        assert(ret->next->next->next->next->val == 3);
        assert(ret->next->next->next->next->next == nullptr);
    }
    {
        ListNode *r = new ListNode(0);
        r->next = new ListNode(1);
        r->next->next = new ListNode(2);

        auto ret = rotateRight(r, 4);

        assert(ret->val == 2);
        assert(ret->next->val == 0);
        assert(ret->next->next->val == 1);
        assert(ret->next->next->next == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        auto ret = rotateRight(r, 0);
        assert(ret->val == 1);
        assert(ret->next == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        auto ret = rotateRight(r, 0);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next == nullptr);
    }
    return 0;
}
