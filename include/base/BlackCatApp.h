#ifndef BLACK_CATAPP_H
#define BLACK_CATAPP_H

#include "MooseApp.h"

class BlackCatApp;

template <>
InputParameters validParams<BlackCatApp>();

class BlackCatApp : public MooseApp
{
public:
  BlackCatApp(InputParameters parameters);
  virtual ~BlackCatApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void registerObjectDepends(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void associateSyntaxDepends(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* BLACK_CATAPP_H */
