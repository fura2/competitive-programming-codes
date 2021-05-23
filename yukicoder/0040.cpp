#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<int> solve(vector<int> a){
	if(a.empty()) return a;
	if(a.back()==0) return solve(vector<int>(a.begin(),--a.end()));
	int d=a.size()-1;
	if(d<=2) return a;

	vector<int> b(d+1);
	rep(i,d+1) b[i/3+i%3]+=a[i];
	return solve(b);
}

int main(){
	int d; scanf("%d",&d);
	vector<int> a(d+1);
	rep(i,d+1) scanf("%d",&a[i]);

	a=solve(a);
	if(a.empty()){
		puts("0\n0");
	}
	else{
		printf("%lu\n",a.size()-1);
		rep(i,a.size()) printf("%d%c",a[i],i<a.size()-1?' ':'\n');
	}

	return 0;
}
