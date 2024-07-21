[Mesh]
  [generator]
  type = GeneratedMeshGenerator
  dim = 1
  nx = 40
  []
[]

[Variables]
  [u]
    order = FIRST
    family = LAGRANGE
  []
[]

[Kernels]
  [diffu]
    type = Diffu
    variable = u
  []

[]

[BCs]
  [l_d]
    type = DirichletBC
    variable = u
    boundary = left
    value = 1
  []

  [r_d]
    type = DirichletBC
    variable = u
    boundary = right
    value = 2
  []


[]

[VectorPostprocessors]
  [diagonal_flux]
    type = PointValueSampler
    variable = u
    points = '0.1 0 0 0.3 0 0 0.5 0 0 0.8 0 0'
    sort_by = x
  []
[]

[Executioner]
  type = Steady
  solve_type = 'PJFNK'
[]

[Outputs]
  execute_on = 'timestep_end'
  exodus = true
  csv = true
[]
