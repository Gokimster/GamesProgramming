// GamesProgramming.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "glut.h"
#include "Ball.h"
#include "ParticleSystem.h"
#include "RenderManager.h"
#include "BoidsManager.h"
using namespace std;

Ball *b;
int oldTime = 0;
int newTime = 0;
ParticleSystem *particles;
BoidsManager *boids;

//==========================
//Common Helper Functions
//==========================
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

void displayBall()
{
	RenderManager::clear();
	RenderManager::renderBall(*b);
	glFlush();
}

bool checkBallBottom()
{
	
	if (b->pos.y <= (-10 + b->radius))
	{
		return true;
	}
	return false;
}

//==========================
//Particle System 
//==========================

void displayParticles()
{
	RenderManager::clear();
	glBegin(GL_POINTS);
	for (int i = 0; i < particles->particle_no; i++)
	{
		RenderManager::renderPoint(particles->particles[i], vector((float)1 - i / particles->particle_no, 0.0, (float)i / particles->particle_no), (float)particles->particles[i].currLife / particles->particles[i].lifespan);
	}
	glEnd();
	glFlush();
}

void idleParticles()
{
	int dt = getDeltaTime();
	particles->updateParticles(dt);
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
	}
	else {
		int dt = getDeltaTime();
		b->updatePosition(dt);
		glutPostRedisplay();
	}

}

void lab1(int argc, char **argv)
{
	glutDisplayFunc(displayBall);
	glutIdleFunc(idleBallFalling);
}


//==========================
//Bouncing Ball 
//==========================

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

void lab2(int argc, char **argv)
{
	glutDisplayFunc(displayBall);
	glutIdleFunc(idleBallBouncing);
}


//==========================
//Boids - Flocking
//==========================

void displayBoids()
{
	RenderManager::clear();
	glBegin(GL_POINTS);
	for (int i = 0; i < boids->boids_no; i++)
	{
		//RenderManager::renderPoint(boids->boids[i], vector(0,0,1), 0);
		RenderManager::renderBall(Ball(boids->boids[i].pos, 0.1, 0.1));
	}
	glEnd();
	glFlush();
}

void idleBoids()
{
	int dt = getDeltaTime();
	boids->updateBoids(dt, 10);
	glutPostRedisplay();
}

void lab3(int argc, char **argv)
{
	boids = new BoidsManager(vector(0, 0, 0), 3, 3);
	glutDisplayFunc(displayBoids);
	glutIdleFunc(idleBoids);
}

//==========================
//Main Function
//==========================
int main(int argc, char **argv)
{
	b = new Ball(vector(0.0, 10.0, 0.0), 1.0f, 1.0f);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);	
	glutCreateWindow("Games Programming");
	//lab1(argc, argv);
	//lab2(argc, argv);
	lab3(argc, argv);
	RenderManager::initGL();
	glutMainLoop();
}

