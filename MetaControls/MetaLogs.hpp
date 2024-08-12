#pragma once

#include <iostream>
#include <string>

class MetaLogs
{
private:
	/* data */
	int current_message_counter;
public:
	MetaLogs();

	void printMessage(std::string message);
};