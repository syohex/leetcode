#include <cassert>
#include <vector>
#include <map>
#include <cstdio>

class Node {
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) : val(_val), next(nullptr), random(nullptr) {
    }
};

Node *copyRandomList(Node *head) {
    Node *ret = nullptr;
    Node **pp = &ret;
    std::map<Node *, int> m;
    Node *p = head;
    int i = 0;
    while (p != nullptr) {
        *pp = new Node(p->val);
        m[p] = i++;
        p = p->next;

        pp = &((*pp)->next);
    }

    std::vector<int> vi;
    std::vector<Node *> vn;
    p = head;
    Node *q = ret;
    while (p != nullptr) {
        if (p->random == nullptr) {
            vi.push_back(-1);
        } else {
            vi.push_back(m[p->random]);
        }
        vn.push_back(q);
        p = p->next;
        q = q->next;
    }

    p = ret;
    i = 0;
    while (p != nullptr) {
        if (vi[i] == -1) {
            p->random = nullptr;
        } else {
            p->random = vn[vi[i]];
        }
        ++i;
        p = p->next;
    }

    return ret;
}

int main() {
    {
        Node *r = new Node(7);
        r->next = new Node(13);
        r->next->next = new Node(11);
        r->next->next->next = new Node(10);
        r->next->next->next->next = new Node(1);

        r->random = nullptr;
        r->next->random = r;
        r->next->next->random = r->next->next->next->next;
        r->next->next->next->random = r->next->next;
        r->next->next->next->next->random = r;

        auto ret = copyRandomList(r);
        assert(ret->val == 7);
        assert(ret->next->val == 13);
        assert(ret->next->next->val == 11);
        assert(ret->next->next->next->val == 10);
        assert(ret->next->next->next->next->val == 1);
        assert(ret->next->next->next->next->next == nullptr);

        assert(ret->random == nullptr);
        assert(ret->next->random == ret);
        assert(ret->next->next->random == ret->next->next->next->next);
        assert(ret->next->next->next->random == ret->next->next);
        assert(ret->next->next->next->next->random == ret);
    }
    return 0;
}
