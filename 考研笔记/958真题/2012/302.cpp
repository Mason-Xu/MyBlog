#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

struct Student {
	string name;
	double average;
};

int main302() {
	ofstream f("abc.txt");	// ����ļ���,����abc.txt�ļ�����д������
	if (f.is_open()) {
		int s_num;
		int class_num;
		cin >> s_num;
		f << s_num << " ";		// д������
		cin >> class_num;
		f << class_num << endl;	// д������

		vector<Student> students;		// student ����
		for (int i = 0; i < s_num; i++) {
			Student student;
			string name;
			cin >> name;
			f << name << " ";
			student.name = name;
			for (int j = 0; j < class_num; j++) {
				int score;
				cin >> score;
				f << score << " ";
				student.average += score;
			}
			f << endl;
			student.average /= class_num;
			students.push_back(student);
		}
		sort(students.begin(), students.end(),
			[](Student &a, Student &b) {return a.average > b.average; });
		int index=1;
		for(Student &s:students) {
			cout << (index++) << " " << s.name << endl;
		}
	}
	system("pause");
	return 0;
}
