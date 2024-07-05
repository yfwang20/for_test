//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "for_testTestApp.h"
#include "for_testApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
for_testTestApp::validParams()
{
  InputParameters params = for_testApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

for_testTestApp::for_testTestApp(InputParameters parameters) : MooseApp(parameters)
{
  for_testTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

for_testTestApp::~for_testTestApp() {}

void
for_testTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  for_testApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"for_testTestApp"});
    Registry::registerActionsTo(af, {"for_testTestApp"});
  }
}

void
for_testTestApp::registerApps()
{
  registerApp(for_testApp);
  registerApp(for_testTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
for_testTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  for_testTestApp::registerAll(f, af, s);
}
extern "C" void
for_testTestApp__registerApps()
{
  for_testTestApp::registerApps();
}
