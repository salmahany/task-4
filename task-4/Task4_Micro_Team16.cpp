#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
#include "SerialPort.h"
#include <stdio.h>
#include <string.h>

using namespace std;


using std::cout;
using std::endl;

static int wrist_Angle = 0, elbow_Angle = 0, finger_Angle = 0;
char* port_Name = "\\\\.\\COM6";

#define MAX_DATA_LENGTH 255

char recievedData[MAX_DATA_LENGTH];

//Arduino SerialPort object
//SerialPort *arduino;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}



void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	// SHOULDER
	glPushMatrix();
	glScalef(2, 0.4, .4);
	glutWireCube(1.0);
	glPopMatrix();
	//ELBOW 
	//JOINT

	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)elbow_Angle, 0.0, 0.0, 1.0);
	glTranslatef(-1.0, 0.0, 0.0);
	glTranslatef(1.2, 0.0, 0.0);
	glPushMatrix();
	glScalef(.4, 0.4, .4);
	glutWireSphere(.4, 20, 20);
	glPopMatrix();
	//part 2
	glTranslatef(.8, 0.0, 0.0);

	glPushMatrix();
	glScalef(1.2, 0.4, .4);
	glutWireCube(1.0);
	glPopMatrix();
	//WRIST 
	//JOINT
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)wrist_Angle, 0.0, 0.0, 1.0);
	glTranslatef(-1.0, 0.0, 0.0);
	glTranslatef(.8, 0.0, 0.0);
	glPushMatrix();
	glScalef(.4, 0.4, .4);
	glutWireSphere(.4, 20, 20);
	glPopMatrix();
	//PART2
	glTranslatef(.4, 0, 0);
	glPushMatrix();
	glScalef(.5, 0.4, .4);
	glutWireCube(1.0);
	glPopMatrix();
	//F1
	//part 1

	glTranslatef(.4, 0.15, 0.0);
	glPushMatrix();
	glScalef(.25, 0.1, .1);
	glutWireCube(1.0);
	glPopMatrix();
	//joint
	glTranslatef(.1, 0, 0);
	glRotatef((GLfloat)-f, 0.0, 0.0, 1.0);
	glTranslatef(-.1, 0, 0);
	glTranslatef(.2, -.005, 0);
	glPushMatrix();
	glScalef(.4, 0.4, .4);
	glutWireSphere(.1, 20, 20);
	glPopMatrix();
	//3


	glTranslatef(.2, -0.005, 0.0);
	glPushMatrix();
	glScalef(.25, 0.1, .1);
	glutWireCube(1.0);
	glPopMatrix();
	//F2
	//1

	glTranslatef(-.4, -.005, -.15);
	glPushMatrix();
	glScalef(.25, 0.1, .1);
	glutWireCube(1.0);
	glPopMatrix();
	//2
	glTranslatef(.1, 0.0, 0.0);
	glTranslatef(.1, 0.0, 0.0);

	glTranslatef(-.1, 0.0, 0.0);
	glTranslatef(.1, -.005, 0);
	glPushMatrix();
	glScalef(.4, 0.4, .4);
	glutWireSphere(.1, 20, 20);
	glPopMatrix();
	//3
	glTranslatef(.1, 0.0, 0.0);
	glTranslatef(.1, -0.005, 0.0);
	glPushMatrix();
	glScalef(.25, 0.1, .1);
	glutWireCube(1.0);
	glPopMatrix();
	//F3
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(0, 0.0, 0.0, 1.0);
	glTranslatef(-1.4, -.005, 0.25);
	glPushMatrix();
	glScalef(.25, 0.1, .1);
	glutWireCube(1.0);
	glPopMatrix();
	//2

	glTranslatef(.1, 0.0, 0.0);

	glTranslatef(.1, -.005, 0);
	glPushMatrix();
	glScalef(.4, 0.4, .4);
	glutWireSphere(.1, 20, 20);
	glPopMatrix();
	//3

	glTranslatef(.1, 0.0, 0.0);
	glTranslatef(.1, -0.005, 0.0);
	glPushMatrix();
	glScalef(.25, 0.1, .1);
	glutWireCube(1.0);
	glPopMatrix();

	//F4
	//part 1
	/*glTranslatef(-.4, -.15, -.4);
	glRotatef((GLfloat)-f, 0.0, 0.0, 1.0);
	glTranslatef(.4, 0.15, .4);*/
	glTranslatef(-.4, -.25, 0);
	glPushMatrix();
	glScalef(.25, 0.1, .1);

	glutWireCube(1.0);
	glPopMatrix();
	//2

	glTranslatef(.1, 0.0, 0.0);

	glTranslatef(.1, -.005, 0);
	glPushMatrix();
	glScalef(.4, 0.4, .4);
	glutWireSphere(.1, 20, 20);
	glPopMatrix();
	//3


	glTranslatef(.2, -0.005, 0.0);
	glPushMatrix();
	glScalef(.25, 0.1, .1);
	glutWireCube(1.0);
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case '2':
		wrist_Angle = (wrist_Angle + 5);
		if (wrist_Angle >= 50)
		{
			wrist_Angle = 50;
		};
		glutPostRedisplay();
		break;
	case '@':
		wrist_Angle = (wrist_Angle - 5);
		if (wrist_Angle <= -50)
		{
			wrist_Angle = -50;
		};
		glutPostRedisplay();
		break;
	case '1':

		elbow_Angle = (elbow_Angle + 5);
		glutPostRedisplay();
		if (elbow_Angle >= 170)
		{
			elbow_Angle = 170;
		};

		break;
	case '!':

		elbow_Angle = (elbow_Angle - 5);
		glutPostRedisplay();
		if (elbow_Angle <= 0)
		{
			elbow_Angle = 0;
		};


		break;
	case '3':
		finger_Angle = 30;
		glutPostRedisplay();
		break;
	case '#':
		finger_Angle = 0;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	////arduino
	SerialPort arduino(portName);
	if (arduino.isConnected()) cout << "Connection Established" << endl;
	else cout << "ERROR, check port name";

	while (arduino.isConnected()) {
		//Check if data has been read or not
		int read_result = arduino.readSerialPort(incomingData, MAX_DATA_LENGTH);
		//prints out data
		puts(incomingData);
		//wait a bit
		Sleep(100);
	}

	glutMainLoop();
	return 0;
}