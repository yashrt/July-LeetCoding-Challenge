class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> res;
        res = cells;
        N = N % 14 == 0 ? 14 : N % 14;    // pattern repeats(as the 1st day) in every 14 days
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=6; j++)
            {
                res[j] = (cells[j-1]==cells[j+1])?1:0;
            }
            res[0] = 0;
            res[7] = 0;
            cells = res;;
        }
        return res;
    }
};
