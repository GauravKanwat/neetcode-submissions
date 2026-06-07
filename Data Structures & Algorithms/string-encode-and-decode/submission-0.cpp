class Solution {
public:

    string encode(vector<string>& strs) {
        ostringstream enc;
        for(const string& str : strs)
            enc << str.size() << ":" << str;
        return enc.str();
    }

    vector<string> decode(string s) {
        vector<string> ans;
        istringstream stream(s);
        string token;

        while(getline(stream, token, ':')) {
            int len = stoi(token);
            char* buffer = new char[len];
            stream.read(buffer, len);
            ans.emplace_back(buffer, len);
            delete[] buffer;
        }
        return ans;
    }
};
