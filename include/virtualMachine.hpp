//
// virtualMachine.hh for AbstractVM in /home/andre_j/Projects/C++/AbstractVM/dev_AVM/include
//
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
//
// Started on  Wed Feb 12 10:47:20 2014 Julien ANDRE
// Last update Fri Feb 28 15:07:49 2014 abgral_f
//

#ifndef			VIRTUALMACHINE_HPP_
# define		VIRTUALMACHINE_HPP_

#include		<exception>
#include		<list>

#include		"IOperand.hh"
#include		"Exceptions.hpp"
#include		"specOperand.hh"
#include		"operandCreator.hpp"

/* Errors */

#define NO_ELEMS	"Not enough element for the operation."
#define	POP_ERR		"Pop on an empty stack."
#define	EMPTY_STACK	"Stack is empty."
#define	ASSERT_ERR	"Assertion is not correct."
#define	PRINT_ERR	"Element from print is not an int8."
#define DUMP_ERR	"Dump on an empty stack."

class			virtualMachine
{
private:
  std::list<IOperand *>	_stack;
  operandCreator	*_operandCreator;
public:
			virtualMachine();
			~virtualMachine();
			virtualMachine(const virtualMachine &);
  virtualMachine	*operator=(const virtualMachine &copy);

  void			push(eOperandType type, const std::string &value);
  void			push(IOperand *toPush);
  void			pop();
  void			dump();
  void			assert(eOperandType type, const std::string &value) const;

  void			add();
  void			sub();
  void			mul();
  void			div();
  void			mod();
  void			print();
};

#endif // VIRTUALMACHINE_HH_
