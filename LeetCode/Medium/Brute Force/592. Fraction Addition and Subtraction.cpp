class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0, denominator = 1; // Start with 0/1 as the initial fraction
    int i = 0, n = expression.size();

    while (i < n) {
        // Parse the sign (+ or -)
        int sign = 1;
        if (expression[i] == '-' || expression[i] == '+') {
            sign = (expression[i] == '-') ? -1 : 1;
            i++;
        }

        // Parse the numerator
        int num = 0;
        while (i < n && isdigit(expression[i])) {
            num = num * 10 + (expression[i] - '0');
            i++;
        }

        // Skip the '/'
        i++;

        // Parse the denominator
        int den = 0;
        while (i < n && isdigit(expression[i])) {
            den = den * 10 + (expression[i] - '0');
            i++;
        }

        // Update the overall numerator and denominator
        numerator = numerator * den + sign * num * denominator;
        denominator *= den;

        // Simplify the fraction
        int gcdVal = gcd(abs(numerator), denominator);
        numerator /= gcdVal;
        denominator /= gcdVal;
    }

    // If the numerator is zero, return "0/1"
    if (numerator == 0) {
        return "0/1";
    }

    // Return the result in the form "numerator/denominator"
    return to_string(numerator) + "/" + to_string(denominator);
    }
};
