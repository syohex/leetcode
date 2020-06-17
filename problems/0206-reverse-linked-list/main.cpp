#include <cassert>
#include <functional>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode *next) : val(x), next(next) {
    }

    ~ListNode() {
        delete next;
    }

    bool Equal(ListNode *a) {
        if (a == nullptr) {
            return false;
        }

        if (val != a->val) {
            return false;
        }

        if (next == nullptr && a->next != nullptr) {
            return false;
        }
        if (next == nullptr && a->next == nullptr) {
            return true;
        }

        return next->Equal(a->next);
    }
};

ListNode *reverseList(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }

    std::function<ListNode **(ListNode * node, ListNode * *r)> f;
    f = [&f](ListNode *node, ListNode **r) -> ListNode ** {
        if (node->next == nullptr) {
            (*r)->val = node->val;
            return &((*r)->next);
        }

        ListNode **next = f(node->next, r);
        *next = new ListNode(node->val);
        return &((*next)->next);
    };

    ListNode *ret = new ListNode(0);
    f(head, &ret);
    return ret;
}

int main() {
    {
        ListNode *list = new ListNode(1);
        list->next = new ListNode(2);
        list->next->next = new ListNode(3);
        list->next->next->next = new ListNode(4);
        list->next->next->next->next = new ListNode(5);

        auto ret = reverseList(list);
        ListNode *expected = new ListNode(5);
        expected->next = new ListNode(4);
        expected->next->next = new ListNode(3);
        expected->next->next->next = new ListNode(2);
        expected->next->next->next->next = new ListNode(1);

        assert(ret->Equal(expected));
        delete list;
        delete expected;
    }
    return 0;
}
