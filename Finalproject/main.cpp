#include<windows.h>
#include<GL/glut.h>
#include<math.h>
# define PI           3.14159265358979323846
void night(int);
void displayBack(int);
void rainy(int);
void display();
void day();
void rainyView();
void nightView();

//DAY-START----17312
//RAINY-START--151
//NIGHT-START--10656

GLfloat position = 0.0f;
GLfloat position2 = 0.0f;
GLfloat position3 = 0.0f;
GLfloat position4 = 0.0f;
GLfloat position5 = 0.0f;

GLfloat speed = 0.1f;


void update(int value) {
    if(position <-2.0)
        position = 2.0f;
    position -= speed;
	glutPostRedisplay();
	glutTimerFunc(200, update, 0);
}



void update2(int value) {
    if(position2 >2.0)
        position2 = -2.0f;
    position2 += speed;
	glutPostRedisplay();
	glutTimerFunc(200, update2, 0);
}

void update3(int value) {
    if(position3 >2.0)
        position3 = -2.0f;
    position3 += speed;
	glutPostRedisplay();
	glutTimerFunc(200, update3, 0);
}

void update4(int value) {
    if(position4 <-2.8)
        position4 = 1.0f;
    position4 -= speed;
	glutPostRedisplay();
	glutTimerFunc(200, update4, 0);
}

void update5(int value) {
    if(position5 <-1.8)
        position5 = 1.0f;
    position5 -= speed;
	glutPostRedisplay();
	glutTimerFunc(200, update5, 0);
}


void idle()
{
    glutPostRedisplay();
}
void init()
{
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}



 void SpecialInput(int key, int x, int y){
     switch(key){
case GLUT_KEY_UP:
    speed=.1;
    break;

case GLUT_KEY_DOWN:
    speed=0;

    break;

case GLUT_KEY_LEFT:
  glutTimerFunc(100, update, 0);
    break;

case GLUT_KEY_RIGHT:
    glutTimerFunc(100, update2, 0);
    glutTimerFunc(100, update3, 0);
    break;
}

glutPostRedisplay();
}



void abc(unsigned char key,int x,int y)
{
    switch(key){
case 'd':

    glutDisplayFunc(day);
    glutPostRedisplay();
    PlaySound("vehicles.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
    break;

case 'n':

     glutDisplayFunc(nightView);
    glutPostRedisplay();
    PlaySound("night.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
    break;




    case 'r':

       glutDisplayFunc(rainyView);
       glutPostRedisplay();
       PlaySound("rain.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
    break;


    case 'b':

      speed=0.1;
    glutPostRedisplay();
    break;


    }

}
void  mouseCount(int key,int state, int x, int y)
{
    if(key==GLUT_LEFT_BUTTON)
    {
        glutDisplayFunc(display);
        PlaySound("no.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);


        //sound1();
    }
    else if (key==GLUT_RIGHT_BUTTON)
    {
        glutDisplayFunc(display);
        PlaySound("no.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

    }
    glutPostRedisplay();
}


void displayBack(int value)
{
    glutDisplayFunc(display);
}


//Start rainyview from 171 line

void rainyView()
{
    glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);


//SKY / SUN / CLOUD
{
    //SKY
    glBegin(GL_QUADS);
    glColor3ub(150,151,146);
    glVertex2f(-1,1);
    glVertex2f(-1,.07);
    glVertex2f(1,.07);
    glVertex2f(1,1);
    glEnd();


    //cloud
    glPushMatrix();
    glTranslatef(.98,0.07f, 0.0f);
    GLfloat x=-.24f; GLfloat y=.74f; GLfloat radius =.08f;
   int  triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 89, 72);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

	x=-0.36f;  y=.78f;  radius =.08f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 89, 72);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

	x=-.47f;  y=.82f;  radius =.08f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 89, 72);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

    //below cloud
    x=-.33f;  y=.67f;  radius =.08f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(91, 94, 90);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

    x=-.44f;  y=.7f;  radius =.08f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(91, 94, 90);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

    x=-.54f;  y=.74f;  radius =.08f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(91, 94, 90);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

	x=-.6f;  y=.68f;  radius =.08f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(91, 94, 90);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

	x=-.49f;  y=.66f;  radius =.07f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(91, 94, 90);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glPopMatrix();


}


{

 //cloud
    glPushMatrix();
    glTranslatef(-.4,0.07f, 0.0f);

    GLfloat x=-.24f; GLfloat y=.74f; GLfloat radius =.08f;
   int  triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 89, 72);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

	x=-0.36f;  y=.78f;  radius =.08f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 89, 72);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

	x=-.47f;  y=.82f;  radius =.08f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 89, 72);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

    //below cloud
    x=-.33f;  y=.67f;  radius =.08f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(91, 94, 90);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

    x=-.44f;  y=.7f;  radius =.08f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(91, 94, 90);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

    x=-.54f;  y=.74f;  radius =.08f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(91, 94, 90);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

	x=-.6f;  y=.68f;  radius =.08f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(91, 94, 90);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

	x=-.49f;  y=.66f;  radius =.07f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(91, 94, 90);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glPopMatrix();


}




	//1st Left upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-.32,.54);
    glVertex2f(-.32,.49);
    glVertex2f(-.28,.48);
    glVertex2f(-.28,.56);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.28,.54);
    glVertex2f(-.32,.52);

    glVertex2f(-.28,.52);
    glVertex2f(-.24,.5);
    glEnd();

    //LEFT CIRCLE
     GLfloat x=-.3f; GLfloat y=.5f; GLfloat radius =.022f;
     int triangleAmount = 20;
	 GLfloat twicePi = 2.0f * PI;

	 glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	 glEnd();

    //2nd left upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-.28,.56);
    glVertex2f(-.28,.48);
    glVertex2f(-.24,.46);
    glVertex2f(-.24,.55);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.28,.54);
    glVertex2f(-.24,.53);

    glVertex2f(-.28,.52);
    glVertex2f(-.24,.51);

    glVertex2f(-.28,.5);
    glVertex2f(-.24,.49);

    glEnd();

    //3rd left upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-.24,.55);
    glVertex2f(-.24,.52);
    glVertex2f(-.2,.52);
    glVertex2f(-.2,.56);
    glEnd();

    //4th left upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-.2,.58);
    glVertex2f(-.2,.54);
    glVertex2f(-.06,.54);
    glVertex2f(-.06,.595);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.2,.56);
    glVertex2f(-.06,.56);
    glEnd();

    //LEFT CIRCLE TOP
     x=-.14f;  y=.53f;  radius =.04f;
     triangleAmount = 20;
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


    //1st MIDLLE upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-.06,.585);
    glVertex2f(-.06,.46);
    glVertex2f(.06,.46);
    glVertex2f(.06,.585);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(0,.585);
    glVertex2f(0,.46);

    glVertex2f(-.06,.57);
    glVertex2f(.06,.57);

    glVertex2f(-.06,.55);
    glVertex2f(.06,.55);

    glVertex2f(-.06,.525);
    glVertex2f(.06,.525);

    glVertex2f(-.06,.505);
    glVertex2f(.06,.505);

    glVertex2f(-.06,.485);
    glVertex2f(.06,.485);

    glVertex2f(-.06,.46);
    glVertex2f(.06,.46);

    glEnd();

     //2nd MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(16,16,16);
    glVertex2f(-.06,.46);
    glVertex2f(-.06,.4);
    glVertex2f(.06,.4);
    glVertex2f(.06,.46);
    glEnd();


    //3rd MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(-.06,.4);
    glVertex2f(-.06,.38);
    glVertex2f(.06,.38);
    glVertex2f(.06,.4);
    glEnd();

    //4th MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(21,21,21);
    glVertex2f(-.06,.38);
    glVertex2f(-.06,.32);
    glVertex2f(.06,.32);
    glVertex2f(.06,.38);
    glEnd();

    //5th MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(-.06,.32);
    glVertex2f(-.06,.3);
    glVertex2f(.06,.3);
    glVertex2f(.06,.32);
    glEnd();


    //5th MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(21,21,21);
    glVertex2f(-.06,.3);
    glVertex2f(-.06,.26);
    glVertex2f(.06,.26);
    glVertex2f(.06,.3);
    glEnd();

    //6th MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(80,80,80);
    glVertex2f(-.06,.26);
    glVertex2f(-.06,.24);
    glVertex2f(.06,.24);
    glVertex2f(.06,.26);
    glEnd();

    //7th MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(-.06,.24);
    glVertex2f(-.06,.2);
    glVertex2f(.06,.2);
    glVertex2f(.06,.24);
    glEnd();


    //5th MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(-.06,.2);
    glVertex2f(-.06,.16);
    glVertex2f(.06,.16);
    glVertex2f(.06,.2);
    glEnd();








    //1st RIGHT upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(.32,.54);
    glVertex2f(.32,.49);
    glVertex2f(.28,.48);
    glVertex2f(.28,.56);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.28,.54);
    glVertex2f(.32,.52);

    glVertex2f(.28,.52);
    glVertex2f(.24,.5);


    glEnd();

    //RIGHT CIRCLE
      x=.3f; y=.5f;  radius =.022f;
      triangleAmount = 20;
	  twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


    //2nd RIGHT upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(.28,.56);
    glVertex2f(.28,.48);
    glVertex2f(.24,.46);
    glVertex2f(.24,.55);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.28,.54);
    glVertex2f(.24,.53);

    glVertex2f(.28,.52);
    glVertex2f(.24,.51);


    glVertex2f(.28,.5);
    glVertex2f(.24,.49);


    glEnd();

    //3rd RIGHT upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(.24,.55);
    glVertex2f(.24,.52);
    glVertex2f(.2,.52);
    glVertex2f(.2,.56);
    glEnd();

    //4th RIGHT upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(.2,.58);
    glVertex2f(.2,.54);
    glVertex2f(.06,.54);
    glVertex2f(.06,.595);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.2,.56);
    glVertex2f(.06,.56);
    glEnd();

    // CIRCLE RIGHT
     x=.14f;  y=.53f;  radius =.04f;
     triangleAmount = 20;
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();








{

    //1stLeft
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.81,.41);
    glVertex2f(-.81,.19);
    glVertex2f(-.7,.19);
    glVertex2f(-.7,.41);
    glEnd();



    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.765,.41);
    glVertex2f(-.765,.19);



    glEnd();




    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.81,.38);
    glVertex2f(-.7,.38);

    glVertex2f(-.81,.35);
    glVertex2f(-.7,.35);

    glVertex2f(-.81,.32);
    glVertex2f(-.7,.32);

    glVertex2f(-.81,.29);
    glVertex2f(-.7,.29);

    glVertex2f(-.81,.26);
    glVertex2f(-.7,.26);

    glVertex2f(-.81,.23);
    glVertex2f(-.7,.23);

    glVertex2f(-.81,.20);
    glVertex2f(-.7,.20);



    glEnd();

    //second Left
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.71,.43);
    glVertex2f(-.71,.17);
    glVertex2f(-.58,.17);
    glVertex2f(-.58,.45);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.67,.17);
    glVertex2f(-.67,.438);

    glVertex2f(-.62,.17);
    glVertex2f(-.62,.445);

    glEnd();




    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.71,.4);
    glVertex2f(-.58,.42);

    glVertex2f(-.71,.37);
    glVertex2f(-.58,.39);

    glVertex2f(-.71,.34);
    glVertex2f(-.58,.36);

    glVertex2f(-.71,.31);
    glVertex2f(-.58,.33);

    glVertex2f(-.71,.28);
    glVertex2f(-.58,.30);

    glVertex2f(-.71,.25);
    glVertex2f(-.58,.27);

    glVertex2f(-.71,.22);
    glVertex2f(-.58,.24);

    glVertex2f(-.71,.19);
    glVertex2f(-.58,.21);

    glVertex2f(-.71,.16);
    glVertex2f(-.58,.18);

    glEnd();


    //Middle of 2 ,3 Left
    glBegin(GL_QUADS);
    glColor3ub(100,100,100);
    glVertex2f(-.58,.44);
    glVertex2f(-.58,.38);
    glVertex2f(-.56,.38);
    glVertex2f(-.56,.445);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-.58,.38);
    glVertex2f(-.58,.16);
    glVertex2f(-.56,.16);
    glVertex2f(-.56,.38);
    glEnd();

    //3rd left
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.56,.46);
    glVertex2f(-.56,.16);
    glVertex2f(-.42,.16);
    glVertex2f(-.42,.5);
    glEnd();


     glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.45,.16);
    glVertex2f(-.45,.49);

    glVertex2f(-.52,.16);
    glVertex2f(-.52,.48);

    glEnd();




    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.56,.43);
    glVertex2f(-.42,.47);

    glVertex2f(-.56,.4);
    glVertex2f(-.42,.44);

    glVertex2f(-.56,.37);
    glVertex2f(-.42,.41);

    glVertex2f(-.56,.34);
    glVertex2f(-.42,.38);

    glVertex2f(-.56,.31);
    glVertex2f(-.42,.35);

    glVertex2f(-.56,.28);
    glVertex2f(-.42,.32);

    glVertex2f(-.56,.25);
    glVertex2f(-.42,.29);

    glVertex2f(-.56,.22);
    glVertex2f(-.42,.26);

    glVertex2f(-.56,.19);
    glVertex2f(-.42,.23);

    glEnd();

    //4th left
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.42,.5);
    glVertex2f(-.42,.13);
    glVertex2f(-.24,.13);
    glVertex2f(-.24,.48);
    glEnd();

    //5th left
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.24,.54);
    glVertex2f(-.24,.13);
    glVertex2f(-.04,.13);
    glVertex2f(-.04,.54);
    glEnd();



    //Left 1st Triangle
    //1stLeft
    glBegin(GL_TRIANGLES);
    glColor3ub(1,1,1);
    glVertex2f(-.67,.4);
    glVertex2f(-.695,.24);
    glVertex2f(-.65,.25);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(217,217,217);
    glVertex2f(-.67,.27);
    glVertex2f(-.69,.24);
    glVertex2f(-.65,.25);
    glVertex2f(-.65,.27);

    glEnd();


    //2nd Left
    glBegin(GL_TRIANGLES);
    glColor3ub(1,1,1);
    glVertex2f(-.45,.43);
    glVertex2f(-.49,.26);
    glVertex2f(-.43,.27);
    glEnd();

//LEFT TRIANGLE INSIDE
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.45,.428);
    glVertex2f(-.45,.268);
    glVertex2f(-.443,.268);
    glVertex2f(-.443,.428);

    glVertex2f(-.47,.38);
    glVertex2f(-.47,.373);
    glVertex2f(-.44,.373);
    glVertex2f(-.44,.38);

    glVertex2f(-.47,.35);
    glVertex2f(-.47,.343);
    glVertex2f(-.44,.343);
    glVertex2f(-.44,.35);

    glVertex2f(-.48,.32);
    glVertex2f(-.48,.313);
    glVertex2f(-.43,.313);
    glVertex2f(-.43,.32);

    glVertex2f(-.485,.29);
    glVertex2f(-.485,.283);
    glVertex2f(-.43,.283);
    glVertex2f(-.43,.29);
    glEnd();

    //Under triangle a BOX 1
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-.49,.22);
    glVertex2f(-.49,.17);
    glVertex2f(-.43,.17);
    glVertex2f(-.43,.22);
    glEnd();

    //INSIDE BOX LEFT
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.458,.22);
    glVertex2f(-.458,.17);
    glVertex2f(-.45,.17);
    glVertex2f(-.45,.22);

    glVertex2f(-.49,.195);
    glVertex2f(-.49,.19);
    glVertex2f(-.43,.19);
    glVertex2f(-.43,.195);

    glEnd();



    //Under triangle a BOX 2
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-.695,.21);
    glVertex2f(-.695,.18);
    glVertex2f(-.65,.18);
    glVertex2f(-.65,.21);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(217,217,217);
    glVertex2f(-.695,.21);
    glVertex2f(-.69,.2);
    glVertex2f(-.65,.2);
    glVertex2f(-.65,.21);

    glEnd();





    //LEFTBOTTOM Polygon 1
    glBegin(GL_QUADS);
    glColor3ub(80,0,0);
    glVertex2f(-.82,.19);
    glVertex2f(-.82,.07);
    glVertex2f(-.5,.12);
    glVertex2f(-.68,.19);
    glEnd();

    //LEFTBOTTOM Polygon 2
    glBegin(GL_QUADS);
    glColor3ub(80,0,0);
    glVertex2f(-.56,.17);
    glVertex2f(-.465,.13);
    glVertex2f(-.32,.13);
    glVertex2f(-.43,.17);

    glEnd();




    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.28,.13);
    glVertex2f(-.28,.48);

    glVertex2f(-.37,.16);
    glVertex2f(-.37,.5);



    glEnd();


    //Right 2
    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);


    glVertex2f(-.24,.46);
    glVertex2f(-.42,.48);

    glVertex2f(-.24,.43);
    glVertex2f(-.42,.45);

    glVertex2f(-.24,.4);
    glVertex2f(-.42,.42);

    glVertex2f(-.24,.37);
    glVertex2f(-.42,.39);

    glVertex2f(-.24,.34);
    glVertex2f(-.42,.36);

    glVertex2f(-.24,.31);
    glVertex2f(-.42,.33);

    glVertex2f(-.24,.28);
    glVertex2f(-.42,.30);

    glVertex2f(-.24,.25);
    glVertex2f(-.42,.27);

    glVertex2f(-.24,.22);
    glVertex2f(-.42,.24);

    glVertex2f(-.24,.19);
    glVertex2f(-.42,.21);

    glVertex2f(-.24,.16);
    glVertex2f(-.42,.18);

    glEnd();



    //LEFT CIRCLE


	 x=-.34f;  y=.255f;  radius =.06f;
     triangleAmount = 20;
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

