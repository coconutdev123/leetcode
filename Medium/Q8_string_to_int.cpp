/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
*/
#include <string>
#include <climits>
using namespace std;

int myAtoi(string s) {
    int i = 0, n = s.size();

    // 1. skip leading whitespace
    while (i < n && s[i] == ' ') i++;

    // 2. optional sign
    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        if (s[i] == '-') sign = -1;
        i++;
    }

    // 3. accumulate digits, 5. clamp as we go
    long long num = 0;
    while (i < n && isdigit(static_cast<unsigned char>(s[i]))) {
        num = num * 10 + (s[i] - '0');
        if (sign ==  1 && num >  INT_MAX) return INT_MAX;
        if (sign == -1 && -num < INT_MIN) return INT_MIN;
        i++;
    }

    return static_cast<int>(sign * num);
}