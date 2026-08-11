class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        
        vector<string> mapping = {
            "",    
            "",     
            "abc",  
            "def",  
            "ghi",  
            "jkl",  
            "mno",  
            "pqrs", 
            "tuv",  
            "wxyz"  
        };
        
        string current;
        backtrack(digits, 0, current, mapping, result);
        return result;
    }
    
private:
    void backtrack(const string& digits, int index, string& current, 
                   vector<string>& mapping, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        int digit = digits[index] - '0';
        const string& letters = mapping[digit];
        
        for (char c : letters) {
            current.push_back(c);
            backtrack(digits, index + 1, current, mapping, result);
            current.pop_back();
        }
    }
};