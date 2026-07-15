#include "Serialization.hpp"

int main()
{
	Data* data = new Data;
	data->name = "bob";
	data->age = 20;

	uintptr_t ptr;
	Data* data2;

	ptr = Serialization::serialize(data);
	data2 = Serialization::deserialize(ptr);

	std::cout << "data2 name = " << data2->name << std::endl;
	std::cout << "data = " <<(size_t) data << std::endl;
	std::cout << "ptr = " <<(size_t) ptr << std::endl;

	delete data;
}