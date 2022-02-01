#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main() {
	cout<<"Enter number of elements"<<endl;
	int n;
	cin>>n;
	vector<int>v;
	map<int,int>m;
	for (int i=0;i<n;i++) {
		int t;
		cin>>t;
		m[t]++;
	}

	for (auto it: m) {
		while(it.second) {
			v.push_back(it.first);
			it.second--;
		}
	}

	cout<<"Sorted Elements"<<endl;

	for (auto it: v) cout<<it<<endl;
	return 0;
}