#include "header.h"
#include "sort.h"

int main()
{
	char type{};
	try
	{
		InputType(type);
		ChouseType(type);
	}
	catch (std::invalid_argument& e) { std::cout << e.what(); }
	return 0;
}