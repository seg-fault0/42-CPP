#pragma once

//libraries
# include <vector>
# include <iostream>
# include <sstream>
# include <climits>
# include <stdexcept>
# include <deque>
# include <ctime>

//class
template <typename PairContainer, typename IntContainer  >
class PmergeMe
{
	private:
		PairContainer	_elements;
		IntContainer	_chain;
		IntContainer	_pend;
		bool			_hasStraggler;
		int				_straggler;
		std::string		_before;
		double			_time;

	private:
		void	binaryInsert(int value);
		void	insertPendElements(const std::vector<size_t>& order);
		void	buildMainChain(void);
		void	merge(size_t left, size_t mid, size_t right);
		void	mergeSort(size_t left, size_t right);
		void	swap_sortPairs(void);
		void	sort(void);

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		void	init(int ac, char** av);
		void	lunch(void);

		size_t			getSize(void) const; 
		std::string		getBefore(void) const;
		std::string		getAfter(void) const;
		double			getTime(void) const;

		class BadNumberRange : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class BadInput : public std::exception
		{
			public:
				const char* what() const throw();
		};
};


/******************************************/
/***********     HELPERS     **************/
/******************************************/

template <typename PairContainer, typename IntContainer>
int ft_atoi(const std::string& str)
{
	std::stringstream ss(str);
	long long n;
	char c;

	if (!(ss >> n) || (ss >> c))
		throw(typename PmergeMe<PairContainer, IntContainer>::BadInput());

	if (n < 0 || n > INT_MAX)
		throw(typename PmergeMe<PairContainer, IntContainer>::BadNumberRange());

	return (static_cast<int>(n));
}

inline std::vector<size_t> JacobsthalOrder(size_t size)
{
	std::vector<size_t> order;
	std::vector<size_t> jacob;

	if (size == 0)
		return (order);

	jacob.push_back(1);

	size_t j0 = 0;
	size_t j1 = 1;

	while (true)
	{
		size_t next = j1 + (2 * j0);

		if (next > size)
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

	for (size_t k = size; k > previous; --k)
		order.push_back(k - 1);

	return (order);
}

/******************************************/
/***********     ORTHODOX    **************/
/******************************************/

template <typename PairContainer, typename IntContainer>
PmergeMe<PairContainer, IntContainer>::PmergeMe() : _hasStraggler(false), _straggler(0) {}

template <typename PairContainer, typename IntContainer>
PmergeMe<PairContainer, IntContainer>::~PmergeMe() {}

template <typename PairContainer, typename IntContainer>
PmergeMe<PairContainer, IntContainer>::PmergeMe(const PmergeMe& other) { *this = other; }

template <typename PairContainer, typename IntContainer>
PmergeMe<PairContainer, IntContainer>& PmergeMe<PairContainer, IntContainer>::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_elements = other._elements;
		_chain = other._chain;
		_pend = other._pend;
		_hasStraggler = other._hasStraggler;
		_straggler = other._straggler;
	}
	return (*this);
}

/******************************************/
/************       SORT     **************/
/******************************************/

template <typename PairContainer, typename IntContainer>
void PmergeMe<PairContainer, IntContainer>::binaryInsert(int value)
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

template <typename PairContainer, typename IntContainer>
void PmergeMe<PairContainer, IntContainer>::insertPendElements(
	const std::vector<size_t>& order)
{
	for (size_t i = 0; i < order.size(); i++)
		binaryInsert(_pend[order[i]]);

	if (_hasStraggler)
		binaryInsert(_straggler);
}

template <typename PairContainer, typename IntContainer>
void PmergeMe<PairContainer, IntContainer>::buildMainChain()
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


template <typename PairContainer, typename IntContainer>
void PmergeMe<PairContainer, IntContainer>::merge(size_t left, size_t mid, size_t right)
{
	PairContainer tmp;

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

template <typename PairContainer, typename IntContainer>
void PmergeMe<PairContainer, IntContainer>::mergeSort(size_t left,size_t right)
{
	if (right - left <= 1)
		return;

	size_t mid = (left + right) / 2;

	mergeSort(left, mid);
	mergeSort(mid, right);
	merge(left, mid, right);
}

template <typename PairContainer, typename IntContainer>
void PmergeMe<PairContainer, IntContainer>::swap_sortPairs()
{
	for (size_t i = 0; i < _elements.size(); i++)
	{
		if (_elements[i].first > _elements[i].second)
			std::swap(_elements[i].first, _elements[i].second);
	}
}

template <typename PairContainer, typename IntContainer>
void PmergeMe<PairContainer, IntContainer>::sort()
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

template <typename PairContainer, typename IntContainer>
void PmergeMe<PairContainer, IntContainer>::init(
	int ac,
	char** av)
{
	bool lock = false;
	std::pair<int, int> pair;

	for (int i = 1; i < ac; i++)
	{
		std::stringstream ss(av[i]);
		std::string line;

		while (getline(ss, line, ' '))
		{
			if (line.empty())
				continue;

			if (!lock)
			{
				pair.first = ft_atoi<PairContainer, IntContainer>(line);
				_before += line;
				_before += " ";
				lock = true;
			}
			else
			{
				pair.second =ft_atoi<PairContainer, IntContainer>(line);
				_before += line;
				_before += " ";
				_elements.push_back(pair);
				lock = false;
			}
		}
	}

	if (lock)
	{
		_hasStraggler = true;
		_straggler = pair.first;
	}
}

template <typename PairContainer, typename IntContainer>
void PmergeMe<PairContainer, IntContainer>::lunch()
{
	std::clock_t start = std::clock();

	sort();

	std::clock_t end = std::clock();

	_time = static_cast<double>(end - start) / 1000;
}

/******************************************/
/***********       GETERS      ************/
/******************************************/

template <typename PairContainer, typename IntContainer>
std::string		PmergeMe<PairContainer, IntContainer>::getBefore(void) const { return (_before); }

template <typename PairContainer, typename IntContainer>
double			PmergeMe<PairContainer, IntContainer>::getTime(void) const { return (_time); }

template <typename PairContainer, typename IntContainer>
size_t	PmergeMe<PairContainer, IntContainer>::getSize(void) const { return (_chain.size()); } 

template <typename PairContainer, typename IntContainer>
std::string		PmergeMe<PairContainer, IntContainer>::getAfter(void) const
{
	std::string after;
	for (size_t i = 0; i < _chain.size(); i++)
	{
		std::stringstream ss;
		ss << _chain[i];
		after += ss.str();
		after += " ";
	}
	return (after);
}

/******************************************/
/***********      EXCEPTION    ************/
/******************************************/

template <typename PairContainer, typename IntContainer>
const char*
PmergeMe<PairContainer, IntContainer>::BadNumberRange::what() const throw()
{
	return ("0 <= number <= INT_MAX");
}

template <typename PairContainer, typename IntContainer>
const char*
PmergeMe<PairContainer, IntContainer>::BadInput::what() const throw()
{
	return ("a non space/digit char was found");
}