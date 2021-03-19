#include <cassert>
#include <vector>
#include <functional>

bool canVisitAllRooms(const std::vector<std::vector<int>> &rooms) {
    std::function<bool(int room, std::vector<bool> &checked)> f;
    f = [&f, &rooms](int room, std::vector<bool> &checked) -> bool {
        bool ok = true;
        for (bool c : checked) {
            if (!c) {
                ok = false;
                break;
            }
        }

        if (ok) {
            return true;
        }

        for (int key : rooms[room]) {
            if (checked[key]) {
                continue;
            }

            checked[key] = true;
            if (f(key, checked)) {
                return true;
            }
        }

        return false;
    };

    std::vector<bool> checked(rooms.size(), false);
    checked[0] = true;
    return f(0, checked);
}

int main() {
    {
        std::vector<std::vector<int>> rooms{
            {1},
            {2},
            {3},
            {},
        };

        assert(canVisitAllRooms(rooms));
    }
    {
        std::vector<std::vector<int>> rooms{
            {1, 3},
            {3, 0, 1},
            {2},
            {},
        };

        assert(!canVisitAllRooms(rooms));
    }
    {
        std::vector<std::vector<int>> rooms{
            {2, 3},
            {},
            {2},
            {1, 3, 1},
        };

        assert(canVisitAllRooms(rooms));
    }
    return 0;
}
