class Solution {
public:
    bool wordMatch(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int idx, int i, int j)
    {
        if(idx == word.length() - 1) 
            return true;
        
        visited[i][j] = true;
        if(i>0 && !visited[i-1][j] && board[i-1][j]==word[idx+1] && wordMatch(board, word, visited,idx+1, i-1, j)) 
            return true;
        if(j>0 && !visited[i][j-1] && board[i][j-1]==word[idx+1] && wordMatch(board, word, visited,idx+1, i, j-1)) 
            return true;
        if(i<board.size()-1 && !visited[i+1][j] && board[i+1][j] == word[idx+1] && wordMatch(board, word, visited,idx+1, i+1, j)) 
            return true;
        if(j < board[0].size()-1 && !visited[i][j+1] && board[i][j+1] == word[idx+1] && wordMatch(board, word, visited,idx+1, i, j+1)) 
            return true;
        
        visited[i][j] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++)
                if(board[i][j]==word[0] && wordMatch(board, word, visited, 0, i, j))
                    return true;
        
        return false;
    }
};
