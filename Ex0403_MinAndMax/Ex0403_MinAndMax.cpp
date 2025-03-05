#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr = { 8, 2, 3, 5, 9, 1, 9, 4, 3, 7, 6, 7 };

	// TODO:
	// 힌트 확인함.
	// 1. 현재 내 코드는 3n/2의 횟수를 갖고 있음. 
	// 2. 가장 처음에 i가 0일 경우는 한번의 비교만 하면됨 그렇다면 아래 두 if문은 필요없음. 
	// 3. 그래서 3n/2 -2의 횟수를 가짐
	for(int i = 0; i<arr.size(); i +=2){
		if(arr[i] > arr[i+1]) swap(arr[i], arr[i+1]);

		if(arr[0] > arr[i]) swap(arr[0], arr[i]);

		if(arr[i+1] > arr[1]) swap(arr[i+1], arr[1]);
	}

	cout << "Min value = " << arr[0] << ", Max value = " << arr[1] << endl; // Min value = 1, Max value = 9
}
