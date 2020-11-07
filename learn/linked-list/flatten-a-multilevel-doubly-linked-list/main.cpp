#include <cassert>
#include <vector>
#include <cstdio>

class Node {
  public:
    int val;
    Node *prev;
    Node *next;
    Node *child;

    Node(int v) : val(v), prev(nullptr), next(nullptr), child(nullptr) {
    }
};

Node *flatten(Node *head) {
    Node *p = head;
    Node *q = head;

    std::vector<Node *> parents;
    while (true) {
        if (parents.empty() && p == nullptr) {
            break;
        }

        if (p != nullptr && p->child != nullptr) {
            Node *tmp = p;
            parents.push_back(p->next);
            p = p->child;
            q->next = p;
            q->child = nullptr;
            q = q->next;
            q->prev = tmp;
            continue;
        }

        if ((p == nullptr || p->next == nullptr) && !parents.empty()) {
            Node *tmp = p;
            Node *parent = parents.back();
            parents.pop_back();
            p = parent;
            q->next = p;

            if (p != nullptr) {
                q = q->next;
                q->prev = tmp;
            }
            continue;
        }

        p = p->next;
        q = p;
    }

    return head;
}

int main() {
    {
        Node *one = new Node(1);
        Node *two = new Node(2);
        Node *three = new Node(3);
        Node *four = new Node(4);
        Node *five = new Node(5);
        Node *six = new Node(6);
        Node *seven = new Node(7);
        Node *eight = new Node(8);
        Node *nine = new Node(9);
        Node *ten = new Node(10);
        Node *eleven = new Node(11);
        Node *twelve = new Node(12);

        one->next = two;
        two->prev = one;
        two->next = three;
        three->prev = two;
        three->next = four;
        four->prev = three;
        four->next = five;
        five->prev = four;
        five->next = six;
        six->prev = five;

        three->child = seven;
        seven->next = eight;
        eight->prev = seven;
        eight->next = nine;
        nine->prev = eight;
        nine->next = ten;
        ten->prev = nine;

        eight->child = eleven;
        eleven->next = twelve;
        twelve->prev = eleven;

        auto ret = flatten(one);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next->val == 7);
        assert(ret->next->next->next->next->val == 8);
        assert(ret->next->next->next->next->next->val == 11);
        assert(ret->next->next->next->next->next->next->val == 12);
        assert(ret->next->next->next->next->next->next->next->val == 9);
        assert(ret->next->next->next->next->next->next->next->next->val == 10);
        assert(ret->next->next->next->next->next->next->next->next->next->val == 4);
        assert(ret->next->next->next->next->next->next->next->next->next->next->val == 5);
        assert(ret->next->next->next->next->next->next->next->next->next->next->next->val == 6);
        assert(ret->next->next->next->next->next->next->next->next->next->next->next->next == nullptr);

        assert(one->next == two);
        assert(two->prev == one);
        assert(two->next == three);
        assert(three->prev == two);
        assert(three->next == seven);
        assert(seven->prev == three);
        assert(seven->next == eight);
        assert(eight->prev == seven);
        assert(eight->next == eleven);
        assert(eleven->prev == eight);
        assert(eleven->next == twelve);
        assert(twelve->prev == eleven);
        assert(twelve->next == nine);
        assert(nine->prev == twelve);
        assert(nine->next == ten);
        assert(ten->prev == nine);
        assert(ten->next == four);
        assert(four->prev == ten);
        assert(four->next == five);
        assert(five->prev == four);
        assert(five->next == six);
        assert(six->prev == five);
        assert(six->next == nullptr);
    }
    {
        Node *one = new Node(1);
        Node *two = new Node(2);
        Node *three = new Node(3);

        one->child = two;
        two->child = three;

        auto ret = flatten(one);
        assert(ret->val == 1);
        assert(ret->next->val == 2);
        assert(ret->next->next->val == 3);
        assert(ret->next->next->next == nullptr);
    }
    return 0;
}
