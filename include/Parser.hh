//
// Parser.hh for Parser.hh in /home/abgral_f/dev/avm/include
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Wed Feb 12 16:58:50 2014 abgral_f
// Last update Thu Feb 27 19:10:17 2014 abgral_f
//

#ifndef			PARSER_HH
# define		PARSER_HH

#include                <vector>
#include		<string>
#include		<iostream>
#include		<fstream>
#include		"IOperand.hh"
#include		"Exceptions.hpp"

/* Instruction */

#define ASSERT		"assert"
#define PUSH		"push"
#define EXIT		"exit"
#define SECOND_EXIT	";;"
#define COMMENT		";"

/* Synthaxe error */

#define ERROR_LINE      "avm: line "
#define	SYNTHAXE	": Synthaxe error => "
#define	ADVANCED_SYNTH	" : Advanced instruction must have this synthaxe => INSTRUCTION TYPE(VALUE)"
#define	WRONG_TYPE	" : Wrong type. Type must be : int8 | int16 | int32 | float | double"
#define WRONG_VALUE	" : This type must recieve an integer value."
#define WRONG_VALUE2	" : This type must recieve an integer or decimal value."
#define	INVALID_INSTRUC	" : This instruction does not exist."
#define	INVALID_EXIT	" : Instructions 'exit' and ';;' don't take argument."
#define	EXIT_ABS        "The file must end by the instruction 'exit'."

class						Parser
{
public:
  Parser();
  ~Parser();
  Parser(Parser const &);
  Parser					&operator=(Parser const &);
  void						startParsing(std::istream&, bool);
  void						parsIntegerValue(const std::string, const std::string);
  void						parsNonIntegerValue(const std::string, const std::string);
  std::vector<std::string>			stringToWordtab(const std::string);
  bool						checkType(const std::string);
  void						checkAdvancedInstruc(const std::vector<std::string>);
  void						checkBasicInstruc(const std::vector<std::string>) const;
  bool						checkProgramEnd(const std::vector<std::string>);
  void						commentLine(std::string &);
  const std::vector<std::vector<std::string> >	&getLineTab() const;
  bool						getError() const;
private:
  std::string					_line;
  unsigned int					_line_num;
  eOperandType					_type;
  std::vector<std::vector<std::string> >        _lineTab;
  bool						_error;
  bool						_readInputMode;
  bool						_exit;
};

typedef void					(Parser::*ptr)(std::string, std::string);

struct						s_type
{
  std::string					name;
  eOperandType					type;
  void						(Parser::*ptr)(std::string, std::string);
};

#endif
