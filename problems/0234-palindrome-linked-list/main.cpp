#include <cassert>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

bool isPalindrome(ListNode *head) {
    if (head == nullptr) {
        return true;
    }

    std::vector<int> vals;
    ListNode *next = head;
    while (next != nullptr) {
        vals.push_back(next->val);
        next = next->next;
    }

    size_t limit = vals.size() / 2;
    for (size_t i = 0; i <= limit; ++i) {
        if (vals[i] != vals[vals.size() - 1 - i]) {
            return false;
        }
    }

    return true;
}

int main() {
    {
        ListNode *list = new ListNode(1);
        list->next = new ListNode(2);
        assert(!isPalindrome(list));
        delete list;
    }
    {
        ListNode *list = new ListNode(1);
        list->next = new ListNode(2);
        list->next = new ListNode(2);
        list->next = new ListNode(1);
        assert(isPalindrome(list));
        delete list;
    }
    return 0;
}
