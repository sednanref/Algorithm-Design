#include <bits/stdc++.h>

using namespace std;

int t = 1;	//test case
string insignificant_w;
vector<string> insignificant_set;

int main(){
	while(t){
		cin>>t;
		insignificant_w = "";
		insignificant_set.clear();

		/**/
		for(int i = 0; i < t; i++){
			cin>>insignificant_w;
			insignificant_set.push_back(insignificant_w);
		}

		for(int i = 0; i < t; i++){
			cout<<insignificant_set[i]<<endl;
		}

	}	
	return 0;
}