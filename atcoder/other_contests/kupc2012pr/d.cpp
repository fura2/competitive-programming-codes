#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

random_device seed_gen;
mt19937 rng(seed_gen());

int main(){
	int n; scanf("%d",&n);
	vector A(n,vector(n,0));
	vector B(n,vector(n,0));
	vector C(n,vector(n,0));
	rep(i,n) rep(j,n) scanf("%d",&A[i][j]);
	rep(i,n) rep(j,n) scanf("%d",&B[i][j]);
	rep(i,n) rep(j,n) scanf("%d",&C[i][j]);

	rep(_,5){
		vector<lint> x(n);
		rep(i,n) x[i]=rng()%1000;

		vector<lint> v1(n),v2(n),v3(n);
		rep(i,n) rep(j,n) v1[i]+=B[i][j]*x[j];
		rep(i,n) rep(j,n) v2[i]+=A[i][j]*v1[j];
		rep(i,n) rep(j,n) v3[i]+=C[i][j]*x[j];
		if(v2!=v3){
			puts("NO");
			return 0;
		}
	}
	puts("YES");

	return 0;
}
