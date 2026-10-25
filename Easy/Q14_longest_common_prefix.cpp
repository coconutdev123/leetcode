/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()){
        return "";
    }
    
    int n = strs.size();
    string shortest = strs[0];
    for(int i = 0; i < n; i++){
        if(strs[i].length() < shortest.length()){
            shortest = strs[i];
        }
    }
    int index = 0;
    while (index < shortest.length()) {
        for (const string& str : strs) {
            if (str[index] != shortest[index]) {
                return shortest.substr(0, index);
            }
        }
        index++;
    }
    
    return shortest;
}


