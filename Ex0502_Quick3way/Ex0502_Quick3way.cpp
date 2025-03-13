#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

void Print(vector<int>& arr, int lo, int hi, string sep = "")
{
	//cout << "Index: ";
	//for (int i = 0; i < arr.size(); i++)
	//	cout << setfill(' ') << setw(3) << i;
	//cout << endl;

	cout << "Value: ";
	for (int i = 0; i < arr.size(); i++) {

		if (lo <= i && i <= hi)
			cout << setfill(' ') << setw(3) << arr[i] << sep;
		else
			cout << "   ";
	}
	cout << endl;
}

// Quicksort with 3-way partitioning, Sedgewick p299
// (Dijkstra's Dutch national flag problem)
void Quick3way(vector<int>& arr, int lo, int hi)
{
	if (hi <= lo) return;

	int lt = lo, i = lo, gt = hi;
	int v = arr[lo];
	cout << "Pivot" << v << endl;
	while (i <= gt)
	{
		// TODO:
		// 실수 1 : 분할로 들어갈때 제대로 정렬되지 않은채 진행함. 그래서 꼬임 lt가 gt까지 도달해야지 다 검사한건데
		if(arr[i] == v) i++;
		// 헷갈리는 점 : 왜 i++을 해줘야하는가?
		// lt자리의 값은 i가 항상 검사를 함. swap을 하면 이미 검증된 값이 해당 i자리에 위치하기 때문에 검사하지않고 ++함.
		// else if(arr[i] < v) swap(arr[lt++], arr[i]);
		else if(arr[i] < v) swap(arr[lt++], arr[i++]);
		else swap(arr[i], arr[gt--]);
		Print(arr, lo, hi);
	}

	// Print(arr, lo, hi);

	Quick3way(arr, lo, lt - 1);
	Quick3way(arr, gt + 1, hi);
}

int main()
{
	srand(0);

	// vector<int> arr = { 3, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 2, 3, 4, 5, 1, 3, 5 };
	// vector<int> arr = { 4,8,6,2,5,7,9,1,3,6,8,4,6,1,33,1,3,1,5,4,3,1,5,6,8,4,3,2,1 };
	vector<int> arr = { 4,1,6,2,4};

	Print(arr, 0, arr.size() - 1);

	Quick3way(arr, 0, arr.size() - 1);

	Print(arr, 0, arr.size() - 1);

	return 0;
}
