Ray tracer
	

Made by: Maheeppartap Singh


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

The code will run with the 400x400 window. Feel free to change it :)


To run:
	write "make"
	"./rayT <scene number>" without the <>. 4 scenes are implemented. so scene number should be 1,2,3,4 only.
