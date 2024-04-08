class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int c1=0;
        int c2=0;
        for(auto it:students){
            if(it==1) c1++;
            else c2++;
        }
        for(int i=0;i<students.size();i++){
            if(sandwiches[i]==1){
                if(c1>0) c1--;
                else break;
            }
            else {
                if(c2>0) c2--;
                else break;
            }
        }
        return c1+c2;
    }
};