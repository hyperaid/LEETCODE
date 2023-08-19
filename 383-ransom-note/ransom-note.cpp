class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
         map<char,int> m2;
        
        for(int i=0;i<magazine.length();i++){
            m2[magazine[i]]++;
        }
        
       for(int i=0;i<ransomNote.length();i++ ){
           if(m2[ransomNote[i]]==0){
               return false;
           }
           m2[ransomNote[i]]--;
       }
        return true;

    }
};