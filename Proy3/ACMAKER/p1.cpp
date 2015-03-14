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


int recursion(int i, int j){
	

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
			//Line without the insignificant words.
			cleaned_line.clear();
			for(int i = 0; i < words.size() - 1; i++){
				cleaned_line = cleaned_line + words[i] + " ";
			}

			cleaned_line =  cleaned_line + words[words.size() - 1];
			
			cout<<cleaned_line<<endl;
			n_letters = abbreviation.size();
			n_words = words.size();
			cout<<n_letters<<" "<<n_words<<endl;
		}
		
	}	
	return 0;
}