//
// Open.hh for Open.hh in /home/abgral_f/Dropbox/AVM/avm/include
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Mon Feb 24 16:12:31 2014 abgral_f
// Last update Tue Feb 25 19:12:38 2014 abgral_f
//

#ifndef                 OPEN_HH
# define                OPEN_HH

#include                <string>
#include                <iostream>
#include                <fstream>
#include		"Exceptions.hpp"

/* Extension */

#define SIZE_EXTENSION  4
#define EXTENSION       ".avm"

/* Parsing arguments */

#define	AVM		"AVM : "
#define USAGE           "USAGE : ./avm [FILE.avm]."
#define WRONG_EXTENSION " => The extension must be '.avm'."
#define INVALID_FILE    " => This file doesn't exist."

class				Open
{
public:
  Open(int, char **);
  ~Open();
  Open(Open const &);
  Open				&operator=(Open const &);
  void                          startOpen();
  void		                openFile();
  void                          checkExtension();
  bool                          isFile() const;
  std::ifstream			*getOpenFile() const;
private:
  std::ifstream			*_openFile;
  int				_argc;
  char				**_argv;
  std::string			_file;
};

#endif
