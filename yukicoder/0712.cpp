#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	int ans=0;
	rep(i,h){
		string s; cin>>s;
		ans+=count(s.begin(),s.end(),'W');
	}
	printf("%d\n",ans);
	return 0;
}
