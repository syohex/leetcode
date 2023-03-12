#include <cassert>
#include <queue>
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

ListNode *mergeKLists(const std::vector<ListNode *> &lists) {
    const auto cmp = [](const ListNode *a, const ListNode *b) -> bool { return a->val > b->val; };

    std::priority_queue<ListNode *, std::vector<ListNode *>, decltype(cmp)> q(cmp);
    for (auto *r : lists) {
        ListNode *p = r;
        while (p != nullptr) {
            ListNode *next = p->next;
            p->next = nullptr;
            q.push(p);

            p = next;
        }
    }

    if (q.empty()) {
        return nullptr;
    }

    ListNode *ret = q.top();
    q.pop();

    ListNode *p = ret;
    while (!q.empty()) {
        p->next = q.top();
        q.pop();
        p = p->next;
    }

    return ret;
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

        std::vector<ListNode *> lists{r1, r2, r3};
        auto *ret = mergeKLists(lists);
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
        ListNode *r1 = new ListNode(-1);
        r1->next = new ListNode(-1);
        r1->next->next = new ListNode(-1);

        ListNode *r2 = new ListNode(-2);
        r2->next = new ListNode(-2);
        r2->next->next = new ListNode(-1);

        std::vector<ListNode *> lists{r1, r2};
        auto *ret = mergeKLists(lists);
        assert(ret->val == -2);
        assert(ret->next->val == -2);
        assert(ret->next->next->val == -1);
        assert(ret->next->next->next->val == -1);
        assert(ret->next->next->next->next->val == -1);
        assert(ret->next->next->next->next->next->val == -1);
        assert(ret->next->next->next->next->next->next == nullptr);

        delete ret;
    }
    {
        auto *ret = mergeKLists(std::vector<ListNode *>{});
        assert(ret == nullptr);
    }
    {
        auto *ret = mergeKLists(std::vector<ListNode *>{nullptr});
        assert(ret == nullptr);
    }
    return 0;
}
