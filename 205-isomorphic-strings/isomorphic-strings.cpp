class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> m1;
        map<char,char> m2;
            int boool=-1;

        for(int i=0;i<s.length();i++){
            m1[s[i]]=t[i];
            m2[t[i]]=s[i];
            
        }
        for(int i=0;i<s.length();i++){
            if(m1[s[i]] &&m1[s[i]]!=t[i]) return false;
            if(m2[t[i]] && m2[t[i]]!=s[i]) return false;
            
        }
         
        return true;
    }

//         for(int i=0;i<s.length();i++){
//             if(m1.find(s[i]) != m1.end() && m1[s[i]] != t[i] && m2[t[i]]!=s[i] && m2.find(t[i]) !=m2.end()){
//                 return false;
//             }
//             m1[s[i]]=t[i];
//             m2[t[i]]=s[i];
//         }
//         return true;
//     }
};