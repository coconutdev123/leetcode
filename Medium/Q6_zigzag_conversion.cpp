/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"

*/


#include <string>
using namespace std;

string convert(string s, int numRows) {
    if((numRows == 1)|| (numRows >= s.size())){
        return s;
    }
    string result;
    result.reserve(s.size());
    int cycle = 2 * numRows - 2;
    for(int i = 0; i < numRows; i++){
        for (int j = i; j < s.size(); j+= cycle){
            result.push_back(s[j]);
            int second = j + cycle - 2 * i;
            if(i != 0 && i != numRows - 1 && second < s.size()){
                result.push_back(s[second]);
            }
        }
    }
    return result;
}
