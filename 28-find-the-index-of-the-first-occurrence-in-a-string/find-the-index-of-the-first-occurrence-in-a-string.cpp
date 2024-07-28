class Solution {
public:
    int strStr(string a, string n) {
        int j=0;
        for(int i=0;i<a.size();i++){
            cout<<i<<endl;
            if(a[i]==n[0]){
                // cout<<i<<endl;
                int index=i;
                while(j<n.size() && i<a.size() && a[i]==n[j]){
                    i++;
                    j++;
                }
                if(j==n.size()) return index;
                j=0;
                i=index;
                // cout<<"as";
            }
        }
        return -1;

    }
};