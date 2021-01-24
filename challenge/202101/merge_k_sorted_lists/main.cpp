#include <cassert>
#include <vector>
#include <climits>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    const auto check = [](const std::vector<ListNode *> &v) {
        for (const auto *a : v) {
            if (a != nullptr) {
                return true;
            }
        }

        return false;
    };

    std::vector<ListNode *> ps;
    for (auto *list : lists) {
        if (list != nullptr) {
            ps.push_back(list);
        }
    }

    ListNode *head = nullptr;
    ListNode **pp = &head;
    while (check(ps)) {
        int min = INT_MAX;
        size_t idx = 0;
        for (size_t i = 0; i < ps.size(); ++i) {
            if (ps[i] != nullptr && min > ps[i]->val) {
                min = ps[i]->val;
                idx = i;
            }
        }

        *pp = ps[idx];
        pp = &(ps[idx]->next);
        ps[idx] = ps[idx]->next;
    }

    return head;
}

int main() {
    {
        ListNode *r1 = new ListNode(1);
        r1->next = new ListNode(4);
        r1->next->next = new ListNode(5);

        ListNode *r2 = new ListNode(1);
        r2->next = new ListNode(3);
        r2->next->next = new ListNode(4);

        ListNode *r3 = new ListNode(2);
        r3->next = new ListNode(6);

        std::vector<ListNode *> input{r1, r2, r3};
        auto ret = mergeKLists(input);
        assert(ret->val == 1);
        assert(ret->next->val == 1);
        assert(ret->next->next->val == 2);
        assert(ret->next->next->next->val == 3);
        assert(ret->next->next->next->next->val == 4);
        assert(ret->next->next->next->next->next->val == 4);
        assert(ret->next->next->next->next->next->next->val == 5);
        assert(ret->next->next->next->next->next->next->next->val == 6);
        assert(ret->next->next->next->next->next->next->next->next == nullptr);

        delete ret;
    }
    {
        std::vector<ListNode *> input{};
        auto ret = mergeKLists(input);
        assert(ret == nullptr);
    }
    {
        std::vector<ListNode *> input{nullptr};
        auto ret = mergeKLists(input);
        assert(ret == nullptr);
    }
    return 0;
}
