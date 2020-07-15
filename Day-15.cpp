class Solution {
public:
    string reverseWords(string s) {
        
        stringstream obj(s);
                            
        string ans = "";
        string str;
        
        vector<string> v;
        while(obj>>str)
        {
           v.push_back(str);    
        }
        
        reverse(v.begin(),v.end());
        
        for(auto j : v)
        {
            if(ans.size())  ans+=' ';
            ans+=j;
        }
        
        return ans;
    }
};
