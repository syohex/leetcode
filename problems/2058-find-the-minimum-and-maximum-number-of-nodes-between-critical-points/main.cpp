#include <cassert>
#include <vector>
#include <algorithm>

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
    std::vector<int> v;
    ListNode *p = head;
    while (p != nullptr) {
        v.push_back(p->val);
        p = p->next;
    }

    std::vector<int> points;
    int limit = v.size();
    for (int i = 1; i < limit - 1; ++i) {
        if (v[i - 1] > v[i] && v[i] < v[i + 1]) {
            points.push_back(i);
        } else if (v[i - 1] < v[i] && v[i] > v[i + 1]) {
            points.push_back(i);
        }
    }

    if (points.size() < 2) {
        return {-1, -1};
    }

    int min = 1'000'000;
    int max = points.back() - points.front();

    for (size_t i = 1; i < points.size(); ++i) {
        min = std::min(min, points[i] - points[i - 1]);
    }

    return {min, max};
}

int main() {
    {
        std::vector<int> expected{-1, -1};
        ListNode *r = new ListNode(3);
        r->next = new ListNode(1);
        auto ret = nodesBetweenCriticalPoints(r);
        assert(ret == expected);
        delete r;
    }
    {
        std::vector<int> expected{1, 3};
        ListNode *r = new ListNode(3);
        r->next = new ListNode(3);
        r->next->next = new ListNode(1);
        r->next->next->next = new ListNode(2);
        r->next->next->next->next = new ListNode(5);
        r->next->next->next->next->next = new ListNode(1);
        r->next->next->next->next->next->next = new ListNode(2);
        auto ret = nodesBetweenCriticalPoints(r);
        assert(ret == expected);
        delete r;
    }
    {
        std::vector<int> expected{3, 3};
        ListNode *r = new ListNode(1);
        r->next = new ListNode(3);
        r->next->next = new ListNode(2);
        r->next->next->next = new ListNode(2);
        r->next->next->next->next = new ListNode(3);
        r->next->next->next->next->next = new ListNode(2);
        r->next->next->next->next->next->next = new ListNode(2);
        r->next->next->next->next->next->next->next = new ListNode(2);
        r->next->next->next->next->next->next->next->next = new ListNode(7);
        auto ret = nodesBetweenCriticalPoints(r);
        assert(ret == expected);
        delete r;
    }
    {
        std::vector<int> expected{-1, -1};
        ListNode *r = new ListNode(2);
        r->next = new ListNode(3);
        r->next->next = new ListNode(3);
        r->next->next->next = new ListNode(2);
        auto ret = nodesBetweenCriticalPoints(r);
        assert(ret == expected);
        delete r;
    }
    return 0;
}
