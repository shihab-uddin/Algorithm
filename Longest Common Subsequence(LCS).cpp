/**
Longest Common Subsequence using Memoization approach
Branch and Bound Technique
*/
#include<bits/stdc++.h>
using namespace std;

string A = "bdg";
string B = "abcdefg";
int L[50][50];

int m = 40;

int subproblem(int i, int j){
	if (L[i][j] < 0){
	    if (A[i] == '\0' || B[j] == '\0'){
            L[i][j] = 0;
	    }
	    else if (A[i] == B[j]){
            L[i][j] = 1 + subproblem(i+1, j+1);
	    }
	    else{
            L[i][j] = max(subproblem(i+1, j), subproblem(i, j+1));
	    }
	}
	return L[i][j];
}



int lcs_length(){
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= m; j++){
            L[i][j] = -1;
        }
    }
    return subproblem(0, 0);
}

int main(){

    cout<<lcs_length();

    return 0;
}
