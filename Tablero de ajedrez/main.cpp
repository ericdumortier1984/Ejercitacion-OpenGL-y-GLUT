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

// Tamaño del tablero de ajedrez
const int BOARD_SIZE = 400;
// Tamaño de cada cuadrado del tablero
const int SQUARE_SIZE = BOARD_SIZE / 8;

void DrawChessboard()
{
	
	// Comenzar a dibujar
	glBegin(GL_QUADS);
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
		if((i + j)%2 == 0)
		{
			glColor3f(1.0f, 1.0f, 1.0f); // Color blanco
		}else
		{
			glColor3f(0.f, 0.f, 0.f); // Color negro
		}
		// Dibuja cada cuadrado
		glVertex2f(i * SQUARE_SIZE, j * SQUARE_SIZE);
		glVertex2f((i+1) * SQUARE_SIZE, j * SQUARE_SIZE);
		glVertex2f((i+1) * SQUARE_SIZE, (j+1) * SQUARE_SIZE);
		glVertex2f(i * SQUARE_SIZE, (j+1) * SQUARE_SIZE);
	    }
	}
	// Termina de dibujar los cuadrados
	glEnd();
}

// Función que se llama cuando cambia el tamaño de la ventana
void reshape_cb (int w, int h)
{
	
	if (w==0||h==0) return;
	// Calcula las coordenadas del centro de la ventana
	int centerX = w / 2;
	int centerY = h / 2;
	
	// Ajusta el viewport para centrar el tablero
	int viewportSize = (w < h) ? w : h; // Toma el mínimo entre el ancho y el alto
	glViewport(centerX - BOARD_SIZE/2, centerY - BOARD_SIZE/2, BOARD_SIZE, BOARD_SIZE);
	
	// Establece la proyección ortográfica
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D(0, BOARD_SIZE, 0, BOARD_SIZE);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
}

// Función que se llama para dibujar
void display_cb() 
{
	
	// Limpia el buffer de color
	glClear(GL_COLOR_BUFFER_BIT);
	// Dibuja el tablero
	DrawChessboard();
	// Intercambia los buffers (doble buffer)
	glutSwapBuffers();
}

void initialize() 
{
	
	// Establece el modo de visualización
	glutInitDisplayMode (GLUT_RGBA|GLUT_DOUBLE);
	// Establece el tamaño de la ventana
	glutInitWindowSize (800,600);
	// Establece la posición inicial de la ventana
	glutInitWindowPosition (50,50);
	// Crea la ventana
	glutCreateWindow ("TABLERO DE AJEDREZ");
	// Establece la función de dibujo
	glutDisplayFunc (display_cb);
	// Establece la función de redimensionamiento
	glutReshapeFunc (reshape_cb);
	// Establecer el color de fondo
	glClearColor(0.f,1.f,1.f,1.f);
}

int main (int argc, char **argv) 
{
	
	// Inicializa GLUT
	glutInit (&argc, argv);
	// Llama a la función de inicialización
	initialize();
	// Entra en el bucle principal de GLUT
	glutMainLoop();
	
	return 0;
}
