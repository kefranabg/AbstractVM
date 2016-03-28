//
// specOperand.cpp for AbstractVm in /home/andre_j/Projects/C++/AbstractVM/dev_AVM/src
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Tue Feb 25 10:22:05 2014 Julien ANDRE
// Last update Thu Feb 27 18:02:44 2014 Julien ANDRE
//

#include	"specOperand.hh"

Int8::Int8(char value) : Operand<char>(INT8, value)
{
  this->_value = value;
}

Int8::~Int8()
{
}

Int16::Int16(int value) : Operand<int>(INT16, value, 1)
{
  this->_value = value;
}

Int16::~Int16()
{
}

Int32::Int32(long value) : Operand<long>(INT32, value, 2)
{
  this->_value = value;
}

Int32::~Int32()
{
}

Float::Float(float value) : Operand<float>(FLOAT, value, 6)
{
  this->_value = value;
}

Float::~Float()
{
}

Double::Double(double value) : Operand<double>(DOUBLE, value, 12)
{
  this->_value = value;
}

Double::~Double()
{
}
