#include <cassert>
#include <vector>

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
};

ListNode *middleNode(ListNode *head) {
    std::vector<ListNode *> v;
    for (ListNode *p = head; p != nullptr; p = p->next) {
        v.push_back(p);
    }

    return v[v.size() / 2];
}

int main() {
    {
        ListNode *list = new ListNode(1);
        list->next = new ListNode(2);
        list->next->next = new ListNode(3);
        list->next->next->next = new ListNode(4);
        list->next->next->next->next = new ListNode(5);
        auto ret = middleNode(list);
        assert(ret->val == 3);
        delete list;
    }
    {
        ListNode *list = new ListNode(1);
        list->next = new ListNode(2);
        list->next->next = new ListNode(3);
        list->next->next->next = new ListNode(4);
        list->next->next->next->next = new ListNode(5);
        list->next->next->next->next->next = new ListNode(6);
        auto ret = middleNode(list);
        assert(ret->val == 4);
        delete list;
    }
    return 0;
}
