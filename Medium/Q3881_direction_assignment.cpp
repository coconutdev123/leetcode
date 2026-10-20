// You are given three integers n, pos, and k.

// There are n people standing in a line indexed from 0 to n - 1. Each person independently chooses a direction:

// 'L': visible only to people on their right
// 'R': visible only to people on their left
// A person at index pos sees others as follows:
// A person i < pos is visible if and only if they choose 'L'.
// A person i > pos is visible if and only if they choose 'R'.
// Return the number of possible direction assignments such that the person at index pos sees exactly k people.

// Since the answer may be large, return it modulo 109 + 7.

 

// Example 1:

// Input: n = 3, pos = 1, k = 0

// Output: 2

// Explanation:​​​​​​​

// Index 0 is to the left of pos = 1, and index 2 is to the right of pos = 1.
// To see k = 0 people, index 0 must choose 'R' and index 2 must choose 'L', keeping both invisible.
// The person at index 1 can choose 'L' or 'R' since it does not affect the count. Thus, the answer is 2.

#include <cmath>
#include <iostream>

using namespace std;

long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

long long modInverse(long long x, long long mod) {
    return modPow(x, mod - 2, mod);
}

int countVisiblePeople(int n, int pos, int k) {
    const int MOD = 1'000'000'007;

    if (k < 0 || k > n - 1) return 0;

    int N = n - 1;
    long long comb = 1;
    for (int i = 1; i <= k; i++) {
        comb = comb * (N - k + i) % MOD;
        comb = comb * modInverse(i, MOD) % MOD;
    }

    return (2 * comb) % MOD;
}