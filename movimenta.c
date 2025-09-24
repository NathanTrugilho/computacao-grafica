// Baseado em:
//
// Iluminacao.c - Isabel H. Manssour
// Exemplo adaptado para câmera com movimentação e rotação matricial
//
// gcc movimenta.c -o movimenta -lfreeglut -lopengl32 -lglu32
// gcc movimenta.c -o movimenta -lglut -lGL -lGLU -lm

#include <GL/glut.h>
#include <math.h>
#define PI 3.14159265

GLfloat fAspect;
GLfloat camX = 0.0f, camY = 0.0f, camZ = 100.0f;
GLfloat focX, focY, focZ;
GLfloat dirX = 0.0f, dirY = 0.0f, dirZ = -1.0f; // direção inicial
GLfloat passo = 2.0f, angulo = 3.0f;

// Desenho dos objetos
void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glRotatef(angulo, 0.0f, 1.0f, 0.0f);
    
    glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f); // RED
	glTranslatef(0,0,20);
	glNormal3f(0,0,1);
	glBegin(GL_QUADS);
		glVertex3f(-20.0f, -20.0f, 0.0f);
		glVertex3f( 20.0f, -20.0f, 0.0f);
		glVertex3f( 20.0f,  20.0f, 0.0f);
		glVertex3f(-20.0f,  20.0f, 0.0f);
	glEnd();
    glPopMatrix();
	
    glPushMatrix();
	glColor3f(0.0f, 1.0f, 0.0f); // GREEN
	glTranslatef(0,0,-20);  
	glRotatef(180,0,1,0);
	glNormal3f(0,0,1);
	glBegin(GL_QUADS);
		glVertex3f(-20.0f, -20.0f, 0.0f);
		glVertex3f( 20.0f, -20.0f, 0.0f);
		glVertex3f( 20.0f,  20.0f, 0.0f);
		glVertex3f(-20.0f,  20.0f, 0.0f);
	glEnd();
    glPopMatrix();
	
    glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f); // BLUE
	glTranslatef(20,0,0);
	glRotatef(90,0,1,0);
	glNormal3f(0,0,1);
	glBegin(GL_QUADS);
		glVertex3f(-20.0f, -20.0f, 0.0f);
		glVertex3f( 20.0f, -20.0f, 0.0f);
		glVertex3f( 20.0f,  20.0f, 0.0f);
		glVertex3f(-20.0f,  20.0f, 0.0f);
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f); // YELLOW
	glTranslatef(-20,0,0);
	glRotatef(270,0,1,0);
	glNormal3f(0,0,1);
	glBegin(GL_QUADS);
		glVertex3f(-20.0f, -20.0f, 0.0f);
		glVertex3f( 20.0f, -20.0f, 0.0f);
		glVertex3f( 20.0f,  20.0f, 0.0f);
		glVertex3f(-20.0f,  20.0f, 0.0f);
	glEnd();
    glPopMatrix();
	
    glPushMatrix();
	glColor3f(0.0f, 1.0f, 1.0f); // CYAN
	glTranslatef(0,20,0);
	glRotatef(270,1,0,0);
	glNormal3f(0,0,1);
	glBegin(GL_QUADS);
		glVertex3f(-20.0f, -20.0f, 0.0f);
		glVertex3f( 20.0f, -20.0f, 0.0f);
		glVertex3f( 20.0f,  20.0f, 0.0f);
		glVertex3f(-20.0f,  20.0f, 0.0f);
	glEnd();
    glPopMatrix();
	
    glPushMatrix();
	glColor3f(1.0f, 0.0f, 1.0f); // MAGENTA
	glTranslatef(0,-20,0);
	glRotatef(90,1,0,0);
	glNormal3f(0,0,1);
	glBegin(GL_QUADS);
		glVertex3f(-20.0f, -20.0f, 0.0f);
		glVertex3f( 20.0f, -20.0f, 0.0f);
		glVertex3f( 20.0f,  20.0f, 0.0f);
		glVertex3f(-20.0f,  20.0f, 0.0f);
	glEnd();
	glPopMatrix();

	glutSwapBuffers();
}

void AtualizaFoco() {
	focX = camX + dirX;
	focY = camY + dirY;
	focZ = camZ + dirZ;
}

// Inicialização
void Inicializa(void)
{ 
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0}; 
    GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};		 
    GLfloat luzEspecular[4]={1.0,1.0,1.0,1.0};
    GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};

    GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
    GLint especMaterial = 60;

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glShadeModel(GL_SMOOTH);

    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);  
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    AtualizaFoco();
}

// Define volume de visualização
void EspecificaParametrosVisualizacao(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,fAspect,0.4,500);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camX, camY, camZ, focX, focY, focZ, 0,1,0);
}

// Redimensionamento
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    fAspect = (GLfloat)w/(GLfloat)h;
    EspecificaParametrosVisualizacao();
}

void RotacionaY(float ang) {
    float rad = ang * PI / 180.0f;
    float cosA = cos(rad);
    float sinA = sin(rad);
	
    float nx = dirX * cosA + dirZ * sinA;
    float nz = -dirX * sinA + dirZ * cosA;

    dirX = nx;
    dirZ = nz;
}

// Teclado normal
void GerenciaTeclado(unsigned char tecla, int x, int y)
{
    switch(tecla) {
        case 'w': case 'W':
            camX += passo * dirX;
            camZ += passo * dirZ;
            break;
        case 's': case 'S':
            camX -= passo * dirX;
            camZ -= passo * dirZ;
            break;
		case 'd': case 'D':
            camX -= passo * dirZ;
            camZ += passo * dirX;
            break;
		case 'a': case 'A':
            camX += passo * dirZ;
            camZ -= passo * dirX;
            break;
        case 'e': case 'E': //sobe
            camY += passo;  
            break;
		case 'q': case 'Q': //desce
            camY -= passo;
            break;
    }
    AtualizaFoco();
    EspecificaParametrosVisualizacao();
    glutPostRedisplay();
}

void GerenciaTeclasEspeciais(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) {
        RotacionaY(5.0f);
    } else if (key == GLUT_KEY_RIGHT) {
        RotacionaY(-5.0f);
    }
    AtualizaFoco();
    EspecificaParametrosVisualizacao();
    glutPostRedisplay();
}

// Timer
void Timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(16, Timer, 1); 
}

// Programa principal
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400,350);
    glutCreateWindow("Visualizacao 3D");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutKeyboardFunc(GerenciaTeclado);
    glutSpecialFunc(GerenciaTeclasEspeciais);
    Inicializa();
    glutTimerFunc(60, Timer, 1);
    glutMainLoop();
}
