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

ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode *prev = nullptr;
    ListNode *current = head;

    while (left > 1) {
        prev = current;
        current = current->next;
        --left;
        --right;
    }

    ListNode *before_reverse = prev;
    ListNode *reverse_end = current;

    while (right > 0) {
        ListNode *tmp = current->next;
        current->next = prev;
        prev = current;
        current = tmp;
        --right;
    }

    reverse_end->next = current;

    if (before_reverse == nullptr) {
        head = prev;
    } else {
        before_reverse->next = prev;
    }

    return head;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);

        auto *ret = reverseBetween(r, 2, 4);
        assert(r->val == 1);
        assert(r->next->val == 4);
        assert(r->next->next->val == 3);
        assert(r->next->next->next->val == 2);
        assert(r->next->next->next->next->val == 5);
        assert(r->next->next->next->next->next == nullptr);
        delete ret;
    }
    {
        ListNode *r = new ListNode(5);

        auto *ret = reverseBetween(r, 1, 1);
        assert(r->val == 5);
        assert(r->next == nullptr);
        delete ret;
    }
    return 0;
}
