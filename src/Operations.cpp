//
// Operations.cpp for AbstractVm in /home/andre_j/Projects/C++/AbstractVM/dev_AVM/src
//
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
//
// Started on  Tue Feb 25 17:17:55 2014 Julien ANDRE
// Last update Thu Feb 27 18:58:08 2014 abgral_f
//

#include	"virtualMachine.hpp"
#include	"specOperand.hh"

void		virtualMachine::add()
{
  IOperand	*newOperand;

  if (this->_stack.size() < 2)
    throw tooFewElem(NO_ELEMS);
  std::list<IOperand *>::const_iterator	first = this->_stack.begin();
  std::list<IOperand *>::iterator	second = this->_stack.begin();
  ++second;
  if ((*first)->getPrecision() > (*second)->getPrecision())
    newOperand = *(*first) + *(*second);
  else
    newOperand = *(*second) + *(*first);
  this->pop();
  this->pop();
  this->push(newOperand);
}

void		virtualMachine::sub()
{
  IOperand	*newOperand;

  if (this->_stack.size() < 2)
    throw tooFewElem(NO_ELEMS);
  std::list<IOperand *>::const_iterator	first = this->_stack.begin();
  std::list<IOperand *>::iterator	second = this->_stack.begin();
  ++second;
  if ((*first)->getPrecision() > (*second)->getPrecision())
    {
      IOperand *tmp = _operandCreator->createOperand((*first)->getType(), (*second)->toString());
      newOperand = *(tmp) - *(*first);
      delete tmp;
     }
  else
    newOperand = *(*second) - *(*first);
  this->pop();
  this->pop();
  this->push(newOperand);
}

void		virtualMachine::mul()
{
  IOperand	*newOperand;

  if (this->_stack.size() < 2)
    throw tooFewElem(NO_ELEMS);
  std::list<IOperand *>::const_iterator	first = this->_stack.begin();
  std::list<IOperand *>::iterator	second = this->_stack.begin();
  ++second;
  if ((*first)->getPrecision() > (*second)->getPrecision())
    newOperand = *(*first) * *(*second);
  else
    newOperand = *(*second) * *(*first);
  this->pop();
  this->pop();
  this->push(newOperand);
}

void		virtualMachine::div()
{
  IOperand	*newOperand;

  if (this->_stack.size() < 2)
    throw tooFewElem(NO_ELEMS);
  std::list<IOperand *>::const_iterator	first = this->_stack.begin();
  std::list<IOperand *>::iterator	second = this->_stack.begin();
  ++second;
  if ((*first)->getPrecision() > (*second)->getPrecision())
    {
      IOperand *tmp = _operandCreator->createOperand((*first)->getType(), (*second)->toString());
      newOperand = *tmp / *(*first);
      delete tmp;
     }
  else
    newOperand = *(*second) / *(*first);
  this->pop();
  this->pop();
  this->push(newOperand);
}

void		virtualMachine::mod()
{
  IOperand	*newOperand;

  if (this->_stack.size() < 2)
    throw tooFewElem(NO_ELEMS);
  std::list<IOperand *>::const_iterator	first = this->_stack.begin();
  std::list<IOperand *>::iterator	second = this->_stack.begin();
  ++second;
  if ((*first)->getPrecision() > (*second)->getPrecision())
    {
      IOperand *tmp = _operandCreator->createOperand((*first)->getType(), (*second)->toString());
      newOperand = *tmp % *(*first);
      delete tmp;
     }
  else
    newOperand = *(*second) % *(*first);
  this->pop();
  this->pop();
  this->push(newOperand);
}
