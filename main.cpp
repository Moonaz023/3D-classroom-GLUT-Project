///Copyright © 2024 moonaz023. All Rights Reserved.

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
//#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>

GLfloat alpha = 0.0, theta = 0.0, axis_x = 0.0, axis_y = 0.0, Calpha = 360.0, C_hr_alpha = 360.0;
GLboolean bRotate = false, fRotate = true, cRotate = true, xz_rotate = false, l_on = true;
const int width = 600;
const int height = 800;

/// Scaling Factor
GLfloat scale_factor_x = 1.0;
GLfloat scale_factor_y = 1.0;
GLfloat scale_factor_z = 1.0;

/// Translation
GLfloat translate_x = 0.0;
GLfloat translate_y = 0.0;
GLfloat translate_z = 0.0;

/// Rotation
GLfloat rotate_x = 0.0;
GLfloat rotate_y = 0.0;
GLfloat rotate_z = 0.0;

bool l_on1 = true;
bool l_on2 = true;
bool l_on3 = false;

double spt_cutoff = 40;

float rot = 0;

GLfloat eyeX = 0;
GLfloat eyeY = 10;
GLfloat eyeZ = 10;

GLfloat lookX = 0;
GLfloat lookY = 10;
GLfloat lookZ = 0;

static GLfloat v_Cube[8][3] =
{
    {0,0,0},
    {0,0,1},
    {0,1,0},
    {0,1,1},

    {1,0,0},
    {1,0,1},
    {1,1,0},
    {1,1,1}
};

static GLubyte quadIndices[6][4] =
{
    {0,2,6,4},
    {1,5,7,3},
    {0,4,5,1},
    {2,3,7,6},
    {0,1,3,2},
    {4,6,7,5}
};

void cube(GLfloat colr1, GLfloat colr2, GLfloat colr3)
{
    glColor3f(colr1, colr2, colr3);
    glBegin(GL_QUADS);
    for (GLint i = 0; i < 6; i++)
    {
        for (GLint j = 0; j < 4; j++)
        {
            glVertex3fv(&v_Cube[quadIndices[i][j]][0]);
        }
    }
    glEnd();
}

void teacher()
{
    float length = 0.5;
    float height = 3;
    float width = 0.5;

    glPushMatrix();
    glTranslatef(length / 2 + translate_x, translate_y, translate_z);
    glRotatef(rotate_x, 1, 0, 0);
    glRotatef(rotate_y, 0, 1, 0);
    glRotatef(rotate_z, 0, 0, 1);
    glScalef(scale_factor_x, scale_factor_y, scale_factor_z);
    glScalef(length, height, width);
    glTranslatef(0, 0, 0);
    cube(0.0, 0.0, 0.0); // 1st right leg for the desk
    glPopMatrix();

    glPushMatrix();
    glTranslatef(length / 2 + translate_x, translate_y, translate_z);
    glRotatef(rotate_x, 1, 0, 0);
    glRotatef(rotate_y, 0, 1, 0);
    glRotatef(rotate_z, 0, 0, 1);
    glScalef(scale_factor_x, scale_factor_y, scale_factor_z);
    glScalef(length, height, width);
    glTranslatef(4, 0, 0);
    cube(0.0, 0.0, 0.0); // 1st left leg for desk
    glPopMatrix();

    glPushMatrix();
    glTranslatef(length / 2 + translate_x, translate_y, translate_z);
    glRotatef(rotate_x, 1, 0, 0);
    glRotatef(rotate_y, 0, 1, 0);
    glRotatef(rotate_z, 0, 0, 1);
    glScalef(scale_factor_x, scale_factor_y, scale_factor_z);
    glScalef(length, height, width);
    glTranslatef(0, 0, 3);
    cube(0.0, 0.0, 0.0); // 2nd right leg for desk
    glPopMatrix();

    glPushMatrix();
    glTranslatef(length / 2 + translate_x, translate_y, translate_z);
    glRotatef(rotate_x, 1, 0, 0);
    glRotatef(rotate_y, 0, 1, 0);
    glRotatef(rotate_z, 0, 0, 1);
    glScalef(scale_factor_x, scale_factor_y, scale_factor_z);
    glScalef(length, height, width);
    glTranslatef(4, 0, 3);
    cube(0.0, 0.0, 0.0); // 2nd left leg for desk
    glPopMatrix();

    glPushMatrix();
    glTranslatef(length / 2 + translate_x, translate_y, translate_z);
    glRotatef(rotate_x, 1, 0, 0);
    glRotatef(rotate_y, 0, 1, 0);
    glRotatef(rotate_z, 0, 0, 1);
    glScalef(scale_factor_x, scale_factor_y, scale_factor_z);
    glScalef(length * 6, height / 6, width * 5);
    glTranslatef(0, 6, 0);
    cube(1, 0.8, 0.4);  // top of the desk
    glPopMatrix();
}

