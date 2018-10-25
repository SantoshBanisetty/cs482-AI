#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	int arr[2][3][4] = { { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} },
                     { {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4} } };

    for (int i = 0; i < 3; i++)
    {
    	/* code */
    	for (int j = 0; j < 4; j++)
    	{
    		/* code */
    		cout << arr[1][i][j] << endl;
    	}
    }
	return 0;
}

