#include <cassert>
#include <memory>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode *next) : val(x), next(next) {
    }

    bool Equal(const ListNode *l2) {
        if (l2 == nullptr) {
            return false;
        }

        if (val != l2->val) {
            return false;
        }

        if (next == nullptr && l2->next == nullptr) {
            return true;
        }
        if (next == nullptr || l2->next == nullptr) {
            return false;
        }

        return next->Equal(l2->next);
    }

    void Print() const {
        const ListNode *node = this;
        while (true) {
            printf("%d ", node->val);
            node = node->next;
            if (node == nullptr) {
                printf(" -> nullptr\n");
                break;
            }

            printf(" -> ");
        }
    }
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr && l2 == nullptr) {
        return nullptr;
    }

    ListNode *ret = new ListNode();
    ListNode *p = ret;

    while (l1 != nullptr || l2 != nullptr) {
        if (l1 == nullptr) {
            p->val = l2->val;
            l2 = l2->next;
        } else if (l2 == nullptr) {
            p->val = l1->val;
            l1 = l1->next;
        } else {
            if (l1->val < l2->val) {
                p->val = l1->val;
                l1 = l1->next;
            } else {
                p->val = l2->val;
                l2 = l2->next;
            }
        }

        if (l1 != nullptr || l2 != nullptr) {
            p->next = new ListNode();
            p = p->next;
        }
    }

    return ret;
}

int main() {
    {
        std::unique_ptr<ListNode> l1(new ListNode(1));
        std::unique_ptr<ListNode> l2(new ListNode(2));
        ListNode *ret = mergeTwoLists(l1.get(), l2.get());

        std::unique_ptr<ListNode> expected(new ListNode(1, new ListNode(2)));
        assert(ret->Equal(expected.get()));
    }
    {
        std::unique_ptr<ListNode> l1(new ListNode(1, new ListNode(2, new ListNode(4))));
        std::unique_ptr<ListNode> l2(new ListNode(1, new ListNode(3, new ListNode(4))));
        ListNode *ret = mergeTwoLists(l1.get(), l2.get());

        std::unique_ptr<ListNode> expected(
            new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(4)))))));
        assert(ret->Equal(expected.get()));
    }
    return 0;
}