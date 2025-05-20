class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int columns = board[0].size();
        for(int i = 0 ; i < rows ; i++)
        {
            unordered_map<int, int>mp;
            for(int j = 0 ; j < columns ; j++)
            {
                if(board[i][j] != '.')
                {
                    if(mp.find(board[i][j]) != mp.end())
                        return false;
                    mp[board[i][j]]++;
                }
                    
            }
        }       

        for(int i = 0 ; i < columns ; i++)
        {
            unordered_map<int, int>mp;
            for(int j = 0 ; j < rows ; j++)
            {
                if(board[j][i] != '.')
                {
                    if(mp.find(board[j][i]) != mp.end())
                        return false;
                    mp[board[j][i]]++;
                }
            }
        }
        for(int row = 0 ; row < 9 ; row += 3)
        {
            for(int col = 0 ; col < 9 ; col += 3)
            {
                unordered_map<int, int>mp;
                for(int i = 0 ; i < 9 ; i++)
                {
                    if(board[3*(row/3) + i/3][3*(col/3) + i%3] != '.')
                    {
                        if(mp.find(board[3*(row/3) + i/3][3*(col/3) + i%3]) != mp.end())
                            return false;
                        mp[board[3*(row/3) + i/3][3*(col/3) + i%3]]++;
                    }
                }
            }
        }
        return true;
    }
};