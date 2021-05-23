#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	deque<char> D;
	rep(i,n){
		int t;
		char c; scanf("%d %c",&t,&c);
		if(t==0) D.emplace_back(c);
		else     D.emplace_front(c);
	}

	rep(i,D.size()) putchar(D[i]); puts("");

	return 0;
}
