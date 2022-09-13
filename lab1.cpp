#include <iostream>

using namespace std;

void PrintArr(int* arr, int size, int P, int S, int sum) {
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl; //<< "Sravn: " << S << endl << "Prirav: " << P << endl << "Summa: " << sum << 8 / 3;
}

void BubbleSort(int *arr, int size, int *P, int *S) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				*P += 3;
			}
			*S += 1;
		}
	}
}

void SelectSort(int* arr, int size, int *P, int *S) {
    
	int min;

    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++){
            if (arr[j] < arr[min])
                min = j;
            *S+=1;
        }
        if(min != i){
            swap(arr[min], arr[i]);
            *P+=3;
        }
    }
}

void Merge(int *arr, int size, int sh) {
    int size2 = size / 2;
    int size1 = size - size2;
    int *arr1 = new int[size1];
    int *arr2 = new int[size2];
    
    for (int i = 0; i < size; ++i) {
        if (i < size1) {
            arr1[i] = arr[i];
        } else {
            arr2[i - size1] = arr[i];
        }
    }
    PrintArr(arr1, size1, 0, 0, 0);
    PrintArr(arr2, size2, 0, 0, 0);
    int n = size1 / sh;
    if (size1 % sh != 0) ++n;
    
    int arri = 0;
    for (int i = 0; i < n; ++i) {
        int j1 = 0, j2 = 0, sh1 = sh, sh2 = sh;
        if (i == n - 1) {
            sh1 = size1 - i * sh;
            sh2 = size2 - i * sh;
        }
        while (j1 < sh1 && j2 < sh2) {
            if (arr1[i * sh + j1] < arr2[i * sh + j2]) {
                arr[arri] = arr1[i * sh + j1];
                ++j1;
            } else {
                arr[arri] = arr2[i * sh + j2];
                ++j2;
            }
            ++arri;
        }
        
        if (j1 < sh1) {
            for (int j = j1; j < sh; ++j) {
                arr[arri] = arr1[j];
                ++arri;
            }
        }
        if (j2 < sh2) {
            for (int j = j2; j < sh; ++j) {
                arr[arri] = arr2[j];
                ++arri;
            }
        }
    }
}

void MergeSort(int* arr, int size)
{
    int sh = 1;
    while (sh <= size / 2 + 1) {
        Merge(arr, size, sh);
        sh = sh * 2;
        PrintArr(arr, size, 0, 0, 0);
    }
}



int main()
{
	int* arr;
	int size = 0;
	int P = 0, S = 0, sum = 0;
	cout << "Enter N: ";
	cin >> size;

	arr = new int[size];
	
	for (int i = 0; i < size; ++i) {
		cout << "arr[" << i << "] =";
		cin >> arr[i];
	}

	MergeSort(arr, size);
	sum = S + P;
	PrintArr(arr, size, S, P, sum);

	delete[] arr;

	return 0;
}
