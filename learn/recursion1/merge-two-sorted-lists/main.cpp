#include <cassert>
#include <functional>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    std::function<ListNode *(ListNode * l1, ListNode * l2)> f;
    f = [&f](ListNode *l1, ListNode *l2) -> ListNode * {
        if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }

        if (l1->val < l2->val) {
            l1->next = f(l1->next, l2);
            return l1;
        } else {
            l2->next = f(l1, l2->next);
            return l2;
        }
    };

    return f(l1, l2);
}

int main() {
    {
        ListNode *l1 = new ListNode(1);
        l1->next = new ListNode(2);
        l1->next->next = new ListNode(4);

        ListNode *l2 = new ListNode(1);
        l2->next = new ListNode(3);
        l2->next->next = new ListNode(4);

        auto ret = mergeTwoLists(l1, l2);
        assert(ret->val == 1);
        assert(ret->next->val == 1);
        assert(ret->next->next->val == 2);
        assert(ret->next->next->next->val == 3);
        assert(ret->next->next->next->next->val == 4);
        assert(ret->next->next->next->next->next->val == 4);
        assert(ret->next->next->next->next->next->next == nullptr);
    }
    return 0;
}
