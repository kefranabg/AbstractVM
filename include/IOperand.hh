//
// IOperand.hh for AbstractVM in /home/andre_j/Projects/C++/AbstractVM/dev_AVM/include
//
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
//
// Started on  Wed Feb 12 11:19:30 2014 Julien ANDRE
// Last update Wed Feb 26 13:18:38 2014 abgral_f
//

#ifndef		IOPERAND_HH_
# define	IOPERAND_HH_

# include	<iostream>
# include	<string>

typedef enum
  {
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE,
    UNKNOWN
  }	eOperandType;

class		IOperand
{
public:
  virtual			~IOperand() {}

  virtual int			getPrecision() const = 0;
  virtual eOperandType		getType() const = 0;

  virtual std::string const	&toString() const = 0;

  virtual IOperand		*operator+(const IOperand &rhs) const = 0;
  virtual IOperand		*operator-(const IOperand &rhs) const = 0;
  virtual IOperand		*operator*(const IOperand &rhs) const = 0;
  virtual IOperand		*operator/(const IOperand &rhs) const = 0;
  virtual IOperand		*operator%(const IOperand &rhs) const = 0;
};

#endif // IOPERAND_HH_
