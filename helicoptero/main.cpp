#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

GLfloat tranx, trany = 0;
GLfloat escala=1;
GLfloat girar=1;
void init()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,800,0,600);
    glMatrixMode(GL_MODELVIEW);
}

void janela(int x, int y)
{
    float th;
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<360;i++)
    {
        th=i*3.142/180;
        glVertex2f(x+20*cos(th),y+20*sin(th));
    }
    glEnd();
}

void helicoptero()
{
    glPushMatrix();
    glTranslatef(tranx, trany, 0);
    glScalef(escala, escala, 0);
    glRotated(girar, girar, girar, girar);
    //HELICE ESQUERDA
    glBegin(GL_LINE_LOOP);
    glVertex2f(265,485);
    glVertex2f(400,460);
    glEnd();

    //HELICE DIREITA
    glBegin(GL_LINE_LOOP);
    glVertex2f(535,485);
    glVertex2f(400,460);
    glEnd();

    //HELICE BAIXO
    glBegin(GL_LINE_LOOP);
    glVertex2f(400,430);
    glVertex2f(400,460);
    glEnd();

    //CORPO
    glBegin(GL_LINE_LOOP);
    glVertex2f(300,430);
    glVertex2f(480,430);
    glVertex2f(530,390);
    glVertex2f(530,330);
    glVertex2f(300,330);
    glEnd();

    //JANELA
    glBegin(GL_LINE_LOOP);
    glVertex2f(530,390);
    glVertex2f(480,390);
    glVertex2f(480,430);
    glEnd();

    //PORTA
    glBegin(GL_LINE_LOOP);
    glVertex2f(420,410);
    glVertex2f(420,330);
    glVertex2f(460,330);
    glVertex2f(460,410);
    glEnd();

    //APOIO1
    glBegin(GL_LINE_LOOP);
    glVertex2f(530,300);
    glVertex2f(300,300);
    glEnd();

    //APOIO2
    glBegin(GL_LINE_LOOP);
    glVertex2f(340,330);
    glVertex2f(340,300);
    glEnd();

    //APOIO2
    glBegin(GL_LINE_LOOP);
    glVertex2f(340,330);
    glVertex2f(340,300);
    glEnd();

    //APOIO3
    glBegin(GL_LINE_LOOP);
    glVertex2f(480,330);
    glVertex2f(480,300);
    glEnd();

    //APOIO4
    glBegin(GL_LINE_LOOP);
    glVertex2f(530,300);
    glVertex2f(560,315);
    glEnd();

    //APOIO5
    glBegin(GL_LINE_LOOP);
    glVertex2f(300,300);
    glVertex2f(270,315);
    glEnd();

    //SLA
    glBegin(GL_LINE_LOOP);
    glVertex2f(300,400);
    glVertex2f(200,400);
    glEnd();

    //SLA2
    glBegin(GL_LINE_LOOP);
    glVertex2f(300,380);
    glVertex2f(200,380);
    glEnd();

    //SLA3
    glBegin(GL_LINE_LOOP);
    glVertex2f(200,400);
    glVertex2f(180,430);
    glEnd();

    //SLA4
    glBegin(GL_LINE_LOOP);
    glVertex2f(180,430);
    glVertex2f(180,380);
    glEnd();

    //SLA5
    glBegin(GL_LINE_LOOP);
    glVertex2f(180,380);
    glVertex2f(200,380);
    glEnd();

    //JANELA PASSAGEIRO
    janela(330,400);
    janela(380,400);

    glPopMatrix();
}

void teclado(unsigned char tecla, GLint x, GLint y){
switch(tecla){
case 'w' : trany+=10;
break;
case 's' : trany-=10;
break;
case 'a' : tranx-=10;
break;
case 'd' : tranx+=10;
break;
case '=' : escala+=0.01;
break;
case '-' : escala-=0.01;
break;
case 'q' : girar++;
break;
case 'e' : girar--;
break;
}
glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    helicoptero();
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,500);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB| GLUT_SINGLE);
    glutCreateWindow("Helicoptero");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(teclado);
    display();
    glutIdleFunc(helicoptero);
    glutMainLoop();
    return 0;
}