void table()
{
    float length = 0.5;
    float height = 3;
    float width = 0.5;

    glPushMatrix();
 //   glTranslatef(length / 2, 0, 0);
    glScalef(length, height, width);
    glTranslatef(0, 0, 0);
    cube(0.0, 0.0, 0.0); // 1st right leg for the desk
    glPopMatrix();

    glPushMatrix();
//    glTranslatef(length / 2, 0, 0);
    glScalef(length, height, width);
    glTranslatef(4, 0, 0);
    cube(0.0, 0.0, 0.0); // 1st left leg for the desk
    glPopMatrix();

    glPushMatrix();
 //   glTranslatef(length / 2, 0, 0);
    glScalef(length, height, width);
    glTranslatef(0, 0, 3);
    cube(0.0, 0.0, 0.0); // 2nd right leg for the desk
    glPopMatrix();

    glPushMatrix();
  //  glTranslatef(length / 2, 0, 0);
    glScalef(length, height, width);
    glTranslatef(4, 0, 3);
    cube(0.0, 0.0, 0.0); // 2nd left leg for the desk
    glPopMatrix();

    glPushMatrix();
    glScalef(length * 6, height / 6, width * 5);
    glTranslatef(0, 6, 0);
    cube(1, 0.8, 0.4); // top of table
    glPopMatrix();
}

void chair()
{
    float length = 0.5;
    float height = 2;
    float width = 0.5;

    glPushMatrix();
    //glTranslatef(length / 2, 0, 0);
    glScalef(length, height, width);
    glTranslatef(0.5, 0, -2);
    cube(0.0, 0.0, 0.0); // 1st right leg for chair
    glPopMatrix();

    glPushMatrix();
    glTranslatef(length / 2, 0, 0);
    glScalef(length, height, width);
    glTranslatef(3.5, 0, -2);
    cube(0.0, 0.0, 0.0); // 1st left leg for chair
    glPopMatrix();

    glPushMatrix();
   // glTranslatef(length / 2, 0, 0);
    glScalef(length, height, width);
    glTranslatef(0.5, 0, -4);
    cube(0.0, 0.0, 0.0); // 2nd right leg for chair
    glPopMatrix();

    glPushMatrix();
   // glTranslatef(length / 2, 0, 0);
    glScalef(length, height, width);
    glTranslatef(3.5, 0, -4);
    cube(0.0, 0.0, 0.0); // 2nd left leg for chair
    glPopMatrix();

    glPushMatrix();
    //glTranslatef(length / 2, 0, 0);
    glScalef(length * 4, height / 6, width * 4);
    glTranslatef(0.15, 6, -1.2);
    cube(1, 0.8, 0.4); // Seat for chair
    glPopMatrix();

    glPushMatrix();
    //glTranslatef(length / 2, 0, 0);
    glScalef(length * 4, height * 1.2, width);
    glTranslatef(0.15, 1, -5);
    cube(1, 0.8, 0.4); // Back support for the chair
    glPopMatrix();
}

void full_set()
{
    glPushMatrix();
    table();
    glPopMatrix();

    glPushMatrix();
    chair();
    glPopMatrix();
}

void full_set_chair_table()
{
    glPushMatrix();
    full_set();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,0,0);
    full_set();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5, 0, 0);
    full_set();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,0,0);
    full_set();
    glPopMatrix();




    glPushMatrix();
    glTranslatef(0, 0, -6);
    full_set();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,0,-6);
    full_set();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5, 0, -6);
    full_set();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,0,-6);
    full_set();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.5, 2, 1);
    glTranslatef(1, 0, 6);
    teacher();
    glPopMatrix();
}

void board()
{
    glPushMatrix();
    glScalef(10, 8, 0.1);
    glTranslatef(-1.2, 0.45, 130);
    cube(0.0, 0.0, 0.0); // Black color for the board
    glPopMatrix();
}


void fan_face()
{
    glPushMatrix();
    glScalef(2,.5,1.8);
    glTranslatef(-0.4,19,-.4);
    cube(1.000, 1.000, 1.000);
    glPopMatrix();


}
void stand()
{
    glPushMatrix();
    glScalef(.5,5,.5);
    glTranslatef(0,2,0);
    cube(0.392, 0.584, 0.929);
    glPopMatrix();
}

