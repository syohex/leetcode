#include <cassert>
#include <set>
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

ListNode *deleteDuplicates(ListNode *head) {
    ListNode *p = head;
    ListNode *prev = nullptr;
    std::set<int> s;
    while (p != nullptr) {
        if (s.find(p->val) != s.end()) {
            ListNode *tmp = p->next;
            p->next = nullptr;
            delete p;

            prev->next = tmp;
            p = tmp;
            continue;
        }

        s.insert(p->val);

        prev = p;
        p = p->next;
    }

    return head;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(1);
        r->next->next = new ListNode(2);

        auto ret = deleteDuplicates(r);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next == nullptr);

        delete r;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(1);
        r->next->next = new ListNode(2);
        r->next->next->next = new ListNode(3);
        r->next->next->next->next = new ListNode(3);

        auto ret = deleteDuplicates(r);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next == nullptr);

        delete r;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(1);
        r->next->next = new ListNode(1);
        r->next->next->next = new ListNode(1);
        r->next->next->next->next = new ListNode(1);

        auto ret = deleteDuplicates(r);
        assert(ret->val == 1);
        assert(ret->next == nullptr);
        delete r;
    }
    {
        auto ret = deleteDuplicates(nullptr);
        assert(ret == nullptr);
    }
    return 0;
}