//Left inside circle
 glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.36,.315);
    glVertex2f(-.36,.2);
    glVertex2f(-.352,.2);
    glVertex2f(-.352,.315);

    glVertex2f(-.33,.315);
    glVertex2f(-.33,.2);
    glVertex2f(-.322,.2);
    glVertex2f(-.322,.315);

    glVertex2f(-.4,.28);
    glVertex2f(-.4,.273);
    glVertex2f(-.25,.273);
    glVertex2f(-.25,.28);

    glVertex2f(-.4,.24);
    glVertex2f(-.4,.233);
    glVertex2f(-.25,.233);
    glVertex2f(-.25,.24);

    glEnd();




	//RIGHT BUILDING

    //1st Right
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.05,.54);
    glVertex2f(.05,.13);
    glVertex2f(.25,.13);
    glVertex2f(.25,.54);
    glEnd();

    //2nd Right
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.42,.5);
    glVertex2f(.42,.13);
    glVertex2f(.25,.13);
    glVertex2f(.25,.48);
    glEnd();

    //3rd Right
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.56,.46);
    glVertex2f(.56,.16);
    glVertex2f(.42,.16);
    glVertex2f(.42,.5);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.45,.16);
    glVertex2f(.45,.49);

    glVertex2f(.52,.16);
    glVertex2f(.52,.48);
    glEnd();

    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.56,.43);
    glVertex2f(.42,.47);

    glVertex2f(.56,.4);
    glVertex2f(.42,.44);

    glVertex2f(.56,.37);
    glVertex2f(.42,.41);

    glVertex2f(.56,.34);
    glVertex2f(.42,.38);

    glVertex2f(.56,.31);
    glVertex2f(.42,.35);

    glVertex2f(.56,.28);
    glVertex2f(.42,.32);

    glVertex2f(.56,.25);
    glVertex2f(.42,.29);

    glVertex2f(.56,.22);
    glVertex2f(.42,.26);

    glVertex2f(.56,.19);
    glVertex2f(.42,.23);

    glEnd();

    //Middle of 3 ,4 Right
    glBegin(GL_QUADS);
    glColor3ub(100,100,100);
    glVertex2f(.58,.44);
    glVertex2f(.58,.38);
    glVertex2f(.56,.38);
    glVertex2f(.56,.445);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.58,.38);
    glVertex2f(.58,.16);
    glVertex2f(.56,.16);
    glVertex2f(.56,.38);
    glEnd();

	//4th Right
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.71,.43);
    glVertex2f(.71,.17);
    glVertex2f(.58,.17);
    glVertex2f(.58,.45);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.67,.17);
    glVertex2f(.67,.438);

    glVertex2f(.62,.17);
    glVertex2f(.62,.445);

    glEnd();

    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.71,.4);
    glVertex2f(.58,.42);

    glVertex2f(.71,.37);
    glVertex2f(.58,.39);

    glVertex2f(.71,.34);
    glVertex2f(.58,.36);

    glVertex2f(.71,.31);
    glVertex2f(.58,.33);

    glVertex2f(.71,.28);
    glVertex2f(.58,.30);

    glVertex2f(.71,.25);
    glVertex2f(.58,.27);

    glVertex2f(.71,.22);
    glVertex2f(.58,.24);

    glVertex2f(.71,.19);
    glVertex2f(.58,.21);

    glVertex2f(.71,.16);
    glVertex2f(.58,.18);
    glEnd();

    //5th Right
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.81,.41);
    glVertex2f(.81,.19);
    glVertex2f(.7,.19);
    glVertex2f(.7,.41);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.765,.41);
    glVertex2f(.765,.19);
    glEnd();

    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.81,.38);
    glVertex2f(.7,.38);

    glVertex2f(.81,.35);
    glVertex2f(.7,.35);

    glVertex2f(.81,.32);
    glVertex2f(.7,.32);

    glVertex2f(.81,.29);
    glVertex2f(.7,.29);

    glVertex2f(.81,.26);
    glVertex2f(.7,.26);

    glVertex2f(.81,.23);
    glVertex2f(.7,.23);

    glVertex2f(.81,.20);
    glVertex2f(.7,.20);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.28,.13);
    glVertex2f(.28,.48);

    glVertex2f(.37,.13);
    glVertex2f(.37,.5);
    glEnd();

    //Right 2
    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);


    glVertex2f(.25,.46);
    glVertex2f(.42,.48);

    glVertex2f(.25,.43);
    glVertex2f(.42,.45);

    glVertex2f(.25,.4);
    glVertex2f(.42,.42);

    glVertex2f(.25,.37);
    glVertex2f(.42,.39);

    glVertex2f(.25,.34);
    glVertex2f(.42,.36);

    glVertex2f(.25,.31);
    glVertex2f(.42,.33);

    glVertex2f(.25,.28);
    glVertex2f(.42,.30);

    glVertex2f(.25,.25);
    glVertex2f(.42,.27);

    glVertex2f(.25,.22);
    glVertex2f(.42,.24);

    glVertex2f(.25,.19);
    glVertex2f(.42,.21);

    glVertex2f(.25,.16);
    glVertex2f(.42,.18);

    glVertex2f(.25,.13);
    glVertex2f(.42,.15);
    glEnd();

    //RIGHT CIRCLE
	 x=.34f;  y=.255f;  radius =.06f;
     triangleAmount = 20;
	 twicePi = 2.0f * PI;

	 glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	 glEnd();



	 //RIGHT inside circle
 glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.36,.315);
    glVertex2f(.36,.2);
    glVertex2f(.352,.2);
    glVertex2f(.352,.315);

    glVertex2f(.33,.315);
    glVertex2f(.33,.2);
    glVertex2f(.322,.2);
    glVertex2f(.322,.315);

    glVertex2f(.4,.28);
    glVertex2f(.4,.273);
    glVertex2f(.25,.273);
    glVertex2f(.25,.28);

    glVertex2f(.4,.24);
    glVertex2f(.4,.233);
    glVertex2f(.25,.233);
    glVertex2f(.25,.24);

    glEnd();




    //RIGHT 1st Triangle
    //1stRight
    glBegin(GL_TRIANGLES);
    glColor3ub(1,1,1);
    glVertex2f(.67,.4);
    glVertex2f(.695,.24);
    glVertex2f(.65,.25);
    glEnd();
    //SHADE INSIDE
    glBegin(GL_QUADS);
    glColor3ub(217,217,217);
    glVertex2f(.67,.27);
    glVertex2f(.69,.24);
    glVertex2f(.65,.25);
    glVertex2f(.65,.27);

    glEnd();

    //2nd RIGHT
    glBegin(GL_TRIANGLES);
    glColor3ub(1,1,1);
    glVertex2f(.45,.43);
    glVertex2f(.49,.26);
    glVertex2f(.43,.27);
    glEnd();



    //RIGHT TRIANGLE INSIDE
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.45,.428);
    glVertex2f(.45,.268);
    glVertex2f(.443,.268);
    glVertex2f(.443,.428);

    glVertex2f(.47,.38);
    glVertex2f(.47,.373);
    glVertex2f(.44,.373);
    glVertex2f(.44,.38);

    glVertex2f(.47,.35);
    glVertex2f(.47,.343);
    glVertex2f(.44,.343);
    glVertex2f(.44,.35);

    glVertex2f(.48,.32);
    glVertex2f(.48,.313);
    glVertex2f(.43,.313);
    glVertex2f(.43,.32);

    glVertex2f(.485,.29);
    glVertex2f(.485,.283);
    glVertex2f(.43,.283);
    glVertex2f(.43,.29);
    glEnd();



    //Under triangle a BOX RIGHT
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.49,.22);
    glVertex2f(.49,.17);
    glVertex2f(.43,.17);
    glVertex2f(.43,.22);
    glEnd();


     //INSIDE BOX
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.458,.22);
    glVertex2f(.458,.17);
    glVertex2f(.45,.17);
    glVertex2f(.45,.22);

    glVertex2f(.49,.195);
    glVertex2f(.49,.19);
    glVertex2f(.43,.19);
    glVertex2f(.43,.195);

    glEnd();

    //Under triangle a BOX 2
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.695,.21);
    glVertex2f(.695,.18);
    glVertex2f(.65,.18);
    glVertex2f(.65,.21);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(217,217,217);
    glVertex2f(.695,.21);
    glVertex2f(.69,.2);
    glVertex2f(.65,.2);
    glVertex2f(.65,.21);

    glEnd();




    //RIGHT BOTTOM Polygon 1
    glBegin(GL_QUADS);
    glColor3ub(80,0,0);
    glVertex2f(.82,.19);
    glVertex2f(.82,.07);
    glVertex2f(.5,.12);
    glVertex2f(.68,.19);
    glEnd();

    //RIGHT BOTTOM Polygon 2
    glBegin(GL_QUADS);
    glColor3ub(80,0,0);
    glVertex2f(.56,.17);
    glVertex2f(.465,.13);
    glVertex2f(.32,.13);
    glVertex2f(.43,.17);
    glEnd();


     //FLAG QUAD  2
    glBegin(GL_QUADS);
    glColor3ub(178,34,34);
    glVertex2f(-.08,.16);
    glVertex2f(-.082,.1);
    glVertex2f(.082,.1);
    glVertex2f(.08,.16);
    glEnd();

    //FLAG QUAD 1
    glBegin(GL_QUADS);
    glColor3ub(80,0,0);
    glVertex2f(-.06,.16);
    glVertex2f(-.06,.1);
    glVertex2f(.06,.1);
    glVertex2f(.06,.16);
    glEnd();

    //FLAG QUAD
    glBegin(GL_QUADS);
    glColor3ub(220,220,220);
    glVertex2f(-.08,.16);
    glVertex2f(-.082,.12);
    glVertex2f(-.06,.12);
    glVertex2f(-.06,.16);
    glEnd();

    //FLAG QUAD
    glBegin(GL_QUADS);
    glColor3ub(220,220,220);
    glVertex2f(.08,.16);
    glVertex2f(.082,.12);
    glVertex2f(.06,.12);
    glVertex2f(.06,.16);
    glEnd();

    //FLAG QUAD CIRCLE
     x=0.0f;  y=.075f;  radius =.05f;
     triangleAmount = 20;
	 twicePi = 2.0f * PI;

	 glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	 glEnd();

	//White ROAD QUADS LEFT
	//1st White
    glBegin(GL_POLYGON);
    glColor3ub(190, 191, 191);
    glVertex2f(-.8,.07);
    glVertex2f(-.88,.07);
    glVertex2f(-1,.07);
    glVertex2f(-1,0);
    glVertex2f(-.8,0);
    glEnd();

	//2nd White
    glBegin(GL_QUADS);
    glColor3ub(190, 191, 191);
    glVertex2f(-.8,.07);
    glVertex2f(-.8,0);
    glVertex2f(-.58,0);
    glVertex2f(-.58,.11);
    glEnd();

    //3rd White
    glBegin(GL_POLYGON);
    glColor3ub(190, 191, 191);
    glVertex2f(-.58,.11);
    glVertex2f(-.58,0);
    glVertex2f(-.082,0);
    glVertex2f(-.08,.13);
    glVertex2f(-.32,.13);
    glVertex2f(-.46,.13);
    glEnd();


    //White ROAD QUADS RIGHT
	//1st White
    glBegin(GL_POLYGON);
    glColor3ub(190, 191, 191);
    glVertex2f(.8,.07);
    glVertex2f(.88,.07);
    glVertex2f(1,.07);
    glVertex2f(1,0);
    glVertex2f(.8,0);
    glEnd();

	//2nd White
    glBegin(GL_QUADS);
    glColor3ub(190, 191, 191);
    glVertex2f(.8,.07);
    glVertex2f(.8,0);
    glVertex2f(.58,0);
    glVertex2f(.58,.11);
    glEnd();

    //3rd White
    glBegin(GL_POLYGON);
    glColor3ub(190, 191, 191);
    glVertex2f(.58,.11);
    glVertex2f(.58,0);
    glVertex2f(.082,0);
    glVertex2f(.08,.13);
    glVertex2f(.32,.13);
    glVertex2f(.46,.13);
    glEnd();


    //MIDLE White QUAD
    glBegin(GL_QUADS);
    glColor3ub(190, 191, 191);
    glVertex2f(-.082,.1);
    glVertex2f(-.082,0);
    glVertex2f(.082,0);
    glVertex2f(.082,.1);
    glEnd();

    //WHITE SHIRI LEFT 1
    glBegin(GL_QUADS);
    glColor3ub(181, 183, 183);
    glVertex2f(-.62,.17);
    glVertex2f(-.53,.12);
    glVertex2f(-.44,.12);
    glVertex2f(-.56,.17);
    glEnd();


    //WHITE SHIRI Right
    glBegin(GL_QUADS);
    glColor3ub(181, 183, 183);
    glVertex2f(.62,.17);
    glVertex2f(.53,.12);
    glVertex2f(.44,.12);
    glVertex2f(.56,.17);
    glEnd();

    //LEFT 2nd SHIRI
    glBegin(GL_QUADS);
    glColor3ub(181, 183, 183);
    glVertex2f(-.43,.17);
    glVertex2f(-.33,.13);
    glVertex2f(-.3,.13);
    glVertex2f(-.41,.17);
    glEnd();

    //RIGHT 2nd SHIRI
    glBegin(GL_QUADS);
    glColor3ub(181, 183, 183);
    glVertex2f(.43,.17);
    glVertex2f(.33,.13);
    glVertex2f(.3,.13);
    glVertex2f(.41,.17);
    glEnd();

    //BD FLAG STAND
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(238,232,170);
    glVertex2f(0,.16);
    glVertex2f(0,.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,102,0);
    glVertex2f(0,.29);
    glVertex2f(0,.25);
    glVertex2f(.02,.24);
    glVertex2f(.025,.27);
    glEnd();


    //FLAG CIRCLE
     x=0.01f;  y=.265f;  radius =.007f;
     triangleAmount = 20;
	 twicePi = 2.0f * PI;

	 glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(204,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	 glEnd();



	//LINES
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.12,.54);
    glVertex2f(.12,.13);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);

    //RIGHT 1
    glVertex2f(-.11,.54);
    glVertex2f(-.11,.13);
    glEnd();

    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.05,.54);
    glVertex2f(.25,.54);

    glVertex2f(.05,.51);
    glVertex2f(.25,.51);

    glVertex2f(.05,.48);
    glVertex2f(.25,.48);

    glVertex2f(.05,.45);
    glVertex2f(.25,.45);

    glVertex2f(.05,.42);
    glVertex2f(.25,.42);

    glVertex2f(.05,.39);
    glVertex2f(.25,.39);

    glVertex2f(.05,.36);
    glVertex2f(.25,.36);

    glVertex2f(.05,.33);
    glVertex2f(.25,.33);

    glVertex2f(.05,.30);
    glVertex2f(.25,.30);

    glVertex2f(.05,.27);
    glVertex2f(.25,.27);

    glVertex2f(.05,.24);
    glVertex2f(.25,.24);

    glVertex2f(.05,.21);
    glVertex2f(.25,.21);

    glVertex2f(.05,.18);
    glVertex2f(.25,.18);

    glVertex2f(.08,.15);
    glVertex2f(.25,.15);


    //LEFT 5
    glVertex2f(-.04,.54);
    glVertex2f(-.24,.54);

    glVertex2f(-.04,.51);
    glVertex2f(-.24,.51);

    glVertex2f(-.04,.48);
    glVertex2f(-.24,.48);

    glVertex2f(-.04,.45);
    glVertex2f(-.24,.45);

    glVertex2f(-.04,.42);
    glVertex2f(-.24,.42);

    glVertex2f(-.04,.39);
    glVertex2f(-.24,.39);

    glVertex2f(-.04,.36);
    glVertex2f(-.24,.36);

    glVertex2f(-.04,.33);
    glVertex2f(-.24,.33);

    glVertex2f(-.04,.30);
    glVertex2f(-.24,.30);

    glVertex2f(-.04,.27);
    glVertex2f(-.24,.27);

    glVertex2f(-.04,.24);
    glVertex2f(-.24,.24);

    glVertex2f(-.04,.21);
    glVertex2f(-.24,.21);

    glVertex2f(-.04,.18);
    glVertex2f(-.24,.18);

    glVertex2f(-.07,.15);
    glVertex2f(-.24,.15);

    glVertex2f(.25,.13);
    glVertex2f(.25,.54);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(105,105,105);
    glVertex2f(.25,.13);
    glVertex2f(.25,.54);

    glVertex2f(-.24,.13);
    glVertex2f(-.24,.54);

    glVertex2f(.42,.5);
    glVertex2f(.42,.17);

    glVertex2f(-.42,.5);
    glVertex2f(-.42,.17);

    glVertex2f(-.71,.43);
    glVertex2f(-.71,.19);

    glVertex2f(.71,.43);
    glVertex2f(.71,.19);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.06,.595);
    glVertex2f(-.06,.54);

    glVertex2f(.06,.595);
    glVertex2f(.06,.54);

    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);


    glVertex2f(-.77,.16);
    glVertex2f(-.77,.08);

    glVertex2f(-.7,.16);
    glVertex2f(-.7,.09);

    glVertex2f(-.64,.15);
    glVertex2f(-.64,.1);


    glVertex2f(.77,.16);
    glVertex2f(.77,.08);

    glVertex2f(.7,.16);
    glVertex2f(.7,.09);

    glVertex2f(.64,.15);
    glVertex2f(.64,.1);
    glEnd();



    //LIGHT Left
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(-.22,.23);
    glVertex2f(-.22,.13);
    glVertex2f(-.21,.13);
    glVertex2f(-.21,.23);
    glEnd();

    //LIGHT Left Top Two
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(-.22,.23);
    glVertex2f(-.21,.23);
    glVertex2f(-.18,.24);
    glVertex2f(-.2,.25);

    glVertex2f(-.21,.23);
    glVertex2f(-.22,.23);
    glVertex2f(-.26,.24);
    glVertex2f(-.23,.25);
    glEnd();


    //LIGHT Right
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(.22,.23);
    glVertex2f(.22,.13);
    glVertex2f(.21,.13);
    glVertex2f(.21,.23);
    glEnd();


    //LIGHT Right Top Two
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(.22,.23);
    glVertex2f(.21,.23);
    glVertex2f(.18,.24);
    glVertex2f(.2,.25);

    glVertex2f(.21,.23);
    glVertex2f(.22,.23);
    glVertex2f(.26,.24);
    glVertex2f(.23,.25);
    glEnd();





    //Field Upper
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-1,0);
    glVertex2f(-1,-.03);
    glVertex2f(1,-.03);
    glVertex2f(1,0);
    glEnd();

    //Lower field
    glBegin(GL_QUADS);
    glColor3ub(34,139,34);
    glVertex2f(-1,-.03);
    glVertex2f(-1,-.6);
    glVertex2f(1,-.6);
    glVertex2f(1,-.03);
    glEnd();




