#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	// 3, 5, 7 はそれ自身で使うのが最適
	int ans=0;
	string t;
	rep(i,n){
		if(s[i]=='1' || s[i]=='9') t+=s[i];
		else ans++;
	}

	// 11, 19, 991 は素数
	// 19 -> 991 -> 11 の順で貪欲に作るのが最適
	int cnt1=0,cnt9=0;
	rep(i,t.length()){
		if(t[i]=='1'){
			cnt1++;
		}
		else{
			cnt9++;
			if(cnt1>=1){
				cnt1--;
				cnt9--;
				ans++;
			}
		}
	}
	ans+=min(cnt9/2,cnt1);
	cnt1-=min(cnt9/2,cnt1);
	ans+=cnt1/2;

	printf("%d\n",ans);

	return 0;
}
