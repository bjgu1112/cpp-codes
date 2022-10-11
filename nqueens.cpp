#define all(v) v.begin(), v.end()
bool GoodQueen(int n, const vector<string>& board, int startx, int starty) {
        vector<int> dirx = {1, -1, 1, -1}, diry = {1, 1, -1, -1};
        for (int i = 0; i < 4; i++) {
            int x = startx + dirx[i], y = starty + diry[i];
            while ((x >= 0 and x < n) and (y >= 0 and y < n)) {
                if (board[y][x] == 'Q') return false;
                x += dirx[i];
                y += diry[i];
            }
        }
        return true;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<int> cols, og;
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            cols.push_back(i);
            og.push_back(i);
        }
        next_permutation(all(cols));
        while (true) {
            bool good = true;
            vector<string> board(n, string(n, '.'));
            for (int i = 0; i < n; i++) {
                board[i][cols[i]] = 'Q';
                if (not GoodQueen(n, board, cols[i], i)) {
                    good = false;
                    break;
                }
            }
            
            if (good) ans.push_back(board);
            
            next_permutation(all(cols));
            if (cols == og) break;
        }
        return ans;
    }
int main(){
  int n;
  cin>>n;
  vector<vector<string>> str;
  str = solveNQueens(n);
  for(int i=0;i<str.size();i++){
    for(int j=0;j<str[0].size();j++){
      cout<<str[i][j]<<" ";
    }
    cout<<endl;
  }
}
