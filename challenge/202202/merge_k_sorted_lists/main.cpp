#include <cassert>
#include <vector>
#include <queue>

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
    const auto cmp = [](ListNode *a, ListNode *b) -> bool { return a->val > b->val; };
    std::priority_queue<ListNode *, std::vector<ListNode *>, decltype(cmp)> q(cmp);

    for (auto *list : lists) {
        ListNode *p = list;
        while (p != nullptr) {
            q.push(p);
            p = p->next;
        }
    }

    if (q.empty()) {
        return nullptr;
    }

    ListNode *ret = q.top();
    q.pop();

    ListNode *p = ret;
    while (!q.empty()) {
        ListNode *tmp = q.top();
        q.pop();

        p->next = tmp;
        p = tmp;
    }
    p->next = nullptr;

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
        auto ret = mergeKLists(lists);
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
        std::vector<ListNode *> lists{};
        auto ret = mergeKLists(lists);
        assert(ret == nullptr);
    }
    {
        std::vector<ListNode *> lists{nullptr};
        auto ret = mergeKLists(lists);
        assert(ret == nullptr);
    }
    {
        std::vector<ListNode *> lists{nullptr, nullptr};
        auto ret = mergeKLists(lists);
        assert(ret == nullptr);
    }
    {
        ListNode *r1 = new ListNode(-1);
        r1->next = new ListNode(-1);
        r1->next->next = new ListNode(-1);

        ListNode *r2 = new ListNode(-2);
        r2->next = new ListNode(-2);
        r2->next->next = new ListNode(-1);

        std::vector<ListNode *> lists{r1, r2};
        auto ret = mergeKLists(lists);
        assert(ret->val == -2);
        assert(ret->next->val == -2);
        assert(ret->next->next->val == -1);
        assert(ret->next->next->next->val == -1);
        assert(ret->next->next->next->next->val == -1);
        assert(ret->next->next->next->next->next->val == -1);
        assert(ret->next->next->next->next->next->next == nullptr);
        delete ret;
    }
    return 0;
}
