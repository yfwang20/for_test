#include "Nbc_2.h"

registerMooseObject("for_testApp", Nbc_2);

InputParameters
Nbc_2::validParams()
{
  InputParameters params = IntegratedBC::validParams();

  // Specify input parameters that we want users to be able to set:
  params.addParam<Real>("var", 2.0, "var");
  return params;
}

Nbc_2::Nbc_2(const InputParameters & parameters)
  : IntegratedBC(parameters),
    // store the user-specified parameters from the input file...
    _var(getParam<Real>("var"))
{
}

Real
Nbc_2::computeQpResidual()
{
  return 2 * _test[_i][_qp] * _var;
}