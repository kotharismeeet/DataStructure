#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/*
Problem Statement
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram
https://leetcode.com/problems/largest-rectangle-in-histogram/
 */

int largestRectangleArea(vector<int>& heights) {
    int maxArea=0;
    stack<int>st;
       
     for (int i=0;i<=heights.size();i++) {
        while(!st.empty() && (i==heights.size() || heights[st.top()]>heights[i])) {
            int height = heights[st.top()];
            st.pop();
            int width;
            if(st.empty()) width=i;
            else width=i-st.top()-1;
            maxArea=max(maxArea,width*height);
        }
        st.push(i);
    }
    return maxArea;
}

int main () {
	vector<int>heights={2,1,5,6,2,3};
	cout<<largestRectangleArea(heights)<<endl;
	return 0;
}