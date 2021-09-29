#include <cassert>
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

std::vector<ListNode *> splitListToParts(ListNode *head, int k) {
    std::vector<ListNode *> ret;
    int len = 0;
    ListNode *p = head;
    while (p != nullptr) {
        p = p->next;
        ++len;
    }

    int num = len / k;
    int mod = len % k;
    std::vector<int> nums(k, num);
    for (int i = 0; i < mod; ++i) {
        ++nums[i];
    }

    ListNode *prev = nullptr;
    p = head;
    for (int i = 0; i < k; ++i) {
        ListNode *start = p;
        for (int j = 0; j < nums[i]; ++j) {
            prev = p;
            p = p->next;
        }

        if (prev != nullptr) {
            prev->next = nullptr;
        }

        ret.push_back(start);
    }

    return ret;
}

int main() {
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);

        auto ret = splitListToParts(r, 5);
        assert(ret.size() == 5);
        assert(ret[0]->val == 1);
        assert(ret[0]->next == nullptr);
        assert(ret[1]->val == 2);
        assert(ret[1]->next == nullptr);
        assert(ret[2]->val == 3);
        assert(ret[2]->next == nullptr);
        assert(ret[3] == nullptr);
        assert(ret[4] == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);
        r->next->next->next->next->next = new ListNode(6);
        r->next->next->next->next->next->next = new ListNode(7);
        r->next->next->next->next->next->next->next = new ListNode(8);
        r->next->next->next->next->next->next->next->next = new ListNode(9);
        r->next->next->next->next->next->next->next->next->next = new ListNode(10);

        auto ret = splitListToParts(r, 3);
        assert(ret.size() == 3);
        assert(ret[0]->val == 1);
        assert(ret[0]->next->val == 2);
        assert(ret[0]->next->next->val == 3);
        assert(ret[0]->next->next->next->val == 4);
        assert(ret[0]->next->next->next->next == nullptr);
        assert(ret[1]->val == 5);
        assert(ret[1]->next->val == 6);
        assert(ret[1]->next->next->val == 7);
        assert(ret[1]->next->next->next == nullptr);
        assert(ret[2]->val == 8);
        assert(ret[2]->next->val == 9);
        assert(ret[2]->next->next->val == 10);
        assert(ret[2]->next->next->next == nullptr);
    }
    {
        auto ret = splitListToParts(nullptr, 3);
        assert(ret.size() == 3);
        assert(ret[0] == nullptr);
        assert(ret[1] == nullptr);
        assert(ret[2] == nullptr);
    }
    return 0;
}