#pragma once

#include <vector>
#include <iostream>

/*
	MetaMemory will track pointers of memory
	so that at the end of the programs lifetime
	all memory addresses can be wiped with ease.

	This will also be used later on to track memory
	addresses so that reporting can be done for
	memory safety reasons.
*/
class MetaMemory
{
private:
	//A vector that will store all pointers.
	std::vector<void**> allocated_memory_addresses;
public:
	MetaMemory();
	~MetaMemory();

	void* addMemoryAddress(void** memory_address);
	std::vector<void**> checkForNulls();
	void printOutNullAddresses(std::vector<void**> null_addresses);
};