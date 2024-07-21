#pragma once

#include "IntegratedBC.h"

/**
 * Implements a simple constant Neumann BC where grad(u)=alpha * v on the boundary.
 * Uses the term produced from integrating the diffusion operator by parts.
 */
class Nbc_1 : public IntegratedBC
{
public:
  Nbc_1(const InputParameters & parameters);

  static InputParameters validParams();

protected:
  virtual Real computeQpResidual() override;

private:
  Real _var;
};