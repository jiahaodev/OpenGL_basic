// InitGlut.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <gl\glut.h>
#include <iostream>
void render(void){
	//����ϴ���ʾ�����ÿ�λ���ǰ����
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,1.0,0.0,0.0);
	//���細���Ե�ǰ�����е�Ϊԭ�㣬����Ϊ+x�ᣬ����Ϊ+y��
	glBegin(GL_TRIANGLES);
		glColor3f(1.0,1.0,1.0);
		glVertex3f(1.0,1.0,1.0);
		glVertex3f(-0.5,0.5,0.0);
		glVertex3f(0.5,0.0,0.0);
	glEnd();
	//glFlush();//�͵�����GLUT_SINGLE ���ʹ��
	glutSwapBuffers();//��˫����GLUT_DOUBLE ���ʹ��
	std::cout<<"glutSwapBuffers() ---- GLUT_DOUBLE\n";
}
int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc,(char**)argv);
	//glutInitDisplayMode(GLUT_DEPTH|GLUT_SINGLE|GLUT_RGBA);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_RGBA|GLUT_DOUBLE);
	glutInitWindowPosition(-1,-1);
	//ʵ�ֵ��Ǳ�������
	glutInitWindowSize(400,400);
	glutCreateWindow("OpenGL-glutInit()");
	glutDisplayFunc(render);//�Ĵ�ص�
	glutMainLoop();
	return 0;
}

