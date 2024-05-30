#include<gl/glut.h>
float mrotateangle = 0;
float mengtranslatex, mengtranslatey = 0.0;
void init() {
	glClearColor(0,1,0, 1);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-20, 20, -20,20, -20, 20);
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	//mengtranslatey += 0.1;
	glPushMatrix();
	glRotatef(mrotateangle, 0, 0, 1.0);
	glTranslatef(mengtranslatex, mengtranslatey, 0.0);
	//head
	glPushMatrix();
	glTranslatef(0, 5, 0);
	glColor3f(1, 0.5,0.5);
	glutSolidSphere(3, 20, 20);
	glPopMatrix();
	//left eye
	glPushMatrix();
	glTranslatef(-1, 6, 0);
	glColor3f(0.0, 0.0, 0.0);
	glutSolidSphere(0.5, 20, 20);
	glPopMatrix();
	//right eye
	glPushMatrix();
	glTranslatef(1, 6, 0);
	glColor3f(0.0, 0.0, 0.0);
	glutSolidSphere(0.5, 20, 20);
	glPopMatrix();
	//mouth
	glPushMatrix();
	glTranslatef(0, 4, 0);
	glColor3f(1.0, 1.0, 1.0);
	glutSolidSphere(0.5, 20, 20);
	glPopMatrix();
	//teeth
	glPushMatrix();
	glTranslatef(0, 4, 0);
	glColor3f(0.7, 0.0, 2.0);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();
	//neck
	glPushMatrix();
	glTranslatef(0, 2, 0);
	glColor3f(1, 0.5, 0.5);
	glutSolidCube(1);
    glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 1, 0);
	glColor3f(1, 0.5, 0.5);
	glutSolidCube(1);
	glPopMatrix();
	//body
	glPushMatrix();
	glTranslatef(0, -2.5, 0);
	glColor3f(1, 0.5, 0.5);
	glutSolidCube(8);
	glPopMatrix();
	//left hand
	glPushMatrix();
	glScalef(1, 7, 1);
	//glRotatef(30, 0.0f, 1.0f, 1.0f);
	glTranslatef(-4, 0.6, 0);
	glColor3f(1, 0.5, 0.5);
	glutSolidCube(1);
	glPopMatrix();
	//right hand
	glPushMatrix();
	glScalef(1, 7, 1);
//	glRotatef(3, 0.0f, 1.0f, 1.0f);
	glTranslatef(4, 0.6, 0);
	glColor3f(1, 0.5, 0.5);
	glutSolidCube(1);
	glPopMatrix();
	//left leg
	glPushMatrix();
	glScalef(1, 5, 1);
	glTranslatef(-1.5, -1.5, 0);
	glColor3f(1, 0.5, 0.5);
	glutSolidCube(1);
	glPopMatrix();
	//right leg
	//left leg
	glPushMatrix();
	glScalef(-1, 5, 1);
	glTranslatef(-1.5, -1.5, 0);
	glColor3f(1, 0.5, 0.5);
	glutSolidCube(1);
	glPopMatrix();
	//left shoese
	glPushMatrix();
	glScalef(1.5, 1.5, 1);
	glRotatef(-2, 1, 1, 1);
	glTranslatef(-1, -7, 0);
	glColor3f(0.2, 0.5, 0.6);
	glutSolidSphere(0.5, 20, 20);
	glPopMatrix();
	//
	glPushMatrix();
	glScalef(1, 1.5, 1);
	glRotatef(-5, 1, 1, 1);
	glTranslatef(-1.5, -7.2, 0);
	glColor3f(0.2, 0.5, 0.6);
	glutSolidCube(1);
	glPopMatrix();

	//right shoese
	glPushMatrix();
	glScalef(1.5, 1.5, 1);
	glRotatef(2, 1, 1, 1);
	glTranslatef(1, -7, 0);
	glColor3f(0.2, 0.5, 0.6);
	glutSolidSphere(0.5, 20, 20);
	glPopMatrix();
	//
	glPushMatrix();
	glScalef(-1, 1.5, 1);
	glRotatef(-5, 1, 1, 1);
	glTranslatef(-1.5, -7.2, 0);
	glColor3f(0.2, 0.5, 0.6);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	// leftbar
	glPushMatrix();
	glScalef(1,35 , 1);
	//glRotatef(-5, 1, 1, 1);
	glTranslatef(-13,0, 1);
	glColor3f(0, 0, 0);
	glutSolidCube(1);
	glPopMatrix();
	// right bar
	glPushMatrix();
	glScalef(1, 35, 1);
	//glRotatef(-5, 1, 1, 1);
	glTranslatef(13, 0, 1);
	glColor3f(0, 0, 0);
	glutSolidCube(1);
	glPopMatrix();
	// top tbar
	glPushMatrix();
	glScalef(27, 1, 1);
	//glRotatef(-5, 1, 1, 1);
	glTranslatef(0, 18, 1);
	glColor3f(0, 0, 0);
	glutSolidCube(1);
	glPopMatrix();
	glFlush();
	glutSwapBuffers();

}
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '8':
		mengtranslatey += 1.0;
		break;
	case '2':
		mengtranslatey -= 1.0;
		break;
	case '4':
		mrotateangle -= 5.0;
		break;
	case '6':
		mrotateangle += 5.0;
		break;
	}
	glutPostRedisplay();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("I am mengaw's robot");
	glutKeyboardFunc(keyboard);
	glutIdleFunc(display);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;

}