#include "Tensor.h"
#include <numeric>
#include <stdarg.h>


Tensor::Tensor(std::vector<unsigned int> dimensions)
{
	std::function<float(void)> filler = []() -> float { return 0; };
	Initialize(dimensions, filler);
}

Tensor::Tensor(std::vector<unsigned int> dimensions, std::function<float(void)>& filler)
{
	Initialize(dimensions, filler);
}

void Tensor::Initialize(std::vector<unsigned int> dimensions, std::function<float(void)>& filler)
{
	m_dimensions = dimensions;
	m_dataLength = std::accumulate(dimensions.begin(),
		dimensions.end(), 1, std::multiplies<unsigned int>());
	p_data = new float[m_dataLength];
	InitializeSizes();
	InitializeData(filler);
}

Tensor::~Tensor()
{
	delete p_data;
}

// PUBLIC

std::vector<unsigned int> Tensor::GetDimension()
{
	return m_dimensions;
}

// PRIVATE

void Tensor::InitializeData(std::function<float(void)>& filler)
{
	if(p_data == nullptr)
		return;

	for (size_t i = 0; i < m_dataLength; ++i)
	{
		p_data[i] = filler();
	}
}

void Tensor::InitializeSizes()
{
	m_sizes = std::vector<unsigned int>(m_dimensions.size());
	m_sizes[m_sizes.size() - 1] = 1;
	for (size_t i = 0; i < m_sizes.size() - 1 ; ++i)
	{
		int subTensorSize = 1;
		for (size_t j = i + 1 ; j < m_dimensions.size(); ++j)
		{
			subTensorSize *= m_dimensions[j];
		}
		m_sizes[i] = subTensorSize;
	}
}
