#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

ListNode *removeElements(ListNode *head, int val) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode *prev = nullptr;
    ListNode *ret = head;
    ListNode *ptr = head;
    while (ptr != nullptr) {
        if (ptr->val == val) {
            ListNode *tmp = ptr;
            if (prev != nullptr) {
                prev->next = ptr->next;
            } else {
                ret = ptr->next;
            }
            ptr = ptr->next;
            tmp->next = nullptr;
            delete tmp;
        } else {
            prev = ptr;
            ptr = ptr->next;
        }
    }

    return ret;
}

int main() {
    {
        ListNode *list = new ListNode(1);
        list->next = new ListNode(2);
        list->next->next = new ListNode(6);
        list->next->next->next = new ListNode(3);
        list->next->next->next->next = new ListNode(4);
        list->next->next->next->next->next = new ListNode(5);
        list->next->next->next->next->next->next = new ListNode(6);

        auto ret = removeElements(list, 6);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 4);
        assert(ret->next->next->next->next->val == 5);
        assert(ret->next->next->next->next->next == nullptr);
        delete list;
    }
    {
        ListNode *list = new ListNode(1);
        list->next = new ListNode(2);

        auto ret = removeElements(list, 1);
        assert(ret->val == 2);
        assert(ret->next == nullptr);
        delete list;
    }
    {
        ListNode *list = new ListNode(1);
        list->next = new ListNode(1);
        list->next = new ListNode(1);

        auto ret = removeElements(list, 1);
        assert(ret == nullptr);
        delete list;
    }
    return 0;
}
