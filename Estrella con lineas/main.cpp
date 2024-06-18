#ifdef __APPLE__
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <GLUT/glut.h>
#include <iostream>
#include <cmath>
#else
# include <GL/gl.h>
# include <GL/glu.h>
# include <GL/glut.h>
#include <iostream>
#include <cmath>
#endif

void Reshape_cb (int w, int h) 
{
	if (w==0||h==0) return;
	glViewport(0,0,w,h);
	
	// Establece la proyección ortográfica
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D(0,w,0,h);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
}

void Display_cb() 
{
	// Limpia el buffer de color
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f,0.0f,0.0f); 
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
		for(int i = 0; i <= 360; i += 72)
		{
			glVertex2f(0.5 * cos(i * 3.14 / 180), 0.5 * sin(i * 3.14 / 180));
			glVertex2f(0.0, 0.0);
			glVertex2f(0.5 * cos((i + 36) * 3.14 / 180), 
				0.5 * sin((i + 36) * 3.14 / 180));
		}
	glEnd();
	// Intercambia los buffers (doble buffer)
	glutSwapBuffers();
}

void Initialize() 
{
	// Establece el modo de visualización
	glutInitDisplayMode (GLUT_RGBA|GLUT_DOUBLE);
	// Establece el tamaño de la ventana
	glutInitWindowSize (800,600);
	// Establece la posición inicial de la ventana
	glutInitWindowPosition (50,50);
	// Crea la ventana
	glutCreateWindow ("Estrella con lineas");
	// Establece la función de dibujo
	glutDisplayFunc (Display_cb);
	// Establece la función de redimensionamiento
	glutReshapeFunc (Reshape_cb);
	// Establecer el color de fondo
	glClearColor(0.5f,0.5f,0.5f,1.f);
}

int main (int argc, char **argv) 
{
	// Inicializa GLUT
	glutInit (&argc, argv);
	// Llama a la función de inicialización
	Initialize();
	// Entra en el bucle principal de GLUT
	glutMainLoop();
	
	return 0;
}
