Ray tracer
	made for CMPT 361 fall 2019, SFU.

Made by: Maheeppartap Singh
S number: 301367679

implemented: 
	*3 spheres
	*plane
	*chess board
	*lighting
	*light attenuation (not efficent, but very works perfectly)
	*shadows
	*reflections
	*refractions
	*supersampling

Description:
	This ray tracer has 3 spheres ( red green and blue )  and a plane in each scene. I have made all the planes to look like shiny chess boards(because they make it look better) except for the last scene.That scene has a different pattern.

**Scene 1 does not look very pretty because i turned off everything except specular lighting because that was the requirement of that scene**
**Scene 2 has everything enabled, so will take time to run. It has shadows and refelctions bot running, as well as supersampling enabled.**
**Scene 3 will look dark, due to light attenuation. there is a plane at the bottom and refraction works perfectly with index = 1.5.**
**Scene 4 is just evrything put together**

The images are bmp format and are NOT 400x400. But the code will run with the 400x400 window as stated in the requirements.


To run:
	write "make"
	"./rayT <scene number>" without the <>. 4 scenes are implemented. so scene number should be 1,2,3,4 only.


disclaimer:
I used a number of online tutorials from the internet. The code which saves the picture is NOT made by me, I found it on stack overflow. Implementing that did not appear important as we are not concerned with how an image is saved. Also I am using a math library in this code. The initshader file was partially written by me to suite to this project and i reused certain code from assignment 2. 	
