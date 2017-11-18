#ifndef BLACK_CATTESTAPP_H
#define BLACK_CATTESTAPP_H

#include "MooseApp.h"

class BlackCatTestApp;

template <>
InputParameters validParams<BlackCatTestApp>();

class BlackCatTestApp : public MooseApp
{
public:
  BlackCatTestApp(InputParameters parameters);
  virtual ~BlackCatTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* BLACK_CATTESTAPP_H */
