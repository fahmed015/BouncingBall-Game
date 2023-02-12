
#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <glut.h>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

using namespace std;
#include <Windows.h>
#include<mmsystem.h>


float rotAng = 180;
float rotAng2 = 0;
bool center1 = false;
bool center2 = false;
bool center3 = false;
bool right1 = false;
bool right4 = false;
bool right5 = false;
bool ff = false;


bool org = false;

bool down = false;
bool down2 = false;
bool tt = false;
bool down3 = false;

bool flip = false;
bool flip2 = false;

bool right12 = false;
bool right13 = false;
bool right14 = false;

bool left12 = false;
bool left13 = false;
bool left14 = false;

bool right2 = false;
bool right3 = false;
bool right6 = false;
bool right7 = false;
bool right8 = false;


bool left1 = false;
bool left2 = false;
bool left3 = false;
bool left5 = false;
bool left4 = false;
bool left7 = false;
bool left8 = false;
bool left6 = false;


int score = 0;
int totalscore = 0;
string number;

int reds = -10;
int yellows = 15;
int blues = 5;
int greens = 20;
int cr1 = 0;
int cr2 = 0;
int cr3 = 0;
int cr4 = 0;
int cr6 = 0;

int cr5 = 0;
int cr8 = 0;
int cr7 = 0;
int cr9 = 0;
int cr10 = 0;
int cr11 = 0;
int cr12 = 0;



bool bcr1 = false;
bool bcr2 = false;
bool bcr3 = false;
bool bcr4 = false;
bool bcr5 = false;
bool bcr6 = false;
bool bcr7 = false;
bool bcr8 = false;
bool bcr9 = false;
bool bcr10 = false;
bool bcr11 = false;
bool bcr12 = false;



bool show = false;
bool view = false;
bool not= false;
bool keyy = false;



int rounds = 0;




float speedx = 0.0002;
float speedy = 0.001;
float speedz = 0.005;

float speedz1 = 0.0015;
float speedx1 = 0.0008;

float speedx2 = 0.004;
float speedz2 = 0.0008;

float speedz3 = 0.002;
float speedx3 = 0.0008;

float speedz4 = 0.0023;
float speedx4 = 0.0008;

float speedz5 = 0.0027;
float speedx5 = 0.0008;





bool pos2 = false;

float z = 2.5;
float x = 0;
float y = 0;

float zo = 2.5;
float xo = 0;
float yo = 0;




float c1 = 0;
float c2 = 0;
float c3 = 3.3;
float l1 = 0;
float l3 = -1;
float l2 = 0;



void axis(double length) { // draw a z-axis, with cone at end  
	glPushMatrix();

	glBegin(GL_LINES);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, length); // along the z-axis 
	glEnd();

	glTranslated(0, 0, length - 1.5);
	glutWireCone(0.04, 0.2, 12, 9);

	glPopMatrix();
}

void print(int x, int y, char* string)
{
	int len, i;

	//set the position of the text in the window using the x and y coordinates
	glRasterPos2f(x, y);

	//get the length of the string to display
	len = (int)strlen(string);

	//loop to display character by character
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}
void setupCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 300 / 300, 0.1f, 300.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(c1, c2, c3, l1, l2, l3, 0.0f, 1.0f, 0.0f);


	//gluLookAt(c1, c2, c3, l1, l2, l2, 0.0, 1.0, 0.0);    //postion beta3 camera , postion ell camera hatbos 3alyha , orination beta3 camera
}


