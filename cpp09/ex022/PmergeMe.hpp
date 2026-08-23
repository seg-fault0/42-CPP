#pragma once

# include <iostream>
# include <vector>
# include <deque>
# include <sstream>
# include <climits>
# include <ctime>
# include <algorithm>

typedef struct S_Pair
{
	int big;
	int small;
}Pair;

int					ft_atoi(const std::string& str);
void				print(std::string str, const std::vector<int>& vec);
double				getDur(std::clock_t start);