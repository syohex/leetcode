#include <cassert>
#include <vector>

int chalkReplacer(const std::vector<int> &chalk, int k) {
    int len = chalk.size();
    long sum = 0;
    for (int n : chalk) {
        sum += n;
    }

    long t = k;
    t = t % sum;

    for (int i = 0; i < len; ++i) {
        if (t < chalk[i]) {
            return i;
        }
        t -= chalk[i];
    }

    // never reach here
    return -1;
}

int main() {
    {
        std::vector<int> chalk{5, 1, 5};
        int ret = chalkReplacer(chalk, 22);
        assert(ret == 0);
    }
    {
        std::vector<int> chalk{3, 4, 1, 2};
        int ret = chalkReplacer(chalk, 25);
        assert(ret == 1);
    }
    return 0;
}
