#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h> 
using namespace std;
#define N 5

//������� ����������� �������
float minArray(float arr[N][N]);
float maxArray(float arr[N][N]);
float maxDownTriangleArray(float arr[N][N]);
float maxUpTriangleArray(float arr[N][N]);
float minDownTriangleArray(float arr[N][N]);
float minUpTriangleArray(float arr[N][N]);
float minMajorDiag(float arr[N][N]);
float maxMajorDiag(float arr[N][N]);
float minSecondDiag(float arr[N][N]);
float maxSecondDiag(float arr[N][N]);
float midArifmeticMatrix(float arr[N][N]);
float midBottomTriangleMatrix(float arr[N][N]);
float midUpTriangleMatrix(float arr[N][N]);
void summLineOnMatrix(float arr[N][N]);
void summColumnOnMatrix(float arr[N][N]);
void minNumberOnLine(float arr[N][N]);
void minNumberOnColumn(float arr[N][N]);
void maxNumberOnLine(float arr[N][N]);
void maxNumberOnColumn(float arr[N][N]);
void midNumberOnLine(float arr[N][N]);
void midNumberOnColumn(float arr[N][N]);
float summBottomTriangle(float arr[N][N]);
float summUpTriangle(float arr[N][N]);
float closest(float arr[N][N]);
//
int main(void)
{
	float m[N][N];
	int i, j;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) m[i][j] = rand() / 10.;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			cout << setw(8) << setprecision(5) << m[i][j] << " ";
		cout << endl;
	}
	//getch();//��������� conio �� �������� �� ��� �� �����(

	cout << "������� �������: " << minArray(m) << "\n";
	cout << "�������� �������: " << maxArray(m) << "\n";
	cout << "�������� ���������������� �����: " << maxDownTriangleArray(m) << "\n";
	cout << "�������� ���������������� �����: " << maxUpTriangleArray(m) << "\n";
	cout << "������� ��������������� �����: " << minDownTriangleArray(m) << "\n";
	cout << "������� ���������������� �����: " << minUpTriangleArray(m) << "\n";
	cout << "������� ������� ���������: " << minMajorDiag(m) << "\n";
	cout << "�������� ������� ���������: " << maxMajorDiag(m) << "\n";
	cout << "������� ������������� ���������: " << minSecondDiag(m) << "\n";
	cout << "�������� �������������� ���������: " << maxSecondDiag(m) << "\n";
	cout << "������� �������������� ���������� �������: " << midArifmeticMatrix(m) << "\n";
	cout << "������� �������������� ������� ������������: " << midBottomTriangleMatrix(m) << "\n";
	cout << "������� �������������� �������� ������������: " << midUpTriangleMatrix(m) << "\n";
	cout << "����� ����� �������: "; summLineOnMatrix(m);
	cout << "����� �������� �������: "; summColumnOnMatrix(m);
	cout << "����������� ����� � ������� �������: "; minNumberOnLine(m);
	cout << "����������� ����� � ��������� �������: "; minNumberOnColumn(m);
	cout << "������������ ����� � ������� �������: "; maxNumberOnLine(m);
	cout << "������������ ����� � �������� �������: "; maxNumberOnColumn(m);
	cout << "������� �������� � ������� �������: "; midNumberOnLine(m);
	cout << "������� �������� � �������� �������: "; midNumberOnColumn(m);
	cout << "����� ���������� ������� ������������ �������: " << summBottomTriangle(m) << "\n";
	cout << "����� ���������� �������� ������������ �������: " << summUpTriangle(m) << "\n";
	cout << "�������� ������������ �������� ������� � ��������: " << closest(m) << "\n";
	return 0;
}

float minArray(float arr[N][N]) {//������� ������ �������� �������
	float min = arr[0][0];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (min > arr[i][j]) min = arr[i][j];
		}
	}
	return min;
}

float maxArray(float arr[N][N]) {//������� ������ ������������� �������� � �������
	float max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (max < arr[i][j]) max = arr[i][j];
		}
	}
	return max;
}

float maxDownTriangleArray(float arr[N][N]) {//�������� ������� ������������
	float max = 0;
	int endArr = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= endArr; j++) {
			if (max < arr[i][j]) max = arr[i][j];
		}
		if (endArr != N) endArr++;
	}
	return max;
}

float maxUpTriangleArray(float arr[N][N]) {//�������� �������� ������������
	float max = 0;
	int startArr = 0;
	for (int i = 0; i < N; i++) {
		for (int j = startArr; j < N; j++) {
			if (max < arr[i][j]) max = arr[i][j];
		}
		if (startArr != N) startArr++;
	}
	return max;
}

float minDownTriangleArray(float arr[N][N]) {//������� ������� ������������
	float min = arr[0][0];
	int endArr = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= endArr; j++) {
			if (min > arr[i][j]) min = arr[i][j];
		}
		if (endArr != N) endArr++;
	}
	return min;
}

float minUpTriangleArray(float arr[N][N]) {//�������� ������� ������������
	float min = arr[0][0];
	int startArr = 0;
	for (int i = 0; i < N; i++) {
		for (int j = startArr; j < N; j++) {
			if (min > arr[i][j]) min = arr[i][j];
		}
		if (startArr != N) startArr++;
	}
	return min;
}

