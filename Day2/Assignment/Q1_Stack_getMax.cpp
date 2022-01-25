#include<iostream>
#include<stack>

using namespace std;

void getMax() {
	//cout<<"Enter No of Queries!"<<endl;
	int n;
	cin>>n;
	stack<int>s,max;
	
	for (int i=0;i<n;i++) {
		int type;
		//cout<<"Press 1 to push in Stack, 2 to Pop and 3 to get Maximum from Stack!"<<endl;
		cin>>type;
		switch(type) {
			case 1:
				int x;
				cin>>x;
				//cout<<x<<" is pushed in Stack!"<<endl;
				s.push(x);
				if( (!max.empty() && x>max.top()) || max.empty()) max.push(x);
				break;
			case 2:
				if(s.empty()) {
					cout<<"Underflow in Stack!"<<endl;
					break;
				}
				//cout<<"Top Element --> "<<s.top()<<" is poped!"<<endl;
				if(!max.empty() && s.top()==max.top()) max.pop();
				s.pop();
				break;
			case 3:
			    //cout<<i<<endl;
				cout<<max.top()<<endl;
				break;
			default:
				cout<<"Enter a valid choice!"<<endl;
				break;
		}
	}
}

int main() {
	getMax();

	return 0;
}