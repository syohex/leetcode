#include <cassert>
#include <map>
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

ListNode *sortList(ListNode *head) {
    std::map<int, std::vector<ListNode *>> m;
    ListNode *p = head;
    while (p != nullptr) {
        m[p->val].push_back(p);
        p = p->next;
    }

    ListNode *ret = nullptr;
    ListNode *prev = nullptr;
    for (const auto &it : m) {
        for (ListNode *n : it.second) {
            if (ret == nullptr) {
                ret = n;
            }

            if (prev != nullptr) {
                prev->next = n;
            }

            prev = n;
        }
    }

    if (prev != nullptr) {
        prev->next = nullptr;
    }

    return ret;
}

int main() {
    {
        ListNode *r = new ListNode(4);
        r->next = new ListNode(2);
        r->next->next = new ListNode(1);
        r->next->next->next = new ListNode(3);

        auto ret = sortList(r);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 4);
        assert(ret->next->next->next->next == nullptr);

        delete ret;
    }
    {
        ListNode *r = new ListNode(-1);
        r->next = new ListNode(5);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(0);

        auto ret = sortList(r);
        assert(ret->val == -1);
        assert(ret->next->val == 0);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 4);
        assert(ret->next->next->next->next->val == 5);
        assert(ret->next->next->next->next->next == nullptr);

        delete ret;
    }
    {
        auto ret = sortList(nullptr);
        assert(ret == nullptr);
    }
    return 0;
}
