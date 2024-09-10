#include <cassert>
#include <vector>
#include <algorithm>
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

ListNode *insertGreatestCommonDivisors(ListNode *head) {
    const auto gcd = [](int a, int b) {
        int x = std::max(a, b);
        int y = std::min(a, b);

        while (x % y != 0) {
            int m = x % y;
            x = y;
            y = m;
        }

        return y;
    };

    ListNode *p = head;
    ListNode *q = head->next;

    while (q != nullptr) {
        ListNode *d = new ListNode(gcd(p->val, q->val));
        p->next = d;
        d->next = q;

        p = q;
        q = p->next;
    }

    return head;
}

ListNode *toList(const std::vector<int> &v) {
    ListNode *head = nullptr;
    ListNode **p = &head;
    for (int n : v) {
        *p = new ListNode(n);
        p = &((*p)->next);
    }
    return head;
}

std::vector<int> toVector(ListNode *head) {
    std::vector<int> v;
    ListNode *p = head;
    while (p != nullptr) {
        v.push_back(p->val);
        p = p->next;
    }
    return v;
}

int main() {
    {
        ListNode *head = toList({18, 6, 10, 3});
        std::vector<int> expected{18, 6, 6, 2, 10, 1, 3};
        auto *ret = insertGreatestCommonDivisors(head);
        assert(expected == toVector(ret));
        delete ret;
    }
    {
        ListNode *head = toList({7});
        std::vector<int> expected{7};
        auto *ret = insertGreatestCommonDivisors(head);
        assert(expected == toVector(ret));
        delete ret;
    }
    return 0;
}