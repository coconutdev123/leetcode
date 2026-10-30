#include <vector>
#include <string>

using namespace std;


string longestPalindrome(string s) {
    int n = s.size();
    if(n < 2) return s;
    vector<vector<bool>>dp(n,vector<bool>(n,false));
    
    int start = 0;
    int len = 1;

    for(int i = 0; i < n; i++) dp[i][i] = true;

    for(int a = 2; a <= n; a++){
        for(int i = 0; i + a - 1 < n; i++){
            int j = i + a - 1;

            if(s[i] == s[j]){
                if(a == 2 || dp[i+1][j-1]){
                    dp[i][j] = true;
                    if(a > len){
                        len = a;
                        start = i;
                    }
                }
            }
        }
    }
    return s.substr(start, len);
}
