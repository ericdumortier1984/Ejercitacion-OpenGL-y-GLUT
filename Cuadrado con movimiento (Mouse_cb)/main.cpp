#ifdef __APPLE__ // Verifica si el sistema operativo es macOS
# include <OpenGL/gl.h> // Incluye las bibliotecas OpenGL y GLUT para macOS
# include <OpenGL/glu.h>
# include <GLUT/glut.h>
#include <stdlib.h>
#include <iostream>
#else // Si no es macOS
# include <GL/gl.h> // Incluye las bibliotecas OpenGL y GLUT para otros sistemas operativos
# include <GL/glu.h>
# include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#endif

static GLfloat girarCuadrado = 0.0; // Variable global que almacena el �ngulo de rotaci�n del cuadrado
static GLfloat velocidadRotacion = 2.0; // Variable global que define la velocidad de rotaci�n

void reshape_cb (int w, int h) // Funci�n de callback para el redimensionamiento de la ventana
{
	if (w==0||h==0) return; // Si la ventana tiene un ancho o alto de 0, no hace nada
	glViewport(0,0,w,h); // Establece el viewport a todo el tama�o de la ventana
	glMatrixMode (GL_PROJECTION); // Entra en el modo de proyecci�n
	glLoadIdentity (); // Carga la matriz de identidad
	gluOrtho2D(-w/2, w/2, -h/2, h/2); // Establece una proyecci�n ortogr�fica 2D
	glMatrixMode (GL_MODELVIEW); // Entra en el modo de vista de modelo
	glLoadIdentity (); // Carga la matriz de identidad
}

void display_cb() // Funci�n de callback para el dibujo de la escena
{
	glClear(GL_COLOR_BUFFER_BIT); // Limpia el buffer de color
	glShadeModel(GL_FLAT); // Establece el modelo de sombreado a plano
	glPushMatrix(); // Guarda la matriz de modelado actual
	glRotatef(girarCuadrado, 0.0, 0.0, 1.0); // Rota el cuadrado seg�n el �ngulo almacenado en girarCuadrado
	glTranslatef(0.0, 0.0, 0.0); // Centra el cuadrado
	glColor3f(1.3, 0.5, 1.0); // Establece el color del cuadrado
	glRectf(-50.0, -50.0, 50.0, 50.0); // Dibuja el cuadrado
	glPopMatrix(); // Restaura la matriz de modelado anterior
	glutSwapBuffers(); // Intercambia los buffers de color para mostrar la imagen
}

void rotarCuadrado() // Funci�n que actualiza el �ngulo de rotaci�n del cuadrado
{
	girarCuadrado += velocidadRotacion; // Incrementa el �ngulo de rotaci�n
	if(girarCuadrado > 360.0) // Si el �ngulo supera los 360 grados
	{
		girarCuadrado = girarCuadrado - 360.0; // Lo resetea a un valor entre 0 y 360 grados
	}
	glutPostRedisplay(); // Solicita que se vuelva a dibujar la escena
}

void mouse(int botonMouse, int estadoMouse, int x, int y) // Funci�n de callback para eventos de rat�n
{
	switch(botonMouse) // Verifica qu� bot�n del rat�n se presion�
	{
	case GLUT_LEFT_BUTTON: // Si se presion� el bot�n izquierdo
		if (estadoMouse == GLUT_DOWN) // Y se solt� el bot�n
			glutIdleFunc(rotarCuadrado); // Activa la funci�n rotarCuadrado para que el cuadrado comience a girar
		break;
    case GLUT_MIDDLE_BUTTON: // Si se presion� el bot�n central
        if (estadoMouse == GLUT_DOWN) // Y se solt� el bot�n
	        glutIdleFunc(NULL); // Detiene la rotaci�n del cuadrado
		break;
	default:
		break;
	}
}

void initialize() // Funci�n que inicializa el entorno OpenGL
{
	glutInitDisplayMode (GLUT_RGBA|GLUT_DOUBLE); // Establece el modo de visualizaci�n, en este caso RGBA y doble buffer
	glutInitWindowSize (640,480); // Establece el tama�o de la ventana
	glutInitWindowPosition (100,100); // Establece la posici�n de la ventana
	glutCreateWindow ("Cuadrado con movimiento"); // Crea la ventana
	glutDisplayFunc (display_cb); // Asigna la funci�n de callback para el dibujo
	glutReshapeFunc (reshape_cb); // Asigna la funci�n de callback para el redimensionamiento
	glutMouseFunc (mouse); // Asigna la funci�n de callback para eventos de rat�n
	glClearColor(0.4f,0.4f,0.4f,0.4f); // Establece el color de fondo
}

int main (int argc, char **argv) // Funci�n principal
{
	glutInit (&argc, argv); // Inicializa GLUT
	initialize(); // Llama a la funci�n initialize para configurar el entorno
	glutMainLoop(); // Entra en el bucle principal de GLUT
	
	return 0;
}
