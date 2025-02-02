#include <string>
#include <vector>
#include <iostream>

using namespace std;
// 1차 시도 : string형 result를 사용함. 이러면 자릿수 마다 저장하기 힒듬.

string Multiply(string str1, string str2)
{
	// TODO:
	int N = str1.size() + str2.size();
	// string result(N, '0');
	vector<int> temp(N, 0);
	for(int i = str2.size()-1;i>-1;i--){
		for(int j = str1.size()-1;j>-1;j--){
			char n1 = str1[j] - '0';
			char n2 = str2[i] - '0';
			
			// int mul = n1 * n2;
			
			//  해당 부분은 자릿수 계산을 못해서 그런것 아주 간단한 방식으로 그려볼것 그냥 대충 생각한게 문제
			// result[i+j] = mul % 10 + '0';
			// result[i+j-1] = mul / 10 + '0';

			int sum = temp[i + j + 1] + (n1 * n2);
			temp[i + j + 1] = sum % 10;
            temp[i + j] += sum / 10;
		}
	}

	string result;
	bool check_empt = false;
	for(int i = 0; i<N; i++){
		if(temp[i] != 0){
			check_empt = true;
		}

		if(check_empt){
			result += char(temp[i] + '0'); // >> result = result + char(temp[i] + '0'); 그래서 뒤에 붙여짐
		}
	}

	return result.empty() ? "0" : result;
	
}

int main()
{
	vector<vector<string>> tests = {
		{"12", "34", std::to_string(12 * 34)},
		{"123", "45", std::to_string(123 * 45)},
		{"5555", "55", std::to_string(5555 * 55)},
		{"5555", "5555", std::to_string(5555 * 5555)},
		{"98234712354214154", "171454654654655", "16842798681791158832220782986870"}
		, {"9823471235421415454545454545454544", "1714546546546545454544548544544545", "16842798681791114273590624445460185389471221520083884298838480662480"}
	};

	for (const auto& t : tests)
	{
		const string str1 = t[0];
		const string str2 = t[1];
		const string expected = t[2];

		cout << str1 << " * " << str2 << " = " << expected << endl;

		const string result = Multiply(str1, str2);

		cout << result << " " << expected << " ";

		if (result == expected)
			cout << "OK";
		else {
			cout << "Not OK";
			exit(-1);
		}
		cout << endl << endl;
	}

	cout << "Congratulations. All OK!" << endl;

	return 0;
}
