//
// catch.cpp for catch.cpp in /home/abgral_f/rendu/dev_AVM/src
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Thu Feb 27 18:20:35 2014 abgral_f
// Last update Mon Sep 15 10:00:35 2014 abgral_f
//

#include                <stdexcept>
#include                "Exceptions.hpp"
#include                "Parser.hh"
#include                "Open.hh"
#include                "Execute.hh"

void			run_avm(int argc, char **argv)
{
  Open                  file(argc, argv);
  Parser                parsing;
  Execute               exec;
  std::istream          *stream;

  file.startOpen();
  if (file.getOpenFile() != NULL)
    {
      stream = file.getOpenFile();
      parsing.startParsing(*stream, false);
      if (parsing.getError() == false)
	exec.startExecute(parsing.getLineTab());
    }
  else
    {
      parsing.startParsing(std::cin, true);
      if (parsing.getError() == false)
	exec.startExecute(parsing.getLineTab());
    }
}

void			catch_ex(int argc, char **argv)
{
  try
    {
      run_avm(argc, argv);
    }
  catch (const invalidArgument & e)
    {
      std::cout << AVM << e.what() << std::endl;
    }
  catch (const intValueOverflow & e)
    {
      std::cout << AVM << e.what() << std::endl;
    }
  catch (const intValueUnderflow & e)
    {
      std::cout << AVM << e.what() << std::endl;
    }
  catch (const floatRangeError & e)
    {
      std::cout << AVM << e.what() << std::endl;
    }
  catch (const wrongAssert & e)
    {
      std::cout << AVM << e.what() << std::endl;
    }
  catch (const popOnAnEmptyStack & e)
    {
      std::cout << AVM << e.what() << std::endl;
    }
  catch (const tooFewElem & e)
    {
      std::cout << AVM << e.what() << std::endl;
    }
  catch (const printError & e)
    {
      std::cout << AVM << e.what() << std::endl;
    }
  catch (const unknownType & e)
    {
      std::cout << AVM << e.what() << std::endl;
    }
  catch (const divideByZero & e)
    {
      std::cout << AVM << e.what() << std::endl;
    }
  catch (const std::logic_error & e)
    {
      std::cout << AVM << e.what() << std::endl;
    }
  catch (const std::exception & e)
    {
      std::cout << AVM << e.what() << std::endl;
    }
}
