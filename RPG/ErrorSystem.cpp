#include "ErrorSystem.h"



	ErrorSystem::ErrorSystem(std::string typeErr)
	{
		message = typeErr;
	}


	ErrorSystem::~ErrorSystem(void)
	{

	}


	std::string ErrorSystem::what()
	{
		return message;
	}