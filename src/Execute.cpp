//
// Execute.cpp for Execute.cpp in /home/abgral_f/Dropbox/AVM/avm/src
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Mon Feb 24 19:04:58 2014 abgral_f
// Last update Sun Mar  2 20:47:49 2014 abgral_f
//

#include                <stdexcept>
#include                "Execute.hh"

static s_type_ex type[] =
  {
    {"int8", INT8, &Execute::getIntegerValue},
    {"int16", INT16, &Execute::getIntegerValue},
    {"int32", INT32, &Execute::getIntegerValue},
    {"float", FLOAT, &Execute::getNonIntegerValue},
    {"double", DOUBLE, &Execute::getNonIntegerValue},
    {"", UNKNOWN, NULL}
  };


static s_basic_instruc basic[] =
  {
    {"add", &virtualMachine::add},
    {"sub", &virtualMachine::sub},
    {"mul", &virtualMachine::mul},
    {"div", &virtualMachine::div},
    {"mod", &virtualMachine::mod},
    {"pop", &virtualMachine::pop},
    {"dump", &virtualMachine::dump},
    {"print", &virtualMachine::print},
  };

Execute::Execute()
{
  this->_value = "";
}

Execute::~Execute()
{

}

Execute::Execute(Execute const & cpy)
{
  this->_type = cpy._type;
  this->_value = cpy._value;
}

Execute                  &Execute::operator=(Execute const & cpy)
{
  this->_type = cpy._type;
  this->_value = cpy._value;
  return (*this);
}

void                            Execute::getIntegerValue(const std::string type, const std::string word)
{
  size_t                        count;
  char                          to_add[2];

  to_add[1] = '\0';
  this->_value = "";
  count = type.size() + 1;
  for (int i = count ; word[i] != ')' ; i++)
    {
      to_add[0] = word[i];
      this->_value += &to_add[0];
    }
}

void                            Execute::getNonIntegerValue(const std::string type, const std::string word)
{
  size_t                        count;
  char                          to_add[2];

  to_add[1] = '\0';
  this->_value = "";
  count = type.size() + 1;
  for (int i = count ; word[i] != ')' ; i++)
    {
      to_add[0] = word[i];
      this->_value += &to_add[0];
    }
}

void                          Execute::getType(const std::string word)
{
  for (int i = 0 ; type[i].ptr_ex != NULL ; i++)
    {
      if (word.find(type[i].name) == 0)
        {
          (this->*(type[i].ptr_ex))(type[i].name, word);
          this->_type = type[i].type;
	}
    }
}

void                          Execute::executeAdvancedInstruc(const std::vector<std::string> string_tab)
{
  this->getType(string_tab[1]);
  epureValue(this->_value);
  if (string_tab[0] == PUSH)
    this->_vm.push(this->_type, this->_value);
  else
    this->_vm.assert(this->_type, this->_value);
}

void                          Execute::executeBasicInstruc(const std::vector<std::string> string_tab)
{
  for (int i = 0 ; i != SIZE_TAB ; i++)
    {
      if (string_tab[0] == basic[i].name)
	(this->_vm.*(basic[i].ptr_op))();
    }
}

void				Execute::startExecute(const std::vector<std::vector<std::string> > lineTab)
{
  for(size_t i = 0 ; i != lineTab.size() ; i++)
    {
      if (lineTab[i].size() != 0)
	{
	  if (lineTab[i][0] == ASSERT || lineTab[i][0] == PUSH)
	    executeAdvancedInstruc(lineTab[i]);
	  else if (lineTab[i][0] == EXIT)
	    return ;
	  else if (lineTab[i].size() == 1)
	    executeBasicInstruc(lineTab[i]);
	}
    }
}

void				Execute::epureValue(std::string &value)
{
  size_t			count = 0;
  size_t			ret;

  if (value[count] == '-')
    ++count;
  while (count != value.size() && value[count] == '0')
    {
      if (value.size() == 1 || value[count + 1] == '.')
	++count;
      else
	value.erase(count, 1);
    }
  if ((ret = value.find(".", 0)) != std::string::npos)
    {
      count = value.size() - 1;
      while (count != ret && value[count] == '0')
	value.erase(count--, 1);
    }
}
