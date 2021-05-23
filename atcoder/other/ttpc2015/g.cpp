#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	int cnt[6]={};
	for(char c:s){
		if(c=='t'){
			if(cnt[1]>0){
				cnt[1]--;
				cnt[2]++;
			}
			else{
				cnt[0]++;
			}
		}
		else if(c=='i'){
			if(cnt[0]==0){
				if(cnt[2]==0){
					puts("No");
					return 0;
				}
				else{
					cnt[2]--;
					cnt[1]++;
					cnt[0]++;
				}
			}
			cnt[0]--;
			cnt[1]++;
		}
		else if(c=='e'){
			if(cnt[2]==0){
				puts("No");
				return 0;
			}
			cnt[2]--;
			cnt[3]++;
		}
		else if(c=='c'){
			if(cnt[3]==0){
				puts("No");
				return 0;
			}
			cnt[3]--;
			cnt[4]++;
		}
		else if(c=='h'){
			if(cnt[4]==0){
				puts("No");
				return 0;
			}
			cnt[4]--;
			cnt[5]++;
		}
		else{
			puts("No");
			return 0;
		}
	}
	puts(6*cnt[5]==s.length()?"Yes":"No");

	return 0;
}
