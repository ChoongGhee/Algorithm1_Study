#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <iostream>

using namespace std;

void Print(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

// 가장 작은 값이 arr[lo]에 오도록 
void SelectionSortPass(vector<int>& arr, int lo, int hi)
{
	// TODO: 
	int min_idx = lo;
	for (int i = lo; i<hi ; i++){
		if(arr[min_idx] > arr[i]){
			min_idx = i;
		}
	}

	swap(arr[min_idx], arr[lo]);
}

void PartialSelectionSort(vector<int>& arr, int k)
{
	Print(arr);

	for (int i = 0; i < k; i++)
	{
		// SelectionSortPass( TODO: );
		SelectionSortPass(arr, i, arr.size());

		Print(arr);
	}
}

int main()
{
	vector<int> my_vector = { 7, 10, 4, 3, 20, 15 };

	int k = 3;

	PartialSelectionSort(my_vector, k);

	cout << my_vector[k - 1] << endl;
}
