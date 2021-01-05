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

ListNode *deleteDuplicates(ListNode *head) {
    ListNode *p = head;
    ListNode *prev = nullptr;
    while (p != nullptr) {
        int val = p->val;
        if (p->next != nullptr && p->next->val == val) {
            while (p != nullptr) {
                if (val != p->val) {
                    break;
                }

                ListNode *tmp = p->next;
                p->next = nullptr;
                delete p;
                p = tmp;
            }

            if (prev == nullptr) {
                head = p;
            } else {
                prev->next = p;
            }

            continue;
        }

        prev = p;
        p = p->next;
    }

    return head;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(3);
        r->next->next->next->next = new ListNode(4);
        r->next->next->next->next->next = new ListNode(4);
        r->next->next->next->next->next->next = new ListNode(5);

        auto ret = deleteDuplicates(r);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 5);
        assert(ret->next->next->next == nullptr);

        delete ret;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(1);
        r->next->next = new ListNode(1);
        r->next->next->next = new ListNode(2);
        r->next->next->next->next = new ListNode(3);

        auto ret = deleteDuplicates(r);
        assert(ret->val == 2);
        assert(ret->next->val == 3);
        assert(ret->next->next == nullptr);

        delete ret;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(1);
        r->next->next = new ListNode(1);

        auto ret = deleteDuplicates(r);
        assert(ret == nullptr);
    }
    {
        ListNode *r = new ListNode(9);
        r->next = new ListNode(1);
        r->next->next = new ListNode(1);

        auto ret = deleteDuplicates(r);
        assert(ret->val == 9);
        assert(ret->next == nullptr);
        delete ret;
    }
    return 0;
}
