#include <GL/glut.h>
int a = 0;
int Oz = 0, Ox = 0;;
void mydisplay(){

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(Ox, 0, Oz);
	glRotatef(a, 0, 1, 0);
	glutWireTeapot(20);	 
	glPopMatrix();


	glFlush();
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0, 100.0, -100.0, 100.0, -500.0, 500.0);
	gluLookAt(0, 10, 100, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}
void idle()
{
	a=(a+1)%360;
	glutPostRedisplay();
}
void menu(int id)
{
	if (id == 1)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-100.0, 100.0, -100.0, 100.0, -500.0, 500.0);
		gluLookAt(0, 10, 100, 0, 0, 0, 0, 1, 0);
	}
	else if (id == 2)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glFrustum(-50.0, 50.0, -50.0, 50.0, 50, 500);
		gluLookAt(0, 10, 500, 0, 0, 0, 0, 1, 0);
		
	}
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
void key(unsigned char a, int x, int y)
{
	switch (a)
	{
	case 'w':
		Oz-=5;
		break;
	case 's':
		Oz+=5;
		break;
	case 'a':
		Ox--;
		break;
	case 'd':
		Ox++;
		break;
	}
	glutPostRedisplay();
}
int main()
{
	glutInitWindowSize(500, 500);
	glutCreateWindow("simple");
	glutDisplayFunc(mydisplay);
	glutKeyboardFunc(key);
	glutIdleFunc(idle);
	glutCreateMenu(menu);
	glutAddMenuEntry("垂直投影", 1);
	glutAddMenuEntry("俯視投影", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	init();

	glutMainLoop();
}