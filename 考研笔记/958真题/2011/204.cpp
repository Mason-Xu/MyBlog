// c++������.
 // �ҷ��־���this��c1.m_real �д�,this����ô�����������?
 // ��ʱ������Ŀ����ֻ��Ĵ�,����ָ������֮��...��ô���

#include<iostream>
using namespace std;

class CComplex {
	double m_real;
	double m_image;
public:
	~CComplex() {}
	void setValue(double r = 0, double i = 0) {
		m_real = r;
		m_image = i;
	}
	double getreal() {
		return m_real;
	}
	double getimage() {
		return m_image;
	}
	void show() {
		cout << m_real << "+" << m_image << "*i" << endl;
	}
};

int main204() {
	CComplex c1;
	c1.setValue(2.5, 7.5);
	cout << c1.getreal() << endl;
	system("pause");
	return 0;
}