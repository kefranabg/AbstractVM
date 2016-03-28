//
// operandCreator.hpp for AbstractVM in /home/andre_j/Projects/C++/AbstractVM/AVM/include
//
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
//
// Started on  Wed Feb 26 18:47:34 2014 Julien ANDRE
// Last update Fri Feb 28 16:25:35 2014 abgral_f
//

#ifndef		OPERANDCREATOR_HPP_
# define	OPERANDCREATOR_HPP_

# include	<limits>

# include	"specOperand.hh"
# include	"Exceptions.hpp"

# define	NBR_TYPE	5

# define	INT8_UNDER	"int8 underflow."
# define	INT8_OVER	"int8 overflow."
# define	INT16_UNDER	"int16 underflow."
# define	INT16_OVER	"int16 overflow."
# define	INT32_UNDER	"int32 underflow."
# define	INT32_OVER	"int32 overflow."
# define	FLOAT_UNDER	"float underflow."
# define	FLOAT_OVER	"float overflow."
# define	DOUBLE_UNDER	"double underflow."
# define	DOUBLE_OVER	"double overflow."

# define	UNKN_TYPE	"This type isn't known."

class			operandCreator
{
private:
  IOperand		*createInt8(const std::string &value);
  IOperand		*createInt16(const std::string &value);
  IOperand		*createInt32(const std::string &value);
  IOperand		*createFloat(const std::string &value);
  IOperand		*createDouble(const std::string &value);

public:
			operandCreator();
			operandCreator(const operandCreator &copy);
			~operandCreator();

  operandCreator	*operator=(const operandCreator &copy);

  template<typename T>
  bool			checkUnder(const long double &value)
  {
    if (value < std::numeric_limits<T>::min())
      return true;
    return false;
  }


  template<typename T>
  bool			checkOver(const long double &value)
  {
    if (value > std::numeric_limits<T>::max())
      return true;
    return false;
  }

  IOperand		*createOperand(eOperandType type, const std::string &value);

  struct		operandType
  {
    eOperandType	type;
    IOperand		*(operandCreator::*ptr)(const std::string &value);
  };

  operandType		_operandType[NBR_TYPE];
};

#endif
