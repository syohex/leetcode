#include <cassert>
#include <vector>
#include <limits>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

std::vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    ListNode *p = head->next;
    ListNode *prev = head;

    int first_critical = 0;
    int prev_critical = 0;
    int i = 1;
    int min_distance = std::numeric_limits<int>::max();
    while (p->next != nullptr) {
        bool is_maxima = p->val > prev->val && p->val > p->next->val;
        bool is_minima = p->val < prev->val && p->val < p->next->val;

        if (is_maxima || is_minima) {
            if (first_critical == 0) {
                first_critical = i;
            } else {
                min_distance = std::min(min_distance, i - prev_critical);
            }

            prev_critical = i;
        }

        ++i;
        prev = p;
        p = p->next;
    }

    if (first_critical == prev_critical) {
        return {-1, -1};
    }

    return {min_distance, prev_critical - first_critical};
}

int main() {
    {
        ListNode *r = new ListNode(3);
        r->next = new ListNode(1);
        std::vector<int> expected{-1, -1};

        auto ret = nodesBetweenCriticalPoints(r);
        assert(ret == expected);

        delete r;
    }
    {
        ListNode *r = new ListNode(5);
        r->next = new ListNode(3);
        r->next->next = new ListNode(1);
        r->next->next->next = new ListNode(2);
        r->next->next->next->next = new ListNode(5);
        r->next->next->next->next->next = new ListNode(1);
        r->next->next->next->next->next->next = new ListNode(2);
        std::vector<int> expected{1, 3};

        auto ret = nodesBetweenCriticalPoints(r);
        assert(ret == expected);

        delete r;
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(3);
        r->next->next = new ListNode(2);
        r->next->next->next = new ListNode(2);
        r->next->next->next->next = new ListNode(3);
        r->next->next->next->next->next = new ListNode(2);
        r->next->next->next->next->next->next = new ListNode(2);
        r->next->next->next->next->next->next->next = new ListNode(7);
        std::vector<int> expected{3, 3};

        auto ret = nodesBetweenCriticalPoints(r);
        assert(ret == expected);

        delete r;
    }
    return 0;
}
