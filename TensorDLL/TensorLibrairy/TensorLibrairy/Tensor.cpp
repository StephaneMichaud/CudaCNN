/*#include "Tensor.h"
#include <numeric>
#include <stdarg.h>


Tensor(std::vector<unsigned int> dimensions)
{
	std::function<float(void)> filler = []() -> float { return 0; };
	Initialize(dimensions, filler);
}

Tensor(std::vector<unsigned int> dimensions, std::function<float(void)>& filler)
{
	Initialize(dimensions, filler);
}

void Initialize(std::vector<unsigned int> dimensions, std::function<float(void)>& filler)
{
	m_dimensions = dimensions;
	m_dataLength = std::accumulate(dimensions.begin(),
		dimensions.end(), 1, std::multiplies<unsigned int>());
	p_data = new float[m_dataLength];
	InitializeSizes();
	InitializeData(filler);
}

~Tensor()
{
	delete p_data;
}

// PUBLIC
float operator()(const unsigned int count, ...)
{
	va_list ap;
	va_start(ap, count);
	unsigned int index = 0;
	for (size_t i = 0; i < m_sizes.size() ; ++i)
	{
		index += va_arg(ap, unsigned int) * m_sizes[i];
	}
	va_end(ap);

	if (index >= m_dataLength || index < 0)
		throw new std::runtime_error("Tensor index was out of range.");
	return p_data;

}

std::vector<unsigned int> GetDimension()
{
	return m_dimensions;
}

// PRIVATE
float* GetPData()
{
	return p_data;
}

void InitializeData(std::function<float(void)>& filler)
{
	if(p_data == nullptr)
		return;

	for (size_t i = 0; i < m_dataLength; ++i)
	{
		p_data[i] = filler();
	}
}

void InitializeSizes()
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
}*/
