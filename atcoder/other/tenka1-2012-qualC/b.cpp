#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int len=s.length();

	bool suit[128]={};
	vector<int> number(128,-1);
	suit['S']=suit['H']=suit['D']=suit['C']=true;
	rep(i,10) number['0'+i]=i;
	number['A']=1;
	number['J']=11;
	number['Q']=12;
	number['K']=13;

	vector<pair<char,int>> v;
	rep(i,len){
		char c=s[i];
		assert(suit[c]);
		int num=0;
		for(i++;i<len&&number[s[i]]!=-1;i++) num=10*num+number[s[i]];
		v.emplace_back(c,num);
		i--;
	}

	vector<pair<char,int>> ans(60);
	for(char c0:{'S','H','D','C'}){
		vector<pair<char,int>> res;
		int cnt=0;
		for(auto [c,num]:v){
			if(c==c0 && (num==1 || 10<=num)){
				cnt++;
				if(cnt==5) break;
			}
			else{
				res.emplace_back(c,num);
			}
		}
		if(cnt==5 && ans.size()>res.size()) ans=res;
	}

	if(ans.empty()){
		puts("0");
		return 0;
	}

	for(auto [c,num]:ans){
		putchar(c);
		if     (num== 1) putchar('A');
		else if(num==11) putchar('J');
		else if(num==12) putchar('Q');
		else if(num==13) putchar('K');
		else             printf("%d",num);
	}
	puts("");

	return 0;
}
