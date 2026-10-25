/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/

#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char>c1;
    int n = s.length();

    for(int i = 0; i< n; i++){
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        c1.push(s[i]);
        } else if (!c1.empty() && s[i] == ')' && c1.top() == '(') {
            c1.pop();
        } else if (!c1.empty() && s[i] == '}' && c1.top() == '{') {
            c1.pop();
        } else if (!c1.empty() && s[i] == ']' && c1.top() == '[') {
            c1.pop();
        } else {
            return false;
        }
    }
    if(c1.empty()){
        return true;
    }
    else{
        return false;
    }
}