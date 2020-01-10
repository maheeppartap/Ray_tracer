#include "vector.h"
#include <math.h>



float vector_lambai(vector_xyz k) {
  return sqrt(k.x * k.x + k.y * k.y + k.z * k.z);
}


float vec_mul_d(vector_xyz m, vector_xyz n) {
  return m.x * n.x + m.y * n.y + m.z * n.z;
}


vector_xyz vec_mul_c(vector_xyz m, vector_xyz n) {
  vector_xyz answer;
  answer.x = m.y*n.z - m.z*n.y;
  answer.y = m.z*n.x - m.x*n.z;
  answer.z = m.x*n.y - m.y*n.x;
  return answer;
}


vector_xyz vec_add_it(vector_xyz m, vector_xyz n) {
  vector_xyz answer;
  answer.x = m.x + n.x;
  answer.y = m.y + n.y;
  answer.z = m.z + n.z;

  return answer;
}


vector_xyz vec_sub_it(vector_xyz m, vector_xyz n) {
  vector_xyz answer;
  answer.x = m.x - n.x;
  answer.y = m.y - n.y;
  answer.z = m.z - n.z;

  return answer;
}

vector_xyz make_new(coord m, coord n) {
  vector_xyz answer;
  answer.x = n.x - m.x;
  answer.y = n.y - m.y;
  answer.z = n.z - m.z;

  return answer;
}


coord what_p(coord m, vector_xyz n) {
  coord answer;
  answer.x = m.x + n.x;
  answer.y = m.y + n.y;
  answer.z = m.z + n.z;

  return answer;
}


void norm_vec(vector_xyz *m) {
  float answer;

  answer = vector_lambai(*m);
  (*m).x = (*m).x / answer;
  (*m).y = (*m).y / answer;
  (*m).z = (*m).z / answer;
}


vector_xyz vec_x(vector_xyz m, vector_xyz n) {
  vector_xyz answer;

  answer.x = m.x * n.x;
  answer.y = m.y * n.y;
  answer.z = m.z * n.z;

  return answer;
}


vector_xyz vec_scale(vector_xyz m, float n) {
  vector_xyz answ;

  answ.x = n * m.x;
  answ.y = n * m.y;
  answ.z = n * m.z;

  return answ;
}


coord pt_int(coord m, vector_xyz n) {
  float ep = 1e-4;
  norm_vec(&n);
  return what_p(m, vec_scale(n,ep));
}


colour_type rang_add(colour_type m, colour_type n) {
  colour_type answer;

  answer.r = m.r + n.r;
  answer.g = m.g + n.g;
  answer.b = m.b + n.b;

  return answer;
}

colour_type sc_clr(colour_type m, float n) {
  colour_type answer;

  answer.r = n * m.r;
  answer.g = n * m.g;
  answer.b = n * m.b;

  return answer;
}