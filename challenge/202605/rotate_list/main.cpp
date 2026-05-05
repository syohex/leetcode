#include <cassert>
#include <print>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

std::vector<int> toVector(ListNode *p) {
    std::vector<int> v;
    while (p != nullptr) {
        v.push_back(p->val);
        p = p->next;
    }
    std::println("## v={}", v);
    return v;
}

ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr) {
        return nullptr;
    }

    int len = 0;
    ListNode *p = head;
    ListNode *prev = nullptr;
    while (p != nullptr) {
        ++len;
        prev = p;
        p = p->next;
    }

    prev->next = head;
    k = k % len;

    prev = nullptr;
    p = head;
    for (int i = 0; i < len - k; ++i) {
        prev = p;
        p = p->next;
    }

    prev->next = nullptr;
    return p;
}

int main() {
    {
        auto ret = rotateRight(nullptr, 0);
        assert(ret == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        std::vector<int> expected{1};
        auto ret = rotateRight(r, 0);
        assert(toVector(ret) == expected);
        delete ret;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        std::vector<int> expected{1, 2};
        auto ret = rotateRight(r, 0);
        assert(toVector(ret) == expected);
        delete ret;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);
        std::vector<int> expected{4, 5, 1, 2, 3};
        auto ret = rotateRight(r, 2);
        assert(toVector(ret) == expected);
        delete ret;
    }
    {
        ListNode *r = new ListNode(0);
        r->next = new ListNode(1);
        r->next->next = new ListNode(2);
        std::vector<int> expected{2, 0, 1};
        auto ret = rotateRight(r, 4);
        assert(toVector(ret) == expected);
        delete ret;
    }
    return 0;
}
