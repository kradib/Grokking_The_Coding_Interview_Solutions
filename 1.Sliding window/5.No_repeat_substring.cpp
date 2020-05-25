
//link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int maxl=0;
        map<char,int> mymap;
        int start=-1;
        int i;
        for(i=0;i<s.length();i++){
            if(mymap.find(s[i])==mymap.end()){
                mymap[s[i]]=i;
            }
            else{
                maxl=max(maxl,i-start-1);
                start=max(start,mymap[s[i]]);
                mymap[s[i]]=i;
            }
        }
        maxl=max(i-start-1,maxl);
        return maxl;
    }
};