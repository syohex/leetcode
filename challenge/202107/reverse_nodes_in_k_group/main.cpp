#include <cassert>
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

ListNode *reverseKGroup(ListNode *head, int k) {
    std::vector<ListNode *> v(k);
    ListNode *p = head;
    ListNode *ret = nullptr;
    ListNode *last = nullptr;
    while (p != nullptr) {
        int i = 0;
        while (p != nullptr && i < k) {
            v[i++] = p;
            p = p->next;
        }

        if (i != k) {
            break;
        }

        if (ret == nullptr) {
            ret = v[k - 1];
        }

        for (int j = k - 1; j >= 1; --j) {
            v[j]->next = v[j - 1];
        }

        if (last != nullptr) {
            last->next = v[k - 1];
        }

        last = v[0];
        last->next = p;
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
        auto ret = reverseKGroup(r, 2);
        assert(ret->val == 2);
        assert(ret->next->val == 1);
        assert(ret->next->next->val == 4);
        assert(ret->next->next->next->val == 3);
        assert(ret->next->next->next->next->val == 5);
        assert(ret->next->next->next->next->next == nullptr);
        delete r;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);
        auto ret = reverseKGroup(r, 3);
        assert(ret->val == 3);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 1);
        assert(ret->next->next->next->val == 4);
        assert(ret->next->next->next->next->val == 5);
        assert(ret->next->next->next->next->next == nullptr);
        delete r;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);
        auto ret = reverseKGroup(r, 1);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 4);
        assert(ret->next->next->next->next->val == 5);
        assert(ret->next->next->next->next->next == nullptr);
        delete r;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);
        auto ret = reverseKGroup(r, 5);
        assert(ret->val == 5);
        assert(ret->next->val == 4);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 2);
        assert(ret->next->next->next->next->val == 1);
        assert(ret->next->next->next->next->next == nullptr);
        delete r;
    }
    {
        ListNode *r = new ListNode(1);
        auto ret = reverseKGroup(r, 1);
        assert(ret->val == 1);
        assert(ret->next == nullptr);
        delete r;
    }
    return 0;
}