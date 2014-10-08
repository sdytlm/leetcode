/* Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 
 The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int i;
        int j;
        // test row
        vector <char> subSudoku;
        for(i=0;i<9;i++) {
            subSudoku.clear();
            for(j=0;j<9;j++) {
                subSudoku.push_back(board[i][j]);
            }
            if(isDuplicates(subSudoku))
                return false;
        }
        
        // test column
        for(i=0;i<9;i++) {
            subSudoku.clear();
            for(j=0;j<9;j++) {
                subSudoku.push_back(board[j][i]);
            }
            if(isDuplicates(subSudoku))
                return false;
        }
        
        // test 9*9 cubic.
        int a;
        int b;
        for(a=0;a<3;a++) {
            for(b=0;b<3;b++) {
                subSudoku.clear();
                for(i=3*a;i<3+3*a;i++) {
                    for(j=3*b;j<3+3*b;j++) {
                        subSudoku.push_back(board[i][j]);
                    }
                }
                if(isDuplicates(subSudoku))
                    return false;
            }
        }
        return true;
        
    }
    bool isDuplicates(vector<char> &subSudoku) {
        unordered_map <char, bool> hash_map;
        while(!subSudoku.empty()) {
            char num = subSudoku.back();
            subSudoku.pop_back();
            if(num=='.')
                continue;
            if(hash_map.find(num)!=hash_map.end())
                return true;
            else    // not found
                hash_map.insert(make_pair<char,bool>(num,true));
        }
        return false;
    }
};