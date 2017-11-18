#include "BlackCatApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<BlackCatApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

BlackCatApp::BlackCatApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  BlackCatApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  BlackCatApp::associateSyntax(_syntax, _action_factory);
}

BlackCatApp::~BlackCatApp() {}

void
BlackCatApp::registerApps()
{
  registerApp(BlackCatApp);
}

void
BlackCatApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new production objects here! */
}

void
BlackCatApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new production objects here! */
}

void
BlackCatApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
BlackCatApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
BlackCatApp__registerApps()
{
  BlackCatApp::registerApps();
}

extern "C" void
BlackCatApp__registerObjects(Factory & factory)
{
  BlackCatApp::registerObjects(factory);
}

extern "C" void
BlackCatApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  BlackCatApp::associateSyntax(syntax, action_factory);
}
