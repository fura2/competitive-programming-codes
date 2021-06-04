#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	deque<int> D;
	rep(i,n){
		if(s[i]=='L'){
			D.emplace_front(i+1);
		}
		else if(s[i]=='R'){
			D.emplace_back(i+1);
		}
		else if(s[i]=='A'){
			if(D.size()==0){
				puts("ERROR");
			}
			else{
				printf("%d\n",D.front());
				D.pop_front();
			}
		}
		else if(s[i]=='B'){
			if(D.size()<=1){
				puts("ERROR");
			}
			else{
				int tmp=D.front();
				D.pop_front();
				printf("%d\n",D.front());
				D.pop_front();
				D.emplace_front(tmp);
			}
		}
		else if(s[i]=='C'){
			if(D.size()<=2){
				puts("ERROR");
			}
			else{
				int tmp1=D.front();
				D.pop_front();
				int tmp2=D.front();
				D.pop_front();
				printf("%d\n",D.front());
				D.pop_front();
				D.emplace_front(tmp2);
				D.emplace_front(tmp1);
			}
		}
		else if(s[i]=='D'){
			if(D.size()==0){
				puts("ERROR");
			}
			else{
				printf("%d\n",D.back());
				D.pop_back();
			}
		}
		else if(s[i]=='E'){
			if(D.size()<=1){
				puts("ERROR");
			}
			else{
				int tmp=D.back();
				D.pop_back();
				printf("%d\n",D.back());
				D.pop_back();
				D.emplace_back(tmp);
			}
		}
		else{
			if(D.size()<=2){
				puts("ERROR");
			}
			else{
				int tmp1=D.back();
				D.pop_back();
				int tmp2=D.back();
				D.pop_back();
				printf("%d\n",D.back());
				D.pop_back();
				D.emplace_back(tmp2);
				D.emplace_back(tmp1);
			}
		}
	}

	return 0;
}
