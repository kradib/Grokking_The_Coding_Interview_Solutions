//link: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int start=0,end=0;
        int n=s.length();
        map<char,int> mymap;
        while(end<n){
            mymap[s[end]]++;
            if(mymap.size()>k){
                mymap.erase(mymap.find(s[end]));
                break;
            }
            end++;
        }
        
        if(end==n)
            return n;
        int maxl=end-start;
        
        
        while(start<=end && end<n){
            while(start<=end && mymap.size()==k){
                if(mymap[s[start]]==1)
                 mymap.erase(mymap.find(s[start]));
                else
                    mymap[s[start]]--;
                start++;
            }
            while(end<n && mymap.size()<=k){
                mymap[s[end]]++;
                if(mymap.size()>k){
                    mymap.erase(mymap.find(s[end]));
                    break;
                }
                end++;
            }
            //cout<<end<<endl;
            maxl=max(maxl,end-start);
        }
        
        
        return maxl;
    }
};