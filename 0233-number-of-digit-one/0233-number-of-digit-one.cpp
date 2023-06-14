class Solution {
private:
int solve(int n ){
       string len=to_string(n);
        int length=len.size();
     if(n<=0){
         return 0;
     }
     if(n<10){
         return 1;
     }
    int base=pow(10,length-1);
    int firstdigit=n/base;
    int rem=n%base;
    int oneinbase;
    if(firstdigit==1){
        oneinbase=n-base+1;
    }else{
        oneinbase=base;
    }
return solve(rem)+firstdigit*solve(base-1)+oneinbase;
}


public:
    int countDigitOne(int n) {
       return solve(n);
    }  
};