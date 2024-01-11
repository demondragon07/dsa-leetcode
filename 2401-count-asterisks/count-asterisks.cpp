class Solution {
public:
    int countAsterisks(string s) {
        bool breaker=false;
        int count=0;
        for(int i=0;i<s.size();i++){
             if(s[i]=='|' && breaker==false){
                 breaker=true;
             }
             else if(s[i]=='|' && breaker==true){
                 breaker=false;
             }
             else if(s[i]=='*' && breaker ==false){
                 count++;
             }

        }

        return count;
    }
};