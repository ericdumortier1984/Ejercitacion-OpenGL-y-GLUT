#ifdef __APPLE__
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <GLUT/glut.h>
#include <stdlib.h>
#include <iostream>
#else
# include <GL/gl.h>
# include <GL/glu.h>
# include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#endif

static GLfloat girarCuadrado = 0.0;
static GLfloat velocidadRotacion = 2.0; // Velocidad de rotación

void reshape_cb (int w, int h) 
{
	if (w==0||h==0) return;
	glViewport(0,0,w,h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D(-w/2, w/2, -h/2, h/2);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
}

void display_cb() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_FLAT);
	glPushMatrix();
	glRotatef(girarCuadrado, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0); // Centrar el cuadrado
	glColor3f(1.6, 1.6, 1.6);
	glRectf(-50.0, -50.0, 50.0, 50.0);
	glPopMatrix();
	glutSwapBuffers();
}

void rotarCuadrado()
{
	girarCuadrado += velocidadRotacion;
	if(girarCuadrado > 360.0)
	{
		girarCuadrado = girarCuadrado - 360.0;
	}
	glutPostRedisplay();
}

void mouse(int botonMouse, int estadoMouse, int x, int y)
{
	switch(botonMouse)
	{
	case GLUT_LEFT_BUTTON:
		if (estadoMouse == GLUT_DOWN)
			glutIdleFunc(rotarCuadrado);
		break;
    case GLUT_MIDDLE_BUTTON:
        if (estadoMouse == GLUT_DOWN)
	        glutIdleFunc(NULL);
		break;
	default:
		break;
	}
}

void initialize()
{
	glutInitDisplayMode (GLUT_RGBA|GLUT_DOUBLE);
	glutInitWindowSize (640,480);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Cuadrado con movimiento");
	glutDisplayFunc (display_cb);
	glutReshapeFunc (reshape_cb);
	glutMouseFunc (mouse);
	glClearColor(0.4f,0.4f,0.4f,0.4f);
}

int main (int argc, char **argv) 
{
	glutInit (&argc, argv);
	initialize();
	glutMainLoop();
	
	return 0;
}
