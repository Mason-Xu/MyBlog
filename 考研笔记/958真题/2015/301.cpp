#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

class Score {
private:
	int ave=0;
	int min;
	int max;
public :
	int FindMax(int score[]) {
		for (int i = 0; i < 10; i++) {
			if (score[i] > max) {
				max = score[i];
			}
		}
		return max;
	}
	int FindMin(int score[]) {
		min = score[0];
		for (int i = 0; i < 10; i++) {
			if (score[i] < min) {
				min = score[i];
			}
		}
		return min;
	}
	void GetResult(int score[]) {
		int sum = 0;
		min = FindMin(score);
		max = FindMax(score);
		for (int i = 0; i < 10; i++) {
			sum += score[i];
		}
		ave = (sum - min - max) / 8;
		cout << "平均值" << ave <<endl;
		cout << "sum" << sum <<endl;
		cout << "min" << min <<endl;
		cout << "max" << max <<endl;
	}
};
int main301() {
	int score[10] = { 80,70,60,65,66,90,95,88,91,85 };
	Score a;
	a.GetResult(score);
	system("pause");
	return 0;
}