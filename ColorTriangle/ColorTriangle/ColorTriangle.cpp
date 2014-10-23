// ColorTriangle.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <gl/glut.h>

void init(GLvoid){
	glClearColor(1.0,1.0,1.0,0.0);
	//������ɫģʽ  GL_FLAT:�㶨 GL_SMOOTH: �⻬
//	glShadeModel(GL_SMOOTH);
	glShadeModel(GL_FLAT);
}

void triangle(GLvoid){
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f,0.0f,0.0f);glVertex2f(5.0f,5.0f);
		glColor3f(0.0f,1.0f,0.0f);glVertex2f(25.0f,5.0f);
		glColor3f(0.0f,0.0f,1.0f);glVertex2f(5.0f,25.0f);
	glEnd();
}

void display(GLvoid){
	glClear(GL_COLOR_BUFFER_BIT);
	triangle();
	glFlush();
}

void reshape(int w,int h){
	glViewport(0,0,(GLsizei)w ,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h)
		gluOrtho2D(0.0,30.0,0.0,30.0*(GLfloat)h/(GLfloat)w);//���½�x,���Ͻ�x,���½�y,���Ͻ�y
	else
		gluOrtho2D(0.0,30.0*(GLfloat)w/(GLfloat)h,0.0,30.0);
	glMatrixMode(GL_MODELVIEW);
}

int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc,(char**)argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(600,400);
	glutInitWindowPosition(100,100);
	glutCreateWindow("OpenGL ��ɫ����");
	init();
	//ע�ᴰ�ڵ���ʾ�ص�����
	//���ڸı��С���ߴӱ�����״̬�ָ����������ڵ���glutPostRedisplay()����Ҫ��glut����ʱ��ִ��func����ָ���ĺ���
	//�βΣ�void(*func)(void)
	glutDisplayFunc(display);
	//�����ڵĴ�С�ı�ʱ���õĺ������������ڵ�һ�δ���) 
	//�βΣ�void func(int width,int height)
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

