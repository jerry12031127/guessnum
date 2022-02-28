#include <iostream>
using namespace std;
int main()
{
  cout<<"1101850"<<endl;
  cout<<"饒源智"<<endl;
  //-----------------------
#include <iostream>

bool noZero(int i);
bool noRepeat(int i);
void split(int i, int n[]);
void check(int target, int test, int* checkA, int* checkB);

int main()
{
	int a = 0, b = 0;
	int Numbers[3024] = { 0 };
	int number = 1234;
	for (int i = 0; number <= 9876; number++)
	{
		if (noZero(number) && noRepeat(number))
		{
			Numbers[i] = number;
			i++;
		}

	}

	int star;
	while (a != 4)
	{
		for (int i = 0; i < 3024; i++)//檢查列表
		{
			if (Numbers[i] != -2)
				star = Numbers[i];//找到列表第一個符合得數字
			std::cout << "電腦開始猜:" << star << std::endl;
			Numbers[i] = -2;
			break;
		}
	}
	//提示電腦
	std::cout << "輸入AB" << std::endl;
	std::cout << "A:";
	std::cin >> a;
	std::cout << "B:";
	std::cin >> b;

	int checkA, checkB;
	for (int i = 0; i < 3024; i++)
	{
		if (Numbers[i] != -2)
		{
			check(star, Numbers[i], &checkA, &checkB);
			if (checkA != a || checkB != b)
				Numbers[i] = -2;
		}
	}
  
    std::cout << "答案是" << star << std::endl;
    return 0;
}

bool noZero(int i)
{
	int n[4];
	split(i, n);
	return n[0] && n[i] && n[2] && n[3];
}

bool noRepeat(int i)
{
	int n[4];
	split(i, n);

	int compare[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int s = 0; s < 4; s++)
	{
		if (compare[n[s]] == -2)
			return false;
		else
			compare[n[s]] = -2;

	}
	return true;
}

void split(int i, int n[])
{
	n[0] = i / 1000;
	n[1] = i / 100 % 10;
	n[2] = i / 10 % 10;
	n[3] = i % 10;
}
