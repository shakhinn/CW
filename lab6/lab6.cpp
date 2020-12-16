#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include <windows.h>

using namespace std;

extern "C"{
	void func(int* arr, int Xmin, int* res, int length_); 
	 
	void func2(int* result, int* LGr, int* result_final, int length_big, int Xmin, int lehtg_);
}

int cmp(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}

void print(int* arr, int* LGr, int count, ofstream* file, int max) {
	cout << endl << endl;
	cout << "Номер интервала\t интервал   Кол-во чисел, попавших в интервал\n";
	for (int i = 0; i < count-1; i++) {
		cout << i + 1 << "\t\t [" << LGr[i]<<" , "<<LGr[i+1]-1 << ")\t\t\t   " << arr[i] << "\n";
		*file << i + 1 << "\t\t [" << LGr[i] << " , " << LGr[i+1]-1 << ")\t\t\t   " << arr[i] << "\n";
	}
	cout << count << "\t\t [" << LGr[count-1] << " , " << max << ")\t\t\t   " << arr[count-1] << "\n";
	*file << count << "\t\t [" << LGr[count-1] << " , " << max << ")\t\t\t   " << arr[count-1] << "\n";
}

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ofstream file("C:\\Users\\Asus\\Documents\\result.txt");
	int len, xmin, xmax, NInt,
		* arr, * LGr, * RGr, * res;
	cout << "Ввеедите длину массива псевдослучайных чисел: ";
	cin >> len;
	while (len <= 0 || len > 16000){
		cout << "Кол-во элементов должно "
			"принадлежать полуинтервалу: (0; 16000]\n"
			"Ввеедите длину массива псевдослучайных чисел: ";
		cin >> len;
	}
	cout << "Введите диапозон изменения массива "
		"псевдослучайных чисел:\n";
	cout << "Левая граница отрезка: ";
	cin >> xmin;
	cout << "Правая граница отрезка: ";
	cin >> xmax;
	while (xmin > xmax){
		cout << "Некорректно задан отрезок\n";
		"Левая граница отрезка: ";
		cin >> xmin;
		cout << "Правая граница отрезка: ";
		cin >> xmax;
	}
	srand(time(nullptr));
	arr = new int[len];
	for (size_t i = 0; i < len; i++)
		arr[i] = rand() % (xmax + 1 - xmin) + xmin;

	int* result = new int[(xmax - xmin + 1)];
	int* LGr1 = new int[(xmax - xmin + 1)];
	for (int i = 0; i < (xmax - xmin + 1); i++) {
		result[i] = 0;
		LGr1[i] = xmin + i;
	}
	func(arr, xmin, result, len);

	cout << "Введите кол-во интервалов: ";
	cin >> NInt;
	while (NInt <= 0 || NInt > 24 || NInt > xmax - xmin){
		cout << "Кол-во интервалов должно "
			"принадлежать полуинтервалу: (0; 24] || (0; xmax - xmin]\n";
		"Введите кол-во интервалов: ";
		cin >> NInt;
	}
	LGr = new int[NInt];
	res = new int[NInt];
	cout << "Введите массив левых границ интервалов:\n";
	for (int i = 0; i < NInt; i++){
		cin >> LGr[i];
		while (LGr[i] < xmin || LGr[i] >= xmax){
			cout << "Левая граница интервала должна "
				"быть в полуинтервале: [xmin; xmax)\n"
				"Продолжите ввод:\n";
			cin >> LGr[i];
		}
	}
	qsort(LGr, NInt, sizeof(int), cmp);
	for (int i = 0; i < NInt; i++) {
		res[i] = 0;
	}
	print(result, LGr1, (xmax - xmin + 1), &file, xmax);
	func2(result, LGr, res, (xmax - xmin), xmin, NInt);
	print(res, LGr, NInt, &file, xmax);

	delete [] arr;
	delete [] LGr;
	delete [] res;
	delete [] result;
	delete[] LGr1;

	return 0;
}

