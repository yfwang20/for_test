#include "Diffu_2.h"
registerMooseObject("for_testApp", Diffu_2);

InputParameters Diffu_2::validParams()
{
    InputParameters params = Kernel::validParams();
    return params;
}

Diffu_2::Diffu_2(const InputParameters & parameters)
    :   Diffusion(parameters)
{
}

Real Diffu_2::computeQpResidual()
{
    return - 2 * Diffusion::computeQpResidual() - 3 * _test[_i][_qp];
}

Real Diffu_2::computeQpJacobian()
{
    return - 2 * Diffusion::computeQpJacobian();
}