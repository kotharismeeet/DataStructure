#include<iostream>
using namespace std;

void reverseArray(int* arr, int size) {
	// Instead of making new copy of array swaping of element takes place
	for (int i=0;i<size/2;i++) {
		int temp=*(arr+i);
		*(arr+i)=*(arr+size-1-i);
		*(arr+size-1-i)=temp;
	}
	return;
}

int main() {
	cout<<"Print number of elements in Array"<<'\n';
	int n;
	cin>>n;
	int arr[n];
	for (int i=0;i<n;i++) {
		cout<<"Enter "<<i+1<<" element of Array."<<'\n';
		cin>>arr[i];
	}
	
	cout<<"Original Array"<<'\n';
	for (int i=0;i<n;i++) {
	    cout<<arr[i]<<" ";
	}
	cout<<'\n';
	
	reverseArray(arr,n);
	cout<<"After Reversal of Array!"<<'\n';
	for (int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
	cout<<'\n';
	cout<<"Time Complexity: O(N) and Space Complexity: O(1) as we are just swaping elements"<<'\n';
	return 0;
}