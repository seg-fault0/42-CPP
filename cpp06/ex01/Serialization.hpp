#pragma once

//libraries
# include <iostream>
# include <stdint.h>

//struct
typedef struct s_data
{
	std::string	name;
	int			age;
}Data;

//class
class Serialization
{
	private:
		Serialization();
		~Serialization();
		Serialization(const Serialization& other);
		Serialization& operator=(const Serialization& other);

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};