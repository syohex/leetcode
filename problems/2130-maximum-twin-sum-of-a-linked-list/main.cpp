#include <cassert>
#include <queue>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

int pairSum(ListNode *head) {
    std::deque<int> q;
    ListNode *p = head;
    while (p != nullptr) {
        q.push_back(p->val);
        p = p->next;
    }

    int ret = -1;
    while (!q.empty()) {
        int f = q.front();
        int b = q.back();

        q.pop_front();
        q.pop_back();

        ret = std::max(ret, f + b);
    }

    return ret;
}

int main() {
    {
        ListNode *r = new ListNode(5);
        r->next = new ListNode(4);
        r->next->next = new ListNode(2);
        r->next->next->next = new ListNode(1);

        assert(pairSum(r) == 6);

        delete r;
    }
    {
        ListNode *r = new ListNode(4);
        r->next = new ListNode(2);
        r->next->next = new ListNode(2);
        r->next->next->next = new ListNode(3);

        assert(pairSum(r) == 7);

        delete r;
    }
    return 0;
}