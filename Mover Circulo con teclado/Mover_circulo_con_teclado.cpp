#include <iostream>
#include <cmath>
#include <GL/glut.h>

using namespace std;
//Variables globales
float _x = 0.0f, _y = 0.0f; //Variables para la posicion del circulo 
float _radio = 0.1f; //Radio del circulo
	
//Funcion para el dibujo
void Display()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f); //Color del circulo
	
	//Dibujar el circulo
	glBegin(GL_POLYGON);
	for(int i = 0; i < 360; i++)
	{
		float _angulo = i * 3.14159f / 180.0f;
		glVertex2f(_x + _radio * cos(_angulo), _y + _radio * sin(_angulo));
	}
	glEnd();
	glFlush();
}

//Funcion para el teclado
void Move(int _key, int x, int y)
{
	switch(_key)
	{
		case GLUT_KEY_LEFT:
		    cout << "se mueve a la izquerda" << endl;
		_x -= 0.1f;
		break;
		case GLUT_KEY_RIGHT:
			cout << "se mueve a la derecha" << endl;
		_x += 0.1f;
		break;
		case GLUT_KEY_UP:
			cout << "se mueve hacia arriba" << endl;
		_y += 0.1f;
		break;
		case GLUT_KEY_DOWN:
			cout << "se mueve hacia abajo" << endl;
		_y -= 5.f;
		break;
	}
	glutPostRedisplay();	
}

int main(int argc, char *argv[]) 
{
	//INICIALIZACIONES Y LLAMADAS A FUNCIONES
	glutInit(&argc, argv); //Inicializamos GLUT;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Modo de visualizacion
	glutInitWindowSize(800, 600); //Creamos tamaño de ventana
	glutCreateWindow("Circulo movil"); //Creamos la ventana
	glutDisplayFunc(Display); //Llamamos a la funcion Display
	glutSpecialFunc(Move); //Llamamos a la funcion para mover el circulo 
	glutMainLoop(); //Loop
	
	return 0;
}

