#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint X1[]={-1,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069,926,1756,1863,452,806,579,49,1548,1069};
lint X2[]={-1,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981,1759,1943,1657,1545,1570,1942,35,994,981};
lint Y1[]={-1,357937485,804984391,213641900,174761623,170022889,538498623,674127607,113497782,314733564,225775023,346252647,457324760,29129849,693356077,192849208,630714925,286142219,105392501,593245923,489386852,144620409,670068977,39119836,462344899,440356203,39704867,208660141,204627871,3584369,748063654,524452271,546309698,392225499,494339849,309573769,466606364,807334352,445583574,289934121,852602125,166979874,384778805,523808866,434652515,293177960,519076079,849580506,226086696,785326662,350868834,94158258,588649604,630946258,718657002,219860617,374651436,874835642,249356646,467412922,502939095,998327380,4074160,142824240,609972093,313604231,798344763,446099091,582632719,667790229,131447761,442223675,1121782,203986463,91616755,105961547,87881972,985214104,241381062,535577826,129703885,334246011,55016926,275178316,335438469,327738416,729838755,179901664,451620343,913744303,481618866,238446950,454379086,362240791,3675865,131827149,263437808,443470299,351491692,331380708,55588194,861063655,898756416,621125911,408653194,982828474,449468943,766827385,587397383,796476964,75879518,443412733,757816822,240620235,716012686,357805038,241802804,42849675,73139111,754220264,455463968,355968602,366197488,188509534,511327178,866335309,657766538,908294349,335340896,650166008,45870587,875691801,219943690,74474809,946559128,932882879,575969671,446429347,785252704,148756109,963409099,939765489,776286939,286716646,386019292,914473346,691610454,72704653,481637115,321321047,109444344,810307773,608547819,99912090,164746801,256244861,699260976,605504333,779547539,311183047,797585607,57487119,212907694,543829396,133921803,706163369,869995040,316670861,29661153,7916280,840275162,520364401,985873984,908381992,820556871,367625833,397298046,770471050,553841274,212919684,910655203,374457278,129275334,571392011,31203152,344344369,69262764,305773355,723209794,317017688,850946618,658521207,571778407,590848770,583419498,370525808,802233842,963639188,318767861,385897251,56028700,514166339,749377936,683572449,221957002,982615361,44412807,103302224,956833506,218033899,658555980,484514235,352459623,655427066,853981304};
lint Y2[]={-1,512340681,993830859,213100669,606327353,55354055,904967934,885244229,934545202,445409109,483876267,32749546,850045726,588319422,399202382,922306327,958369490,720548602,900172101,444008707,372917577,664052270,994729518,250863450,762774205,52055929,596562056,935468446,530281975,753961467,656631780,807710468,564568320,743891164,71822997,898358120,183345662,350939679,555482079,240759305,667819395,842511161,931374357,552237020,598068295,42121812,939812555,328405194,473351538,59586854,5085809,282203002,143436390,617871571,234183789,848755400,46398807,352204020,774571666,899965841,312380343,625175102,677061426,448696105,508159625,793770026,350976812,656715875,728420633,299453783,780698083,99826131,81829160,785292230,554335222,39319782,181144179,648474555,563561962,286527309,164510387,424397749,132175115,485114058,999932619,248924106,972200871,104388964,73692836,210191206,10236542,844541104,304292410,267412892,169989425,262985869,465711981,181870056,532446390,323131274,666238159,92247096,46879136,340490837,729378593,879183517,388359987,854741679,348611706,59218767,324192204,74227424,67690453,235491722,914902409,268085784,153038784,513743242,568581148,271125561,529010426,975474891,238587592,388326419,374789183,494878232,832407065,945929533,606150021,793884462,313439891,986797871,918228175,360399370,905235032,233012375,792628175,905899309,695707383,137158984,53849911,667553335,187829232,49621278,459173123,429605803,421170692,787150818,342248257,929063610,764664524,908442556,561202042,953631310,981935427,533547579,953064346,920857699,256583740,625640681,660413797,181704119,845644941,299596954,341101713,586872009,136981993,735635784,822121968,708430751,599744993,418028053,467787880,324509174,689990093,851558709,289805676,925412476,134958185,871376573,337447978,675522221,868930984,427753538,182661288,232706995,718006627,815022424,608788365,16206968,334321224,758243399,754931811,149669656,829626938,874542763,454513868,716654917,540475057,700764273,7388891,632392005,151120461,208383177,798421015,538282542,933859409,985480162,534033324,81300150,830799062,187950786,73532998,132850326,277046594};

int main(){
/*
	lint m=1999;
	lint a1=0,a2=1,a3;
	for(lint i=3;i<(1LL<<31);i++){
		a3=(a1*a1+a2*a2)%m;
		if(i%10000000==0){
			printf("%lld,",a1);
		}
		a1=a2;
		a2=a3;
	}
*/
	lint n,m; cin>>n>>m;

	if(n<3){
		puts(n==1?"0":"1");
		return 0;
	}
	if(n<10000000){
		lint a1=0,a2=1,a3;
		for(int i=3;i<=n;i++){
			a3=(a1*a1+a2*a2)%m;
			a1=a2;
			a2=a3;
		}
		printf("%lld\n",a3);
		return 0;
	}

	lint a1,a2,a3;
	if(m==1999){
		a1=X1[n/10000000];
		a2=X2[n/10000000];
	}
	else{
		a1=Y1[n/10000000];
		a2=Y2[n/10000000];
	}
	for(lint i=n/10000000*10000000;i<=n;i++){
		a3=(a1*a1+a2*a2)%m;
		a1=a2;
		a2=a3;
	}
	printf("%lld\n",a3);

	return 0;
}
