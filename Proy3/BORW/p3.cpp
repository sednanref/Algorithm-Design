#include <bits/stdc++.h>
#define MAX 250
using namespace std;


int seq[MAX];
int n;
int minimun = -1000001;
int maximun = 1000001;
int dp[MAX][MAX][MAX];
int answer;

int recursion(int index, int to_upper, int to_lower){
	if(dp[index][to_upper][to_lower] != -1){
		return dp[index][to_upper][to_lower];
	}
	//Arrived to the final of the sequence.
	if(index == n){
		return 0;
	}
	//if the value in the sequence is greater than the "greatest value" of the
	//incremental sequence.
	if(seq[index] > seq[to_upper]){
		dp[index][to_upper][to_lower] = recursion(index + 1, index, to_lower);
	}
	//if the value in the sequence is lower than the "lowest value" of the
	//decremental sequence.
	if(seq[index] < seq[to_lower]){
		if(dp[index][to_upper][to_lower] != -1){
			//if it has a value, see if the value is optimal, or not coloring is a better idea.
			dp[index][to_upper][to_lower] = min(recursion(index + 1, to_upper, index), 
											dp[index][to_upper][to_lower]);
		}else{
			//if it has not a value yet, go and find it.
			dp[index][to_upper][to_lower] = recursion(index + 1, to_upper, index);
		}
	}

	//if the value is not in the incremental sequence or in the decremental one...
	//and it has a value.
	if(dp[index][to_upper][to_lower] != -1){
		//see if the value is optimal, or not coloring is a better idea.
		dp[index][to_upper][to_lower] = min(1 + recursion(index + 1, to_upper, to_lower), 
											dp[index][to_upper][to_lower]);
	//if it has not a value yet in the dp...
	}else{
		//it is not colored, so the value is 1 more the value of the rest of the sequence...
		dp[index][to_upper][to_lower] = 1 + recursion(index + 1, to_upper, to_lower);
	}



	return dp[index][to_upper][to_lower];
}


int main(){
	minimun = -1000001;
	maximun = 1000001;
	
	seq[MAX-1] = minimun;
	seq[MAX-2] = maximun;

	while(1){
		cin>>n;

		if(n == -1){
			return 0;
		}
		for(int i = 0; i < n; i++){
			cin>>seq[i];
		}

		memset(dp, -1, sizeof(dp));
		answer = recursion(0, MAX-1, MAX-2);

		cout<<answer<<endl;		
	}


	
}