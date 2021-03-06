#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<double> > Matrix;
typedef vector<double> Vector;

class FEMSolver {
public:
  FEMSolver(
    int num_nodes_x, int num_nodes_y, double length_x, double length_y,
    double E, double nu
  );
  ~FEMSolver();
  void get_stiffness_matrix(double* data, int* rows, int* cols);
private:
  int num_nodes, num_elems;
  int num_nodes_x, num_nodes_y;
  double length_x, length_y;
  double dr_dx, ds_dy;
  vector<vector<double> > nodes;
  vector<vector<int> > elems;
  vector<vector<double> > D_voigt;
  vector<vector<double> > Ke_;
  
  
  void compute_nodes();
  void compute_elems();
  void compute_D(double E, double nu);
  // void compute_KG();
  void compute_Ke(double x1, double x2, double y1, double y2);
  // void compute_Ke(int elem_id);
};
