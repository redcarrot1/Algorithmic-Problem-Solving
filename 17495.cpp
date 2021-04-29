#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
using namespace std;

string map[12] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
string sheet[1001];

//거리합, 연주 방법, r위치, l위치
tuple<int, string, string, string> d[1001][2]; 

int findOct(string &str) {
	return (str[1]-'0');
}

string findx(string str) {
	str.erase(1, 1);
	return str;
}

int findDiff(string &str1, string &str2) {
	int st1, st2;
	string s1 = findx(str1);
	string s2 = findx(str2);
	
	for (int i = 0; i < 12; i++) {
		if (s1 == map[i]) st1 = i;
		if (s2 == map[i]) st2 = i;
	}

	int mapdiff = abs(st1 - st2);
	int octdiff = findOct(str1) - findOct(str2);

	if (octdiff == 0) return mapdiff;
	else if (st1 <= st2 && octdiff <= 0) return mapdiff - (12 * octdiff);
	else if (st1 >= st2 && octdiff <= 0) return -mapdiff-(12 * octdiff);
	else if (st1 <= st2 && octdiff >= 0) return 12 * octdiff - mapdiff;
	else if (st1 >= st2 && octdiff >= 0) return 12 * octdiff + mapdiff;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	string rx, lx; //현재 위치
	
	cin >> lx >> rx >> n;

	for (int i = 1; i <= n; i++) {
		cin >> sheet[i];
	}
	for (int i = 1; i <= n; i++) {
		if(findx(sheet[i]) == "E#"){
			sheet[i] = "F" + to_string(findOct(sheet[i]));
		}
		else if(findx(sheet[i]) == "B#") {
			sheet[i] = "C" + to_string(findOct(sheet[i])+1);
		}
	}

	//현재까지 이동한 거리합, 연주 방법, 현재 r위치, l위치
	d[0][0] = make_tuple(0, "", rx, lx);
	d[0][1] = make_tuple(0, "", rx, lx);
	

	int sum0, sum1, k, q;
	string how0, r0, l0, how1, r1, l1, next;

	for (int i = 1; i <= n; i++) {
		next = sheet[i];
		tie(sum0, how0, r0, l0) = d[i-1][0];
		tie(sum1, how1, r1, l1) = d[i-1][1];

		//오른손 2, 왼손 1
		//d[i-1][0] -> d[i][0]  VS  d[i-1][1] -> d[i][0]
		
		//오른손으로 치는 경우
		k = findDiff(r0, next); 
		q = findDiff(r1, next); 

		if (k+sum0 > q+sum1) {
			d[i][0] = make_tuple(q + sum1, how1 + "2 ", next, l1);
		}
		else {
			d[i][0] = make_tuple(k + sum0, how0 + "2 ", next, l0);
		}


		//왼손으로 치는 경우
		k = findDiff(l0, next);
		q = findDiff(l1, next);

		if (k + sum0 > q + sum1) {
			d[i][1] = make_tuple(q + sum1, how1 + "1 ", r1, next);
		}
		else {
			d[i][1] = make_tuple(k + sum0, how0 + "1 ", r0, next);
		}
	
	}


	for (int i = 1; i <= 10; i++) {
		cout << i<<":\n";
		cout<<get<0>(d[i][0])<<"   "<< get<0>(d[i][1])<<"\n";
		cout<<get<1>(d[i][0])<<"   "<< get<1>(d[i][1]) << "\n";
		cout<<get<2>(d[i][0])<<"   "<< get<2>(d[i][1]) << "\n";
		cout<<get<3>(d[i][0])<<"   "<< get<3>(d[i][1]) << "\n";
		cout << "\n";
	}

	if (get<0>(d[n][0]) > get<0>(d[n][1])) {
		cout << get<0>(d[n][1])<<"\n";
		cout << get<1>(d[n][1]);
	}
	else {
		cout << get<0>(d[n][0]) << "\n";
		cout << get<1>(d[n][0]);
	}

}