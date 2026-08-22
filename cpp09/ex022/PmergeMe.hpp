#pragma once

# include <iostream>
# include <vector>
# include <sstream>
# include <climits>
# include <ctime>

int					ft_atoi(const std::string& str);
std::vector<int>	ft_parse(int ac, char** av);
std::vector<int>	sort(std::vector<int> input);