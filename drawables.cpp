#include "drawables.h"
#include <stdlib.h>
#include <math.h>

#include <iostream>
using namespace std;

int poi(coord point_1__, vector_xyz my_ray, chess_board * plane__, coord *hit_where) {
  coord cop = plane__->middle;
  vector_xyz dir_int = plane__->direction;
  

  norm_vec(&my_ray);
  norm_vec(&dir_int);

  coord point_of_hit;
  float y_1 = 0;
  float cross = vec_mul_d(my_ray, dir_int);
  if (cross > 1e-4) {   
    return 0;
  } else {         
    y_1 = vec_mul_d( make_new(point_1__, cop), dir_int) / cross;
    point_of_hit = what_p(point_1__, vec_scale(my_ray, y_1));

    bool j_1 = (point_of_hit.x < plane__->x_MAX__);
    bool j_2 = (point_of_hit.x > plane__->X_MIN__);
    bool j_3 = (point_of_hit.z < plane__->Z_MAX__);
    bool j_4 = (point_of_hit.z > plane__->Z_MIN__);

    if (j_1 && j_2 && j_3 && j_4) { 
      *hit_where = point_of_hit;
      
      float x_coordinate = point_of_hit.x - plane__->X_MIN__;
      float z_coordinate = point_of_hit.z - plane__->Z_MIN__;
      
      int x_coordinate_1 = (int) ((x_coordinate/plane__->lambai)*(plane__->batwara)) + 1; 
      int z_coordinate_1 = (int) ((z_coordinate/plane__->lambai)*(plane__->batwara)) + 1;

      int kind_ = (x_coordinate_1 + z_coordinate_1) % 2 + 1;

      return kind_;
    } else {
      return 0;
    }

  }
  
}


float i_sphere(coord m, vector_xyz n, list_of_spheres *sphere_, coord *where) {

  float max_val = -1.0;
  norm_vec(&n); 

  coord point_1 = sphere_->middle;
  float point_2 = sphere_->radius;
  vector_xyz vect_point = make_new(m,point_1);  

  if (vec_mul_d(vect_point, n) < 0) {   
    
    if (vector_lambai(vect_point) < point_2) {    
     
      vector_xyz p_oc_u = vec_scale( n, vec_mul_d(vect_point,n)/vector_lambai(n) );
      coord pc = what_p(m, p_oc_u);  
                  
      float mm = vector_lambai(make_new(pc,point_1));   
      float mm_ = vector_lambai(make_new(pc,m));   
      float final_dist = sqrt(point_2*point_2 - mm*mm);  
      max_val = final_dist - mm_;
      *where = what_p(m , vec_scale(n,max_val));

    } else if (vector_lambai(vect_point) == point_2) {
      
      *where = m;
    }

  } else {  

    vector_xyz scaled_vector_u = vec_scale( n, vec_mul_d(vect_point,n)/vector_lambai(n) );  
    coord points_in_svu = what_p(m, scaled_vector_u);  

    float a__1 = vector_lambai(make_new(points_in_svu,point_1));   
    if (a__1 < point_2) { 

      float dist_2 = sqrt(point_2*point_2 - a__1*a__1);  

      if (vector_lambai(vect_point) > point_2) {    
        max_val = vector_lambai(make_new(points_in_svu,m)) - dist_2;
      } else {                  
        max_val = vector_lambai(make_new(points_in_svu,m)) + dist_2;
      }

      *where = what_p(m , vec_scale(n,max_val));
    }
  }

  return max_val;
}


list_of_spheres *int_where_(coord m, vector_xyz ray__, list_of_spheres *tot_spheres, coord *where_hit) {

  
  list_of_spheres * sp_1 = NULL;
  coord hit_11;



  float max_d, min_d = 100000.0;
  while(tot_spheres != NULL) {
      max_d = i_sphere(m, ray__, tot_spheres,&hit_11);
      if (max_d >= 0.0 && max_d < min_d) {
        min_d = max_d;
        sp_1 = tot_spheres;
        *where_hit = hit_11;
      }

      tot_spheres = tot_spheres->next;

  }

	return sp_1;
}

list_of_spheres *another_one_sphere(list_of_spheres *slist, coord ctr, float rad, float amb[],
		    float dif[], float spe[], float shine, 
		    float refl, float trans, float SPHERE_ref_ind, int sindex) {
  list_of_spheres *new_sphere;

  new_sphere = (list_of_spheres *)malloc(sizeof(list_of_spheres));
  new_sphere->start = sindex;
  new_sphere->middle = ctr;
  new_sphere->radius = rad;
  (new_sphere->mat.SPHERE_amb)[0] = 1;
  (new_sphere->mat.SPHERE_amb)[1] = 1;
  (new_sphere->mat.SPHERE_amb)[2] = 1;
  (new_sphere->mat.SPHERE_diff)[0] = dif[0];
  (new_sphere->mat.SPHERE_diff)[1] = dif[1];
  (new_sphere->mat.SPHERE_diff)[2] = dif[2];
  (new_sphere->mat.SPHERE_spec)[0] = spe[0];
  (new_sphere->mat.SPHERE_spec)[1] = spe[1];
  (new_sphere->mat.SPHERE_spec)[2] = spe[2];
  new_sphere->mat.SPHERE_shine = shine;
  new_sphere->mat.SPHERE_reflect = refl;
  new_sphere->mat.SPHERE_transp = trans;
  new_sphere->mat.SPHERE_ref_ind = SPHERE_ref_ind;
  new_sphere->next = NULL;

  if (slist == NULL) { 
    slist = new_sphere;
  } else { 
    new_sphere->next = slist;
    slist = new_sphere;
  }

  return slist;
}

vector_xyz dir_of_sphere(coord q, list_of_spheres *sph) {
  vector_xyz rc;

  rc = make_new(sph->middle, q);
  norm_vec(&rc);
  return rc;
}