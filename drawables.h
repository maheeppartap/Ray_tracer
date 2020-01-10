
#include "vector.h"

struct stuff__ {
float SPHERE_reflect;
float SPHERE_transp;
float SPHERE_ref_ind;
float SPHERE_amb[3];   
float SPHERE_diff[3];
float SPHERE_spec[3];
float SPHERE_shine;      
};

typedef struct list_of_sphere {
  int start;               

  coord middle;
  float radius;
  
  struct stuff__ mat;
  struct list_of_sphere *next;
} list_of_spheres;   


list_of_spheres* int_where_(coord, vector_xyz, list_of_spheres*, coord*);

vector_xyz dir_of_sphere(coord, list_of_spheres*);

list_of_spheres* another_one_sphere(list_of_spheres*, coord, float, float[], float[], float[], float, float, float, float, int);


typedef struct chessboard {
  
  coord middle;
  vector_xyz direction;

  float lambai;
  float x_MAX__;
  float X_MIN__;
  float Z_MAX__;
  float Z_MIN__;

  int batwara;
  struct stuff__ black_part__;
  struct stuff__ white_part__;

} chess_board;

int poi(coord, vector_xyz, chess_board *, coord *);


