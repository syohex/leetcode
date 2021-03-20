#include <cassert>
#include <string>
#include <map>
#include <cmath>

class UndergroundSystem {
  public:
    struct Info {
        std::string name;
        int time = 0;
    };
    struct Summary {
        double total = 0;
        double count = 0;
    };

    UndergroundSystem() {
    }

    void checkIn(int id, const std::string &stationName, int t) {
        checkInTable_[id] = Info{stationName, t};
    }

    void checkOut(int id, const std::string &stationName, int t) {
        const auto &checkInData = checkInTable_[id];
        std::string summaryKey = checkInData.name + " " + stationName;

        summaryTable_[summaryKey].total += t - checkInData.time;
        summaryTable_[summaryKey].count += 1;
    }

    double getAverageTime(const std::string &startStation, const std::string &endStation) {
        const std::string key = startStation + " " + endStation;
        const auto &summary = summaryTable_[key];
        return summary.total / summary.count;
    }

    std::map<int, Info> checkInTable_;
    std::map<std::string, Summary> summaryTable_;
};

void check(double a, double b) {
    double diff = std::fabs(a - b);
    assert(diff < 0.00001);
}

int main() {
    {
        UndergroundSystem u;
        u.checkIn(45, "Leyton", 3);
        u.checkIn(32, "Paradise", 8);
        u.checkIn(27, "Leyton", 10);
        u.checkOut(45, "Waterloo", 15);
        u.checkOut(27, "Waterloo", 20);
        u.checkOut(32, "Cambridge", 22);
        check(u.getAverageTime("Paradise", "Cambridge"), 14.00);
        check(u.getAverageTime("Leyton", "Waterloo"), 11.00);

        u.checkIn(10, "Leyton", 24);
        check(u.getAverageTime("Leyton", "Waterloo"), 11.00);
        u.checkOut(10, "Waterloo", 38);
        check(u.getAverageTime("Leyton", "Waterloo"), 12.00);
    }
    {

        UndergroundSystem u;
        u.checkIn(10, "Leyton", 3);
        u.checkOut(10, "Paradise", 8);
        check(u.getAverageTime("Leyton", "Paradise"), 5.00);
        u.checkIn(5, "Leyton", 10);
        u.checkOut(5, "Paradise", 16);
        check(u.getAverageTime("Leyton", "Paradise"), 5.50);
        u.checkIn(2, "Leyton", 21);
        u.checkOut(2, "Paradise", 30);
        check(u.getAverageTime("Leyton", "Paradise"), 6.666667);
    }
    return 0;
}
