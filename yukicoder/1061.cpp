#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<int> solve2(int n);

vector<int> solve1(int n){
	if(n==1) return {0,0,0};
	if(n==5) return {0,0,0,4,1,1,4,1,2,3,3,2,2,4,3};

	vector<int> res(3*n);
	if(n%2==1){
		int idx=0;
		for(int a:solve1(n/2)){
			res[idx++]=a;
		}
		for(int i=n-1;i>=n/2;i--){
			res[idx++]=i;
			res[idx++]=i;
		}
		for(int i=n-1;i>=n/2;i--){
			res[idx++]=i;
		}
	}
	else{
		int idx=0;
		for(int i=n/2;i<n;i++){
			res[idx++]=i;
		}
		res[idx++]=n-1;
		for(int i=n/2;i<n-1;i++){
			res[idx++]=i;
			res[idx++]=i;
		}
		int idx2=idx+1;
		for(int a:solve2(n/2)){
			res[idx++]=a;
		}
		res[idx2]=n-1;
	}
	return res;
}

vector<int> solve2(int n){
	if(n==3) return {1,-1,1,2,0,1,0,2,0,2};
	if(n==4) return {1,-1,1,3,3,1,0,2,3,0,2,2,0};

	vector<int> res(3*n+1);
	if(n%2==1){
		int idx=0;
		for(int a:solve2(n/2)){
			res[idx++]=a;
		}
		for(int i=n-1;i>=n/2;i--){
			res[idx++]=i;
			res[idx++]=i;
		}
		for(int i=n-1;i>=n/2;i--){
			res[idx++]=i;
		}
	}
	else{
		int idx=0;
		for(int i=n-1;i>=n/2;i--){
			res[idx++]=i;
			res[idx++]=i;
		}
		res[idx++]=n-1;
		for(int i=n-1;i>=n/2;i--){
			res[idx++]=i;
		}
		for(int a:solve1(n/2)){
			res[idx++]=a;
		}
	}
	return res;
}

int main(){
	int n; scanf("%d",&n);

	if(n==2) return puts("-1"),0;

	auto ans=solve1(n);
	rep(i,3*n) printf("%d%c",ans[i],i<3*n-1?' ':'\n');

	return 0;
}
