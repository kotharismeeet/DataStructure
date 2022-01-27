#include<iostream>
#include<map>
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

void minimizeAverageWaitingTime(int n,map<int,int> priority) {
	int time=0;
	float ans=0;
	//priority has sorted orders by task time 
	map<int,int>::iterator it;
	for(it= priority.begin();it!=priority.end();) {		
		// if not arrived find first smallest task
		while(it!=priority.end() && it->second > time) {
		    //cout<<"Finding smallest task"<<endl;
		    it++;
		}
		/*cout<<"Pre debug"<<endl;
		cout<<"Task has Arrived"<<it->second<<" "<<"Time Elapsed"<<time<<endl;*/
		// arived with smallest task
		if(it->second <= time) {
			ans += time - it->second + it->first;
			time += it->first;
			// deleting from hashmap 
			priority.erase(it);
			it=priority.begin();
		}
		else time++;
		/*cout<<"Post debug"<<endl;
		cout<<ans<<" "<<time<<endl;
		for (auto itt: priority) cout<<itt.first<<" "<<itt.second<<endl;
		cout<<endl;*/
	}
	//cout<<ans<<endl;
	cout<<"Average waiting Time will be "<<ceil((float)ans/n);
}

int main() {
	int n;
	cin>>n;
	map<int,int>priority;
	for (int i=0;i<n;i++) {
		int t,l;
		cin>>t>>l;		
		priority[l]=t;
	}
	minimizeAverageWaitingTime(n,priority);
	return 0;
}