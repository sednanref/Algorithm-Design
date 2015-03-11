#include <bits/stdc++.h>

using namespace std;

int t; 		//number of test cases
int m, n;   //matrix dimensions.
int matrix[250][250]; //Map as input.
string line; //line of the matrix.
vector <int> dp;	//structure of dp.
int max_value; //answer to the problem.


int take_max_left(int i, int j){
	if((j == 0)){
		if(dp[(i-1)*n] != -1){
			return dp[(i-1)*n] + matrix[i][j];
		}else{
			return -1;
		}
	}else{
		if(max(dp[((i-1)*n) + j], dp[i*n + (j - 1)]) != -1){
			return max(dp[((i-1)*n) + j], dp[i*n + (j - 1)]) + matrix[i][j];
		}else{
			return -1;
		}
	}
}

int take_max_right(int i, int j){
	if((j == n - 1)){
		if(dp[((i-1)*n) + j] != -1){
			return dp[((i-1)*n) + j] + matrix[i][j];
		}else{
			return -1;
		}
	}else{
		if(max(dp[((i-1)*n) + j], dp[i*n + (j + 1)]) != -1){
			return max(dp[((i-1)*n) + j], dp[i*n + (j + 1)]) + matrix[i][j];
		}else{
			return -1;
		}
	}
}

int main(){
	cin>>t; //read number of test cases.
	while(t--){
		cin>>m>>n;	//read dimensions of the matrix.
		dp.resize(m*n);
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


		//calculate max_value
		dp[0] = matrix[0][0];
		if(max_value < dp[0]){
			max_value = dp[0];
		}
		for(int i = 0; i < m; i++){
			if(i == 0){	//first line of the input;
				
				for(int j = 1; j < n; j ++){
					if(matrix[i][j] != -1){
						if(dp[j-1] != -1){
							dp[j] = dp[j - 1] + matrix[i][j];
							if(max_value < dp[j]){
								max_value = dp[j];
							}
						}else{
							dp[j] = -1;
						}
					}else{
						dp[j] = -1;
					}
				}
			}else{		//not first line
				if(i % 2 == 0){		//even
					for(int j = 0; j < n; j++){
						if(matrix[i][j] == -1){
							dp[i*n + j] = -1;	
						}else{
							dp[i*n + j] = take_max_left(i, j);
							if(max_value < dp[i*n + j]){
								max_value = dp[i*n + j];
							}
						}
					}
				}else{				//not even
					for(int j = n - 1; j >= 0; j--){
						if(matrix[i][j] == -1){
							dp[i*n + j] = -1;	
						}else{
							dp[i*n + j] = take_max_right(i, j);
							if(max_value < dp[i*n + j]){
								max_value = dp[i*n + j];
							}
						}
					}
				}
			}
		}
		/*cout<<"--------------"<<endl;
		for(int i = 0; i < m*n; i++){
			cout<<dp[i]<<" ";
		}
		cout<<endl<<"--------------"<<endl;*/
		cout<<max_value<<endl;
	}
	return 0;
}