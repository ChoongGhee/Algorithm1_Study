	for (int length = 0; length < price_table.size(); length++)
	{
		cout << "Length: " << length << endl;
		int revenue = ExtendedBottomUpCutRod(price_table, length);
		cout << "Optimal revenue: " << revenue << endl;
	}
