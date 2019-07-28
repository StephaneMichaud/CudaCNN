#include <iostream>
#include <random>
#include <time.h>
#include "Tensor.h"

using namespace std;

#define MAX_SIZE 10

static std::function<float(void)> RandomFiller = []() 
{
	return (float)(rand() % (MAX_SIZE + 1));
};

int main()
{
	Tensor t({ 3,2,2 });
	return 0;
}