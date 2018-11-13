// 设计一个时间类Time,包含3个数据成员,h,m,s,
// 另外包括存取 各个数据元素和设置时间的成员函数,按12小时制输出时间.
// 设计成员函数disp12(),以及默认构造函数,默认时间0时0分0秒 ,main()函数已经给出


#include<iostream>
#include<iomanip>	// 自动补0 依赖头文件
using namespace std;

class Time {
private:
	int h, m, s;
public:
	Time() {}
	Time(int hour=0, int min=0, int sec=0){
		setH(hour);
		setM(min);
		setS(sec);

	}
	void setH(int hour) { h = hour; }
	void setM(int min) { m = min; }
	void setS(int sec) { s = sec; }
	int getH() const { return h ; }
	int getM() const { return m ; }
	int getS() const { return s ; }
	void setTime(int hour, int min, int sec) {
		h = getH();
		m = getM();
		s = getS();
	}

	void disp12() {
		if (h > 12) { 
			h -= 12;
			cout << setfill('0') << setw(2) << h << ":" 
				<< setfill('0') << setw(2) << m << ":" 
				<< setfill('0') << setw(2) << s << "PM" << endl;
		}
		else {
			cout << setfill('0') << setw(2) << h << ":"
				<< setfill('0') << setw(2) << m << ":"
				<< setfill('0') << setw(2) << s << "AM" << endl;
		}
	}
};

int main() {
	Time t1(13, 45, 12), t2(9, 30, 50);
	t1.disp12();
	t2.disp12();
	system("pause");
	return 0;
}