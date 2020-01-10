//
// this provide functions to set up the scene
//
#include "drawables.h"
#include <stdio.h>

extern coord light_id_1;
extern float light_id_1_amb[3];
extern float light_id_1_diff[3];
extern float light_id_1_spec[3];

extern float gloabal_lighting_amb[3];
extern list_of_spheres* spheres_in_img;

extern colour_type back_clr_Global;
extern float decay_a;
extern float decay_b;
extern float decay_c;

extern coord user_position;

extern chess_board main_c_board__;


void scene_1() {


	
	main_c_board__.middle = { 0.0, -2.0, -4.0 };
	main_c_board__.direction = { 0.0, 1.0, 0.0 };
	main_c_board__.lambai = 30.0;
	main_c_board__.x_MAX__ = main_c_board__.middle.x + (main_c_board__.lambai / 2.0);
	main_c_board__.X_MIN__ = main_c_board__.middle.x - (main_c_board__.lambai / 2.0);
	main_c_board__.Z_MAX__ = main_c_board__.middle.z + (main_c_board__.lambai / 2.0);
	main_c_board__.Z_MIN__ = main_c_board__.middle.z - (main_c_board__.lambai / 2.0);
	main_c_board__.batwara = 40;


	main_c_board__.black_part__.SPHERE_amb[0] = 0.0;
	main_c_board__.black_part__.SPHERE_amb[1] = 0.0;
	main_c_board__.black_part__.SPHERE_amb[2] = 0.0;
	main_c_board__.black_part__.SPHERE_diff[0] = 0.0;
	main_c_board__.black_part__.SPHERE_diff[1] = 0.0;
	main_c_board__.black_part__.SPHERE_diff[2] = 0.0;
	main_c_board__.black_part__.SPHERE_spec[0] = 1.0;
	main_c_board__.black_part__.SPHERE_spec[1] = 1.0;
	main_c_board__.black_part__.SPHERE_spec[2] = 1.0;
	main_c_board__.black_part__.SPHERE_shine = 50;
	main_c_board__.black_part__.SPHERE_reflect = 0.5;
	main_c_board__.black_part__.SPHERE_transp = 0.0;
	main_c_board__.black_part__.SPHERE_ref_ind = 0.0;

	main_c_board__.white_part__.SPHERE_amb[0] = 0.0;
	main_c_board__.white_part__.SPHERE_amb[1] = 0.0;
	main_c_board__.white_part__.SPHERE_amb[2] = 0.0;
	main_c_board__.white_part__.SPHERE_diff[0] = 1.0;
	main_c_board__.white_part__.SPHERE_diff[1] = 1.0;
	main_c_board__.white_part__.SPHERE_diff[2] = 1.0;
	main_c_board__.white_part__.SPHERE_spec[0] = 1.0;
	main_c_board__.white_part__.SPHERE_spec[1] = 1.0;
	main_c_board__.white_part__.SPHERE_spec[2] = 1.0;
	main_c_board__.white_part__.SPHERE_shine = 50;
	main_c_board__.white_part__.SPHERE_reflect = 0.5;
	main_c_board__.white_part__.SPHERE_transp = 0.0;
	main_c_board__.white_part__.SPHERE_ref_ind = 0.0;

	gloabal_lighting_amb[0] = 0.2;
	gloabal_lighting_amb[1] = 0.2;
	gloabal_lighting_amb[2] = 0.2;


	light_id_1.x = -2.0;
	light_id_1.y = 5.0;
	light_id_1.z = 1.0;
	light_id_1_amb[0] = 0.1;
	light_id_1_amb[1] = 0.1;
	light_id_1_amb[2] = 0.1;
	light_id_1_diff[0] = 1;
	light_id_1_diff[1] = 1;
	light_id_1_diff[2] = 1;
	light_id_1_spec[0] = 1;
	light_id_1_spec[1] = 1;
	light_id_1_spec[2] = 1;



	// sphere 1
	coord sphere1_ctr = { 1.9, -0.2, -3.2 };
	float sphere1_rad = 1.23;
	float sphere1_ambient[] = { 0.7, 0.7, 0.7 };
	float sphere1_diffuse[] = { 0.1, 0.5, 0.8 };
	float sphere1_specular[] = { 0.0, 0.0, 0.0 };
	float sphere1_shineness = 10;
	float sphere1_reflectance = 0.4;
	float sphere1_transparency = 0.0;
	float sphere1_ref_index = 1.0;
	spheres_in_img = another_one_sphere(spheres_in_img, sphere1_ctr, sphere1_rad, sphere1_ambient,
		sphere1_diffuse, sphere1_specular, sphere1_shineness,
		sphere1_reflectance, sphere1_transparency, sphere1_ref_index, 1);
	

coord sphere4_ctr = { 2.1, -0.2, -3.2 };
	float sphere4_rad = 1.28;
	float sphere4_ambient[] = { 0.7, 0.7, 0.7 };
	float sphere4_diffuse[] = { 0.1, 0.5, 0.8 };
	float sphere4_specular[] = { 0.0, 0.0, 0.0 };
	float sphere4_shineness = 10;
	float sphere4_reflectance = 0.4;
	float sphere4_transparency = 0.0;
	float sphere4_ref_index = 1.0;
	spheres_in_img = another_one_sphere(spheres_in_img, sphere4_ctr, sphere4_rad, sphere4_ambient,
		sphere4_diffuse, sphere4_specular, sphere4_shineness,
		sphere4_reflectance, sphere4_transparency, sphere4_ref_index, 4);



	
	coord sphere2_ctr = { -1.9, 0.0, -3.5 };
	float sphere2_rad = 1.5;
	float sphere2_ambient[] = { 0.6, 0.6, 0.6 };
	float sphere2_diffuse[] = { 1.0, 0.0, 0.25 };
	float sphere2_specular[] = { 1.0, 1.0, 1.0 };
	float sphere2_shineness = 6;
	float sphere2_reflectance = 0.3;
	float sphere2_transparency = 0.0;
	float sphere2_ref_index = 1.0;
	spheres_in_img = another_one_sphere(spheres_in_img, sphere2_ctr, sphere2_rad, sphere2_ambient,
		sphere2_diffuse, sphere2_specular, sphere2_shineness,
		sphere2_reflectance, sphere2_transparency, sphere2_ref_index, 2);

	// sphere 3
	coord sphere3_ctr = { 0.0, -0.4, -0.75 };
	float sphere3_rad = 0.2;
	float sphere3_ambient[] = { 1.2, 1.2, 0.2 };
	float sphere3_diffuse[] = { 0.0, 1.0, 0.25 };
	float sphere3_specular[] = { 0.0, 1.0, 1.0 };
	float sphere3_shineness = 30;
	float sphere3_reflectance = 0.3;
	float sphere3_transparency = 0.0;
	float sphere3_ref_index = 1.0;
	spheres_in_img = another_one_sphere(spheres_in_img, sphere3_ctr, sphere3_rad, sphere3_ambient,
		sphere3_diffuse, sphere3_specular, sphere3_shineness,
		sphere3_reflectance, sphere3_transparency, sphere3_ref_index, 3);


	back_clr_Global.r = 0.0;
	back_clr_Global.g = 0.0;
	back_clr_Global.b = 0.0;
	
	decay_a = 0.1;
	decay_b = 0.1;
	decay_c = 0.0;

}

