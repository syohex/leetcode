#include <cassert>
#include <cstdio>

class MyLinkedList {
  public:
    MyLinkedList() : val_(0), next_(nullptr) {
    }

    explicit MyLinkedList(int val, MyLinkedList *elem) : val_(val), next_(elem) {
    }

    int get(int index) {
        auto *pos = next_;
        for (int i = 0; i < index; ++i) {
            if (pos == nullptr) {
                return -1;
            }

            pos = pos->next_;
        }

        return pos != nullptr ? pos->val_ : -1;
    }

    void addAtHead(int val) {
        auto *elem = new MyLinkedList(val, next_);
        next_ = elem;
    }

    void addAtTail(int val) {
        auto *elem = new MyLinkedList(val, nullptr);
        auto *pos = next_;
        while (pos != nullptr) {
            if (pos->next_ == nullptr) {
                pos->next_ = elem;
                return;
            }

            pos = pos->next_;
        }

        next_ = elem;
    }

    void addAtIndex(int index, int val) {
        auto *pos = next_;
        MyLinkedList *prev = nullptr;
        for (int i = 0; i < index; ++i) {
            prev = pos;
            pos = pos->next_;
        }

        auto *elem = new MyLinkedList(val, pos);
        if (prev == nullptr) {
            next_ = elem;
        } else {
            prev->next_ = elem;
        }
    }

    void deleteAtIndex(int index) {
        auto *pos = next_;
        MyLinkedList *prev = nullptr;
        for (int i = 0; i < index; ++i) {
            if (pos == nullptr) {
                return;
            }
            prev = pos;
            pos = pos->next_;
        }

        if (prev == nullptr) {
            next_ = pos->next_;
        } else {
            if (prev->next_ != nullptr) {
                prev->next_ = pos->next_;
            }
        }
        delete pos;
    }

    int val_;
    MyLinkedList *next_;
};

int main() {
    {
        auto *list = new MyLinkedList();
        list->addAtHead(1);
        list->addAtTail(3);
        list->addAtIndex(1, 2);
        assert(list->get(1) == 2);
        list->deleteAtIndex(1);
        assert(list->get(1) == 3);

        delete list;
    }
    {
        auto *list = new MyLinkedList();
        list->addAtHead(1);
        list->deleteAtIndex(0);
        assert(list->get(0) == -1);

        delete list;
    }
    {
        auto *list = new MyLinkedList();
        list->addAtHead(1);
        list->addAtTail(3);
        list->addAtIndex(1, 2);
        assert(list->get(1) == 2);
        list->deleteAtIndex(0);
        assert(list->get(0) == 2);
        delete list;
    }
    {
        auto *list = new MyLinkedList();
        list->addAtIndex(0, 10);
        list->addAtIndex(0, 20);
        list->addAtIndex(1, 30);
        assert(list->get(0) == 20);
        delete list;
    }
    {
        auto *list = new MyLinkedList();
        list->addAtHead(2);
        list->deleteAtIndex(1);
        list->addAtHead(2);
        list->addAtHead(7);
        list->addAtHead(3);
        list->addAtHead(2);
        list->addAtHead(5);
        list->addAtTail(5);
        assert(list->get(5) == 2);
        list->deleteAtIndex(6);
        list->deleteAtIndex(4);
        delete list;
    }
    return 0;
}
