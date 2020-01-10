#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include "my_defined_scenes.h"
#include "drawables.h"

#include <iostream>
using namespace std;
extern int fnal_window_width__;
extern int final_window_height;
extern GLfloat IMAGE_final_global[WIN_HEIGHT][WIN_WIDTH][3];  
extern float pic_width__global;
extern float pic_img_height__gloabl;
extern coord user_position;
extern float img_plane_GLOBAL;
extern colour_type back_clr_Global;
extern colour_type black_colour;
extern list_of_spheres *spheres_in_img;
extern chess_board main_c_board__;
extern coord light_id_1;
extern float light_id_1_amb[3];
extern float light_id_1_diff[3];
extern float light_id_1_spec[3];
extern float gloabal_lighting_amb[3];
extern float decay_a;
extern float decay_b;
extern float decay_c;
extern int step_max;
extern bool shadow_on;
extern bool reflection_on;
extern bool refraction_on;
extern bool chess_pattern_on;
extern bool diffuse_rend_on;
extern bool super_samp_on;
const double PI = 3.14159265358979;

vector_xyz ray_r(vector_xyz n) {

  float x_1 = ((float) rand() / (RAND_MAX)) * 2 - 1;    
  float x_2 = ((float) rand() / (RAND_MAX)) * PI;       
  float x_3 = ((float) rand() / (RAND_MAX));           

  float x_4 = sqrt(1-x_1*x_1)*cos(x_1);
  float x_5 = sqrt(1-x_1*x_1)*sin(x_2);
  float x_6 = x_3;
  coord point = {x_4,x_5,x_6};
  
  vector_xyz ab;
  if (abs(n.z) < 0.0001 && abs(n.y) < 0.0001) {
    ab = {-n.z, 0.0, n.x};
  } else {
    ab = {0.0, -n.z, n.y};
  }

  vector_xyz b = vec_mul_c(n,ab);
  norm_vec(&ab);
  norm_vec(&b);
  norm_vec(&n);
  
  vector_xyz answer;
  answer.x = ab.x*point.x + b.x*point.y + n.x*point.z;
  answer.y = ab.y*point.x + b.y*point.y + n.y*point.z;
  answer.z = ab.z*point.x + b.z*point.y + n.z*point.z;
  return answer;
}



vector_xyz refraction__(vector_xyz m, vector_xyz n, float o, float op) {
  n = vec_scale (n, -1.0);
  norm_vec(&m);
  norm_vec(&n);
  float nr = o/op;
  vector_xyz t;
  float n_dot_v = vec_mul_d(m, n);
  float root_part = sqrtf( 1 - nr*nr*( 1 - n_dot_v*n_dot_v ) );
  if (root_part >= 0.0) {
    t = vec_sub_it( vec_scale(m, nr*n_dot_v - root_part), vec_scale(n, nr) );
  }
  return t;
}

vector_xyz ref__(vector_xyz m, vector_xyz n) {
  n = vec_scale(n, -1.0);
  return vec_sub_it( vec_scale( m, 2*(vec_mul_d(m,n)) ) , n ); 
}


