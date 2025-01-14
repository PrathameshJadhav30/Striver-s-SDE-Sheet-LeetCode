class Solution {
public:
    double myPow(double x, int n) {
        // Step 1: Convert 'n' to a long type to handle the edge case where n = INT_MIN
        long binForm = n;

        // Step 2: Handle negative exponent
        // If the exponent is negative, take the reciprocal of the base (1/x)
        // and convert the exponent to a positive value
        if (n < 0) {
            x = 1 / x;
            binForm = -binForm;
        }

        // Step 3: Initialize the result to 1 (x^0 = 1)
        double ans = 1;

        // Step 4: Perform binary exponentiation
        // Loop until the exponent becomes 0
        while (binForm > 0) {
            // If the current power is odd, multiply the result by the current base
            if (binForm % 2 == 1) {
                ans *= x;
            }
            // Square the base for the next iteration
            x *= x;
            // Halve the exponent by dividing it by 2
            binForm /= 2;
        }

        // Step 5: Return the final computed power
        return ans;
    }
};
