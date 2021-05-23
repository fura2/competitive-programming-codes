#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; cin>>h>>w;
	int hist[128]={};
	rep(i,h){
		string s; cin>>s;
		rep(j,w) hist[s[j]]++;
	}

	if(h%2==0 && w%2==0){
		for(int c='a';c<='z';c++){
			if(hist[c]%4!=0) return puts("No"),0;
		}
		puts("Yes");
	}
	else if(h%2==0 || w%2==0){
		if(h%2==1) swap(h,w);

		int two=0;
		for(int c='a';c<='z';c++){
			if(hist[c]%2==1) return puts("No"),0;
			if(hist[c]%4==2) two++;
		}
		puts(two<=h/2?"Yes":"No");
	}
	else{
		int one=0;
		for(int c='a';c<='z';c++){
			if(hist[c]%2==1) one++;
		}
		if(one!=1) return puts("No"),0;

		for(int c='a';c<='z';c++){
			if(hist[c]%2==1) hist[c]--;
		}

		int two=0;
		for(int c='a';c<='z';c++){
			if(hist[c]%4==2) two++;
		}
		puts(two<=h/2+w/2?"Yes":"No");
	}

	return 0;
}
