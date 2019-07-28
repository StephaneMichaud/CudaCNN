#pragma once
#include <vector>
#include <functional>

class Tensor
{
public:

	Tensor(std::vector<unsigned int> dimensions);
	Tensor(std::vector<unsigned int> dimensions, std::function<float(void)>& filler);
	~Tensor();

	float operator()(std::vector<unsigned int> dimensions);
	std::vector<unsigned int> GetDimension();
private:
	void Initialize(std::vector<unsigned int> dimensions, std::function<float(void)>& filler);
	void InitializeData(std::function<float(void)>& filler);
	void InitializeSizes();
	int m_dataLength; // the total length of the p_data
	float* p_data; // all the elements of the tensor crammed into one vector
	std::vector<unsigned int> m_dimensions; // the count of sub-tensors of dimension[index].
	std::vector<unsigned int> m_sizes; // refer to the size of each dimension (present at dimension[index]) of the tensor, used to get a specific element 

	friend class ITensorCalculator;
};