float minMajorDiag(float arr[N][N]) {//������� ������� ��������� �������
	float min = arr[0][0];
	for (int i = 0; i < N; i++)
		if (min > arr[i][i]) min = arr[i][i];
	return min;
}

float maxMajorDiag(float arr[N][N]) {//�������� ������� ���������
	float max = 0;
	for (int i = 0; i < N; i++)
		if (max < arr[i][i]) max = arr[i][i];
	return max;
}

float minSecondDiag(float arr[N][N]) {//������� �������������� ���������
	float min = arr[0][4];
	for (int i = 0; i < N; i++) {
		for (int j = 4; j >= 0; j--) {
			if (min > arr[i][j]) {
				min = arr[i][j];
			}
		}
	}
	return min;
}

float maxSecondDiag(float arr[N][N]) {//�������� �������������� ���������
	float max = arr[0][4];
	for (int i = 0; i < N; i++) {
		for (int j = 4; j >= 0; j--) {
			if (max < arr[i][j]) {
				max = arr[i][j];
			}
		}
	}
	return max;
}

float midArifmeticMatrix(float arr[N][N]) {//������� ��������������
	float mid = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mid += arr[i][j];
		}
	}
	mid = mid / (N * N);
	return mid;
}

float midBottomTriangleMatrix(float arr[N][N]) {//������� �������������� ������� ������������
	float mid = 0;
	int count = 0;
	int ref = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < ref; j++) {
			mid += arr[i][j];
			count++;
		}
		ref++;
	}
	mid = mid / count;
	return mid;
}

float midUpTriangleMatrix(float arr[N][N]) {//������� �������������� �������� ������������
	float mid = 0;
	int count = 0;
	int ref = 0;
	for (int i = 0; i < N; i++) {
		for (int j = ref; j < N; j++) {
			mid += arr[i][j];
			count++;
		}
		ref++;
	}
	mid = mid / count;
	return mid;
}

void summLineOnMatrix(float arr[N][N]) {
	float summ;
	for (int i = 0; i < N; i++) {
		summ = 0;
		for (int j = 0; j < N; j++) {
			summ += arr[i][j];
		}
		cout << summ << " ";
	}
	cout << endl;
	//return 0;
}

void summColumnOnMatrix(float arr[N][N]) {
	float summ;
	for (int i = 0; i < N; i++) {
		summ = 0;
		for (int j = 0; j < N; j++) {
			summ += arr[j][i];
		}
		cout << summ << " ";
	}
	cout << endl;
	//return 0;
}

void minNumberOnLine(float arr[N][N]) {
	float min;
	for (int i = 0; i < N; i++) {
		min = arr[i][0];
		for (int j = 0; j < N; j++) {
			if (min > arr[i][j]) min = arr[i][j];
		}
		cout << min << " ";
	}
	cout << endl;
}

void minNumberOnColumn(float arr[N][N]) {
	float min;
	for (int i = 0; i < N; i++) {
		min = arr[0][i];
		for (int j = 0; j < N; j++) {
			if (min > arr[j][i]) min = arr[j][i];
		}
		cout << min << " ";
	}
	cout << endl;
}

void maxNumberOnLine(float arr[N][N]) {
	float max;
	for (int i = 0; i < N; i++) {
		max = 0;
		for (int j = 0; j < N; j++) {
			if (max < arr[i][j]) max = arr[i][j];
		}
		cout << max << " ";
	}
	cout << endl;
}

void maxNumberOnColumn(float arr[N][N]) {
	float max;
	for (int i = 0; i < N; i++) {
		max = 0;
		for (int j = 0; j < N; j++) {
			if (max < arr[j][i]) max = arr[j][i];
		}
		cout << max << " ";
	}
	cout << endl;
}

void midNumberOnLine(float arr[N][N]) {
	float mid;
	int ref = N;
	for (int i = 0; i < N; i++) {
		mid = 0;
		for (int j = 0; j < N; j++) {
			mid += arr[i][j];
		}
		mid = mid / ref;
		cout << mid << " ";
	}
	cout << endl;
}

void midNumberOnColumn(float arr[N][N]) {
	float mid;
	for (int i = 0; i < N; i++) {
		mid = 0;
		for (int j = 0; j < N; j++) {
			mid += arr[j][i];
		}
		mid = mid / N;
		cout << mid << " ";
	}
	cout << endl;
}

float summBottomTriangle(float arr[N][N]) {
	float summ = 0;
	int ref = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < ref; j++) {
			summ += arr[i][j];
		}
		ref++;
	}
	return summ;
}

float summUpTriangle(float arr[N][N]) {
	float summ = 0;
	int ref = 0;
	for (int i = 0; i < N; i++) {
		for (int j = ref; j < N; j++) {
			summ += arr[i][j];
		}
		ref++;
	}
	return summ;
}

float closest(float arr[N][N]) {//�������� ���������� �������� � ��������
	float mid = midArifmeticMatrix(arr);
	float def = abs(mid - arr[0][0]);
	float result = arr[0][0];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (def > abs(mid - arr[i][j])) {
				def = abs(mid - arr[i][j]);
				result = arr[i][j];
			}
		}
	}
	return result;
}
