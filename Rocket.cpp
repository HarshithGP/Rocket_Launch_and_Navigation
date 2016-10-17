/* ROCKET LAUNCH AND NAVIGATION

Code Developed by Harshith Guru Prasad
6th Sem, Computer Science and Engineering,
BNMIT, VTU, May 2015

*/

#include<GL/glut.h>
#include<math.h>

int counter = 0, launch = 0;
int star_flag = 0, p = 0, flag = 0,f=0;

// fucntion to display the text content of the home screen
void drawstring(int x, int y, char *s)
{
	char *c;
	glRasterPos2i(x, y);
	for (c = s; *c != '\0'; *c++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
}

// function to draw the graphic visuals of the moon object
void moon(int x1, int y1, int r)
{
	GLfloat theta = 0;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 1);
	while (theta <= 360.0)
	{
		float xc = r*sin(theta) + x1;
		float yc = r*cos(theta) + y1;
		glVertex2f(xc, yc);
		glutPostRedisplay();
		glFlush();
		theta += 0.1;
	}
	glEnd();
	glutPostRedisplay();
	glFlush();

}

// replicates the twinkling of stars in the sky
void stars1()
{
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(1.5);

	glBegin(GL_POINTS);
	glVertex2i(10, 20);
	glVertex2i(20, 100);
	glVertex2i(30, 10);
	glVertex2i(15, 150);
	glVertex2i(17, 80);
	glVertex2i(200, 200);
	glVertex2i(55, 33);
	glVertex2i(400, 300);
	glVertex2i(330, 110);
	glVertex2i(125, 63);
	glVertex2i(63, 125);
	glVertex2i(20, 10);
	glVertex2i(110, 330);
	glVertex2i(440, 430);
	glVertex2i(32, 65);
	glVertex2i(110, 440);
	glVertex2i(210, 230);
	glVertex2i(390, 490);
	glVertex2i(12, 90);
	glVertex2i(400, 322);
	glVertex2i(420, 366);
	glVertex2i(455, 400);
	glVertex2i(20, 20);
	glVertex2i(111, 120);
	glVertex2i(401, 200);
	glVertex2i(230, 30);
	glVertex2i(220, 20);
	glVertex2i(122, 378);
	glVertex2i(133, 340);
	glVertex2i(345, 420);
	glVertex2i(130, 360);
	glVertex2i(333, 120);
	glVertex2i(250, 22);
	glVertex2i(242, 11);
	glVertex2i(220, 332);
	glVertex2i(233, 40);
	glVertex2i(210, 418);
	glVertex2i(256, 12);
	glVertex2i(218, 232);
	glVertex2i(247, 36);
	glVertex2i(229, 342);
	glVertex2i(257, 47);
	glVertex2i(290, 63);
	glVertex2i(232, 72);
	glVertex2i(243, 143);
	glVertex2i(150, 200);
	glVertex2i(90, 250);
	glVertex2i(80, 225);
	glVertex2i(50, 333);
	glVertex2i(60, 350);
	glVertex2i(243, 143);
	glVertex2i(543, 143);
	glVertex2i(583, 143);
	glVertex2i(543, 123);
	glVertex2i(583, 183);
	glVertex2i(593, 113);
	glVertex2i(580, 573);
	glVertex2i(540, 543);
	glVertex2i(550, 523);
	glEnd();

}
void stars2()
{
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(1.5);

	glBegin(GL_POINTS);
	glVertex2i(13, 24);
	glVertex2i(26, 120);
	glVertex2i(3, 14);
	glVertex2i(15, 350);
	glVertex2i(17, 90);
	glVertex2i(260, 300);
	glVertex2i(554, 35);
	glVertex2i(450, 320);
	glVertex2i(330, 180);
	glVertex2i(425, 69);
	glVertex2i(63, 125);
	glVertex2i(20, 10);
	glVertex2i(110, 330);
	glVertex2i(540, 130);
	glVertex2i(320, 64);
	glVertex2i(112, 410);
	glVertex2i(410, 290);
	glVertex2i(290, 390);
	glVertex2i(120, 98);
	glVertex2i(500, 422);
	glVertex2i(320, 326);
	glVertex2i(355, 200);
	glVertex2i(209, 203);
	glVertex2i(115, 140);
	glVertex2i(450, 250);
	glVertex2i(239, 305);
	glVertex2i(235, 205);
	glVertex2i(125, 390);
	glVertex2i(135, 345);
	glVertex2i(395, 490);
	glVertex2i(180, 350);
	glVertex2i(313, 100);
	glVertex2i(220, 220);
	glVertex2i(202, 110);
	glVertex2i(270, 301);
	glVertex2i(233, 40);
	glVertex2i(210, 418);
	glVertex2i(256, 12);
	glVertex2i(298, 432);
	glVertex2i(237, 396);
	glVertex2i(259, 542);
	glVertex2i(257, 547);
	glVertex2i(290, 563);
	glVertex2i(232, 572);
	glVertex2i(243, 543);
	glVertex2i(150, 500);
	glVertex2i(10, 250);
	glVertex2i(70, 225);
	glVertex2i(80, 333);
	glVertex2i(60, 550);
	glVertex2i(243, 543);
	glVertex2i(443, 143);
	glVertex2i(583, 143);
	glVertex2i(543, 123);
	glVertex2i(583, 183);
	glVertex2i(593, 113);
	glVertex2i(583, 573);
	glVertex2i(540, 543);
	glVertex2i(550, 523);
	glEnd();

}

