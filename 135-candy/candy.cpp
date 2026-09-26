class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        if (n == 0) return 0;

        int i = 1;
        int sum = 1;

        while (i < n) {

            if (ratings[i] == ratings[i - 1]) {
                sum += 1;
                i++;
                continue;
            }

            // Increasing
            int peak = 1;

            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                sum += peak;
                i++;
            }

            // Decreasing
            int down = 1;

            while (i < n && ratings[i] < ratings[i - 1]) {
                down++;
                sum += down-1;
                i++;
            }

            // Fix the peak
            if (down > peak) {
                sum += down - peak;
            }
        }

        return sum;
    }
};