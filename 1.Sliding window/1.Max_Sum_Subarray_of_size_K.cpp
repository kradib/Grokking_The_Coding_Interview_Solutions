
//Problem link:https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k/0

#include <bits/stdc++.h>
using namespace std;



int my(vector<int> arr,int n, int k){
    int maxsum=0;
    int cursum=0;
    for(int i=0;i<k;i++)
    cursum+=arr[i];
    
    
    maxsum=cursum;
    
    for(int i=k;i<n;i++){
        cursum-=arr[i-k];
        cursum+=arr[i];  
        maxsum=max(maxsum,cursum);
    }
    
    
    return maxsum;

}
int main()
 {
	int t,n,item,k;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d %d",&n,&k);
        vector<int> a;
        for(int j=0;j<n;j++){
        scanf("%d",&item);
        a.push_back(item);
        }
        
        cout<<my(a,n,k)<<endl;
    }

	return 0;
}