#include "for_testApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
for_testApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

for_testApp::for_testApp(InputParameters parameters) : MooseApp(parameters)
{
  for_testApp::registerAll(_factory, _action_factory, _syntax);
}

for_testApp::~for_testApp() {}

void 
for_testApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<for_testApp>(f, af, s);
  Registry::registerObjectsTo(f, {"for_testApp"});
  Registry::registerActionsTo(af, {"for_testApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
for_testApp::registerApps()
{
  registerApp(for_testApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
for_testApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  for_testApp::registerAll(f, af, s);
}
extern "C" void
for_testApp__registerApps()
{
  for_testApp::registerApps();
}
