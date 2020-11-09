#include <cassert>
#include <cstdio>

class Node {
  public:
    int val;
    Node *next;

    Node(int _val) : val(_val), next(nullptr) {
    }
};

Node *insert(Node *head, int insertVal) {
    if (head == nullptr) {
        auto ret = new Node(insertVal);
        ret->next = ret;
        return ret;
    }

    if (head->next == head) {
        head->next = new Node(insertVal);
        head->next->next = head;
        return head;
    }

    Node *p = head->next;
    Node *prev = head;
    do {
        if (prev->val <= insertVal && insertVal <= p->val) {
            prev->next = new Node(insertVal);
            prev->next->next = p;
            return head;
        }

        if (prev->val > p->val) {
            if (insertVal >= prev->val || insertVal <= p->val) {
                prev->next = new Node(insertVal);
                prev->next->next = p;
                return head;
            }
        }

        prev = p;
        p = p->next;
    } while (prev != head);

    prev->next = new Node(insertVal);
    prev->next->next = p;
    return head;
}

int main() {
    {
        Node *r = new Node(3);
        r->next = new Node(4);
        r->next->next = new Node(1);
        r->next->next->next = r;

        auto ret = insert(r, 2);
        assert(ret->val == 3);
        assert(ret->next->val == 4);
        assert(ret->next->next->val == 1);
        assert(ret->next->next->next->val == 2);
        assert(ret->next->next->next->next == ret);
    }
    {
        Node *r = new Node(3);
        r->next = new Node(3);
        r->next->next = new Node(3);
        r->next->next->next = r;

        auto ret = insert(r, 0);
        assert(ret->val == 3);
        assert(ret->next->val == 0);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 3);
        assert(ret->next->next->next->next == ret);
    }
    {
        auto ret = insert(nullptr, 1);
        assert(ret->val == 1);
        assert(ret->next == ret);
    }
    {
        Node *r = new Node(1);
        r->next = r;
        auto ret = insert(r, 0);
        assert(ret->val == 1);
        assert(ret->next->val == 0);
        assert(ret->next->next == ret);
    }
    return 0;
}
