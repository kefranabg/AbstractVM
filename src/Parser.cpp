//
// Parser.cpp for Parser.cpp in /home/abgral_f/dev/avm/src
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Wed Feb 12 17:00:51 2014 abgral_f
// Last update Thu Feb 27 18:48:45 2014 abgral_f
//

#include		<stdexcept>
#include		"Parser.hh"

static s_type type[] =
  {
    {"int8", INT8, &Parser::parsIntegerValue},
    {"int16", INT16, &Parser::parsIntegerValue},
    {"int32", INT32, &Parser::parsIntegerValue},
    {"float", FLOAT, &Parser::parsNonIntegerValue},
    {"double", DOUBLE, &Parser::parsNonIntegerValue},
    {"", UNKNOWN, NULL}
  };

static std::string basic[] =
  {
    "add",
    "sub",
    "mul",
    "div",
    "mod",
    "pop",
    "dump",
    "print",
    "exit",
    ""
  };

Parser::Parser()
{
  this->_line_num = 0;
  this->_error = false;
}

Parser::~Parser()
{

}

Parser::Parser(Parser const & cpy)
{
  this->_line_num = cpy._line_num;
  this->_type = cpy._type;
  this->_lineTab = cpy._lineTab;
  this->_error = cpy._error;
  this->_readInputMode = cpy._readInputMode;
}

Parser							&Parser::operator=(Parser const & cpy)
{
  this->_line_num = cpy._line_num;
  this->_type = cpy._type;
  this->_lineTab = cpy._lineTab;
  this->_error = cpy._error;
  this->_readInputMode = cpy._readInputMode;
  return (*this);
}

bool							Parser::getError() const
{
  return (this->_error);
}

const std::vector<std::vector<std::string> >		&Parser::getLineTab() const
{
  return (this->_lineTab);
}

std::vector<std::string>			Parser::stringToWordtab(const std::string line)
{
  std::vector<std::string>		        string_tab;
  std::string					str;
  char						c[2];
  int						i = 0;

  c[1] = '\0';
  while (line[i] != '\0')
    {
      str = "";
      if (line[i] != '\t' && line[i] != ' ' && line[i] != '\n')
	{
	  while (line[i] != '\t' && line[i] != ' ' && line[i] != '\0' && line[i] != '\n')
	    {
	      c[0] = line[i];
	      str += &c[0];
	      i++;
	    }
	  string_tab.push_back(str);
	}
      if (line[i] != '\0')
	i++;
    }
  return (string_tab);
}

void						Parser::parsIntegerValue(const std::string type, const std::string word)
{
  size_t					count;

  count = type.size();
  if (word[count] != '(')
    throw logicError(ADVANCED_SYNTH, word);
  else
    count++;
  if (word[count] == '-')
    count++;
  if (word[count] == ')')
    throw logicError(ADVANCED_SYNTH, word);
  while (word[count] != '\0' && word[count] != ')')
    {
      if (word[count] < 48 || word[count] > 57)
	throw logicError(WRONG_VALUE, word);
      count++;
    }
  if (word[count] == '\0' || (word[count] == ')' && word[count + 1] != '\0'))
    throw logicError(ADVANCED_SYNTH, word);
}

void						Parser::parsNonIntegerValue(const std::string type, const std::string word)
{
  size_t					count;
  bool						check = false;


  count = type.size();
  if (word[count] != '(')
    throw logicError(ADVANCED_SYNTH, word);
  else
    count++;
  if (word[count] == '-')
    count++;
  if (word[count] == ')')
    throw logicError(ADVANCED_SYNTH, word);
  while (word[count] != '\0' && word[count] != ')')
    {
      if (((word[count] < 48 || word[count] > 57) && word[count] != '.')
	  || (word[count] == '.' && check == true))
	throw logicError(WRONG_VALUE2, word);
      if (word[count] == '.')
	{
	  if (word[count - 1] < 48 || word[count - 1] > 57
	      || word[count + 1] < 48 || word[count + 1] > 57)
	    throw logicError(WRONG_VALUE2, word);
	  check = true;
	}
      count++;
    }
  if (word[count] == '\0' || (word[count] == ')' && word[count + 1] != '\0'))
    throw logicError(ADVANCED_SYNTH, word);
}

bool						Parser::checkType(const std::string word)
{
  for (int i = 0 ; type[i].ptr != NULL ; i++)
    {
      if (word.find(type[i].name) == 0)
	{
	  (this->*(type[i].ptr))(type[i].name, word);
	  return (true);
	}
    }
  return (false);
}

void						Parser::checkAdvancedInstruc(const std::vector<std::string> string_tab)
{
  if (string_tab.size() != 2)
    throw logicError(ADVANCED_SYNTH, this->_line);
  if (this->checkType(string_tab[1]) == false)
    throw logicError(WRONG_TYPE, string_tab[1]);
}

void						Parser::checkBasicInstruc(const std::vector<std::string> string_tab) const
{
  for (int i = 0 ; basic[i] != "" ; i++)
    {
      if (string_tab[0] == basic[i])
	return ;
    }
  throw logicError(INVALID_INSTRUC, this->_line);
}

bool						Parser::checkProgramEnd(const std::vector<std::string> string_tab)
{
  if (string_tab.size() != 1)
    throw logicError(INVALID_EXIT, string_tab[0]);
  if (string_tab[0] == SECOND_EXIT
      && this->_readInputMode == true)
    {
      if (this->_exit == false)
        throw std::runtime_error(EXIT_ABS);
      return (true);
    }
  else if (string_tab[0] == EXIT
           && this->_readInputMode == false)
    return (true);
  else
    {
      this->_exit = true;
      return (false);
    }
}

void						Parser::commentLine(std::string & line)
{
  int						i = 0;

  while (line[i] != '\0')
    {
      if (line[i] == ';' && line[i + 1] == ';')
	return ;
      if (line[i] == ';' && line[i + 1] != ';')
	{
	  line[i] = '\0';
	  i--;
	}
      i++;
    }
}

void						Parser::startParsing(std::istream& is, bool _readInputMode)
{
  std::string					line;
  std::vector<std::string>			string_tab;

  this->_readInputMode = _readInputMode;
  while (std::getline(is, line))
    {
      this->_line = line;
      try
	{
	  commentLine(line);
	  this->_line_num++;
	  string_tab = this->stringToWordtab(line);
	  this->_lineTab.push_back(string_tab);
	  if (string_tab.size() != 0)
	    {
	      if (string_tab[0] == ASSERT || string_tab[0] == PUSH)
		checkAdvancedInstruc(string_tab);
	      else if (string_tab[0] == EXIT || string_tab[0] == SECOND_EXIT)
		{
		  if (checkProgramEnd(string_tab) == true)
		    return ;
		}
	      else if (string_tab.size() == 1)
		checkBasicInstruc(string_tab);
	      else
		throw logicError(INVALID_INSTRUC, line);
	    }
	}
      catch (const logicError & e)
	{
	  this->_error = true;
	  std::cout << ERROR_LINE << this->_line_num << SYNTHAXE << e.getStr() << e.what() << std::endl;
	  if (this->_readInputMode == true)
	    return ;
	}
    }
  if (this->_readInputMode == false && string_tab[0] != EXIT)
    throw std::runtime_error(EXIT_ABS);
}
