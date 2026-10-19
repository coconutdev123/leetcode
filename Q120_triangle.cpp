/*
Example 1:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
*/


#include <vector>
#include <iostream>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    if (n == 0) return 0;
    for(int i = n - 2; i >= 0; --i) {
        for(int j = 0; j < triangle[i].size(); ++j) {
            // cout << "Before: triangle[" << i << "][" << j << "] = " << triangle[i][j] << endl;
            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            // cout << "After: triangle[" << i << "][" << j << "] = " << triangle[i][j] << endl;
        }
    }
    return triangle[0][0];

}