#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();

        int startingrow = 0;
        int endingrow = row - 1;
        int startingcol = 0;
        int endingcol = col - 1;

        int count = 0;
        int total = row * col;

        while (count < total)
        {

            // left to right along startingrow
            for (int i = startingcol; count < total && i <= endingcol; i++)
            {
                ans.push_back(matrix[startingrow][i]);
                count++;
            }
            startingrow++;

            // top to bottom along endingcol
            for (int i = startingrow; count < total && i <= endingrow; i++)
            {
                ans.push_back(matrix[i][endingcol]);
                count++;
            }
            endingcol--;

            // right to left along endingrow
            for (int i = endingcol; count < total && i >= startingcol; i--)
            {
                ans.push_back(matrix[endingrow][i]);
                count++;
            }
            endingrow--;

            // bottom to top along startingcol
            for (int i = endingrow; count < total && i >= startingrow; i--)
            {
                ans.push_back(matrix[i][startingcol]);
                count++;
            }
            startingcol++;
        }

        return ans;
    }
};

int main()
{

    int nRows, mCols;
    cin >> nRows >> mCols;

    vector<vector<int>> arr(nRows, vector<int>(mCols));

    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < mCols; j++)
        {
            cin >> arr[i][j];
        }
    }

    Solution sol;
    vector<int> result = sol.spiralOrder(arr);

    cout << "Spiral Order: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}