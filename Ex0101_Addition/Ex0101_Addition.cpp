#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 문제 : 오버플로우 예외를 계산하지 못해서 문자를 하나하나 추가하는 형식 그 자릿수의, 그래서 로직이 많이 바뀌어야함.
// string Add(string str1, string str2)
// {
// 	// TODO:
// 	int exp = 1;
// 	int str1_idx = str1.size()-1;
// 	int str2_idx = str2.size()-1;
// 	int result = 0;

// 	while(str1_idx > -1 || str2_idx > -1){
//         if(str1_idx > -1 && str2_idx > -1){           // 둘 다 유효할 때
//             result += ((str1[str1_idx] - '0') + (str2[str2_idx] - '0')) * exp;
//             str1_idx--;
//             str2_idx--;
//         }
//         else if(str1_idx > -1){                       // str1만 남았을 때
//             result += (str1[str1_idx] - '0') * exp;
//             str1_idx--;
//         }
//         else if(str2_idx > -1){                       // str2만 남았을 때
//             result += (str2[str2_idx] - '0') * exp;
//             str2_idx--;
//         }
//         exp *= 10;
//     }

// 	cout << result << endl;
// 	return to_string(result);
// }
string Add(string str1, string str2) {
    string result;
    int carry = 0;
    int str1_idx = str1.size() - 1;
    int str2_idx = str2.size() - 1;
    
    // 한 자리씩 더하기
    while (str1_idx >= 0 || str2_idx >= 0 || carry) {
        int sum = carry;
        
        if (str1_idx >= 0)
            sum += (str1[str1_idx--] - '0');
        if (str2_idx >= 0)
            sum += (str2[str2_idx--] - '0');
        
        carry = sum / 10;        // 다음 자리로 올림
        result = char(sum % 10 + '0') + result;  // 현재 자리 숫자
    }
    
    return result;
}

int main()
{
	vector<vector<string>> tests = {
		{"12", "34", to_string(12 + 34)}
		, {"123", "45", to_string(123 + 45)}
		, {"54544", "44545", to_string(54544 + 44545)}
		, {"5555", "55", to_string(5555 + 55)}
		, {"5555", "5555", to_string(5555 + 5555)}
		, {"9823471235421415454545454545454544", "1714546546546545454544548544544545", "11538017781967960909090003089999089"}
	};

	for (const auto& t : tests)
	{
		const string str1 = t[0];     // "12"
		const string str2 = t[1];     // "34"
		const string expected = t[2]; // "46"

		cout << str1 << " + " << str2 << " = " << expected << endl;

		const string result = Add(str1, str2);

		cout << result << " " << expected << " ";

		if (result == expected)
			cout << "OK" << endl;
		else {
			cout << "Not OK" << endl;
			exit(-1);
		}
		cout << endl << endl;
	}

	cout << "Congratulations. All OK!" << endl;

	return 0;
}
