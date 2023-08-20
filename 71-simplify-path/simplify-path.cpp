// class Solution {
// // public:
//     string simplifyPath(string path) {
//         stack<string> s;
//         string temp;
//         for(int i=0;i<path.length();i++){
//             if(path[i]=='/'){
//                 continue;
//             }
//             while(path.length()>i && path[i]!='/'){
//                 temp+=path[i];
//                 i++;
//             }
//             if(temp=="."){
//                 continue;
//             }
//             else if(temp==".."){
//                 if(!s.empty()){
//                     s.pop();
//                 }
//             }
//             else{
//                 s.push(temp);
//                 // temp="";
//             }
//         }
//         string res="";
//         while(!s.empty()){
//             res = "/" + s.top() + res;
//             s.pop();
//         }
//         if(res.size() == 0)
//             return "/";
//         return res;
//     }
// };

class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> st;
        string res;
        for(int i = 0;  i<path.size(); ++i){
            if(path[i] == '/')    
                continue;
            string temp;
            while(i < path.size() && path[i] != '/'){
                temp += path[i];
                ++i;
            }
            if(temp == ".")
                continue;
            else if(temp == ".."){
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(temp);
        }
        while(!st.empty()){
            res = "/" + st.top() + res;
            st.pop();
        }
        if(res.size() == 0)
            return "/";
        return res;
    }
};