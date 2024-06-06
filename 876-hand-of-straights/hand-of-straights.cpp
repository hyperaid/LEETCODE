class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mpp;
        for(auto i:hand){
            mpp[i]++;
        }
        for (auto i:mpp){
              if(mpp[i.first]>0){
                  for(int j=1;j<groupSize;j++){
                      mpp[i.first+j]-=mpp[i.first];
                      if(mpp[i.first+j]<0) return false;
                  }
              }
        }
        return true;

    }
};