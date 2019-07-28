#include <iostream>
#include <random>
#include <time.h>
#include "Tensor.h"

using namespace std;

#define MAX_SIZE 10

#define	ONE_D 1
#define TWO_D 2
#define THREE_D 3
#define FOUR_D 4

static std::function<float(void)> RandomFiller = []() 
{
	return (float)(rand() % (MAX_SIZE + 1));
};

int main()
{
	srand(time(NULL));
	Tensor testTensor({ 4, 3, 2, 2 }, RandomFiller);
	for (size_t i = 0; i < 4; ++i)
	{
		for (size_t j = 0; j < 3; ++j)
		{
			for (size_t k = 0; k < 2; ++k)
			{
				for (size_t l = 0; l < 2; ++l)
				{
					cout << testTensor({i,j,k,l}) << " ";
				}
				cout << endl;
			}
			cout << endl;
			cout << endl;
		}
	}


	while (true);
	return 0;
}