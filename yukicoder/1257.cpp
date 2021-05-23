#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,d,e,f; cin>>a>>b>>c>>d>>e>>f;
	if(multiset<int>{a,b,c}==multiset<int>{d,e,f}){
		puts("Yes\n2");
	}
	else{
		puts("No");
	}
	return 0;
}
