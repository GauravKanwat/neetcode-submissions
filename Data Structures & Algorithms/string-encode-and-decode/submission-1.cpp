class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string temp;
        for(string str : strs) {
            for(char c : str) {
                if(c == ':') {
                    temp += "::";
                }
                else temp.push_back(c);
            }
            temp += ":;";
        }
        return temp;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string temp;
        int i = 0;
        while(i < s.size()) {
            if(s[i] != ':') {
                temp.push_back(s[i]);
                i++;
            }
            else {
                if(i + 1 < s.size()) {
                    if(s[i+1] == ';') {
                        res.push_back(temp);
                        temp = "";
                        i += 2;
                    }
                    else if(s[i+1] == ':') {
                        temp += s[i+1];
                        i += 2;
                    }
                }
            }
        }
        return res;
    }
};
