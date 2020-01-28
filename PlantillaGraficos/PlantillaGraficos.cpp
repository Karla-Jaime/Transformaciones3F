// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h> 
#include <stdlib.h> 
#define GLEW_STATIC 
 
#include"GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream> 

using namespace std;


float angulo = 0.0f;

void actualizar() {
	angulo += 0.01;
	if (angulo >= 360.0f) {
		angulo = 0.0f;
	}
}

void dibujarTriangulo(){
	glPushMatrix();
	//Se colocan antes de glBegin
	
	//glTranslatef(0.4f,-0.5f,0.0f);
	glRotatef(angulo,0.0f,1.0f,0.0);
	//glScalef(5.0f,2.0f,1.0f);

	glBegin(GL_TRIANGLES);
	glColor3f(0.75f,0.71f,0.22f);

	glVertex3f(0.0f, 0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);

	glEnd();
	glPopMatrix();
	////////////////////////////
	glPushMatrix();
	//Se colocan antes de glBegin

	glTranslatef(0.15f,-0.30f,0.0f);
	glRotatef(angulo,0.0f,1.0f,0.0);
	//glScalef(5.0f,2.0f,1.0f);

	glBegin(GL_TRIANGLES);
	glColor3f(0.75f, 0.71f, 0.22f);

	glVertex3f(0.0f, 0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);

	glEnd();
	glPopMatrix();
	/////////////////////////////
	glPushMatrix();
	//Se colocan antes de glBegin

	glTranslatef(-0.15f, -0.3f, 0.0f);
	glRotatef(angulo,0.0f,1.0f,0.0);
	//glScalef(5.0f,2.0f,1.0f);

	glBegin(GL_TRIANGLES);
	glColor3f(0.75f, 0.71f, 0.22f);

	glVertex3f(0.0f, 0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);

	glEnd();
	glPopMatrix();
}

void dibujar() {
	dibujarTriangulo();
}


//$(ProjectDir)include 
int main()
{
	//Declarar una ventana 
	GLFWwindow* window;


	//Si no se pudo inicializar GLFW  //Terminamos Ejecución 
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	window = glfwCreateWindow(600, 600, "Ventana Cookie", NULL, NULL);
	
	//Si no se pudo crear la ventana
	//Terminamos ejecución
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Si se pudo inicializar GLFW
	//Inicializams la ventana


	//Establecemos la ventana como contexto
	glfwMakeContextCurrent(window);
	//UsarFuncionesdeOpengl
	//Una vez establecido el contexto. Se activan las funciones "modernas" (gpu)
	glewExperimental = true;
	
	GLenum errores = glewInit();
	if (errores != GLEW_OK) {
		glewGetErrorString(errores);
	}

	const GLubyte  *versionGL = glGetString(GL_VERSION);

	cout << "Version OpenGl: " << versionGL;

	//Clilo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {

		//Establecer región de dibujo 
		glViewport(0, 0, 600, 600);
		//Establecemos el color de borrado
		glClearColor(0.19, 0.44, 0.2, 1);
		//Borrar
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Actualizar los valores y dibujar 
		actualizar(); 
		dibujar();
		
		//Se comunica con los dispositivos de entrada
		glfwPollEvents();		
		glfwSwapBuffers(window);
	}
	//Despues del ciclo de dibujo Eliminamos ventana y procesos de glfw
	glfwDestroyWindow(window);
	glfwTerminate();
}