//TREE
{
    //Tree-round left-1
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(-2.9,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();

    int i;

	GLfloat x=-.75f; GLfloat y=.33f; GLfloat radius =.06f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    GLfloat a=-.68f; GLfloat b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c=-.81f; GLfloat d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e=-.87f; GLfloat f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g=-.61f; GLfloat h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	GLfloat a1=-.61f; GLfloat b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c1=-.88f; GLfloat d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e1=-.87f; GLfloat f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g1=-.61f; GLfloat h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e11=-.64f; GLfloat f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e12=-.75f; GLfloat f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

    GLfloat e123=-.8f; GLfloat f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	GLfloat e1232=-.7f; GLfloat f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-2
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(-2.1,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-3
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(-1.3,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-4
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(-.5,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(560, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-5
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(.3,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-6
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(1.1,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-7
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(1.9,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-8
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(2.7,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-9
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(3.5,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-10
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(4.3,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();


    //Background Tree

    //Left Back tree
    glPushMatrix();
    glScalef(.6,.6,0);
    glTranslatef(-.97f,-.335f,0.0f);
    glBegin(GL_POLYGON);
	glColor3ub(102, 51, 0);
	glVertex2f(-0.52f,0.45f);
	glVertex2f(-0.48f, 0.45f);
	glVertex2f(-0.48f,0.62f);
    glVertex2f(-0.5f,0.64f);
    glVertex2f(-0.52f,0.62f);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(34,139,34);
    glVertex2f(-0.5f,0.64f);
    glVertex2f(-0.52f,0.62f);
    glVertex2f(-0.58f,0.6f);
	glVertex2f(-0.55f, 0.63f);
	glVertex2f(-0.58f,0.66f);
	glVertex2f(-0.52f,0.66f);
	glVertex2f(-0.52f, 0.72f);
	glVertex2f(-0.5f,0.69f);
	glVertex2f(-0.48f,0.72f);
	glVertex2f(-0.48f, 0.66f);
	glVertex2f(-0.42f,0.66f);
	glVertex2f(-0.45f,0.63f);
	glVertex2f(-0.42f, 0.6f);
	glVertex2f(-0.48f,0.62f);
    glEnd();
    glPopMatrix();

    //Right Back Tree
    glPushMatrix();
    glScalef(.6,.6,0);
    glTranslatef(.97f,-.335f,0.0f);
    glBegin(GL_POLYGON);
	glColor3ub(102, 51, 0);
	glVertex2f(0.52f,0.45f);
	glVertex2f(0.48f, 0.45f);
	glVertex2f(0.48f,0.62f);
    glVertex2f(0.5f,0.64f);
    glVertex2f(0.52f,0.62f);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(34,139,34);
    glVertex2f(0.5f,0.64f);
    glVertex2f(0.52f,0.62f);
    glVertex2f(0.58f,0.6f);
	glVertex2f(0.55f, 0.63f);
	glVertex2f(0.58f,0.66f);
	glVertex2f(0.52f,0.66f);
	glVertex2f(0.52f, 0.72f);
	glVertex2f(0.5f,0.69f);
	glVertex2f(0.48f,0.72f);
	glVertex2f(0.48f, 0.66f);
	glVertex2f(0.42f,0.66f);
	glVertex2f(0.45f,0.63f);
	glVertex2f(0.42f, 0.6f);
	glVertex2f(0.48f,0.62f);
    glEnd();
    glPopMatrix();
}

//Grass-Flower
{
    //Grass-Right-1
    glPushMatrix();
    glScalef(.8,.8,0);
    glTranslatef(.8,-.12,0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();
    int i;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;
	GLfloat e=-.05f; GLfloat f=-.35f; GLfloat radius11 =.02f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                e + (radius11 * cos(i *  twicePi / triangleAmount)),
            f+ (radius11 * sin(i * twicePi / triangleAmount))
			);
    }
	glEnd();

	GLfloat g=0.05f; GLfloat h=-0.35f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                g + (radius11 * cos(i *  twicePi / triangleAmount)),
            h+ (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    GLfloat a1=0.0f; GLfloat b1=-0.3f;
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                a1 + (radius11 * cos(i *  twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glPopMatrix();

	//Grass-Right-2
    glPushMatrix();
    glScalef(.8,.8,0);
    glTranslatef(.8,.15,0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();

    triangleAmount = 20;
    twicePi = 2.0f * PI;
	e=-.05f; f=-.35f; radius11 =.02f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                e + (radius11 * cos(i *  twicePi / triangleAmount)),
            f+ (radius11 * sin(i * twicePi / triangleAmount))
			);
    }
	glEnd();

	g=0.05f; h=-0.35f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                g + (radius11 * cos(i *  twicePi / triangleAmount)),
            h+ (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    a1=0.0f; b1=-0.3f;
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                a1 + (radius11 * cos(i *  twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glPopMatrix();

	//Grass-Middle-1
    glPushMatrix();
    glScalef(.8,.8,0);
    glTranslatef(.0,-.12,0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();

    triangleAmount = 20;
    twicePi = 2.0f * PI;
	e=-.05f; f=-.35f; radius11 =.02f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                e + (radius11 * cos(i *  twicePi / triangleAmount)),
            f+ (radius11 * sin(i * twicePi / triangleAmount))
			);
    }
	glEnd();

	g=0.05f; h=-0.35f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                g + (radius11 * cos(i *  twicePi / triangleAmount)),
            h+ (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    a1=0.0f; b1=-0.3f;
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                a1 + (radius11 * cos(i *  twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glPopMatrix();

	//Grass-Middle-2
    glPushMatrix();
    glScalef(.8,.8,0);
    glTranslatef(0.0,.15,0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();

    triangleAmount = 20;
    twicePi = 2.0f * PI;
	e=-.05f; f=-.35f; radius11 =.02f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                e + (radius11 * cos(i *  twicePi / triangleAmount)),
            f+ (radius11 * sin(i * twicePi / triangleAmount))
			);
    }
	glEnd();

	g=0.05f; h=-0.35f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                g + (radius11 * cos(i *  twicePi / triangleAmount)),
            h+ (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    a1=0.0f; b1=-0.3f;
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                a1 + (radius11 * cos(i *  twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glPopMatrix();

	//Grass-Left-1
    glPushMatrix();
    glScalef(.8,.8,0);
    glTranslatef(-.8,-.12,0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();

    triangleAmount = 20;
    twicePi = 2.0f * PI;
	e=-.05f; f=-.35f; radius11 =.02f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                e + (radius11 * cos(i *  twicePi / triangleAmount)),
            f+ (radius11 * sin(i * twicePi / triangleAmount))
			);
    }
	glEnd();

	g=0.05f; h=-0.35f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                g + (radius11 * cos(i *  twicePi / triangleAmount)),
            h+ (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    a1=0.0f; b1=-0.3f;
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                a1 + (radius11 * cos(i *  twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glPopMatrix();

	//Grass-Left-2
    glPushMatrix();
    glScalef(.8,.8,0);
    glTranslatef(-.8,.15,0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(18, 97, 11);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();

    triangleAmount = 20;
    twicePi = 2.0f * PI;
	e=-.05f; f=-.35f; radius11 =.02f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                e + (radius11 * cos(i *  twicePi / triangleAmount)),
            f+ (radius11 * sin(i * twicePi / triangleAmount))
			);
    }
	glEnd();

	g=0.05f; h=-0.35f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                g + (radius11 * cos(i *  twicePi / triangleAmount)),
            h+ (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    a1=0.0f; b1=-0.3f;
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                a1 + (radius11 * cos(i *  twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glPopMatrix();



}


//Fence
{
    //Fence-Left-1
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(-.25,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(176, 176, 172);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-2
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(.105,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(176, 176, 172);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-3
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(.46,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(176, 176, 172);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-4
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(.815,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(176, 176, 172);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-5
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(1.17,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(176, 176, 172);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-6
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(1.525,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(176, 176, 172);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-7
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(1.88,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(176, 176, 172);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

}


    //FootWalk
    glBegin(GL_QUADS);
    glColor3ub(82, 80, 79);
    glVertex2f(-1,-.6);
    glVertex2f(-1,-.66);
    glVertex2f(1,-.66);
    glVertex2f(1,-.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(176, 176, 172);
    glVertex2f(-1,-.66);
    glVertex2f(-1,-.67);
    glVertex2f(1,-.67);
    glVertex2f(1,-.66);
    glEnd();

//Road / Car
{
    //Road
    glBegin(GL_QUADS);
    glColor3ub(28, 26, 25);
    glVertex2f(-1,-.67);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-.67);
    glEnd();
    //Road-Line
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(230,200,0);
    glVertex2f(-.98,-.835);
    glVertex2f(-.88,-.835);

    glVertex2f(-.83,-.835);
    glVertex2f(-.73,-.835);

    glVertex2f(-.68,-.835);
    glVertex2f(-.58,-.835);

    glVertex2f(-.53,-.835);
    glVertex2f(-.43,-.835);

    glVertex2f(-.38,-.835);
    glVertex2f(-.28,-.835);

    glVertex2f(-.23,-.835);
    glVertex2f(-.13,-.835);

    glVertex2f(-.08,-.835);
    glVertex2f(.02,-.835);

    glVertex2f(.07,-.835);
    glVertex2f(.17,-.835);

    glVertex2f(.22,-.835);
    glVertex2f(.32,-.835);

    glVertex2f(.37,-.835);
    glVertex2f(.47,-.835);

    glVertex2f(.52,-.835);
    glVertex2f(.62,-.835);

    glVertex2f(.67,-.835);
    glVertex2f(.77,-.835);

    glVertex2f(.82,-.835);
    glVertex2f(.92,-.835);

    glVertex2f(.97,-.835);
    glVertex2f(1,-.835);

    glEnd();

    /*

    //Car-Below-Left
    glPushMatrix();
    glTranslatef(.11,-.29,0);
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(-.66,-.60);
    glVertex2f(-.66,-.68);
    glVertex2f(-.28,-.68);
    glVertex2f(-.28,-.62);
    glVertex2f(-.27,-.62);
    glVertex2f(-.28,-.60);
    glVertex2f(-.36,-.60);
    glVertex2f(-.40,-.54);
    glVertex2f(-.60,-.54);
    glVertex2f(-.62,-.62);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-.37,-.60);
    glVertex2f(-.40,-.55);
    glVertex2f(-.58,-.55);
    glVertex2f(-.62,-.60);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(-.40,-.55);
    glVertex2f(-.40,-.60);

    glVertex2f(-.58,-.55);
    glVertex2f(-.58,-.60);
    glEnd();

//car wheel back
    int i;
    x=-.58f; y=-.68f; radius =.03f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
//-----------
	 x=-.58f;  y=-.68f;  radius =.018f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,250);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

//car wheel front
	x=-.34f;  y=-.68f;  radius =.03f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
//-----------------
	x=-.34f;  y=-.68f;  radius =.018f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,250);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    glPopMatrix();

    //Below Car Right
    glPushMatrix();
    glTranslatef(1.18,-.29,0);
    glBegin(GL_POLYGON);
    glColor3ub(0,0,128);
    glVertex2f(-.66,-.60);
    glVertex2f(-.66,-.68);
    glVertex2f(-.28,-.68);
    glVertex2f(-.28,-.62);
    glVertex2f(-.27,-.62);
    glVertex2f(-.28,-.60);
    glVertex2f(-.36,-.60);
    glVertex2f(-.40,-.54);
    glVertex2f(-.60,-.54);
    glVertex2f(-.62,-.62);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-.37,-.60);
    glVertex2f(-.40,-.55);
    glVertex2f(-.58,-.55);
    glVertex2f(-.62,-.60);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(-.40,-.55);
    glVertex2f(-.40,-.60);

    glVertex2f(-.58,-.55);
    glVertex2f(-.58,-.60);
    glEnd();

//car wheel back

    x=-.58f; y=-.68f; radius =.03f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
//-----------
	 x=-.58f;  y=-.68f;  radius =.018f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,250);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

//car wheel front
	x=-.34f;  y=-.68f;  radius =.03f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
//-----------------
	x=-.34f;  y=-.68f;  radius =.018f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,250);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    glPopMatrix();

    //Upper Car
    glPushMatrix();
    glTranslatef(0,-.38,0);
    glBegin(GL_POLYGON);
    glColor3ub(128,0,0);
    glVertex2f(.04,-.24);
    glVertex2f(0.0,-.34);
    glVertex2f(0,-.40);
    glVertex2f(.4,-.40);
    glVertex2f(.4,-.24);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240,255,240);
    glVertex2f(.37,-.26);
    glVertex2f(.30,-.26);
    glVertex2f(.30,-.34);
    glVertex2f(.37,-.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240,255,240);
    glVertex2f(.28,-.26);
    glVertex2f(.22,-.26);
    glVertex2f(.22,-.34);
    glVertex2f(.28,-.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240,255,240);
    glVertex2f(.20,-.26);
    glVertex2f(.14,-.26);
    glVertex2f(.14,-.34);
    glVertex2f(.20,-.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240,255,240);
    glVertex2f(.12,-.26);
    glVertex2f(.05,-.26);
    glVertex2f(.02,-.34);
    glVertex2f(.12,-.34);
    glEnd();
//car wheel front
	x=.08f;  y=-.40f;  radius =.04f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
//-----------------
	x=.08f;  y=-.40f;  radius =.025f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,250);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
//car wheel back
	x=.3f;  y=-.40f;  radius =.04f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
//-----------------
	x=.3f;  y=-.40f;  radius =.025f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,250);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    glPopMatrix();*/



}

//Road side tree
{
    //Left-1
    glPushMatrix();
    glScalef(.5,.4,0);
    glTranslatef(-.9,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();

    int i;

	 x=-.75f;  y=.33f;  radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    GLfloat a=-.68f; GLfloat b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c=-.81f; GLfloat d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e=-.87f; GLfloat f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g=-.61f; GLfloat h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	GLfloat a1=-.61f; GLfloat b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c1=-.88f; GLfloat d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e1=-.87f; GLfloat f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g1=-.61f; GLfloat h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e11=-.64f; GLfloat f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e12=-.75f; GLfloat f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

    GLfloat e123=-.8f; GLfloat f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	GLfloat e1232=-.7f; GLfloat f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();


	//Left-2
    glPushMatrix();
    glScalef(.5,.4,0);
    glTranslatef(.35,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	 x=-.75f;  y=.33f;  radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f;  f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

    e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Left-3
    glPushMatrix();
    glScalef(.5,.4,0);
    glTranslatef(1.6,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	 x=-.75f;  y=.33f;  radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f;  f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

    e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Left-4
    glPushMatrix();
    glScalef(.5,.4,0);
    glTranslatef(2.5,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	 x=-.75f;  y=.33f;  radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f;  f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

    e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

}





//LIGHT Left
    glPushMatrix();
    glTranslatef(-.3,-.65,0);

    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(-.22,.23);
    glVertex2f(-.22,.02);
    glVertex2f(-.21,.02);
    glVertex2f(-.21,.23);
    glEnd();


    //LIGHT Left Top Two
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(-.22,.23);
    glVertex2f(-.21,.23);
    glVertex2f(-.18,.24);
    glVertex2f(-.2,.25);

    glVertex2f(-.21,.23);
    glVertex2f(-.22,.23);
    glVertex2f(-.26,.24);
    glVertex2f(-.23,.25);
    glEnd();
    glLoadIdentity();
    glPopMatrix();


    //LIGHT Right
    glPushMatrix();
    glTranslatef(0,-.65,0);
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(.22,.23);
    glVertex2f(.22,.02);
    glVertex2f(.21,.02);
    glVertex2f(.21,.23);
    glEnd();


    //LIGHT Right Top Two

    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(.22,.23);
    glVertex2f(.21,.23);
    glVertex2f(.18,.24);
    glVertex2f(.2,.25);

    glVertex2f(.21,.23);
    glVertex2f(.22,.23);
    glVertex2f(.26,.24);
    glVertex2f(.23,.25);
    glEnd();
    glLoadIdentity();
    glPopMatrix();







//LIGHT Left
    glPushMatrix();
    glTranslatef(-.75,-.65,0);

    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(-.22,.23);
    glVertex2f(-.22,.02);
    glVertex2f(-.21,.02);
    glVertex2f(-.21,.23);
    glEnd();


    //LIGHT Left Top Two
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(-.22,.23);
    glVertex2f(-.21,.23);
    glVertex2f(-.18,.24);
    glVertex2f(-.2,.25);

    glVertex2f(-.21,.23);
    glVertex2f(-.22,.23);
    glVertex2f(-.26,.24);
    glVertex2f(-.23,.25);
    glEnd();
    glLoadIdentity();
    glPopMatrix();


    //LIGHT Right
    glPushMatrix();
    glTranslatef(.5,-.65,0);
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(.22,.23);
    glVertex2f(.22,.02);
    glVertex2f(.21,.02);
    glVertex2f(.21,.23);
    glEnd();


    //LIGHT Right Top Two

    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(.22,.23);
    glVertex2f(.21,.23);
    glVertex2f(.18,.24);
    glVertex2f(.2,.25);

    glVertex2f(.21,.23);
    glVertex2f(.22,.23);
    glVertex2f(.26,.24);
    glVertex2f(.23,.25);
    glEnd();
    glLoadIdentity();
    glPopMatrix();








//RAINS--------------------------


    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);

    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);

    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);

    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.36f,0.96f);
    glVertex2f(.38f,1.0f);

    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //-------------------

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);

    glVertex2f(-0.06f,0.98f);
    glVertex2f(-.08f,0.94f);

    glVertex2f(-0.09f,1.0f);
    glVertex2f(-.11f,.96f);

    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();





    //RAINS---------------COPY---01


    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(0.02,-.075,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);

    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);

    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.36f,0.96f);
    glVertex2f(.38f,1.0f);

    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //-------------------

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);

    glVertex2f(-0.06f,0.98f);
    glVertex2f(-.08f,0.94f);

    glVertex2f(-0.09f,1.0f);
    glVertex2f(-.11f,.96f);

    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();


    //RAINS---------------COPY---03


    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(0.04,-.15,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);

    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);

    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.36f,0.96f);
    glVertex2f(.38f,1.0f);

    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //-------------------

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);

    glVertex2f(-0.06f,0.98f);
    glVertex2f(-.08f,0.94f);

    glVertex2f(-0.09f,1.0f);
    glVertex2f(-.11f,.96f);

    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();








//RAINS--------------------------FULL COPY


    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(0,.16,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);

    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);

    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.36f,0.96f);
    glVertex2f(.38f,1.0f);

    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //-------------------

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);

    glVertex2f(-0.06f,0.98f);
    glVertex2f(-.08f,0.94f);

    glVertex2f(-0.09f,1.0f);
    glVertex2f(-.11f,.96f);

    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();





    //RAINS---------------COPY---01


    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(0.02,.08,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);

    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);

    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.36f,0.96f);
    glVertex2f(.38f,1.0f);

    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //-------------------

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);

    glVertex2f(-0.06f,0.98f);
    glVertex2f(-.08f,0.94f);

    glVertex2f(-0.09f,1.0f);
    glVertex2f(-.11f,.96f);

    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();


    //RAINS---------------COPY---03


    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(0.04,-.15,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);

    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);

    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.36f,0.96f);
    glVertex2f(.38f,1.0f);

    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //-------------------

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);

    glVertex2f(-0.06f,0.98f);
    glVertex2f(-.08f,0.94f);

    glVertex2f(-0.09f,1.0f);
    glVertex2f(-.11f,.96f);

    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();





    //RAINS--------------------------FULL COPY 0000000001


    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(0,.3,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);

    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);

    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.36f,0.96f);
    glVertex2f(.38f,1.0f);

    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //-------------------

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);

    glVertex2f(-0.06f,0.98f);
    glVertex2f(-.08f,0.94f);

    glVertex2f(-0.09f,1.0f);
    glVertex2f(-.11f,.96f);

    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();





    //RAINS---------------COPY---01     0000000001


    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(0.02,.38,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);

    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);

    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.36f,0.96f);
    glVertex2f(.38f,1.0f);

    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //-------------------

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);

    glVertex2f(-0.06f,0.98f);
    glVertex2f(-.08f,0.94f);

    glVertex2f(-0.09f,1.0f);
    glVertex2f(-.11f,.96f);

    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();


    //RAINS---------------COPY---03    0000000001


    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(0.04,.22,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);

    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);

    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.36f,0.96f);
    glVertex2f(.38f,1.0f);

    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //-------------------

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);

    glVertex2f(-0.06f,0.98f);
    glVertex2f(-.08f,0.94f);

    glVertex2f(-0.09f,1.0f);
    glVertex2f(-.11f,.96f);

    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();



//RAINS--------------------------FULL COPY   0000000002


    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(0,-.22,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);

    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);

    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.36f,0.96f);
    glVertex2f(.38f,1.0f);

    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //-------------------

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);

    glVertex2f(-0.06f,0.98f);
    glVertex2f(-.08f,0.94f);

    glVertex2f(-0.09f,1.0f);
    glVertex2f(-.11f,.96f);

    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();





    //RAINS---------------COPY---01    0000000002


    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(0.02,-.31,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);

    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);

    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.36f,0.96f);
    glVertex2f(.38f,1.0f);

    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //-------------------

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);

    glVertex2f(-0.06f,0.98f);
    glVertex2f(-.08f,0.94f);

    glVertex2f(-0.09f,1.0f);
    glVertex2f(-.11f,.96f);

    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();


    //RAINS---------------COPY---03    0000000002


    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(0.04,-.4,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);

    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);

    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.36f,0.96f);
    glVertex2f(.38f,1.0f);

    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //-------------------

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);

    glVertex2f(-0.06f,0.98f);
    glVertex2f(-.08f,0.94f);

    glVertex2f(-0.09f,1.0f);
    glVertex2f(-.11f,.96f);

    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();



    //RAINS--------------------------FULL COPY   0000000003


    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(0,-.49,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);

    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);

    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.36f,0.96f);
    glVertex2f(.38f,1.0f);

    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //-------------------

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);

    glVertex2f(-0.06f,0.98f);
    glVertex2f(-.08f,0.94f);

    glVertex2f(-0.09f,1.0f);
    glVertex2f(-.11f,.96f);

    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();





    //RAINS---------------COPY---01    0000000003


    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(0.02,-.58,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);

    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);

    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.36f,0.96f);
    glVertex2f(.38f,1.0f);

    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //-------------------

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);

    glVertex2f(-0.06f,0.98f);
    glVertex2f(-.08f,0.94f);

    glVertex2f(-0.09f,1.0f);
    glVertex2f(-.11f,.96f);

    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();


    //RAINS---------------COPY---03     0000000003


    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(0.04,-.67,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);

    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);

    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.36f,0.96f);
    glVertex2f(.38f,1.0f);

    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //-------------------

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);

    glVertex2f(-0.06f,0.98f);
    glVertex2f(-.08f,0.94f);

    glVertex2f(-0.09f,1.0f);
    glVertex2f(-.11f,.96f);

    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();




    //RAINS--------------------------FULL COPY   0000000004


    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(0,-.76,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);

    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);

    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.36f,0.96f);
    glVertex2f(.38f,1.0f);

    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //-------------------

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);

    glVertex2f(-0.06f,0.98f);
    glVertex2f(-.08f,0.94f);

    glVertex2f(-0.09f,1.0f);
    glVertex2f(-.11f,.96f);

    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();





    //RAINS---------------COPY---01    0000000004


    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(0.02,-.85,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);

    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);

    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.36f,0.96f);
    glVertex2f(.38f,1.0f);

    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //-------------------

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);

    glVertex2f(-0.06f,0.98f);
    glVertex2f(-.08f,0.94f);

    glVertex2f(-0.09f,1.0f);
    glVertex2f(-.11f,.96f);

    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();


    //RAINS---------------COPY---03     0000000004


    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(0.04,-.94,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);

    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);

    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.36f,0.96f);
    glVertex2f(.38f,1.0f);

    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //-------------------

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);

    glVertex2f(-0.06f,0.98f);
    glVertex2f(-.08f,0.94f);

    glVertex2f(-0.09f,1.0f);
    glVertex2f(-.11f,.96f);

    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();






        //RAINS--------------------------FULL COPY   0000000005


    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(0,.45,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);

    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);

    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.36f,0.96f);
    glVertex2f(.38f,1.0f);

    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //-------------------

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);

    glVertex2f(-0.06f,0.98f);
    glVertex2f(-.08f,0.94f);

    glVertex2f(-0.09f,1.0f);
    glVertex2f(-.11f,.96f);

    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();





    //RAINS---------------COPY---01    0000000005


    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(0.02,.54,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);

    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);

    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.36f,0.96f);
    glVertex2f(.38f,1.0f);

    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //-------------------

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);

    glVertex2f(-0.06f,0.98f);
    glVertex2f(-.08f,0.94f);

    glVertex2f(-0.09f,1.0f);
    glVertex2f(-.11f,.96f);

    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();


    //RAINS---------------COPY---03     0000000005


    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(0.04,.63,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);

    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);

    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.36f,0.96f);
    glVertex2f(.38f,1.0f);

    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //-------------------

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);

    glVertex2f(-0.06f,0.98f);
    glVertex2f(-.08f,0.94f);

    glVertex2f(-0.09f,1.0f);
    glVertex2f(-.11f,.96f);

    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();



   //glutTimerFunc(8000,displayBack,0);

	glFlush();
}











void rainy(int value)
{
    glutDisplayFunc(rainyView);
}





void nightView()
{
    glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);


//SKY / SUN / CLOUD
{
    //SKY
    glBegin(GL_QUADS);
    glColor3ub(150,151,146);
    glVertex2f(-1,1);
    glVertex2f(-1,.07);
    glVertex2f(1,.07);
    glVertex2f(1,1);
    glEnd();


    //STAR
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    glColor3ub(255,255,255);
//-----------------------
    glVertex2f(-.95,.7);
    glVertex2f(-.9,.65);

    glVertex2f(-.8,.75);

    glVertex2f(-.7,.7);
    glVertex2f(-.6,.72);

    glVertex2f(-.5,.67);
    glVertex2f(-.4,.73);

    glVertex2f(-.3,.68);
    glVertex2f(-.2,.7);

    glVertex2f(-.1,.74);
    glVertex2f(-.9,.79);

    //-----------------

    glVertex2f(-.95,.6);
    glVertex2f(-.9,.65);

    glVertex2f(-.8,.55);

    glVertex2f(-.7,.62);
    glVertex2f(-.6,.52);

    glVertex2f(-.5,.6);
    glVertex2f(-.4,.63);

    glVertex2f(-.3,.66);
    glVertex2f(-.2,.89);

    glVertex2f(-.8,.9);
    glVertex2f(-.5,.85);

    //------------------

    glVertex2f(.95,.7);
    glVertex2f(.9,.65);

    glVertex2f(.8,.75);

    glVertex2f(.7,.7);
    glVertex2f(.6,.72);

    glVertex2f(.5,.67);
    glVertex2f(.4,.73);

    glVertex2f(.3,.68);
    glVertex2f(.2,.7);

    glVertex2f(.1,.74);
    glVertex2f(.9,.79);

    //-----------------

    glVertex2f(.95,.6);
    glVertex2f(.9,.65);

    glVertex2f(.8,.55);

    glVertex2f(.7,.62);
    glVertex2f(.6,.52);

    glVertex2f(.5,.6);
    glVertex2f(.4,.63);

    glVertex2f(.3,.66);
    glVertex2f(.2,.89);

    glVertex2f(.8,.9);
    glVertex2f(.5,.85);


    //---------------


    glVertex2f(.7,.95);
    glVertex2f(.8,.95);

    glVertex2f(.75,.82);
    glVertex2f(.65,.92);

    glVertex2f(.07,.95);
    glVertex2f(.18,.95);

    glVertex2f(.0,.92);
    glVertex2f(-.07,.92);

    glVertex2f(.0,.82);
    glVertex2f(-.07,.72);


    glVertex2f(-.7,.95);

    glVertex2f(-.8,.95);

    glVertex2f(-.75,.82);
    glVertex2f(-.65,.92);


    glEnd();







    //Moon
    int i;
	GLfloat x=-.2f; GLfloat y=.91f; GLfloat radius =.07f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(235, 237, 237);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++){
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();



}

	//1st Left upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-.32,.54);
    glVertex2f(-.32,.49);
    glVertex2f(-.28,.48);
    glVertex2f(-.28,.56);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.28,.54);
    glVertex2f(-.32,.52);

    glVertex2f(-.28,.52);
    glVertex2f(-.24,.5);
    glEnd();

    //LEFT CIRCLE
     GLfloat x=-.3f; GLfloat y=.5f; GLfloat radius =.022f;
     int triangleAmount = 20;
	 GLfloat twicePi = 2.0f * PI;

	 glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	 glEnd();

    //2nd left upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-.28,.56);
    glVertex2f(-.28,.48);
    glVertex2f(-.24,.46);
    glVertex2f(-.24,.55);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.28,.54);
    glVertex2f(-.24,.53);

    glVertex2f(-.28,.52);
    glVertex2f(-.24,.51);

    glVertex2f(-.28,.5);
    glVertex2f(-.24,.49);

    glEnd();

    //3rd left upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-.24,.55);
    glVertex2f(-.24,.52);
    glVertex2f(-.2,.52);
    glVertex2f(-.2,.56);
    glEnd();

    //4th left upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-.2,.58);
    glVertex2f(-.2,.54);
    glVertex2f(-.06,.54);
    glVertex2f(-.06,.595);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.2,.56);
    glVertex2f(-.06,.56);
    glEnd();

    //LEFT CIRCLE TOP
     x=-.14f;  y=.53f;  radius =.04f;
     triangleAmount = 20;
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


    //1st MIDLLE upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-.06,.585);
    glVertex2f(-.06,.46);
    glVertex2f(.06,.46);
    glVertex2f(.06,.585);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(0,.585);
    glVertex2f(0,.46);

    glVertex2f(-.06,.57);
    glVertex2f(.06,.57);

    glVertex2f(-.06,.55);
    glVertex2f(.06,.55);

    glVertex2f(-.06,.525);
    glVertex2f(.06,.525);

    glVertex2f(-.06,.505);
    glVertex2f(.06,.505);

    glVertex2f(-.06,.485);
    glVertex2f(.06,.485);

    glVertex2f(-.06,.46);
    glVertex2f(.06,.46);

    glEnd();

     //2nd MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(16,16,16);
    glVertex2f(-.06,.46);
    glVertex2f(-.06,.4);
    glVertex2f(.06,.4);
    glVertex2f(.06,.46);
    glEnd();


    //3rd MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(-.06,.4);
    glVertex2f(-.06,.38);
    glVertex2f(.06,.38);
    glVertex2f(.06,.4);
    glEnd();

    //4th MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(21,21,21);
    glVertex2f(-.06,.38);
    glVertex2f(-.06,.32);
    glVertex2f(.06,.32);
    glVertex2f(.06,.38);
    glEnd();

    //5th MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(-.06,.32);
    glVertex2f(-.06,.3);
    glVertex2f(.06,.3);
    glVertex2f(.06,.32);
    glEnd();


    //5th MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(21,21,21);
    glVertex2f(-.06,.3);
    glVertex2f(-.06,.26);
    glVertex2f(.06,.26);
    glVertex2f(.06,.3);
    glEnd();

    //6th MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(80,80,80);
    glVertex2f(-.06,.26);
    glVertex2f(-.06,.24);
    glVertex2f(.06,.24);
    glVertex2f(.06,.26);
    glEnd();

    //7th MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(-.06,.24);
    glVertex2f(-.06,.2);
    glVertex2f(.06,.2);
    glVertex2f(.06,.24);
    glEnd();


    //5th MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(-.06,.2);
    glVertex2f(-.06,.16);
    glVertex2f(.06,.16);
    glVertex2f(.06,.2);
    glEnd();








    //1st RIGHT upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(.32,.54);
    glVertex2f(.32,.49);
    glVertex2f(.28,.48);
    glVertex2f(.28,.56);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.28,.54);
    glVertex2f(.32,.52);

    glVertex2f(.28,.52);
    glVertex2f(.24,.5);


    glEnd();

    //RIGHT CIRCLE
      x=.3f; y=.5f;  radius =.022f;
      triangleAmount = 20;
	  twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


    //2nd RIGHT upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(.28,.56);
    glVertex2f(.28,.48);
    glVertex2f(.24,.46);
    glVertex2f(.24,.55);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.28,.54);
    glVertex2f(.24,.53);

    glVertex2f(.28,.52);
    glVertex2f(.24,.51);


    glVertex2f(.28,.5);
    glVertex2f(.24,.49);


    glEnd();

    //3rd RIGHT upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(.24,.55);
    glVertex2f(.24,.52);
    glVertex2f(.2,.52);
    glVertex2f(.2,.56);
    glEnd();

    //4th RIGHT upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(.2,.58);
    glVertex2f(.2,.54);
    glVertex2f(.06,.54);
    glVertex2f(.06,.595);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.2,.56);
    glVertex2f(.06,.56);
    glEnd();

    // CIRCLE RIGHT
     x=.14f;  y=.53f;  radius =.04f;
     triangleAmount = 20;
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();








