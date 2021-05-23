#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

string md5(string str){
	unsigned int A0=0x67452301;
	unsigned int B0=0xEFCDAB89;
	unsigned int C0=0x98BADCFE;
	unsigned int D0=0x10325476;
	unsigned int s[64]={
		7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
		5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
		4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
		6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21
	};
	unsigned int K[64]={
		0xD76AA478, 0xE8C7B756, 0x242070DB, 0xC1BDCEEE,
		0xF57C0FAF, 0x4787C62A, 0xA8304613, 0xFD469501,
		0x698098D8, 0x8B44F7AF, 0xFFFF5BB1, 0x895CD7BE,
		0x6B901122, 0xFD987193, 0xA679438E, 0x49B40821,
		0xF61E2562, 0xC040B340, 0x265E5A51, 0xE9B6C7AA,
		0xD62F105D, 0x02441453, 0xD8A1E681, 0xE7D3FBC8,
		0x21E1CDE6, 0xC33707D6, 0xF4D50D87, 0x455A14ED,
		0xA9E3E905, 0xFCEFA3F8, 0x676F02D9, 0x8D2A4C8A,
		0xFFFA3942, 0x8771F681, 0x6D9D6122, 0xFDE5380C,
		0xA4BEEA44, 0x4BDECFA9, 0xF6BB4B60, 0xBEBFBC70,
		0x289B7EC6, 0xEAA127FA, 0xD4EF3085, 0x04881D05,
		0xD9D4D039, 0xE6DB99E5, 0x1FA27CF8, 0xC4AC5665,
		0xF4292244, 0x432AFF97, 0xAB9423A7, 0xFC93A039,
		0x655B59C3, 0x8F0CCC92, 0xFFEFF47D, 0x85845DD1,
		0x6FA87E4F, 0xFE2CE6E0, 0xA3014314, 0x4E0811A1,
		0xF7537E82, 0xBD3AF235, 0x2AD7D2BB, 0xEB86D391
	};

	string bin;
	for(char c:str) for(int i=7;i>=0;i--) bin+='0'+(c>>i&1);
	bin+='1';
	while(bin.length()<448) bin+='0';

	unsigned int M[16]={};
	rep(i,15) rep(j,4) rep(k,8) if(bin[32*i+8*j+k]=='1') M[i]|=1<<(8*j+7-k);
	M[14]=8*str.length();

	unsigned int A=A0,B=B0,C=C0,D=D0;
	rep(i,64){
		unsigned int F,g;
		if(i<16){
			F=(B&C)|(~B&D);
			g=i;
		}
		else if(i<32){
			F=(D&B)|(~D&C);
			g=(5*i+1)%16;
		}
		else if(i<48){
			F=B^C^D;
			g=(3*i+5)%16;
		}
		else{
			F=C^(B|~D);
			g=(7*i)%16;
		}
		F+=A+K[i]+M[g];
		A=D;
		D=C;
		C=B;
		B+=(F<<s[i])|(F>>(32-s[i]));
	}

	A0+=A; B0+=B; C0+=C; D0+=D;
	char tmp[33];
	sprintf(tmp,"%08x%08x%08x%08x",A0,B0,C0,D0);
	string res=tmp;
	rep(i,4){
		swap(res[  8*i],res[6+8*i]);
		swap(res[1+8*i],res[7+8*i]);
		swap(res[2+8*i],res[4+8*i]);
		swap(res[3+8*i],res[5+8*i]);
	}
	return res;
}

int main(){
	string s; cin>>s;
	cout<<md5(md5(s))<<'\n';
	return 0;
}
