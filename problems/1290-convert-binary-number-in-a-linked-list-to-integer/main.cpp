#include <cassert>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
    ~ListNode() {
        delete next;
    }
};

int getDecimalNumber(ListNode *head) {
    int ret = 0;
    auto *p = head;
    while (true) {
        ret += p->val;
        p = p->next;
        if (p == nullptr) {
            break;
        }

        ret <<= 1;
    }

    return ret;
}

int main() {
    {
        ListNode input(1, new ListNode(0, new ListNode(1)));
        int ret = getDecimalNumber(&input);
        assert(ret == 5);
    }
    {
        ListNode input(1, new ListNode(1, new ListNode(1)));
        int ret = getDecimalNumber(&input);
        assert(ret == 7);
    }
    {
        ListNode input(1, new ListNode(0, new ListNode(1, new ListNode(1))));
        int ret = getDecimalNumber(&input);
        assert(ret == 11);
    }
    {
        ListNode input(
            1,
            new ListNode(
                0,
                new ListNode(
                    0, new ListNode(
                           1, new ListNode(
                                  0, new ListNode(
                                         0, new ListNode(
                                                1, new ListNode(
                                                       1, new ListNode(
                                                              1, new ListNode(
                                                                     0, new ListNode(
                                                                            0, new ListNode(
                                                                                   0, new ListNode(
                                                                                          0, new ListNode(
                                                                                                 0, new ListNode(0)))))))))))))));
        int ret = getDecimalNumber(&input);
        assert(ret == 18880);
    }
    {
        ListNode input(0);
        int ret = getDecimalNumber(&input);
        assert(ret == 0);
    }
    {
        ListNode input(1);
        int ret = getDecimalNumber(&input);
        assert(ret == 1);
    }
    {
        ListNode input(0, new ListNode(0));
        int ret = getDecimalNumber(&input);
        assert(ret == 0);
    }
    return 0;
}