void Display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	if (rounds >= 5) {
		c1 = 0;
		c2 = 0;
		c3 = 3.3;
		l1 = 0;
		l3 = -1;
		l2 = 0;
		glColor3f(1, 0, 0);
		//print(-1, 0.5, "GAME OVER");
		glColor3f(0, 0, 0);

		//print(-50, 0, "YOUR SCORE IS");

		stringstream strs;
		strs << totalscore;
		string temp_str = strs.str();
		char* final2 = (char*)temp_str.c_str();

		print(0, -0.5, final2);



		glutPostRedisplay();


		glFlush();

	}










	else {





		setupCamera();


		//print(0,0,2.8 , "HELOO");



		/* glMatrixMode(GL_PROJECTION); // set the view volume shape
		glLoadIdentity();
		glOrtho(-2.0 * 64 / 48.0, 2.0 * 64 / 48.0, -2.0, 2.0, 0.1, 100);
		glMatrixMode(GL_MODELVIEW); // position and aim the camera
		glLoadIdentity();
		gluLookAt(2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); */



		//glColor3d(0, 0, 0); // draw black lines       
		//axis(5);      // z-axis 

		//glPushMatrix();
		//glRotated(90, 0, 1.0, 0);
		//axis(5);     // y-axis
		//glRotated(-90.0, 1, 0, 0);
		//axis(3.5);     // z-axis
		//glPopMatrix();




		/*glPushMatrix();
		glRotatef(rotAng, 0, 1, 0);
		glColor3f(0.0f, 0.0f, 0.0f);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glRotatef(-rotAng, 0, 1, 0);
		glTranslatef(2, 0, 0);
		glRotatef(rotAng, 1, 0, 0);
		glColor3f(0.5f, 0.5f, 0.5f);
		glutSolidSphere(0.5, 25, 25);
		glPopMatrix();*/

		//glColor3f(1, 0, 0);

		//glRotatef(0,0,0,1);
		//glScalef(2,1,2);
		//glBegin(GL_QUADS);
		/* Floor */
		//glColor3f(1, 0, 0);
		//glVertex3f(-1, -1, -1);
		//glVertex3f(1, -1, -1);
		//glVertex3f(1, -1, 1);
		//glVertex3f(-1, -1, 1);
		//glEnd();
		/* Ceiling */
		//glBegin(GL_QUADS);
		//glColor3f(1, 1, 0);
		//glVertex3f(-1, 1, -1);
		//glVertex3f(1, 1, -1);
		//glVertex3f(1, 1, 1);
		//glVertex3f(-1, 1, 1);
		//glEnd();
		/* Walls */
		/*glBegin(GL_QUADS);
		glColor3f(0, 0, 1);
		glVertex3f(-1, -1, 1);
		glVertex3f(1, -1, 1);
		glVertex3f(1, 1, 1);
		glVertex3f(-1, 1, 1);
		glEnd();*/
		glBegin(GL_QUADS);
		glColor3f(0, 0, 0);
		glVertex3f(-1, -1, -1);
		glVertex3f(1, -1, -1);
		glVertex3f(1, 1, -1);
		glVertex3f(-1, 1, -1);
		glEnd();
		//glBegin(GL_QUADS);
		//glColor3f(1, 0, 1);
		//glVertex3f(1, 1, 1);
		//glVertex3f(1, -1, 1);
		//glVertex3f(1, -1, -1);
		//glVertex3f(1, 1, -1);
		//glEnd();
		///glBegin(GL_QUADS);
		////glColor3f(0, 1, 1);
		///glVertex3f(-1, 1, 1);
		//glVertex3f(-1, -1, 1);
		//glVertex3f(-1, -1, -1);
		///glVertex3f(-1, 1, -1);
		//glEnd();





		/////////////////////////////////// celing


		int red = 0.6;
		int blue = 0;
		int green = 1;
		int counter = 0;
		float j = -1;
		for (float i = -0.6; i < 1; i = i + 0.4) {
			glBegin(GL_QUADS);
			glColor3f(red, green, blue);
			glVertex3f(j, 1, -1);
			glVertex3f(i, 1, -1);
			glVertex3f(i, 1, -0.6);
			glVertex3f(j, 1, -0.6);
			glEnd();
			j = j + 0.4;
			counter++;
			if (counter % 2 == 0) {
				blue = 0;
				green = 1;
				red = 0.6;


			}
			else {
				red = 0;
				blue = 1;
				green = 0;
			}


		}





		int red1 = 1;
		int blue1 = 0;
		int green1 = 0;
		int counter1 = 0;
		float j1 = -1;
		for (float i = -0.6; i < 1; i = i + 0.4) {
			glBegin(GL_QUADS);
			glColor3f(red1, green1, blue1);
			glVertex3f(j1, 1, -0.6);
			glVertex3f(i, 1, -0.6);
			glVertex3f(i, 1, -0.2);
			glVertex3f(j1, 1, -0.2);
			glEnd();
			counter1++;
			j1 = j1 + 0.4;
			if (counter1 % 2 == 0) {
				red1 = 1;
				blue1 = 0;
				green1 = 0;


			}
			else {
				red1 = 1;
				blue1 = 0;
				green1 = 1;
			}


		}



		int red2 = 0.6;
		int blue2 = 0;
		int green2 = 1;
		int counter2 = 0;
		float j2 = -1;
		for (float i = -0.6; i < 1; i = i + 0.4) {
			glBegin(GL_QUADS);
			glColor3f(red2, green2, blue2);
			glVertex3f(j2, 1, -0.2);
			glVertex3f(i, 1, -0.2);
			glVertex3f(i, 1, 0.2);
			glVertex3f(j2, 1, 0.2);
			glEnd();
			j2 = j2 + 0.4;
			counter2++;
			if (counter2 % 2 == 0) {
				blue2 = 0;
				green2 = 1;
				red2 = 0.6;


			}
			else {
				red2 = 0;
				blue2 = 1;
				green2 = 0;
			}


		}


		int red3 = 1;
		int blue3 = 0;
		int green3 = 0;
		int counter3 = 0;
		float j3 = -1;
		for (float i = -0.6; i < 1; i = i + 0.4) {
			glBegin(GL_QUADS);
			glColor3f(red3, green3, blue3);
			glVertex3f(j3, 1, 0.2);
			glVertex3f(i, 1, 0.2);
			glVertex3f(i, 1, 0.6);
			glVertex3f(j3, 1, 0.6);
			glEnd();
			counter3++;
			j3 = j3 + 0.4;
			if (counter3 % 2 == 0) {
				red3 = 1;
				blue3 = 0;
				green3 = 0;


			}
			else {
				red3 = 1;
				blue3 = 0;
				green3 = 1;
			}


		}


		int red4 = 0.6;
		int blue4 = 0;
		int green4 = 1;
		int counter4 = 0;
		float j4 = -1;
		for (float i = -0.6; i < 1; i = i + 0.4) {
			glBegin(GL_QUADS);
			glColor3f(red4, green4, blue4);
			glVertex3f(j4, 1, 0.6);
			glVertex3f(i, 1, 0.6);
			glVertex3f(i, 1, 1);
			glVertex3f(j4, 1, 1);
			glEnd();
			j4 = j4 + 0.4;
			counter4++;
			if (counter4 % 2 == 0) {
				blue4 = 0;
				green4 = 1;
				red4 = 0.6;


			}
			else {
				red4 = 0;
				blue4 = 1;
				green4 = 0;
			}


		}



		/////////////////////////////////////////////////////////////flooor 


		int red5 = 0.6;
		int blue5 = 0;
		int green5 = 1;
		int counter5 = 0;
		float j5 = -1;
		for (float i = -0.6; i < 1; i = i + 0.4) {
			glBegin(GL_QUADS);
			glColor3f(red5, green5, blue5);
			glVertex3f(j5, -1, -1);
			glVertex3f(i, -1, -1);
			glVertex3f(i, -1, -0.6);
			glVertex3f(j5, -1, -0.6);
			glEnd();
			j5 = j5 + 0.4;
			counter5++;
			if (counter5 % 2 == 0) {
				blue5 = 0;
				green5 = 1;
				red5 = 0.6;


			}
			else {
				red5 = 0;
				blue5 = 1;
				green5 = 0;
			}


		}





		int red6 = 1;
		int blue6 = 0;
		int green6 = 0;
		int counter6 = 0;
		float j6 = -1;
		for (float i = -0.6; i < 1; i = i + 0.4) {
			glBegin(GL_QUADS);
			glColor3f(red6, green6, blue6);
			glVertex3f(j6, -1, -0.6);
			glVertex3f(i, -1, -0.6);
			glVertex3f(i, -1, -0.2);
			glVertex3f(j6, -1, -0.2);
			glEnd();
			counter6++;
			j6 = j6 + 0.4;
			if (counter6 % 2 == 0) {
				red6 = 1;
				blue6 = 0;
				green6 = 0;


			}
			else {
				red6 = 1;
				blue6 = 0;
				green6 = 1;
			}


		}



		int red7 = 0.6;
		int blue7 = 0;
		int green7 = 1;
		int counter7 = 0;
		float j7 = -1;
		for (float i = -0.6; i < 1; i = i + 0.4) {
			glBegin(GL_QUADS);
			glColor3f(red7, green7, blue7);
			glVertex3f(j7, -1, -0.2);
			glVertex3f(i, -1, -0.2);
			glVertex3f(i, -1, 0.2);
			glVertex3f(j7, -1, 0.2);
			glEnd();
			j7 = j7 + 0.4;
			counter7++;
			if (counter7 % 2 == 0) {
				blue7 = 0;
				green7 = 1;
				red7 = 0.6;


			}
			else {
				red7 = 0;
				blue7 = 1;
				green7 = 0;
			}


		}


		int red8 = 1;
		int blue8 = 0;
		int green8 = 0;
		int counter8 = 0;
		float j8 = -1;
		for (float i = -0.6; i < 1; i = i + 0.4) {
			glBegin(GL_QUADS);
			glColor3f(red8, green8, blue8);
			glVertex3f(j8, -1, 0.2);
			glVertex3f(i, -1, 0.2);
			glVertex3f(i, -1, 0.6);
			glVertex3f(j8, -1, 0.6);
			glEnd();
			counter8++;
			j8 = j8 + 0.4;
			if (counter8 % 2 == 0) {
				red8 = 1;
				blue8 = 0;
				green8 = 0;


			}
			else {
				red8 = 1;
				blue8 = 0;
				green8 = 1;
			}


		}


		int red9 = 0.6;
		int blue9 = 0;
		int green9 = 1;
		int counter9 = 0;
		float j9 = -1;
		for (float i = -0.6; i < 1; i = i + 0.4) {
			glBegin(GL_QUADS);
			glColor3f(red9, green9, blue9);
			glVertex3f(j9, -1, 0.6);
			glVertex3f(i, -1, 0.6);
			glVertex3f(i, -1, 1);
			glVertex3f(j9, -1, 1);
			glEnd();
			j9 = j9 + 0.4;
			counter9++;
			if (counter9 % 2 == 0) {
				blue9 = 0;
				green9 = 1;
				red9 = 0.6;


			}
			else {
				red9 = 0;
				blue9 = 1;
				green9 = 0;
			}


		}

		//////////////////////////////////////////////////////// right wall





		int red10 = 1;
		int blue10 = 0;
		int green10 = 0;
		int counter10 = 0;
		float j10 = -1;
		for (float i = -0.6; i < 1; i = i + 0.4) {
			glBegin(GL_QUADS);
			glColor3f(red10, green10, blue10);
			glVertex3f(1, j10, 1);
			glVertex3f(1, i, 1);
			glVertex3f(1, i, 0.6);
			glVertex3f(1, j10, 0.6);
			glEnd();
			counter10++;
			j10 = j10 + 0.4;
			if (counter10 % 2 == 0) {
				red10 = 1;
				blue10 = 0;
				green10 = 0;


			}
			else {
				red10 = 1;
				blue10 = 0;
				green10 = 1;
			}


		}

		int red11 = 0.6;
		int blue11 = 0;
		int green11 = 1;
		int counter11 = 0;
		float j11 = -1;
		for (float i = -0.6; i < 1; i = i + 0.4) {
			glBegin(GL_QUADS);
			glColor3f(red11, green11, blue11);
			glVertex3f(1, j11, 0.6);
			glVertex3f(1, i, 0.6);
			glVertex3f(1, i, 0.2);
			glVertex3f(1, j11, 0.2);
			glEnd();
			j11 = j11 + 0.4;
			counter11++;
			if (counter11 % 2 == 0) {
				blue11 = 0;
				green11 = 1;
				red11 = 0.6;


			}
			else {
				red11 = 0;
				blue11 = 1;
				green11 = 0;
			}


		}


		int red12 = 1;
		int blue12 = 0;
		int green12 = 0;
		int counter12 = 0;
		float j12 = -1;
		for (float i = -0.6; i < 1; i = i + 0.4) {
			glBegin(GL_QUADS);
			glColor3f(red12, green12, blue12);
			glVertex3f(1, j12, 0.2);
			glVertex3f(1, i, 0.2);
			glVertex3f(1, i, -0.2);
			glVertex3f(1, j12, -0.2);
			glEnd();
			counter12++;
			j12 = j12 + 0.4;
			if (counter12 % 2 == 0) {
				red12 = 1;
				blue12 = 0;
				green12 = 0;


			}
			else {
				red12 = 1;
				blue12 = 0;
				green12 = 1;
			}


		}


		int red13 = 0.6;
		int blue13 = 0;
		int green13 = 1;
		int counter13 = 0;
		float j13 = -1;
		for (float i = -0.6; i < 1; i = i + 0.4) {
			glBegin(GL_QUADS);
			glColor3f(red13, green13, blue13);
			glVertex3f(1, j13, -0.2);
			glVertex3f(1, i, -0.2);
			glVertex3f(1, i, -0.6);
			glVertex3f(1, j13, -0.6);
			glEnd();
			j13 = j13 + 0.4;
			counter13++;
			if (counter13 % 2 == 0) {
				blue13 = 0;
				green13 = 1;
				red13 = 0.6;


			}
			else {
				red13 = 0;
				blue13 = 1;
				green13 = 0;
			}


		}


		int red14 = 1;
		int blue14 = 0;
		int green14 = 0;
		int counter14 = 0;
		float j14 = -1;
		for (float i = -0.6; i < 1; i = i + 0.4) {
			glBegin(GL_QUADS);
			glColor3f(red14, green14, blue14);
			glVertex3f(1, j14, -0.6);
			glVertex3f(1, i, -0.6);
			glVertex3f(1, i, -1);
			glVertex3f(1, j14, -1);
			glEnd();
			counter14++;
			j14 = j14 + 0.4;
			if (counter14 % 2 == 0) {
				red14 = 1;
				blue14 = 0;
				green14 = 0;


			}
			else {
				red14 = 1;
				blue14 = 0;
				green14 = 1;
			}


		}

		//////////////////////////////////////////////////////// left side




		int red15 = 1;
		int blue15 = 0;
		int green15 = 0;
		int counter15 = 0;
		float j15 = -1;
		for (float i = -0.6; i < 1; i = i + 0.4) {
			glBegin(GL_QUADS);
			glColor3f(red15, green15, blue15);
			glVertex3f(-1, j15, 1);
			glVertex3f(-1, i, 1);
			glVertex3f(-1, i, 0.6);
			glVertex3f(-1, j15, 0.6);
			glEnd();
			counter15++;
			j15 = j15 + 0.4;
			if (counter15 % 2 == 0) {
				red15 = 1;
				blue15 = 0;
				green15 = 0;


			}
			else {
				red15 = 1;
				blue15 = 0;
				green15 = 1;
			}


		}

		int red16 = 0.6;
		int blue16 = 0;
		int green16 = 1;
		int counter16 = 0;
		float j16 = -1;
		for (float i = -0.6; i < 1; i = i + 0.4) {
			glBegin(GL_QUADS);
			glColor3f(red16, green16, blue16);
			glVertex3f(-1, j16, 0.6);
			glVertex3f(-1, i, 0.6);
			glVertex3f(-1, i, 0.2);
			glVertex3f(-1, j16, 0.2);
			glEnd();
			j16 = j16 + 0.4;
			counter16++;
			if (counter16 % 2 == 0) {
				blue16 = 0;
				green16 = 1;
				red16 = 0.6;


			}
			else {
				red16 = 0;
				blue16 = 1;
				green16 = 0;
			}


		}


		int red17 = 1;
		int blue17 = 0;
		int green17 = 0;
		int counter17 = 0;
		float j17 = -1;
		for (float i = -0.6; i < 1; i = i + 0.4) {
			glBegin(GL_QUADS);
			glColor3f(red17, green17, blue17);
			glVertex3f(-1, j17, 0.2);
			glVertex3f(-1, i, 0.2);
			glVertex3f(-1, i, -0.2);
			glVertex3f(-1, j17, -0.2);
			glEnd();
			counter17++;
			j17 = j17 + 0.4;
			if (counter17 % 2 == 0) {
				red17 = 1;
				blue17 = 0;
				green17 = 0;


			}
			else {
				red17 = 1;
				blue17 = 0;
				green17 = 1;
			}


		}


		int red18 = 0.6;
		int blue18 = 0;
		int green18 = 1;
		int counter18 = 0;
		float j18 = -1;
		for (float i = -0.6; i < 1; i = i + 0.4) {
			glBegin(GL_QUADS);
			glColor3f(red18, green18, blue18);
			glVertex3f(-1, j18, -0.2);
			glVertex3f(-1, i, -0.2);
			glVertex3f(-1, i, -0.6);
			glVertex3f(-1, j18, -0.6);
			glEnd();
			j18 = j18 + 0.4;
			counter18++;
			if (counter18 % 2 == 0) {
				blue18 = 0;
				green18 = 1;
				red18 = 0.6;


			}
			else {
				red18 = 0;
				blue18 = 1;
				green18 = 0;
			}


		}


		int red19 = 1;
		int blue19 = 0;
		int green19 = 0;
		int counter19 = 0;
		float j19 = -1;
		for (float i = -0.6; i < 1; i = i + 0.4) {
			glBegin(GL_QUADS);
			glColor3f(red19, green19, blue19);
			glVertex3f(-1, j19, -0.6);
			glVertex3f(-1, i, -0.6);
			glVertex3f(-1, i, -1);
			glVertex3f(-1, j19, -1);
			glEnd();
			counter19++;
			j19 = j19 + 0.4;
			if (counter19 % 2 == 0) {
				red19 = 1;
				blue19 = 0;
				green19 = 0;


			}
			else {
				red19 = 1;
				blue19 = 0;
				green19 = 1;
			}


		}
		//////////////////////////////////////////
		/*glPushMatrix();
		glColor3f(1, 0.4, 0);

		glTranslated(0, 0, 2.5);
		glutSolidCone(0.1, 0.4, 12, 9);
		glPopMatrix();*/


		glPushMatrix();
		glColor3f(0.6, 0.6, 0.6);

		glTranslated(xo, yo, zo);

		//
		glutSolidSphere(0.03, 10, 10);

		glPopMatrix();



		/*
			glPushMatrix();
			glColor3f(0.6, 0.6, 0.6);
			glTranslated(0, -1, 2.8);

			glutSolidSphere(0.08, 10, 10);

			glPopMatrix();*/


			//glVertex3f(-1, -1, -1);
			//glVertex3f(1, -1, -1);
			//glVertex3f(1, 1, -1);
			//glVertex3f(-1, 1, -1); 


		//glBegin(GL_LINES);
		////glRotated(rotAng, 0, 1.0, 0);
		//glColor3f(1, 0, 0);
		//glVertex3d(0, 0, 2.5);
		//glVertex3d(0, 0, 2.3); // along the z-axis 
		//glEnd();
		//glPopMatrix();

		if (show == false) {
			glPushMatrix();
			glColor3f(0.6, 0.6, 0.6);
			glTranslated(0, 0, 2.3);
			glRotated(rotAng, 0, 1, 0);
			glRotated(rotAng2, 1, 0, 0);
			glutWireCone(0.04, 0.2, 12, 9);

			glPopMatrix();

		}


		glColor3f(1, 1, 1);
		stringstream strs;
		strs << score;
		string temp_str = strs.str();
		char* final = (char*)temp_str.c_str();

		//print(-0.9, 0, "Score   : ");

		print(0, 0, final);




		//setupCamera();










		glFlush();

	}
}

