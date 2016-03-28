//
// operandCreator.cpp for AbstractVM in /home/andre_j/Projects/C++/AbstractVM/AVM/include
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Wed Feb 26 19:19:00 2014 Julien ANDRE
// Last update Thu Feb 27 17:18:54 2014 Julien ANDRE
//

#include	"operandCreator.hpp"

operandCreator::operandCreator()
{
  _operandType[0].type = INT8;
  _operandType[0].ptr = &operandCreator::createInt8;
  _operandType[1].type = INT16;
  _operandType[1].ptr = &operandCreator::createInt16;
  _operandType[2].type = INT32;
  _operandType[2].ptr = &operandCreator::createInt32;
  _operandType[3].type = FLOAT;
  _operandType[3].ptr = &operandCreator::createFloat;
  _operandType[4].type = DOUBLE;
  _operandType[4].ptr = &operandCreator::createDouble;
}

operandCreator::operandCreator(const operandCreator &copy)
{
  _operandType[0].type = copy._operandType[0].type;
  _operandType[0].ptr = copy._operandType[0].ptr;
  _operandType[1].type = copy._operandType[1].type;
  _operandType[1].ptr = copy._operandType[1].ptr;
  _operandType[2].type = copy._operandType[2].type;
  _operandType[2].ptr = copy._operandType[2].ptr;
  _operandType[3].type = copy._operandType[3].type;
  _operandType[3].ptr = copy._operandType[3].ptr;
  _operandType[4].type = copy._operandType[4].type;
  _operandType[4].ptr = copy._operandType[4].ptr;  
}

operandCreator::~operandCreator()
{
}

operandCreator	*operandCreator::operator=(const operandCreator &copy)
{
  _operandType[0].type = copy._operandType[0].type;
  _operandType[0].ptr = copy._operandType[0].ptr;
  _operandType[1].type = copy._operandType[1].type;
  _operandType[1].ptr = copy._operandType[1].ptr;
  _operandType[2].type = copy._operandType[2].type;
  _operandType[2].ptr = copy._operandType[2].ptr;
  _operandType[3].type = copy._operandType[3].type;
  _operandType[3].ptr = copy._operandType[3].ptr;
  _operandType[4].type = copy._operandType[4].type;
  _operandType[4].ptr = copy._operandType[4].ptr;  
  return this;
}
