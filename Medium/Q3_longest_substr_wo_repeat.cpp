/*
Given a string s, find the length of the longest substring without duplicate characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <string>
#include <unordered_set>
using namespace std;


int lengthOfLongestSubstring(string s) {
    int res = 0;
    unordered_set<char> set;
    int left = 0, right = s.size();
    for (int i = 0; i < right; i++) {
        while(set.count(s[i])) {
            set.erase(s[left++]);
        }
        set.insert(s[i]);
        res = max(res, i - left + 1);
    }    
    return res;
}

