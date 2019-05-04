#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        mapping.push_back({'a', 'b', 'c'});
        mapping.push_back({'d', 'e', 'f'});
        mapping.push_back({'g', 'h', 'i'});
        mapping.push_back({'j', 'k', 'l'});
        mapping.push_back({'m', 'n', 'o'});
        mapping.push_back({'p', 'q', 'r', 's'});
        mapping.push_back({'t', 'u', 'v'});
        mapping.push_back({'w', 'x', 'y', 'z'});

        dfs(digits, "");
        return ans;
    }
    
    void dfs(string digits, string comb) {
        if (digits.empty()) {
            ans.push_back(comb);
            return;
        }
        
        auto character = digits[0];
        auto chars = mapping[charToIndex(character)];
        for (auto c: chars) {
            auto tmp = comb;
            tmp.push_back(c);
            if (digits.length() > 1)
                dfs(digits.substr(1, digits.length() - 1), tmp);
            else
                dfs("", tmp);
        }
    }


    int charToIndex(char c) {
        return c - '0' - 2;
    }
    
private:
    vector<vector<char>> mapping;
    vector<string> ans;
};

int main() {
    Solution s;
    string digits = "23";
    auto ans = s.letterCombinations(digits);
}