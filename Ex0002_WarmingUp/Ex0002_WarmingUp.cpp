#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 문제 1. 10진수 -> 2진수
	{
		int decimal = 105;
		string binary;

		//TODO:
		while (decimal > 0) {
			// 2로 나눈 나머지가 0인지 1인지 확인
			if (decimal % 2 == 0)
				binary = '0' + binary;  // 앞에 붙여줌
			else
				binary = '1' + binary;  // 앞에 붙여줌
			
			decimal = decimal / 2;
		}

		cout << binary << endl; // 1101001
	}

	// 문제 2. 문자열 뒤집기
	{
		string input = "Hello, World!";

		// TODO:
		for(int i = 0;i<(input.size()-1)/2;i++)
			swap(input[i], input[input.size()-1-i]);

		cout << input << endl; // !dlroW ,olleH
	}

	// 문제 3. 모든 자리 다 더하기
	// 이건 문제를 이해하지 못함. 자리수가 1이 될때 까지 더하는 것임.
	{
		string n = "789789";

		// TODO:
		// int sum = 0;
		// for(char c : n){
		// 	sum +=stoi(string(1, c));
		// }
		// cout << sum << endl;
		
		while (n.size() > 1)
        {
            int sum = 0;
            while (n.size() > 0)
            {
                sum += (n[0] - '0') % 10;
                n = n.substr(1, n.size() - 1);
            }
            cout << sum << endl;
            n = to_string(sum);
        }
        cout << n << endl; // 3 <- 기대 출력

		
	}

	return 0;
}
