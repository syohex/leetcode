#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

auto largestSubmatrix(const vector<vector<int>> &matrix) -> int {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> prev_row_sum(cols, 0);

    int ret = 0;
    for (int row = 0; row < rows; ++row) {
        vector<int> row_sum{matrix[row]};
        for (int col = 0; col < cols; ++col) {
            if (matrix[row][col] != 0) {
                row_sum[col] += prev_row_sum[col];
            }
        }

        vector<int> tmp{row_sum};
        sort(tmp.begin(), tmp.end(), greater{});

        for (int i = 0; i < cols; ++i) {
            ret = max(ret, tmp[i] * (i + 1));
        }

        prev_row_sum = std::move(row_sum);
    }


    return ret;
}

int main() {
    {
        vector<vector<int>> matrix{
            {0, 0, 1},
            {1, 1, 1},
            {1, 0, 1},
        };
        int ret = largestSubmatrix(matrix);
        assert(ret == 4);
    }
    {
        vector<vector<int>> matrix{
            {1, 0, 1, 0, 1},
        };
        int ret = largestSubmatrix(matrix);
        assert(ret == 3);
    }
    {
        vector<vector<int>> matrix{
            {1, 1, 0},
            {1, 0, 1},
        };
        int ret = largestSubmatrix(matrix);
        assert(ret == 2);
    }
    return 0;
}
