// GamesProgramming.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "glut.h"
#include "Ball.h"
#include "ParticleSystem.h"
#include "RenderBall.h"
using namespace std;

Ball *b;
int oldTime = 0;
int newTime = 0;
ParticleSystem *particles;

int getDeltaTime()
{
	oldTime = newTime;
	newTime = glutGet(GLUT_ELAPSED_TIME);
	if (oldTime == 0)
	{
		oldTime = newTime;
	}
	return newTime - oldTime;
}

void initGL()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

void displayBall()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	RenderBall::render(*b);
	glFlush();
}

void displayParticles()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glBegin(GL_POINTS);
	for (int i = 0; i < particles->particle_no; i++)
	{
		glColor4f((float)1 - i / particles->particle_no, 0.0, (float)i/particles->particle_no, (float)particles->particles[i].currLife/particles->particles[i].lifespan);
		glVertex3f(particles->particles[i].pos.x, particles->particles[i].pos.y, particles->particles[i].pos.z);
	}
	glEnd();
	glFlush();
}

void idleParticles()
{
	int dt = getDeltaTime();
	if (dt < 10)
	{
		particles->updateParticles(dt);
		glutPostRedisplay();
	}
}

bool checkBallBottom()
{
	
	if (b->pos.y <= (-10 + b->radius))
	{
		return true;
	}
	return false;
}

void idleBallBouncing()
{
	if (checkBallBottom() && b->velocity.y < 0)
	{
		b->addForce(b->velocity * -1.7);
	}
	int dt = getDeltaTime();
	b->updatePosition(dt);
	glutPostRedisplay();

}

void idleBallFalling()
{
	if (checkBallBottom() && b->velocity.y < 0)
	{
		particles = new ParticleSystem(vector(0, 0, b->pos.z), 5, 1.2);
		glutIdleFunc(idleParticles);
		glutDisplayFunc(displayParticles);
		int dt = getDeltaTime();
	}else{
		int dt = getDeltaTime();
		b->updatePosition(dt);
		glutPostRedisplay();
	}

}

void lab1(int argc, char **argv)
{
	b = new Ball(vector(0.0, 10.0, 0.0), 1.0f, 1.0f);
	GLUquadric *qobj = gluNewQuadric();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Lab1");
	glutDisplayFunc(displayBall);
	glutIdleFunc(idleBallFalling);
	initGL();
	glutMainLoop();\
}

void lab2(int argc, char **argv)
{
	b = new Ball(vector(0.0, 10.0, 0.0), 1.0f, 1.0f);
	GLUquadric *qobj = gluNewQuadric();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Lab1");
	glutDisplayFunc(displayBall);
	glutIdleFunc(idleBallBouncing);
	initGL();
	glutMainLoop(); \
}

int main(int argc, char **argv)
{
	//lab1(argc, argv);
	lab2(argc, argv);
}

