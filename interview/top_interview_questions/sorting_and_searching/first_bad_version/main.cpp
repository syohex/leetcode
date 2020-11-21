#include <cassert>

int bad_version;

bool isBadVersion(int version) {
    return version >= bad_version;
}

int firstBadVersion(int n) {
    int left = 1;
    int right = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            if (!isBadVersion(mid - 1)) {
                return mid;
            }

            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return n;
}

int main() {
    {
        bad_version = 4;
        assert(firstBadVersion(5) == bad_version);
    }
    {
        bad_version = 1;
        assert(firstBadVersion(1) == bad_version);
    }
    {
        bad_version = 1702766719;
        assert(firstBadVersion(2126753390) == bad_version);
    }
    return 0;
}
