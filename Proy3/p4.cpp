#include <bits/stdc++.h>

using namespace std;

int t; 		//number of test cases
int m, n;   //matrix dimensions.
char aux_c;

int main(){
	cin>>t;

	while(t--){
		cin>>m>>n;
		for(int i = 0; i < m; i++){
			for(int j = 0; i < n; j++){
				cin>>aux_c;
				cout<<aux_c;
			}
			cout<<endl;
		}
	}


	return 0;
}