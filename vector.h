
typedef struct {
  float x;
  float y;
  float z;
} coord;  // geometric 3D point

typedef struct {
  float x;
  float y;
  float z;
} vector_xyz; // geometric 3D vector

typedef struct {
  float r;
  float g;
  float b;
} colour_type;

float vector_lambai(vector_xyz);
float vec_mul_d(vector_xyz, vector_xyz);
vector_xyz vec_mul_c(vector_xyz, vector_xyz);
vector_xyz vec_add_it(vector_xyz, vector_xyz);
vector_xyz vec_sub_it(vector_xyz, vector_xyz);
vector_xyz make_new(coord, coord);
coord what_p(coord, vector_xyz);
void norm_vec(vector_xyz *);
vector_xyz vec_x(vector_xyz, vector_xyz);
vector_xyz vec_scale(vector_xyz, float);
coord pt_int(coord, vector_xyz);
colour_type rang_add(colour_type, colour_type);
colour_type sc_clr(colour_type, float);