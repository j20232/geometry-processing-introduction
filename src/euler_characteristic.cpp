#include "euler_characteristic.h"
#include <iostream>
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F) {
  Eigen::MatrixXi E = edges(F);
  // |V| = E.maxCoeff() + 1
  // |E| = E.rows()
  // |F| = F.rows()
  // Chi = |V| - |E| + |F|
  int Chi = E.maxCoeff() + 1 - E.rows() + F.rows();
  return Chi;
}
