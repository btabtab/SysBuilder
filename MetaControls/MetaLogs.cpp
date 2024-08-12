#include "MetaLogs.hpp"

MetaLogs::MetaLogs()
{
}

void MetaLogs::printMessage(std::string message)
{
    std::cout << "[ " << current_message_counter << " ] :: >> { "\
    << message << " }\n";
}