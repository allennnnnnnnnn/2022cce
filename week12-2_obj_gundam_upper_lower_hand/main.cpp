#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

///�W�g�����L, �ХΰŶK��
#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel = NULL;
GLMmodel * hande1 = NULL;
GLMmodel * hande2 = NULL;
GLMmodel * upper = NULL;
GLMmodel * lower = NULL;
void drawhande1(void)
{
    if (!hande1) {
        hande1 = glmReadOBJ("hande1.obj");
        ///�W�g���ҫ���,��b�_�Ǫ��ؿ��� �ୱ\freeglut\bin
        ///���g,�n����n���a��
        if (!hande1) exit(0);
        glmUnitize(hande1);
        glmFacetNormals(hande1);
        glmVertexNormals(hande1, 90.0);
    }

    glmDraw(hande1, GLM_SMOOTH | GLM_TEXTURE);
}
void drawpmodel(void)
{
    if (!pmodel) {
        pmodel = glmReadOBJ("pmodel.obj");
        ///�W�g���ҫ���,��b�_�Ǫ��ؿ��� �ୱ\freeglut\bin
        ///���g,�n����n���a��
        if (!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90.0);
    }

    glmDraw(pmodel, GLM_SMOOTH | GLM_TEXTURE);
}

void drawupper(void)
{
    if (!upper) {
        upper = glmReadOBJ("upper.obj");
        ///�W�g���ҫ���,��b�_�Ǫ��ؿ��� �ୱ\freeglut\bin
        ///���g,�n����n���a��
        if (!upper) exit(0);
        glmUnitize(upper);
        glmFacetNormals(upper);
        glmVertexNormals(upper, 90.0);
    }

    glmDraw(upper, GLM_SMOOTH | GLM_TEXTURE);
}

void drawlower(void)
{
    if (!lower) {
        lower = glmReadOBJ("lower.obj");
        ///�W�g���ҫ���,��b�_�Ǫ��ؿ��� �ୱ\freeglut\bin
        ///���g,�n����n���a��
        if (!lower) exit(0);
        glmUnitize(lower);
        glmFacetNormals(lower);
        glmVertexNormals(lower, 90.0);
    }

    glmDraw(lower, GLM_SMOOTH | GLM_TEXTURE);
}
void drawhande2(void)
{
    if (!hande2) {
        hande2 = glmReadOBJ("hande2.obj");
        ///�W�g���ҫ���,��b�_�Ǫ��ؿ��� �ୱ\freeglut\bin
        ///���g,�n����n���a��
        if (!hande2) exit(0);
        glmUnitize(hande2);
        glmFacetNormals(hande2);
        glmVertexNormals(hande2, 90.0);
    }

    glmDraw(hande2, GLM_SMOOTH | GLM_TEXTURE);
}
float angle=0;
void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutWireCube(0.6);
    glutSolidSphere(0.1,30,30);

    glPushMatrix();
    drawupper();
    glPushMatrix();
        ///glRotatef(angle++,0,1,0);
        glTranslatef(0,-0.1,0);
        glRotatef(angle++,0,0,1);
        glTranslatef(0,-0.2,0);
        drawlower(); ///glutSolidTeapot( 0.3 );
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };

const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };

const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };


const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };

const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };

const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };

const GLfloat high_shininess[] = { 100.0f };


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week12-2_obj_gundam_upper_lower_hand");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    myTexture("Diffuse.jpg");


    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);

    glEnable(GL_NORMALIZE);

    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_LIGHTING);



    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);

    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);

    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);



    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);

    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);

    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);

    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}