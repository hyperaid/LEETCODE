class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<pair<int,int>>maxheap;
        deque<pair<int,int>>minheap;
        int i=0;
        int j=0;
        int maxlen=0;
        int n=nums.size();
        // maxheap.push({nums[i],0});
        // minheap.push({nums[i],0});
        while(j<n){
            while(!minheap.empty() && minheap.back().first>nums[j]) minheap.pop_back();
            minheap.push_back({nums[j],j});
            while(!maxheap.empty() && maxheap.back().first<nums[j]) maxheap.pop_back();
            maxheap.push_back({nums[j],j});
            int diff=maxheap.front().first-minheap.front().first;
            while(i<j && diff>limit){
                i=min(minheap.front().second,maxheap.front().second)+1;
                while(!maxheap.empty() && maxheap.front().second<i) maxheap.pop_front();
                while(!minheap.empty() && minheap.front().second<i) minheap.pop_front();

                diff=maxheap.front().first-minheap.front().first;

            }
            maxlen=max(maxlen,j-i+1);
            j++;


        }
        return maxlen;
    }
};