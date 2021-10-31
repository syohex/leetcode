#include <cassert>
#include <stack>

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

    Node *dummyPrev = new Node(0);
    dummyPrev->next = head;

    std::stack<Node *> stack;
    stack.push(head);

    Node *prev = dummyPrev;
    while (!stack.empty()) {
        Node *cur = stack.top();
        stack.pop();

        prev->next = cur;
        cur->prev = prev;

        if (cur->next != nullptr) {
            stack.push(cur->next);
        }
        if (cur->child != nullptr) {
            stack.push(cur->child);
            cur->child = nullptr;
        }

        prev = cur;
    }

    delete dummyPrev;
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
    return 0;
}