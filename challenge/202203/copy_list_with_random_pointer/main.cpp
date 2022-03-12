#include <cassert>
#include <map>
#include <vector>

class Node {
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) : val(_val), next(nullptr), random(nullptr) {
    }
    ~Node() {
        delete next;
    }
};

Node *copyRandomList(Node *head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node *p = head;
    Node *ret = nullptr;
    Node **q = &ret;

    std::map<Node *, int> table;
    std::vector<Node *> ret_nodes;
    int i = 0;
    while (p != nullptr) {
        *q = new Node(p->val);
        ret_nodes.push_back(*q);

        table[p] = i;

        p = p->next;
	q = &((*q)->next);
        ++i;
    }

    std::vector<int> randoms;
    p = head;
    while (p != nullptr) {
        if (p->random == nullptr) {
            randoms.push_back(-1);
        } else {
            randoms.push_back(table[p->random]);
        }
        p = p->next;
    }

    for (std::size_t i = 0; i < randoms.size(); ++i) {
        if (randoms[i] == -1) {
            ret_nodes[i]->random = nullptr;
        } else {
            ret_nodes[i]->random = ret_nodes[randoms[i]];
        }
    }

    return ret;
}

int main() {
    {
        Node *n1 = new Node(7);
        Node *n2 = new Node(13);
        Node *n3 = new Node(11);
        Node *n4 = new Node(10);
        Node *n5 = new Node(1);

        n1->next = n2;
        n2->next = n3;
        n3->next = n4;
        n4->next = n5;

        n1->random = nullptr;
        n2->random = n1;
        n3->random = n5;
        n4->random = n3;
        n5->random = n1;

        auto ret = copyRandomList(n1);
        auto r1 = ret;
        auto r2 = ret->next;
        auto r3 = ret->next->next;
        auto r4 = ret->next->next->next;
        auto r5 = ret->next->next->next->next;

        assert(r1 != n1 && r1->val == 7 && r1->random == nullptr);
        assert(r2 != n2 && r2->val == 13 && r2->random == r1);
        assert(r3 != n3 && r3->val == 11 && r3->random == r5);
        assert(r4 != n4 && r4->val == 10 && r4->random == r3);
        assert(r5 != n5 && r5->val == 1 && r5->random == r1);
        assert(r5->next == nullptr);

	delete n1;
	delete r1;
    }
    {
        Node *n1 = new Node(1);
        Node *n2 = new Node(2);

        n1->next = n2;

        n1->random = n2;
        n2->random = n2;

        auto ret = copyRandomList(n1);
        auto r1 = ret;
        auto r2 = ret->next;

        assert(r1 != n1 && r1->val == 1 && r1->random == r2);
        assert(r2 != n2 && r2->val == 2 && r2->random == r2);
        assert(r2->next == nullptr);

	delete n1;
	delete r1;
    }
    {
        Node *n1 = new Node(3);
        Node *n2 = new Node(3);
        Node *n3 = new Node(3);

        n1->next = n2;
        n2->next = n3;

        n1->random = nullptr;
        n2->random = n1;
        n3->random = nullptr;

        auto ret = copyRandomList(n1);
        auto r1 = ret;
        auto r2 = ret->next;
        auto r3 = ret->next->next;

        assert(r1 != n1 && r1->val == 3 && r1->random == nullptr);
        assert(r2 != n2 && r2->val == 3 && r2->random == r1);
        assert(r3 != n3 && r3->val == 3 && r3->random == nullptr);
        assert(r3->next == nullptr);

	delete n1;
	delete r1;
    }
    return 0;
}
