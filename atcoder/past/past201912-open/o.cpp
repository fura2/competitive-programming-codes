#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	vector<pair<int,int>> ord(6*n);
	rep(i,n) rep(j,6) {
		int a; scanf("%d",&a);
		ord[6*i+j]={a,i};
	}

	sort(ord.begin(),ord.end());

	vector<double> ex(n,1);
	double ex_max=1;
	for(int i=6*n-1;i>=0;i--){
		int idx=ord[i].second;
		ex[idx]+=ex_max/6;
		ex_max=max(ex_max,ex[idx]);
	}
	printf("%.9f\n",ex_max);

	return 0;
}
