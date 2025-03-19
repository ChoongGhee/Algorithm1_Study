#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <fstream>
#include <chrono>
#include <numeric>
#include <iomanip>

#include <algorithm>
using namespace std;

void Print(vector<int>& arr)
{
	for (auto& a : arr)
		cout << a << " ";
	cout << endl;
}

// 편의상 결과가 arr에 저장되도록 바꿨습니다.
void CountingSort(vector<int>& arr, int k, int exp)
{
	vector<int> temp = arr; // 복사

	vector<int> count(k + 1, 0);
	// TODO:
	int divisor = 1;
    for(int i=1; i<exp; i++) divisor *= 10;

	for(int i=0;i<temp.size();i++) count[(temp[i] / divisor) % 10]++;

	for(int i=1;i<count.size();i++) count[i] += count[i-1];

	for (int i = arr.size() - 1; i >= 0; i--) arr[--count[(temp[i] / divisor) % 10]] = temp[i];
}


// 최적화 전 코드 작동은 함.
// void CountingSort(vector<int>& arr, int k, int exp)
// {
//     vector<int> temp = arr; // 복사

//     vector<int> count(k + 1, 0);
//     // TODO:
//     for(int i=0;i<temp.size();i++) {
//         int idx = temp[i];
//         for(int j=0; j<exp-1;j++) idx/=10;
//         count[idx%10]++;
//     }

//     for(int i=1;i<count.size();i++) count[i] += count[i-1];

//     for (int i = arr.size() - 1; i >= 0; i--)
//     {
//         // TODO:
//         int idx = temp[i];
//         for(int j=0; j<exp-1;j++) idx/=10;

//         arr[--count[idx%10]] = temp[i];
//     }
// }

void RadixSort(vector<int>& arr)
{
	int k = 9; // 0 이상 9 이하
	int m = *max_element(arr.begin(), arr.end());
	// TODO:
	int exp = 1;

	while(m/10 > 0) {
		m/=10;
		exp++;
	}

	for(int i=1;i<=exp;i++)
	{
		cout << "exp = " << exp << endl;
		// TODO:
		CountingSort(arr, k, i);
		Print(arr);
	}
}

int main()
{
	// vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
	vector<int> arr = { 2, 5, 3, 0, 2, 3, 0, 3 };

	Print(arr);

	RadixSort(arr);

	return 0;
}