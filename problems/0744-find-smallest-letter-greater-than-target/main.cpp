#include <cassert>
#include <vector>
#include <map>

char nextGreatestLetter(const std::vector<char> &letters, char target) {
    std::map<int, char> m;
    for (char c : letters) {
        int diff;
        if (c < target) {
            diff = (c + 26) - target;
        } else {
            diff = c - target;
        }

        if (diff <= 0) {
            diff += 26;
        }

        m[diff] = c;
    }

    return m.begin()->second;
}

int main() {
    {
        std::vector<char> input{'a', 'b'};
        assert(nextGreatestLetter(input, 'z') == 'a');
    }
    {
        std::vector<char> input{'c', 'f', 'j'};
        assert(nextGreatestLetter(input, 'a') == 'c');
    }
    {
        std::vector<char> input{'c', 'f', 'j'};
        assert(nextGreatestLetter(input, 'c') == 'f');
    }
    {
        std::vector<char> input{'c', 'f', 'j'};
        assert(nextGreatestLetter(input, 'd') == 'f');
    }
    {
        std::vector<char> input{'c', 'f', 'j'};
        assert(nextGreatestLetter(input, 'g') == 'j');
    }
    {
        std::vector<char> input{'c', 'f', 'j'};
        assert(nextGreatestLetter(input, 'j') == 'c');
    }
    {
        std::vector<char> input{'c', 'f', 'j'};
        assert(nextGreatestLetter(input, 'k') == 'c');
    }
    return 0;
}
