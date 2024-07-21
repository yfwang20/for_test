#include "Nbc_1.h"

registerMooseObject("for_testApp", Nbc_1);

InputParameters
Nbc_1::validParams()
{
  InputParameters params = IntegratedBC::validParams();

  // Specify input parameters that we want users to be able to set:
  params.addParam<Real>("var", 1.0, "var");
  return params;
}

Nbc_1::Nbc_1(const InputParameters & parameters)
  : IntegratedBC(parameters),
    // store the user-specified parameters from the input file...
    _var(getParam<Real>("var"))
{
}

Real
Nbc_1::computeQpResidual()
{
  return _test[_i][_qp] * _var;
}