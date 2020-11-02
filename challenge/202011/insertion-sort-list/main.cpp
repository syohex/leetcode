#include <cassert>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode *insertionSortList(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode *current_head = nullptr;
    ListNode *p = head;
    while (p != nullptr) {
        ListNode *next = p->next;
        if (current_head == nullptr) {
            current_head = p;
            p->next = nullptr;
        } else {
            ListNode *q = current_head;
            ListNode *prev = nullptr;

            while (q != nullptr) {
                if (p->val < q->val) {
                    if (prev == nullptr) {
                        p->next = current_head;
                        current_head = p;
                    } else {
                        prev->next = p;
                        p->next = q;
                    }
                    break;
                }

                prev = q;
                q = q->next;
            }

            if (q == nullptr) {
                p->next = prev->next;
                prev->next = p;
            }
        }

        p = next;
    }

    return current_head;
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
    }
    return 0;
}
