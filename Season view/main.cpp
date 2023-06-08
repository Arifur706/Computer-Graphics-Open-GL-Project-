#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdbool.h>
#include<cmath>
#include<stdlib.h>

void circle(float r, int x_center, int y_center)
{

    int deg =0;
    float x,y,theta;

    glBegin(GL_POLYGON);

    while(deg<360)
    {

        theta = (deg*M_PI)/180;
        x = x_center + r* cos(theta);
        y = y_center + r* sin(theta);
        deg++;

        glVertex2d(x,y);
    }
    glEnd();
}
void circle1(float r, int x_center, int y_center)
{

    int deg =0;
    float x,y,theta;

    glBegin(GL_LINE_LOOP);

    while(deg<360)
    {

        theta = (deg*M_PI)/180;
        x = x_center + r* cos(theta);
        y = y_center + r* sin(theta);
        deg++;

        glVertex2d(x,y);
    }
    glEnd();
}


float boat_x= 0.0,sun_y= 0.0,cloud_x=0.0, bird_x = 0.0;
float angle1  = 0.0;
int angle  = 0.0;
int r = 58, g= 194, b = 224;
int r1= 37, r2= 48,r3= 20;

bool moving = true;
bool moving1 = true;
bool moving3 = true;

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 's': //stop boat
    {
        moving3 = false;
        break;
        glutPostRedisplay();
    }


    case 'd': //boat move
    {
        moving3 = true;
        break;
        glutPostRedisplay();
    }
    case 'e': //rainy
    {
        r = 194;
        g= 191;
        b = 186;

        moving = false;
        glutPostRedisplay();
        break;
    }

    case 'r':
    {

        r = 58;
        g= 194;
        b = 224;
        moving = true;
        glutPostRedisplay();
        break;

    }

    case 'w': //winter
    {

        r1= 255;
        r2= 255;
        r3= 255;
        glutPostRedisplay();
        break;

    }
    case 'q':
    {

        r1= 34;
        r2= 139;
        r3= 34;
        glutPostRedisplay();
        break;

    }

    case 'k': //autumn
    {

        r1= 212;
        r2= 91;
        r3= 18;
        glutPostRedisplay();
        break;

    }
    case 'l':
    {

        r1= 34;
        r2= 139;
        r3= 34;
        glutPostRedisplay();
        break;

    }


    }
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);


//sky
    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex2i(0,50);
    glVertex2i(0,100);
    glVertex2i(100,100);
    glVertex2i(100,60);
    glEnd();

//sun
    glPushMatrix();
    glTranslatef(0.0, sun_y, 0.0f);
    glColor3ub(253,185,101);
    circle(6,15,70);
    glPopMatrix();


//draw river
    glColor3ub(135,206,250);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(0, 30);
    glVertex2i(100, 25);
    glVertex2i(100, 10);
    glEnd();

