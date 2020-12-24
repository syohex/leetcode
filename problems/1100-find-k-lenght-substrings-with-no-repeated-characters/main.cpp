#include <cassert>
#include <string>
#include <set>

int numKLenSubstrNoRepeats(const std::string &S, int K) {
    if (S.size() < static_cast<size_t>(K)) {
        return 0;
    }

    char table[26] = {0};
    std::set<int> bad_keys;
    for (int i = 0; i < K - 1; ++i) {
        int key = S[i] - 'a';
        ++table[key];
        if (table[key] >= 2) {
            bad_keys.insert(key);
        }
    }

    int ret = 0;
    int limit = static_cast<int>(S.size());
    for (int i = K - 1; i < limit; ++i) {
        int key = S[i] - 'a';
        if (bad_keys.empty() && table[key] == 0) {
            ++ret;
        }

        ++table[key];
        if (table[key] >= 2) {
            bad_keys.insert(key);
        }

        int removed_key = S[i - K + 1] - 'a';
        --table[removed_key];
        if (bad_keys.find(removed_key) != bad_keys.end() && table[removed_key] <= 1) {
            bad_keys.erase(removed_key);
        }
    }

    return ret;
}

int main() {
    assert(numKLenSubstrNoRepeats("havefunonleetcode", 5) == 6);
    assert(numKLenSubstrNoRepeats("home", 5) == 0);
    assert(numKLenSubstrNoRepeats("gdggdbjchgadcfddfahbdebjbagaicgeahehjhdfghadbcbbfhgefcihbcbjjibjdhfhbdijehhiabad", 5) == 29);

    return 0;
}
