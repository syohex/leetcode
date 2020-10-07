#include <cassert>
#include <vector>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }

    void Print() {
        printf("[");
        auto pos = next;
        do {
            printf(" %d ", val);
            pos = pos->next;
        } while (pos == nullptr);
        printf("]\n");
    }
};

ListNode *rotateRight(ListNode *head, int k) {
    if (k == 0 || head == nullptr) {
        return head;
    }

    int size = 0;
    std::vector<ListNode *> v{head};
    ListNode *node = head;
    while (node != nullptr) {
        node = node->next;
        v.push_back(node);
        ++size;
    }

    k = k % size;

    ListNode *ret;
    ListNode **p = &ret;
    int pos = size - k;
    for (int i = 0; i < size; ++i, ++pos) {
        if (pos >= size) {
            pos %= size;
        }

        *p = new ListNode(v[pos]->val);
        p = &((*p)->next);
    }

    return ret;
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

        delete ret;
        delete r;
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

        delete ret;
        delete r;
    }
    return 0;
}
