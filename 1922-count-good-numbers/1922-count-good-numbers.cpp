#define MOD 1000000007
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long modPow(long long base, long long exp) {
        long long ans = 1;
        base %= MOD; // Ensure base is modulo MOD

        while (exp > 0) {
            if (exp % 2 == 1) { // If exp is odd
                ans = (ans * base) % MOD;
            }
            base = (base * base) % MOD; // Square the base
            exp = exp >> 1; // Right shift exp by 1 (divide by 2)
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        // For even indices (0-based)
        long long evenCount = (n + 1) / 2; // Half are even indices, +1 if n is odd
        // For odd indices (0-based)
        long long oddCount = n / 2; // Half are odd indices

        // 5 choices for even indices (0, 2, 4, 6, 8) and 4 choices for odd indices (2, 3, 5, 7)
        return (modPow(5, evenCount) * modPow(4, oddCount)) % MOD;
    }
};