void scene_2() {


	main_c_board__.middle = { 0.0, -2.0, -4.0 };
	main_c_board__.direction = { 0.0, 1.0, 0.0 };
	main_c_board__.lambai = 30.0;
	main_c_board__.x_MAX__ = main_c_board__.middle.x + (main_c_board__.lambai / 2.0);
	main_c_board__.X_MIN__ = main_c_board__.middle.x - (main_c_board__.lambai / 2.0);
	main_c_board__.Z_MAX__ = main_c_board__.middle.z + (main_c_board__.lambai / 2.0);
	main_c_board__.Z_MIN__ = main_c_board__.middle.z - (main_c_board__.lambai / 2.0);
	main_c_board__.batwara = 40;


	main_c_board__.black_part__.SPHERE_amb[0] = 0.0;
	main_c_board__.black_part__.SPHERE_amb[1] = 0.0;
	main_c_board__.black_part__.SPHERE_amb[2] = 0.0;
	main_c_board__.black_part__.SPHERE_diff[0] = 0.0;
	main_c_board__.black_part__.SPHERE_diff[1] = 0.0;
	main_c_board__.black_part__.SPHERE_diff[2] = 0.0;
	main_c_board__.black_part__.SPHERE_spec[0] = 1.0;
	main_c_board__.black_part__.SPHERE_spec[1] = 1.0;
	main_c_board__.black_part__.SPHERE_spec[2] = 1.0;
	main_c_board__.black_part__.SPHERE_shine = 50;
	main_c_board__.black_part__.SPHERE_reflect = 0.5;
	main_c_board__.black_part__.SPHERE_transp = 0.0;
	main_c_board__.black_part__.SPHERE_ref_ind = 0.0;

	main_c_board__.white_part__.SPHERE_amb[0] = 0.0;
	main_c_board__.white_part__.SPHERE_amb[1] = 0.0;
	main_c_board__.white_part__.SPHERE_amb[2] = 0.0;
	main_c_board__.white_part__.SPHERE_diff[0] = 1.0;
	main_c_board__.white_part__.SPHERE_diff[1] = 1.0;
	main_c_board__.white_part__.SPHERE_diff[2] = 1.0;
	main_c_board__.white_part__.SPHERE_spec[0] = 1.0;
	main_c_board__.white_part__.SPHERE_spec[1] = 1.0;
	main_c_board__.white_part__.SPHERE_spec[2] = 1.0;
	main_c_board__.white_part__.SPHERE_shine = 50;
	main_c_board__.white_part__.SPHERE_reflect = 0.5;
	main_c_board__.white_part__.SPHERE_transp = 0.0;
	main_c_board__.white_part__.SPHERE_ref_ind = 0.0;

	gloabal_lighting_amb[0] = 0.2;
	gloabal_lighting_amb[1] = 0.2;
	gloabal_lighting_amb[2] = 0.2;


	light_id_1.x = -2.0;
	light_id_1.y = 5.0;
	light_id_1.z = 1.0;
	light_id_1_amb[0] = 0.1;
	light_id_1_amb[1] = 0.1;
	light_id_1_amb[2] = 0.1;
	light_id_1_diff[0] = 1;
	light_id_1_diff[1] = 1;
	light_id_1_diff[2] = 1;
	light_id_1_spec[0] = 1;
	light_id_1_spec[1] = 1;
	light_id_1_spec[2] = 1;



	// sphere 1
	coord sphere1_ctr = { 1.5, -0.2, -3.2 };
	float sphere1_rad = 1.23;
	float sphere1_ambient[] = { 0.7, 0.7, 0.7 };
	float sphere1_diffuse[] = { 0.1, 0.5, 0.8 };
	float sphere1_specular[] = { 1.0, 1.0, 1.0 };
	float sphere1_shineness = 30;
	float sphere1_reflectance = 0.4;
	float sphere1_transparency = 0.0;
	float sphere1_ref_index = 1.0;
	spheres_in_img = another_one_sphere(spheres_in_img, sphere1_ctr, sphere1_rad, sphere1_ambient,
		sphere1_diffuse, sphere1_specular, sphere1_shineness,
		sphere1_reflectance, sphere1_transparency, sphere1_ref_index, 1);

	// sphere 2
	coord sphere2_ctr = { -0.5, 0.2, -2.2  };
	float sphere2_rad = 0.7;
	float sphere2_ambient[] = { 0.6, 0.6, 0.6 };
	float sphere2_diffuse[] = { 1.0, 0.0, 0.25 };
	float sphere2_specular[] = { 1.0, 1.0, 1.0 };
	float sphere2_shineness = 6;
	float sphere2_reflectance = 0.3;
	float sphere2_transparency = 0.0;
	float sphere2_ref_index = 1.0;
	spheres_in_img = another_one_sphere(spheres_in_img, sphere2_ctr, sphere2_rad, sphere2_ambient,
		sphere2_diffuse, sphere2_specular, sphere2_shineness,
		sphere2_reflectance, sphere2_transparency, sphere2_ref_index, 2);

	// sphere 3
	coord sphere3_ctr = { -0.7, -0.9, -2 };
	float sphere3_rad = 0.3;
	float sphere3_ambient[] = { 1.2, 1.2, 0.2 };
	float sphere3_diffuse[] = { 0.0, 1.0, 0.25 };
	float sphere3_specular[] = { 0.0, 1.0, 1.0 };
	float sphere3_shineness = 30;
	float sphere3_reflectance = 0.3;
	float sphere3_transparency = 0.0;
	float sphere3_ref_index = 1.0;
	spheres_in_img = another_one_sphere(spheres_in_img, sphere3_ctr, sphere3_rad, sphere3_ambient,
		sphere3_diffuse, sphere3_specular, sphere3_shineness,
		sphere3_reflectance, sphere3_transparency, sphere3_ref_index, 3);


	back_clr_Global.r = 0.0;
	back_clr_Global.g = 0.0;
	back_clr_Global.b = 0.0;
	
	decay_a = 0.1;
	decay_b = 0.1;
	decay_c = 0.0;
}


