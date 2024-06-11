#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h> 
using namespace std;
#define N 5

//Çàðàíåå îáüÿâëåííûå ôóíêöèè
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
	//getch();//Ïîñêîëüêó conio íå ðàáîòàåò îí òóò íå íóæåí(

	cout << "Ìèíèìóì ìàòðèöû: " << minArray(m) << "\n";
	cout << "Ìàêñèìóì ìàòðèöû: " << maxArray(m) << "\n";
	cout << "Ìàêñèìóì íèæíåòðåóãîëüíîé ÷àñòè: " << maxDownTriangleArray(m) << "\n";
	cout << "Ìàêñèìóì âåðõíåðåóãîëüíîé ÷àñòè: " << maxUpTriangleArray(m) << "\n";
	cout << "Ìèíèìóì íèæíåðåóãîëüíîé ÷àñòè: " << minDownTriangleArray(m) << "\n";
	cout << "Ìèíèìóì âåðõíåðåóãîëüíîé ÷àñòè: " << minUpTriangleArray(m) << "\n";
	cout << "Ìèíèìóì ãëàâíîé äèàãîíàëè: " << minMajorDiag(m) << "\n";
	cout << "Ìàêñèìóì ãëàâíîé äèàãîíàëè: " << maxMajorDiag(m) << "\n";
	cout << "Ìèíèìóì âòîðîñòåïåíîé äèàãîíàëè: " << minSecondDiag(m) << "\n";
	cout << "Ìàêñèìóì âòîðîñòåïåííîé äèàãîíàëè: " << maxSecondDiag(m) << "\n";
	cout << "Ñðåäíåå àðèôìåòè÷åñêîå ýëëåìåíòîâ ìàòðèöû: " << midArifmeticMatrix(m) << "\n";
	cout << "Ñðåäíåå àðèôìåòè÷åñêîå íèæíåãî òðåóãîëüíèêà: " << midBottomTriangleMatrix(m) << "\n";
	cout << "Ñðåäíåå àðèôìåòè÷åñêîå âåðõíåãî òðåóãîëüíèêà: " << midUpTriangleMatrix(m) << "\n";
	cout << "Ñóììà ñòðîê ìàññèâà: "; summLineOnMatrix(m);
	cout << "Ñóììà ñòîëáöîâ ìàññèâà: "; summColumnOnMatrix(m);
	cout << "Ìèíèìàëüíîå ÷èñëî â ñòðîêàõ ìàññèâà: "; minNumberOnLine(m);
	cout << "Ìèíèìàëüíîå ÷èñëî â ñòîëáöîàõ ìàññèâà: "; minNumberOnColumn(m);
	cout << "Ìàêñèìàëüíîå ÷èñëî â ñòðîêàõ ìàññèâà: "; maxNumberOnLine(m);
	cout << "Ìàêñèìàëüíîå ÷èñëî â ñòîëáöàõ ìàññèâà: "; maxNumberOnColumn(m);
	cout << "Ñðåäíåå çíà÷åíèå â ñòðîêàõ ìàòðèöû: "; midNumberOnLine(m);
	cout << "Ñðåäíåå çíà÷åíèå â ñòîëáöàõ ìàòðèöû: "; midNumberOnColumn(m);
	cout << "Ñóììà ýëëåìåíòîâ íèæíåãî òðåóãîëüíèêà ìàòðèöû: " << summBottomTriangle(m) << "\n";
	cout << "Ñóììà ýëëåìåíòîâ âåðõíåãî òðåóãîëüíèêà ìàòðèöû: " << summUpTriangle(m) << "\n";
	cout << "Íàèáîëåå ïðèáëèæåííûé ýëëåìåíò ìàññèâà ê ñðåäíåìó: " << closest(m) << "\n";
	return 0;
}

float minArray(float arr[N][N]) {//Ôóíêöèÿ ïîèñêà ìèíèìóìà ìàòðèöû
	float min = arr[0][0];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (min > arr[i][j]) min = arr[i][j];
		}
	}
	return min;
}

float maxArray(float arr[N][N]) {//Ôóíêöèÿ ïîèñêà ìàêñèìàëüíîãî çíà÷åíèÿ â ìàòðèöå
	float max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (max < arr[i][j]) max = arr[i][j];
		}
	}
	return max;
}

float maxDownTriangleArray(float arr[N][N]) {//Ìàêñèìóì íèæíåãî òðåóãîëüíèêà
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

float maxUpTriangleArray(float arr[N][N]) {//Ìàêñèìóì âåðõíåãî òðåóãîëüíèêà
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

float minDownTriangleArray(float arr[N][N]) {//Ìèíèìóì íèæíåãî òðåóãîëüíèêà
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

float minUpTriangleArray(float arr[N][N]) {//Ìàêñèìóì íèæíåãî òðåóãîëüíèêà
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

float minMajorDiag(float arr[N][N]) {//Ìèíèìóì ãëàâíîé äèàãîíàëè ìàòðèöû
	float min = arr[0][0];
	for (int i = 0; i < N; i++)
		if (min > arr[i][i]) min = arr[i][i];
	return min;
}

float maxMajorDiag(float arr[N][N]) {//Ìàêñèìóì ãëàâíîé äèàãîíàëè
	float max = 0;
	for (int i = 0; i < N; i++)
		if (max < arr[i][i]) max = arr[i][i];
	return max;
}

float minSecondDiag(float arr[N][N]) {//Ìèíèìóì âòîðîñòåïåííîé äèàãîíàëè
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

float maxSecondDiag(float arr[N][N]) {//Ìàêñèìóì âòîðîñòåïåííîé äèàãîíàëè
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

float midArifmeticMatrix(float arr[N][N]) {//Ñðåäíåå àðèôìåòè÷åñêîå
	float mid = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mid += arr[i][j];
		}
	}
	mid = mid / (N * N);
	return mid;
}

float midBottomTriangleMatrix(float arr[N][N]) {//Ñðåäíåå àðèôìåòè÷åñêîå íèæíåãî òðåóãîëüíèêà
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

float midUpTriangleMatrix(float arr[N][N]) {//Ñðåäíåå àðèôìåòè÷åñêîå âåðõíåãî òðåóãîëüíèêà
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

float closest(float arr[N][N]) {//Íàèáîëåå ïîäõîäÿùèé ýëëåìåíò ê ñðåäíåìó
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
