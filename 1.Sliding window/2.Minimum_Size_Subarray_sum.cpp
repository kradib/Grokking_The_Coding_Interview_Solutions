
//link: https://leetcode.com/problems/minimum-size-subarray-sum/


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start=0;
        int end=0;
        int sum=0;
        int n=nums.size();
        while(end<n && sum<s){
            sum+=nums[end++];
        }
        if(sum<s)
            return 0;
        
        
        int minl=end-start;
        
        while(start<=end && end<n){
            
            while(start<=end && sum>=s){
                sum-=nums[start];
                start++;
            }
            minl=min(end-start+1,minl);
            
            while(end<n && sum<s){
                sum+=nums[end++];
            }
            
            minl=min(end-start,minl);
        }
        
        while(start<=end && sum>=s){
                sum-=nums[start];
                start++;
        }
        minl=min(end-start+1,minl);
        return minl;
        
    }
};