{

    //1stLeft
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.81,.41);
    glVertex2f(-.81,.19);
    glVertex2f(-.7,.19);
    glVertex2f(-.7,.41);
    glEnd();



    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.765,.41);
    glVertex2f(-.765,.19);



    glEnd();




    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.81,.38);
    glVertex2f(-.7,.38);

    glVertex2f(-.81,.35);
    glVertex2f(-.7,.35);

    glVertex2f(-.81,.32);
    glVertex2f(-.7,.32);

    glVertex2f(-.81,.29);
    glVertex2f(-.7,.29);

    glVertex2f(-.81,.26);
    glVertex2f(-.7,.26);

    glVertex2f(-.81,.23);
    glVertex2f(-.7,.23);

    glVertex2f(-.81,.20);
    glVertex2f(-.7,.20);



    glEnd();

    //second Left
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.71,.43);
    glVertex2f(-.71,.17);
    glVertex2f(-.58,.17);
    glVertex2f(-.58,.45);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.67,.17);
    glVertex2f(-.67,.438);

    glVertex2f(-.62,.17);
    glVertex2f(-.62,.445);

    glEnd();




    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.71,.4);
    glVertex2f(-.58,.42);

    glVertex2f(-.71,.37);
    glVertex2f(-.58,.39);

    glVertex2f(-.71,.34);
    glVertex2f(-.58,.36);

    glVertex2f(-.71,.31);
    glVertex2f(-.58,.33);

    glVertex2f(-.71,.28);
    glVertex2f(-.58,.30);

    glVertex2f(-.71,.25);
    glVertex2f(-.58,.27);

    glVertex2f(-.71,.22);
    glVertex2f(-.58,.24);

    glVertex2f(-.71,.19);
    glVertex2f(-.58,.21);

    glVertex2f(-.71,.16);
    glVertex2f(-.58,.18);

    glEnd();


    //Middle of 2 ,3 Left
    glBegin(GL_QUADS);
    glColor3ub(100,100,100);
    glVertex2f(-.58,.44);
    glVertex2f(-.58,.38);
    glVertex2f(-.56,.38);
    glVertex2f(-.56,.445);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-.58,.38);
    glVertex2f(-.58,.16);
    glVertex2f(-.56,.16);
    glVertex2f(-.56,.38);
    glEnd();

    //3rd left
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.56,.46);
    glVertex2f(-.56,.16);
    glVertex2f(-.42,.16);
    glVertex2f(-.42,.5);
    glEnd();


     glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.45,.16);
    glVertex2f(-.45,.49);

    glVertex2f(-.52,.16);
    glVertex2f(-.52,.48);

    glEnd();




    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.56,.43);
    glVertex2f(-.42,.47);

    glVertex2f(-.56,.4);
    glVertex2f(-.42,.44);

    glVertex2f(-.56,.37);
    glVertex2f(-.42,.41);

    glVertex2f(-.56,.34);
    glVertex2f(-.42,.38);

    glVertex2f(-.56,.31);
    glVertex2f(-.42,.35);

    glVertex2f(-.56,.28);
    glVertex2f(-.42,.32);

    glVertex2f(-.56,.25);
    glVertex2f(-.42,.29);

    glVertex2f(-.56,.22);
    glVertex2f(-.42,.26);

    glVertex2f(-.56,.19);
    glVertex2f(-.42,.23);

    glEnd();

    //4th left
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.42,.5);
    glVertex2f(-.42,.13);
    glVertex2f(-.24,.13);
    glVertex2f(-.24,.48);
    glEnd();

    //5th left
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.24,.54);
    glVertex2f(-.24,.13);
    glVertex2f(-.04,.13);
    glVertex2f(-.04,.54);
    glEnd();



    //Left 1st Triangle
    //1stLeft
    glBegin(GL_TRIANGLES);
    glColor3ub(1,1,1);
    glVertex2f(-.67,.4);
    glVertex2f(-.695,.24);
    glVertex2f(-.65,.25);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(217,217,217);
    glVertex2f(-.67,.27);
    glVertex2f(-.69,.24);
    glVertex2f(-.65,.25);
    glVertex2f(-.65,.27);

    glEnd();


    //2nd Left
    glBegin(GL_TRIANGLES);
    glColor3ub(1,1,1);
    glVertex2f(-.45,.43);
    glVertex2f(-.49,.26);
    glVertex2f(-.43,.27);
    glEnd();

//LEFT TRIANGLE INSIDE
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.45,.428);
    glVertex2f(-.45,.268);
    glVertex2f(-.443,.268);
    glVertex2f(-.443,.428);

    glVertex2f(-.47,.38);
    glVertex2f(-.47,.373);
    glVertex2f(-.44,.373);
    glVertex2f(-.44,.38);

    glVertex2f(-.47,.35);
    glVertex2f(-.47,.343);
    glVertex2f(-.44,.343);
    glVertex2f(-.44,.35);

    glVertex2f(-.48,.32);
    glVertex2f(-.48,.313);
    glVertex2f(-.43,.313);
    glVertex2f(-.43,.32);

    glVertex2f(-.485,.29);
    glVertex2f(-.485,.283);
    glVertex2f(-.43,.283);
    glVertex2f(-.43,.29);
    glEnd();

    //Under triangle a BOX 1
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-.49,.22);
    glVertex2f(-.49,.17);
    glVertex2f(-.43,.17);
    glVertex2f(-.43,.22);
    glEnd();

    //INSIDE BOX LEFT
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.458,.22);
    glVertex2f(-.458,.17);
    glVertex2f(-.45,.17);
    glVertex2f(-.45,.22);

    glVertex2f(-.49,.195);
    glVertex2f(-.49,.19);
    glVertex2f(-.43,.19);
    glVertex2f(-.43,.195);

    glEnd();



    //Under triangle a BOX 2
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-.695,.21);
    glVertex2f(-.695,.18);
    glVertex2f(-.65,.18);
    glVertex2f(-.65,.21);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(217,217,217);
    glVertex2f(-.695,.21);
    glVertex2f(-.69,.2);
    glVertex2f(-.65,.2);
    glVertex2f(-.65,.21);

    glEnd();





    //LEFTBOTTOM Polygon 1
    glBegin(GL_QUADS);
    glColor3ub(80,0,0);
    glVertex2f(-.82,.19);
    glVertex2f(-.82,.07);
    glVertex2f(-.5,.12);
    glVertex2f(-.68,.19);
    glEnd();

    //LEFTBOTTOM Polygon 2
    glBegin(GL_QUADS);
    glColor3ub(80,0,0);
    glVertex2f(-.56,.17);
    glVertex2f(-.465,.13);
    glVertex2f(-.32,.13);
    glVertex2f(-.43,.17);

    glEnd();




    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.28,.13);
    glVertex2f(-.28,.48);

    glVertex2f(-.37,.16);
    glVertex2f(-.37,.5);



    glEnd();


    //Right 2
    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);


    glVertex2f(-.24,.46);
    glVertex2f(-.42,.48);

    glVertex2f(-.24,.43);
    glVertex2f(-.42,.45);

    glVertex2f(-.24,.4);
    glVertex2f(-.42,.42);

    glVertex2f(-.24,.37);
    glVertex2f(-.42,.39);

    glVertex2f(-.24,.34);
    glVertex2f(-.42,.36);

    glVertex2f(-.24,.31);
    glVertex2f(-.42,.33);

    glVertex2f(-.24,.28);
    glVertex2f(-.42,.30);

    glVertex2f(-.24,.25);
    glVertex2f(-.42,.27);

    glVertex2f(-.24,.22);
    glVertex2f(-.42,.24);

    glVertex2f(-.24,.19);
    glVertex2f(-.42,.21);

    glVertex2f(-.24,.16);
    glVertex2f(-.42,.18);

    glEnd();



    //LEFT CIRCLE


	 x=-.34f;  y=.255f;  radius =.06f;
     triangleAmount = 20;
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

