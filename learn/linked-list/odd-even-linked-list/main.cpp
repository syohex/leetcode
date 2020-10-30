#include <cassert>
#include <vector>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int value) : val(value), next(nullptr) {
    }
};

ListNode *oddEvenList(ListNode *head) {
    if (head == nullptr) {
        return head;
    }

    std::vector<ListNode *> v[2];
    ListNode *p = head;
    int index = 0;
    while (p != nullptr) {
        v[index].push_back(p);
        index = index == 0 ? 1 : 0;
        p = p->next;
    }

    p = head;
    for (size_t i = 1; i < v[0].size(); ++i) {
        p->next = v[0][i];
        p = p->next;
    }
    for (size_t i = 0; i < v[1].size(); ++i) {
        p->next = v[1][i];
        p = p->next;
    }
    p->next = nullptr;

    return head;
}

ListNode *oddEvenList2(ListNode *head) {
    if (head == nullptr) {
        return head;
    }

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *even_head = even;
    while (even != nullptr && even->next != nullptr) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = even_head;
    return head;
}

int main() {
    for (auto *f : {oddEvenList, oddEvenList2}) {
        {
            ListNode *r = new ListNode(1);
            r->next = new ListNode(2);
            r->next->next = new ListNode(3);
            r->next->next->next = new ListNode(4);
            r->next->next->next->next = new ListNode(5);
            auto ret = f(r);
            assert(ret->val == 1);
            assert(ret->next->val == 3);
            assert(ret->next->next->val == 5);
            assert(ret->next->next->next->val == 2);
            assert(ret->next->next->next->next->val == 4);
            assert(ret->next->next->next->next->next == nullptr);
        }
        {
            ListNode *r = new ListNode(2);
            r->next = new ListNode(1);
            r->next->next = new ListNode(3);
            r->next->next->next = new ListNode(5);
            r->next->next->next->next = new ListNode(6);
            r->next->next->next->next->next = new ListNode(4);
            r->next->next->next->next->next->next = new ListNode(7);
            auto ret = f(r);
            assert(ret->val == 2);
            assert(ret->next->val == 3);
            assert(ret->next->next->val == 6);
            assert(ret->next->next->next->val == 7);
            assert(ret->next->next->next->next->val == 1);
            assert(ret->next->next->next->next->next->val == 5);
            assert(ret->next->next->next->next->next->next->val == 4);
            assert(ret->next->next->next->next->next->next->next == nullptr);
        }
    }
    return 0;
}
