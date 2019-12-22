#include "edges.h"
#include <algorithm>
#include <set>

Eigen::MatrixXi edges(const Eigen::MatrixXi &F) {
  Eigen::MatrixXi E(F.rows() * 3 / 2, 2);

  // Add all edges to the set
  std::set<std::pair<int, int>> edges;
  int min_v, max_v;
  for (int i = 0; i < F.rows(); i++) {
    min_v = std::min(F(i, 0), F(i, 1));
    max_v = std::max(F(i, 0), F(i, 1));
    edges.insert(std::make_pair(min_v, max_v));

    min_v = std::min(F(i, 1), F(i, 2));
    max_v = std::max(F(i, 2), F(i, 1));
    edges.insert(std::make_pair(min_v, max_v));

    min_v = std::min(F(i, 2), F(i, 0));
    max_v = std::max(F(i, 2), F(i, 0));
    edges.insert(std::make_pair(min_v, max_v));
  }

  // Assign each edge to E
  int edge_index = 0;
  for (std::set<std::pair<int, int>>::iterator e = edges.begin();
       e != edges.end(); e++) {
    std::pair<int, int> edge = *e;
    E(edge_index, 0) = edge.first;
    E(edge_index++, 1) = edge.second;
  }

  return E;
}
