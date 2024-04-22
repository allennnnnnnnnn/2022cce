#include <GL/glut.h>
void myBody(){
    glColor3f(1,0,0);
    glutWireCube(0.6);
}

    void myArm(){
        glColor3f(0,1,0);
        glScalef(1.5,0.5,0.5);
        glutWireCube(0.3);
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     glPushMatrix();

         myBody();

        glPopMatrix();

     glPushMatrix();

         glRotatef(angle++,0,0,1);
         glTranslatef(0.225,0,0);
         myArm();
        glutWireCube( 0.3 );
        glPopMatrix();
        glutSwapBuffers();
}




int main(int argc, char* argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week09-1 obj gundam opencv texture lighting");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();


}
