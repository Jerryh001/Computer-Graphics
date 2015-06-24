#include <iostream>
#include <fstream>
#include <GL/glut.h>
#include "vector.h"
using namespace std;
float r = 0;
int tp = 0;
vector3D point[20][20];
vector3D fa_face[19][19][2];
vector3D fa_point[20][20];
float pos[4] = { 0, 100, 0, 0 };
float sp[4] = { 1, 1, 1, 1 };
float amb[4] = { 0.1, 0.1, 0.1, 1 };
float dif[4] = { 0.5, 0.5, 0.5, 0 };
float m_sp[4] = { 0.5, 0.5, 0.6, 1 };
float m_sh = 1;
float m_amb[4] = { 0.1, 0.1, 0.1, 1 };
float m_dif[4] = { 1, 1, 1, 1 };
int time = glutGet(GLUT_ELAPSED_TIME);
void drawframe()
{
	glShadeModel(GL_SMOOTH);
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glLineWidth(2);
	for (int i = 1; i < 19; i++)
	{
		for (int j = 1; j < 19; j++)
		{
			glBegin(GL_LINE_STRIP);
			glColor3ub(0, 0, 255);
			glVertex3fv(point[i][j].tofloat());
			glVertex3fv(point[i][j + 1].tofloat());
			glVertex3fv(point[i + 1][j + 1].tofloat());
			glVertex3fv(point[i + 1][j].tofloat());
			glVertex3fv(point[i][j].tofloat());
			glColor3ub(255, 255, 255);
			glVertex3fv(point[i + 1][j + 1].tofloat());
			glEnd();
		}
	}
}
void c_fa_face()
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			fa_face[i][j][0] = (point[i + 1][j + 1] - point[i][j]).cross_normal(point[i][j + 1] - point[i][j]);
			fa_face[i][j][1] = (point[i + 1][j] - point[i][j]).cross_normal(point[i + 1][j + 1] - point[i][j]);
		}
	}
}
void c_fa_point()
{
	c_fa_face();
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (i>0 && j>0)
			{
				fa_point[i][j] += fa_face[i-1][j-1][0] + fa_face[i-1][j-1][1];
			}
			if (i <19 && j <19)
			{
				fa_point[i][j] += fa_face[i][j][0] + fa_face[i][j][1];
			}
			if (j<19&&i>0)
			{
				fa_point[i][j] += fa_face[i - 1][j][1];
			}
			if (i<19&&j>0)
			{
				fa_point[i][j] += fa_face[i][j - 1][0];
			}
			fa_point[i][j] = fa_point[i][j].normal();
		}
	}
}
void drawflat()
{
	glShadeModel(GL_FLAT);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	c_fa_face();
	for (int i = 1; i < 19; i++)
	{
		for (int j = 1; j < 19; j++)
		{
			glBegin(GL_TRIANGLE_FAN);
			glNormal3fv(fa_face[i][j][0].tofloat());
			glVertex3fv(point[i][j].tofloat());
			glVertex3fv(point[i][j+1].tofloat());
			glVertex3fv(point[i+1][j+1].tofloat());
			glNormal3fv(fa_face[i][j][1].tofloat());
			glVertex3fv(point[i+1][j].tofloat());
			glEnd();
		}
	}
}
void drawsmooth()
{
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	c_fa_point();
	for (int i = 1; i < 19; i++)
	{
		for (int j = 1; j < 19; j++)
		{
			glBegin(GL_TRIANGLE_FAN);
			glNormal3fv(fa_point[i][j].tofloat());
			glVertex3fv(point[i][j].tofloat());
			glNormal3fv(fa_point[i][j + 1].tofloat());
			glVertex3fv(point[i][j + 1].tofloat());
			glNormal3fv(fa_point[i + 1][j + 1].tofloat());
			glVertex3fv(point[i + 1][j + 1].tofloat());
			glNormal3fv(fa_point[i + 1][j].tofloat());
			glVertex3fv(point[i + 1][j].tofloat());
			glEnd();
		}
	}
}
void draw()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glMaterialfv(GL_LIGHT0, GL_SPECULAR, sp);
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, m_sp);
	glMaterialfv(GL_FRONT, GL_SHININESS, &m_sh);
	glMaterialfv(GL_FRONT, GL_AMBIENT, m_amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_dif);

	glPushMatrix();
	glRotatef(r, 0, 1, 0);
	switch (tp)
	{
	case 0:
		drawframe();
		break;
	case 1:
		drawflat();
		break;
	case 2:
		drawsmooth();
		break;
	}
	glPopMatrix();
	glutSwapBuffers();
}
void idle()
{
	int timenow = glutGet(GLUT_ELAPSED_TIME);
	r += (timenow-time)/10.0;
	glutPostRedisplay();
	if (r > 360) r -= 360;
	time = timenow;
}
void viewchange(int choose)
{
	tp = choose;
	glutPostRedisplay();
}
void init()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Shading");
	glutDisplayFunc(draw);
	glutIdleFunc(idle);
	glutCreateMenu(viewchange);
	glutAddMenuEntry("®Ø¬[", 0);
	glutAddMenuEntry("FLAT", 1);
	glutAddMenuEntry("SMOOTH", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20, 20, -20, 20, -20, 20);
	gluLookAt(0, 5, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
}
int main()
{
	ifstream fin("map.txt");
	for (int i = 0; i < 400; i++)
	{
		fin >> point[i / 20][i % 20];
	}
	init();
}