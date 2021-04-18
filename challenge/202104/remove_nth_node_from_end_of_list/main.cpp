#include <cassert>
#include <vector>
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
    std::vector<ListNode *> v;
    ListNode *p = head;
    while (p != nullptr) {
        v.push_back(p);
        p = p->next;
    }

    if (v.size() == 1 && n == 1) {
        delete head;
        return nullptr;
    }

    if (n == v.size()) {
        head->next = nullptr;
        delete head;
        return v[1];
    }

    if (n == 1) {
        delete v.back();
        v[v.size() - n - 1]->next = nullptr;
        return head;
    }

    size_t prev = v.size() - n - 1;
    size_t index = v.size() - n;
    size_t next = v.size() - n + 1;
    v[prev]->next = v[next];

    v[index]->next = nullptr;
    delete v[index];

    return head;
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
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        auto ret = removeNthFromEnd(r, 1);
        assert(ret->val == 1);
        assert(ret->next == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        auto ret = removeNthFromEnd(r, 1);
        assert(ret == nullptr);
    }
    return 0;
}