//Left inside circle
 glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.36,.315);
    glVertex2f(-.36,.2);
    glVertex2f(-.352,.2);
    glVertex2f(-.352,.315);

    glVertex2f(-.33,.315);
    glVertex2f(-.33,.2);
    glVertex2f(-.322,.2);
    glVertex2f(-.322,.315);

    glVertex2f(-.4,.28);
    glVertex2f(-.4,.273);
    glVertex2f(-.25,.273);
    glVertex2f(-.25,.28);

    glVertex2f(-.4,.24);
    glVertex2f(-.4,.233);
    glVertex2f(-.25,.233);
    glVertex2f(-.25,.24);

    glEnd();




	//RIGHT BUILDING

    //1st Right
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.05,.54);
    glVertex2f(.05,.13);
    glVertex2f(.25,.13);
    glVertex2f(.25,.54);
    glEnd();

    //2nd Right
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.42,.5);
    glVertex2f(.42,.13);
    glVertex2f(.25,.13);
    glVertex2f(.25,.48);
    glEnd();

    //3rd Right
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.56,.46);
    glVertex2f(.56,.16);
    glVertex2f(.42,.16);
    glVertex2f(.42,.5);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.45,.16);
    glVertex2f(.45,.49);

    glVertex2f(.52,.16);
    glVertex2f(.52,.48);
    glEnd();

    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.56,.43);
    glVertex2f(.42,.47);

    glVertex2f(.56,.4);
    glVertex2f(.42,.44);

    glVertex2f(.56,.37);
    glVertex2f(.42,.41);

    glVertex2f(.56,.34);
    glVertex2f(.42,.38);

    glVertex2f(.56,.31);
    glVertex2f(.42,.35);

    glVertex2f(.56,.28);
    glVertex2f(.42,.32);

    glVertex2f(.56,.25);
    glVertex2f(.42,.29);

    glVertex2f(.56,.22);
    glVertex2f(.42,.26);

    glVertex2f(.56,.19);
    glVertex2f(.42,.23);

    glEnd();

    //Middle of 3 ,4 Right
    glBegin(GL_QUADS);
    glColor3ub(100,100,100);
    glVertex2f(.58,.44);
    glVertex2f(.58,.38);
    glVertex2f(.56,.38);
    glVertex2f(.56,.445);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.58,.38);
    glVertex2f(.58,.16);
    glVertex2f(.56,.16);
    glVertex2f(.56,.38);
    glEnd();

	//4th Right
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.71,.43);
    glVertex2f(.71,.17);
    glVertex2f(.58,.17);
    glVertex2f(.58,.45);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.67,.17);
    glVertex2f(.67,.438);

    glVertex2f(.62,.17);
    glVertex2f(.62,.445);

    glEnd();

    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.71,.4);
    glVertex2f(.58,.42);

    glVertex2f(.71,.37);
    glVertex2f(.58,.39);

    glVertex2f(.71,.34);
    glVertex2f(.58,.36);

    glVertex2f(.71,.31);
    glVertex2f(.58,.33);

    glVertex2f(.71,.28);
    glVertex2f(.58,.30);

    glVertex2f(.71,.25);
    glVertex2f(.58,.27);

    glVertex2f(.71,.22);
    glVertex2f(.58,.24);

    glVertex2f(.71,.19);
    glVertex2f(.58,.21);

    glVertex2f(.71,.16);
    glVertex2f(.58,.18);
    glEnd();

    //5th Right
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.81,.41);
    glVertex2f(.81,.19);
    glVertex2f(.7,.19);
    glVertex2f(.7,.41);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.765,.41);
    glVertex2f(.765,.19);
    glEnd();

    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.81,.38);
    glVertex2f(.7,.38);

    glVertex2f(.81,.35);
    glVertex2f(.7,.35);

    glVertex2f(.81,.32);
    glVertex2f(.7,.32);

    glVertex2f(.81,.29);
    glVertex2f(.7,.29);

    glVertex2f(.81,.26);
    glVertex2f(.7,.26);

    glVertex2f(.81,.23);
    glVertex2f(.7,.23);

    glVertex2f(.81,.20);
    glVertex2f(.7,.20);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.28,.13);
    glVertex2f(.28,.48);

    glVertex2f(.37,.13);
    glVertex2f(.37,.5);
    glEnd();

    //Right 2
    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);


    glVertex2f(.25,.46);
    glVertex2f(.42,.48);

    glVertex2f(.25,.43);
    glVertex2f(.42,.45);

    glVertex2f(.25,.4);
    glVertex2f(.42,.42);

    glVertex2f(.25,.37);
    glVertex2f(.42,.39);

    glVertex2f(.25,.34);
    glVertex2f(.42,.36);

    glVertex2f(.25,.31);
    glVertex2f(.42,.33);

    glVertex2f(.25,.28);
    glVertex2f(.42,.30);

    glVertex2f(.25,.25);
    glVertex2f(.42,.27);

    glVertex2f(.25,.22);
    glVertex2f(.42,.24);

    glVertex2f(.25,.19);
    glVertex2f(.42,.21);

    glVertex2f(.25,.16);
    glVertex2f(.42,.18);

    glVertex2f(.25,.13);
    glVertex2f(.42,.15);
    glEnd();

    //RIGHT CIRCLE
	 x=.34f;  y=.255f;  radius =.06f;
     triangleAmount = 20;
	 twicePi = 2.0f * PI;

	 glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	 glEnd();



	 //RIGHT inside circle
 glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.36,.315);
    glVertex2f(.36,.2);
    glVertex2f(.352,.2);
    glVertex2f(.352,.315);

    glVertex2f(.33,.315);
    glVertex2f(.33,.2);
    glVertex2f(.322,.2);
    glVertex2f(.322,.315);

    glVertex2f(.4,.28);
    glVertex2f(.4,.273);
    glVertex2f(.25,.273);
    glVertex2f(.25,.28);

    glVertex2f(.4,.24);
    glVertex2f(.4,.233);
    glVertex2f(.25,.233);
    glVertex2f(.25,.24);

    glEnd();




    //RIGHT 1st Triangle
    //1stRight
    glBegin(GL_TRIANGLES);
    glColor3ub(1,1,1);
    glVertex2f(.67,.4);
    glVertex2f(.695,.24);
    glVertex2f(.65,.25);
    glEnd();
    //SHADE INSIDE
    glBegin(GL_QUADS);
    glColor3ub(217,217,217);
    glVertex2f(.67,.27);
    glVertex2f(.69,.24);
    glVertex2f(.65,.25);
    glVertex2f(.65,.27);

    glEnd();

    //2nd RIGHT
    glBegin(GL_TRIANGLES);
    glColor3ub(1,1,1);
    glVertex2f(.45,.43);
    glVertex2f(.49,.26);
    glVertex2f(.43,.27);
    glEnd();



    //RIGHT TRIANGLE INSIDE
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.45,.428);
    glVertex2f(.45,.268);
    glVertex2f(.443,.268);
    glVertex2f(.443,.428);

    glVertex2f(.47,.38);
    glVertex2f(.47,.373);
    glVertex2f(.44,.373);
    glVertex2f(.44,.38);

    glVertex2f(.47,.35);
    glVertex2f(.47,.343);
    glVertex2f(.44,.343);
    glVertex2f(.44,.35);

    glVertex2f(.48,.32);
    glVertex2f(.48,.313);
    glVertex2f(.43,.313);
    glVertex2f(.43,.32);

    glVertex2f(.485,.29);
    glVertex2f(.485,.283);
    glVertex2f(.43,.283);
    glVertex2f(.43,.29);
    glEnd();



    //Under triangle a BOX RIGHT
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.49,.22);
    glVertex2f(.49,.17);
    glVertex2f(.43,.17);
    glVertex2f(.43,.22);
    glEnd();


     //INSIDE BOX
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.458,.22);
    glVertex2f(.458,.17);
    glVertex2f(.45,.17);
    glVertex2f(.45,.22);

    glVertex2f(.49,.195);
    glVertex2f(.49,.19);
    glVertex2f(.43,.19);
    glVertex2f(.43,.195);

    glEnd();

    //Under triangle a BOX 2
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.695,.21);
    glVertex2f(.695,.18);
    glVertex2f(.65,.18);
    glVertex2f(.65,.21);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(217,217,217);
    glVertex2f(.695,.21);
    glVertex2f(.69,.2);
    glVertex2f(.65,.2);
    glVertex2f(.65,.21);

    glEnd();




    //RIGHT BOTTOM Polygon 1
    glBegin(GL_QUADS);
    glColor3ub(80,0,0);
    glVertex2f(.82,.19);
    glVertex2f(.82,.07);
    glVertex2f(.5,.12);
    glVertex2f(.68,.19);
    glEnd();

    //RIGHT BOTTOM Polygon 2
    glBegin(GL_QUADS);
    glColor3ub(80,0,0);
    glVertex2f(.56,.17);
    glVertex2f(.465,.13);
    glVertex2f(.32,.13);
    glVertex2f(.43,.17);
    glEnd();


     //FLAG QUAD  2
    glBegin(GL_QUADS);
    glColor3ub(178,34,34);
    glVertex2f(-.08,.16);
    glVertex2f(-.082,.1);
    glVertex2f(.082,.1);
    glVertex2f(.08,.16);
    glEnd();

    //FLAG QUAD 1
    glBegin(GL_QUADS);
    glColor3ub(80,0,0);
    glVertex2f(-.06,.16);
    glVertex2f(-.06,.1);
    glVertex2f(.06,.1);
    glVertex2f(.06,.16);
    glEnd();

    //FLAG QUAD
    glBegin(GL_QUADS);
    glColor3ub(220,220,220);
    glVertex2f(-.08,.16);
    glVertex2f(-.082,.12);
    glVertex2f(-.06,.12);
    glVertex2f(-.06,.16);
    glEnd();

    //FLAG QUAD
    glBegin(GL_QUADS);
    glColor3ub(220,220,220);
    glVertex2f(.08,.16);
    glVertex2f(.082,.12);
    glVertex2f(.06,.12);
    glVertex2f(.06,.16);
    glEnd();

    //FLAG QUAD CIRCLE
     x=0.0f;  y=.075f;  radius =.05f;
     triangleAmount = 20;
	 twicePi = 2.0f * PI;

	 glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	 glEnd();

	//White ROAD QUADS LEFT
	//1st White
    glBegin(GL_POLYGON);
    glColor3ub(190, 191, 191);
    glVertex2f(-.8,.07);
    glVertex2f(-.88,.07);
    glVertex2f(-1,.07);
    glVertex2f(-1,0);
    glVertex2f(-.8,0);
    glEnd();

	//2nd White
    glBegin(GL_QUADS);
    glColor3ub(190, 191, 191);
    glVertex2f(-.8,.07);
    glVertex2f(-.8,0);
    glVertex2f(-.58,0);
    glVertex2f(-.58,.11);
    glEnd();

    //3rd White
    glBegin(GL_POLYGON);
    glColor3ub(190, 191, 191);
    glVertex2f(-.58,.11);
    glVertex2f(-.58,0);
    glVertex2f(-.082,0);
    glVertex2f(-.08,.13);
    glVertex2f(-.32,.13);
    glVertex2f(-.46,.13);
    glEnd();


    //White ROAD QUADS RIGHT
	//1st White
    glBegin(GL_POLYGON);
    glColor3ub(190, 191, 191);
    glVertex2f(.8,.07);
    glVertex2f(.88,.07);
    glVertex2f(1,.07);
    glVertex2f(1,0);
    glVertex2f(.8,0);
    glEnd();

	//2nd White
    glBegin(GL_QUADS);
    glColor3ub(190, 191, 191);
    glVertex2f(.8,.07);
    glVertex2f(.8,0);
    glVertex2f(.58,0);
    glVertex2f(.58,.11);
    glEnd();

    //3rd White
    glBegin(GL_POLYGON);
    glColor3ub(190, 191, 191);
    glVertex2f(.58,.11);
    glVertex2f(.58,0);
    glVertex2f(.082,0);
    glVertex2f(.08,.13);
    glVertex2f(.32,.13);
    glVertex2f(.46,.13);
    glEnd();


    //MIDLE White QUAD
    glBegin(GL_QUADS);
    glColor3ub(190, 191, 191);
    glVertex2f(-.082,.1);
    glVertex2f(-.082,0);
    glVertex2f(.082,0);
    glVertex2f(.082,.1);
    glEnd();

    //WHITE SHIRI LEFT 1
    glBegin(GL_QUADS);
    glColor3ub(181, 183, 183);
    glVertex2f(-.62,.17);
    glVertex2f(-.53,.12);
    glVertex2f(-.44,.12);
    glVertex2f(-.56,.17);
    glEnd();


    //WHITE SHIRI Right
    glBegin(GL_QUADS);
    glColor3ub(181, 183, 183);
    glVertex2f(.62,.17);
    glVertex2f(.53,.12);
    glVertex2f(.44,.12);
    glVertex2f(.56,.17);
    glEnd();

    //LEFT 2nd SHIRI
    glBegin(GL_QUADS);
    glColor3ub(181, 183, 183);
    glVertex2f(-.43,.17);
    glVertex2f(-.33,.13);
    glVertex2f(-.3,.13);
    glVertex2f(-.41,.17);
    glEnd();

    //RIGHT 2nd SHIRI
    glBegin(GL_QUADS);
    glColor3ub(181, 183, 183);
    glVertex2f(.43,.17);
    glVertex2f(.33,.13);
    glVertex2f(.3,.13);
    glVertex2f(.41,.17);
    glEnd();

    //BD FLAG STAND
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(238,232,170);
    glVertex2f(0,.16);
    glVertex2f(0,.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,102,0);
    glVertex2f(0,.29);
    glVertex2f(0,.25);
    glVertex2f(.02,.24);
    glVertex2f(.025,.27);
    glEnd();


    //FLAG CIRCLE
     x=0.01f;  y=.265f;  radius =.007f;
     triangleAmount = 20;
	 twicePi = 2.0f * PI;

	 glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(204,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	 glEnd();



	//LINES
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.12,.54);
    glVertex2f(.12,.13);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);

    //RIGHT 1
    glVertex2f(-.11,.54);
    glVertex2f(-.11,.13);
    glEnd();

    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.05,.54);
    glVertex2f(.25,.54);

    glVertex2f(.05,.51);
    glVertex2f(.25,.51);

    glVertex2f(.05,.48);
    glVertex2f(.25,.48);

    glVertex2f(.05,.45);
    glVertex2f(.25,.45);

    glVertex2f(.05,.42);
    glVertex2f(.25,.42);

    glVertex2f(.05,.39);
    glVertex2f(.25,.39);

    glVertex2f(.05,.36);
    glVertex2f(.25,.36);

    glVertex2f(.05,.33);
    glVertex2f(.25,.33);

    glVertex2f(.05,.30);
    glVertex2f(.25,.30);

    glVertex2f(.05,.27);
    glVertex2f(.25,.27);

    glVertex2f(.05,.24);
    glVertex2f(.25,.24);

    glVertex2f(.05,.21);
    glVertex2f(.25,.21);

    glVertex2f(.05,.18);
    glVertex2f(.25,.18);

    glVertex2f(.08,.15);
    glVertex2f(.25,.15);


    //LEFT 5
    glVertex2f(-.04,.54);
    glVertex2f(-.24,.54);

    glVertex2f(-.04,.51);
    glVertex2f(-.24,.51);

    glVertex2f(-.04,.48);
    glVertex2f(-.24,.48);

    glVertex2f(-.04,.45);
    glVertex2f(-.24,.45);

    glVertex2f(-.04,.42);
    glVertex2f(-.24,.42);

    glVertex2f(-.04,.39);
    glVertex2f(-.24,.39);

    glVertex2f(-.04,.36);
    glVertex2f(-.24,.36);

    glVertex2f(-.04,.33);
    glVertex2f(-.24,.33);

    glVertex2f(-.04,.30);
    glVertex2f(-.24,.30);

    glVertex2f(-.04,.27);
    glVertex2f(-.24,.27);

    glVertex2f(-.04,.24);
    glVertex2f(-.24,.24);

    glVertex2f(-.04,.21);
    glVertex2f(-.24,.21);

    glVertex2f(-.04,.18);
    glVertex2f(-.24,.18);

    glVertex2f(-.07,.15);
    glVertex2f(-.24,.15);

    glVertex2f(.25,.13);
    glVertex2f(.25,.54);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(105,105,105);
    glVertex2f(.25,.13);
    glVertex2f(.25,.54);

    glVertex2f(-.24,.13);
    glVertex2f(-.24,.54);

    glVertex2f(.42,.5);
    glVertex2f(.42,.17);

    glVertex2f(-.42,.5);
    glVertex2f(-.42,.17);

    glVertex2f(-.71,.43);
    glVertex2f(-.71,.19);

    glVertex2f(.71,.43);
    glVertex2f(.71,.19);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.06,.595);
    glVertex2f(-.06,.54);

    glVertex2f(.06,.595);
    glVertex2f(.06,.54);

    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);


    glVertex2f(-.77,.16);
    glVertex2f(-.77,.08);

    glVertex2f(-.7,.16);
    glVertex2f(-.7,.09);

    glVertex2f(-.64,.15);
    glVertex2f(-.64,.1);


    glVertex2f(.77,.16);
    glVertex2f(.77,.08);

    glVertex2f(.7,.16);
    glVertex2f(.7,.09);

    glVertex2f(.64,.15);
    glVertex2f(.64,.1);
    glEnd();



    //LIGHT Left
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(-.22,.23);
    glVertex2f(-.22,.13);
    glVertex2f(-.21,.13);
    glVertex2f(-.21,.23);
    glEnd();

    //LIGHT Left Top Two
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(-.22,.23);
    glVertex2f(-.21,.23);
    glVertex2f(-.18,.24);
    glVertex2f(-.2,.25);

    glVertex2f(-.21,.23);
    glVertex2f(-.22,.23);
    glVertex2f(-.26,.24);
    glVertex2f(-.23,.25);
    glEnd();


    //LIGHT Right
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(.22,.23);
    glVertex2f(.22,.13);
    glVertex2f(.21,.13);
    glVertex2f(.21,.23);
    glEnd();


    //LIGHT Right Top Two
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(.22,.23);
    glVertex2f(.21,.23);
    glVertex2f(.18,.24);
    glVertex2f(.2,.25);

    glVertex2f(.21,.23);
    glVertex2f(.22,.23);
    glVertex2f(.26,.24);
    glVertex2f(.23,.25);
    glEnd();


    //ON LIGHT Left Top Two
    glBegin(GL_QUADS);
    glColor3ub(211, 228, 86);

    glVertex2f(-.19,.23);
    glVertex2f(-.2,.24);
    glVertex2f(-.21,.13);
    glVertex2f(-.15,.13);


    glVertex2f(-.24,.23);
    glVertex2f(-.23,.24);
    glVertex2f(-.225,.13);
    glVertex2f(-.29,.13);
    glEnd();






 //ON LIGHT Right Top Two
    glBegin(GL_QUADS);
    glColor3ub(211, 228, 86);

    glVertex2f(.19,.23);
    glVertex2f(.2,.24);
    glVertex2f(.21,.13);
    glVertex2f(.15,.13);


    glVertex2f(.24,.23);
    glVertex2f(.23,.24);
    glVertex2f(.225,.13);
    glVertex2f(.29,.13);
    glEnd();




    /*

    //BIRD
{

    int i;
	GLfloat mm=0.182f; GLfloat nn=.801f; GLfloat radiusmm =.01f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(225, 225, 208);
    glVertex2f(mm, nn); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.11f,0.79f);
    glVertex2f(0.12f,0.78f);
    glVertex2f(0.16f,0.77f);
    glVertex2f(0.19f,0.79f);
    glVertex2f(0.201f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.14f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.144f,0.8f);
    glVertex2f(0.12f,0.83f);
    glEnd();
	/////2nd bird////
	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.02f,0.8f);
    glVertex2f(-0.01f,0.79f);
    glVertex2f(0.0f,0.78f);
    glVertex2f(0.04f,0.77f);
    glVertex2f(0.07f,0.79f);
    glVertex2f(0.081f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.03f,0.8f);
    glVertex2f(0.02f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.024f,0.8f);
    glVertex2f(0.0f,0.83f);
    glEnd();

	GLfloat mmm=0.062f; GLfloat nnn=.801f; GLfloat radiusmmm =.01f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmm, nnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
			    nnn + (radiusmmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	/////3rd bird/////
	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.72f,0.8f);
    glVertex2f(-0.71f,0.79f);
    glVertex2f(-0.7f,0.78f);
    glVertex2f(-0.66f,0.77f);
    glVertex2f(-0.63f,0.79f);
    glVertex2f(-0.619f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.67f,0.8f);
    glVertex2f(-0.68f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.676f,0.8f);
    glVertex2f(-0.7f,0.83f);
    glEnd();

	GLfloat mmmm=-0.638f; GLfloat nnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmmm,nnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
			    nnnn + (radiusmmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	////4th bird////
	GLfloat mmmmm=-0.518f; GLfloat nnnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmmmm, nnnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmmmm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nnnnn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.59f,0.79f);
    glVertex2f(-0.58f,0.78f);
    glVertex2f(-0.54f,0.77f);
    glVertex2f(-0.51f,0.79f);
    glVertex2f(-0.499f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.56f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.556f,0.8f);
    glVertex2f(-0.58f,0.83f);
    glEnd();

    //Bird-Copy
    {
    glPushMatrix();
    glTranslatef(.07,-.07,0);
    int i;
	GLfloat mm=0.182f; GLfloat nn=.801f; GLfloat radiusmm =.01f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(225, 225, 208);
    glVertex2f(mm, nn); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.11f,0.79f);
    glVertex2f(0.12f,0.78f);
    glVertex2f(0.16f,0.77f);
    glVertex2f(0.19f,0.79f);
    glVertex2f(0.201f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.14f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.144f,0.8f);
    glVertex2f(0.12f,0.83f);
    glEnd();
	/////2nd bird////
	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.02f,0.8f);
    glVertex2f(-0.01f,0.79f);
    glVertex2f(0.0f,0.78f);
    glVertex2f(0.04f,0.77f);
    glVertex2f(0.07f,0.79f);
    glVertex2f(0.081f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.03f,0.8f);
    glVertex2f(0.02f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.024f,0.8f);
    glVertex2f(0.0f,0.83f);
    glEnd();

	GLfloat mmm=0.062f; GLfloat nnn=.801f; GLfloat radiusmmm =.01f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmm, nnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
			    nnn + (radiusmmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	/////3rd bird/////
	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.72f,0.8f);
    glVertex2f(-0.71f,0.79f);
    glVertex2f(-0.7f,0.78f);
    glVertex2f(-0.66f,0.77f);
    glVertex2f(-0.63f,0.79f);
    glVertex2f(-0.619f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.67f,0.8f);
    glVertex2f(-0.68f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.676f,0.8f);
    glVertex2f(-0.7f,0.83f);
    glEnd();

	GLfloat mmmm=-0.638f; GLfloat nnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmmm,nnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
			    nnnn + (radiusmmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	////4th bird////
	GLfloat mmmmm=-0.518f; GLfloat nnnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmmmm, nnnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmmmm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nnnnn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.59f,0.79f);
    glVertex2f(-0.58f,0.78f);
    glVertex2f(-0.54f,0.77f);
    glVertex2f(-0.51f,0.79f);
    glVertex2f(-0.499f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.56f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.556f,0.8f);
    glVertex2f(-0.58f,0.83f);
    glEnd();
    glPopMatrix();
    }

}

*/

    //Field Upper
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-1,0);
    glVertex2f(-1,-.03);
    glVertex2f(1,-.03);
    glVertex2f(1,0);
    glEnd();

    //Lower field
    glBegin(GL_QUADS);
    glColor3ub(34,139,34);
    glVertex2f(-1,-.03);
    glVertex2f(-1,-.6);
    glVertex2f(1,-.6);
    glVertex2f(1,-.03);
    glEnd();




