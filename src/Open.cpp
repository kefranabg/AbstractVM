//
// Open.cpp for Open.cpp in /home/abgral_f/Dropbox/AVM/avm/src
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Mon Feb 24 16:16:23 2014 abgral_f
// Last update Wed Feb 26 14:44:25 2014 abgral_f
//

#include                <stdexcept>
#include                "Open.hh"

Open::Open(int argc, char **argv)
{
  this->_argc = argc;
  this->_argv = argv;
  this->_file = "";
  this->_openFile = NULL;
}

Open::~Open()
{

}

Open::Open(Open const & cpy)
{
  this->_file = cpy._file;
  this->_argc = cpy._argc;
  this->_argv = cpy._argv;
  this->_openFile = cpy._openFile;
}

Open                  &Open::operator=(Open const & cpy)
{
  this->_file = cpy._file;
  this->_argc = cpy._argc;
  this->_argv = cpy._argv;
  this->_openFile = cpy._openFile;
  return (*this);
}

std::ifstream           *Open::getOpenFile() const
{
  return (this->_openFile);
}

void			Open::openFile()
{
  this->_openFile = new std::ifstream();
  this->_openFile->open(this->_file.c_str(), std::ifstream::in);
  if (!(*this->_openFile))
    throw invalidArgument(INVALID_FILE, this->_file);
  }

bool                    Open::isFile() const
{
  if (this->_argc == 1)
    return (false);
  else if (this->_argc == 2)
    return (true);
  else
    throw invalidArgument(USAGE, "");
  return (false);
}

void                    Open::checkExtension()
{
  size_t                str_size;
  size_t                pos_occur;

  str_size = this->_file.size();
  pos_occur = this->_file.rfind(EXTENSION);
  if (pos_occur != str_size - SIZE_EXTENSION
      || pos_occur == std::string::npos
      || pos_occur == 0)
    throw invalidArgument(WRONG_EXTENSION, this->_file);
  }

void                    Open::startOpen()
{
  if (this->isFile() != false)
    {
      this->_file = this->_argv[1];
      this->checkExtension();
      this->openFile();
    }
}
