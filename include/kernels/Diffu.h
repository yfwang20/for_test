#pragma once

#include "Diffusion.h"

class Diffu : public Diffusion
{
public:
    Diffu(const InputParameters & parameters);

    static InputParameters validParams();

protected:
    virtual Real computeQpResidual() override;
    
    virtual Real computeQpJacobian() override;
};