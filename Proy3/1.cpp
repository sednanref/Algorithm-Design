#include <bits/stdc++.h>

using namespace std;

int t = 1;	//test case
string insignificant_w;
vector<string> insignificant_set;
string line; 
vector<string> words;

/*Functions to split string into a vector*/
vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

int main(){
	while(true){
		cin>>t;
		if(t == 0) break;
		insignificant_w = "";
		insignificant_set.resize(150);
		cout<<t<<endl;
		/*Reading the insignificant words*/
		for(int i = 0; i < t; i++){
			cin>>insignificant_w;
			insignificant_set[i] = insignificant_w;
		}


		while(true){
			
			getline(cin, line);
			/*this is for buffer errors, sometimes it gets an empty line*/
			if(line.compare("") == 0){
				continue;
			}
			/*if the line is the last case, go to the other test case*/
			if(line.compare("LAST CASE") == 0){
				cout<<line<<endl;
				break;
			}

			cout<<line<<endl;
			words = split(line, ' ');

			for(int i = 0; i < words.size(); i++){
				cout<<words[i]<<endl;
			}
			/*int i;
			stringstream ssin(line);
    		while (ssin.good() && i < 150){
        		ssin >> words[i];
	        	++i;
    		}
    		for(int i = 0; i < 150; i++){
        		cout << words[i] << endl;
    		}*/
		}
		
	}	
	return 0;
}