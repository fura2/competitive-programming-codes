#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	int cnt=0,mx=0;
	for(char c:s){
		if(c=='2') cnt++;
		else       cnt--;
		mx=max(mx,cnt);
		if(cnt<0){
			puts("-1");
			return 0;
		}
	}
	printf("%d\n",cnt==0?mx:-1);

	return 0;
}
