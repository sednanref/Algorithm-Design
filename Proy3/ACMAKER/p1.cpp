#include <bits/stdc++.h>

using namespace std;

int t = 1;	//test case
string insignificant_w;			//a insignificant word.
set<string> insignificant_set; //set with the insignificant words.
string line;	//The whole line of a case. 
string word;	//a word of the line.
vector<string> words;	//the words of the line.
string abbreviation;    //abbreviation of each case.
string abbreviation_lower; //abbreviation in lower case.
string cleaned_line;	//line without insignificant words.
int n_words;		//number of words.
int n_letters;		//number of letters of the acronym.
int dp[150][150];	//dp structure

int recursion(int w, int l, int w_pos){

	if(dp[w][l] != -1){
		return dp[w][l];
	}

	//the word is ready
	if((w_pos > words[w].size()){
		//if it is da last word.
		if(w == words.size()){
			return 0;
		}
		//if not.. just go to the next word.
		dp[w][l] = recursion(w+1, l, 0);
		return dp[w][l];
	}

	

	
	if(dp[w][l] == -1){
			
	}
	return dp[w][l];

}

int main(){
	while(true){
		cin>>t;		//read number of insignifant words.
		if(t == 0) break;
		insignificant_w = "";
		insignificant_set.clear();

		/*Reading the insignificant words*/
		for(int i = 0; i < t; i++){
			cin>>insignificant_w;
			insignificant_set.insert(insignificant_w);
		}

		//read a \n, I really don't know why... but it works.
		getline(cin, line);

		while(true){
			getline(cin, line);			
			/*this is for buffer errors, sometimes it gets an empty line*/
			/*if(line.compare("") == 0){
				continue;
			}*/
			/*if the line is the last case, go to the other test case*/
			if(line.compare("LAST CASE") == 0){
				break;
			}

			istringstream iss(line);
			word.clear();
			words.clear();
			//get the abbreviation of the case.
			getline(iss, abbreviation, ' ');

			//fill words with the significant words.
			while(true){
				if(getline(iss, word, ' ') == 0) break;
				if(insignificant_set.find(word) == insignificant_set.end()){
					words.push_back(word);
				}
			}
			abbreviation_lower = abbreviation;
			//Transform the abbreviation to lower case.
			transform(abbreviation_lower.begin(), abbreviation_lower.end(), 
					  abbreviation_lower.begin(), ::tolower);
			
			memset(dp, -1, sizeof(dp));
			n_words = words.size();
			n_letters = abbreviation.size();
			int answer = recursion(0, 0, 0);
			cout<<answer<<endl;				
	
		}
		
	}	
	return 0;
}