//TREE
{
    //Tree-round left-1
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(-2.9,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();

    int i;

	GLfloat x=-.75f; GLfloat y=.33f; GLfloat radius =.06f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    GLfloat a=-.68f; GLfloat b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c=-.81f; GLfloat d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e=-.87f; GLfloat f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g=-.61f; GLfloat h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	GLfloat a1=-.61f; GLfloat b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c1=-.88f; GLfloat d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e1=-.87f; GLfloat f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g1=-.61f; GLfloat h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e11=-.64f; GLfloat f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e12=-.75f; GLfloat f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

    GLfloat e123=-.8f; GLfloat f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	GLfloat e1232=-.7f; GLfloat f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-2
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(-2.1,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-3
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(-1.3,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-4
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(-.5,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(560, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-5
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(.3,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-6
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(1.1,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-7
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(1.9,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-8
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(2.7,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-9
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(3.5,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-10
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(4.3,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();


    //Background Tree

    //Left Back tree
    glPushMatrix();
    glScalef(.6,.6,0);
    glTranslatef(-.97f,-.335f,0.0f);
    glBegin(GL_POLYGON);
	glColor3ub(102, 51, 0);
	glVertex2f(-0.52f,0.45f);
	glVertex2f(-0.48f, 0.45f);
	glVertex2f(-0.48f,0.62f);
    glVertex2f(-0.5f,0.64f);
    glVertex2f(-0.52f,0.62f);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(34,139,34);
    glVertex2f(-0.5f,0.64f);
    glVertex2f(-0.52f,0.62f);
    glVertex2f(-0.58f,0.6f);
	glVertex2f(-0.55f, 0.63f);
	glVertex2f(-0.58f,0.66f);
	glVertex2f(-0.52f,0.66f);
	glVertex2f(-0.52f, 0.72f);
	glVertex2f(-0.5f,0.69f);
	glVertex2f(-0.48f,0.72f);
	glVertex2f(-0.48f, 0.66f);
	glVertex2f(-0.42f,0.66f);
	glVertex2f(-0.45f,0.63f);
	glVertex2f(-0.42f, 0.6f);
	glVertex2f(-0.48f,0.62f);
    glEnd();
    glPopMatrix();

    //Right Back Tree
    glPushMatrix();
    glScalef(.6,.6,0);
    glTranslatef(.97f,-.335f,0.0f);
    glBegin(GL_POLYGON);
	glColor3ub(102, 51, 0);
	glVertex2f(0.52f,0.45f);
	glVertex2f(0.48f, 0.45f);
	glVertex2f(0.48f,0.62f);
    glVertex2f(0.5f,0.64f);
    glVertex2f(0.52f,0.62f);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(34,139,34);
    glVertex2f(0.5f,0.64f);
    glVertex2f(0.52f,0.62f);
    glVertex2f(0.58f,0.6f);
	glVertex2f(0.55f, 0.63f);
	glVertex2f(0.58f,0.66f);
	glVertex2f(0.52f,0.66f);
	glVertex2f(0.52f, 0.72f);
	glVertex2f(0.5f,0.69f);
	glVertex2f(0.48f,0.72f);
	glVertex2f(0.48f, 0.66f);
	glVertex2f(0.42f,0.66f);
	glVertex2f(0.45f,0.63f);
	glVertex2f(0.42f, 0.6f);
	glVertex2f(0.48f,0.62f);
    glEnd();
    glPopMatrix();
}

//Grass-Flower
{
    //Grass-Right-1
    glPushMatrix();
    glScalef(.8,.8,0);
    glTranslatef(.8,-.12,0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();
    int i;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;
	GLfloat e=-.05f; GLfloat f=-.35f; GLfloat radius11 =.02f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                e + (radius11 * cos(i *  twicePi / triangleAmount)),
            f+ (radius11 * sin(i * twicePi / triangleAmount))
			);
    }
	glEnd();

	GLfloat g=0.05f; GLfloat h=-0.35f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                g + (radius11 * cos(i *  twicePi / triangleAmount)),
            h+ (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    GLfloat a1=0.0f; GLfloat b1=-0.3f;
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                a1 + (radius11 * cos(i *  twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glPopMatrix();

	//Grass-Right-2
    glPushMatrix();
    glScalef(.8,.8,0);
    glTranslatef(.8,.15,0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();

    triangleAmount = 20;
    twicePi = 2.0f * PI;
	e=-.05f; f=-.35f; radius11 =.02f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                e + (radius11 * cos(i *  twicePi / triangleAmount)),
            f+ (radius11 * sin(i * twicePi / triangleAmount))
			);
    }
	glEnd();

	g=0.05f; h=-0.35f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                g + (radius11 * cos(i *  twicePi / triangleAmount)),
            h+ (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    a1=0.0f; b1=-0.3f;
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                a1 + (radius11 * cos(i *  twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glPopMatrix();

	//Grass-Middle-1
    glPushMatrix();
    glScalef(.8,.8,0);
    glTranslatef(.0,-.12,0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();

    triangleAmount = 20;
    twicePi = 2.0f * PI;
	e=-.05f; f=-.35f; radius11 =.02f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                e + (radius11 * cos(i *  twicePi / triangleAmount)),
            f+ (radius11 * sin(i * twicePi / triangleAmount))
			);
    }
	glEnd();

	g=0.05f; h=-0.35f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                g + (radius11 * cos(i *  twicePi / triangleAmount)),
            h+ (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    a1=0.0f; b1=-0.3f;
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                a1 + (radius11 * cos(i *  twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glPopMatrix();

	//Grass-Middle-2
    glPushMatrix();
    glScalef(.8,.8,0);
    glTranslatef(0.0,.15,0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();

    triangleAmount = 20;
    twicePi = 2.0f * PI;
	e=-.05f; f=-.35f; radius11 =.02f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                e + (radius11 * cos(i *  twicePi / triangleAmount)),
            f+ (radius11 * sin(i * twicePi / triangleAmount))
			);
    }
	glEnd();

	g=0.05f; h=-0.35f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                g + (radius11 * cos(i *  twicePi / triangleAmount)),
            h+ (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    a1=0.0f; b1=-0.3f;
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                a1 + (radius11 * cos(i *  twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glPopMatrix();

	//Grass-Left-1
    glPushMatrix();
    glScalef(.8,.8,0);
    glTranslatef(-.8,-.12,0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();

    triangleAmount = 20;
    twicePi = 2.0f * PI;
	e=-.05f; f=-.35f; radius11 =.02f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                e + (radius11 * cos(i *  twicePi / triangleAmount)),
            f+ (radius11 * sin(i * twicePi / triangleAmount))
			);
    }
	glEnd();

	g=0.05f; h=-0.35f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                g + (radius11 * cos(i *  twicePi / triangleAmount)),
            h+ (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    a1=0.0f; b1=-0.3f;
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                a1 + (radius11 * cos(i *  twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glPopMatrix();

	//Grass-Left-2
    glPushMatrix();
    glScalef(.8,.8,0);
    glTranslatef(-.8,.15,0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(18, 97, 11);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();

    triangleAmount = 20;
    twicePi = 2.0f * PI;
	e=-.05f; f=-.35f; radius11 =.02f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                e + (radius11 * cos(i *  twicePi / triangleAmount)),
            f+ (radius11 * sin(i * twicePi / triangleAmount))
			);
    }
	glEnd();

	g=0.05f; h=-0.35f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                g + (radius11 * cos(i *  twicePi / triangleAmount)),
            h+ (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    a1=0.0f; b1=-0.3f;
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 128, 136);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                a1 + (radius11 * cos(i *  twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glPopMatrix();



}


//Fence
{
    //Fence-Left-1
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(-.25,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(176, 176, 172);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-2
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(.105,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(176, 176, 172);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-3
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(.46,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(176, 176, 172);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-4
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(.815,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(176, 176, 172);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-5
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(1.17,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(176, 176, 172);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-6
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(1.525,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(176, 176, 172);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-7
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(1.88,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(176, 176, 172);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

}


    //FootWalk
    glBegin(GL_QUADS);
    glColor3ub(82, 80, 79);
    glVertex2f(-1,-.6);
    glVertex2f(-1,-.66);
    glVertex2f(1,-.66);
    glVertex2f(1,-.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(176, 176, 172);
    glVertex2f(-1,-.66);
    glVertex2f(-1,-.67);
    glVertex2f(1,-.67);
    glVertex2f(1,-.66);
    glEnd();

//Road / Car
{
    //Road
    glBegin(GL_QUADS);
    glColor3ub(28, 26, 25);
    glVertex2f(-1,-.67);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-.67);
    glEnd();
    //Road-Line
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(230,200,0);
    glVertex2f(-.98,-.835);
    glVertex2f(-.88,-.835);

    glVertex2f(-.83,-.835);
    glVertex2f(-.73,-.835);

    glVertex2f(-.68,-.835);
    glVertex2f(-.58,-.835);

    glVertex2f(-.53,-.835);
    glVertex2f(-.43,-.835);

    glVertex2f(-.38,-.835);
    glVertex2f(-.28,-.835);

    glVertex2f(-.23,-.835);
    glVertex2f(-.13,-.835);

    glVertex2f(-.08,-.835);
    glVertex2f(.02,-.835);

    glVertex2f(.07,-.835);
    glVertex2f(.17,-.835);

    glVertex2f(.22,-.835);
    glVertex2f(.32,-.835);

    glVertex2f(.37,-.835);
    glVertex2f(.47,-.835);

    glVertex2f(.52,-.835);
    glVertex2f(.62,-.835);

    glVertex2f(.67,-.835);
    glVertex2f(.77,-.835);

    glVertex2f(.82,-.835);
    glVertex2f(.92,-.835);

    glVertex2f(.97,-.835);
    glVertex2f(1,-.835);

    glEnd();



    //Car-Below-Left
    glPushMatrix();
    glTranslatef(position2,0.0f,0.0f);
    glTranslatef(.11,-.29,0);
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(-.66,-.60);
    glVertex2f(-.66,-.68);
    glVertex2f(-.28,-.68);
    glVertex2f(-.28,-.62);
    glVertex2f(-.27,-.62);
    glVertex2f(-.28,-.60);
    glVertex2f(-.36,-.60);
    glVertex2f(-.40,-.54);
    glVertex2f(-.60,-.54);
    glVertex2f(-.62,-.62);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-.37,-.60);
    glVertex2f(-.40,-.55);
    glVertex2f(-.58,-.55);
    glVertex2f(-.62,-.60);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(-.40,-.55);
    glVertex2f(-.40,-.60);

    glVertex2f(-.58,-.55);
    glVertex2f(-.58,-.60);
    glEnd();

//car wheel back
    int i;
    x=-.58f; y=-.68f; radius =.03f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
//-----------
	 x=-.58f;  y=-.68f;  radius =.018f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,250);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

//car wheel front
	x=-.34f;  y=-.68f;  radius =.03f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
//-----------------
	x=-.34f;  y=-.68f;  radius =.018f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,250);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    glPopMatrix();

    //Below Car Right
    glPushMatrix();
    glTranslatef(position2,0.0f,0.0f);
    glTranslatef(1.18,-.29,0);
    glBegin(GL_POLYGON);
    glColor3ub(0,0,128);
    glVertex2f(-.66,-.60);
    glVertex2f(-.66,-.68);
    glVertex2f(-.28,-.68);
    glVertex2f(-.28,-.62);
    glVertex2f(-.27,-.62);
    glVertex2f(-.28,-.60);
    glVertex2f(-.36,-.60);
    glVertex2f(-.40,-.54);
    glVertex2f(-.60,-.54);
    glVertex2f(-.62,-.62);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-.37,-.60);
    glVertex2f(-.40,-.55);
    glVertex2f(-.58,-.55);
    glVertex2f(-.62,-.60);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(-.40,-.55);
    glVertex2f(-.40,-.60);

    glVertex2f(-.58,-.55);
    glVertex2f(-.58,-.60);
    glEnd();

//car wheel back

    x=-.58f; y=-.68f; radius =.03f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
//-----------
	 x=-.58f;  y=-.68f;  radius =.018f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,250);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

//car wheel front
	x=-.34f;  y=-.68f;  radius =.03f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
//-----------------
	x=-.34f;  y=-.68f;  radius =.018f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,250);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    glPopMatrix();




}

//Road side tree
{
    //Left-1
    glPushMatrix();
    glScalef(.5,.4,0);
    glTranslatef(-.9,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();

    int i;

	 x=-.75f;  y=.33f;  radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    GLfloat a=-.68f; GLfloat b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c=-.81f; GLfloat d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e=-.87f; GLfloat f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g=-.61f; GLfloat h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	GLfloat a1=-.61f; GLfloat b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c1=-.88f; GLfloat d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e1=-.87f; GLfloat f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g1=-.61f; GLfloat h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e11=-.64f; GLfloat f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e12=-.75f; GLfloat f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

    GLfloat e123=-.8f; GLfloat f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	GLfloat e1232=-.7f; GLfloat f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();


	//Left-2
    glPushMatrix();
    glScalef(.5,.4,0);
    glTranslatef(.35,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	 x=-.75f;  y=.33f;  radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f;  f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

    e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Left-3
    glPushMatrix();
    glScalef(.5,.4,0);
    glTranslatef(1.6,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	 x=-.75f;  y=.33f;  radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f;  f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

    e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Left-4
    glPushMatrix();
    glScalef(.5,.4,0);
    glTranslatef(2.5,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	 x=-.75f;  y=.33f;  radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f;  f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 149, 76);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

    e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(60, 149, 76);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

}



//LIGHT Left
    glPushMatrix();
    glTranslatef(-.3,-.65,0);

    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(-.22,.23);
    glVertex2f(-.22,.02);
    glVertex2f(-.21,.02);
    glVertex2f(-.21,.23);
    glEnd();


    //LIGHT Left Top Two
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(-.22,.23);
    glVertex2f(-.21,.23);
    glVertex2f(-.18,.24);
    glVertex2f(-.2,.25);

    glVertex2f(-.21,.23);
    glVertex2f(-.22,.23);
    glVertex2f(-.26,.24);
    glVertex2f(-.23,.25);
    glEnd();
    glLoadIdentity();
    glPopMatrix();


    //LIGHT Right
    glPushMatrix();
    glTranslatef(0,-.65,0);
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(.22,.23);
    glVertex2f(.22,.02);
    glVertex2f(.21,.02);
    glVertex2f(.21,.23);
    glEnd();


    //LIGHT Right Top Two

    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(.22,.23);
    glVertex2f(.21,.23);
    glVertex2f(.18,.24);
    glVertex2f(.2,.25);

    glVertex2f(.21,.23);
    glVertex2f(.22,.23);
    glVertex2f(.26,.24);
    glVertex2f(.23,.25);
    glEnd();
    glLoadIdentity();
    glPopMatrix();


    //ON LIGHT Left Top Two
    glPushMatrix();

    glTranslatef(-.3,-.65,0);
    glBegin(GL_QUADS);
    glColor3ub(211, 228, 86);

    glVertex2f(-.19,.23);
    glVertex2f(-.2,.24);
    glVertex2f(-.2,.02);
    glVertex2f(-.07,.02);


    glVertex2f(-.24,.23);
    glVertex2f(-.23,.24);
    glVertex2f(-.225,.02);
    glVertex2f(-.35,.02);
    glEnd();
    glLoadIdentity();
    glPopMatrix();






 //ON LIGHT Right Top Two
    glPushMatrix();
    glTranslatef(0,-.65,0);
    glBegin(GL_QUADS);
    glColor3ub(211, 228, 86);

    glVertex2f(.19,.23);
    glVertex2f(.2,.24);
    glVertex2f(.21,.02);
    glVertex2f(.07,.02);


    glVertex2f(.24,.23);
    glVertex2f(.23,.24);
    glVertex2f(.225,.02);
    glVertex2f(.35,.02);
    glEnd();
    glLoadIdentity();
    glPopMatrix();





//LIGHT Left
    glPushMatrix();
    glTranslatef(-.75,-.65,0);

    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(-.22,.23);
    glVertex2f(-.22,.02);
    glVertex2f(-.21,.02);
    glVertex2f(-.21,.23);
    glEnd();


    //LIGHT Left Top Two
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(-.22,.23);
    glVertex2f(-.21,.23);
    glVertex2f(-.18,.24);
    glVertex2f(-.2,.25);

    glVertex2f(-.21,.23);
    glVertex2f(-.22,.23);
    glVertex2f(-.26,.24);
    glVertex2f(-.23,.25);
    glEnd();
    glLoadIdentity();
    glPopMatrix();


    //LIGHT Right
    glPushMatrix();
    glTranslatef(.5,-.65,0);
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(.22,.23);
    glVertex2f(.22,.02);
    glVertex2f(.21,.02);
    glVertex2f(.21,.23);
    glEnd();


    //LIGHT Right Top Two

    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(.22,.23);
    glVertex2f(.21,.23);
    glVertex2f(.18,.24);
    glVertex2f(.2,.25);

    glVertex2f(.21,.23);
    glVertex2f(.22,.23);
    glVertex2f(.26,.24);
    glVertex2f(.23,.25);
    glEnd();
    glLoadIdentity();
    glPopMatrix();


    //ON LIGHT Left Top Two
    glPushMatrix();

    glTranslatef(-.75,-.65,0);
    glBegin(GL_QUADS);
    glColor3ub(211, 228, 86);

    glVertex2f(-.19,.23);
    glVertex2f(-.2,.24);
    glVertex2f(-.2,.02);
    glVertex2f(-.07,.02);


    glVertex2f(-.24,.23);
    glVertex2f(-.23,.24);
    glVertex2f(-.225,.02);
    glVertex2f(-.35,.02);
    glEnd();
    glLoadIdentity();
    glPopMatrix();






 //ON LIGHT Right Top Two
    glPushMatrix();
    glTranslatef(.5,-.65,0);
    glBegin(GL_QUADS);
    glColor3ub(211, 228, 86);

    glVertex2f(.19,.23);
    glVertex2f(.2,.24);
    glVertex2f(.21,.02);
    glVertex2f(.07,.02);


    glVertex2f(.24,.23);
    glVertex2f(.23,.24);
    glVertex2f(.225,.02);
    glVertex2f(.35,.02);
    glEnd();
    glLoadIdentity();
    glPopMatrix();


 //Upper Car
    glPushMatrix();
    glTranslatef(position,0.0f,0.0f);
    glTranslatef(0,-.38,0);
    glBegin(GL_POLYGON);
    glColor3ub(128,0,0);
    glVertex2f(.04,-.24);
    glVertex2f(0.0,-.34);
    glVertex2f(0,-.40);
    glVertex2f(.4,-.40);
    glVertex2f(.4,-.24);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240,255,240);
    glVertex2f(.37,-.26);
    glVertex2f(.30,-.26);
    glVertex2f(.30,-.34);
    glVertex2f(.37,-.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240,255,240);
    glVertex2f(.28,-.26);
    glVertex2f(.22,-.26);
    glVertex2f(.22,-.34);
    glVertex2f(.28,-.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240,255,240);
    glVertex2f(.20,-.26);
    glVertex2f(.14,-.26);
    glVertex2f(.14,-.34);
    glVertex2f(.20,-.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240,255,240);
    glVertex2f(.12,-.26);
    glVertex2f(.05,-.26);
    glVertex2f(.02,-.34);
    glVertex2f(.12,-.34);
    glEnd();
//car wheel front
	x=.08f;  y=-.40f;  radius =.04f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
//-----------------
	x=.08f;  y=-.40f;  radius =.025f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,250);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
//car wheel back
	x=.3f;  y=-.40f;  radius =.04f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
//-----------------
	x=.3f;  y=-.40f;  radius =.025f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,250);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    glPopMatrix();









   //glutTimerFunc(8000,rainy,0);

	glFlush();
}


void night(int value)
{
    glutDisplayFunc(nightView);
}














void day()
{
    glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
    speed=.1f;

//SKY / SUN / CLOUD
{
    //SKY
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 235);
    glVertex2f(-1,1);
    glVertex2f(-1,.07);
    glVertex2f(1,.07);
    glVertex2f(1,1);
    glEnd();

    int i;
	GLfloat x=-.2f; GLfloat y=.91f; GLfloat radius =.07f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 204, 0);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++){
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

    //cloud
    glPushMatrix();
    glTranslatef(.98,0.07f, 0.0f);
    x=-.24f; y=.74f; radius =.08f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(211,211,211);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

	x=-0.36f;  y=.78f;  radius =.08f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(211,211,211);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

	x=-.47f;  y=.82f;  radius =.08f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(211,211,211);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

    //below cloud
    x=-.33f;  y=.67f;  radius =.08f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(220,220,220);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

    x=-.44f;  y=.7f;  radius =.08f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(220,220,220);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

    x=-.54f;  y=.74f;  radius =.08f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(220,220,220);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

	x=-.6f;  y=.68f;  radius =.08f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(220,220,220);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

	x=-.49f;  y=.66f;  radius =.07f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(220,220,220);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glPopMatrix();

}

	//1st Left upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-.32,.54);
    glVertex2f(-.32,.49);
    glVertex2f(-.28,.48);
    glVertex2f(-.28,.56);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.28,.54);
    glVertex2f(-.32,.52);

    glVertex2f(-.28,.52);
    glVertex2f(-.24,.5);
    glEnd();

    //LEFT CIRCLE
     GLfloat x=-.3f; GLfloat y=.5f; GLfloat radius =.022f;
     int triangleAmount = 20;
	 GLfloat twicePi = 2.0f * PI;

	 glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	 glEnd();

    //2nd left upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-.28,.56);
    glVertex2f(-.28,.48);
    glVertex2f(-.24,.46);
    glVertex2f(-.24,.55);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.28,.54);
    glVertex2f(-.24,.53);

    glVertex2f(-.28,.52);
    glVertex2f(-.24,.51);

    glVertex2f(-.28,.5);
    glVertex2f(-.24,.49);

    glEnd();

    //3rd left upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-.24,.55);
    glVertex2f(-.24,.52);
    glVertex2f(-.2,.52);
    glVertex2f(-.2,.56);
    glEnd();

    //4th left upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-.2,.58);
    glVertex2f(-.2,.54);
    glVertex2f(-.06,.54);
    glVertex2f(-.06,.595);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.2,.56);
    glVertex2f(-.06,.56);
    glEnd();

    //LEFT CIRCLE TOP
     x=-.14f;  y=.53f;  radius =.04f;
     triangleAmount = 20;
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


    //1st MIDLLE upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-.06,.585);
    glVertex2f(-.06,.46);
    glVertex2f(.06,.46);
    glVertex2f(.06,.585);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(0,.585);
    glVertex2f(0,.46);

    glVertex2f(-.06,.57);
    glVertex2f(.06,.57);

    glVertex2f(-.06,.55);
    glVertex2f(.06,.55);

    glVertex2f(-.06,.525);
    glVertex2f(.06,.525);

    glVertex2f(-.06,.505);
    glVertex2f(.06,.505);

    glVertex2f(-.06,.485);
    glVertex2f(.06,.485);

    glVertex2f(-.06,.46);
    glVertex2f(.06,.46);

    glEnd();

     //2nd MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(16,16,16);
    glVertex2f(-.06,.46);
    glVertex2f(-.06,.4);
    glVertex2f(.06,.4);
    glVertex2f(.06,.46);
    glEnd();


    //3rd MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(-.06,.4);
    glVertex2f(-.06,.38);
    glVertex2f(.06,.38);
    glVertex2f(.06,.4);
    glEnd();

    //4th MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(21,21,21);
    glVertex2f(-.06,.38);
    glVertex2f(-.06,.32);
    glVertex2f(.06,.32);
    glVertex2f(.06,.38);
    glEnd();

    //5th MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(-.06,.32);
    glVertex2f(-.06,.3);
    glVertex2f(.06,.3);
    glVertex2f(.06,.32);
    glEnd();


    //5th MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(21,21,21);
    glVertex2f(-.06,.3);
    glVertex2f(-.06,.26);
    glVertex2f(.06,.26);
    glVertex2f(.06,.3);
    glEnd();

    //6th MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(80,80,80);
    glVertex2f(-.06,.26);
    glVertex2f(-.06,.24);
    glVertex2f(.06,.24);
    glVertex2f(.06,.26);
    glEnd();

    //7th MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(-.06,.24);
    glVertex2f(-.06,.2);
    glVertex2f(.06,.2);
    glVertex2f(.06,.24);
    glEnd();


    //5th MIDLLE upper Back DOWN
    glBegin(GL_QUADS);
    glColor3ub(50,50,50);
    glVertex2f(-.06,.2);
    glVertex2f(-.06,.16);
    glVertex2f(.06,.16);
    glVertex2f(.06,.2);
    glEnd();








    //1st RIGHT upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(.32,.54);
    glVertex2f(.32,.49);
    glVertex2f(.28,.48);
    glVertex2f(.28,.56);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.28,.54);
    glVertex2f(.32,.52);

    glVertex2f(.28,.52);
    glVertex2f(.24,.5);


    glEnd();

    //RIGHT CIRCLE
      x=.3f; y=.5f;  radius =.022f;
      triangleAmount = 20;
	  twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


    //2nd RIGHT upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(.28,.56);
    glVertex2f(.28,.48);
    glVertex2f(.24,.46);
    glVertex2f(.24,.55);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.28,.54);
    glVertex2f(.24,.53);

    glVertex2f(.28,.52);
    glVertex2f(.24,.51);


    glVertex2f(.28,.5);
    glVertex2f(.24,.49);


    glEnd();

    //3rd RIGHT upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(.24,.55);
    glVertex2f(.24,.52);
    glVertex2f(.2,.52);
    glVertex2f(.2,.56);
    glEnd();

    //4th RIGHT upper Back
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(.2,.58);
    glVertex2f(.2,.54);
    glVertex2f(.06,.54);
    glVertex2f(.06,.595);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.2,.56);
    glVertex2f(.06,.56);
    glEnd();

    // CIRCLE RIGHT
     x=.14f;  y=.53f;  radius =.04f;
     triangleAmount = 20;
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();








{

    //1stLeft
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.81,.41);
    glVertex2f(-.81,.19);
    glVertex2f(-.7,.19);
    glVertex2f(-.7,.41);
    glEnd();



    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.765,.41);
    glVertex2f(-.765,.19);



    glEnd();




    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.81,.38);
    glVertex2f(-.7,.38);

    glVertex2f(-.81,.35);
    glVertex2f(-.7,.35);

    glVertex2f(-.81,.32);
    glVertex2f(-.7,.32);

    glVertex2f(-.81,.29);
    glVertex2f(-.7,.29);

    glVertex2f(-.81,.26);
    glVertex2f(-.7,.26);

    glVertex2f(-.81,.23);
    glVertex2f(-.7,.23);

    glVertex2f(-.81,.20);
    glVertex2f(-.7,.20);



    glEnd();

    //second Left
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.71,.43);
    glVertex2f(-.71,.17);
    glVertex2f(-.58,.17);
    glVertex2f(-.58,.45);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.67,.17);
    glVertex2f(-.67,.438);

    glVertex2f(-.62,.17);
    glVertex2f(-.62,.445);

    glEnd();




    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.71,.4);
    glVertex2f(-.58,.42);

    glVertex2f(-.71,.37);
    glVertex2f(-.58,.39);

    glVertex2f(-.71,.34);
    glVertex2f(-.58,.36);

    glVertex2f(-.71,.31);
    glVertex2f(-.58,.33);

    glVertex2f(-.71,.28);
    glVertex2f(-.58,.30);

    glVertex2f(-.71,.25);
    glVertex2f(-.58,.27);

    glVertex2f(-.71,.22);
    glVertex2f(-.58,.24);

    glVertex2f(-.71,.19);
    glVertex2f(-.58,.21);

    glVertex2f(-.71,.16);
    glVertex2f(-.58,.18);

    glEnd();


    //Middle of 2 ,3 Left
    glBegin(GL_QUADS);
    glColor3ub(100,100,100);
    glVertex2f(-.58,.44);
    glVertex2f(-.58,.38);
    glVertex2f(-.56,.38);
    glVertex2f(-.56,.445);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-.58,.38);
    glVertex2f(-.58,.16);
    glVertex2f(-.56,.16);
    glVertex2f(-.56,.38);
    glEnd();

    //3rd left
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.56,.46);
    glVertex2f(-.56,.16);
    glVertex2f(-.42,.16);
    glVertex2f(-.42,.5);
    glEnd();


     glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.45,.16);
    glVertex2f(-.45,.49);

    glVertex2f(-.52,.16);
    glVertex2f(-.52,.48);

    glEnd();




    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.56,.43);
    glVertex2f(-.42,.47);

    glVertex2f(-.56,.4);
    glVertex2f(-.42,.44);

    glVertex2f(-.56,.37);
    glVertex2f(-.42,.41);

    glVertex2f(-.56,.34);
    glVertex2f(-.42,.38);

    glVertex2f(-.56,.31);
    glVertex2f(-.42,.35);

    glVertex2f(-.56,.28);
    glVertex2f(-.42,.32);

    glVertex2f(-.56,.25);
    glVertex2f(-.42,.29);

    glVertex2f(-.56,.22);
    glVertex2f(-.42,.26);

    glVertex2f(-.56,.19);
    glVertex2f(-.42,.23);

    glEnd();

    //4th left
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.42,.5);
    glVertex2f(-.42,.13);
    glVertex2f(-.24,.13);
    glVertex2f(-.24,.48);
    glEnd();

    //5th left
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.24,.54);
    glVertex2f(-.24,.13);
    glVertex2f(-.04,.13);
    glVertex2f(-.04,.54);
    glEnd();



    //Left 1st Triangle
    //1stLeft
    glBegin(GL_TRIANGLES);
    glColor3ub(1,1,1);
    glVertex2f(-.67,.4);
    glVertex2f(-.695,.24);
    glVertex2f(-.65,.25);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(217,217,217);
    glVertex2f(-.67,.27);
    glVertex2f(-.69,.24);
    glVertex2f(-.65,.25);
    glVertex2f(-.65,.27);

    glEnd();


    //2nd Left
    glBegin(GL_TRIANGLES);
    glColor3ub(1,1,1);
    glVertex2f(-.45,.43);
    glVertex2f(-.49,.26);
    glVertex2f(-.43,.27);
    glEnd();

//LEFT TRIANGLE INSIDE
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.45,.428);
    glVertex2f(-.45,.268);
    glVertex2f(-.443,.268);
    glVertex2f(-.443,.428);

    glVertex2f(-.47,.38);
    glVertex2f(-.47,.373);
    glVertex2f(-.44,.373);
    glVertex2f(-.44,.38);

    glVertex2f(-.47,.35);
    glVertex2f(-.47,.343);
    glVertex2f(-.44,.343);
    glVertex2f(-.44,.35);

    glVertex2f(-.48,.32);
    glVertex2f(-.48,.313);
    glVertex2f(-.43,.313);
    glVertex2f(-.43,.32);

    glVertex2f(-.485,.29);
    glVertex2f(-.485,.283);
    glVertex2f(-.43,.283);
    glVertex2f(-.43,.29);
    glEnd();

    //Under triangle a BOX 1
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-.49,.22);
    glVertex2f(-.49,.17);
    glVertex2f(-.43,.17);
    glVertex2f(-.43,.22);
    glEnd();

    //INSIDE BOX LEFT
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.458,.22);
    glVertex2f(-.458,.17);
    glVertex2f(-.45,.17);
    glVertex2f(-.45,.22);

    glVertex2f(-.49,.195);
    glVertex2f(-.49,.19);
    glVertex2f(-.43,.19);
    glVertex2f(-.43,.195);

    glEnd();



    //Under triangle a BOX 2
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-.695,.21);
    glVertex2f(-.695,.18);
    glVertex2f(-.65,.18);
    glVertex2f(-.65,.21);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(217,217,217);
    glVertex2f(-.695,.21);
    glVertex2f(-.69,.2);
    glVertex2f(-.65,.2);
    glVertex2f(-.65,.21);

    glEnd();





    //LEFTBOTTOM Polygon 1
    glBegin(GL_QUADS);
    glColor3ub(128,0,0);
    glVertex2f(-.82,.19);
    glVertex2f(-.82,.07);
    glVertex2f(-.5,.12);
    glVertex2f(-.68,.19);
    glEnd();

    //LEFTBOTTOM Polygon 2
    glBegin(GL_QUADS);
    glColor3ub(128,0,0);
    glVertex2f(-.56,.17);
    glVertex2f(-.465,.13);
    glVertex2f(-.32,.13);
    glVertex2f(-.43,.17);

    glEnd();




    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(-.28,.13);
    glVertex2f(-.28,.48);

    glVertex2f(-.37,.16);
    glVertex2f(-.37,.5);



    glEnd();


    //Right 2
    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);


    glVertex2f(-.24,.46);
    glVertex2f(-.42,.48);

    glVertex2f(-.24,.43);
    glVertex2f(-.42,.45);

    glVertex2f(-.24,.4);
    glVertex2f(-.42,.42);

    glVertex2f(-.24,.37);
    glVertex2f(-.42,.39);

    glVertex2f(-.24,.34);
    glVertex2f(-.42,.36);

    glVertex2f(-.24,.31);
    glVertex2f(-.42,.33);

    glVertex2f(-.24,.28);
    glVertex2f(-.42,.30);

    glVertex2f(-.24,.25);
    glVertex2f(-.42,.27);

    glVertex2f(-.24,.22);
    glVertex2f(-.42,.24);

    glVertex2f(-.24,.19);
    glVertex2f(-.42,.21);

    glVertex2f(-.24,.16);
    glVertex2f(-.42,.18);

    glEnd();



    //LEFT CIRCLE


	 x=-.34f;  y=.255f;  radius =.06f;
     triangleAmount = 20;
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

