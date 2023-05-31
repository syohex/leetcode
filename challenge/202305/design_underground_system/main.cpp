#include <cassert>
#include <string>
#include <map>
#include <cstdio>

class UndergroundSystem {
  public:
    UndergroundSystem() {
    }

    void checkIn(int id, const std::string stationName, int t) {
        check_ins_[id] = {stationName, t};
    }

    void checkOut(int id, const std::string stationName, int t) {
        auto &start = check_ins_[id];

        std::pair<std::string, std::string> key{start.first, stationName};
        auto it = times_.find(key);
        if (it != times_.end()) {
            it->second.first += 1;
            it->second.second += (t - start.second);
        } else {
            times_[key] = {1, t - start.second};
        }

        check_ins_.erase(id);
    }

    double getAverageTime(const std::string startStation, const std::string endStation) {
        const auto &it = times_.find({startStation, endStation});
        if (it != times_.end()) {
            return static_cast<double>(it->second.second) / it->second.first;
        }

        const auto &it2 = times_.find({endStation, startStation});
        return static_cast<double>(it2->second.second) / it2->second.first;
    }

    std::map<int, std::pair<std::string, int>> check_ins_;
    std::map<std::pair<std::string, std::string>, std::pair<int, int>> times_;
};

int main() {
    {
        UndergroundSystem g;
        g.checkIn(45, "Leyton", 3);
        g.checkIn(32, "Paradise", 8);
        g.checkIn(27, "Leyton", 10);
        g.checkOut(45, "Waterloo", 15);
        g.checkOut(27, "Waterloo", 20);
        g.checkOut(32, "Cambridge", 22);
        assert(g.getAverageTime("Paradise", "Cambridge") == 14);
        assert(g.getAverageTime("Leyton", "Waterloo") == 11);
        g.checkIn(10, "Leyton", 24);
        assert(g.getAverageTime("Leyton", "Waterloo") == 11);
        g.checkOut(10, "Waterloo", 38);
        assert(g.getAverageTime("Leyton", "Waterloo") == 12);
    }
    return 0;
}
