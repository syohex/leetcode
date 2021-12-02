#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode *oddEvenList(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *even_head = even;

    while (even != nullptr && even->next != nullptr) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = even_head;
    return head;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);
        auto ret = oddEvenList(r);
    }
    return 0;
}