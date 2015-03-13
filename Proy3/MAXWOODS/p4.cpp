#include <bits/stdc++.h>

using namespace std;

int t; 		//number of test cases
int m, n;   //matrix dimensions.
int matrix[250][250]; //Map as input.
string line; //line of the matrix.
int dp[250];	//structure of dp.
int max_value; //answer to the problem.


int take_max_left(int i, int j){
	if(matrix[i][j] == -1){
		return -1;
	}else{
		if(j == 0){
			if(dp[j] == -1){
				return -1;
			}else{
				return matrix[i][j] + dp[j];
			}
		}else{
			if(max(dp[j], dp[j -1]) == -1){
				return -1;
			}else{
				return max(dp[j], dp[j -1]) + matrix[i][j];
			}
		}
	}
}

int take_max_right(int i, int j){
	if(matrix[i][j] == -1){
		return -1;
	}else{
		if(j == n - 1){
			if(dp[j] == -1){
				return -1;
			}else{
				return matrix[i][j] + dp[j];
			}
		}else{
			if(max(dp[j], dp[j + 1]) == -1){
				return -1;
			}else{
				return max(dp[j], dp[j + 1]) + matrix[i][j];
			}
		}
	}
}

int main(){
	cin>>t; //read number of test cases.
	while(t--){
		cin>>m>>n;	//read dimensions of the matrix.
		memset(dp, -1, sizeof(dp));
		max_value = 0;
		memset(matrix, 0, sizeof(matrix));
		//fill the matrix
		for(int i = 0; i < m; i++){
			cin>>line;
			for(int j = 0; j < n ; j++){
				if(line[j] == '0'){
					matrix[i][j] = 0;
				}else if (line [j] == 'T'){
					matrix[i][j] = 1;
				}else if(line [j] == '#'){
					matrix[i][j] = -1;
				}
			}
		}



		dp[0] = matrix[0][0];
		//calculate max_value
		if(max_value < dp[0]){
			max_value = dp[0];
		}
		//check first row
		for(int j = 1; j < n; j++){
			if(dp[j-1] == -1){
				dp[j] = -1;
			}else{
				if(matrix[0][j] == -1){
					dp[j] = -1;
				}else{
					dp[j] = dp[j - 1] + matrix[0][j];
					if(max_value < dp[j]){
						max_value = dp[j];
					}
				}
			}
		}
		
		//check the rest
		for(int i = 1; i < m; i++){
			if(i % 2 != 0){
				for(int j = n-1; j >= 0; j--){
					if(matrix[i][j] != -1){
						dp[j] = take_max_right(i, j);
						if(max_value < dp[j]){
							max_value = dp[j];
						}
					}else{
						dp[j] = -1;
					}
				}
			}else{
				for(int j = 0; j < n; j++){
					if(matrix[i][j] != -1){
						dp[j] = take_max_left(i, j);
						if(max_value < dp[j]){
							max_value = dp[j];
						}
					}else{
						dp[j] = -1;
					}
				}
			}
			
		}


		cout<<max_value<<endl;
	}
	return 0;
}