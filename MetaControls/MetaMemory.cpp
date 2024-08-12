#include "MetaMemory.hpp"

MetaMemory::MetaMemory()
{
}
MetaMemory::~MetaMemory()
{
}

void* MetaMemory::addMemoryAddress(void** memory_address)
{
    allocated_memory_addresses.push_back(memory_address);
}
/*
    Goes through and checks for guilty (NULL) memory
    addresses and then returns them.
*/
std::vector<void**> MetaMemory::checkForNulls()
{
    std::vector<void**> guilty_addresses;
    for(int i = 0; i != allocated_memory_addresses.size(); i++)
    {
        void** current_address = allocated_memory_addresses.at(i);
        if((*current_address) == NULL)
        {
            guilty_addresses.push_back(current_address);
        }
    }
    return guilty_addresses;
}

void printOutNullAddresses(std::vector<void**> null_addresses)
{
}