//
// Operand.hpp for AbstractVm in /home/andre_j/Projects/C++/AbstractVM/dev_AVM/include
//
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
//
// Started on  Tue Feb 25 10:01:45 2014 Julien ANDRE
// Last update Fri Feb 28 14:15:33 2014 Julien ANDRE
//

#ifndef			OPERAND_HPP_
# define		OPERAND_HPP_

#include		<sstream>

#include		"Exceptions.hpp"
#include		"IOperand.hh"

/* Errors */

#define DIV_ERR		"Divsion by zero."
#define	MOD_ERR		"Modulo by zero."

template<typename T>
T	stringToValue(const std::string &value)
{
  std::istringstream	iss(value);
  long double		tmp;
  T			res;

  iss >> tmp;
  res = tmp;
  return res;
}

template<typename T>
class		Operand : public IOperand
{
protected:
  eOperandType		_type;
  T			_value;
  std::string		_descrp;
  int			_precision;

public:
   Operand(eOperandType type, T value, int precision)
  {
    std::ostringstream		oss;

    this->_type = type;
    this->_value = value;
    oss << this->_value;
    this->_descrp = oss.str();
    this->_precision = precision;
  }

  Operand(eOperandType type, char value)
  {
    std::ostringstream		oss;

    this->_type = type;
    this->_value = value;
    oss << static_cast<int>(this->_value);
    this->_descrp = oss.str();
    this->_precision = 0;
  }

  Operand(const IOperand &copy)
  {
    this->_type = copy.getType();
    this->_value = stringToValue<T>(copy.toString());
    this->_descrp = copy.toString();
    this->_precision = copy.getPrecision();
  }

  virtual			~Operand() {}

  virtual int			getPrecision() const
  {
    return this->_precision;
  }

  virtual eOperandType		getType() const
  {
    return this->_type;
  }

  virtual std::string const	&toString() const
  {
    return this->_descrp;
  }

  virtual IOperand		*operator+(const IOperand &rhs) const
  {
    return new Operand<T>(this->_type, this->_value + stringToValue<T>(rhs.toString()), this->_precision);
  }

  virtual IOperand		*operator-(const IOperand &rhs) const
  {
    return new Operand<T>(this->_type, this->_value - stringToValue<T>(rhs.toString()), this->_precision);
  }

  virtual IOperand		*operator*(const IOperand &rhs) const
  {
    return new Operand<T>(this->_type, this->_value * stringToValue<T>(rhs.toString()), this->_precision);
  }

  virtual IOperand		*operator/(const IOperand &rhs) const
  {
    if (stringToValue<T>(rhs.toString()) == 0)
      throw divideByZero(DIV_ERR);
    return new Operand<T>(this->_type, this->_value / stringToValue<T>(rhs.toString()), this->_precision);
  }

  virtual IOperand		*operator%(const IOperand &rhs) const
  {
    if (stringToValue<T>(rhs.toString()) == 0)
      throw divideByZero(MOD_ERR);
    return new Operand<T>(this->_type, static_cast<long>(this->_value) % static_cast<long>(stringToValue<T>(rhs.toString())), this->_precision);
  }

  IOperand			*operator=(const IOperand &copy)
  {
    this->_type = copy.getType();
    this->_value = stringToValue<T>(copy.toString());
    this->_precision = copy.getPrecision();
    return this;
  }
};

#endif
