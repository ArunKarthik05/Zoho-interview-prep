#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty()) return result;

    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        // Traverse top row
        for (int i = left; i <= right; ++i)
            result.push_back(matrix[top][i]);
        top++;

        // Traverse right column
        for (int i = top; i <= bottom; ++i)
            result.push_back(matrix[i][right]);
        right--;

        // Traverse bottom row (if applicable)
        if (top <= bottom) {
            for (int i = right; i >= left; --i)
                result.push_back(matrix[bottom][i]);
            bottom--;
        }

        // Traverse left column (if applicable)
        if (left <= right) {
            for (int i = bottom; i >= top; --i)
                result.push_back(matrix[i][left]);
            left++;
        }
    }

    return result;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10,11,12}
    };

    vector<int> result = spiralOrder(matrix);

    cout << "Spiral order traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
