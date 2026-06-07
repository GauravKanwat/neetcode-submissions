class Solution {
    bool checkValid(vector<int>& arr) {
        vector<bool> temp(9, false);
        for(int i=0; i<arr.size(); i++) {
            if(temp[arr[i] - 1]) return false;
            temp[arr[i] - 1] = true;
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        // Check rows
        for(int i=0; i<n; i++) {
            vector<int> currRow;
            for(int j=0; j<m; j++) {
                int no = board[i][j] - '0';
                if(board[i][j] != '.') currRow.push_back(no);
            }
            if(!checkValid(currRow)) return false;
        }

        // Check co
        for(int j=0; j<m; j++) {
            vector<int> currCol;
            for(int i=0; i<n; i++) {
                int no = board[i][j] - '0';
                if(board[i][j] != '.') currCol.push_back(no);
            }
            if(!checkValid(currCol)) return false;
        }

        // Check boxes
        vector<vector<int>> boxes(9);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == '.') continue;
                int no = board[i][j] - '0';
                int box = (i/3) * 3 + (j/3);
                boxes[box].push_back(no);
            }
        }
        for(vector<int> temp : boxes) {
            if(!checkValid(temp)) return false;
        }
        return true;
    }
};
