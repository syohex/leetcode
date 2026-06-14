#include <cassert>
#include <deque>
#include <limits>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

int pairSum(ListNode *head) {
    deque<int> q;
    ListNode *p = head;
    while (p != nullptr) {
        q.push_back(p->val);
        p = p->next;
    }

    int ret = numeric_limits<int>::min();
    while (!q.empty()) {
        ret = max(ret, q.front() + q.back());
        q.pop_front();
        q.pop_back();
    }

    return ret;
}

int main() {
    {
        ListNode *r = new ListNode(5);
        r->next = new ListNode(4);
        r->next->next = new ListNode(2);
        r->next->next->next = new ListNode(1);
        int ret = pairSum(r);
        assert(ret == 6);
        delete r;
    }
    {
        ListNode *r = new ListNode(4);
        r->next = new ListNode(2);
        r->next->next = new ListNode(2);
        r->next->next->next = new ListNode(3);
        int ret = pairSum(r);
        assert(ret == 7);
        delete r;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(100000);
        int ret = pairSum(r);
        assert(ret == 100001);
        delete r;
    }
    return 0;
}