//Left inside circle
 glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(-.36,.315);
    glVertex2f(-.36,.2);
    glVertex2f(-.352,.2);
    glVertex2f(-.352,.315);

    glVertex2f(-.33,.315);
    glVertex2f(-.33,.2);
    glVertex2f(-.322,.2);
    glVertex2f(-.322,.315);

    glVertex2f(-.4,.28);
    glVertex2f(-.4,.273);
    glVertex2f(-.25,.273);
    glVertex2f(-.25,.28);

    glVertex2f(-.4,.24);
    glVertex2f(-.4,.233);
    glVertex2f(-.25,.233);
    glVertex2f(-.25,.24);

    glEnd();




	//RIGHT BUILDING

    //1st Right
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.05,.54);
    glVertex2f(.05,.13);
    glVertex2f(.25,.13);
    glVertex2f(.25,.54);
    glEnd();

    //2nd Right
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.42,.5);
    glVertex2f(.42,.13);
    glVertex2f(.25,.13);
    glVertex2f(.25,.48);
    glEnd();

    //3rd Right
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.56,.46);
    glVertex2f(.56,.16);
    glVertex2f(.42,.16);
    glVertex2f(.42,.5);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.45,.16);
    glVertex2f(.45,.49);

    glVertex2f(.52,.16);
    glVertex2f(.52,.48);
    glEnd();

    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.56,.43);
    glVertex2f(.42,.47);

    glVertex2f(.56,.4);
    glVertex2f(.42,.44);

    glVertex2f(.56,.37);
    glVertex2f(.42,.41);

    glVertex2f(.56,.34);
    glVertex2f(.42,.38);

    glVertex2f(.56,.31);
    glVertex2f(.42,.35);

    glVertex2f(.56,.28);
    glVertex2f(.42,.32);

    glVertex2f(.56,.25);
    glVertex2f(.42,.29);

    glVertex2f(.56,.22);
    glVertex2f(.42,.26);

    glVertex2f(.56,.19);
    glVertex2f(.42,.23);

    glEnd();

    //Middle of 3 ,4 Right
    glBegin(GL_QUADS);
    glColor3ub(100,100,100);
    glVertex2f(.58,.44);
    glVertex2f(.58,.38);
    glVertex2f(.56,.38);
    glVertex2f(.56,.445);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.58,.38);
    glVertex2f(.58,.16);
    glVertex2f(.56,.16);
    glVertex2f(.56,.38);
    glEnd();

	//4th Right
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.71,.43);
    glVertex2f(.71,.17);
    glVertex2f(.58,.17);
    glVertex2f(.58,.45);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.67,.17);
    glVertex2f(.67,.438);

    glVertex2f(.62,.17);
    glVertex2f(.62,.445);

    glEnd();

    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.71,.4);
    glVertex2f(.58,.42);

    glVertex2f(.71,.37);
    glVertex2f(.58,.39);

    glVertex2f(.71,.34);
    glVertex2f(.58,.36);

    glVertex2f(.71,.31);
    glVertex2f(.58,.33);

    glVertex2f(.71,.28);
    glVertex2f(.58,.30);

    glVertex2f(.71,.25);
    glVertex2f(.58,.27);

    glVertex2f(.71,.22);
    glVertex2f(.58,.24);

    glVertex2f(.71,.19);
    glVertex2f(.58,.21);

    glVertex2f(.71,.16);
    glVertex2f(.58,.18);
    glEnd();

    //5th Right
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.81,.41);
    glVertex2f(.81,.19);
    glVertex2f(.7,.19);
    glVertex2f(.7,.41);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.765,.41);
    glVertex2f(.765,.19);
    glEnd();

    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.81,.38);
    glVertex2f(.7,.38);

    glVertex2f(.81,.35);
    glVertex2f(.7,.35);

    glVertex2f(.81,.32);
    glVertex2f(.7,.32);

    glVertex2f(.81,.29);
    glVertex2f(.7,.29);

    glVertex2f(.81,.26);
    glVertex2f(.7,.26);

    glVertex2f(.81,.23);
    glVertex2f(.7,.23);

    glVertex2f(.81,.20);
    glVertex2f(.7,.20);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.28,.13);
    glVertex2f(.28,.48);

    glVertex2f(.37,.13);
    glVertex2f(.37,.5);
    glEnd();

    //Right 2
    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);


    glVertex2f(.25,.46);
    glVertex2f(.42,.48);

    glVertex2f(.25,.43);
    glVertex2f(.42,.45);

    glVertex2f(.25,.4);
    glVertex2f(.42,.42);

    glVertex2f(.25,.37);
    glVertex2f(.42,.39);

    glVertex2f(.25,.34);
    glVertex2f(.42,.36);

    glVertex2f(.25,.31);
    glVertex2f(.42,.33);

    glVertex2f(.25,.28);
    glVertex2f(.42,.30);

    glVertex2f(.25,.25);
    glVertex2f(.42,.27);

    glVertex2f(.25,.22);
    glVertex2f(.42,.24);

    glVertex2f(.25,.19);
    glVertex2f(.42,.21);

    glVertex2f(.25,.16);
    glVertex2f(.42,.18);

    glVertex2f(.25,.13);
    glVertex2f(.42,.15);
    glEnd();

    //RIGHT CIRCLE
	 x=.34f;  y=.255f;  radius =.06f;
     triangleAmount = 20;
	 twicePi = 2.0f * PI;

	 glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	 glEnd();



	 //RIGHT inside circle
 glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.36,.315);
    glVertex2f(.36,.2);
    glVertex2f(.352,.2);
    glVertex2f(.352,.315);

    glVertex2f(.33,.315);
    glVertex2f(.33,.2);
    glVertex2f(.322,.2);
    glVertex2f(.322,.315);

    glVertex2f(.4,.28);
    glVertex2f(.4,.273);
    glVertex2f(.25,.273);
    glVertex2f(.25,.28);

    glVertex2f(.4,.24);
    glVertex2f(.4,.233);
    glVertex2f(.25,.233);
    glVertex2f(.25,.24);

    glEnd();




    //RIGHT 1st Triangle
    //1stRight
    glBegin(GL_TRIANGLES);
    glColor3ub(1,1,1);
    glVertex2f(.67,.4);
    glVertex2f(.695,.24);
    glVertex2f(.65,.25);
    glEnd();
    //SHADE INSIDE
    glBegin(GL_QUADS);
    glColor3ub(217,217,217);
    glVertex2f(.67,.27);
    glVertex2f(.69,.24);
    glVertex2f(.65,.25);
    glVertex2f(.65,.27);

    glEnd();

    //2nd RIGHT
    glBegin(GL_TRIANGLES);
    glColor3ub(1,1,1);
    glVertex2f(.45,.43);
    glVertex2f(.49,.26);
    glVertex2f(.43,.27);
    glEnd();



    //RIGHT TRIANGLE INSIDE
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.45,.428);
    glVertex2f(.45,.268);
    glVertex2f(.443,.268);
    glVertex2f(.443,.428);

    glVertex2f(.47,.38);
    glVertex2f(.47,.373);
    glVertex2f(.44,.373);
    glVertex2f(.44,.38);

    glVertex2f(.47,.35);
    glVertex2f(.47,.343);
    glVertex2f(.44,.343);
    glVertex2f(.44,.35);

    glVertex2f(.48,.32);
    glVertex2f(.48,.313);
    glVertex2f(.43,.313);
    glVertex2f(.43,.32);

    glVertex2f(.485,.29);
    glVertex2f(.485,.283);
    glVertex2f(.43,.283);
    glVertex2f(.43,.29);
    glEnd();



    //Under triangle a BOX RIGHT
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.49,.22);
    glVertex2f(.49,.17);
    glVertex2f(.43,.17);
    glVertex2f(.43,.22);
    glEnd();


     //INSIDE BOX
    glBegin(GL_QUADS);
    glColor3ub(162,163,158);
    glVertex2f(.458,.22);
    glVertex2f(.458,.17);
    glVertex2f(.45,.17);
    glVertex2f(.45,.22);

    glVertex2f(.49,.195);
    glVertex2f(.49,.19);
    glVertex2f(.43,.19);
    glVertex2f(.43,.195);

    glEnd();

    //Under triangle a BOX 2
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.695,.21);
    glVertex2f(.695,.18);
    glVertex2f(.65,.18);
    glVertex2f(.65,.21);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(217,217,217);
    glVertex2f(.695,.21);
    glVertex2f(.69,.2);
    glVertex2f(.65,.2);
    glVertex2f(.65,.21);

    glEnd();




    //RIGHT BOTTOM Polygon 1
    glBegin(GL_QUADS);
    glColor3ub(128,0,0);
    glVertex2f(.82,.19);
    glVertex2f(.82,.07);
    glVertex2f(.5,.12);
    glVertex2f(.68,.19);
    glEnd();

    //RIGHT BOTTOM Polygon 2
    glBegin(GL_QUADS);
    glColor3ub(128,0,0);
    glVertex2f(.56,.17);
    glVertex2f(.465,.13);
    glVertex2f(.32,.13);
    glVertex2f(.43,.17);
    glEnd();


     //FLAG QUAD  2
    glBegin(GL_QUADS);
    glColor3ub(178,34,34);
    glVertex2f(-.08,.16);
    glVertex2f(-.082,.1);
    glVertex2f(.082,.1);
    glVertex2f(.08,.16);
    glEnd();

    //FLAG QUAD 1
    glBegin(GL_QUADS);
    glColor3ub(128,0,0);
    glVertex2f(-.06,.16);
    glVertex2f(-.06,.1);
    glVertex2f(.06,.1);
    glVertex2f(.06,.16);
    glEnd();

    //FLAG QUAD
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-.08,.16);
    glVertex2f(-.082,.12);
    glVertex2f(-.06,.12);
    glVertex2f(-.06,.16);
    glEnd();

    //FLAG QUAD
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(.08,.16);
    glVertex2f(.082,.12);
    glVertex2f(.06,.12);
    glVertex2f(.06,.16);
    glEnd();

    //FLAG QUAD CIRCLE
     x=0.0f;  y=.075f;  radius =.05f;
     triangleAmount = 20;
	 twicePi = 2.0f * PI;

	 glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	 glEnd();

	//White ROAD QUADS LEFT
	//1st White
    glBegin(GL_POLYGON);
    glColor3ub(208,206,204);
    glVertex2f(-.8,.07);
    glVertex2f(-.88,.07);
    glVertex2f(-1,.07);
    glVertex2f(-1,0);
    glVertex2f(-.8,0);
    glEnd();

	//2nd White
    glBegin(GL_QUADS);
    glColor3ub(208,206,204);
    glVertex2f(-.8,.07);
    glVertex2f(-.8,0);
    glVertex2f(-.58,0);
    glVertex2f(-.58,.11);
    glEnd();

    //3rd White
    glBegin(GL_POLYGON);
    glColor3ub(208,206,204);
    glVertex2f(-.58,.11);
    glVertex2f(-.58,0);
    glVertex2f(-.082,0);
    glVertex2f(-.08,.13);
    glVertex2f(-.32,.13);
    glVertex2f(-.46,.13);
    glEnd();


    //White ROAD QUADS RIGHT
	//1st White
    glBegin(GL_POLYGON);
    glColor3ub(208,206,204);
    glVertex2f(.8,.07);
    glVertex2f(.88,.07);
    glVertex2f(1,.07);
    glVertex2f(1,0);
    glVertex2f(.8,0);
    glEnd();

	//2nd White
    glBegin(GL_QUADS);
    glColor3ub(208,206,204);
    glVertex2f(.8,.07);
    glVertex2f(.8,0);
    glVertex2f(.58,0);
    glVertex2f(.58,.11);
    glEnd();

    //3rd White
    glBegin(GL_POLYGON);
    glColor3ub(208,206,204);
    glVertex2f(.58,.11);
    glVertex2f(.58,0);
    glVertex2f(.082,0);
    glVertex2f(.08,.13);
    glVertex2f(.32,.13);
    glVertex2f(.46,.13);
    glEnd();


    //MIDLE White QUAD
    glBegin(GL_QUADS);
    glColor3ub(208,206,204);
    glVertex2f(-.082,.1);
    glVertex2f(-.082,0);
    glVertex2f(.082,0);
    glVertex2f(.082,.1);
    glEnd();




    //WHITE SHIRI LEFT 1
    glBegin(GL_QUADS);
    glColor3ub(238,232,170);
    glVertex2f(-.62,.17);
    glVertex2f(-.53,.12);
    glVertex2f(-.44,.12);
    glVertex2f(-.56,.17);
    glEnd();


    //WHITE SHIRI Right
    glBegin(GL_QUADS);
    glColor3ub(238,232,170);
    glVertex2f(.62,.17);
    glVertex2f(.53,.12);
    glVertex2f(.44,.12);
    glVertex2f(.56,.17);
    glEnd();

    //LEFT 2nd SHIRI
    glBegin(GL_QUADS);
    glColor3ub(238,232,170);
    glVertex2f(-.43,.17);
    glVertex2f(-.33,.13);
    glVertex2f(-.3,.13);
    glVertex2f(-.41,.17);
    glEnd();

    //RIGHT 2nd SHIRI
    glBegin(GL_QUADS);
    glColor3ub(238,232,170);
    glVertex2f(.43,.17);
    glVertex2f(.33,.13);
    glVertex2f(.3,.13);
    glVertex2f(.41,.17);
    glEnd();

    //BD FLAG STAND
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(238,232,170);
    glVertex2f(0,.16);
    glVertex2f(0,.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,102,0);
    glVertex2f(0,.29);
    glVertex2f(0,.25);
    glVertex2f(.02,.24);
    glVertex2f(.025,.27);
    glEnd();


    //FLAG CIRCLE
     x=0.01f;  y=.265f;  radius =.007f;
     triangleAmount = 20;
	 twicePi = 2.0f * PI;

	 glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(204,0,0);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	 glEnd();



	//LINES
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.12,.54);
    glVertex2f(.12,.13);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);

    //RIGHT 1
    glVertex2f(-.11,.54);
    glVertex2f(-.11,.13);
    glEnd();

    glLineWidth(.01);
    glBegin(GL_LINES);
    glColor3ub(255,255,240);
    glVertex2f(.05,.54);
    glVertex2f(.25,.54);

    glVertex2f(.05,.51);
    glVertex2f(.25,.51);

    glVertex2f(.05,.48);
    glVertex2f(.25,.48);

    glVertex2f(.05,.45);
    glVertex2f(.25,.45);

    glVertex2f(.05,.42);
    glVertex2f(.25,.42);

    glVertex2f(.05,.39);
    glVertex2f(.25,.39);

    glVertex2f(.05,.36);
    glVertex2f(.25,.36);

    glVertex2f(.05,.33);
    glVertex2f(.25,.33);

    glVertex2f(.05,.30);
    glVertex2f(.25,.30);

    glVertex2f(.05,.27);
    glVertex2f(.25,.27);

    glVertex2f(.05,.24);
    glVertex2f(.25,.24);

    glVertex2f(.05,.21);
    glVertex2f(.25,.21);

    glVertex2f(.05,.18);
    glVertex2f(.25,.18);

    glVertex2f(.08,.15);
    glVertex2f(.25,.15);


    //LEFT 5
    glVertex2f(-.04,.54);
    glVertex2f(-.24,.54);

    glVertex2f(-.04,.51);
    glVertex2f(-.24,.51);

    glVertex2f(-.04,.48);
    glVertex2f(-.24,.48);

    glVertex2f(-.04,.45);
    glVertex2f(-.24,.45);

    glVertex2f(-.04,.42);
    glVertex2f(-.24,.42);

    glVertex2f(-.04,.39);
    glVertex2f(-.24,.39);

    glVertex2f(-.04,.36);
    glVertex2f(-.24,.36);

    glVertex2f(-.04,.33);
    glVertex2f(-.24,.33);

    glVertex2f(-.04,.30);
    glVertex2f(-.24,.30);

    glVertex2f(-.04,.27);
    glVertex2f(-.24,.27);

    glVertex2f(-.04,.24);
    glVertex2f(-.24,.24);

    glVertex2f(-.04,.21);
    glVertex2f(-.24,.21);

    glVertex2f(-.04,.18);
    glVertex2f(-.24,.18);

    glVertex2f(-.07,.15);
    glVertex2f(-.24,.15);

    glVertex2f(.25,.13);
    glVertex2f(.25,.54);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(105,105,105);
    glVertex2f(.25,.13);
    glVertex2f(.25,.54);

    glVertex2f(-.24,.13);
    glVertex2f(-.24,.54);

    glVertex2f(.42,.5);
    glVertex2f(.42,.17);

    glVertex2f(-.42,.5);
    glVertex2f(-.42,.17);

    glVertex2f(-.71,.43);
    glVertex2f(-.71,.19);

    glVertex2f(.71,.43);
    glVertex2f(.71,.19);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.06,.595);
    glVertex2f(-.06,.54);

    glVertex2f(.06,.595);
    glVertex2f(.06,.54);

    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);


    glVertex2f(-.77,.16);
    glVertex2f(-.77,.08);

    glVertex2f(-.7,.16);
    glVertex2f(-.7,.09);

    glVertex2f(-.64,.15);
    glVertex2f(-.64,.1);


    glVertex2f(.77,.16);
    glVertex2f(.77,.08);

    glVertex2f(.7,.16);
    glVertex2f(.7,.09);

    glVertex2f(.64,.15);
    glVertex2f(.64,.1);
    glEnd();




    //LIGHT Left
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(-.22,.23);
    glVertex2f(-.22,.13);
    glVertex2f(-.21,.13);
    glVertex2f(-.21,.23);
    glEnd();

    //LIGHT Left Top Two
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(-.22,.23);
    glVertex2f(-.21,.23);
    glVertex2f(-.18,.24);
    glVertex2f(-.2,.25);

    glVertex2f(-.21,.23);
    glVertex2f(-.22,.23);
    glVertex2f(-.26,.24);
    glVertex2f(-.23,.25);
    glEnd();


    //LIGHT Right
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(.22,.23);
    glVertex2f(.22,.13);
    glVertex2f(.21,.13);
    glVertex2f(.21,.23);
    glEnd();


    //LIGHT Right Top Two
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(.22,.23);
    glVertex2f(.21,.23);
    glVertex2f(.18,.24);
    glVertex2f(.2,.25);

    glVertex2f(.21,.23);
    glVertex2f(.22,.23);
    glVertex2f(.26,.24);
    glVertex2f(.23,.25);
    glEnd();







    //BIRD
{
    glPushMatrix();
    glTranslatef(position3,0.0f, 0.0f);

    int i;
	GLfloat mm=0.182f; GLfloat nn=.801f; GLfloat radiusmm =.01f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(225, 225, 208);
    glVertex2f(mm, nn); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.11f,0.79f);
    glVertex2f(0.12f,0.78f);
    glVertex2f(0.16f,0.77f);
    glVertex2f(0.19f,0.79f);
    glVertex2f(0.201f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.14f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.144f,0.8f);
    glVertex2f(0.12f,0.83f);
    glEnd();
	/////2nd bird////
	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.02f,0.8f);
    glVertex2f(-0.01f,0.79f);
    glVertex2f(0.0f,0.78f);
    glVertex2f(0.04f,0.77f);
    glVertex2f(0.07f,0.79f);
    glVertex2f(0.081f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.03f,0.8f);
    glVertex2f(0.02f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.024f,0.8f);
    glVertex2f(0.0f,0.83f);
    glEnd();

	GLfloat mmm=0.062f; GLfloat nnn=.801f; GLfloat radiusmmm =.01f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmm, nnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
			    nnn + (radiusmmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	/////3rd bird/////
	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.72f,0.8f);
    glVertex2f(-0.71f,0.79f);
    glVertex2f(-0.7f,0.78f);
    glVertex2f(-0.66f,0.77f);
    glVertex2f(-0.63f,0.79f);
    glVertex2f(-0.619f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.67f,0.8f);
    glVertex2f(-0.68f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.676f,0.8f);
    glVertex2f(-0.7f,0.83f);
    glEnd();

	GLfloat mmmm=-0.638f; GLfloat nnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmmm,nnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
			    nnnn + (radiusmmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	////4th bird////
	GLfloat mmmmm=-0.518f; GLfloat nnnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmmmm, nnnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmmmm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nnnnn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.59f,0.79f);
    glVertex2f(-0.58f,0.78f);
    glVertex2f(-0.54f,0.77f);
    glVertex2f(-0.51f,0.79f);
    glVertex2f(-0.499f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.56f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.556f,0.8f);
    glVertex2f(-0.58f,0.83f);
    glEnd();









    //Bird-Copy
    {
    glPushMatrix();
    glTranslatef(.07,-.07,0);
    int i;
	GLfloat mm=0.182f; GLfloat nn=.801f; GLfloat radiusmm =.01f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(225, 225, 208);
    glVertex2f(mm, nn); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.11f,0.79f);
    glVertex2f(0.12f,0.78f);
    glVertex2f(0.16f,0.77f);
    glVertex2f(0.19f,0.79f);
    glVertex2f(0.201f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.14f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.144f,0.8f);
    glVertex2f(0.12f,0.83f);
    glEnd();
	/////2nd bird////
	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.02f,0.8f);
    glVertex2f(-0.01f,0.79f);
    glVertex2f(0.0f,0.78f);
    glVertex2f(0.04f,0.77f);
    glVertex2f(0.07f,0.79f);
    glVertex2f(0.081f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.03f,0.8f);
    glVertex2f(0.02f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.024f,0.8f);
    glVertex2f(0.0f,0.83f);
    glEnd();

	GLfloat mmm=0.062f; GLfloat nnn=.801f; GLfloat radiusmmm =.01f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmm, nnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
			    nnn + (radiusmmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	/////3rd bird/////
	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.72f,0.8f);
    glVertex2f(-0.71f,0.79f);
    glVertex2f(-0.7f,0.78f);
    glVertex2f(-0.66f,0.77f);
    glVertex2f(-0.63f,0.79f);
    glVertex2f(-0.619f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.67f,0.8f);
    glVertex2f(-0.68f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.676f,0.8f);
    glVertex2f(-0.7f,0.83f);
    glEnd();

	GLfloat mmmm=-0.638f; GLfloat nnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmmm,nnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
			    nnnn + (radiusmmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	////4th bird////
	GLfloat mmmmm=-0.518f; GLfloat nnnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmmmm, nnnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmmmm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nnnnn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.59f,0.79f);
    glVertex2f(-0.58f,0.78f);
    glVertex2f(-0.54f,0.77f);
    glVertex2f(-0.51f,0.79f);
    glVertex2f(-0.499f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.56f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.556f,0.8f);
    glVertex2f(-0.58f,0.83f);
    glEnd();
    glPopMatrix();
    }
