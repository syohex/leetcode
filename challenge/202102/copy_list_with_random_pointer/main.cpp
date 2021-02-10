#include <cassert>
#include <vector>
#include <map>

class Node {
  public:
    int val;
    Node *next;
    Node *random;

    explicit Node(int val) : val(val), next(nullptr), random(nullptr) {
    }

    ~Node() {
        delete next;
    }
};

Node *copyRandomList(Node *head) {
    if (head == nullptr) {
        return nullptr;
    }

    std::vector<Node *> nodes;
    std::map<Node *, size_t> index_map;
    Node *p = head;
    size_t pos = 0;
    while (p != nullptr) {
        index_map[p] = pos;
        nodes.push_back(new Node(p->val));

        p = p->next;
        ++pos;
    }
    for (size_t i = 0; i < pos - 1; ++i) {
        nodes[i]->next = nodes[i + 1];
    }

    p = head;
    pos = 0;
    while (p != nullptr) {
        if (index_map.find(p->random) != index_map.end()) {
            size_t index = index_map[p->random];
            nodes[pos]->random = nodes[index];
        }

        p = p->next;
        ++pos;
    }

    return nodes[0];
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

        n2->random = n1;
        n3->random = n5;
        n4->random = n3;
        n5->random = n1;

        auto ret = copyRandomList(n1);
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

        delete n1;
        delete ret;
    }
    {
        Node *n1 = new Node(1);
        Node *n2 = new Node(2);

        n1->next = n2;

        n1->random = n2;
        n2->random = n2;

        auto ret = copyRandomList(n1);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next == nullptr);

        assert(ret->random == ret->next);
        assert(ret->next->random == ret->next);

        delete n1;
        delete ret;
    }
    {
        Node *n1 = new Node(3);
        Node *n2 = new Node(3);
        Node *n3 = new Node(3);

        n1->next = n2;
        n2->next = n3;

        n2->random = n1;

        auto ret = copyRandomList(n1);
        assert(ret->val == 3);
        assert(ret->next->val == 3);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next == nullptr);

        assert(ret->random == nullptr);
        assert(ret->next->random == ret);
        assert(ret->next->next->random == nullptr);

        delete n1;
        delete ret;
    }
    return 0;
}
