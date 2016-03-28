//
// specOperand.hh for AbstractVM in /home/andre_j/Projects/C++/AbstractVM/dev_AVM/include
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Tue Feb 25 10:18:36 2014 Julien ANDRE
// Last update Tue Feb 25 17:14:25 2014 Julien ANDRE
//

#ifndef		SPECOPERAND_HH_
# define	SPECOPERAND_HH_

# include	"Operand.hpp"

class		Int8 : public Operand<char>
{
public:
  Int8(char value);
  virtual ~Int8();
};
  
class		Int16 : public Operand<int>
{
public:
  Int16(int value);
  virtual ~Int16();
};

class		Int32 : public Operand<long>
{
public:
  Int32(long value);
  virtual ~Int32();
};

class		Float : public Operand<float>
{
public:
  Float(float value);
  virtual ~Float();
};

class		Double : public Operand<double>
{
public:
  Double(double value);
  virtual ~Double();
};

#endif
