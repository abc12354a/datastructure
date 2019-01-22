#include<iostream>
#include<string>
using namespace std;
int main() {
	string A[10];
	int num;
	int flagA;
	int flag[10] = { -1 };
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < num; i++)
	{
		const char* temp = A[i].data();
		int j = 0;
		flagA = 0;
		while (temp[j] =='A')
		{
			j++;
		}
		if (temp[j] == 'P') {
			j++;
			while (temp[j] == 'A')
			{
				flagA = 1;
				j++;
			}
			if (temp[j] == 'T'&& flagA) {
				j++;
				while (temp[j] == 'A') {
					j++;
				}
				if (temp[j] != '\0')
					break;
				flag[i] = 1;
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
		
	}
	//std::cout << std::endl;
	for (size_t i = 0; i < num-1; i++)
	{
		if (flag[i] == 1)
			std::cout << "YES";
		else
		{
			std::cout << "NO";
		}
		std::cout << endl;
	}
	if (flag[num] == 1)
		std::cout << "YES";
	else
	{
		std::cout << "NO";
	}
	system("pause");
	return 0;
}
