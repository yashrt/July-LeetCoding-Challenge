class Solution {
public:
    void getSubset(vector<int>& nums, int index, vector<vector<int>>& res)
    {
        if(index == nums.size()-1)
        {
            res.push_back({});
            res.push_back({nums[index]});
        }
        else
        {
            getSubset(nums, index+1, res);
            int n = res.size();
            for(int i=0; i<n; i++)
            {
                vector<int> temp = res[i];
                temp.push_back(nums[index]);
                res.push_back(temp);
            }
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size()==0)
            return {{}};
        
        vector<vector<int>> res;
        getSubset(nums, 0, res);
        
        return res;
    }
};
