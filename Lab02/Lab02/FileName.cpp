#include <iostream>
using namespace std;

int sum(int x, int y) {
	return x + y;
}

int sub(int x, int y) {
	return x - y;
}
int (*f)(int, int);


int main() {

	// 4 �������
	bool real = 0, notReal = 1;

	// 5 �������
	char secondSurnameSymb = 'H';

	// 6 �������
	char rusSecondSurnameSymb = '�';

	// 7 �������
	wchar_t firstSurnameSymb = L'Z';
	//�� Windows �������� � ������ 2 ����� (16 ���)

	// 8 �������
	wchar_t rusFirstSurnameSymb = L'�';// !!!!!!!!!!!!!!

	// 9 �������
	short X = 15, minusX = -15;
	// ������ �������
	// 1) 15 � �������� ������� 1111
	// 2) 1000 0000 0000 1111 - ��
	// 3) 1111 1111 1111 0000 - ��
	// 4) 1111 1111 1111 0001 - ���
	// 5) F � �����������������
	// �������� - -X � ����������������� ������� ��������� : 0xF

	// 10 �������
	short maxShort = 0x7fff, minShort = 0x8000;

	// 11 ������� 
	//!!unsigned short maxUnsShort = 0x7FFFFFFF, minUnsShort = 65535
	unsigned short minus = 0x0, maxus = 0xffff;

	// 12 �������
	int frstY = 16, scndY = -16;
	// ������ �������
	// 1) 16 � �������� ������� 10000
	// 2) 1000 0000 0001 0000 - ��
	// 3) 1111 1111 1110 1111 - ��
	// 4) 1111 1111 1111 0000 - ���
	// 5) 10 � �����������������
	// �������� - -X � ����������������� ������� ��������� : 0x10

	//13 �������
	int maxInt = 0x7fffffff, minInt = 0x80000000; 

	// 14 �������
	unsigned int maxUI = 0xffffffff, minUI = 0x0;

	// 15 ������� 
	long frstZ = 17, scndZ = -17;
	// ������ �������
	// 1) -17 � �������� ������� 10001
	// 2) 1000 0000 0001 0001 - ��
	// 3) 1111 1111 1110 1110 - ��
	// 4) 1111 1111 1110 1111 - ���
	// 5) 1111 1111 1110 1111 - FEFF � �����������������
	// �������� - -X � ����������������� ������� ��������� : 0xFFEF

	//16
	long maxLong = 0x7fffffff, minLong = 0x80000000;

	//17
	long maxUnsLong = 0xffffffff, minUnsLong = 0x0;

	//18 
	float frstS = 9.0, L = -9.0;
	// 9.0 = 1001,0 = 1,001(2) (+3)
	// 0 | 10000010 | 00100000
	// 4 | 1 | 1 | 0
	// 0x41100000

	// 1 | 10000010 | 00100000
	// C | 1 | 1 | 0
	// 0xC110

	//19
	frstS = frstS / 0;
	L = L / 0;
	float Undef = sqrt(-6);

	char* pointerEng = &secondSurnameSymb;
	char* pointerEng1 = pointerEng + 3;

	wchar_t* pointerRus = &rusFirstSurnameSymb;
	wchar_t* pointerRus1 = pointerRus + 3;

	short* pointerMaxShrt = &X;
	short* pointerMaxShrt1 = pointerMaxShrt + 3;

	int* intFrst = &frstY;
	int* intFrst1 = intFrst + 3;

	float* shortPos = &frstS;
	float* shortPos1 = shortPos + 3;

	double exampleDouble = 3436.238459;
	double* pointerDbl = &exampleDouble;
	double* pointerDbl1 = pointerDbl + 3;

	//21
	f = sum;
	int x = f(2, 3);
	cout << "Sum = " << x << endl;

	f = sub;
	int y = f(2, 3);
	cout << "Minus = " << y << endl;

	return 0;
 }