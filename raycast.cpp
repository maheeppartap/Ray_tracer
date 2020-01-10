
#include "include/Angel.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trace.h"

#include "my_defined_scenes.h"
#include "drawables.h"
#include "img.h"
#include "scene.h"


int fnal_window_width__ = WIN_WIDTH;
int final_window_height = WIN_HEIGHT;

GLfloat IMAGE_final_global[WIN_HEIGHT][WIN_WIDTH][3];


float pic_width__global = IMAGE_WIDTH;
float pic_img_height__gloabl = (float(WIN_HEIGHT) / float(WIN_WIDTH)) * IMAGE_WIDTH;


colour_type back_clr_Global;

coord user_position = { 0.0, 0.0, 0.0 };
float img_plane_GLOBAL = -1.5;

list_of_spheres* spheres_in_img = NULL;
chess_board main_c_board__;


coord light_id_1;
float light_id_1_amb[3];
float light_id_1_diff[3];
float light_id_1_spec[3];


float gloabal_lighting_amb[3];


float decay_a;
float decay_b;
float decay_c;


int step_max = 1;


bool shadow_on = false;
bool reflection_on = false;
bool refraction_on = false;
bool chess_pattern_on = true;
bool diffuse_rend_on = true;
bool super_samp_on = true;

const int total_num_points = 6;

void init()
{

	double modera__ = 1.0;

	vec4 int_points[total_num_points] = {
		vec4(-modera__, -modera__,  0, 1.0),
		vec4(modera__, -modera__,  0, 1.0),
		vec4(-modera__,  modera__,  0, 1.0),
		vec4(-modera__,  modera__,  0, 1.0),
		vec4(modera__, -modera__,  0, 1.0),
		vec4(modera__,  modera__,  0, 1.0)
	};

	vec2 mapping_coord__[total_num_points] = {
		vec2(0.0, 0.0),
		vec2(1.0, 0.0),
		vec2(0.0, 1.0),
		vec2(0.0, 1.0),
		vec2(1.0, 0.0),
		vec2(1.0, 1.0)
	};


	GLuint texture;
	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, WIN_WIDTH, WIN_HEIGHT, 0,
		GL_RGB, GL_FLOAT, IMAGE_final_global);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glActiveTexture(GL_TEXTURE0);


	GLuint buffer_img;
	glGenBuffers(1, &buffer_img);
	glBindBuffer(GL_ARRAY_BUFFER, buffer_img);
	glBufferData(GL_ARRAY_BUFFER, sizeof(int_points) + sizeof(mapping_coord__), NULL, GL_STATIC_DRAW);
	GLintptr off_ = 0;
	glBufferSubData(GL_ARRAY_BUFFER, off_, sizeof(int_points), int_points);
	off_ += sizeof(int_points);
	glBufferSubData(GL_ARRAY_BUFFER, off_, sizeof(mapping_coord__), mapping_coord__);
	GLuint my_img = InitShader("vshader.glsl", "fshader.glsl");
	glUseProgram(my_img);
	off_ = 0;
	GLuint vPosition = glGetAttribLocation(my_img, "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(off_));
	off_ += sizeof(int_points);
	GLuint vTexCoord = glGetAttribLocation(my_img, "vTexCoord");
	glEnableVertexAttribArray(vTexCoord);
	glVertexAttribPointer(vTexCoord, 2, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(off_));

	glUniform1i(glGetUniformLocation(my_img, "texture"), 0);

	glClearColor(1.0, 1.0, 1.0, 1.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_CULL_FACE);

	glDrawArrays(GL_TRIANGLES, 0, total_num_points);

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'q':case 'Q':
		free(spheres_in_img);
		exit(0);
		break;
	case 's':case 'S':
		save_image();
		glutPostRedisplay();
		break;
	default:
		break;
	}
}


int main(int argc, char** argv)
{
	if (strcmp(argv[1], "1") == 0) {
		shadow_on = 0;
		reflection_on = 0;
		refraction_on = 0;
		
		scene_1();
	}else

		if (strcmp(argv[1], "2") == 0) {
			shadow_on = true;
			reflection_on = true;
			scene_2();
		}else

	if (strcmp(argv[1], "3") == 0) {  
		shadow_on = true;
		reflection_on = true;
		refraction_on = true;
		scene_3();
	}
	else { 
		shadow_on = true;
		reflection_on = true;
		refraction_on = false;
		scene_4();
	}

	step_max = 4;
	run();
	norm();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutCreateWindow("Maheep's tracer");
	glewInit();
	init();

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
