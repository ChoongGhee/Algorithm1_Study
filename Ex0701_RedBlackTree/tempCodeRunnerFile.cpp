	// Search 테스트
		for (char c : keys)
		{
			cout << c << " " << int(c) << " " << bst.Search(string(1, c)) << endl;
		}

		bst.Print2D();