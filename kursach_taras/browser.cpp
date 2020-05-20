#include <gl\glut.h>
#include "browser.h"

#define ROTATE_CONST 1
#define SCALE_UP_CONST 1.02f
#define SCALE_DOWN_CONST 0.9803921568627451f
#define TRASNPARATE_CONST 0.05f



void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (auto& figure : FigureQueue::getQueue())
		figure->draw();

	glutSwapBuffers();
}

void keyboardEeventsHandler(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '1':
		for (auto& figure : FigureQueue::getQueue())
			figure->rotate(0, ROTATE_CONST, 0);
		break;
	case '3':
		for (auto& figure : FigureQueue::getQueue())
			figure->rotate(0, -ROTATE_CONST, 0);
		break;
	case '4':
		for (auto& figure : FigureQueue::getQueue())
			figure->rotate(ROTATE_CONST, 0, 0);
		break;
	case '6':
		for (auto& figure : FigureQueue::getQueue())
			figure->rotate(-ROTATE_CONST, 0, 0);
		break;
	case '7':
		for (auto& figure : FigureQueue::getQueue())
			figure->rotate(0, 0, ROTATE_CONST);
		break;
	case '9':
		for (auto& figure : FigureQueue::getQueue())
			figure->rotate(0, 0, -ROTATE_CONST);
		break;

	case '+':
		for (auto& figure : FigureQueue::getQueue())
			figure->scale(SCALE_UP_CONST, SCALE_UP_CONST, SCALE_UP_CONST);
		break;
	case '-':
		for (auto& figure : FigureQueue::getQueue())
			figure->scale(SCALE_DOWN_CONST, SCALE_DOWN_CONST, SCALE_DOWN_CONST);
		break;

	case 27:
		exit(0);
		break;
	}
}

void specialEventsHandler(int key, int x, int y)
{
	switch (key)
	{
		//incorrect trasparate
	case GLUT_KEY_UP:
		for (auto& figure : FigureQueue::getQueue())
			figure->translate(0.0f, 0.0f, -TRASNPARATE_CONST);
		break;
	case GLUT_KEY_DOWN:
		for (auto& figure : FigureQueue::getQueue())
			figure->translate(0.0f, 0.0f, TRASNPARATE_CONST);
		break;
	case GLUT_KEY_LEFT:
		for (auto& figure : FigureQueue::getQueue())
			figure->translate(0.0f, TRASNPARATE_CONST, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		for (auto& figure : FigureQueue::getQueue())
			figure->translate(0.0f, -TRASNPARATE_CONST, 0.0f);
		break;
	}

	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}

Browser::Browser(int *argcp, char **argv)
{
	glutInit(argcp, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(640, 480);
	glutCreateWindow("TARASJ");
	parser.run(argcp, argv);
	//glutFullScreen();
}

Browser::~Browser()
{

}

void Browser::run()
{
	initializeScreen();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardEeventsHandler);
	glutSpecialFunc(specialEventsHandler);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}

void Browser::initializeScreen()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);
	gluPerspective(60, w / h, 0.1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt
		(
		3, 0, 0,
		0, 0, 0,
		0, 0, 1
		);

	glutSwapBuffers();
}
