class Solution {
public:
    int countPoints(string rings) {
        int n=rings.size();
        unordered_map<int,unordered_set<char>>mp;
        
        int count=0;
        
        for(int i=1;i<n;i++){
            mp[rings[i]-'0'].insert(rings[i-1]);
        }

        for(int i=0;i<10;i++){
            if(mp.find(i)!=mp.end()){
                if(mp.at(i).size()==3){
                    count++;
                }
            }
        }
     
     return count;

    }
};