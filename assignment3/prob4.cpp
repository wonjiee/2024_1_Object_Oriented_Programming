#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

class Omok
{
public:
	int Omok_line = 0;
	vector<int> number1;
	vector<int> number2;
};

vector<string> split_line(string line, char delimiter)
{
	vector<string> numbers;
	stringstream sstrem(line);
	string str;
	while (getline(sstrem, str, delimiter))
		numbers.push_back(str);
	return numbers;
}

int diagonal(int n, vector<Omok> &data)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < data[i].number2.size(); j++)
		{
			if (data[i].number2.size() == 0)
			{
				break;
			}
			int num2_location = data[i].number2[j];
			if (num2_location > 3 && i < n - 3)
			{
				for (int a = 0; a < data[i + 1].number2.size(); a++)
				{
					if (num2_location - 1 == data[i + 1].number2[a])
					{
						for (int a = 0; a < data[i + 2].number2.size(); a++)
						{
							if (num2_location - 2 == data[i + 2].number2[a])
							{
								for (int a = 0; a < data[i + 3].number2.size(); a++)
								{
									if (num2_location - 3 == data[i + 3].number2[a])
									{
										for (int a = 0; a < data[i + 4].number2.size(); a++)
										{
											if (num2_location - 4 == data[i + 4].number2[a])
											{
												return 2;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < data[i].number1.size(); j++)
		{
			if (data[i].number1.size() == 0)
			{
				break;
			}
			int num1_location = data[i].number1[j];
			if (num1_location > 3 && i < n - 3)
			{
				for (int a = 0; a < data[i + 1].number1.size(); a++)
				{
					if (num1_location - 1 == data[i + 1].number1[a])
					{
						for (int a = 0; a < data[i + 2].number1.size(); a++)
						{
							if (num1_location - 2 == data[i + 2].number1[a])
							{
								for (int a = 0; a < data[i + 3].number1.size(); a++)
								{
									if (num1_location - 3 == data[i + 3].number1[a])
									{
										for (int a = 0; a < data[i + 4].number1.size(); a++)
										{
											if (num1_location - 4 == data[i + 4].number1[a])
											{
												return 1;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < data[i].number2.size(); j++)
		{
			if (data[i].number2.size() == 0)
			{
				break;
			}
			int num2_location = data[i].number2[j];
			if (num2_location < n - 3 && i < n - 3)
			{
				for (int a = 0; a < data[i + 1].number2.size(); a++)
				{
					if (num2_location + 1 == data[i + 1].number2[a])
					{
						for (int a = 0; a < data[i + 2].number2.size(); a++)
						{
							if (num2_location + 2 == data[i + 2].number2[a])
							{
								for (int a = 0; a < data[i + 3].number2.size(); a++)
								{
									if (num2_location + 3 == data[i + 3].number2[a])
									{
										for (int a = 0; a < data[i + 4].number2.size(); a++)
										{
											if (num2_location + 4 == data[i + 4].number2[a])
											{
												return 2;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < data[i].number2.size(); j++)
		{
			if (data[i].number1.size() == 0)
			{
				break;
			}
			int num1_location = data[i].number1[j];
			if (num1_location < n - 3 && i < n - 3)
			{
				for (int a = 0; a < data[i + 1].number1.size(); a++)
				{
					if (num1_location + 1 == data[i + 1].number1[a])
					{
						for (int a = 0; a < data[i + 2].number1.size(); a++)
						{
							if (num1_location + 2 == data[i + 2].number1[a])
							{
								for (int a = 0; a < data[i + 3].number1.size(); a++)
								{
									if (num1_location + 3 == data[i + 3].number1[a])
									{
										for (int a = 0; a < data[i + 4].number1.size(); a++)
										{
											if (num1_location + 4 == data[i + 4].number1[a])
											{
												return 1;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

int right_Omok(int n, vector<Omok> &data)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < data[i].number1.size(); j++)
		{
			if (data[i].number1.size() == 0)
			{
				break;
			}
			if (data[i].number1[j] > n - 5)
			{
				break;
			}
			if (data[i].number1[j] + 1 == data[i].number1[j + 1])
			{
				if (data[i].number1[j + 1] + 1 == data[i].number1[j + 2])
				{
					if (data[i].number1[j + 2] + 1 == data[i].number1[j + 3])
					{
						if (data[i].number1[j + 3] + 1 == data[i].number1[j + 4])
						{
							return 1;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < data[i].number2.size(); j++)
		{
			if (data[i].number2.size() == 0)
			{
				break;
			}
			if (data[i].number2[j] > n - 5)
			{
				break;
			}
			if (data[i].number2[j] + 1 == data[i].number2[j + 1])
			{
				if (data[i].number2[j + 1] + 1 == data[i].number2[j + 2])
				{
					if (data[i].number2[j + 2] + 1 == data[i].number2[j + 3])
					{
						if (data[i].number2[j + 3] + 1 == data[i].number2[j + 4])
						{
							return 2;
						}
					}
				}
			}
		}
	}
	return 0;
}

int down_Omok(int n, vector<Omok> &data)
{
	for (int i = 0; i < n - 3; i++)
	{
		for (int j = 0; j < data[i].number2.size(); j++)
		{
			if (data[i].number2.size() == 0)
			{
				break;
			}
			int num2_location = data[i].number2[j];
			if (i < n - 3)
			{
				for (int a = 0; a < data[i + 1].number2.size(); a++)
				{
					if (data[i + 1].number2[a] == num2_location)
					{
						for (int a = 0; a < data[i + 2].number2.size(); a++)
						{
							if (data[i + 2].number2[a] == num2_location)
							{
								for (int a = 0; a < data[i + 3].number2.size(); a++)
								{
									if (data[i + 3].number2[a] == num2_location)
									{
										for (int a = 0; a < data[i + 4].number2.size(); a++)
										{
											if (data[i + 4].number2[a] == num2_location)
											{
												return 2;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < data[i].number1.size(); j++)
		{
			if (data[i].number1.size() == 0)
			{
				break;
			}
			int num1_location = data[i].number1[j];
			if (i < n - 3)
			{
				for (int a = 0; a < data[i + 1].number1.size(); a++)
				{
					if (data[i + 1].number1[a] == num1_location)
					{
						for (int a = 0; a < data[i + 2].number1.size(); a++)
						{
							if (data[i + 2].number1[a] == num1_location)
							{
								for (int a = 0; a < data[i + 3].number1.size(); a++)
								{
									if (data[i + 3].number1[a] == num1_location)
									{
										for (int a = 0; a < data[i + 4].number1.size(); a++)
										{
											if (data[i + 4].number1[a] == num1_location)
											{
												return 1;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

int main()
{
	ifstream infile("board.txt");
	vector<Omok> data;
	string line;
	int size = 0;
	int line_numbers = 0;
	vector<int> number1;
	vector<int> number2;
	while (getline(infile, line))
	{
		if (size == 0)
		{
			size = stoi(line);
			continue;
		}
		vector<string> numbers = split_line(line, ' ');
		Omok tmp;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] == "1")
				tmp.number1.push_back(i);
			if (numbers[i] == "2")
				tmp.number2.push_back(i);
		}
		tmp.Omok_line = line_numbers;
		data.push_back(tmp);
		line_numbers++;
	}
	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i].Omok_line << endl;
		for (int j = 0; j < data[i].number1.size(); j++)
			cout << data[i].number1[j] << " ";
		cout << endl;
		for (int k = 0; k < data[i].number2.size(); k++)
			cout << data[i].number2[k] << " ";
		cout << endl;
	}
	int value = diagonal(size, data);
	int value1 = right_Omok(size, data);
	int value2 = down_Omok(size, data);
	cout << value << endl;
	cout << value1 << endl;
	cout << value2 << endl;
	string result = "Not";
	if (value1 == 1 || value == 1 || value2 == 1)
	{
		result = "Black";
	}
	if (value1 == 2 || value == 2 || value2 == 2)
	{
		result = "White";
	}
	cout << result;

	return 0;
}
