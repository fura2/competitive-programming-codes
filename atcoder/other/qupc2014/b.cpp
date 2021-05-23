#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	string ans;
	rep(i,s.length()){
		int d=s[i]-'0';
		if(i!=s.length()-1){
			switch(d){
				case 0: if(!ans.empty() && ans.back()=='n') ans.pop_back(); ans+="nil"; break;
				case 1: ans+="un"; break;
				case 2: ans+="bi"; break;
				case 3: ans+="tri"; break;
				case 4: ans+="quad"; break;
				case 5: ans+="pent"; break;
				case 6: ans+="hex"; break;
				case 7: ans+="sept"; break;
				case 8: ans+="oct"; break;
				case 9: ans+="enn"; break;
			}
		}
		else{
			switch(d){
				case 0: if(!ans.empty() && ans.back()=='n') ans.pop_back(); ans+="nilium"; break;
				case 1: ans+="unium"; break;
				case 2: ans+="bium"; break;
				case 3: ans+="trium"; break;
				case 4: ans+="quadium"; break;
				case 5: ans+="pentium"; break;
				case 6: ans+="hexium"; break;
				case 7: ans+="septium"; break;
				case 8: ans+="octium"; break;
				case 9: ans+="ennium"; break;
			}
		}
	}
	ans[0]=toupper(ans[0]);
	cout<<ans<<'\n';

	return 0;
}
