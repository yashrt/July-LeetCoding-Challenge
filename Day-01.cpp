class Solution {
public:
    int arrangeCoins(int n) {
        long sum = 0;
        int i = 0;
        while(sum<n)
            sum += ++i;

        return (sum==n)?i:i-1;
    }
};
