class Solution {
private:

string solve(string s,int & pos){
   int num=0;
   string word="";
   for(;pos<s.size();pos++){
         char curr=s[pos];
         if(curr=='['){
               string curstr=solve(s,++pos);
              for(;num>0;num--){
               word+=curstr;
              } 
         }else if(curr>='0' && curr<='9'){
           num=num*10+curr-'0';
         }else if(curr==']'){
             return word;
         }else{
           word+=curr;
         }
   }
   return word;
}


public:
    string decodeString(string s) {
        int pos=0;
       return solve(s,pos);
    }
};