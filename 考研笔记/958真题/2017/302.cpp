#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

class School {
private :
	string id;
	string name;
	double cost;
public:
	School(string i, string n, double c) {} 
	string getId() {
		return id;
	}
	string getName() {
		return name;
	}
	double getCost() {
		return cost;
	}
	void putId(string i ) {
		id = i;
	}
	void putName(string n) {
		name = n;
	}
	void putCost(double c) {
		cost = c;
	}
};


class MaxSchool {
private:
	vector<School> schools;
public :
	MaxSchool() {
		ifstream in("aa.txt");
		if (in.is_open()) {
			for (int i = 0; i < 5; i++) {
				string id;
				string name;
				double cost;
				in >> id;
				in >> name;
				in >> cost;
				schools.push_back(School(id, name, cost));
			}
		}
	}
	void printMax() {
		sort(schools.begin(), schools.end(), 
			[](School s1, School s2) {
			return s1.getCost() > s2.getCost(); 
		});
		School sc = schools[0];
		cout << sc.getId() << " " << sc.getName() << " " << sc.getCost() << endl;
	}
};

int main() {
	MaxSchool mx;
	mx.printMax();
	system("pause");
	return 0;
}