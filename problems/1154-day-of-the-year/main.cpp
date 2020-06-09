#include <cassert>
#include <string>

int dayOfYear(const std::string &date) {
    int year = 0;
    for (int i = 3, v = 1; i >= 0; --i, v *= 10) {
        year += (date[i] - '0') * v;
    }

    int month = 0;
    for (int i = 6, v = 1; i >= 5; --i, v *= 10) {
        month += (date[i] - '0') * v;
    }

    int day = 0;
    for (int i = 9, v = 1; i >= 8; --i, v *= 10) {
        day += (date[i] - '0') * v;
    }

    int mDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                mDays[1] = 29;
            }
        } else {
            mDays[1] = 29;
        }
    }

    int ret = 0;
    for (int i = 0; i < month - 1; ++i) {
        ret += mDays[i];
    }

    return ret + day;
}

int main() {
    assert(dayOfYear("2019-01-09") == 9);
    assert(dayOfYear("2019-02-10") == 41);
    assert(dayOfYear("2003-03-01") == 60);
    assert(dayOfYear("2004-03-01") == 61);
    assert(dayOfYear("2000-03-01") == 61);
    return 0;
}
