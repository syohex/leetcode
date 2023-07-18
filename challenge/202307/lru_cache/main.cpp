#include <cassert>
#include <map>
#include <cstddef>
#include <cstdio>

class LRUCache {
  public:
    struct ListNode {
        ListNode *prev;
        ListNode *next;
        int key;
        int val;

        ListNode(int key, int val) : prev(nullptr), next(nullptr), key(key), val(val) {
        }
    };

    LRUCache(int capacity) : capacity_(capacity), head_(new ListNode(-1, -1)), tail_(new ListNode(-1, -1)) {
        head_->next = tail_;
        tail_->prev = head_;
    }

    ~LRUCache() {
        for (const auto &it : m_) {
            delete it.second;
        }

        delete head_;
        delete tail_;
    }

    int get(int key) {
        if (m_.find(key) == m_.end()) {
            return -1;
        }

        auto *r = m_[key];
        remove(r);
        push_back(r);
        return r->val;
    }

    void put(int key, int value) {
        if (m_.find(key) != m_.end()) {
            remove(m_[key]);
            delete m_[key];
        }

        ListNode *r = new ListNode(key, value);
        m_[key] = r;
        push_back(r);

        if (m_.size() > capacity_) {
            auto *least_used = head_->next;
            remove(least_used);
            m_.erase(least_used->key);
            delete least_used;
        }
    }

  private:
    void push_back(ListNode *r) {
        ListNode *prev = tail_->prev;
        prev->next = r;
        r->prev = prev;
        r->next = tail_;
        tail_->prev = r;
    }

    void remove(ListNode *r) {
        ListNode *prev = r->prev;
        ListNode *next = r->next;
        prev->next = next;
        next->prev = prev;
    }

    size_t capacity_;
    std::map<int, ListNode *> m_;
    ListNode *head_;
    ListNode *tail_;
};

int main() {
    // {
    //     LRUCache c(2);
    //     c.put(1, 1);
    //     c.put(2, 2);
    //     assert(c.get(1) == 1);
    //     c.put(3, 3);
    //     assert(c.get(2) == -1);
    //     c.put(4, 4);
    //     assert(c.get(1) == -1);
    //     assert(c.get(3) == 3);
    //     assert(c.get(4) == 4);
    // }
    {
        LRUCache c(2);
        c.put(2, 1);
        c.put(1, 1);
        c.put(2, 3);
        c.put(4, 1);
        assert(c.get(1) == -1);
        assert(c.get(2) == 3);
    }
    return 0;
}
