class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = 0;
        for(int num: nums)
            temp ^= num;
        
        int setBit = 0;
        for(int i=0; i<32; i++)
            if(temp & 1<<i)
            {
                setBit = i;
                break;
            }
        
        int first = 0, second = 0;
        for(int num: nums)
            if(num & 1<<setBit)
                first ^= num;
            else
                second ^= num;
        
        return {first, second};
    }
};