//design of the rocket flames
void flames(int x, int y)
{
	//to change the color of the flame alternately
	if ((p % 2) == 0)
		glColor3f(1.0, 0.816, 0.0);
	else
		glColor3f(1.0, 0.25, 0.0);

	glBegin(GL_POLYGON);//outer flame
	glVertex2i(x - 25, y - 75);
	glVertex2i(x - 100, y - 125);
	glVertex2i(x, y - 200);
	glVertex2i(x + 100, y - 125);
	glVertex2i(x + 25, y - 75);
	glEnd();

	//alternately switch between flame colors
	if ((p % 2) == 0)
		glColor3f(1.0, 0.25, 0.0);
	else
		glColor3f(1.0, 0.816, 0.0);

	glBegin(GL_POLYGON);//inner flame
	glVertex2i(x - 25, y - 75);
	glVertex2i(x - 50, y - 125);
	glVertex2i(x, y - 150);
	glVertex2i(x + 50, y - 125);
	glVertex2i(x + 25, y - 75);
	glEnd();

	//delay
	for (int j = 1; j <= 50000000; j++)
		;

	glutSwapBuffers();
	glutPostRedisplay();
	glFlush();

}

//design of the stand object on screen
void stand()
{
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2i(50, 0);
	glVertex2i(50, 350);
	glVertex2i(100, 350);
	glVertex2i(100, 150);
	glVertex2i(150, 100);
	glVertex2i(275, 100);
	glVertex2i(235, 50);
	glVertex2i(150, 50);
	glVertex2i(150, 0);
	glEnd();

	glColor3f(1, 1, 1);
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
	glVertex2i(50, 0);
	glVertex2i(50, 350);
	glVertex2i(100, 350);
	glVertex2i(100, 150);
	glVertex2i(150, 100);
	glVertex2i(275, 100);
	glVertex2i(235, 50);
	glVertex2i(150, 50);
	glVertex2i(150, 0);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(250, 0);
	glVertex2i(250, 25);
	glVertex2i(275, 25);
	glVertex2i(275, 0);

	glVertex2i(325, 0);
	glVertex2i(325, 25);
	glVertex2i(350, 25);
	glVertex2i(350, 0);
	glEnd();
}

//design of the rocket body
void rocket(int x, int y)
{

	glColor3f(1, 1, 1);

	glBegin(GL_QUADS);
	glVertex2f(x - 25, y - 75);
	glVertex2f(x - 25, y + 75);
	glVertex2f(x + 25, y + 75);
	glVertex2f(x + 25, y - 75);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(x - 25, y + 75);
	glVertex2f(x, y + 150);
	glVertex2f(x + 25, y + 75);

	glVertex2f(x - 25, y + 75);
	glVertex2f(x - 75, y + 75);
	glVertex2f(x - 25, y + 25);

	glVertex2f(x + 25, y + 75);
	glVertex2f(x + 75, y + 75);
	glVertex2f(x + 25, y + 25);

	glVertex2f(x - 25, y);
	glVertex2f(x - 75, y - 75);
	glVertex2f(x - 25, y - 75);

	glVertex2f(x + 25, y);
	glVertex2f(x + 75, y - 75);
	glVertex2f(x + 25, y - 75);

	glEnd();

	glColor3f(1, 0, 0);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x - 25, y - 75);
	glVertex2f(x - 25, y + 75);
	glVertex2f(x + 25, y + 75);
	glVertex2f(x + 25, y - 75);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(x - 25, y + 75);
	glVertex2f(x, y + 150);
	glVertex2f(x + 25, y + 75);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(x - 25, y + 75);
	glVertex2f(x - 75, y + 75);
	glVertex2f(x - 25, y + 25);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(x + 25, y + 75);
	glVertex2f(x + 75, y + 75);
	glVertex2f(x + 25, y + 25);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(x - 25, y);
	glVertex2f(x - 75, y - 75);
	glVertex2f(x - 25, y - 75);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(x + 25, y);
	glVertex2f(x + 75, y - 75);
	glVertex2f(x + 25, y - 75);
	glEnd();
}

