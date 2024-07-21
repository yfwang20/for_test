#include "Diffu.h"
registerMooseObject("for_testApp", Diffu);

InputParameters Diffu::validParams()
{
    InputParameters params = Kernel::validParams();
    return params;
}

Diffu::Diffu(const InputParameters & parameters)
    :   Diffusion(parameters)
{
}

Real Diffu::computeQpResidual()
{
    return - Diffusion::computeQpResidual();
}

Real Diffu::computeQpJacobian()
{
    return - Diffusion::computeQpJacobian();
}