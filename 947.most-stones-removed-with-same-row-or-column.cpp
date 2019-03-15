#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        cnt =  0;
        for (auto &s: stones) {
            X[s[0]].insert(s[1]);
            Y[s[1]].insert(s[0]);
        }
        
        for (auto &s: stones) {
            visit(stones, s[0], s[1]);
        }
        
        return cnt;
     }
    
    void visit(vector<vector<int>>& stones, int i, int j) {
        if (stones[i][j] < 0) return;
        else {
            cout << "stone[" << i << "][" << j << "] " << stones[i][j] << endl;
            stones[i][j] = -stones[i][j];
        }
        
        for (auto y: X[i]) {
            if (y != j && stones[i][j] >= 0) {
                visit(stones, i, y);
                cnt++;
            }
        }
        
        for (auto x: Y[j]) {
            if (x != i && stones[i][j] >= 0) {
                visit(stones, x, j);
                cnt++;
            }
        }
    }
    
private:
    unordered_map<int, unordered_set<int> > X;
    unordered_map<int, unordered_set<int> > Y;    
    int cnt;
};

int main() {
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    Solution s;
    cout << s.removeStones(stones) << endl;
}