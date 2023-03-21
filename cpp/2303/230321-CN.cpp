#include <vector>

/**
 * 2469. Convert the Temperature
 *
 * You are given a non-negative floating point number rounded to two decimal places celsius, that denotes the temperature in Celsius.
 * You should convert Celsius into Kelvin and Fahrenheit and return it as an array ans = [kelvin, fahrenheit].
 * Return the array ans. Answers within 10-5 of the actual answer will be accepted.
 */

class Solution {
public:
    static std::vector<double> convertTemperature(double c) {
        return {c + 273.15, c * 1.8 + 32.0};
    }
};