#pragma once

#include <string>


class ErrorSystem
{
private:
	std::string message;

public:
	ErrorSystem(std::string typeErr);
	~ErrorSystem(void);

	std::string what();
};