void leg()
{
    glPushMatrix();
    glScalef(5,0.07,1.8);
    glTranslatef(0,140,-0.3);
    cube(0.392, 0.584, 0.929);
    glPopMatrix();
}


void fan_set()
{
    glPushMatrix();
    glPushMatrix();
    fan_face();
    glPopMatrix();



    glPushMatrix();
    leg();
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-5,0.0,0);
    leg();
    glPopMatrix();


    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(-6,0,0);
    leg();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(0,0,0);
    leg();
    glPopMatrix();
}

void fan()
{


    glPushMatrix();
    glRotatef(alpha,0,.1,0);
    fan_set();
    glPopMatrix();

    glPushMatrix();
    stand();
    glPopMatrix();

}
void fan_full_set()
{
    glPushMatrix();
    glTranslatef(7,0,0);
    fan();
    glPopMatrix();

}


///Floor Ceiling
void floorWallsCeiling(float scale)
{
    glPushMatrix(); ///floor
    glScalef(scale, 1, scale);
    glTranslatef(-0.5, -1, -0.5);
    cube(0.8, 0.8, 0.8);
    glPopMatrix();

    glPushMatrix(); ///right wall
    glTranslatef(scale / 2, scale / 4,1.0);
    glScalef(1,scale/2,scale);
    glTranslatef(-1,-0.5,-0.5);
    cube(0.871, 0.722, 0.529);
    glPopMatrix();

    glPushMatrix();///left wall
    glTranslatef(-scale/2+1,scale/4,0);
    glScalef(1,scale/2,scale);
    glTranslatef(-1,-0.5,-0.5);
    cube(0.871, 0.722, 0.529);
    glPopMatrix();


    glPushMatrix();///font wall(board)
    glTranslatef(0,scale/4,scale/2);
    glScalef(scale,scale/2,1);
    glTranslatef(-0.5,-0.5,-1);
    cube(1.000, 0.855, 0.725);
    glPopMatrix();

    glPushMatrix();///back wall
    glTranslatef(0,scale/4,scale/2);
    glScalef(scale,scale/2,1);
    glTranslatef(-0.5,-0.5,-31);
    cube(1.000, 0.855, 0.725);
    glPopMatrix();


    glPushMatrix();///celing
    glTranslatef(0,scale/2,0);
    glScalef(scale,1,scale);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.8, 0.8, 0.8);
    glPopMatrix();

   ;
}

///Door
GLfloat rotate_door = 0.0;
void door()
{
     glPushMatrix();
    glScalef(3.8,10,.2);
    glTranslatef(2.3,0,-75);
    cube(0, 0, 0);
    glPopMatrix();

    glPushMatrix();
    glScalef(3.8,10,.19);
    glTranslatef(2.2,0,-75);
     glRotatef(rotate_door, 0, 1, 0); // Rotate around y-axis
    cube(.8, .7, .5);
    glPopMatrix();

    glPushMatrix();
    glScalef(.3,1,.2);
    glTranslatef(28,4.5,-73);
     glRotatef(rotate_door, 0, 1, 0); // Rotate around y-axis
    cube(0, 0, 0);
    glPopMatrix();
}

void window()
{
    glPushMatrix();
    glScalef(0.1,10,10);
    glTranslatef(-140,.3,-.5);
    cube(.5, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.1,10,.1);
    glTranslatef(-139,.3,0);
    cube(0, 0, 0);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.1,0.1,10);
    glTranslatef(-139,75,-.5);
    cube(0, 0, 0);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.1,0.1,10);
    glTranslatef(-139,130,-.5);
    cube(0, 0, 0);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.1,0.1,10);
    glTranslatef(-139,30,-.5);
    cube(0, 0, 0);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.1,10,.1);
    glTranslatef(-139,.3,-50);
    cube(0, 0, 0);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.1,10,.1);
    glTranslatef(-139,.3,50);
    cube(0, 0, 0);
    glPopMatrix();



}
void windows()
{
    glPushMatrix();
    window();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180,0,1,0);
    window();
    glPopMatrix();
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-3, 3, -3, 3, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, 0,1,0);


    glRotatef(rot, 0,1,0);
    full_set_chair_table();
    floorWallsCeiling(30);
    board();
    fan();
    glFlush();
    door();
    windows();
    glutSwapBuffers();
}

