#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h> 
using namespace std;
#define N 5

//Заранее обьявленные функции
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
	//getch();//Поскольку conio не работает он тут не нужен(

	cout << "Минимум матрицы: " << minArray(m) << "\n";
	cout << "Максимум матрицы: " << maxArray(m) << "\n";
	cout << "Максимум нижнетреугольной части: " << maxDownTriangleArray(m) << "\n";
	cout << "Максимум верхнереугольной части: " << maxUpTriangleArray(m) << "\n";
	cout << "Минимум нижнереугольной части: " << minDownTriangleArray(m) << "\n";
	cout << "Минимум верхнереугольной части: " << minUpTriangleArray(m) << "\n";
	cout << "Минимум главной диагонали: " << minMajorDiag(m) << "\n";
	cout << "Максимум главной диагонали: " << maxMajorDiag(m) << "\n";
	cout << "Минимум второстепеной диагонали: " << minSecondDiag(m) << "\n";
	cout << "Максимум второстепенной диагонали: " << maxSecondDiag(m) << "\n";
	cout << "Среднее арифметическое эллементов матрицы: " << midArifmeticMatrix(m) << "\n";
	cout << "Среднее арифметическое нижнего треугольника: " << midBottomTriangleMatrix(m) << "\n";
	cout << "Среднее арифметическое верхнего треугольника: " << midUpTriangleMatrix(m) << "\n";
	cout << "Сумма строк массива: "; summLineOnMatrix(m);
	cout << "Сумма столбцов массива: "; summColumnOnMatrix(m);
	cout << "Минимальное число в строках массива: "; minNumberOnLine(m);
	cout << "Минимальное число в столбцоах массива: "; minNumberOnColumn(m);
	cout << "Максимальное число в строках массива: "; maxNumberOnLine(m);
	cout << "Максимальное число в столбцах массива: "; maxNumberOnColumn(m);
	cout << "Среднее значение в строках матрицы: "; midNumberOnLine(m);
	cout << "Среднее значение в столбцах матрицы: "; midNumberOnColumn(m);
	cout << "Сумма эллементов нижнего треугольника матрицы: " << summBottomTriangle(m) << "\n";
	cout << "Сумма эллементов верхнего треугольника матрицы: " << summUpTriangle(m) << "\n";
	cout << "Наиболее приближенный эллемент массива к среднему: " << closest(m) << "\n";
	return 0;
}

float minArray(float arr[N][N]) {//Функция поиска минимума матрицы
	float min = arr[0][0];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (min > arr[i][j]) min = arr[i][j];
		}
	}
	return min;
}

float maxArray(float arr[N][N]) {//Функция поиска максимального значения в матрице
	float max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (max < arr[i][j]) max = arr[i][j];
		}
	}
	return max;
}

float maxDownTriangleArray(float arr[N][N]) {//Максимум нижнего треугольника
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

float maxUpTriangleArray(float arr[N][N]) {//Максимум верхнего треугольника
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

float minDownTriangleArray(float arr[N][N]) {//Минимум нижнего треугольника
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

float minUpTriangleArray(float arr[N][N]) {//Максимум нижнего треугольника
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

float minMajorDiag(float arr[N][N]) {//Минимум главной диагонали матрицы
	float min = arr[0][0];
	for (int i = 0; i < N; i++)
		if (min > arr[i][i]) min = arr[i][i];
	return min;
}

float maxMajorDiag(float arr[N][N]) {//Максимум главной диагонали
	float max = 0;
	for (int i = 0; i < N; i++)
		if (max < arr[i][i]) max = arr[i][i];
	return max;
}

float minSecondDiag(float arr[N][N]) {//Минимум второстепенной диагонали
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

float maxSecondDiag(float arr[N][N]) {//Максимум второстепенной диагонали
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

float midArifmeticMatrix(float arr[N][N]) {//Среднее арифметическое
	float mid = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mid += arr[i][j];
		}
	}
	mid = mid / (N * N);
	return mid;
}

float midBottomTriangleMatrix(float arr[N][N]) {//Среднее арифметическое нижнего треугольника
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

float midUpTriangleMatrix(float arr[N][N]) {//Среднее арифметическое верхнего треугольника
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

float closest(float arr[N][N]) {//Наиболее подходящий эллемент к среднему
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