//ground


    glColor3ub(r1, r2, r3);
    glBegin(GL_POLYGON);
    glVertex2i(0, 30);
    glVertex2i(0, 65);
    glVertex2i(100, 70);
    glVertex2i(100, 25);
    glEnd();

    glColor3ub(0,100,0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    for (int i=5; i<100 ; i+=5)
    {
        glVertex2i(i, 0);
        glVertex2i(i-2, 3);

        glVertex2i(i, 0);
        glVertex2i(i+2, 3);


    }
    glEnd();


//draw boat

    glPushMatrix();
    glTranslatef(boat_x, 0.0, 0.0);

    glBegin(GL_POLYGON); //body
    glColor3ub(0,0,0);
    glVertex2i(15,11);
    glVertex2i(10,15);
    glVertex2i(25,15);
    glVertex2i(20,11);
    glEnd();

    glBegin(GL_POLYGON); //body
    glColor3ub(112,128,144);
    glVertex2i(12,15);
    glVertex2i(15,18);
    glVertex2i(20,18);
    glVertex2i(23,15);
    glEnd();

    glColor3ub(0, 0, 0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2i(14, 19);
    glVertex2i(10, 10);

    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(boat_x, 0.0, 0.0);
    glTranslatef( 30.0, 5.0, 0.0);
    glBegin(GL_POLYGON); //body
    glColor3ub(255,140,0);
    glVertex2i(15,11);
    glVertex2i(10,15);
    glVertex2i(25,15);
    glVertex2i(20,11);
    glEnd();
    glBegin(GL_POLYGON); //body
    glColor3ub(240,230,140);
    glVertex2i(12,15);
    glVertex2i(15,18);
    glVertex2i(20,18);
    glVertex2i(23,15);
    glEnd();

    glColor3ub(0, 0, 0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2i(14, 19);
    glVertex2i(10, 10);

    glEnd();

glPopMatrix();

    glPushMatrix();
    glTranslatef(boat_x, 0.0, 0.0);
    glTranslatef(-30.0, 5.0, 0.0);
    glBegin(GL_POLYGON); //body
    glColor3ub(0,0,0);
    glVertex2i(15,11);
    glVertex2i(10,15);
    glVertex2i(25,15);
    glVertex2i(20,11);
    glEnd();

    glBegin(GL_POLYGON); //body
    glColor3ub(128,0,0);
    glVertex2i(12,15);
    glVertex2i(15,18);
    glVertex2i(20,18);
    glVertex2i(23,15);
    glEnd();

    glColor3ub(0, 0, 0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2i(14, 19);
    glVertex2i(10, 10);

    glEnd();

    glPopMatrix();


//draw 1st house
    glPushMatrix();
    glColor3ub(240,230,140);
    glRecti(10, 35, 25, 48);


    glColor3ub(143,188,143);//window
    glRecti(11,41,14, 45);

    glColor3ub(143,188,143);
    glRecti(21,41,24,45);

    glColor3ub(139,69,19);
    glRecti(15,35,20,44);

    glBegin(GL_POLYGON); //upper
    glColor3ub(47,79,79);
    glVertex2i(8,48);
    glVertex2i(11,55);
    glVertex2i(24,55);
    glVertex2i(27,48);
    glEnd();

    glPopMatrix();

//draw 2nd house
    glPushMatrix();
    glTranslatef(48.0, 5.0, 0.0);
    glColor3ub(230,190,138);
    glRecti(10, 35, 25, 48);


    glColor3ub(255,215,0);//window
    glRecti(11,41,14, 45);

    glColor3ub(255,215,0);
    glRecti(21,41,24,45);

    glColor3ub(205,133,63);
    glRecti(15,35,20,44);

    glBegin(GL_POLYGON); //upper
    glColor3ub(128,0,0);
    glVertex2i(8,48);
    glVertex2i(11,55);
    glVertex2i(24,55);
    glVertex2i(27,48);
    glEnd();

    glPopMatrix();

    glPopMatrix();


    glColor3ub(0,0,0);//big road
    glRecti(17, 31, 65, 33);
    glRecti(17, 31, 19, 35);
    glRecti(65, 31, 67, 40);
    glRecti(37, 28, 39, 31);

//Tree 1st

glPushMatrix();
    glColor3ub(82, 54, 36);//body
    glTranslatef(-6.0,0.0,0.0);
    glRecti(37, 37, 41, 49);

    glColor3ub(0,132,0);//leaf
    circle(4, 37, 52);
    circle(5, 37, 57);
    circle(5, 41, 57);
    circle(4, 41, 52);
    glPopMatrix();

//Tree 2nd

glPushMatrix();
    glColor3ub(82, 54, 36);//body
    glTranslatef(12.0,9.0,0.0);
    glRecti(37, 37, 41, 49);

    glColor3ub(0,132,0);//leaf
    circle(4, 37, 52);
    circle(5, 37, 57);
    circle(5, 41, 57);
    circle(4, 41, 52);
    glPopMatrix();

//wind

    glColor3ub(128,128,128);//body
    glRecti(89, 35, 91, 55);

    glColor3ub(160,82,45);
    glPushMatrix();
    glTranslatef(90.0, 55.0, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glTranslatef(-90.0, -55.0, 0.0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2i(90, 55);
    glVertex2i(85, 43);

    glVertex2i(90, 55);
    glVertex2i(85, 65);

    glVertex2i(90, 55);
    glVertex2i(95, 43);

    glVertex2i(90, 55);
    glVertex2i(95, 65);
    glEnd();
    angle -= 2;
    glPopMatrix();


//cloud
    glPushMatrix();
    glTranslatef(cloud_x, 0.0, 0.0);
    glTranslatef(0.0, 10.0, 0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(5, 20, 70);
    circle(5, 24, 70);
    circle(4, 22, 74);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(25.0, 20.0, 0.0);
    glTranslatef(cloud_x, 0.0, 0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(5, 20, 70);
    circle(5, 24, 70);
    circle(4, 22, 74);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25.0, 20.0, 0.0);
    glTranslatef(cloud_x, 0.0, 0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(5, 20, 70);
    circle(5, 24, 70);
    circle(4, 22, 74);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(bird_x, 0.0, 0.0);
    glTranslatef(-20, 0.0, 0.0);
     glBegin(GL_LINES);
    glVertex2i(15,70);
    glVertex2i(13,72);
    glVertex2i(15,70);
    glVertex2i(17,72);

    glVertex2i(22,70);
    glVertex2i(20,72);
    glVertex2i(22,70);
    glVertex2i(24,72);

    glVertex2i(18,73);
    glVertex2i(16,75);
    glVertex2i(18,73);
    glVertex2i(20,75);
    glEnd();
    glPopMatrix();




    glFlush();


}

void sun(int value)
{
    if(moving)
    {
        sun_y += .1;
        {
            if (sun_y > 35)
            {
                sun_y = -40;
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(20, sun, 0);
}

void cloud(int value)
{
    if(moving1)
    {
        cloud_x += .1;
        {
            if (cloud_x > 110.0)
            {
                cloud_x = -40;
            }
        }
    }


    glutPostRedisplay();

    glutTimerFunc(10, cloud, 0);
}

void birds(int value)
{
        bird_x += .1;
        {
            if (bird_x > 110.0)
            {
                bird_x = -40;
            }
        }

    glutPostRedisplay();

    glutTimerFunc(20, birds, 0);
}


void boat(int value)
{
    if(moving3)
    {
        boat_x += .1;
        {
            if (boat_x > 85)
            {
                boat_x = -30;
            }
        }
    }


    glutPostRedisplay();
    glutTimerFunc(20, boat, 0);
}


void init()
{
    glClearColor(0.148, 0.190, 0.0817, 0.0);
    gluOrtho2D(0.0f, 100.0f, 0.0f, 100.0f);

}
//coand line argument and pointer argument
int main(int argc, char** argv)
{

glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(300, 100);
    glutInitWindowSize(1000, 600);
    glutCreateWindow("PROJECT");
    //display callback Function
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, sun, 0);
    glutTimerFunc(0, cloud, 0);
    glutTimerFunc(0, birds, 0);
    glutTimerFunc(0, boat, 0);
    init();
    //Add a timer
    glutMainLoop();

    return 0;
}
