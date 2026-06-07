class Solution {
public:
    bool isPalindrome(string s) {
        string check = "";
        for(char c : s) {
            if(iswalnum(c))
                check += tolower(c);
        } 
        int low = 0, high = check.size()-1;
        while(low < high) {
            if(check[low] != check[high]) return false;
            low++; high--;
        }
        return true;
    }
};
