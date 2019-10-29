#include <bits/stdc++.h>
using namespace std;

string solve(string st, unordered_map<string, int>& mm){
	
	// this username has not been assigned
	if(mm.find(st) == mm.end()){
			//st has been seen now, new st request will receive st0
			mm[st] = 0;
			return st;
	}
	// increment counter till an unseen username has been found
	while(mm.find(st + to_string(mm[st])) != mm.end())
		mm[st]++;
	//the available username is seen now, by assigning 0
	mm[st + to_string(mm[st])] = 0;
	return st + to_string(mm[st]);
}

int main(){
	vector<string> requests = {"a","a","a1","a5","a4","a5","a5","a54","a5","a5","a57","a5","a5"};

	unordered_map<string, int> mm;
	for(auto &st: requests)
		cout<<solve(st, mm)<<endl;

	return 0;
}
