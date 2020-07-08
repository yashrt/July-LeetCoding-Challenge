class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)
            return {};
        
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-2; i++)
        {
            int j = i+1;
            int k = nums.size()-1;
            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0)
                    ans.insert({nums[i], nums[j++], nums[k--]});
                else if(sum<0)
                    j++;
                else
                    k--;
            }
        }
        
        vector<vector<int>> res;
        for(vector<int> temp: ans)
            res.push_back(temp);
    
        return res;      
    }
};
