#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<bool> er;
void sieve(int n){
	er.assign(n+1,true);
	er[0]=er[1]=false;
	for(int i=2;i*i<=n;i++) if(er[i]) for(int j=i*i;j<=n;j+=i) er[j]=false;
}

int main(){
	sieve(1e6);

	int n; cin>>n;

	int ans=0;
	rep(i,n){
		int x,g; cin>>x;
		if(x==7) g=3;
		else     g=(er[x-2]?2:1);
		ans^=g;
	}
	cout<<(ans>0?"An":"Ai")<<endl;

	return 0;
}
