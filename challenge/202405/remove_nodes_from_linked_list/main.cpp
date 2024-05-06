#include <cassert>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode *removeNodes(ListNode *head) {
    std::vector<ListNode*> stack;

    ListNode *p = head;
    while (p != nullptr) {
        while (!stack.empty()) {
            ListNode *q = stack.back();
            if (q->val >= p->val) {
                break;
            }

            stack.pop_back();
        }

        stack.push_back(p);
        p = p->next;
    }

    int len = stack.size();
    for (int i = 0; i < len - 1; ++i){
        stack[i]->next = stack[i + 1];
    }

    return stack[0];
}

int main(){
    {
        ListNode *r = new ListNode(5);
        r->next = new ListNode(2);
        r->next->next = new ListNode(13);
        r->next->next->next = new ListNode(3);
        r->next->next->next->next = new ListNode(8);

        ListNode *ret = removeNodes(r);
        assert(ret->val == 13);
        assert(ret->next->val == 8);
        assert(ret->next->next == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(1);
        r->next->next = new ListNode(1);
        r->next->next->next = new ListNode(1);

        ListNode *ret = removeNodes(r);
        assert(ret->val == 1);
        assert(ret->next->val == 1);
        assert(ret->next->next->val == 1);
        assert(ret->next->next->next->val == 1);
        assert(ret->next->next->next->next == nullptr);
    }
    return 0;
}
