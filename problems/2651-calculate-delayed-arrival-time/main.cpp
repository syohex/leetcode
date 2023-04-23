#include <cassert>

int findDelayedArraivalTime(int arrivalTime, int delayedTime) {
    return (arrivalTime + delayedTime) % 24;
}

int main() {
    {
        int ret = findDelayedArraivalTime(15, 5);
        assert(ret == 20);
    }
    {
        int ret = findDelayedArraivalTime(13, 11);
        assert(ret == 0);
    }
    return 0;
}
