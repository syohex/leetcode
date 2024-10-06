#include <cassert>
#include <string>
#include <vector>
#include <sstream>

bool areSentencesSimilar(const std::string& sentence1, const std::string& sentence2) {
    const auto split = [](const std::string& s) -> std::vector<std::string> {
        std::vector<std::string> ret;
        std::stringstream ss(s);
        std::string tmp;

        while (std::getline(ss, tmp, ' ')) {
            if (tmp.empty()) {
                break;
            }
            ret.push_back(tmp);
        }

        return ret;
    };

    auto words1 = split(sentence1);
    auto words2 = split(sentence2);

    auto& v1 = words1.size() < words2.size() ? words1 : words2;
    auto& v2 = words1.size() < words2.size() ? words2 : words1;

    int start = 0;
    int len1 = v1.size();
    int len2 = v2.size();
    while (start < len1 && v1[start] == v2[start]) {
        ++start;
    }

    int end1 = len1 - 1;
    int end2 = len2 - 1;
    while (end1 >= 0 && v1[end1] == v2[end2]) {
        --end1;
        --end2;
    }
    return end1 < start;
}

int main(){
    assert(areSentencesSimilar("Hello Jane", "Hello my name is Jane"));
    assert(!areSentencesSimilar("Frog cool", "Frogs are cool"));
    assert(areSentencesSimilar("My name is Haley", "My Haley"));
    assert(!areSentencesSimilar("of", "A lot of words"));
    assert(areSentencesSimilar("Eating right now", "Eating"));
    return 0;
}
