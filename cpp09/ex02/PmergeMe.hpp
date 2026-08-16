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
		int				_straggler;
		std::string		_before;
		double			_time;

	private:
		void	binaryInsert(int value, int end);
		void	insertPendElements();
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

int					ft_atoi(const std::string& str);

/******************************************/
/***********     ORTHODOX    **************/
/******************************************/

template <typename PairContainer, typename IntContainer>
PmergeMe<PairContainer, IntContainer>::PmergeMe() : _straggler(-1) {}

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
		_straggler = other._straggler;
		_before = other._before;
		_time = other._time;
	}
	return (*this);
}

/******************************************/
/************       SORT     **************/
/******************************************/

template <typename PairContainer, typename IntContainer>
void PmergeMe<PairContainer, IntContainer>::binaryInsert(int value, int end)
{
	size_t left = 0;
	size_t right = end;

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
void PmergeMe<PairContainer, IntContainer>::insertPendElements()
{
	int jacob[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
	int jacob_size = sizeof(jacob) / sizeof(jacob[0]);

	for (size_t jacob_i = 0; jacob_i + 1 < jacob_size; jacob_i++)
	{
		size_t group_start = jacob[jacob_i];
		size_t group_end = jacob[jacob_i + 1];

		if (group_start >= _pend.size())
			break;

		if (group_end > _pend.size())
			group_end = _pend.size();

		while (group_end > group_start)
		{
			size_t pend_index = --group_end;
			int b = _elements[pend_index + 1].second;

			size_t b_pos = 0;
			while (b_pos < _chain.size() && _chain[b_pos] != b)
				b_pos++;

			binaryInsert(_pend[pend_index], b_pos);
		}
	}

	if (_straggler != -1)
		binaryInsert(_straggler, _chain.size());
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
		{
			int	tmp = _elements[i].first;
			_elements[i].first = _elements[i].second;
			_elements[i].second = tmp;
		}
	}
}

template <typename PairContainer, typename IntContainer>
void PmergeMe<PairContainer, IntContainer>::sort()
{
	swap_sortPairs();

	if (_elements.size() > 1)
		mergeSort(0, _elements.size());

	buildMainChain();
	insertPendElements();
}

/******************************************/
/***********      METHODS    **************/
/******************************************/

template <typename PairContainer, typename IntContainer>
void PmergeMe<PairContainer, IntContainer>::init(int ac, char** av)
{
	bool lock = false;
	std::pair<int, int> pair;

	for (int i = 1; i < ac; i++)
	{
		std::stringstream ss(av[i]);
		std::string line;

		while (std::getline(ss, line, ' '))
		{
			if (line.empty())
				continue;

			if (!lock)
			{
				pair.first = ft_atoi(line);
				_before += line + " ";
				lock = true;
			}
			else
			{
				pair.second = ft_atoi(line);
				_before += line + " ";
				_elements.push_back(pair);
				lock = false;
			}
		}
	}

	if (lock)
		_straggler = pair.first;
}

template <typename PairContainer, typename IntContainer>
void PmergeMe<PairContainer, IntContainer>::lunch()
{
	std::clock_t start = std::clock();

	sort();

	std::clock_t end = std::clock();

	_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
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