#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int cnt[14]={};
	rep(i,5){
		int a; cin>>a;
		cnt[a]++;
	}

	int c2=count(cnt,cnt+14,2);
	int c3=count(cnt,cnt+14,3);

	if     (c3==1) puts(c2==1?"FULL HOUSE":"THREE CARD");
	else if(c2==2) puts("TWO PAIR");
	else if(c2==1) puts("ONE PAIR");
	else           puts("NO HAND");

	return 0;
}
