#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <iostream>

#include <algorithm>
using namespace std;

void Print(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

int Count1(const vector<int>& arr, int x)
{
	//TODO: O(n)
	int cnt = 0;
	int len = arr.size();
	for(int i = 0; i<len;i++){
		if(arr[i] == x)
			cnt++;
	}

	return cnt;
}

int Count2(const vector<int>& arr, int x)
{
	//TODO: O(log(n) + count)
	
	// 실수1 : 아래 아무것도 없을 경우 생각 못함
	if (arr.empty()) return 0;

	int idx = arr.size()/2;
	// 실수2 : 아래 조건문은 내부 조건문에 의해 항상 성립됨 고로 불필요
	// while( 0 <= idx && idx < arr.size()){

	// 실수3 : 결국 무한루프 방지를 위해 이전 인덱스 필요
	// while(true){
	// 	if(arr[idx] == x) break;
	// 	else if(arr[idx] < x) idx = (arr.size()+idx)/2;
	// 	else idx /= 2;

	// 	// 실수 2 답안 : 무한루프 방지 (더이상  변하지 않는다면 종료)
	// 	if(idx == (arr.size()+idx)/2 || idx == idx/2) break;
	// }

	// 실수 5 (범위 축소가 이상함함)
	// int prev_idx;
	// while(true) {
	// 	if(arr[idx] == x) break;
	// 	prev_idx = idx;
	// 	//   범위를 좁혀서 찾아야하는데 이상한 공식으로 찾고 있었음. 
		//   범위가 mid(가운데) 기준으로 증가 감소만 함.
	// 	if(arr[idx] < x) idx = (arr.size()+idx)/2;
	// 	else idx /= 2;

	// 	if(prev_idx == idx) break;  // 위치가 더 이상 변하지 않으면 종료
	// }
	int prev_idx;
	int step = arr.size() / 4;
	while(step > 0) {
		if(arr[idx] == x) break;
		
		prev_idx = idx;
		if(arr[idx] < x) {
			idx = idx + step;
		} else {
			idx = idx - step;
		}
		step = step / 2 > 0 ? step / 2 : 1;  // 스텝 크기 축소
		// 스텝 크기가 왜 0이 되면 안되는 이유
		// 		이 코드에서 문제는 step이 0이 되면서 종료되지만, 이전에 실행한 마지막 이동이 실제로 x를 찾지 못했을 수 있다는 점입니다.
		// 무슨 일이 일어나는지 단계별로 설명하겠습니다:
		// 예를 들어 1 1 1 2 3 3 4 4 5 6 7 7 7 7 8 9 9 9 9 10 배열에서 x = 6을 찾으려고 할 때:

		// 초기 idx = 10 (배열 중간), step = 5
		// arr[10] = 7 > 6이므로 idx = 10 - 5 = 5
		// arr[5] = 3 < 6이므로 idx = 5 + 2 = 7 (step = 2)
		// arr[7] = 4 < 6이므로 idx = 7 + 1 = 8 (step = 1)
		// arr[8] = 5 < 6이므로 idx = 8 + 0 = 8 (step = 0)
		// 이제 step이 0이 되어 루프가 종료됩니다. 하지만 arr[8] = 5 != 6이므로 x를 찾지 못했습니다.

		// 문제는 마지막 단계에서 step이 0이 되어 루프가 종료되었지만, 마지막으로 확인한 위치가 target 값인지 확인하지 않았다는 것입니다. 이 경우 arr[idx] != x이므로 0을 반환합니다.
		// 해결 방법:

		// step이 0이 되기 전에 한 번 더 시도하는 방법 (step = 0.5를 1로 반올림)
		// 루프 후에 인접한 인덱스를 추가로 확인하는 방법

	
		// 스텝이 1이고 이전과 같은 위치를 반복 검사하게 되면 종료
		// 다음 두 조건이 모두 참일 때:
		// a. (idx + step >= arr.size() || arr[idx + step] > x):

		// idx + step >= arr.size(): 오른쪽으로 한 스텝 이동했을 때 배열 범위를 벗어나거나
		// arr[idx + step] > x: 오른쪽으로 한 스텝 이동했을 때 값이 x보다 커짐

		// b. (idx - step < 0 || arr[idx - step] < x):

		// idx - step < 0: 왼쪽으로 한 스텝 이동했을 때 배열 범위를 벗어나거나
		// arr[idx - step] < x: 왼쪽으로 한 스텝 이동했을 때 값이 x보다 작아짐
		if(step == 1 && ((idx + step >= arr.size() || arr[idx + step] > x) && 
                     (idx - step < 0 || arr[idx - step] < x))) {
        break;
    }
			
	}

	// 실수4 : x를 찾지 못했으면 0 반환 (생각 못함)
    if (arr[idx] != x) return 0;

	int minus = idx - 1 < 0 ? 0 : idx -1;
	int plus = idx + 1 > arr.size() ? arr.size() -1: idx + 1;
	
	int cnt = 1;

	while((minus >= 0 && arr[minus] == x) || (plus < arr.size() && arr[plus] == x)) {
        if(minus >= 0 && arr[minus] == x) {
            cnt++;
            minus--;
			// cout << "hello1" << endl;
        }
        if(plus < arr.size() && arr[plus] == x) {
            cnt++;
            plus++;
			
        }
    }

    return cnt;

}

// 실수 : 접근할 때 Count2 처럼 접근해서 안되는 것. 그냥 2번 이분탐색하는 것이 맞음.
// int Count3(const vector<int>& arr, int x)
// {
// 	//TODO: O(log(n))
// 	if (arr.empty()) return 0;

// 	int idx = arr.size()/2;
// 	int prev_idx;
// 	while(true) {
// 		if(arr[idx] == x) break;
// 		prev_idx = idx;
// 		if(arr[idx] < x) idx = (arr.size()+idx)/2;
// 		else idx /= 2;
		
// 		if(prev_idx == idx) break;  // 위치가 더 이상 변하지 않으면 종료
// 	}

// 	if (arr[idx] != x) return 0;

// 	// int r_idx = (arr.size() + idx)/2;
// 	// int l_idx = idx/2;

// 	// x를 찾은 위치(idx)에서 시작
// 	int r_idx = idx;
// 	int l_idx = idx;
// 	// 오른쪽 경계 찾기
// 	while(r_idx < arr.size() && arr[r_idx] == x) {
// 		if(r_idx == arr.size()-1 || arr[r_idx+1] != x) break;
// 		int next = (r_idx + arr.size()) / 2;
// 		if(next == r_idx) break;  // 더 이상 이동할 수 없음
// 		r_idx = next;
// 	}

// 	// 왼쪽 경계 찾기
// 	while(l_idx >= 0 && arr[l_idx] == x) {
// 		if(l_idx == 0 || arr[l_idx-1] != x) break;
// 		int next = l_idx / 2;
// 		if(next == l_idx) break;  // 더 이상 이동할 수 없음
// 		l_idx = next;
// 	}
//     return r_idx - l_idx + 1;
// }


int Count3(const vector<int>& arr, int x){

	if (arr.empty()) return 0;
	
	int mid, left , right;
	left = 0;
	// 실수 1 인덱스는 size -1까지 임
	right = arr.size() - 1;

	while(left <= right){
		// 실수 2 mid를 갱신할 때 while문 마지막에 해버리면 left < right 검사 후 제대로 된 값이 안나옴. 즉 순서가 잘못됨.
		mid = (left+right) / 2;

		// cout << left << " " << mid << " " << right << endl;
		// cout << arr[mid] << endl;

		// 실수 3 범위를 변경할 때 반대로 작동하도록 함.
		// 의문 항상 -1 +1을 해야하나 안해야하나 고민이 되는데 그땐 mid값을 검사했냐 안했냐를 기준으로 생각하자.
		// 정리 1. (무한루프 방지) left + 1, right -1은 국룰임. 이미 mid 검사를 했기도 하고 범위를 축소해야 무한루프가 돌지 않기 때문
		// 정리 2. (고민할 것은 목표값과의 관계), if문을 어떻게 설정하느냐에 따라 값이 반환되는게 달라짐. 위에 말한 mid검사가 이걸 말하는것.
		if(arr[mid] >= x){
			right = mid -1 ;

		}
		else{
			left = mid + 1;
		}
	
	}

	// 실수 4 one 값이 while문이 완료된 mid일 수가 있나? 
	int one = left;

	if(arr[one] != x) return 0;

	left = 0;
	right = arr.size()-1;

	while(left <= right){
		mid = (left+right) / 2;
		
		// cout << left << " " << mid << " " << right << endl;
		// cout << arr[mid] << endl;

		if(arr[mid] <= x){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}

	int two = right;
	if(arr[two] != x) return 0; 
	

	return (two - one + 1);

}

int main()
{
	random_device rd;
	mt19937 gen(rd());

	const int n = 20;
	vector<int> my_vector(n);

	int x = 6; // target to find

	for (int r = 0; r < 100; r++)
	{
		uniform_int_distribution<int> value_distribution(1, 10);
		generate(my_vector.begin(), my_vector.end(), [&]() { return value_distribution(gen); });
		sort(my_vector.begin(), my_vector.end());

		Print(my_vector);

		const int expected_count = std::count(my_vector.begin(), my_vector.end(), x);

		cout << "Expected count = " << expected_count << endl;

		// 1. O(n) brute force
		if (Count1(my_vector, x) != expected_count)
		{
			cout << "Wrong count1: " << Count1(my_vector, x) << endl;
			exit(-1);
		}

		// 2. O(log(n) + count)
		if (Count2(my_vector, x) != expected_count)
		{
			cout << "Wrong count2: " << Count2(my_vector, x) << endl;
			exit(-1);
		}

		// 3. O(log(n))
		if (Count3(my_vector, x) != expected_count)
		{
			cout << "Wrong count3: " << Count3(my_vector, x) << endl;
			exit(-1);
		}
	}

	cout << "Good!" << endl;

	return 0;
}
