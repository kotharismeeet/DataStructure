#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;

/*
Problem Statement
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above
 */

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int>s;
    map<int,int>nge;
        
    for (int i=nums2.size()-1;i>=0;i--) {
        if(!s.empty() && s.top()>nums2[i]) {
            nge[nums2[i]]=s.top();
        }
        else {
            while(!s.empty() && s.top()<=nums2[i]) s.pop();
            if(!s.empty()) nge[nums2[i]]=s.top();
            else nge[nums2[i]]=-1;
        }
        s.push(nums2[i]);            
    }
        
    vector<int>ans;
    for (int i=0;i<nums1.size();i++) {            
        int temp=nge[nums1[i]];
        ans.push_back(temp);
    }
    return ans;
}

int main() {
	vector<int>nums1={4,1,2};
	vector<int>nums2={1,3,4,2};
    vector<int>ans=nextGreaterElement(nums1,nums2);
    for(auto it:ans) {
        cout<<it<<"  ";
    }

	return 0;
}