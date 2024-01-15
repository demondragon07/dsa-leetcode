class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index=word.find(ch);
        int n=word.size();
        if(index>=0 && index<n){
            reverse(word.begin(),word.begin()+index+1);
        }

        return word;



    }
};