void Anim() {
	if (center1 == true) {
		show = true;
		zo = zo - speedz;
		c3 = c3 - 0.003;
		if (zo <= -1)
		{
			center1 = false;
			keyy = false;

		}


	}

	if (center2 == true) {


		show = true;


		zo = zo - speedz;
		xo = xo + speedx;

		c3 = c3 - 0.003;
		c1 = c1 - 0.0001;

		if (zo <= -1 || xo >= 1)
		{
			center2 = false;
			keyy = false;



		}

	}
	if (center3 == true) {
		show = true;
		zo = zo - speedz;
		xo = xo - speedx;

		c3 = c3 - 0.003;
		c1 = c1 + 0.0001;
		if (zo <= -1 || xo <= -1)
		{
			center3 = false;
			keyy = false;


		}

	}

	if (right1 == true) {
		if (down == true) {
			yo = -0.4;
			down = false;
			tt = true;
			c2 = -0.1;


		}
		if (down2 == true) {
			yo = +0.4;
			down2 = false;
			ff = true;
			flip = false;
			c2 = 0.2;

		}
		show = true;
		xo = xo + speedx1;
		zo = zo - speedz1;
		c1 = c1 - 0.0001;
		c3 = c3 - 0.00001;
		l1 = l1 + 0.0003;
		l3 = l3 - 0.0009;
		if (zo <= -1 || xo >= 0.9)
		{
			right1 = false;
			right2 = true;



			if (tt == true) {
				right2 = false;
				right4 = true;
			}

			if (tt == true) {
				if (cr9 == 0) {
					totalscore = totalscore + yellows;
					score = score + yellows;
					cr9 = cr5 + 1;
					bcr9 = true;
					not= true;
				}


			}
			if (ff == true) {
				if (cr5 == 0) {
					totalscore = totalscore + yellows;
					score = score + yellows;
					cr5 = cr5 + 1;
					bcr5 = true;
					not= true;
				}


			}


			if (not== false) {
				if (cr1 == 0) {
					totalscore = totalscore + reds;
					score = score + reds;
					cr1 = cr1 + 1;
					bcr1 = true;
				}

			}


		}



	}

	if (right12 == true) {
		if (down == true) {
			yo = -0.4;
			down = false;
			tt = true;
			c2 = -0.1;

		}
		if (down2 == true) {
			yo = 0.4;
			down2 = false;
			ff = true;
			flip = false;
			c2 = 0.2;

		}
		show = true;
		xo = xo + speedx3;
		zo = zo - 0.0018;

		c1 = c1 - 0.0001;
		c3 = c3 - 0.0004;
		l1 = l1 + 0.0004;
		l3 = l3 - 0.001;




		if (zo <= -1 || xo >= 0.9)
		{
			right12 = false;
			right2 = true;

			if (tt == true) {
				right2 = false;
				right4 = true;
			}

			if (ff == true) {
				if (cr6 == 0) {
					totalscore = totalscore + blues;
					score = score + blues;
					cr6 = cr6 + 1;
					bcr6 = true;
					not= true;
				}


			}


			if (tt == true) {
				if (cr10 == 0) {
					totalscore = totalscore + blues;
					score = score + blues;
					cr10 = cr10 + 1;
					bcr10 = true;
					not= true;
				}


			}



			if (not== false) {
				if (cr2 == 0) {
					totalscore = totalscore + greens;
					score = score + greens;
					cr2 = cr2 + 1;
					bcr2 = true;
				}
			}

		}


	}

	if (right13 == true) {
		if (down == true) {
			yo = -0.4;
			down = false;
			tt = true;
			c2 = -0.1;

		}
		if (down2 == true) {
			yo = 0.4;
			down2 = false;
			ff = true;
			flip = false;
			c2 = 0.2;

		}
		show = true;
		c1 = c1 - 0.0001;
		c3 = c3 - 0.0009;
		xo = xo + speedx4;
		zo = zo - 0.0024;
		//float speedz4 = 0.0023;
		l1 = l1 + 0.0005;
		l3 = l3 - 0.001;

		if (zo <= -1 || xo >= 0.9)
		{
			right13 = false;
			right2 = true;
			if (tt == true) {
				right2 = false;
				right4 = true;
			}

			if (ff == true) {
				if (cr7 == 0) {
					totalscore = totalscore + blues;
					score = score + blues;
					cr7 = cr7 + 1;
					bcr7 = true;
					not= true;
				}


			}
			if (tt == true) {
				if (cr11 == 0) {
					totalscore = totalscore + blues;
					score = score + blues;
					cr11 = cr11 + 1;
					bcr11 = true;
					not= true;
				}


			}

			if (not== false) {

				if (cr3 == 0) {
					totalscore = totalscore + reds;
					score = score + reds;
					cr3 = cr3 + 1;
					bcr3 = true;
				}
			}








		}


	}

	if (right14 == true) {
		if (down == true) {
			yo = -0.4;
			down = false;
			tt = true;
			c2 = -0.1;

		}
		if (down2 == true) {
			yo = 0.4;
			down2 = false;
			ff = true;
			flip = false;
			c2 = 0.2;

		}
		show = true;
		c1 = c1 - 0.0001;
		c3 = c3 - 0.001;
		xo = xo + speedx5;
		zo = zo - speedz5;
		l1 = l1 + 0.00053;
		l3 = l3 - 0.009;
		if (zo <= -1 || xo >= 0.9)
		{
			right14 = false;
			right2 = true;
			if (tt == true) {
				right2 = false;
				right4 = true;
			}

			if (ff == true) {
				if (cr8 == 0) {
					totalscore = totalscore + yellows;
					score = score + yellows;
					cr8 = cr8 + 1;
					bcr8 = true;
					not= true;
				}


			}

			if (tt == true) {
				if (cr12 == 0) {
					totalscore = totalscore + yellows;
					score = score + yellows;
					cr12 = cr12 + 1;
					bcr12 = true;
					not= true;
				}


			}

			if (not== false) {
				if (cr4 == 0) {
					totalscore = totalscore + reds;
					score = score + reds;
					cr4 = cr4 + 1;
					bcr4 = true;
				}

			}
		}


	}




	if (right2 == true) {

		xo = xo - speedx2;
		l1 = l1 - 0.002;
		c1 = c1 + 0.0009;

		if (xo < -0.9)
		{

			right2 = false;
			right3 = true;

			if (ff == true)
			{
				right2 = false;
				right3 = false;
				right5 = true;
			}

			if (zo <= -0.8) {
				right3 = false;
				right5 = false;
				right2 = false;
				bcr1 = false;
				bcr2 = false;
				bcr3 = false;
				bcr4 = false;
				bcr5 = false;
				bcr6 = false;
				bcr7 = false;
				bcr8 = false;
				not= false;
				ff = false;
				keyy = false;


			}
			if (bcr1 == true) {

				if (cr1 == 2 || cr1 == 3 || cr1 == 6 || cr1 == 7) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr1 == 1 || cr1 == 4 || cr1 == 5 || cr1 == 8 || cr1 == 9) {
					score = score + reds;
					totalscore = totalscore + reds;
				}

				cr1++;

			}

			if (bcr2 == true) {

				if (cr2 == 2 || cr2 == 3 || cr2 == 6 || cr2 == 7) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr2 == 1 || cr2 == 4 || cr2 == 5) {
					score = score + greens;
					totalscore = totalscore + greens;
				}

				cr2++;

			}



			if (bcr3 == true) {

				if (cr3 == 2 || cr3 == 3) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr3 == 1 || cr3 == 4 || cr3 == 5) {
					score = score + reds;
					totalscore = totalscore + reds;
				}

				cr3++;

			}

			if (bcr4 == true) {


				if (cr4 == 1) {
					score = score + reds;
					totalscore = totalscore + reds;
				}

				cr4++;

			}

			if (bcr5 == true) {

				if (cr5 == 2 || cr5 == 3 || cr5 == 6 || cr5 == 7) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr5 == 1 || cr5 == 4 || cr5 == 5 || cr5 == 8 || cr5 == 9) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}

				cr5++;

			}


			if (bcr6 == true) {

				if (cr6 == 2 || cr6 == 3 || cr6 == 6 || cr6 == 7) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr6 == 1 || cr6 == 4 || cr6 == 5) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr6++;

			}

			if (bcr7 == true) {

				if (cr7 == 2 || cr7 == 3) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr7 == 1) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr7++;

			}


			if (bcr8 == true) {


				if (cr8 == 1) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}

				cr8++;

			}






		}





	}

	if (right3 == true) {
		if (tt == true) {
			xo = xo + 0.004;
			zo = zo - 0.0007;

		}
		else {
			xo = xo + speedx2;
			zo = zo - speedz2;
		}
		l1 = l1 + 0.0021;
		l3 = l3 - 0.001;
		if (tt == true) {
			c1 = c1 - 0.0003;
			c3 = c3 - 0.0007;
		}
		else {
			c1 = c1 - 0.0009;
			c3 = c3 - 0.0009;
		}
		if (xo > 0.9)
		{

			right3 = false;
			right2 = true;
			if (tt == true) {
				if (flip2 == false) {
					right7 = true;
				}
				else {
					right4 = true;
				}
				right2 = false;
			}


			if (zo <= -0.8) {
				right3 = false;
				right2 = false;
				bcr1 = false;
				bcr2 = false;
				bcr3 = false;
				bcr4 = false;
				keyy = false;

			}
			if (tt == true) {
				if (zo <= -0.6) {
					right7 = false;
					right4 = false;
					tt = false;
					keyy = false;
				}

			}

			if (bcr1 == true) {
				if (cr1 == 2 || cr1 == 3 || cr1 == 6 || cr1 == 7) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr1 == 1 || cr1 == 4 || cr1 == 5 || cr1 == 8 || cr1 == 9) {
					score = score + reds;
					totalscore = totalscore + reds;
				}

				cr1++;
			}

			if (bcr2 == true) {

				if (cr2 == 2 || cr2 == 3 || cr2 == 6 || cr2 == 7) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr2 == 1 || cr2 == 4 || cr2 == 5) {
					score = score + greens;
					totalscore = totalscore + greens;
				}

				cr2++;

			}


			if (bcr3 == true) {

				if (cr3 == 2 || cr3 == 3) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr3 == 1 || cr3 == 4 || cr3 == 5) {
					score = score + reds;
					totalscore = totalscore + reds;
				}

				cr3++;

			}

			if (bcr4 == true) {


				if (cr4 == 1) {
					score = score + reds;
					totalscore = totalscore + reds;
				}

				cr4++;

			}

			if (bcr9 == true) {

				if (cr9 == 2 || cr9 == 6 || cr9 == 8 || cr9 == 12 || cr9 == 14) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr9 == 1 || cr9 == 4 || cr9 == 10 || cr9 == 13) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr9 == 7) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr9 == 5 || cr9 == 3 || cr9 == 9 || cr9 == 11) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr9++;

			}


			if (bcr10 == true) {

				if (cr10 == 3 || cr10 == 5 || cr10 == 9 || cr10 == 11) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr10 == 7) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr10 == 1 || cr10 == 4 || cr10 == 10) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr10 == 2 || cr10 == 6 || cr10 == 8) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr10++;

			}



			if (bcr11 == true) {

				if (cr11 == 3 || cr11 == 5) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr11 == 1) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr11 == 4) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr11 == 2) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr11++;

			}

			if (bcr12 == true) {

				if (cr12 == 3) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}

				if (cr12 == 4) {
					score = score + greens;
					totalscore = totalscore + greens;
				}


				cr12++;

			}
















		}


	}




	if (right4 == true) {


		xo = xo - 0.0033;
		yo = yo + 0.005;



		c1 = c1 + 0.0003;
		c2 = c2 + 0.001;

		l1 = l1 - 0.0005;
		l2 = l2 + 0.0006;

		if (yo > 0.9)
		{
			flip2 = false;
			right4 = false;
			right6 = true;


			if (bcr9 == true) {

				if (cr9 == 2 || cr9 == 6 || cr9 == 8 || cr9 == 12 || cr9 == 14) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr9 == 1 || cr9 == 4 || cr9 == 10 || cr9 == 13) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr9 == 7) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr9 == 5 || cr9 == 3 || cr9 == 9 || cr9 == 11) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr9++;

			}


			if (bcr10 == true) {

				if (cr10 == 3 || cr10 == 5 || cr10 == 9 || cr10 == 11) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr10 == 7) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr10 == 1 || cr10 == 4 || cr10 == 10) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr10 == 2 || cr10 == 6 || cr10 == 8) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr10++;

			}



			if (bcr11 == true) {

				if (cr11 == 3 || cr11 == 5) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr11 == 1) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr11 == 4) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr11 == 2) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr11++;

			}

			if (bcr12 == true) {

				if (cr12 == 3) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}

				if (cr12 == 4) {
					score = score + greens;
					totalscore = totalscore + greens;
				}


				cr12++;

			}




			if (zo <= -0.6) {
				right6 = false;
				tt = false;
				bcr9 = false;
				bcr10 = false;
				bcr11 = false;
				bcr12 = false;
				keyy = false;
			}


		}



	}

	if (right6 == true) {
		xo = xo - 0.003;
		yo = yo - 0.0043;
		c1 = c1 + 0.0003;
		c2 = c2 - 0.001;

		l1 = l1 - 0.002;
		l2 = l2 - 0.0006;
		if (xo < -0.9)
		{
			right6 = false;
			right3 = true;


			if (bcr9 == true) {

				if (cr9 == 2 || cr9 == 6 || cr9 == 8 || cr9 == 12 || cr9 == 14) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr9 == 1 || cr9 == 4 || cr9 == 10 || cr9 == 13) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr9 == 7) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr9 == 5 || cr9 == 3 || cr9 == 9 || cr9 == 11) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr9++;

			}

			if (bcr10 == true) {

				if (cr10 == 3 || cr10 == 5 || cr10 == 9 || cr10 == 11) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr10 == 7) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr10 == 1 || cr10 == 4 || cr10 == 10) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr10 == 2 || cr10 == 6 || cr10 == 8) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr10++;

			}

			if (bcr11 == true) {

				if (cr11 == 3 || cr11 == 5) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr11 == 1) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr11 == 4) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr11 == 2) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr11++;

			}




			if (zo < -0.6) {
				right3 = false;
				tt = false;
				bcr9 = false;
				bcr10 = false;
				bcr11 = false;
				bcr12 = false;
				keyy = false;

			}
		}



	}

	if (right7 == true) {
		xo = xo - 0.002;
		yo = yo - 0.001;
		c1 = c1 + 0.0002;
		c2 = c2 - 0.0001;

		l1 = l1 - 0.0005;
		l2 = l2 - 0.0006;
		if (yo < -0.9)
		{
			flip2 = true;
			right7 = false;
			right8 = true;

			if (bcr9 == true) {

				if (cr9 == 2 || cr9 == 6 || cr9 == 8 || cr9 == 12 || cr9 == 14) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr9 == 1 || cr9 == 4 || cr9 == 10 || cr9 == 13) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr9 == 7) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr9 == 5 || cr9 == 3 || cr9 == 9 || cr9 == 11) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr9++;

			}



			if (bcr10 == true) {

				if (cr10 == 3 || cr10 == 5 || cr10 == 9 || cr10 == 11) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr10 == 7) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr10 == 1 || cr10 == 4 || cr10 == 10) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr10 == 2 || cr10 == 6 || cr10 == 8) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr10++;

			}

			if (bcr11 == true) {

				if (cr11 == 3 || cr11 == 5) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr11 == 1) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr11 == 4) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr11 == 2) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr11++;

			}









			if (zo < -0.6) {
				right8 = false;
				tt = false;
				bcr9 = false;
				bcr10 = false;
				bcr12 = false;
				bcr11 = false;
				keyy = false;
			}
		}


	}
	if (right8 == true) {
		xo = xo - 0.003;
		yo = yo + 0.002;
		c1 = c1 + 0.0003;
		c2 = c2 + 0.0008;

		l1 = l1 - 0.003;
		l2 = l2 + 0.0006;

		if (xo < -0.9)
		{
			right8 = false;
			right3 = true;

			if (bcr9 == true) {

				if (cr9 == 2 || cr9 == 6 || cr9 == 8 || cr9 == 12 || cr9 == 14) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr9 == 1 || cr9 == 4 || cr9 == 10 || cr9 == 13) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr9 == 7) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr9 == 5 || cr9 == 3 || cr9 == 9 || cr9 == 11) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr9++;

			}


			if (bcr10 == true) {

				if (cr10 == 3 || cr10 == 5 || cr10 == 9 || cr10 == 11) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr10 == 7) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr10 == 1 || cr10 == 4 || cr10 == 10) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr10 == 2 || cr10 == 6 || cr10 == 8) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr10++;

			}



			if (bcr11 == true) {

				if (cr11 == 3 || cr11 == 5) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr11 == 1) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr11 == 4) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr11 == 2) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr11++;

			}







			if (zo < -0.6) {
				right3 = false;
				tt = false;
				bcr9 = false;
				bcr10 = false;
				bcr10 = false;
				keyy = false;

			}

		}


	}


	if (right5 == true) {


		xo = xo + speedx2;
		zo = zo - speedz2;

		c1 = c1 - 0.0009;
		c3 = c3 - 0.0009;

		l1 = l1 + 0.0021;
		l3 = l3 - 0.0008;

		if (flip == false) {
			yo = yo + speedy;
			c2 = c2 + 0.0008;

		}

		else {
			if (flip == true)
				yo = yo - speedy;
			c2 = c2 - 0.001;


		}




		if (xo > 0.9)
		{

			right5 = false;
			right2 = true;

			if (flip == false) {


				flip = true;
			}
			else {
				if (flip == true) {

					flip = false;
				}
			}

			if (zo <= -0.8) {
				ff = false;
				right5 = false;
				right2 = false;
				bcr5 = false;
				bcr6 = false;
				bcr7 = false;
				bcr8 = false;
				not= false;
				keyy = false;

			}

			if (bcr5 == true) {

				if (cr5 == 2 || cr5 == 3 || cr5 == 6 || cr5 == 7) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr5 == 1 || cr5 == 4 || cr5 == 5 || cr5 == 8 || cr5 == 9) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}

				cr5++;

			}



			if (bcr6 == true) {

				if (cr6 == 2 || cr6 == 3 || cr6 == 6 || cr6 == 7) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr6 == 1 || cr6 == 4 || cr6 == 5) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr6++;

			}

			if (bcr7 == true) {

				if (cr7 == 2 || cr7 == 3) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr7 == 1) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr7++;

			}







		}



	}





	if (left1 == true) {

		if (down2 == true) {
			yo = 0.4;
			down2 = false;
			ff = true;
			flip = false;
			c2 = 0.2;

		}
		if (down == true) {
			yo = -0.4;
			down = false;
			tt = true;
			c2 = -0.1;

		}
		show = true;
		c1 = c1 + 0.0001;
		c3 = c3 - 0.00001;

		xo = xo - speedx1;
		zo = zo - speedz1;
		l1 = l1 - 0.0003;
		l3 = l3 - 0.0009;
		if (zo <= -1 || xo <= -0.9)
		{
			left1 = false;
			left2 = true;

			if (tt == true) {
				left2 = false;
				left4 = true;
			}

			if (tt == true) {
				if (cr9 == 0) {
					totalscore = totalscore + yellows;
					score = score + yellows;
					cr9 = cr5 + 1;
					bcr9 = true;
					not= true;
				}


			}
			if (ff == true) {
				if (cr5 == 0) {
					totalscore = totalscore + yellows;
					score = score + yellows;
					cr5 = cr5 + 1;
					bcr5 = true;
					not= true;
				}


			}


			if (not== false) {
				if (cr1 == 0) {
					totalscore = totalscore + reds;
					score = score + reds;
					cr1 = cr1 + 1;
					bcr1 = true;
				}

			}























		}


	}

	if (left2 == true) {

		xo = xo + speedx2;
		c1 = c1 - 0.0009;
		l1 = l1 + 0.0021;
		if (xo > 0.9)
		{

			left2 = false;
			left3 = true;

			if (ff == true)
			{
				left2 = false;
				left3 = false;
				left5 = true;

			}

			if (bcr1 == true) {

				if (cr1 == 2 || cr1 == 3 || cr1 == 6 || cr1 == 7) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr1 == 1 || cr1 == 4 || cr1 == 5 || cr1 == 8 || cr1 == 9) {
					score = score + reds;
					totalscore = totalscore + reds;
				}

				cr1++;

			}

			if (bcr2 == true) {

				if (cr2 == 2 || cr2 == 3 || cr2 == 6 || cr2 == 7) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr2 == 1 || cr2 == 4 || cr2 == 5) {
					score = score + greens;
					totalscore = totalscore + greens;
				}

				cr2++;

			}



			if (bcr3 == true) {

				if (cr3 == 2 || cr3 == 3) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr3 == 1 || cr3 == 4 || cr3 == 5) {
					score = score + reds;
					totalscore = totalscore + reds;
				}

				cr3++;

			}

			if (bcr4 == true) {


				if (cr4 == 1) {
					score = score + reds;
					totalscore = totalscore + reds;
				}

				cr4++;

			}

			if (bcr5 == true) {

				if (cr5 == 2 || cr5 == 3 || cr5 == 6 || cr5 == 7) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr5 == 1 || cr5 == 4 || cr5 == 5 || cr5 == 8 || cr5 == 9) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}

				cr5++;

			}


			if (bcr6 == true) {

				if (cr6 == 2 || cr6 == 3 || cr6 == 6 || cr6 == 7) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr6 == 1 || cr6 == 4 || cr6 == 5) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr6++;

			}

			if (bcr7 == true) {

				if (cr7 == 2 || cr7 == 3) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr7 == 1) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr7++;

			}


			if (bcr8 == true) {


				if (cr8 == 1) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}

				cr8++;

			}





			if (zo <= -0.8) {
				left3 = false;
				ff = false;
				bcr1 = false;
				bcr2 = false;
				bcr3 = false;
				bcr4 = false;
				bcr5 = false;
				bcr6 = false;
				bcr7 = false;
				bcr8 = false;
				not= false;
				ff = false;
				keyy = false;


			}

		}



	}

	if (left3 == true) {

		if (tt == true) {
			xo = xo - 0.004;
			zo = zo - 0.0007;

		}
		else {
			xo = xo - speedx2;
			zo = zo - speedz2;
		}
		l1 = l1 - 0.0021;
		l3 = l3 - 0.001;
		if (tt == true) {
			c1 = c1 + 0.0003;
			c3 = c3 - 0.0007;
		}
		else {
			c1 = c1 + 0.0009;
			c3 = c3 - 0.0009;
		}



		if (xo < -0.9)
		{

			left3 = false;
			left2 = true;
			if (tt == true) {
				if (flip2 == false) {
					left7 = true;
				}
				else {
					left4 = true;
				}
				left2 = false;
			}
			if (zo <= -0.8) {
				left2 = false;
				left3 = false;
				right3 = false;
				right2 = false;
				bcr1 = false;
				bcr2 = false;
				bcr3 = false;
				bcr4 = false;
				keyy = false;

			}

			if (tt == true) {
				if (zo <= -0.6) {
					left3 = false;
					left7 = false;
					left4 = false;
					tt = false;
					keyy = false;
				}

			}

			if (bcr1 == true) {
				if (cr1 == 2 || cr1 == 3 || cr1 == 6 || cr1 == 7) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr1 == 1 || cr1 == 4 || cr1 == 5 || cr1 == 8 || cr1 == 9) {
					score = score + reds;
					totalscore = totalscore + reds;
				}

				cr1++;
			}

			if (bcr2 == true) {

				if (cr2 == 2 || cr2 == 3 || cr2 == 6 || cr2 == 7) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr2 == 1 || cr2 == 4 || cr2 == 5) {
					score = score + greens;
					totalscore = totalscore + greens;
				}

				cr2++;

			}


			if (bcr3 == true) {

				if (cr3 == 2 || cr3 == 3) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr3 == 1 || cr3 == 4 || cr3 == 5) {
					score = score + reds;
					totalscore = totalscore + reds;
				}

				cr3++;

			}

			if (bcr4 == true) {


				if (cr4 == 1) {
					score = score + reds;
					totalscore = totalscore + reds;
				}

				cr4++;

			}

			if (bcr9 == true) {

				if (cr9 == 2 || cr9 == 6 || cr9 == 8 || cr9 == 12 || cr9 == 14) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr9 == 1 || cr9 == 4 || cr9 == 10 || cr9 == 13) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr9 == 7) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr9 == 5 || cr9 == 3 || cr9 == 9 || cr9 == 11) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr9++;

			}


			if (bcr10 == true) {

				if (cr10 == 3 || cr10 == 5 || cr10 == 9 || cr10 == 11) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr10 == 7) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr10 == 1 || cr10 == 4 || cr10 == 10) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr10 == 2 || cr10 == 6 || cr10 == 8) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr10++;

			}



			if (bcr11 == true) {

				if (cr11 == 3 || cr11 == 5) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr11 == 1) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr11 == 4) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr11 == 2) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr11++;

			}

			if (bcr12 == true) {

				if (cr12 == 3) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}

				if (cr12 == 4) {
					score = score + greens;
					totalscore = totalscore + greens;
				}


				cr12++;

			}






		}



	}
	if (left5 == true) {


		xo = xo - speedx2;
		zo = zo - speedz2;
		c1 = c1 + 0.0009;
		c3 = c3 - 0.0009;
		l1 = l1 - 0.0021;
		l3 = l3 - 0.0008;
		if (flip == false) {
			yo = yo + speedy;
			c2 = c2 + 0.0008;


		}

		else {
			if (flip == true)
				yo = yo - speedy;
			c2 = c2 - 0.001;
		}




		if (xo < -0.9)
		{

			left5 = false;
			left2 = true;

			if (flip == false) {


				flip = true;
			}
			else {
				if (flip == true) {

					flip = false;
				}
			}
			if (bcr5 == true) {

				if (cr5 == 2 || cr5 == 3 || cr5 == 6 || cr5 == 7) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr5 == 1 || cr5 == 4 || cr5 == 5 || cr5 == 8 || cr5 == 9) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}

				cr5++;

			}



			if (bcr6 == true) {

				if (cr6 == 2 || cr6 == 3 || cr6 == 6 || cr6 == 7) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr6 == 1 || cr6 == 4 || cr6 == 5) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr6++;

			}

			if (bcr7 == true) {

				if (cr7 == 2 || cr7 == 3) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr7 == 1) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr7++;

			}


			if (zo <= -0.8) {
				left5 = false;
				left2 = false;
				ff = false;
				bcr5 = false;
				bcr6 = false;
				bcr7 = false;
				bcr8 = false;
				not= false;
				keyy = false;
				tt = false;

			}

		}



	}

	if (left14 == true) {
		if (down == true) {
			yo = -0.4;
			down = false;
			tt = true;
			c2 = -0.1;

		}

		if (down2 == true) {
			yo = 0.4;
			down2 = false;
			ff = true;
			flip = false;
			c2 = 0.2;

		}
		show = true;

		zo = zo - 0.0018;
		xo = xo - speedx3;

		c1 = c1 + 0.0001;
		c3 = c3 - 0.0004;
		l1 = l1 - 0.0004;
		l3 = l3 - 0.001;

		if (zo <= -1 || xo <= -0.9)
		{
			left14 = false;
			left2 = true;
			if (tt == true) {
				left2 = false;
				left4 = true;
			}
			if (ff == true) {
				if (cr6 == 0) {
					totalscore = totalscore + blues;
					score = score + blues;
					cr6 = cr6 + 1;
					bcr6 = true;
					not= true;
				}


			}


			if (tt == true) {
				if (cr10 == 0) {
					totalscore = totalscore + blues;
					score = score + blues;
					cr10 = cr10 + 1;
					bcr10 = true;
					not= true;
				}


			}



			if (not== false) {
				if (cr2 == 0) {
					totalscore = totalscore + greens;
					score = score + greens;
					cr2 = cr2 + 1;
					bcr2 = true;
				}
			}


		}
	}

	if (left13 == true) {
		if (down == true) {
			yo = -0.4;
			down = false;
			tt = true;
			c2 = -0.1;

		}
		if (down2 == true) {
			yo = 0.4;
			down2 = false;
			ff = true;
			flip = false;
			c2 = 0.2;

		}
		show = true;
		c1 = c1 + 0.0001;
		c3 = c3 - 0.0009;
		xo = xo - speedx4;
		zo = zo - 0.0024;
		l1 = l1 - 0.0005;
		l3 = l3 - 0.001;
		if (zo <= -1 || xo <= -0.9)
		{
			left13 = false;
			left2 = true;
			if (tt == true) {
				left2 = false;
				left4 = true;
			}


			if (ff == true) {
				if (cr7 == 0) {
					totalscore = totalscore + blues;
					score = score + blues;
					cr7 = cr7 + 1;
					bcr7 = true;
					not= true;
				}


			}
			if (tt == true) {
				if (cr11 == 0) {
					totalscore = totalscore + blues;
					score = score + blues;
					cr11 = cr11 + 1;
					bcr11 = true;
					not= true;
				}


			}

			if (not== false) {

				if (cr3 == 0) {
					totalscore = totalscore + reds;
					score = score + reds;
					cr3 = cr3 + 1;
					bcr3 = true;
				}
			}

		}
	}

	if (left12 == true) {
		if (down == true) {
			yo = -0.4;
			down = false;
			tt = true;
			c2 = -0.1;

		}
		if (down2 == true) {
			yo = +0.4;
			down2 = false;
			ff = true;
			flip = false;
			c2 = 0.2;

		}
		show = true;
		c1 = c1 + 0.0001;
		c3 = c3 - 0.001;
		xo = xo - speedx5;
		zo = zo - speedz5;
		l1 = l1 - 0.00053;
		l3 = l3 - 0.009;
		if (zo <= -1 || xo <= -0.9)
		{
			left12 = false;
			left2 = true;
			if (tt == true) {
				left2 = false;
				left4 = true;
			}

			if (ff == true) {
				if (cr8 == 0) {
					totalscore = totalscore + yellows;
					score = score + yellows;
					cr8 = cr8 + 1;
					bcr8 = true;
					not= true;
				}


			}

			if (tt == true) {
				if (cr12 == 0) {
					totalscore = totalscore + yellows;
					score = score + yellows;
					cr12 = cr12 + 1;
					bcr12 = true;
					not= true;
				}


			}

			if (not== false) {
				if (cr4 == 0) {
					totalscore = totalscore + reds;
					score = score + reds;
					cr4 = cr4 + 1;
					bcr4 = true;
				}

			}
		}


	}




	if (left4 == true) {


		xo = xo + 0.0033;
		yo = yo + 0.005;

		c1 = c1 - 0.0003;
		c2 = c2 + 0.001;
		l1 = l1 + 0.0005;
		l2 = l2 + 0.0006;

		if (yo > 0.9)
		{
			flip2 = false;
			left4 = false;
			left6 = true;
			if (bcr9 == true) {

				if (cr9 == 2 || cr9 == 6 || cr9 == 8 || cr9 == 12 || cr9 == 14) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr9 == 1 || cr9 == 4 || cr9 == 10 || cr9 == 13) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr9 == 7) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr9 == 5 || cr9 == 3 || cr9 == 9 || cr9 == 11) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr9++;

			}


			if (bcr10 == true) {

				if (cr10 == 3 || cr10 == 5 || cr10 == 9 || cr10 == 11) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr10 == 7) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr10 == 1 || cr10 == 4 || cr10 == 10) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr10 == 2 || cr10 == 6 || cr10 == 8) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr10++;

			}



			if (bcr11 == true) {

				if (cr11 == 3 || cr11 == 5) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr11 == 1) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr11 == 4) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr11 == 2) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr11++;

			}

			if (bcr12 == true) {

				if (cr12 == 3) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}

				if (cr12 == 4) {
					score = score + greens;
					totalscore = totalscore + greens;
				}


				cr12++;

			}




			if (zo <= -0.6) {
				left6 = false;
				tt = false;
				ff = false;
				bcr9 = false;
				bcr10 = false;
				bcr11 = false;
				bcr12 = false;
				keyy = false;

			}

		}



	}

	if (left6 == true) {
		xo = xo + 0.003;
		yo = yo - 0.0043;
		c1 = c1 - 0.0003;
		c2 = c2 - 0.001;
		l1 = l1 + 0.002;
		l2 = l2 - 0.0006;
		if (xo > 0.9)
		{
			left6 = false;
			left3 = true;
			if (bcr9 == true) {

				if (cr9 == 2 || cr9 == 6 || cr9 == 8 || cr9 == 12 || cr9 == 14) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr9 == 1 || cr9 == 4 || cr9 == 10 || cr9 == 13) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr9 == 7) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr9 == 5 || cr9 == 3 || cr9 == 9 || cr9 == 11) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr9++;

			}

			if (bcr10 == true) {

				if (cr10 == 3 || cr10 == 5 || cr10 == 9 || cr10 == 11) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr10 == 7) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr10 == 1 || cr10 == 4 || cr10 == 10) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr10 == 2 || cr10 == 6 || cr10 == 8) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr10++;

			}

			if (bcr11 == true) {

				if (cr11 == 3 || cr11 == 5) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr11 == 1) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr11 == 4) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr11 == 2) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr11++;

			}


			if (zo < -0.6) {
				left3 = false;
				tt = false;
				ff = false;
				bcr9 = false;
				bcr10 = false;
				bcr11 = false;
				bcr12 = false;
				keyy = false;
			}

		}



	}

	if (left7 == true) {
		xo = xo + 0.002;
		yo = yo - 0.001;
		c1 = c1 - 0.0002;
		c2 = c2 - 0.0001;
		l1 = l1 + 0.0005;
		l2 = l2 - 0.0006;
		if (yo < -0.9)
		{
			flip2 = true;
			left7 = false;
			left8 = true;
			if (bcr9 == true) {

				if (cr9 == 2 || cr9 == 6 || cr9 == 8 || cr9 == 12 || cr9 == 14) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr9 == 1 || cr9 == 4 || cr9 == 10 || cr9 == 13) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr9 == 7) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr9 == 5 || cr9 == 3 || cr9 == 9 || cr9 == 11) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr9++;

			}



			if (bcr10 == true) {

				if (cr10 == 3 || cr10 == 5 || cr10 == 9 || cr10 == 11) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr10 == 7) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr10 == 1 || cr10 == 4 || cr10 == 10) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr10 == 2 || cr10 == 6 || cr10 == 8) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr10++;

			}

			if (bcr11 == true) {

				if (cr11 == 3 || cr11 == 5) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr11 == 1) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr11 == 4) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr11 == 2) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr11++;

			}
			if (zo < -0.6) {
				left8 = false;
				tt = false;
				ff = false;
				bcr9 = false;
				bcr10 = false;
				bcr12 = false;
				bcr11 = false;
				keyy = false;
			}

		}


	}
	if (left8 == true) {
		xo = xo + 0.003;
		yo = yo + 0.002;
		c1 = c1 - 0.0003;
		c2 = c2 + 0.0008;
		l1 = l1 + 0.003;
		l2 = l2 + 0.0006;
		if (xo > 0.9)
		{
			left8 = false;
			left3 = true;

			if (bcr9 == true) {

				if (cr9 == 2 || cr9 == 6 || cr9 == 8 || cr9 == 12 || cr9 == 14) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr9 == 1 || cr9 == 4 || cr9 == 10 || cr9 == 13) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr9 == 7) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr9 == 5 || cr9 == 3 || cr9 == 9 || cr9 == 11) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr9++;

			}


			if (bcr10 == true) {

				if (cr10 == 3 || cr10 == 5 || cr10 == 9 || cr10 == 11) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr10 == 7) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr10 == 1 || cr10 == 4 || cr10 == 10) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr10 == 2 || cr10 == 6 || cr10 == 8) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr10++;

			}
			if (bcr11 == true) {

				if (cr11 == 3 || cr11 == 5) {
					score = score + yellows;
					totalscore = totalscore + yellows;
				}
				if (cr11 == 1) {
					score = score + reds;
					totalscore = totalscore + reds;
				}
				if (cr11 == 4) {
					score = score + greens;
					totalscore = totalscore + greens;
				}
				if (cr11 == 2) {
					score = score + blues;
					totalscore = totalscore + blues;
				}

				cr11++;

			}

			if (zo < -0.6) {
				left3 = false;
				tt = false;
				ff = false;
				bcr9 = false;
				bcr10 = false;
				bcr11 = false;
				keyy = false;
			}

		}


	}















	glutPostRedisplay();
}