//determines when the rocket is to be launched
void rocket_static()
{
	counter++;
	if (counter == 500)
		launch = 1;

	if (launch == 0)
	{
		glClearColor(0.2, 0.6, 0.8, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		stars1();
		moon(500, 500, 25);

		rocket(300, 100);
		stand();


		for (int j = 1; j <= 1000000; j++)
			;

		glutSwapBuffers();
		glutPostRedisplay();
		glFlush();
	}
}

void rocket_launch()
{
	int i, x1 = 300, y1 = 100;
	for (i = 1; i <= 40; i++)
	{
		glClearColor(0.2, 0.6, 0.8, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		y1 = y1 + i;
		stars1();
		moon(500, 500, 35);
		rocket(x1, y1);
		p++;
		flames(x1, y1);
	}
}

//displays the rocket in outer space
void rocket_in_space()
{
	int x1 = 300, y1 = 250, i;

	for (i = 1; i <= 10; i++)
	{
		glClearColor(0.0, 0.0, 0.0, 1.0);
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		moon(500, 500, 35);
		if (star_flag == 0)
		{
			stars1();
			star_flag = 1;
		}
		else
		{
			stars2();
			star_flag = 0;
		}

		rocket(x1, y1);
		p++;
		flames(x1, y1);
	}
}

// left navigation in space on mouse left click
void navigate_left()
{
	int x1 = 200, y1 = 250, i;


	for (i = 1; i <= 10; i++)
	{
		glClearColor(0.0, 0.0, 0.0, 1.0);
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		moon(500, 500, 35);
		if (star_flag == 0)
		{
			stars1();
			star_flag = 1;
		}
		else
		{
			stars2();
			star_flag = 0;
		}

		rocket(x1, y1);
		p++;
		flames(x1, y1);
	}

}

//right navigation in space on mouse right click
void navigate_right()
{
	int x1 = 400, y1 = 250;
	int i;


	for (i = 1; i <= 10; i++)
	{
		glClearColor(0.0, 0.0, 0.0, 1.0);
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		moon(500, 500, 35);
		if (star_flag == 0)
		{
			stars1();
			star_flag = 1;
		}
		else
		{
			stars2();
			star_flag = 0;
		}
		rocket(x1, y1);
		p++;
		flames(x1, y1);
	}
}


//keys that trigger manual Lanch
void keyboard(unsigned char key, int x, int y)
{
	if (key == 'S' || key == 's')
		flag = 1;

	if (key == 'L' || key == 'l')
	{
		rocket_launch();
		launch = 1;
	}

	if (key == 'Q' || key == 'q')
		exit(0);

}

// mouse interface
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		navigate_left();
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		navigate_right();
}

//design of homescreen
void page()
{
	glColor3f(1, 1, 1);
	glLineWidth(5);
	glBegin(GL_LINE_LOOP);
	glVertex2d(175, 525);
	glVertex2d(475, 525);
	glVertex2d(475, 425);
	glVertex2d(175, 425);
	glEnd();

	drawstring(200, 500, "ROCKET LAUNCH AND NAVIGATION");
	drawstring(200, 480, "NAME : HARSHITH GURU PRASAD");
	drawstring(200, 460, "USN : 1BG12CS039");
	drawstring(200, 440, "SEM : VI");

	glBegin(GL_LINE_LOOP);
	glVertex2d(175, 175);
	glVertex2d(475, 175);
	glVertex2d(475, 325);
	glVertex2d(175, 325);
	glEnd();

	drawstring(200, 300, "INSTRUCTIONS");
	drawstring(200, 280, "Press S to START");
	drawstring(200, 260, "Press L to Launch the Rocket");
	drawstring(200, 240, "RIGHT CLICK to Navigate Right");
	drawstring(200, 220, "LEFT CLICK to Navigate Left");
	drawstring(200, 200, "Press Q to quit");
	glFlush();
}

//determines the state of rocket launch
void control()
{
	counter++;

	if (launch == 0)
		rocket_static();
	else if (launch == 1 && (counter == 600 || counter == 601))
		rocket_launch();

	else if (launch == 1 && counter >= 1000)
		rocket_in_space();
}

//display all components
void display()
{
	if (flag == 0)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		page();
		glutSwapBuffers();
	}
	else
		control();
	glFlush();
}


//initial settings
void myInit()
{
	glClearColor(0.2, 0.6, 0.8, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 600, 0, 600);
	glMatrixMode(GL_MODELVIEW);
}

//main()
void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutCreateWindow("ROCKET");
	myInit();
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop();
}
