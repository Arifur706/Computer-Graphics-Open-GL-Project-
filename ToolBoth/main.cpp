#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<cmath>

//Draw Circle

void createCircle(float r, int x_center, int y_center)
{
    int deg = 0;
    double x,y,theta;

    glBegin(GL_POLYGON);
    while(deg < 360)
    {
        theta = (deg*M_PI)/180;
        x = x_center+ r*cos(theta);
        y = y_center+ r*sin(theta);
        deg++;
        glVertex2d(x,y);
    }
    glEnd();

}

void createUnfilledCircle(float r, int x_center, int y_center)
{
    int deg = 0;
    double x,y,theta;

    glPointSize(3);
    glBegin(GL_POINTS);
    while(deg < 360)
    {
        theta = (deg*M_PI)/180;
        x = x_center+ r*cos(theta);
        y = y_center+ r*sin(theta);
        deg++;
        glVertex2d(x,y);
    }
    glEnd();

}
//End of draw circle

//draw fild
void drawfield(){
    glColor3ub(153, 153, 0);

    glRecti(0,35, 100, 50);

}

//End draw field

//draw hill
void drawhill(){
    glColor3ub(0, 153, 0);

    glBegin(GL_TRIANGLES);
    glColor3ub(12, 174, 91);
    glVertex2i(0,50);
    glVertex2i(5,64);
    glVertex2i(11,50);

     glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(12, 174, 91);
    glVertex2i(8,50);
    glVertex2i(18,69);
    glVertex2i(29,50);

     glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(12, 174, 91);
    glVertex2i(25,50);
    glVertex2i(31,61);
    glVertex2i(40,50);

     glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(12, 174, 91);
    glVertex2i(34,50);
    glVertex2i(44,72);
    glVertex2i(55,50);

     glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(12, 174, 91);
    glVertex2i(47,50);
    glVertex2i(57,66);
    glVertex2i(67,50);

     glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(12, 174, 91);
    glVertex2i(62,50);
    glVertex2i(72,70);
    glVertex2i(84,50);

     glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(12, 174, 91);
    glVertex2i(77,50);
    glVertex2i(90,65);
    glVertex2i(100,50);


     glEnd();

}

//End draw hill

//draw Rail Line

 void drawrailline()
 {
    glColor3ub(34, 38, 46); //Line
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(0,-5);
    glVertex2i(100,-5);

    glVertex2i(0,2);
    glVertex2i(100,2);
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);

    for (int i=0; i<=95; i+=5)
    {
    glVertex2i(i,-5);
    glVertex2i(i+5,2);

    }
    glEnd();

 }

//End Rail Line

//Draw Train

double trian_position = 0.0;
void drawtrain()
{
    glPushMatrix();
    glTranslated(trian_position, 0.0, 0.0);
    glColor3ub(34, 38, 46);
    createCircle(3, 67 , -2); //wheel
    createCircle(3, 73 , -2);

    createCircle(3, 87 , -2);
    createCircle(3, 93 , -2);

    glColor3ub(0, 191, 124); //body
    glBegin(GL_POLYGON);
    glVertex2i(56,-2);
    glVertex2i(56,0);
    glVertex2i(57,1);
    glVertex2i(58,4);
    glVertex2i(59,8);
    glVertex2i(60,9);
    glVertex2i(100,9);
    glVertex2i(100,-2);
    glEnd();

    glColor3ub(255, 191, 124); //window1
    glBegin(GL_POLYGON);
    glVertex2i(62,2);
    glVertex2i(62,7);
    glVertex2i(66,7);
    glVertex2i(66,2);
    glEnd();

    glColor3ub(255, 191, 124); //window2
    glBegin(GL_POLYGON);
    glVertex2i(68,2);
    glVertex2i(68,7);
    glVertex2i(72,7);
    glVertex2i(72,2);
    glEnd();

    glColor3ub(255, 191, 124); //door1
    glBegin(GL_POLYGON);
    glVertex2i(74,-1);
    glVertex2i(74,7);
    glVertex2i(78,7);
    glVertex2i(78,-1);
    glEnd();

    glColor3ub(255, 191, 124); //window3
    glBegin(GL_POLYGON);
    glVertex2i(80,2);
    glVertex2i(80,7);
    glVertex2i(84,7);
    glVertex2i(84,2);
    glEnd();

    glColor3ub(255, 191, 124); //window4
    glBegin(GL_POLYGON);
    glVertex2i(86,2);
    glVertex2i(86,7);
    glVertex2i(90,7);
    glVertex2i(90,2);
    glEnd();

    glColor3ub(255, 191, 124); //door2
    glBegin(GL_POLYGON);
    glVertex2i(92,-1);
    glVertex2i(92,7);
    glVertex2i(96,7);
    glVertex2i(96,-1);
    glEnd();

    glPopMatrix();

}