void scene_3() {

	main_c_board__.middle = { 0.0, -2.0, -4.0 };
	main_c_board__.direction = { 0.0, 1.0, 0.0 };
	main_c_board__.lambai = 30.0;
	main_c_board__.x_MAX__ = main_c_board__.middle.x + (main_c_board__.lambai / 2.0);
	main_c_board__.X_MIN__ = main_c_board__.middle.x - (main_c_board__.lambai / 2.0);
	main_c_board__.Z_MAX__ = main_c_board__.middle.z + (main_c_board__.lambai / 2.0);
	main_c_board__.Z_MIN__ = main_c_board__.middle.z - (main_c_board__.lambai / 2.0);
	main_c_board__.batwara = 40;


	main_c_board__.black_part__.SPHERE_amb[0] = 0.0;
	main_c_board__.black_part__.SPHERE_amb[1] = 0.0;
	main_c_board__.black_part__.SPHERE_amb[2] = 0.0;
	main_c_board__.black_part__.SPHERE_diff[0] = 0.0;
	main_c_board__.black_part__.SPHERE_diff[1] = 0.0;
	main_c_board__.black_part__.SPHERE_diff[2] = 0.0;
	main_c_board__.black_part__.SPHERE_spec[0] = 1.0;
	main_c_board__.black_part__.SPHERE_spec[1] = 1.0;
	main_c_board__.black_part__.SPHERE_spec[2] = 1.0;
	main_c_board__.black_part__.SPHERE_shine = 50;
	main_c_board__.black_part__.SPHERE_reflect = 0.5;
	main_c_board__.black_part__.SPHERE_transp = 0.0;
	main_c_board__.black_part__.SPHERE_ref_ind = 0.0;

	main_c_board__.white_part__.SPHERE_amb[0] = 0.0;
	main_c_board__.white_part__.SPHERE_amb[1] = 0.0;
	main_c_board__.white_part__.SPHERE_amb[2] = 0.0;
	main_c_board__.white_part__.SPHERE_diff[0] = 1.0;
	main_c_board__.white_part__.SPHERE_diff[1] = 1.0;
	main_c_board__.white_part__.SPHERE_diff[2] = 1.0;
	main_c_board__.white_part__.SPHERE_spec[0] = 1.0;
	main_c_board__.white_part__.SPHERE_spec[1] = 1.0;
	main_c_board__.white_part__.SPHERE_spec[2] = 1.0;
	main_c_board__.white_part__.SPHERE_shine = 50;
	main_c_board__.white_part__.SPHERE_reflect = 0.5;
	main_c_board__.white_part__.SPHERE_transp = 0.0;
	main_c_board__.white_part__.SPHERE_ref_ind = 0.0;

	gloabal_lighting_amb[0] = 0.2;
	gloabal_lighting_amb[1] = 0.2;
	gloabal_lighting_amb[2] = 0.2;


	light_id_1.x = -2.0;
	light_id_1.y = 5.0;
	light_id_1.z = 1.0;
	light_id_1_amb[0] = 0.1;
	light_id_1_amb[1] = 0.1;
	light_id_1_amb[2] = 0.1;
	light_id_1_diff[0] = 1;
	light_id_1_diff[1] = 1;
	light_id_1_diff[2] = 1;
	light_id_1_spec[0] = 1;
	light_id_1_spec[1] = 1;
	light_id_1_spec[2] = 1;



	// sphere 1
	coord sphere1_ctr = { 1.5, -0.2, -3.2 };
	float sphere1_rad = 1.23;
	float sphere1_ambient[] = { 0.7, 0.7, 0.7 };
	float sphere1_diffuse[] = { 0.1, 0.5, 0.8 };
	float sphere1_specular[] = { 1.0, 1.0, 1.0 };
	float sphere1_shineness = 6;
	float sphere1_reflectance = 2.0;
	float sphere1_transparency = 5.0;
	float sphere1_ref_index = 1.5;
	spheres_in_img = another_one_sphere(spheres_in_img, sphere1_ctr, sphere1_rad, sphere1_ambient,
		sphere1_diffuse, sphere1_specular, sphere1_shineness,
		sphere1_reflectance, sphere1_transparency, sphere1_ref_index, 1);

	// sphere 2
	coord sphere2_ctr = { -0.5, 0.2, -2.2  };
	float sphere2_rad = 0.7;
	float sphere2_ambient[] = { 0.6, 0.6, 0.6 };
	float sphere2_diffuse[] = { 1.0, 0.0, 0.25 };
	float sphere2_specular[] = { 1.0, 1.0, 1.0 };
	float sphere2_shineness = 6;
	float sphere2_reflectance = 2.0;
	float sphere2_transparency = 5.0;
	float sphere2_ref_index = 1.5;
	spheres_in_img = another_one_sphere(spheres_in_img, sphere2_ctr, sphere2_rad, sphere2_ambient,
		sphere2_diffuse, sphere2_specular, sphere2_shineness,
		sphere2_reflectance, sphere2_transparency, sphere2_ref_index, 2);

	// sphere 3
	coord sphere3_ctr = { -0.7, -0.9, -2 };
	float sphere3_rad = 0.3;
	float sphere3_ambient[] = { 1.2, 1.2, 0.2 };
	float sphere3_diffuse[] = { 0.0, 1.0, 0.25 };
	float sphere3_specular[] = { 0.0, 1.0, 1.0 };
	float sphere3_shineness = 6;
	float sphere3_reflectance = 2.0;
	float sphere3_transparency = 5;
	float sphere3_ref_index = 1.5;
	spheres_in_img = another_one_sphere(spheres_in_img, sphere3_ctr, sphere3_rad, sphere3_ambient,
		sphere3_diffuse, sphere3_specular, sphere3_shineness,
		sphere3_reflectance, sphere3_transparency, sphere3_ref_index, 3);


	back_clr_Global.r = 0.0;
	back_clr_Global.g = 0.0;
	back_clr_Global.b = 0.0;
	
	decay_a = 0.1;
	decay_b = 0.1;
	decay_c = 0.0;

}

