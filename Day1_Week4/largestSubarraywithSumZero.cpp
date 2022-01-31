#include<iostream>
#include<vector>
#include<map>
using namespace std;

int largestSubarraywithSumZero(vector<int>& nums, int k) {
    int n=nums.szie(),sum=0,ans=0;
    map<int,int>m;
    for (int i=0;i<n;i++) {
        sum += nums[i];
        if(!sum) ans=i+1;
        else {
            if(m.find(sum)) {
                ans = max(ans,i-m[sum])
            }
            else {
                m[sum]=i;
            }
        }            
    }
    return ans;
}

int main () {
    
    return 0;
}