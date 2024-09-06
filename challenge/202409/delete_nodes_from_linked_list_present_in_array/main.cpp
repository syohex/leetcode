#include <cassert>
#include <vector>
#include <set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

ListNode *modifiedList(const std::vector<int> &nums, ListNode *head) {
    std::set<int> s(nums.begin(), nums.end());

    ListNode *prev = nullptr;
    ListNode *p = head;
    while (p != nullptr) {
        if (!s.contains(p->val)) {
            if (prev == nullptr) {
                head = p;
            }

            if (prev != nullptr) {
                prev->next = p;
            }

            prev = p;
        }

        p = p->next;
    }

    if (prev == nullptr) {
        return nullptr;
    }

    prev->next = nullptr;
    return head;
}

int main() {
    {
        std::vector<int> nums{1, 2, 3};
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);
        r->next->next->next->next = new ListNode(5);

        auto *ret = modifiedList(nums, r);
        assert(ret->val == 4);
        assert(ret->next->val == 5);
        assert(ret->next->next == nullptr);
    }
    {
        std::vector<int> nums{1};
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(1);
        r->next->next->next = new ListNode(2);
        r->next->next->next->next = new ListNode(1);
        r->next->next->next->next->next = new ListNode(2);

        auto *ret = modifiedList(nums, r);
        assert(ret->val == 2);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 2);
        assert(ret->next->next->next == nullptr);
    }
    {
        std::vector<int> nums{5};
        ListNode *r = new ListNode(1);
        r->next = new ListNode(2);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(4);

        auto *ret = modifiedList(nums, r);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 4);
        assert(ret->next->next->next->next == nullptr);
    }
    {
        std::vector<int> nums{1};
        ListNode *r = new ListNode(1);
        r->next = new ListNode(1);
        r->next->next = new ListNode(1);
        r->next->next->next = new ListNode(1);

        auto *ret = modifiedList(nums, r);
        assert(ret == nullptr);
    }
    {
        std::vector<int> nums{9, 2, 5};
        ListNode *r = new ListNode(2);
        r->next = new ListNode(10);
        r->next->next = new ListNode(9);

        auto *ret = modifiedList(nums, r);
        assert(ret->val == 10);
        assert(ret->next == nullptr);
    }
    return 0;
}