#pragma once

#include "Diffusion.h"

class Diffu_2 : public Diffusion
{
public:
    Diffu_2(const InputParameters & parameters);

    static InputParameters validParams();

protected:
    virtual Real computeQpResidual() override;
    
    virtual Real computeQpJacobian() override;
};