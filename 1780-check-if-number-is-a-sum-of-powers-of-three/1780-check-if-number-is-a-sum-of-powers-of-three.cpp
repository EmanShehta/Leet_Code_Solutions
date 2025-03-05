class Solution {
public:
    bool checkPowersOfThree(int n) {
        int power = 0;

        // Find the largest power that is smaller or equal to n
        while (pow(3, power) <= n) {
            power++;
        }

        while (n > 0) {
            // Add current power to the sum
            if (n >= pow(3, power)) n -= pow(3, power);
            // We cannot use the same power twice
            if (n >= pow(3, power)) return false;
            // Move to the next power
            power--;
        }

        // n has reached 0
        return true;
    }
};