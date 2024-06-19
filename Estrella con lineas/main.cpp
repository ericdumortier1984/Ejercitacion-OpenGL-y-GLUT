#ifdef __APPLE__
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <GLUT/glut.h>
#include <iostream>
#else
# include <GL/gl.h>
# include <GL/glu.h>
# include <GL/glut.h>
#include <iostream>
#endif

using namespace std;

// Seguimiento del cursor para ver donde hacemos los vertices
void PassiveMotion_cb(int x, int y)
{
	cout << x << "," << y << " \r" << flush;
}

void DrawStar()
{
	// Estrella en modo wireframe
	glColor3f(1.5f,0.5f,0.f); // Color
	glLineWidth(5); // Ancho
	
	glBegin(GL_LINE_STRIP); // Lineas que se cruzan
	glVertex2i(180,100); // Diagonal izquierda a derecha
	glVertex2i(100,200); // Diagonal izquierda a derecha (une)
	glVertex2i(200,200); // Diagonal derecha a izquierda
	glVertex2i(100,100); // Diagonal derecha a izquierda (une)
	glVertex2i(150,250); // Diagonal central
	glVertex2i(180,100); // Diagonal cenral (une)
	
	glEnd();
}

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
	// Dibuja la estrella
	DrawStar();
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
	glutInitWindowPosition (100,100);
	// Crea la ventana
	glutCreateWindow ("Estrella con lineas");
	// Lamada a función para seguir la posición del mouse
	glutPassiveMotionFunc(PassiveMotion_cb);
	// Establece la función de dibujo
	glutDisplayFunc (Display_cb);
	// Establece la función de redimensionamiento
	glutReshapeFunc (Reshape_cb);
	// Establecer el color de fondo
	glClearColor(0.5f,0.5f,0.5f,0.5f);
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
