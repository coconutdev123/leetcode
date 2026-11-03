#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>>map;
    vector<vector<string>>res;
    if (strs.size() < 2){ 
        res.push_back(strs);    
        return res;
    }
    for(int i = 0; i < strs.size(); i++){
        string sorted = strs[i];
        sort(sorted.begin(), sorted.end());
        map[sorted].push_back(strs[i]);
    }
    for (auto& match : map){
        res.push_back(match.second);
    }
    
    return res;  
}
