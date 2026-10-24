/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]

Output: 1

Example 2:

Input: nums = [4,1,2,1,2]

Output: 4

Example 3:

Input: nums = [1]

Output: 1
*/
#include <vector>
#include <unordered_map>
using namespace std;

int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int x : nums){
            m[x]++;
        }
        for(auto &p : m){
            if(p.second == 1){
                return p.first;
            }
        }
        return -1;
    }
