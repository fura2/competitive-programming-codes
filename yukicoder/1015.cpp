#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;


int main(){
	const int p[3]={1000,5000,10000};

	int n,m[3]; scanf("%d",&n);
	rep(i,3) scanf("%d",&m[i]);

	priority_queue<int> Q;
	rep(i,n){
		int a; scanf("%d",&a);
		Q.emplace(a+1);
	}

	for(int i=2;i>=0;i--){
		while(m[i]>0 && !Q.empty()){
			int a=Q.top(); Q.pop();
			int k=min(a/p[i],m[i]);
			if(k==0) k++;
			a-=p[i]*k;
			if(a>0) Q.emplace(a);
			m[i]-=k;
		}
	}

	puts(Q.empty()?"Yes":"No");

	return 0;
}
