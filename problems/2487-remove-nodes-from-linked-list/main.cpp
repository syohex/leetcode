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
};

ListNode *removeNodes(ListNode *head) {
    std::vector<ListNode *> v;

    ListNode *p = head;
    while (p != nullptr) {
        while (!v.empty()) {
            ListNode *last = v.back();
            if (last->val >= p->val) {
                break;
            }

            last->next = nullptr;
            delete last;

            v.pop_back();
        }

        v.push_back(p);
        p = p->next;
    }

    int len = v.size();
    for (int i = 0; i < len - 1; ++i) {
        v[i]->next = v[i + 1];
    }

    return v[0];
}

int main() {
    {
        ListNode *r = new ListNode(5);
        r->next = new ListNode(2);
        r->next->next = new ListNode(13);
        r->next->next->next = new ListNode(3);
        r->next->next->next->next = new ListNode(8);

        auto ret = removeNodes(r);
        assert(ret->val == 13);
        assert(ret->next->val == 8);
        assert(ret->next->next == nullptr);

        delete ret;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(1);
        r->next->next = new ListNode(1);
        r->next->next->next = new ListNode(1);

        auto ret = removeNodes(r);
        assert(ret->val == 1);
        assert(ret->next->val == 1);
        assert(ret->next->next->val == 1);
        assert(ret->next->next->next->val == 1);
        assert(ret->next->next->next->next == nullptr);

        delete ret;
    }
    return 0;
}
