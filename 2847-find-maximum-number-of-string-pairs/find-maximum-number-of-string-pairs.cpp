class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int ans=0;
        int i=0;
        int n=words.size();
        int j=n-1;
        for(int i=0;i<n-1;i++){
             string temp1=words[i];
          while(j>i){
              string temp2;
              temp2=words[j];
              reverse(temp2.begin(),temp2.end());
              if(temp1==temp2){
                  ans++;
                  break;
              }
              j--;
          }
                  j=words.size()-1;
        }
           return ans;

    }
};