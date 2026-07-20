#include "PmergeMe.hpp"

/******************************************/
/***********     ORTHODOX    **************/
/******************************************/

int ft_atoi(const std::string& str)
{
	std::stringstream ss(str);
	long long n;
	char c;

	if (!(ss >> n) || (ss >> c))
		throw(PmergeMe::BadInput());

	if (n < 0 || n > INT_MAX)
		throw(PmergeMe::BadNumberRange());

	return static_cast<int>(n);
}

void	PmergeMe::printElements(void) const
{
	std::pair<int, int> pair;

	for(size_t i = 0; i < _elements.size(); i++)
	{
		pair = _elements[i];

		std::cout << pair.first << " " << pair.second << " ";
	}
	if (_hasStraggler == true)
		std::cout << _straggler;
}

std::vector<size_t> JacobsthalOrder(size_t size)
{
	std::vector<size_t> order;
	std::vector<size_t> jacob;

	size_t n = size;

	if (n == 0)
		return order;

	// Jacobsthal numbers
	jacob.push_back(1);

	size_t j0 = 0;
	size_t j1 = 1;

	while (true)
	{
		size_t next = j1 + (2 * j0);

		if (next > n)
			break;

		jacob.push_back(next);

		j0 = j1;
		j1 = next;
	}

	size_t previous = 0;

	for (size_t i = 0; i < jacob.size(); i++)
	{
		size_t current = jacob[i];

		for (size_t k = current; k > previous; --k)
			order.push_back(k - 1);

		previous = current;
	}

	for (size_t k = n; k > previous; --k)
		order.push_back(k - 1);

	return order;
}

/******************************************/
/***********     ORTHODOX    **************/
/******************************************/

PmergeMe::PmergeMe() : _hasStraggler(false), _straggler(0){}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void) other;
	return (*this);
}

/******************************************/
/************       SORT     **************/
/******************************************/

void	PmergeMe::swap_sortPairs(void)
{
	int	tmp;
	for(size_t i = 0; i < _elements.size(); i++)
	{
		if (_elements[i].first > _elements[i].second)
		{
			tmp = _elements[i].first;
			_elements[i].first =_elements[i].second;
			_elements[i].second = tmp;  
		}
	}
}

void PmergeMe::merge(size_t left, size_t mid, size_t right)
{
	std::vector<std::pair<int, int> > tmp;

	size_t i = left;
	size_t j = mid;

	while (i < mid && j < right)
	{
		if (_elements[i].second < _elements[j].second)
			tmp.push_back(_elements[i++]);
		else
			tmp.push_back(_elements[j++]);
	}

	while (i < mid)
		tmp.push_back(_elements[i++]);

	while (j < right)
		tmp.push_back(_elements[j++]);

	for (size_t k = 0; k < tmp.size(); k++)
		_elements[left + k] = tmp[k];
}

void	PmergeMe::mergeSort(size_t left, size_t right)
{
	size_t mid = (right + left) / 2;
 
	if (right - left <= 1)
		return;
	
	mergeSort(left, mid);
	mergeSort(mid, right);
	merge(left, mid, right);
}

void PmergeMe::buildMainChain()
{
	_chain.clear();
	_pend.clear();

	if (_elements.empty())
		return;

	_chain.push_back(_elements[0].first);

	for (size_t i = 0; i < _elements.size(); i++)
		_chain.push_back(_elements[i].second);

	for (size_t i = 1; i < _elements.size(); i++)
		_pend.push_back(_elements[i].first);
}

void	PmergeMe::binaryInsert(int value)
{
	size_t left = 0;
	size_t right = _chain.size();

	while (left < right)
	{
		size_t mid = left + (right - left) / 2;

		if (_chain[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	_chain.insert(_chain.begin() + left, value);
}

void	PmergeMe::insertPendElements(std::vector<size_t> order)
{
	for (size_t i = 0; i < order.size(); i++)
	{
		size_t idx = order[i];
		int value = _pend[idx];
		binaryInsert(value);
	}

	if (_hasStraggler == true)
		binaryInsert(_straggler);
}

void	PmergeMe::sort(void)
{
	swap_sortPairs();
	if (_elements.size() > 1)
		mergeSort(0, _elements.size());
	buildMainChain();
	insertPendElements(JacobsthalOrder(_pend.size()));
}

/******************************************/
/***********      METHODS    **************/
/******************************************/

void	PmergeMe::init(int ac, char** av)
{
	bool lock = false;
	std::pair<int, int> pair;

	for(int i = 1 ; i < ac; i++)
	{
		std::stringstream ss(av[i]);
		std::string line;

		while(getline(ss, line, ' '))
		{
			if (lock == false)
			{
				pair.first = ft_atoi(line);
				lock = true;
			}
			else
			{
				pair.second = ft_atoi(line);
				_elements.push_back(pair);
				lock = false;
			}
		}
	}
	if (lock == true)
	{
		_hasStraggler = true;
		_straggler = pair.first;
	}
}

void	PmergeMe::lunch(void)
{
	std::cout << "before: "; printElements(); std::cout << std::endl;
	
	sort();
	
	std::cout << "after :";
	for(size_t i = 0; i < _chain.size(); i++)
		std::cout << _chain[i] << " ";
	std::cout << "\n";
}

/******************************************/
/***********      EXCEPTION    ************/
/******************************************/

const char* PmergeMe::BadNumberRange::what() const throw()
{
	return ("0 <= nuber <= INT_MAX");
}

const char* PmergeMe::BadInput::what() const throw()
{
	return ("a non space/digit char was found");
}