#include <iostream>
#include <unordered_map>
#include<map>

using namespace std;

int main() {
    
    unordered_map<int,int>m;
    m.insert({1,3});
    m.insert({1,4});
    unordered_map<int,int>::hasher fn = m.hash_function();
    cout<<"Behaviour of Unordered map"<<endl;
    cout<<fn(3)<<" "<<fn(4)<<endl;
    for(auto it: m) cout<<it.first<<" "<<it.second<<endl;
    
    multimap<int,int>mm;
    mm.insert({1,3});
    mm.insert({1,4});
    mm.insert({-1,0});
    cout<<"Behaviour of Multimap"<<endl;
    for(auto it: mm) cout<<it.first<<" "<<it.second<<endl; 
    cout<<"Insertion Complexity is O(logN)"<<endl;
    
    unordered_multimap<int,int>unmm;
    unmm.insert({1,3});
    unmm.insert({1,4});
    unordered_map<int,int>::hasher fn1 = unmm.hash_function();
    cout<<"Behaviour of Unordered Multimap"<<endl;
    cout<<fn1(3)<<" "<<fn1(4)<<endl;
    for(auto it: unmm) cout<<it.first<<" "<<it.second<<endl;
    cout<<"Limitation : Not order specific as well as no function for sorting"<<endl;
    return 0;    
}