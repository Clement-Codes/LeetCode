#include<vector>
#include<set>
#include<map>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> validRow;
        vector<set<char>> validCol;
        map<int, set<char>> validBox;
        for(int i = 0; i < board.size(); i++){
            set<char> temp;
            validRow.push_back(temp);
            validCol.push_back(temp);
            for(int j = 0; j < board.size(); j++){
                int key = (i/3)*10 + (j/3);
                validBox[key] = temp;
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                int key = (i/3)*10 + (j/3);
                if (board[i][j] == '.') continue;
                if (validRow[i].find(board[i][j]) != validRow[i].end() or validCol[j].find(board[i][j]) != validCol[j].end() or validBox[key].find(board[i][j]) != validBox[key].end()){

                    return false;
                }
                validRow[i].insert(board[i][j]);
                validCol[j].insert(board[i][j]);
                validBox[key].insert(board[i][j]);
            }
        }
        for(set<char> i: validRow){
            for(char j: i){
                
            }
        }
        return true;
    }
};