void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {

    case 'r':  // Rotate Camera view Right to Left
        rot++;
        break;

    case 'R':  // Rotate Camera View Left to Right
        rot--;
        break;

    case 'u': // Camera View Up
        eyeY++;
        break;

    case 'U': // Camera view Down
        eyeY--;
        break;

    case '-': // Zoom Out
        eyeX=0;
        eyeZ++;
        lookZ++;
        break;

    case '+': // Zoom In
        eyeZ--;
        break;

    case 'x': // Increase x-axis scale
            scale_factor_x += 0.1;
            break;
    case 'X': // Decrease x-axis scale
            scale_factor_x -= 0.1;
            break;
    case 'y': // Increase y-axis scale
            scale_factor_y += 0.1;
            break;
    case 'Y': // Decrease y-axis scale
            scale_factor_y -= 0.1;
            break;
    case 'z': // Increase z-axis scale
            scale_factor_z += 0.1;
            break;
    case 'Z': // Decrease z-axis scale
            scale_factor_z -= 0.1;
            break;


    case '4': // Translate along the positive x-axis
        translate_x += 0.1;
        break;
    case '5': // Translate along the negative x-axis
        translate_x -= 0.1;
        break;
    case '6': // Translate along the positive y-axis
        translate_y += 0.1;
        break;
    case '7': // Translate along the negative y-axis
        translate_y -= 0.1;
        break;
    case '8': // Translate along the positive z-axis
        translate_z += 0.1;
        break;
    case '9': // Translate along the negative z-axis
        translate_z -= 0.1;
        break;


    case 'F':
        fRotate = !fRotate;
        axis_x=0.0;
        axis_y=1.0;
        break;

    case 'a': // Rotate around x-axis positive
        rotate_x += 5.0;
        break;
    case 's': // Rotate around x-axis negative
        rotate_x -= 5.0;
        break;
    case 'd': // Rotate around y-axis positive
        rotate_y += 5.0;
        break;
    case 'f': // Rotate around y-axis negative
        rotate_y -= 5.0;
        break;
    case 'g': // Rotate around z-axis positive
        rotate_z += 5.0;
        break;
    case 'h': // Rotate around z-axis negative
        rotate_z -= 5.0;
        break;
    case 'o': // Open door
        rotate_door += 180.0;
        break;

    }
}


void animate()
{
    if (bRotate == true)
    {
        theta += 0.1;
        if(theta > 360.0)
            theta -= 360.0*floor(theta/360.0);
    }


    if (fRotate == true)
    {
        alpha += 0.8;
        if(alpha > 360.0)
            alpha -= 360.0*floor(alpha/360.0);
    }

    glutPostRedisplay();

}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Classroom");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboardFunc);
    glutIdleFunc(display);
    glutIdleFunc(animate);

    printf("\nCamera View: \n");
    printf("Use 'r' for Rotate Camera view Right to Left\n");
    printf("Use 'R' for Rotate Camera view Left to Right\n");
    printf("Use 'u' for Camera View Up\n");
    printf("Use 'U' for Camera View down\n");
    printf("Use '+' to zoom in \n");
    printf("Use '-' to zoom out.\n");

    printf("\nScaling Teacher Desk: \n");
    printf("Use 'x' for Increase Teacher Desk about x-axis scale\n");
    printf("Use 'X' for decrease Teacher Desk about x-axis scale\n");
    printf("Use 'y' for increase Teacher Desk about y-axis scale\n");
    printf("Use 'Y' for decrease Teacher Desk about y-axis scale\n");
    printf("Use 'z' for increase Teacher Desk about z-axis scale\n");
    printf("Use 'Z' for decrease Teacher Desk about z-axis scale\n");

    printf("\nTranslation Teacher Desk: \n");
    printf("Use '4' for Translate along the (+ve) x-axis\n");
    printf("Use '5' for Translate along the (-ve) x-axis\n");
    printf("Use '6' for Translate along the (+ve) y-axis\n");
    printf("Use '7' for Translate along the (-ve) y-axis\n");
    printf("Use '8' for Translate along the (+ve) z-axis\n");
    printf("Use '9' for Translate along the (-ve) z-axis\n");

    printf("\nRotation Teacher Desk : \n");
    printf("Use 'a' for Rotating around x-axis positive\n");
    printf("Use 's' for Rotating around x-axis negative\n");
    printf("Use 'd' for Rotating around y-axis positive\n");
    printf("Use 'f' for Rotating around y-axis negative\n");
    printf("Use 'g' for Rotating around z-axis positive\n");
    printf("Use 'h' for Rotating around Z-axis positive\n");

    printf("\nAnimation : \n");
    printf("Use 'F' to rotate the fan and Stop fan. \n");

    printf("\nKeybord Control : \n");
    printf("Use 'o' to Open and Close Door. \n");
    printf("\nCopyright © 2024 moonaz023. All Rights Reserved. \n");


    glutMainLoop();
    return 0;
}
