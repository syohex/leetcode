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

ListNode *insertionSortList(ListNode *head) {
    ListNode *tmp_head = new ListNode(-1);
    ListNode *current = head;

    while (current != nullptr) {
        ListNode *prev = tmp_head;

        while (prev->next != nullptr && prev->next->val < current->val) {
            prev = prev->next;
        }

        ListNode *tmp_next = current->next;
        current->next = prev->next;
        prev->next = current;

        current = tmp_next;
    }

    ListNode *ret = tmp_head->next;
    tmp_head->next = nullptr;
    delete tmp_head;
    return ret;
}

int main() {
    {
        ListNode *r = new ListNode(4);
        r->next = new ListNode(2);
        r->next->next = new ListNode(1);
        r->next->next->next = new ListNode(3);

        auto ret = insertionSortList(r);
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

        auto ret = insertionSortList(r);
        assert(ret->val == -1);
        assert(ret->next->val == 0);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 4);
        assert(ret->next->next->next->next->val == 5);
        assert(ret->next->next->next->next->next == nullptr);

        delete ret;
    }
    return 0;
}