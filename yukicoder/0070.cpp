#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int ans=0;
	rep(i,n){
		int h1,m1,h2,m2; scanf("%d:%d%d:%d",&h1,&m1,&h2,&m2);
		int s1=60*h1+m1;
		int s2=60*h2+m2;
		if(s2<s1) s2+=24*60;
		ans+=s2-s1;
	}
	printf("%d\n",ans);
	return 0;
}
