#ifdef __APPLE__
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <GLUT/glut.h>
# include <iostream>
#else
# include <GL/gl.h>
# include <GL/glu.h>
# include <GL/glut.h>
# include <iostream>
#endif

using namespace std;

void reshape_cb (int w, int h)
{
	if (w==0||h==0) return;
	glViewport(0,0,w,h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D(0,w,0,h);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
}

void display_cb() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

void initialize() 
{
	glutInitDisplayMode (GLUT_RGBA|GLUT_DOUBLE);
	glutInitWindowSize (800,600);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("TABLERO DE AJEDREZ");
	glutDisplayFunc (display_cb);
	glutReshapeFunc (reshape_cb);
	glClearColor(0.f,1.f,1.f,1.f);
}

int main (int argc, char **argv) 
{
	glutInit (&argc, argv);
	initialize();
	glutMainLoop();
	
	return 0;
}
