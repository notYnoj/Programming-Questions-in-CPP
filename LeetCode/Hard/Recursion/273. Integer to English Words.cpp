class Solution {
public:
    map<int, string> d = {
        {0, "Zero"},
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"},
        {100, "Hundred"},
        {1000, "Thousand"},
        {1000000, "Million"},
        {1000000000, "Billion"}
    };

    string numberToWords(int num) {
        if (num == 0) return d[num];
        return helper(num).substr(1);
    }

    string helper(int num) {
        if (num >= 1000000000) {
            return helper(num / 1000000000) + " Billion" + helper(num % 1000000000);
        } else if (num >= 1000000) {
            return helper(num / 1000000) + " Million" + helper(num % 1000000);
        } else if (num >= 1000) {
            return helper(num / 1000) + " Thousand" + helper(num % 1000);
        } else if (num >= 100) {
            return helper(num / 100) + " Hundred" + helper(num % 100);
        } else if (num >= 20) {
            return " " + d[num / 10 * 10] + helper(num % 10);
        } else if (num >= 1) {
            return " " + d[num];
        }
        return "";
    }
};