colour_type eqn_l(coord m_1, vector_xyz m_2, struct stuff__ *stuff) {
	colour_type answer;

  vector_xyz new_1 = make_new(m_1, light_id_1);      
  vector_xyz new_2 = make_new(m_1, user_position);     
  vector_xyz new_3 = ref__(m_2, vec_scale(new_1, -1.0));    
  float length_of_l = vector_lambai(new_1);   
  int def_;    
  norm_vec(&new_1);
  norm_vec(&m_2);
  norm_vec(&new_2);
  norm_vec(&new_3);
  if (vec_mul_d(m_2,new_1) > 0) {   
    def_ = 1;
  } else {    
    def_ = 0;
  }
  float shiny_part = stuff->SPHERE_shine;
  float attenuation_factor = 1 / ( decay_a + decay_b*length_of_l + decay_c*length_of_l*length_of_l );  
  colour_type att_var_1 = {gloabal_lighting_amb[0], gloabal_lighting_amb[1], gloabal_lighting_amb[2]};
  float att_var_2 = stuff->SPHERE_reflect;
  colour_type att_var_3 = {light_id_1_amb[0], light_id_1_amb[1], light_id_1_amb[2]};
  colour_type att_var_4 = {stuff->SPHERE_amb[0], stuff->SPHERE_amb[1], stuff->SPHERE_amb[2]};
  colour_type att_var_5 = {light_id_1_diff[0], light_id_1_diff[1], light_id_1_diff[2]};
  colour_type att_var_6 = {stuff->SPHERE_diff[0], stuff->SPHERE_diff[1], stuff->SPHERE_diff[2]};
  colour_type att_var_7 = {light_id_1_spec[0], light_id_1_spec[1], light_id_1_spec[2]};
  colour_type att_var_8 = {stuff->SPHERE_spec[0], stuff->SPHERE_spec[1], stuff->SPHERE_spec[2]};
  answer.r = (att_var_1.r * att_var_2) + (att_var_3.r * att_var_4.r) + attenuation_factor * (def_ * att_var_5.r * att_var_6.r *vec_mul_d(m_2,new_1) + att_var_7.r * att_var_8.r * pow(vec_mul_d(new_3,new_2), shiny_part) );
  answer.g = (att_var_1.g * att_var_2) + (att_var_3.g * att_var_4.g) + attenuation_factor * (def_ * att_var_5.g * att_var_6.g *vec_mul_d(m_2,new_1) + att_var_7.g * att_var_8.g * pow(vec_mul_d(new_3,new_2), shiny_part) );
  answer.b = (att_var_1.b * att_var_2) + (att_var_3.b * att_var_4.b) + attenuation_factor * (def_ * att_var_5.b * att_var_6.b *vec_mul_d(m_2,new_1) + att_var_7.b * att_var_8.b * pow(vec_mul_d(new_3,new_2), shiny_part) );

	return answer;
}

colour_type TRACER__(coord m_1, vector_xyz p_ray, int times) {

  colour_type local_light, ref_light, tr_light, d_light;
  ref_light = {0.0, 0.0, 0.0};
  tr_light = {0.0, 0.0, 0.0};
  d_light = {0.0, 0.0, 0.0};
  vector_xyz l_1,n_1,k_1,v_1;         
  coord int_point_maybe;                
  struct stuff__ stuff_proper;  
  bool sh_flag = 0;    
  bool in_flag = 0;     
  int tile_flag = 0;     

  if (times > step_max) return back_clr_Global;

  list_of_spheres * sph = int_where_(m_1, p_ray, spheres_in_img, &int_point_maybe);

  if (sph!= NULL) {                  
 
    l_1 = dir_of_sphere(int_point_maybe, sph);        
    n_1 = make_new( int_point_maybe, light_id_1);          
    stuff_proper = sph->mat;                
    in_flag = 1;

  } else if (chess_pattern_on && sph == NULL) {     
    tile_flag = poi(m_1, p_ray, &main_c_board__, &int_point_maybe);
    if (tile_flag != 0) {                           

      l_1 = main_c_board__.direction;                           
      n_1 = make_new( int_point_maybe, light_id_1);                 
      if (tile_flag == 1) stuff_proper = main_c_board__.black_part__;  
      if (tile_flag == 2) stuff_proper = main_c_board__.white_part__;  
      in_flag = 1;

    }
  }

  if (in_flag == 1) { 
    
    if (shadow_on) {  
      coord qq; 
      if (int_where_( pt_int(int_point_maybe,l_1) , n_1, spheres_in_img, &qq) != NULL)
        sh_flag = 1;
    }

    if (sh_flag) { 
      colour_type I_ga = {gloabal_lighting_amb[0], gloabal_lighting_amb[1], gloabal_lighting_amb[2]};
      float k_ga = stuff_proper.SPHERE_reflect;
      colour_type I_a = {light_id_1_amb[0], light_id_1_amb[1], light_id_1_amb[2]};
      colour_type k_a = {stuff_proper.SPHERE_amb[0], stuff_proper.SPHERE_amb[1], stuff_proper.SPHERE_amb[2]};
      local_light.r = (I_ga.r * k_ga) + (I_a.r * k_a.r);
      local_light.g = (I_ga.g * k_ga) + (I_a.g * k_a.g);
      local_light.b = (I_ga.b * k_ga) + (I_a.b * k_a.b);
    } else {          
      local_light = eqn_l(int_point_maybe, l_1, &stuff_proper);
    }

    if (reflection_on) { 
      k_1 = ref__( l_1, p_ray );     
      ref_light = sc_clr( TRACER__( pt_int(int_point_maybe,k_1) , k_1, times + 1) , stuff_proper.SPHERE_reflect );
    }

    if (diffuse_rend_on) {
      for (int i=0; i<NUM_DIFF_RAYS; i++) {
        vector_xyz d_ray = ray_r(l_1);
        colour_type d_color = sc_clr( TRACER__( pt_int(int_point_maybe,l_1) , d_ray, times + 1) , stuff_proper.SPHERE_reflect );
        d_light = sc_clr(rang_add(d_light, d_color), 1.0/NUM_DIFF_RAYS);
      }
    }

    if (refraction_on && (stuff_proper.SPHERE_transp > 0.0)) { 

      if (vec_mul_d(l_1, p_ray) < 0.0) {                      
        v_1 = refraction__( l_1, p_ray, 1.0, stuff_proper.SPHERE_ref_ind);
      } else {                                         
        v_1 = refraction__( vec_scale(l_1, -1.0), p_ray, stuff_proper.SPHERE_ref_ind, 1.0);
      
      }

        coord qq;
        p_ray = v_1;
        list_of_spheres * sph2 = int_where_( pt_int(int_point_maybe,p_ray), p_ray, spheres_in_img, &qq );

        
        if (sph2 != NULL) {
          l_1 = dir_of_sphere(qq, sph2);
          stuff_proper = sph2->mat;
          if (vec_mul_d(l_1, p_ray) < 0.0) {                     
            v_1 = refraction__( l_1, p_ray, 1.0, stuff_proper.SPHERE_ref_ind);
          } else {                                          
            v_1 = refraction__( vec_scale(l_1, -1.0), p_ray, stuff_proper.SPHERE_ref_ind, 1.0);
          }
          tr_light = sc_clr( TRACER__( pt_int(qq,v_1) , v_1, times + 1) , stuff_proper.SPHERE_transp);
        } else {
          return back_clr_Global;
        }
    }

  } else {

    return back_clr_Global;
  }

  colour_type answer;
  answer.r = local_light.r + ref_light.r + tr_light.r + d_light.r;
  answer.g = local_light.g + ref_light.g + tr_light.g + d_light.g;
  answer.b = local_light.b + ref_light.b + tr_light.b + d_light.b;

	return answer;
}

