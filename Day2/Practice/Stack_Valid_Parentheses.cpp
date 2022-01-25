#include<iostream>
#include<stack>
using namespace std;

/* Problem Statement -->
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 */

bool isValid(string s) {
    stack<char> st;
    for (int i=0;i<s.size();i++) {                        
        if(s[i]=='(' || s[i]=='[' || s[i]=='{') {
            st.push(s[i]);
        }           
        else if(!st.empty()) {
            if(st.top()=='(' && s[i]!=')') return false;
            else if(st.top()=='[' && s[i]!=']') return false;
            else if(st.top()=='{' && s[i]!='}') return false;
            st.pop();                
        }         
        else return false;
       	//cout<<i<<" "<<st.size()<<endl;
    }      
    if(!st.empty()) return false;
    return true;
}

int main() {
	string s;
	cin>>s;
	cout<<"For String "<<s<<":"<<isValid(s)<<endl;
	
	return 0;
}