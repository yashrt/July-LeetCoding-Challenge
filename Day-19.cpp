class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        bool carry = false;
        int i = a.size()-1;
        int j = b.size()-1;
        
        while(i>=0 && j>=0)
        {
            if(carry)
            {
                if(a[i]==b[j])
                {
                    res = "1" + res;
                    carry = a[i]=='1';
                }
                else
                {
                    res = "0" + res;
                    carry = true;
                }
            }
            else
            {
                if(a[i]==b[j])
                {
                    res = "0" + res;
                    carry = a[i]=='1';
                }
                else
                {
                    res = "1" + res;
                    carry = false;
                }
            }
            i--;
            j--;
        }
        
        if(i==j)
            return (carry)?"1"+res:res;
        else
        {
            string temp;
            int k;
            if(j>=0)
            {
                temp = b;
                k = j;
            }
            else
            {
                temp = a;
                k = i;
            }
            while(k>=0)
            {
                if(temp[k]=='0' && carry)
                {
                    res = "1"+res;
                    carry = false;
                }
                else if(temp[k]=='0' && !carry)
                {
                    res = "0"+res;
                }
                else if(temp[k]=='1' && carry)
                {
                    res = "0"+res;
                    carry = true;
                }
                else if(temp[k]=='1' && !carry)
                {
                    res = "1"+res;
                }
                k--;
            }
        }
        
        return (carry)?"1"+res:res;
    }
};
