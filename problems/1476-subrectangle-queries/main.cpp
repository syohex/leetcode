#include <cassert>
#include <vector>

using namespace std;

class SubrectangleQueries {
  public:
    SubrectangleQueries(vector<vector<int>> &rectangle) : rectangle(rectangle) {
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = 0; i <= row2 - row1; ++i) {
            for (int j = 0; j <= col2 - col1; ++j) {
                rectangle[row1 + i][col1 + j] = newValue;
            }
        }
    }

    int getValue(int row, int col) {
        return rectangle[row][col];
    }

    std::vector<std::vector<int>> rectangle;
};

int main() {
    std::vector<std::vector<int>> input{
        {1, 2, 1},
        {4, 3, 4},
        {3, 2, 1},
        {1, 1, 1},
    };
    auto *v = new SubrectangleQueries(input);
    assert(v->getValue(0, 2) == 1);

    v->updateSubrectangle(0, 0, 3, 2, 5);

    std::vector<std::vector<int>> expected1{
        {5, 5, 5},
        {5, 5, 5},
        {5, 5, 5},
        {5, 5, 5},
    };

    assert(v->rectangle == expected1);
    assert(v->getValue(0, 2) == 5);
    assert(v->getValue(3, 1) == 5);

    v->updateSubrectangle(3, 0, 3, 2, 10);

    std::vector<std::vector<int>> expected2{
        {5, 5, 5},
        {5, 5, 5},
        {5, 5, 5},
        {10, 10, 10},
    };
    assert(v->rectangle == expected2);
    assert(v->getValue(0, 2) == 5);
    assert(v->getValue(3, 1) == 10);

    delete v;
    return 0;
}