void run() {

  float g_l_x = pic_width__global / float(fnal_window_width__);
  float g_l_y = pic_img_height__gloabl / float(final_window_height);
  float s_x = -0.5 * pic_width__global;
  float s_y = -0.5 * pic_img_height__gloabl;
  int sup_s_const = 5;
  vector_xyz ray[sup_s_const];
  float x, y, z;
  if (!super_samp_on) {
    sup_s_const = 1;
  }
  srand(time(0));
  coord locations;
  locations.x = s_x + 0.5 * g_l_x;
  locations.y = s_y + 0.5 * g_l_y;
  locations.z = img_plane_GLOBAL;
  int i, j, k;
  float xl, xr, yu, yd;
  for (i=0; i<final_window_height; i++) {
    for (j=0; j<fnal_window_width__; j++) {

      x = locations.x;
      y = locations.y;
      z = locations.z;
      
      ray[0] = make_new(user_position, {x,y,z});

      if (super_samp_on) {
        xl = locations.x - 0.25*g_l_x;
        xr = locations.x + 0.25*g_l_x;
        yu = locations.y - 0.25*g_l_y;
        yd = locations.y + 0.25*g_l_y;
        ray[1] = make_new(user_position, {xl,yu,z});
        ray[2] = make_new(user_position, {xl,yd,z});
        ray[3] = make_new(user_position, {xr,yu,z});
        ray[4] = make_new(user_position, {xr,yd,z});
      }
	  colour_type answer;
      answer = {0.0,0.0,0.0};
      for (k=0; k<sup_s_const; k++) {
        answer = rang_add( answer, TRACER__(user_position, ray[k], 0) );
      }      
      answer = sc_clr( answer, 1.0/sup_s_const );

      IMAGE_final_global[i][j][0] = GLfloat(answer.r);
      IMAGE_final_global[i][j][1] = GLfloat(answer.g);
      IMAGE_final_global[i][j][2] = GLfloat(answer.b);

      locations.x += g_l_x;
    }

    locations.y += g_l_y;
    locations.x = s_x;
  }
}
