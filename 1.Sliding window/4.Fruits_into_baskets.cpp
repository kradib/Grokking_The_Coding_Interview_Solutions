
//link: https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        map<int,int> mymap;
        int n=tree.size();
        int start=0,end=0;
        
        while(end<n){
            
            mymap[tree[end]]++;
            if(mymap.size()>2){
                mymap.erase(tree[end]);
                break;
            }
            end++;
        }
        
        if(end==n)
            return n;
        
        
        int maxl=end-start;
        
        while(start<=end && end<n){
            
            while(start<=end && mymap.size()==2){
                
                if(mymap[tree[start]]==1)
                    mymap.erase(tree[start]);
                else
                    mymap[tree[start]]--;
                
                start++;
            }
            
            while(end<n && mymap.size()<=2){
                mymap[tree[end]]++;
                if(mymap.size()>2){
                    mymap.erase(tree[end]);
                    break;
                }
                end++;
            }
            
            maxl=max(maxl,end-start);
        
        }
        
        
        return maxl;
        
        
    }
};