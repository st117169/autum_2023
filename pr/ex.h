#pragma once
#include <iostream>


class InsufficientBalanceException : public std::exception
{
	std::string message;
public:
	InsufficientBalanceException(const std::string& message) 
	{
		this->message = message;
	}

	const char* what() const noexcept override 
	{
		return this->message.c_str();
	}
};

class AccountNotFoundException : public std::exception 
{
	std::string message;
public:
	AccountNotFoundException(const std::string& message) 
	{
		this->message = message;
	}

	const char* what() const noexcept override 
	{
		return this->message.c_str();
	}
};

class IllegalArgumentException : public std::exception
{
	std::string message;
public:
	IllegalArgumentException(const std::string& message) 
	{
		this->message = message;
	}

	const char* what() const noexcept override 
	{
		return this->message.c_str();
	}
};

class FileNotFoundException : public std::exception {
	std::string message;
public:
	FileNotFoundException();
	FileNotFoundException(const std::string& message);

	const char* what() const noexcept override;
};