void KeyboardSpecial(int key, int x, int y) {

	if (key == GLUT_KEY_RIGHT) {
		if (rotAng > 110) {
			rotAng--;
		}
	}
	if (key == GLUT_KEY_LEFT) {
		if (rotAng < 250) {
			rotAng++;
		}
	}

	if (key == GLUT_KEY_UP) {
		if (rotAng2 > -30) {
			rotAng2--;
		}
	}
	if (key == GLUT_KEY_DOWN) {

		if (rotAng2 < 30) {

			rotAng2++;
		}
	}









}

void Key(unsigned char key, int x, int y) {



	if (key == 'f') {
		if (keyy == false) {
			if (rotAng > 170 && rotAng < 190 && rotAng2 >= -30 && rotAng2 <= 30) {
				center1 = true;


			}

			if (rotAng > 160 && rotAng <= 170 && rotAng2 >= -30 && rotAng2 <= 30) {
				center2 = true;


			}

			if (rotAng >= 190 && rotAng < 200 && (rotAng2 >= -30 && rotAng2 <= 30)) {
				center3 = true;
			}




			if (rotAng >= 110 && rotAng <= 125 && (rotAng2 > -15 && rotAng2 < 15)) {
				right1 = true;
			}


			if (rotAng >= 110 && rotAng <= 125 && (rotAng2 >= 15 && rotAng2 <= 30)) {
				right1 = true;
				down = true;
			}

			if (rotAng >= 110 && rotAng <= 125 && (rotAng2 <= -15 && rotAng2 >= -30)) {
				right1 = true;
				down2 = true;
			}




			if (rotAng > 125 && rotAng <= 140 && rotAng2 > -15 && rotAng2 < 15) {

				right12 = true;

			}


			if (rotAng > 125 && rotAng <= 140 && rotAng2 >= 15 && rotAng2 <= 30) {

				right12 = true;
				down = true;

			}

			if (rotAng > 125 && rotAng <= 140 && rotAng2 <= -15 && rotAng2 >= -30) {

				right12 = true;
				down2 = true;

			}



			if (rotAng > 140 && rotAng <= 150 && rotAng2 > -15 && rotAng2 < 15) {

				right13 = true;
			}

			if (rotAng > 140 && rotAng <= 150 && rotAng2 >= 15 && rotAng2 <= 30) {

				right13 = true;
				down = true;
			}
			if (rotAng > 140 && rotAng <= 150 && rotAng2 <= -15 && rotAng2 >= -30) {

				right13 = true;
				down2 = true;
			}

			if (rotAng > 150 && rotAng <= 160 && rotAng2 > -15 && rotAng2 < 15) {
				right14 = true;
			}


			if (rotAng > 150 && rotAng <= 160 && rotAng2 >= 15 && rotAng2 <= 30) {
				right14 = true;
				down = true;
			}

			if (rotAng > 150 && rotAng <= 160 && rotAng2 <= -15 && rotAng2 >= -30) {
				right14 = true;
				down2 = true;
			}





			if (rotAng >= 230 && rotAng <= 250 && rotAng2 > -15 && rotAng2 < 15) {
				left1 = true;
			}
			if (rotAng >= 230 && rotAng <= 250 && rotAng2 <= -15 && rotAng2 >= -30) {
				left1 = true;
				down2 = true;

			}
			if (rotAng >= 230 && rotAng <= 250 && rotAng2 >= 15 && rotAng2 <= 30) {
				left1 = true;
				down = true;

			}


			if (rotAng >= 200 && rotAng < 210 && rotAng2 > -15 && rotAng2 < 15) {
				left12 = true;
			}
			if (rotAng >= 200 && rotAng < 210 && rotAng2 <= -15 && rotAng2 >= -30) {
				left12 = true;
				down2 = true;
			}
			if (rotAng >= 200 && rotAng < 210 && rotAng2 >= 15 && rotAng2 <= 30) {
				left12 = true;
				down = true;
			}


			if (rotAng >= 210 && rotAng < 225 && rotAng2 > -15 && rotAng2 < 15) {
				left13 = true;
			}
			if (rotAng >= 210 && rotAng < 225 && rotAng2 <= -15 && rotAng2 >= -30) {
				left13 = true;
				down2 = true;
			}
			if (rotAng >= 210 && rotAng < 225 && rotAng2 >= 15 && rotAng2 <= 30) {
				left13 = true;
				down = true;
			}




			if (rotAng >= 225 && rotAng < 230 && rotAng2 > -15 && rotAng2 < 15) {
				left14 = true;
			}
			if (rotAng >= 225 && rotAng < 230 && rotAng2 <= -15 && rotAng2 >= -30) {
				left14 = true;
				down2 = true;
			}
			if (rotAng >= 225 && rotAng < 230 && rotAng2 >= 15 && rotAng2 <= 30) {
				left14 = true;
				down = true;
			}





			keyy = true;


		}






	}



	if (key == 'r') {
		if (keyy == false) {
			//org = true;
			zo = 2.5;
			xo = 0;
			yo = 0;
			show = false;

			c1 = 0;
			c2 = 0;
			c3 = 3.3;
			l1 = 0;
			l3 = -1;
			l2 = 0;


			//rotAng = 180;
			//rotAng2 = 0;
			cr1 = 0;
			cr2 = 0;
			cr3 = 0;
			cr4 = 0;
			cr5 = 0;
			cr6 = 0;
			cr7 = 0;
			cr8 = 0;
			cr9 = 0;
			cr10 = 0;
			cr11 = 0;
			cr12 = 0;


			score = 0;
			not= false;
			rounds++;



		}
	}

}



























void main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitWindowSize(600, 600);
	glutInitWindowPosition(150, 150);

	glutCreateWindow("OpenGL - 3D Template");
	glutDisplayFunc(Display);
	glutIdleFunc(Anim);
	glutKeyboardFunc(Key);
	glutSpecialFunc(KeyboardSpecial);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);


	glEnable(GL_DEPTH_TEST);


	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	gluOrtho2D(0.0, 800, 0.0, 800);



	glutMainLoop();
}

