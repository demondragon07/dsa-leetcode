class Solution {
public:
   int binExp(int a ,int b,int m){
    int ans=1;
    while(b){
    if(b&1){
        ans=(ans*1LL*a)%m;
    }
    a=(a*1LL*a)%m;
    b>>=1;
    }
    return ans;
 }

    int superPow(int a, vector<int>& b) {
        int bmod=0;
        for(auto x:b){
            bmod=(bmod*10+x)%1140;
        }
         return binExp( a,bmod,1337);
    }
};