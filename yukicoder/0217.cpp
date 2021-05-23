#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<vector<int>> solve_odd(int n){
	vector B(n,vector(n,0));
	int i=0,j=n/2;
	rep(k,n*n){
		B[i][j]=k+1;
		i=(i-1+n)%n;
		j=(j+1)%n;
		if(B[i][j]!=0){
			i=(i+2)%n;
			j=(j-1+n)%n;
		}
	}
	return B;
}

int main(){
	int n; scanf("%d",&n);

	vector B(n,vector(n,0));
	if(n%2==1){
		B=solve_odd(n);
	}
	else if(n%4==0){
		rep(i,n) rep(j,n) {
			if(i%4==j%4 || i%4+j%4==3) B[i][j]=i*n+j+1;
		}
		for(int i=n-1;i>=0;i--) for(int j=n-1;j>=0;j--) {
			if(i%4!=j%4 && i%4+j%4!=3) B[i][j]=(n-i-1)*n+(n-j-1)+1;
		}
	}
	else{
		auto C=solve_odd(n/2);
		rep(i,n/2) rep(j,n/2) C[i][j]=4*(C[i][j]-1);
		rep(i,n/2) rep(j,n/2) {
			// L
			if(i<n/4 || (i==n/4 && j!=n/4) || (i==n/4+1 && j==n/4)){
				B[2*i+0][2*j+0]=C[i][j]+4;
				B[2*i+0][2*j+1]=C[i][j]+1;
				B[2*i+1][2*j+0]=C[i][j]+2;
				B[2*i+1][2*j+1]=C[i][j]+3;
			}
			// U
			else if(i<=n/4+1){
				B[2*i+0][2*j+0]=C[i][j]+1;
				B[2*i+0][2*j+1]=C[i][j]+4;
				B[2*i+1][2*j+0]=C[i][j]+2;
				B[2*i+1][2*j+1]=C[i][j]+3;
			}
			// X
			else{
				B[2*i+0][2*j+0]=C[i][j]+1;
				B[2*i+0][2*j+1]=C[i][j]+4;
				B[2*i+1][2*j+0]=C[i][j]+3;
				B[2*i+1][2*j+1]=C[i][j]+2;
			}
		}
	}

	rep(i,n) rep(j,n) printf("%d%c",B[i][j],j<n-1?' ':'\n');

	return 0;
}
