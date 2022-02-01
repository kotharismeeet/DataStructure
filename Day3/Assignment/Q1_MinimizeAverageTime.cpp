#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
/*
Testcase 1: 
3
0 3
1 9
2 6
ANS=9
Testcase : 2
3
0 3
1 9
4 6
ANS=10
*/

void minimizeAverageWaitingTime(int n,map<int,vector<int>> priority) {
	int time=0;
	float ans=0;
	//priority has sorted orders by task time 
	map<int,vector<int>>::iterator it;
	for(it= priority.begin();it!=priority.end();) {		
		// if not arrived find first smallest task
		while(it!=priority.end() && it->second[0] > time) {
		    cout<<"Finding smallest task"<<endl;
		    it++;
		}
		//cout<<"Pre debug"<<endl;
		cout<<"Task has Arrived at "<<it->second[0]<<" "<<"Time Elapsed is "<<time<<endl;
		// arived with smallest task
		if(it->second[0] <= time) {
			ans += time - it->second[0] + it->first;
			time += it->first;
			// deleting from hashmap 
			it->second.erase(it->second.begin());
			if(it->second.size() == 0) priority.erase(it);
			it=priority.begin();
		}
		else time++;
		//cout<<"Post debug"<<endl;
		cout<<ans<<" "<<time<<endl;
		/*for (auto itt: priority) cout<<itt.first<<" "<<itt.second<<endl;
		cout<<endl;*/
	}
	//cout<<ans<<endl;
	cout<<"Average waiting Time will be "<<ceil((float)ans/n);
}

int main() {
	int n;
	cin>>n;
	map<int,vector<int>>priority;
	for (int i=0;i<n;i++) {
		int t,l;
		cin>>t>>l;		
		priority[l].push_back(t);
	}
	for (auto it: priority) {
	    sort(it.second.begin(),it.second.end());
	}
	/*for (auto it: priority) {
	    cout<<it.first<<":";
	    for(auto itt: it.second) cout<<itt<<" ";
	    cout<<endl;
	}*/
	minimizeAverageWaitingTime(n,priority);
	return 0;
}