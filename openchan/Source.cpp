#include <GL/glut.h>
void showopenchan()
{
	GLUquadricObj* quadricPtr = gluNewQuadric();
	gluQuadricDrawStyle(quadricPtr, GLU_FILL);
	glShadeModel(GL_SMOOTH);
	gluQuadricNormals(quadricPtr, GLU_SMOOTH);
	gluQuadricTexture(quadricPtr, GL_FALSE);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	//����
	glPushMatrix();
	glTranslatef(0, -2, 0);
	glColor3ub(219, 32, 68);
	gluPartialDisk(quadricPtr, 9, 12, 50, 1, 270, 180);
	glColor3ub(0, 146, 63);
	gluPartialDisk(quadricPtr, 12.2, 14, 50, 1, 270, 180);
	glColor3ub(230, 120, 23);
	gluPartialDisk(quadricPtr, 14.2, 16, 50, 1, 270, 180);
	glPopMatrix();
	//�Y
	glColor3ub(247, 241, 189);
	glPushMatrix();
	glScalef(1, 0.8, 1);
	gluSphere(quadricPtr, 10, 50, 50);
	glPopMatrix();
	//��
	glColor3ub(143, 84, 68);
	glPushMatrix();
	glTranslatef(0, 0, 10);
	gluSphere(quadricPtr, 1, 50, 50);
	glPopMatrix();
	//����
	glColor3ub(0, 0, 0);
	glPushMatrix();
	glTranslatef(-3, 3, 5);
	gluSphere(quadricPtr, 1.5, 50, 50);
	glPopMatrix();
	//�k��
	glColor3ub(0, 0, 0);
	glPushMatrix();
	glTranslatef(3, 3, 5);
	gluSphere(quadricPtr, 1.5, 50, 50);
	glPopMatrix();
	//�L
	glColor3ub(0, 0, 0);
	glPushMatrix();
	glTranslatef(0, -2, 3);
	gluPartialDisk(quadricPtr, 3.5, 4, 50, 1, 90, 180);
	glPopMatrix();
	//����
	glColor3ub(247, 241, 189);
	glPushMatrix();
	glTranslatef(0, -7, 0);
	glRotatef(90,1,0,0);
	gluCylinder(quadricPtr, 4, 5, 12, 50, 1);
	glPopMatrix();
	//����
	glColor3ub(247, 241, 189);
	glPushMatrix();
	glTranslatef(-4, -12, 0);
	glRotatef(-90, 0, 1, 0);
	gluCylinder(quadricPtr, 1, 1.1, 10, 50, 1);
	glPopMatrix();
	//�k��
	glColor3ub(247, 241, 189);
	glPushMatrix();
	glTranslatef(3.5, -12, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(45, 1, 0, 0);
	gluCylinder(quadricPtr, 1, 1.1, 10, 50, 1);
	glPopMatrix();
	//�U
	glColor3ub(247, 241, 189);
	glPushMatrix();
	glTranslatef(0, -20, 0);
	gluSphere(quadricPtr, 5, 50, 50);
	glPopMatrix();
	//���}
	glColor3ub(247, 241, 189);
	glPushMatrix();
	glTranslatef(-3.5, -22, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(-10, 0, 1, 0);
	gluCylinder(quadricPtr, 1, 1.1, 8, 50, 1);
	glPopMatrix();
	//�k�}
	glColor3ub(247, 241, 189);
	glPushMatrix();
	glTranslatef(3.5, -22, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(10, 0, 1, 0);
	gluCylinder(quadricPtr, 1, 1.1, 8, 50, 1);
	glPopMatrix();
	glFlush();
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50, 50, -50, 50, -50, 50);
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);//�e
	//gluLookAt(0, 10, 0, 0, 0, 0, 0, 0, -1);//�W
	//gluLookAt(10, 0, 10, 0, 0, 0, 0, 1, 0);//�k
	//gluLookAt(10, 10, 10, 0, 0, 0, 0, 1, 0);//45��
	glMatrixMode(GL_MODELVIEW);
}
int main()
{
	glutInitWindowSize(600, 600);
	glutCreateWindow("Open Chan");
	glutDisplayFunc(showopenchan);

	init();

	glutMainLoop();
}