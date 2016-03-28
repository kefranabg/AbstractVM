//
// Execute.hh for Execute.hh in /home/abgral_f/Dropbox/AVM/avm/include
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Mon Feb 24 18:31:12 2014 abgral_f
// Last update Fri Feb 28 15:15:53 2014 abgral_f
//

#ifndef                 EXECUTE_HH
# define                EXECUTE_HH

#include		<vector>
#include                <string>
#include                <iostream>
#include                <fstream>
#include		"virtualMachine.hpp"
#include		"Parser.hh"

#define	SIZE_TAB		8

class				Execute
{
public:
  Execute();
  ~Execute();
  Execute(Execute const &);
  Execute			&operator=(Execute const &);
  void                          startExecute(std::vector<std::vector<std::string> >);
  void                          getIntegerValue(const std::string, const std::string);
  void                          getNonIntegerValue(const std::string, const std::string);
  void                          getType(const std::string);
  void                          executeAdvancedInstruc(const std::vector<std::string>);
  void                          executeBasicInstruc(const std::vector<std::string>);
  void				epureValue(std::string &value);
private:
  eOperandType			_type;
  std::string			_value;
  virtualMachine		_vm;
};


typedef void                    (virtualMachine::*ptr_op)(void);

struct				s_basic_instruc
{
  std::string			name;
  void				(virtualMachine::*ptr_op)(void);
};


typedef void                    (Execute::*ptr_ex)(std::string, std::string);

struct                          s_type_ex
{
  std::string                   name;
  eOperandType                  type;
  void                          (Execute::*ptr_ex)(std::string, std::string);
};

void				catch_ex(int argc, char **argv);

#endif