void traintimer(int value)//car Animation
{

        trian_position -= .5; //increase position in x axis with 0.5 axis
        if (trian_position < -100.0)
            trian_position = 40.0;

    glutPostRedisplay();
    glutTimerFunc(10, traintimer, 0); // Call update function again after 10 milliseconds
}

//End Train

//draw Road

void drawroad()
{

    glColor3ub(34, 38, 46); //Road
    glRecti(0,10,100,30);

    glColor3ub(242, 223, 21); //Road side
    glRecti(0,30,100,35);

    glColor3ub(255, 255, 255);
    glLineWidth(5.0);

    glBegin(GL_LINES);
    glVertex2i(0,30);
    glVertex2i(5,35);

    glVertex2i(15,30);
    glVertex2i(20,35);

    glVertex2i(30,30);
    glVertex2i(35,35);

    glVertex2i(45,30);
    glVertex2i(50,35);

    glVertex2i(60,30);
    glVertex2i(65,35);

    glVertex2i(90,30);
    glVertex2i(95,35);

    glEnd();

    glColor3ub(78, 102, 109); //road divider
    glRecti(73,10,77,30);

    glColor3ub(0, 0, 0); //road divider Line
    glBegin(GL_LINES);
    glVertex2i(75,10);
    glVertex2i(75,30);
    glEnd();

    glColor3ub(255, 255, 255);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2i(73,10);
    glVertex2i(77,15);

    glVertex2i(73,15);
    glVertex2i(77,20);

    glVertex2i(73,20);
    glVertex2i(77,25);

    glVertex2i(73,25);
    glVertex2i(77,30);
    glEnd();

    glColor3ub(255, 255, 255); //road divider Line
    for(int i=0; i<=96; i+=8)
    {
        glBegin(GL_LINES);
        glVertex2i(i,20);
        glVertex2i(i+5,20);
        glEnd();
    }

}


//End Road Draw

//Draw Plaza

void drawplaza()
{

    glPushMatrix();

    glColor3ub(83, 100, 214);//Building
    glRecti(63,30,87,65);

    glColor3ub(151, 128, 194);//Name Plate
    glRecti(66,57,84,63);

    glColor3ub(78, 200, 216);//Window
    glRecti(67,37,73,53);

    glColor3ub(78, 200, 216);//Window
    glRecti(77,37,83,53);

    glPopMatrix();
}

//End Draw Plaza

//Draw Signal Light
int red= 148;
int green= 148;
int blue= 62;
void drawlight()
{

    glPushMatrix();
    glColor3ub(171, 81, 54);
    glLineWidth(5.0);
    glBegin(GL_LINES);//Light Stand
    glVertex2i(93,35);
    glVertex2i(93,40);
    glEnd();

    glColor3ub(212, 159, 164);
    glRecti(90,40,96,50);

    glColor3ub(red, green, blue);//Light
    createCircle(2,93,45);

    glPopMatrix();
}

//End Draw Signal Light

//Draw Man
int  deg=0, axis=0;
void drawman()
{

    glColor3ub(48, 48, 44);//leg
    glLineWidth(8.0);
    glBegin(GL_LINES);
    glVertex2i(56,30);
    glVertex2i(56,36);

    glVertex2i(58,30);
    glVertex2i(58,36);
    glEnd();

    glColor3ub(151, 128, 194);//body
    glRecti(54,36,60,43);

    glColor3ub(163, 161, 142); //head
    createCircle(3,57.5f,46);

    glColor3ub(0, 0, 0);//eye
    createCircle(0.7f,56,46);

    glColor3ub(0, 0, 0);//eye
    createCircle(0.7f,58,46);

    glColor3ub(48, 48, 44);//hand
    glPushMatrix();
    glRotatef(deg, 0,0,axis);
    glLineWidth(6.0);
    glBegin(GL_LINES);
    glVertex2i(60,43);
    glVertex2i(63,36);
    glEnd();
    glPopMatrix();

    glBegin(GL_LINES);
    glVertex2i(54,43);
    glVertex2i(50,36);
    glEnd();

}

//End Draw Man

