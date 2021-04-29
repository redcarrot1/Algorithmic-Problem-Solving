#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct person {
	string name;
	int korean;
	int english;
	int math;
}person;

bool compare(person a, person b) {
	if (a.korean == b.korean) {
		if (a.english == b.english) {
			if (a.math == b.math) {
				return a.name < b.name; //오름차순
			}
			else return a.math > b.math; //내림차순
		}
		else return a.english < b.english; //오름차순
	}
	else return a.korean > b.korean; //내림차순
}

int main() {
	int num;
	cin >> num;
	person* p = new person[num];

	string name;
	int korean;
	int english;
	int math;
	for (int i = 0; i < num; i++) {
		cin >> name >> korean >> english >> math;
		p[i].name = name;
		p[i].korean = korean;
		p[i].english = english;
		p[i].math = math;
	}

	sort(p, p + num, compare);

	for (int i = 0; i < num; i++) {
		cout << p[i].name << "\n";
	}
}