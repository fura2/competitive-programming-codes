#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; scanf("%d%d",&h,&w);

	int ans=0;
	rep(i,h){
		char s[101]; scanf("%s",s);
		rep(j,w) if(isdigit(s[j])) ans+=s[j]-'0';
	}
	printf("%d\n",ans);

	return 0;
}