//Draw Tree
float tree1 = 0.0, tree2 = -25.0;//x axis value
void drawtree(float x, float y)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    glColor3ub(82, 54, 36);
    glRecti(43, 35, 47, 52);
    glColor3ub(0,132,0);
    glBegin(GL_POLYGON);
    glVertex2i(44,52);
    glVertex2i(35,52);
    glVertex2i(42,56);
    glVertex2i(37,56);
    glVertex2i(43,60);
    glVertex2i(39,60);
    glVertex2i(45,66);
    glVertex2i(51,60);
    glVertex2i(47,60);
    glVertex2i(52,56);
    glVertex2i(46,56);
    glVertex2i(55,52);
    glVertex2i(46,52);
    glEnd();
    glPopMatrix();
}

//End Draw Tree

//Draw Car
float carPositionsX=0.0;
float carlPositionsX=0.0;
float wheelAngle = 0.0f;
float wheelAnglel = 0.0f;
bool isMoving = true;
void drawcar()
{
    glColor3ub(171, 81, 54);
    glPushMatrix();
    glTranslatef(carPositionsX, 4.0f, 0.0f);
    glBegin(GL_POLYGON); //Car body
    glVertex2i(14,20);
    glVertex2i(14,26);
    glVertex2i(15,26);
    glVertex2i(17,27);
    glVertex2i(17,29);
    glVertex2i(19,31);
    glVertex2i(20,32);

    glVertex2i(28,32);
    glVertex2i(29,31);
    glVertex2i(30,30);
    glVertex2i(33,26);
    glVertex2i(35,26);
    glVertex2i(35,20);
    glEnd();

    glColor3ub(29, 43, 82);
    glRecti(20,25,23,29); //car window
    glRecti(25,25,28,29);

    glPushMatrix();
    glTranslatef(19, 20, 0);//car wheel
    glRotatef(wheelAngle, 0, 0, 1);
    glTranslatef(-19, -20, 0);
    glColor3ub(29, 43, 82);
    createCircle(2.5f,19,20);
    glColor3ub(218, 227, 229);
    createUnfilledCircle(2.0,19,20);

    glColor3ub(218, 227, 229);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2i(17,20);
    glVertex2i(21,20);
    glVertex2i(19,18);
    glVertex2i(19,22);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(29, 20, 0);
    glRotatef(wheelAngle, 0, 0, 1);
    glTranslatef(-29, -20, 0);
    glColor3ub(29, 43, 82);
    createCircle(2.5f,29,20);
    glColor3ub(218, 227, 229);
    createUnfilledCircle(2.0,29,20);

    glColor3ub(218, 227, 229);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2i(27,20);
    glVertex2i(31,20);
    glVertex2i(29,18);
    glVertex2i(29,22);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void drawcarl()
{

    glPushMatrix();
    glTranslatef(carlPositionsX, 0.0f, 0.0f);
    glColor3ub(23, 14, 120);
    glBegin(GL_POLYGON); //Car body
    glVertex2i(81,13);
    glVertex2i(81,14);
    glVertex2i(82,15);
    glVertex2i(83,16);
    glVertex2i(85,21);
    glVertex2i(93,21);
    glVertex2i(96,17);
    glVertex2i(96,13);
    glEnd();
    glColor3ub(29, 43, 82);
    glRecti(86, 17, 91, 19);

    glPushMatrix();
    glTranslatef(85, 13, 0);
    glRotatef(wheelAnglel, 0, 0, 1);
    glTranslatef(-85, -13, 0);
    glColor3ub(0, 0, 0);
    createCircle(1.5, 85, 13);
    glColor3ub(255, 255, 255);
    createUnfilledCircle(1.4, 85, 13);

    glColor3ub(255, 255, 255);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(84,13);
    glVertex2i(86,13);

    glVertex2i(85,12);
    glVertex2i(85,14);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(7.0, 0.0, 0.0);
    glTranslatef(85, 13, 0);
    glRotatef(wheelAnglel, 0, 0, 1);
    glTranslatef(-85, -13, 0);
    createCircle(1.5, 85, 13);
    glColor3ub(255, 255, 255);
    createUnfilledCircle(1.4, 85, 13);

    glColor3ub(255, 255, 255);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(84,13);
    glVertex2i(86,13);

    glVertex2i(85,12);
    glVertex2i(85,14);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}
void cartimer(int value)//car Animation
{
    if (isMoving)
    {
        carPositionsX += .1; //increase position in x axis with 0.1 axis
        if (carPositionsX > 87.0f)
            carPositionsX = -40.0f;

        wheelAngle -= 6.0f;
    }

        carlPositionsX -= .1; //increase position in x axis with 0.1 axis
        if (carlPositionsX < -100.0f)
            carlPositionsX = 20.0f;

        wheelAnglel += 6.0f;

    glutPostRedisplay();
    glutTimerFunc(10, cartimer, 0); // Call update function again after 10 milliseconds
}

//End Draw Car

//Draw Bus

float busPositionsX=0.0;
float bwheelAngle = 0.0f;
bool isMovingb = true;
void drawBus()
{
glPushMatrix();
    glTranslatef(busPositionsX, 4.0f, 0.0f);
    glTranslatef(-80, 0.0, 0.0);
    glColor3ub(143, 235, 45);
    glRecti(40, 20, 70, 36);
    glPushMatrix();
    glColor3ub(29, 43, 82);
    glRecti(44, 25, 49, 33);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(8.0, 0.0, 0.0);
    glColor3ub(29, 43, 82);
    glRecti(44, 25, 49, 33);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(16.0, 0.0, 0.0);
    glColor3ub(29, 43, 82);
    glRecti(44, 25, 49, 33);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(46, 20, 0);
    glRotatef(bwheelAngle, 0, 0, 1);
    glTranslatef(-46, -20, 0);
    glColor3ub(23, 26, 21);
    createCircle(3.0, 46, 20);
    glColor3ub(255, 255, 255);
    createUnfilledCircle(2.9, 46, 20);

    glColor3ub(255, 255, 255);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(46,17);
    glVertex2i(46,23);

    glVertex2i(43,20);
    glVertex2i(49,20);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, 0.0, 0.0);
    glTranslatef(46, 20, 0);
    glRotatef(bwheelAngle, 0, 0, 1);
    glTranslatef(-46, -20, 0);
    glColor3ub(23, 26, 21);
    createCircle(3.0, 46, 20);
    glColor3ub(255, 255, 255);
    createUnfilledCircle(2.9, 46, 20);

    glColor3ub(255, 255, 255);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(46,17);
    glVertex2i(46,23);

    glVertex2i(43,20);
    glVertex2i(49,20);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(18.0, 0.0, 0.0);
    glTranslatef(46, 20, 0);
    glRotatef(bwheelAngle, 0, 0, 1);
    glTranslatef(-46, -20, 0);
    glColor3ub(23, 26, 21);
    createCircle(3.0, 46, 20);
    glColor3ub(255, 255, 255);
    createUnfilledCircle(2.9, 46, 20);

    glColor3ub(255, 255, 255);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(46,17);
    glVertex2i(46,23);

    glVertex2i(43,20);
    glVertex2i(49,20);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void bustimer(int value)//bus Animation
{
    if (isMovingb)
    {
        busPositionsX += .1; //increase position in x axis with 0.1 axis
        if (busPositionsX > 140.0f)
            busPositionsX = 0.0f;

        bwheelAngle -= 6.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(10, bustimer, 0); // Call update function again after 10 milliseconds
}
//End Draw Bus

//Draw Cloud

float cloud1 = 0.0, cloud2 = 15.0; //x-axis position
float cloud_pos = 0.0;
void drawCloud(float x, float y)
{

    glPushMatrix();
    glTranslatef(x, y, 0.0);
    glColor3ub(239, 222, 222);
    glBegin(GL_POLYGON);
      glVertex2i(14,80);
      glVertex2i(12,80);
      glVertex2i(10,82);
      glVertex2i(10,85);
      glVertex2i(12,87);
      glVertex2i(14,89);
      glVertex2i(17,89);
      glVertex2i(20,87);
      glVertex2i(21,85);
      glVertex2i(21,84);
      glVertex2i(20,80);
      glVertex2i(17,79);
      glVertex2i(14,80);
    glEnd();

    glPopMatrix();


}

void drawCloud1()
{
    glPushMatrix();
    glTranslatef(cloud_pos, 0.0, 0.0);
    glColor3ub(239, 222, 222);
    createCircle(5, 45 ,85);
    createCircle(5, 49 ,85);
    createCircle(5, 47 ,88);
    glPopMatrix();
}
void cloudtimer(int value)
{
    // Update cloud position
    cloud1 += 0.5; //increase position in x axis with 0.5 axis
    cloud2 += 0.3; //increase position in x axis with 0.3 axis
    cloud_pos += 0.4; //increase position in x axis with 0.4 axis


    if (cloud1 > 90.0)
        cloud1 = -20.0;
   if (cloud2 > 90.0)
       cloud2 = -20.0;
    if (cloud_pos > 70.0)
        cloud_pos = -55.0;

    glutPostRedisplay();
    glutTimerFunc(100, cloudtimer, 0);  // Call update function again after 100 milliseconds
}

//End Draw Cloud

//Draw Sun

float x_inc=0;
bool isMoving1=true;
int deg1=18;
int axis1=1;
int sunc1= 252, sunc2=232, sunc3=3;
int sc=6;
void drawsun()
{
    glPushMatrix();
    glColor3ub(sunc1, sunc2, sunc3);
    glRotatef(deg1, 0,0,axis1);
    glTranslatef(x_inc,0.0f, 0.0f);
    createCircle(sc,20,55);
    glPopMatrix();
}
void suntimer(int value)
{
    if(isMoving1)
    {
        x_inc +=0.1; //increase position in x axis with 0.1 axis
        if (x_inc>110.0)
            {
                glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
                sunc1= 239;
                sunc2= 232;
                sunc3= 232;
                sc=4;
                x_inc = -10.0f;
            }

    glutPostRedisplay();
    glutTimerFunc(20, suntimer, 0);// Call update function again after 10 milliseconds
    }

}

//End Draw Sun

void display()
{
//clear the frame buffer
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawsun();

    drawrailline();

    drawtrain();

    drawroad();

    drawhill();

    drawfield();

    drawplaza();

    drawlight();

    drawman();

    drawtree(tree1, 0.0);
    drawtree(tree2, 0.0);

    drawcar();
    drawBus();
    drawcarl();


    drawCloud1();
    drawCloud(cloud1, 0.0);//draw cloud at x-axis(cloud1) and y-axis(0.0)
    drawCloud(cloud2, 10.0); //draw cloud at x-axis(cloud2) and y-axis(10.0)

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 27:
        exit(0);
        break;

    case 'a': //Hand Up
    case 'A':
        deg=5;
        axis = 1;
        red=219; //change light color
        green=4;
        blue=26;
        glutPostRedisplay();
        break;

    case 'z': //Hand Down
    case 'Z':
        deg=-5;
        axis = 0;
        red=0; //back to light color
        green=205;
        blue=0;

        isMoving = true;
        isMovingb = true;
        glutPostRedisplay();
        break;

    case 's':  //Stop Car
    case 'S':
        isMoving = false;
        glutPostRedisplay();
        break;

    case 'q':  //Stop bus
    case 'Q':
        isMovingb = false;
        glutPostRedisplay();
        break;

    case 'd':  //Back to daydd
    case 'D':
        glClearColor(0.641, 0.832, 0.890, 0.0);
        sunc1= 252;
        sunc2=232;
        sunc3=3;
        sc=6;
        glutPostRedisplay();
        break;

    default:

        break;

    }
}



//void reshape(int w, int h)
//{
//    glClearColor(0.641, 0.832, 0.890, 0.0);
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    float h2wRatio = (float)h/(float)w;
//    float w2hRatio = (float)w/(float)h;
//    if(w <= h)
//        gluOrtho2D(0, 100*h2wRatio, -10, 100);
//    else
//        gluOrtho2D(0, 100, -10*w2hRatio, 100);
//    glMatrixMode(GL_MODELVIEW);
//}

//void reshape(int w, int h){
//
//    glClearColor(0.641, 0.832, 0.890, 0.0);
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//
//    float h2wRatio = (float)h/(float)w;
//    float w2hRatio = (float)w/(float)h;
//
//    if(w<=h)
//        gluOrtho2D(0.0, 100.0, -10.0, 100.0*h2wRatio);
//
//    else
//        gluOrtho2D(0.0*w2hRatio, 100.0, -10.0, 100.0);
//
//
//    glMatrixMode(GL_MODELVIEW);
//
//}

int windowWidth = 1200;
int windowHeight = 680;

void reshape(int width, int height) {
    windowWidth = width;
    windowHeight = height;
    glViewport(0, 0, width, height);
    glClearColor(0.641, 0.832, 0.890, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, -10, 100);
    if(width != 1200 || height != 680) {
        glutPositionWindow(100, 25);
        glutReshapeWindow(1200, 680);
        glutPostRedisplay();
    }
    glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(100, 0);
    glutInitWindowSize(1200, 680);

    glutCreateWindow("Tool Plaza");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, traintimer, 0);
    glutTimerFunc(0, cloudtimer, 0);
    glutTimerFunc(0, cartimer, 0);
    glutTimerFunc(0, bustimer, 0);
    glutTimerFunc(0, suntimer, 0);

    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;

}
