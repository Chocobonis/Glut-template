#include<GL/glut.h>
#include<iostream>
#include<unistd.h>
#include<math.h>

void display();
void glIni();
void standf();

int main(int argc, char **argv){
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
 glutInitWindowSize(480,480);
 glutCreateWindow("Template");
 glClearDepth(1.0f);
 glDepthFunc(GL_LEQUAL);
 glIni();
 glutIgnoreKeyRepeat(1);
 glutDisplayFunc(display);
 glutIdleFunc(standf);
 glutMainLoop();
 return 0;
}


void standf(){usleep(33);glutPostRedisplay();}

void glIni(){
 glClearColor(0.0,0.0,0.0,0.0);
 glEnable(GL_DEPTH_TEST);
 glEnable(GL_TEXTURE_2D);
 glEnable(GL_BLEND);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluPerspective(60, 1,1,2000);
}

void display(){
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 gluLookAt(2,1,2, 0,0,0, 0,1,0);

  glPushMatrix();
   glColor3f(1,1,1);
   glutWireCube(1);
  glPopMatrix();

 glFlush();
 glutSwapBuffers();
}
  
