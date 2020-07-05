class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int n = x ^ y;
        while (n) 
        { 
            res += n & 1; 
            n >>= 1; 
        } 
        return res;
    }
};
