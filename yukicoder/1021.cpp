#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	deque<int> D(n);
	rep(i,n) scanf("%d",&D[i]);

	string s; cin>>s;
	for(char c:s){
		if(c=='L'){
			int a=D.front();
			D.pop_front();
			D.front()+=a;
			D.emplace_back(0);
		}
		else{
			int a=D.back();
			D.pop_back();
			D.back()+=a;
			D.emplace_front(0);
		}
	}

	rep(i,n) printf("%d%c",D[i],i<n-1?' ':'\n');

	return 0;
}
