//
// virtualMachine.cpp for AbstractVM in /home/andre_j/Projects/C++/AbstractVM/dev_AVM/src
//
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
//
// Started on  Wed Feb 12 15:05:36 2014 Julien ANDRE
// Last update Fri Feb 28 15:07:56 2014 abgral_f
//

#include	<iomanip>
#include	"virtualMachine.hpp"

#define		HIGHER(x, y)	(x < y ? y : x)

virtualMachine::virtualMachine()
{
  this->_operandCreator = new operandCreator;
}

virtualMachine::virtualMachine(const virtualMachine &copy)
{
  this->_operandCreator = copy._operandCreator;
  this->_stack = copy._stack;
}

virtualMachine::~virtualMachine()
{
}

virtualMachine	*virtualMachine::operator=(const virtualMachine &copy)
{
  this->_operandCreator = copy._operandCreator;
  this->_stack = copy._stack;
  return this;
}

void		virtualMachine::push(eOperandType type, const std::string &value)
{
  this->_stack.push_front(this->_operandCreator->createOperand(type, value));
}

void		virtualMachine::push(IOperand *toPush)
{
  this->_stack.push_front(toPush);
}

void		virtualMachine::pop()
{
  if (this->_stack.size() == 0)
    throw popOnAnEmptyStack(POP_ERR);
  this->_stack.pop_front();
}

void		virtualMachine::dump()
{
  std::list<IOperand *>::iterator	it = this->_stack.begin();

  if (this->_stack.size() == 0)
    throw std::runtime_error(DUMP_ERR);
  while (it != this->_stack.end())
    {
      std::cout << std::setprecision((*it)->getPrecision()) << (*it)->toString() << std::endl;
      ++it;
    }
}

void		virtualMachine::assert(eOperandType type, const std::string &value) const
{
  if (this->_stack.size() == 0)
    throw wrongAssert(EMPTY_STACK);
  std::list<IOperand *>::const_iterator	it = this->_stack.begin();

  if ((*it)->getType() != type)
    throw wrongAssert(ASSERT_ERR);
  if ((*it)->toString() != value)
    throw wrongAssert(ASSERT_ERR);
}

void		virtualMachine::print()
{
  if (this->_stack.size() == 0)
    throw wrongAssert(EMPTY_STACK);
  std::list<IOperand *>::const_iterator	it = this->_stack.begin();

  if ((*it)->getType() != INT8)
    throw printError(PRINT_ERR);
  std::cout << stringToValue<char>((*it)->toString()) << std::endl;
}
