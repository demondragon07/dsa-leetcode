class Solution {
public:
    int minPartitions(string n) {
        int ans=0;
        for(int i=0;i<n.size();i++){
            int num=n[i]-'0';
            ans=max(ans,num);
        }

        return ans;
    }
};