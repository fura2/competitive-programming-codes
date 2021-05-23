#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

string s;
int cnt[128];

int idx;

char person(){
	assert(idx<s.length() && islower(s[idx]));
	return s[idx++];
}

char winner(){
	assert(idx<s.length());
	if(s[idx]=='['){
		idx++;
		char c1=winner();
		assert(idx<s.length() && s[idx]=='-');
		idx++;
		char c2=winner();
		assert(idx<s.length() && s[idx]==']');
		idx++;
		if(cnt[c1]==0 && cnt[c2]>0){
			cnt[c2]--;
			return c2;
		}
		else if(cnt[c1]>0 && cnt[c2]==0){
			cnt[c1]--;
			return c1;
		}
		else{
			puts("No");
			exit(0);
		}
	}
	else{
		return person();
	}
}

int main(){
	cin>>s;
	while(1){
		char c;
		int x; cin>>c>>x;
		if(cin.eof()) break;
		cnt[c]=x;
	}

	winner();

	puts(count(cnt,cnt+128,0)==128?"Yes":"No");

	return 0;
}
