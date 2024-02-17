class Solution {
public:
    bool isPowerOfThree(int n) {
     int maxPowerOfThree = 1162261467;
    // Check if n is a divisor of 3^19 and n is greater than 0
    return n > 0 && maxPowerOfThree % n == 0;
    }
};