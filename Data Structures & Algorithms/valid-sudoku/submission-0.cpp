class Solution {
    bool checkValid(vector<int>& temp) {
        vector<bool> comp(9, false);
        for(int i=0; i<temp.size(); i++) {
            if(comp[temp[i]-1] == true) return false;
            else comp[temp[i]-1] = true;
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        // Rows
        for(int i=0; i<n; i++) {
            vector<int> currRow;
            for(int j=0; j<m; j++) {
                int no = board[i][j] - '0';
                if(board[i][j] != '.') currRow.push_back(no);
            }
            if(!checkValid(currRow)) return false;
        }
        // Cols
        for(int j=0; j<m; j++) {
            vector<int> currCol;
            for(int i=0; i<n; i++) {
                int no = board[i][j] - '0';
                if(board[i][j] != '.') currCol.push_back(no);
            }
            if(!checkValid(currCol)) return false;
        }
        //boxes
        vector<vector<int>> boxes(9);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == '.') continue;
                int no = board[i][j] - '0';
                //box 1
                if(i <= 2 && j <= 2) boxes[0].push_back(no);
                //box 2
                else if(j > 2 && j <= 5 && i <= 2) boxes[1].push_back(no);
                //box 3
                else if(j > 5 && j <= 8 && i <= 2) boxes[2].push_back(no);
                //box 4
                else if(i > 2 && i <= 5 && j <= 2) boxes[3].push_back(no);
                //box 5
                else if(i > 2 && i <= 5 && j > 2 && j <= 5) boxes[4].push_back(no);
                //box 6
                else if(i > 2 && i <= 5 && j > 5) boxes[5].push_back(no);
                //box 7
                else if(i > 5 && j <= 2) boxes[6].push_back(no);
                //box 8
                else if(i > 5 && j > 2 && j <= 5) boxes[7].push_back(no);
                //box 9
                else boxes[8].push_back(no);
            }
        }
        for(int i=0; i<boxes.size(); i++) {
                if(!checkValid(boxes[i])) return false;
        }
        return true;
    }
};
