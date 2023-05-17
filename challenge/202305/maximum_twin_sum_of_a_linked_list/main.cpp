#include <cassert>
#include <algorithm>
#include <vector>

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
    std::vector<int> v;
    ListNode *p = head;

    while (p != nullptr) {
        v.push_back(p->val);
        p = p->next;
    }

    int ret = -1;
    int left = 0;
    int right = v.size() - 1;
    while (left < right) {
        ret = std::max(ret, v[left] + v[right]);
        ++left;
        --right;
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
