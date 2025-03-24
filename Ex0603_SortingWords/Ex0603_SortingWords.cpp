#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <fstream>
#include <chrono>
#include <numeric>
#include <iomanip>
#include <string>
using namespace std;

template<typename T>
void Print(vector<T>& arr)
{
	for (auto& a : arr)
		cout << a << " ";
	cout << endl;
}

void CountingSort(vector<string>& arr, int k, int d)
{
	vector<string> temp = arr; // 복사

	std::fill(arr.begin(), arr.end(), "   "); // 디버깅 편의

	// TODO:
	vector<int> count(k + 1, 0);

	for(int i=0;i<temp.size();i++) count[temp[i][d] - 'A']++;

	for(int i=1;i<count.size();i++) count[i] += count[i-1];

	for (int i = temp.size() - 1; i >= 0; i--) arr[--count[temp[i][d]-'A']] = temp[i];
}

void RadixSort(vector<string>& arr)
{
	// TODO:
	int exp = 1;
	for(auto data : arr) if(exp < data.size()) exp = data.size();

	// 90 - 65  = 25임. 실제 영어 갯수는 26개라서 + 1;
	int arr_range = 'Z' - 'A' + 1;

	for(int i = exp-1; -1<i;i--) CountingSort(arr, arr_range, i);
}

int main()
{
	// CLRS 8.3-1
	vector<string> arr = { "COW", "DOG", "SEA", "RUG",
		"ROW", "MOB", "BOX", "TAB", "BAR", "EAR", "TAR",
		"DIG", "BIG", "TEA", "NOW", "FOX" };

	Print(arr);

	RadixSort(arr);

	Print(arr);

	return 0;
}