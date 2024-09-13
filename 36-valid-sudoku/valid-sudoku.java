import java.util.HashMap;
import java.util.HashSet;
import java.util.Vector;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        Vector<HashSet<Character>> validRow = new Vector<HashSet<Character>>();
        Vector<HashSet<Character>> validCol = new Vector<HashSet<Character>>();
        HashMap<Integer, HashSet<Character>> validBox  = new HashMap<Integer, HashSet<Character>>();

        for(int i = 0; i < board.length; i++){
            HashSet<Character> temp = new HashSet<Character>();
            validRow.add(temp);
            HashSet<Character> temp2 = new HashSet<Character>();
            validCol.add(temp2);
            for(int j = 0; j < board.length; j++){
                int key = (i/3)*10 + (j/3);
                HashSet<Character> temp3 = new HashSet<Character>();
                validBox.put(key, temp3);
            }
            
        }

        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board.length; j++){
                int key = (i/3)*10 + (j/3);
                if(board[i][j] == '.') continue;
                if( validRow.get(i).contains(board[i][j]) ||  validCol.get(j).contains(board[i][j]) || validBox.get(key).contains(board[i][j])){
                    return false;
                } 
                validRow.get(i).add(board[i][j]);
                validCol.get(j).add(board[i][j]);
                validBox.get(key).add(board[i][j]);
                
            }
        }
        return true;
    }
}