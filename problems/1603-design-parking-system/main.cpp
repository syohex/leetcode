#include <cassert>

class ParkingSystem {
  public:
    ParkingSystem(int big, int medium, int small) {
        parkings_[0] = big;
        parkings_[1] = medium;
        parkings_[2] = small;
    }

    bool addCar(int carType) {
        if (parkings_[carType - 1] <= 0) {
            return false;
        }

        --parkings_[carType - 1];
        return true;
    }

    int parkings_[3];
};

int main() {
    ParkingSystem ps(1, 1, 0);
    assert(ps.addCar(1));
    assert(ps.addCar(2));
    assert(!ps.addCar(3));
    assert(!ps.addCar(1));
    return 0;
}