glLoadIdentity();
	glPopMatrix();
}

    //Field Upper
    glBegin(GL_QUADS);
    glColor3ub(0,100,0);
    glVertex2f(-1,0);
    glVertex2f(-1,-.03);
    glVertex2f(1,-.03);
    glVertex2f(1,0);
    glEnd();

    //Lower field
    glBegin(GL_QUADS);
    glColor3ub(34,139,34);
    glVertex2f(-1,-.03);
    glVertex2f(-1,-.6);
    glVertex2f(1,-.6);
    glVertex2f(1,-.03);
    glEnd();

//TREE
{
    //Tree-round left-1
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(-2.9,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();

    int i;

	GLfloat x=-.75f; GLfloat y=.33f; GLfloat radius =.06f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    GLfloat a=-.68f; GLfloat b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c=-.81f; GLfloat d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e=-.87f; GLfloat f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g=-.61f; GLfloat h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	GLfloat a1=-.61f; GLfloat b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c1=-.88f; GLfloat d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e1=-.87f; GLfloat f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g1=-.61f; GLfloat h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e11=-.64f; GLfloat f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e12=-.75f; GLfloat f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51, 204, 51);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

    GLfloat e123=-.8f; GLfloat f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	GLfloat e1232=-.7f; GLfloat f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-2
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(-2.1,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51, 204, 51);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-3
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(-1.3,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51, 204, 51);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-4
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(-.5,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51, 204, 51);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-5
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(.3,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51, 204, 51);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-6
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(1.1,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51, 204, 51);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-7
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(1.9,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51, 204, 51);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-8
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(2.7,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51, 204, 51);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-9
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(3.5,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51, 204, 51);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Tree-round left-10
    glPushMatrix();
    glScalef(.25,.1,0);
    glTranslatef(4.3,-.09,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	x=-.75f; y=.33f; radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

     a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a, b);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f; f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51, 204, 51);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

     e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();


    //Background Tree

    //Left Back tree
    glPushMatrix();
    glScalef(.6,.6,0);
    glTranslatef(-.97f,-.335f,0.0f);
    glBegin(GL_POLYGON);
	glColor3ub(102, 51, 0);
	glVertex2f(-0.52f,0.45f);
	glVertex2f(-0.48f, 0.45f);
	glVertex2f(-0.48f,0.62f);
    glVertex2f(-0.5f,0.64f);
    glVertex2f(-0.52f,0.62f);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(34,139,34);
    glVertex2f(-0.5f,0.64f);
    glVertex2f(-0.52f,0.62f);
    glVertex2f(-0.58f,0.6f);
	glVertex2f(-0.55f, 0.63f);
	glVertex2f(-0.58f,0.66f);
	glVertex2f(-0.52f,0.66f);
	glVertex2f(-0.52f, 0.72f);
	glVertex2f(-0.5f,0.69f);
	glVertex2f(-0.48f,0.72f);
	glVertex2f(-0.48f, 0.66f);
	glVertex2f(-0.42f,0.66f);
	glVertex2f(-0.45f,0.63f);
	glVertex2f(-0.42f, 0.6f);
	glVertex2f(-0.48f,0.62f);
    glEnd();
    glPopMatrix();

    //Right Back Tree
    glPushMatrix();
    glScalef(.6,.6,0);
    glTranslatef(.97f,-.335f,0.0f);
    glBegin(GL_POLYGON);
	glColor3ub(102, 51, 0);
	glVertex2f(0.52f,0.45f);
	glVertex2f(0.48f, 0.45f);
	glVertex2f(0.48f,0.62f);
    glVertex2f(0.5f,0.64f);
    glVertex2f(0.52f,0.62f);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(34,139,34);
    glVertex2f(0.5f,0.64f);
    glVertex2f(0.52f,0.62f);
    glVertex2f(0.58f,0.6f);
	glVertex2f(0.55f, 0.63f);
	glVertex2f(0.58f,0.66f);
	glVertex2f(0.52f,0.66f);
	glVertex2f(0.52f, 0.72f);
	glVertex2f(0.5f,0.69f);
	glVertex2f(0.48f,0.72f);
	glVertex2f(0.48f, 0.66f);
	glVertex2f(0.42f,0.66f);
	glVertex2f(0.45f,0.63f);
	glVertex2f(0.42f, 0.6f);
	glVertex2f(0.48f,0.62f);
    glEnd();
    glPopMatrix();
}

//Grass-Flower
{
    //Grass-Right-1
    glPushMatrix();
    glScalef(.8,.8,0);
    glTranslatef(.8,-.12,0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();
    int i;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;
	GLfloat e=-.05f; GLfloat f=-.35f; GLfloat radius11 =.02f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 51, 0);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                e + (radius11 * cos(i *  twicePi / triangleAmount)),
            f+ (radius11 * sin(i * twicePi / triangleAmount))
			);
    }
	glEnd();

	GLfloat g=0.05f; GLfloat h=-0.35f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 102, 0);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                g + (radius11 * cos(i *  twicePi / triangleAmount)),
            h+ (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    GLfloat a1=0.0f; GLfloat b1=-0.3f;
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 0);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                a1 + (radius11 * cos(i *  twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glPopMatrix();

	//Grass-Right-2
    glPushMatrix();
    glScalef(.8,.8,0);
    glTranslatef(.8,.15,0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();

    triangleAmount = 20;
    twicePi = 2.0f * PI;
	e=-.05f; f=-.35f; radius11 =.02f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 51, 0);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                e + (radius11 * cos(i *  twicePi / triangleAmount)),
            f+ (radius11 * sin(i * twicePi / triangleAmount))
			);
    }
	glEnd();

	g=0.05f; h=-0.35f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 102, 0);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                g + (radius11 * cos(i *  twicePi / triangleAmount)),
            h+ (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    a1=0.0f; b1=-0.3f;
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 0);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                a1 + (radius11 * cos(i *  twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glPopMatrix();

	//Grass-Middle-1
    glPushMatrix();
    glScalef(.8,.8,0);
    glTranslatef(.0,-.12,0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();

    triangleAmount = 20;
    twicePi = 2.0f * PI;
	e=-.05f; f=-.35f; radius11 =.02f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 51, 0);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                e + (radius11 * cos(i *  twicePi / triangleAmount)),
            f+ (radius11 * sin(i * twicePi / triangleAmount))
			);
    }
	glEnd();

	g=0.05f; h=-0.35f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 102, 0);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                g + (radius11 * cos(i *  twicePi / triangleAmount)),
            h+ (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    a1=0.0f; b1=-0.3f;
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 0);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                a1 + (radius11 * cos(i *  twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glPopMatrix();

	//Grass-Middle-2
    glPushMatrix();
    glScalef(.8,.8,0);
    glTranslatef(0.0,.15,0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();

    triangleAmount = 20;
    twicePi = 2.0f * PI;
	e=-.05f; f=-.35f; radius11 =.02f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 51, 0);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                e + (radius11 * cos(i *  twicePi / triangleAmount)),
            f+ (radius11 * sin(i * twicePi / triangleAmount))
			);
    }
	glEnd();

	g=0.05f; h=-0.35f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 102, 0);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                g + (radius11 * cos(i *  twicePi / triangleAmount)),
            h+ (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    a1=0.0f; b1=-0.3f;
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 0);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                a1 + (radius11 * cos(i *  twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glPopMatrix();

	//Grass-Left-1
    glPushMatrix();
    glScalef(.8,.8,0);
    glTranslatef(-.8,-.12,0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();

    triangleAmount = 20;
    twicePi = 2.0f * PI;
	e=-.05f; f=-.35f; radius11 =.02f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 51, 0);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                e + (radius11 * cos(i *  twicePi / triangleAmount)),
            f+ (radius11 * sin(i * twicePi / triangleAmount))
			);
    }
	glEnd();

	g=0.05f; h=-0.35f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 102, 0);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                g + (radius11 * cos(i *  twicePi / triangleAmount)),
            h+ (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    a1=0.0f; b1=-0.3f;
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 0);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                a1 + (radius11 * cos(i *  twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glPopMatrix();

	//Grass-Left-2
    glPushMatrix();
    glScalef(.8,.8,0);
    glTranslatef(-.8,.15,0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();

    triangleAmount = 20;
    twicePi = 2.0f * PI;
	e=-.05f; f=-.35f; radius11 =.02f;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 51, 0);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                e + (radius11 * cos(i *  twicePi / triangleAmount)),
            f+ (radius11 * sin(i * twicePi / triangleAmount))
			);
    }
	glEnd();

	g=0.05f; h=-0.35f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 102, 0);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                g + (radius11 * cos(i *  twicePi / triangleAmount)),
            h+ (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    a1=0.0f; b1=-0.3f;
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 0);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                a1 + (radius11 * cos(i *  twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glPopMatrix();



}


//Fence
{
    //Fence-Left-1
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(-.25,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 252);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-2
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(.105,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 252);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-3
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(.46,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 252);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-4
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(.815,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 252);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-5
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(1.17,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 252);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-6
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(1.525,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 252);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-7
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(1.88,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 252);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

}


    //FootWalk
    glBegin(GL_QUADS);
    glColor3ub(255,178,102);
    glVertex2f(-1,-.6);
    glVertex2f(-1,-.66);
    glVertex2f(1,-.66);
    glVertex2f(1,-.6);
    glEnd();

//Road / Car
{
    //Road
    glBegin(GL_QUADS);
    glColor3ub(64,64,64);
    glVertex2f(-1,-.67);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-.67);
    glEnd();
    //Road-Line
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(255,215,0);
    glVertex2f(-.98,-.835);
    glVertex2f(-.88,-.835);

    glVertex2f(-.83,-.835);
    glVertex2f(-.73,-.835);

    glVertex2f(-.68,-.835);
    glVertex2f(-.58,-.835);

    glVertex2f(-.53,-.835);
    glVertex2f(-.43,-.835);

    glVertex2f(-.38,-.835);
    glVertex2f(-.28,-.835);

    glVertex2f(-.23,-.835);
    glVertex2f(-.13,-.835);

    glVertex2f(-.08,-.835);
    glVertex2f(.02,-.835);

    glVertex2f(.07,-.835);
    glVertex2f(.17,-.835);

    glVertex2f(.22,-.835);
    glVertex2f(.32,-.835);

    glVertex2f(.37,-.835);
    glVertex2f(.47,-.835);

    glVertex2f(.52,-.835);
    glVertex2f(.62,-.835);

    glVertex2f(.67,-.835);
    glVertex2f(.77,-.835);

    glVertex2f(.82,-.835);
    glVertex2f(.92,-.835);

    glVertex2f(.97,-.835);
    glVertex2f(1,-.835);

    glEnd();

    //Car-Below-Left

    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
    glTranslatef(.11,-.29,0);
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(-.66,-.60);
    glVertex2f(-.66,-.68);
    glVertex2f(-.28,-.68);
    glVertex2f(-.28,-.62);
    glVertex2f(-.27,-.62);
    glVertex2f(-.28,-.60);
    glVertex2f(-.36,-.60);
    glVertex2f(-.40,-.54);
    glVertex2f(-.60,-.54);
    glVertex2f(-.62,-.62);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-.37,-.60);
    glVertex2f(-.40,-.55);
    glVertex2f(-.58,-.55);
    glVertex2f(-.62,-.60);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(-.40,-.55);
    glVertex2f(-.40,-.60);

    glVertex2f(-.58,-.55);
    glVertex2f(-.58,-.60);
    glEnd();

//car wheel back
    int i;
    x=-.58f; y=-.68f; radius =.03f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
//-----------
	 x=-.58f;  y=-.68f;  radius =.018f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,250);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

//car wheel front
	x=-.34f;  y=-.68f;  radius =.03f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
//-----------------
	x=-.34f;  y=-.68f;  radius =.018f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,250);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glLoadIdentity();
    glPopMatrix();



    //Below Car Right
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
    glTranslatef(1.18,-.29,0);
    glBegin(GL_POLYGON);
    glColor3ub(0,0,128);
    glVertex2f(-.66,-.60);
    glVertex2f(-.66,-.68);
    glVertex2f(-.28,-.68);
    glVertex2f(-.28,-.62);
    glVertex2f(-.27,-.62);
    glVertex2f(-.28,-.60);
    glVertex2f(-.36,-.60);
    glVertex2f(-.40,-.54);
    glVertex2f(-.60,-.54);
    glVertex2f(-.62,-.62);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-.37,-.60);
    glVertex2f(-.40,-.55);
    glVertex2f(-.58,-.55);
    glVertex2f(-.62,-.60);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(-.40,-.55);
    glVertex2f(-.40,-.60);

    glVertex2f(-.58,-.55);
    glVertex2f(-.58,-.60);
    glEnd();

//car wheel back

    x=-.58f; y=-.68f; radius =.03f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
//-----------
	 x=-.58f;  y=-.68f;  radius =.018f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,250);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

//car wheel front
	x=-.34f;  y=-.68f;  radius =.03f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
//-----------------
	x=-.34f;  y=-.68f;  radius =.018f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,250);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
    glLoadIdentity();
    glPopMatrix();






}

//Road side tree
{
    //Left-1
    glPushMatrix();
    glScalef(.5,.4,0);
    glTranslatef(-.9,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();

    int i;

	 x=-.75f;  y=.33f;  radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    GLfloat a=-.68f; GLfloat b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c=-.81f; GLfloat d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e=-.87f; GLfloat f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g=-.61f; GLfloat h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	GLfloat a1=-.61f; GLfloat b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c1=-.88f; GLfloat d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e1=-.87f; GLfloat f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g1=-.61f; GLfloat h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e11=-.64f; GLfloat f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e12=-.75f; GLfloat f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51, 204, 51);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

    GLfloat e123=-.8f; GLfloat f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	GLfloat e1232=-.7f; GLfloat f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();


	//Left-2
    glPushMatrix();
    glScalef(.5,.4,0);
    glTranslatef(.35,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	 x=-.75f;  y=.33f;  radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f;  f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51, 204, 51);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

    e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Left-3
    glPushMatrix();
    glScalef(.5,.4,0);
    glTranslatef(1.6,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	 x=-.75f;  y=.33f;  radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f;  f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51, 204, 51);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

    e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();

	//Left-4
    glPushMatrix();
    glScalef(.5,.4,0);
    glTranslatef(2.5,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();


	 x=-.75f;  y=.33f;  radius =.06f;
	triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    a=-.68f;  b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c=-.81f;  d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e=-.87f;  f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g=-.61f;  h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 a1=-.61f;  b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 c1=-.88f;  d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e1=-.87f;  f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 g1=-.61f;  h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e11=-.64f;  f11=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	 e12=-.75f;  f12=.44f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51, 204, 51);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

    e123=-.8f;  f123=.5f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 e1232=-.7f;  f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();




//LIGHT Left
    glPushMatrix();
    glTranslatef(-.3,-.65,0);

    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(-.22,.23);
    glVertex2f(-.22,.02);
    glVertex2f(-.21,.02);
    glVertex2f(-.21,.23);
    glEnd();


    //LIGHT Left Top Two
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(-.22,.23);
    glVertex2f(-.21,.23);
    glVertex2f(-.18,.24);
    glVertex2f(-.2,.25);

    glVertex2f(-.21,.23);
    glVertex2f(-.22,.23);
    glVertex2f(-.26,.24);
    glVertex2f(-.23,.25);
    glEnd();
    glLoadIdentity();
    glPopMatrix();


    //LIGHT Right
    glPushMatrix();
    glTranslatef(0,-.65,0);
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(.22,.23);
    glVertex2f(.22,.02);
    glVertex2f(.21,.02);
    glVertex2f(.21,.23);
    glEnd();


    //LIGHT Right Top Two

    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(.22,.23);
    glVertex2f(.21,.23);
    glVertex2f(.18,.24);
    glVertex2f(.2,.25);

    glVertex2f(.21,.23);
    glVertex2f(.22,.23);
    glVertex2f(.26,.24);
    glVertex2f(.23,.25);
    glEnd();
    glLoadIdentity();
    glPopMatrix();







//LIGHT Left
    glPushMatrix();
    glTranslatef(-.75,-.65,0);

    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(-.22,.23);
    glVertex2f(-.22,.02);
    glVertex2f(-.21,.02);
    glVertex2f(-.21,.23);
    glEnd();


    //LIGHT Left Top Two
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(-.22,.23);
    glVertex2f(-.21,.23);
    glVertex2f(-.18,.24);
    glVertex2f(-.2,.25);

    glVertex2f(-.21,.23);
    glVertex2f(-.22,.23);
    glVertex2f(-.26,.24);
    glVertex2f(-.23,.25);
    glEnd();
    glLoadIdentity();
    glPopMatrix();


    //LIGHT Right
    glPushMatrix();
    glTranslatef(.5,-.65,0);
    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(.22,.23);
    glVertex2f(.22,.02);
    glVertex2f(.21,.02);
    glVertex2f(.21,.23);
    glEnd();


    //LIGHT Right Top Two

    glBegin(GL_QUADS);
    glColor3ub(20,20,20);
    glVertex2f(.22,.23);
    glVertex2f(.21,.23);
    glVertex2f(.18,.24);
    glVertex2f(.2,.25);

    glVertex2f(.21,.23);
    glVertex2f(.22,.23);
    glVertex2f(.26,.24);
    glVertex2f(.23,.25);
    glEnd();
    glLoadIdentity();
    glPopMatrix();







	//Upper Car
    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);
    glTranslatef(0,-.38,0);
    glBegin(GL_POLYGON);
    glColor3ub(128,0,0);
    glVertex2f(.04,-.24);
    glVertex2f(0.0,-.34);
    glVertex2f(0,-.40);
    glVertex2f(.4,-.40);
    glVertex2f(.4,-.24);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240,255,240);
    glVertex2f(.37,-.26);
    glVertex2f(.30,-.26);
    glVertex2f(.30,-.34);
    glVertex2f(.37,-.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240,255,240);
    glVertex2f(.28,-.26);
    glVertex2f(.22,-.26);
    glVertex2f(.22,-.34);
    glVertex2f(.28,-.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240,255,240);
    glVertex2f(.20,-.26);
    glVertex2f(.14,-.26);
    glVertex2f(.14,-.34);
    glVertex2f(.20,-.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240,255,240);
    glVertex2f(.12,-.26);
    glVertex2f(.05,-.26);
    glVertex2f(.02,-.34);
    glVertex2f(.12,-.34);
    glEnd();
//car wheel front
	x=.08f;  y=-.40f;  radius =.04f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
//-----------------
	x=.08f;  y=-.40f;  radius =.025f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,250);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
//car wheel back
	x=.3f;  y=-.40f;  radius =.04f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
//-----------------
	x=.3f;  y=-.40f;  radius =.025f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,250);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();
	glLoadIdentity();
    glPopMatrix();


}


    //glutTimerFunc(8000,night,0);

	glFlush();


}




void display()
{
    glutDisplayFunc(day);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    //glutInitWindowPosition(300,100);
    glutCreateWindow("Final Project");
    init();
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	//glutTimerFunc(200, update, 0);
	//glutTimerFunc(200, update2, 0);
    //glutTimerFunc(200, update3, 0);
    glutTimerFunc(200, update4, 0);

    glutSpecialFunc(SpecialInput);
    glutKeyboardFunc(abc);
    glutMouseFunc(mouseCount);

	glutMainLoop();
	return 0;
}
