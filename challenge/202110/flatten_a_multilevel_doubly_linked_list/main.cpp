#include <cassert>
#include <functional>

class Node {
  public:
    int val;
    Node *prev;
    Node *next;
    Node *child;

    Node(int val) : val(val), prev(nullptr), next(nullptr), child(nullptr) {
    }
};

Node *flatten(Node *head) {
    if (head == nullptr) {
        return nullptr;
    }

    std::function<Node *(Node * prev, Node * current)> f;
    f = [&](Node *prev, Node *current) -> Node * {
        if (current == nullptr) {
            return prev;
        }

        current->prev = prev;
        prev->next = current;

        Node *tmp = current->next;
        Node *tail = f(current, current->child);
        current->child = nullptr;

        return f(tail, tmp);
    };

    Node *dummyPrev = new Node(0);
    dummyPrev->next = head;

    f(dummyPrev, head);
    head->prev = nullptr;
    return head;
}

int main() {
    {
        auto *ret = flatten(nullptr);
        assert(ret == nullptr);
    }
    {
        Node *n1 = new Node(1);
        Node *n2 = new Node(2);
        Node *n3 = new Node(3);

        n1->next = n2;
        n2->prev = n1;
        n1->child = n3;

        auto *ret = flatten(n1);
        assert(ret != nullptr);

        assert(n1->next == n3);
        assert(n3->next == n2);
        assert(n2->next == nullptr);
        assert(n2->prev == n3);
        assert(n3->prev == n1);
    }
    {
        Node *n1 = new Node(1);
        Node *n2 = new Node(2);
        Node *n3 = new Node(3);
        Node *n4 = new Node(4);
        Node *n5 = new Node(5);
        Node *n6 = new Node(6);
        Node *n7 = new Node(7);
        Node *n8 = new Node(8);
        Node *n9 = new Node(9);
        Node *n10 = new Node(10);
        Node *n11 = new Node(11);
        Node *n12 = new Node(12);

        n1->next = n2;
        n2->prev = n1;
        n2->next = n3;
        n3->prev = n2;
        n3->next = n4;
        n4->prev = n3;
        n4->next = n5;
        n5->prev = n4;
        n5->next = n6;
        n6->prev = n5;

        n3->child = n7;
        n7->next = n8;
        n8->prev = n7;
        n8->next = n9;
        n9->prev = n8;
        n9->next = n10;
        n10->prev = n9;

        n8->child = n11;
        n11->next = n12;
        n12->prev = n11;

        auto ret = flatten(n1);
        assert(ret != nullptr);

        assert(n1->next == n2);
        assert(n2->next == n3);
        assert(n3->next == n7);
        assert(n7->next == n8);
        assert(n8->next == n11);
        assert(n11->next == n12);
        assert(n12->next == n9);
        assert(n9->next == n10);
        assert(n10->next == n4);
        assert(n4->next == n5);
        assert(n5->next == n6);
        assert(n6->next == nullptr);

        assert(n1->prev == nullptr);
        assert(n2->prev == n1);
        assert(n3->prev == n2);
        assert(n7->prev == n3);
        assert(n8->prev == n7);
        assert(n11->prev == n8);
        assert(n12->prev == n11);
        assert(n9->prev == n12);
        assert(n10->prev == n9);
        assert(n4->prev == n10);
        assert(n5->prev == n4);
        assert(n6->prev == n5);
    }
    return 0;
}