void scene_4(){

	
	main_c_board__.middle = { 0.0, 2.0, -6.0 };
	main_c_board__.direction = { 0.0, 0.0, 1.0 };
	main_c_board__.lambai = 30.0;
	main_c_board__.x_MAX__ = main_c_board__.middle.x + (main_c_board__.lambai / 2.0);
	main_c_board__.X_MIN__ = main_c_board__.middle.x - (main_c_board__.lambai / 2.0);
	main_c_board__.Z_MAX__ = main_c_board__.middle.z + (main_c_board__.lambai / 2.0);
	main_c_board__.Z_MIN__ = main_c_board__.middle.z - (main_c_board__.lambai / 2.0);
	main_c_board__.batwara = 40;


	main_c_board__.black_part__.SPHERE_amb[0] = 0.0;
	main_c_board__.black_part__.SPHERE_amb[1] = 0.0;
	main_c_board__.black_part__.SPHERE_amb[2] = 0.0;
	main_c_board__.black_part__.SPHERE_diff[0] = 0.0;
	main_c_board__.black_part__.SPHERE_diff[1] = 0.0;
	main_c_board__.black_part__.SPHERE_diff[2] = 0.0;
	main_c_board__.black_part__.SPHERE_spec[0] = 0;
	main_c_board__.black_part__.SPHERE_spec[1] = 0;
	main_c_board__.black_part__.SPHERE_spec[2] = 0;
	main_c_board__.black_part__.SPHERE_shine = 50;
	main_c_board__.black_part__.SPHERE_reflect = 0.5;
	main_c_board__.black_part__.SPHERE_transp = 0.0;
	main_c_board__.black_part__.SPHERE_ref_ind = 0.0;

	main_c_board__.white_part__.SPHERE_amb[0] = 0.0;
	main_c_board__.white_part__.SPHERE_amb[1] = 0.0;
	main_c_board__.white_part__.SPHERE_amb[2] = 0.0;
	main_c_board__.white_part__.SPHERE_diff[0] = 1.0;
	main_c_board__.white_part__.SPHERE_diff[1] = 1.0;
	main_c_board__.white_part__.SPHERE_diff[2] = 1.0;
	main_c_board__.white_part__.SPHERE_spec[0] = 1.0;
	main_c_board__.white_part__.SPHERE_spec[1] = 1.0;
	main_c_board__.white_part__.SPHERE_spec[2] = 1.0;
	main_c_board__.white_part__.SPHERE_shine = 50;
	main_c_board__.white_part__.SPHERE_reflect = 0.5;
	main_c_board__.white_part__.SPHERE_transp = 0.0;
	main_c_board__.white_part__.SPHERE_ref_ind = 0.0;

	gloabal_lighting_amb[0] = 0.2;
	gloabal_lighting_amb[1] = 0.2;
	gloabal_lighting_amb[2] = 0.2;


	light_id_1.x =2;
	light_id_1.y = -9.0;
	light_id_1.z = 1.0;
	light_id_1_amb[0] = 0.1;
	light_id_1_amb[1] = 0.1;
	light_id_1_amb[2] = 0.1;
	light_id_1_diff[0] = 1;
	light_id_1_diff[1] = 1;
	light_id_1_diff[2] = 1;
	light_id_1_spec[0] = 1;
	light_id_1_spec[1] = 1;
	light_id_1_spec[2] = 1;



	// sphere 1
	coord sphere1_ctr = { 1.6, -0.2, -3.2 };
	float sphere1_rad = 1.1;
	float sphere1_ambient[] = { 0.7, 0.7, 0.7 };
	float sphere1_diffuse[] = { 0.1, 0.5, 0.8 };
	float sphere1_specular[] = { 1.0, 1.0, 1.0 };
	float sphere1_shineness = 6;
	float sphere1_reflectance = 0.5;
	float sphere1_transparency = 10.0;
	float sphere1_ref_index = 1.0;
	spheres_in_img = another_one_sphere(spheres_in_img, sphere1_ctr, sphere1_rad, sphere1_ambient,
		sphere1_diffuse, sphere1_specular, sphere1_shineness,
		sphere1_reflectance, sphere1_transparency, sphere1_ref_index, 1);

	// sphere 2
	coord sphere2_ctr = { -1.6, 0.0, -3.5 };
	float sphere2_rad = 1.23;
	float sphere2_ambient[] = { 0.6, 0.6, 0.6 };
	float sphere2_diffuse[] = { 1.0, 0.0, 0.25 };
	float sphere2_specular[] = { 1.0, 1.0, 1.0 };
	float sphere2_shineness = 6;
	float sphere2_reflectance = 0.5;
	float sphere2_transparency = 5.0;
	float sphere2_ref_index = 1.5;
	spheres_in_img = another_one_sphere(spheres_in_img, sphere2_ctr, sphere2_rad, sphere2_ambient,
		sphere2_diffuse, sphere2_specular, sphere2_shineness,
		sphere2_reflectance, sphere2_transparency, sphere2_ref_index, 2);

	// sphere 3
	coord sphere3_ctr = { 0.1, 0.8, -1.6 };
	float sphere3_rad = 0.4;
	float sphere3_ambient[] = { 1.2, 1.2, 0.2 };
	float sphere3_diffuse[] = { 0.0, 1.0, 0.25 };
	float sphere3_specular[] = { 0.0, 1.0, 1.0 };
	float sphere3_shineness = 30;
	float sphere3_reflectance = 0.5;
	float sphere3_transparency = 0.0;
	float sphere3_ref_index = 1.0;
	spheres_in_img = another_one_sphere(spheres_in_img, sphere3_ctr, sphere3_rad, sphere3_ambient,
		sphere3_diffuse, sphere3_specular, sphere3_shineness,
		sphere3_reflectance, sphere3_transparency, sphere3_ref_index, 3);


	back_clr_Global.r = 0.1;
	back_clr_Global.g = 0.1;
	back_clr_Global.b = 0.1;
	decay_a = 0.1;
	decay_b = 0.0;
	decay_c = 0.0;
}