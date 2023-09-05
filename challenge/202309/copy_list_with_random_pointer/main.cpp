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

Node *copyRandomListNode(Node *head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node *p = head;
    Node *ret;
    Node **q = &ret;
    std::map<Node *, int> m1;
    std::vector<Node *> v{nullptr};
    int i = 1;
    while (p != nullptr) {
        m1[p] = i;
        ++i;

        *q = new Node(p->val);
        v.push_back(*q);

        q = &((*q)->next);
        p = p->next;
    }

    p = head;
    std::vector<int> indexes;
    while (p != nullptr) {
        if (p->random == nullptr) {
            indexes.push_back(0);
        } else {
            indexes.push_back(m1[p->random]);
        }
        p = p->next;
    }

    p = ret;
    i = 0;
    while (p != nullptr) {
        p->random = v[indexes[i]];
        p = p->next;
        ++i;
    }

    return ret;
}

int main() {
    {
        Node *r1 = new Node(7);
        Node *r2 = new Node(13);
        Node *r3 = new Node(11);
        Node *r4 = new Node(10);
        Node *r5 = new Node(1);

        r1->next = r2;
        r2->next = r3;
        r3->next = r4;
        r4->next = r5;

        r1->random = nullptr;
        r2->random = r1;
        r3->random = r5;
        r4->random = r3;
        r5->random = r1;

        auto *ret1 = copyRandomListNode(r1);
        auto *ret2 = ret1->next;
        auto *ret3 = ret2->next;
        auto *ret4 = ret3->next;
        auto *ret5 = ret4->next;

        assert(ret1->val == 7);
        assert(ret2->val == 13);
        assert(ret3->val == 11);
        assert(ret4->val == 10);
        assert(ret5->val == 1);
        assert(ret5->next == nullptr);

        assert(ret1->random == nullptr);
        assert(ret2->random == ret1);
        assert(ret3->random == ret5);
        assert(ret4->random == ret3);
        assert(ret5->random == ret1);

        delete r1;
        delete ret1;
    }
    {
        Node *r1 = new Node(1);
        Node *r2 = new Node(2);

        r1->next = r2;

        r1->random = r2;
        r2->random = r2;

        auto *ret1 = copyRandomListNode(r1);
        auto *ret2 = ret1->next;

        assert(ret1->val == 1);
        assert(ret2->val == 2);
        assert(ret2->next == nullptr);

        assert(ret1->random == ret2);
        assert(ret2->random == ret2);

        delete r1;
        delete ret1;
    }
    {
        Node *r1 = new Node(3);
        Node *r2 = new Node(3);
        Node *r3 = new Node(3);

        r1->next = r2;
        r2->next = r3;

        r1->random = nullptr;
        r2->random = r1;
        r3->random = nullptr;

        auto *ret1 = copyRandomListNode(r1);
        auto *ret2 = ret1->next;
        auto *ret3 = ret2->next;

        assert(ret1->val == 3);
        assert(ret2->val == 3);
        assert(ret3->val == 3);
        assert(ret3->next == nullptr);

        assert(ret1->random == nullptr);
        assert(ret2->random == ret1);
        assert(ret3->random == nullptr);

        delete r1;
        delete ret1;
    }

    return 0;
}
