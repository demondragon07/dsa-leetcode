class Solution {
public:
    string replaceDigits(string s) {
        for(int i=1;i<s.size();i+=2){
           char ch=s[i-1];
           int jump=s[i]-'0';
           s[i]=ch+jump;
        }

        return s;
    }
};