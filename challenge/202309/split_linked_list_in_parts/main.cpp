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

    void Print() const {
        const ListNode *p = this;
        printf("[");
        while (p != nullptr) {
            printf(" %d ", p->val);
            p = p->next;
        }
        printf("]\n");
    }
};

std::vector<ListNode *> splitListToParts(ListNode *head, int k) {
    std::vector<ListNode *> ret;

    ListNode *p = head;
    int len = 0;
    while (p != nullptr) {
        ++len;
        p = p->next;
    }

    int n = len / k;
    int m = (len % k == 0) ? 0 : (len % k);
    int nulls = (len < k) ? k - len : 0;

    p = head;
    ListNode *q = head;
    int count = 1;
    while (p != nullptr) {
        ListNode *tmp = p->next;
        if (m > 0) {
            if (count == n + 1) {
                p->next = nullptr;
                ret.push_back(q);

                q = tmp;
                --m;
                count = 0;
            }
        } else {
            if (count == n) {
                p->next = nullptr;
                ret.push_back(q);

                q = tmp;
                count = 0;
            }
        }

        p = tmp;
        ++count;
    }

    for (int i = 0; i < nulls; ++i) {
        ret.push_back(nullptr);
    }

    return ret;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);

        auto ret = splitListToParts(r, 5);
        assert(ret.size() == 5);

        assert(ret[0]->val == 1);
        assert(ret[0]->next == nullptr);
        assert(ret[1]->val == 2);
        assert(ret[1]->next == nullptr);
        assert(ret[2]->val == 3);
        assert(ret[2]->next == nullptr);
        assert(ret[3] == nullptr);
        assert(ret[4] == nullptr);

        for (auto *p : ret) {
            delete p;
        }
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);
        r->next->next->next->next->next = new ListNode(6);
        r->next->next->next->next->next->next = new ListNode(7);
        r->next->next->next->next->next->next->next = new ListNode(8);
        r->next->next->next->next->next->next->next->next = new ListNode(9);
        r->next->next->next->next->next->next->next->next->next = new ListNode(10);

        auto ret = splitListToParts(r, 3);
        assert(ret.size() == 3);

        assert(ret[0]->val == 1);
        assert(ret[0]->next->val == 2);
        assert(ret[0]->next->next->val == 3);
        assert(ret[0]->next->next->next->val == 4);
        assert(ret[0]->next->next->next->next == nullptr);

        assert(ret[1]->val == 5);
        assert(ret[1]->next->val == 6);
        assert(ret[1]->next->next->val == 7);
        assert(ret[1]->next->next->next == nullptr);

        assert(ret[2]->val == 8);
        assert(ret[2]->next->val == 9);
        assert(ret[2]->next->next->val == 10);
        assert(ret[2]->next->next->next == nullptr);

        for (auto *p : ret) {
            delete p;
        }
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);

        auto ret = splitListToParts(r, 1);
        assert(ret.size() == 1);

        assert(ret[0]->val == 1);
        assert(ret[0]->next->val == 2);
        assert(ret[0]->next->next == nullptr);

        for (auto *p : ret) {
            delete p;
        }
    }
    {
        auto ret = splitListToParts(nullptr, 3);
        assert(ret.size() == 3);

        assert(ret[0] == nullptr);
        assert(ret[1] == nullptr);
        assert(ret[2] == nullptr);
    }
    return 0;
}
