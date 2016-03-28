//
// Exceptions.hpp for AbstractVM in /home/andre_j/Projects/C++/AbstractVM/dev_AVM/include
//
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
//
// Started on  Wed Feb 12 22:49:19 2014 Julien ANDRE
// Last update Thu Feb 27 19:07:31 2014 abgral_f
//

#ifndef		EXCEPTIONS_HPP_
# define	EXCEPTIONS_HPP_

#include	<stdexcept>
#include	<string>

class		invalidArgument	: public std::invalid_argument
{
public:
  invalidArgument(std::string const &msg, std::string const &str) : std::invalid_argument(msg) {this->str = str;}
  ~invalidArgument() throw() {}
  const std::string	&getStr() const {return (this->str);}
private:
  std::string		str;
};

class		logicError : public std::logic_error
{
public:
  logicError(std::string const &msg, std::string const &str) : std::logic_error(msg) {this->str = str;}
  ~logicError() throw() {}
  const std::string     &getStr() const {return (this->str);}
private:
  std::string           str;
  };


class		intValueOverflow : public std::overflow_error
{
public:
  intValueOverflow(std::string const msg) : std::overflow_error(msg) {}
};

class		intValueUnderflow : public std::underflow_error
{
public:
  intValueUnderflow(std::string const msg) : std::underflow_error(msg) {}
};

class		floatRangeError : public std::range_error
{
public:
  floatRangeError(std::string const msg) : std::range_error(msg) {}
};

class		wrongAssert : public std::runtime_error
{
public:
  wrongAssert(std::string const msg) : std::runtime_error(msg) {}
};

class		popOnAnEmptyStack : public std::runtime_error
{
public:
  popOnAnEmptyStack(std::string const msg) : std::runtime_error(msg) {}
};

class		tooFewElem : public std::runtime_error
{
public:
  tooFewElem(std::string const msg) : std::runtime_error(msg) {}
};

class		printError : public std::runtime_error
{
public:
  printError(std::string const msg) : std::runtime_error(msg) {}
};

class		unknownType : public std::runtime_error
{
public:
  unknownType(const std::string msg) : std::runtime_error(msg) {}
};

class           divideByZero : public std::runtime_error
{
public:
  divideByZero(const std::string msg) : std::runtime_error(msg) {}
};

#endif
