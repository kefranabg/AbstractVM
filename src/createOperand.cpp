//
// createOperand.cpp for AbstractVM in /home/andre_j/Projects/C++/AbstractVM/dev_AVM/src
//
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
//
// Started on  Mon Feb 24 20:12:52 2014 Julien ANDRE
// Last update Fri Feb 28 16:26:11 2014 abgral_f
//

#include	"operandCreator.hpp"

template<>
bool                  operandCreator::checkUnder<float>(const long double &value)
{
  if (value < -std::numeric_limits<float>::max())
    return true;
  return false;
}

template<>
bool                  operandCreator::checkUnder<double>(const long double &value)
{
  if (value < -std::numeric_limits<double>::max())
    return true;
  return false;
}

IOperand	*operandCreator::createInt8(const std::string &value)
{
  long double	numValue = stringToValue<long double>(value);

  if (this->checkUnder<char>(numValue) == true)
    throw intValueUnderflow(INT8_UNDER);
  else if (this->checkOver<char>(numValue) == true)
    throw intValueOverflow(INT8_OVER);
  return new class Int8(stringToValue<char>(value));
}

IOperand	*operandCreator::createInt16(const std::string &value)
{
  long double	numValue = stringToValue<long double>(value);

  if (this->checkUnder<int>(numValue) == true)
    throw intValueUnderflow(INT16_UNDER);
  else if (this->checkOver<int>(numValue) == true)
    throw intValueOverflow(INT16_OVER);
  return new class Int16(stringToValue<int>(value));
}

IOperand	*operandCreator::createInt32(const std::string &value)
{
  long double	numValue = stringToValue<long double>(value);

  if (this->checkUnder<long>(numValue) == true)
    throw intValueUnderflow(INT32_UNDER);
  else if (this->checkOver<long>(numValue) == true)
    throw intValueOverflow(INT32_OVER);
  return new class Int32(stringToValue<long>(value));
}

IOperand	*operandCreator::createFloat(const std::string &value)
{
  long double	numValue = stringToValue<long double>(value);

  if (this->checkUnder<float>(numValue) == true)
    throw floatRangeError(FLOAT_UNDER);
  else if (this->checkOver<float>(numValue) == true)
    throw floatRangeError(FLOAT_OVER);
  return new class Float(stringToValue<float>(value));
}

IOperand	*operandCreator::createDouble(const std::string &value)
{
  long double	numValue = stringToValue<long double>(value);

  if (this->checkUnder<double>(numValue) == true)
    throw floatRangeError(DOUBLE_UNDER);
  else if (this->checkOver<double>(numValue) == true)
    throw floatRangeError(DOUBLE_OVER);
  return new class Double(stringToValue<double>(value));
}

IOperand	*operandCreator::createOperand(eOperandType type, const std::string &value)
{
  int		count = 0;

  while (count != NBR_TYPE)
    {
      if (this->_operandType[count].type == type)
	return (this->*(this->_operandType[count].ptr))(value);
      ++count;
    }
  throw unknownType(UNKN_TYPE);
  return (NULL);
}
