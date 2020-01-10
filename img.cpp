#include <stdio.h>
#include <GL/glut.h>
#include <string.h>

#include "my_defined_scenes.h"

// Global variables
extern int fnal_window_width__;
extern int final_window_height;

extern GLfloat IMAGE_final_global[WIN_HEIGHT][WIN_WIDTH][3]; 


void save_image() {
	int w = fnal_window_width__;
	int h = final_window_height;

	unsigned char * bImg = new unsigned char[w * h * 3];

	int start = 0;
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++) {

		float r = IMAGE_final_global[y][x][0]; 
		float g = IMAGE_final_global[y][x][1]; 
		float b = IMAGE_final_global[y][x][2];

		bImg[start] = (b > 1.f) ? 255 : (unsigned char)(b*255); start++;
		bImg[start] = (g > 1.f) ? 255 : (unsigned char)(g*255); start++;
		bImg[start] = (r > 1.f) ? 255 : (unsigned char)(r*255); start++;
		}
	}

	unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
	unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
	unsigned char bmppad[3] = {0,0,0};

	int filesize = 54 + 3*w*h;

	bmpfileheader[ 2] = (unsigned char)(filesize    );
	bmpfileheader[ 3] = (unsigned char)(filesize>> 8);
	bmpfileheader[ 4] = (unsigned char)(filesize>>16);
	bmpfileheader[ 5] = (unsigned char)(filesize>>24);

	bmpinfoheader[ 4] = (unsigned char)(       w    );
	bmpinfoheader[ 5] = (unsigned char)(       w>> 8);
	bmpinfoheader[ 6] = (unsigned char)(       w>>16);
	bmpinfoheader[ 7] = (unsigned char)(       w>>24);
	bmpinfoheader[ 8] = (unsigned char)(       h    );
	bmpinfoheader[ 9] = (unsigned char)(       h>> 8);
	bmpinfoheader[10] = (unsigned char)(       h>>16);
	bmpinfoheader[11] = (unsigned char)(       h>>24);


	FILE *fp;
	char fname[32];

	strcpy(fname, "scene.bmp");
	printf("Saving image %s: %d x %d\n", fname, w, h);
	fp = fopen(fname, "wb");
	if (!fp) {
	printf("Unable to open file '%s'\n",fname);
	return;
	}


	fwrite(bmpfileheader,1,14,fp);
	fwrite(bmpinfoheader,1,40,fp);

	for(int y = h-1; y >= 0; y--)
	{
		int offset = w * (h - 1 - y) * 3;
		fwrite(bImg + offset, 3, w, fp);
		fwrite(bmppad,1,(4-(w*3)%4)%4,fp);
	}

 
	fclose(fp);
}


void norm() {
  GLfloat max_val = 0.0;
  int i, j;

  for (i=0; i<final_window_height; i++) 
    for (j=0; j<fnal_window_width__; j++) {
      if (IMAGE_final_global[i][j][0] > max_val) max_val = IMAGE_final_global[i][j][0];
      if (IMAGE_final_global[i][j][1] > max_val) max_val = IMAGE_final_global[i][j][1];
      if (IMAGE_final_global[i][j][2] > max_val) max_val = IMAGE_final_global[i][j][2];
    }

  for (i=0; i<final_window_height; i++) 
    for (j=0; j<fnal_window_width__; j++) {
      IMAGE_final_global[i][j][0] /= max_val;
      IMAGE_final_global[i][j][1] /= max_val;
      IMAGE_final_global[i][j][2] /= max_val;
    }
}
