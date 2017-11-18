#include "BlackCatTestApp.h"
#include "BlackCatApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<BlackCatTestApp>()
{
  InputParameters params = validParams<BlackCatApp>();
  return params;
}

BlackCatTestApp::BlackCatTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  BlackCatApp::registerObjectDepends(_factory);
  BlackCatApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  BlackCatApp::associateSyntaxDepends(_syntax, _action_factory);
  BlackCatApp::associateSyntax(_syntax, _action_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    BlackCatTestApp::registerObjects(_factory);
    BlackCatTestApp::associateSyntax(_syntax, _action_factory);
  }
}

BlackCatTestApp::~BlackCatTestApp() {}

void
BlackCatTestApp::registerApps()
{
  registerApp(BlackCatApp);
  registerApp(BlackCatTestApp);
}

void
BlackCatTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
BlackCatTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
BlackCatTestApp__registerApps()
{
  BlackCatTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
BlackCatTestApp__registerObjects(Factory & factory)
{
  BlackCatTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
BlackCatTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  BlackCatTestApp::associateSyntax(syntax, action_factory);
}
