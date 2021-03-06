#include <iostream>

#define MAX_LEN 100

using namespace std;

int main()
{
	int n, l, length, mid;
	bool flag = false;
	int list[MAX_LEN + 1]{ 0, };
	cin >> n >> l;

	for (length = l; length <= MAX_LEN; length++)
	{
		if (length % 2 == 1)//when length is odd num mid num is n / length
		{
			if (n % length != 0) continue;
			mid = n / length;
			if (mid < (length - 1) / 2) continue;//list[0] must be positive num
			for (int i = 0; i < length; i++)
				list[i] = mid - (length - 1) / 2 + i;
			flag = true;
			break;
		}
		//when length is even num list[length / 2 -1] + list[length / 2] = 2 * n / length
		if ((2 * n / length) % 2 == 0 || 2 * n % length != 0) continue;
		mid = (2 * n / length) / 2;
		if (mid < length / 2 - 1) continue;//list[0] must be positive num
		for (int i = 0; i < length; i++)
			list[i] = mid - (length / 2 - 1) + i;
		flag = true;
		break;
	}
	if (flag == false)
		cout << -1;
	else
	{
		for (int i = 0; i < length; i++)
			cout << list[i] << " ";
	}
	return 0;
}