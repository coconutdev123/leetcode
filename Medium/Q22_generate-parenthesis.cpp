#include <vector>
#include <string>

using namespace std;


/*

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.


Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]


Example 2:

Input: n = 1
Output: ["()"]

*/

vector<string> generateParenthesis(int n) {
        
    vector<string> result;
    if(n == 0) {result.push_back(""); return result;}
    if(n == 1) {result.push_back("()"); return result;}

    for(int i = 0; i < n; i++) {
        for (const string& left : generateParenthesis(i)) {
            for (const string& right : generateParenthesis(n - 1 - i)) {
                result.push_back("(" + left + ")" + right);
            }
        }
    }

    return result;

}