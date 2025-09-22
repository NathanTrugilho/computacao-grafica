// Baseado em:
//
// Iluminacao.c - Isabel H. Manssour
// Um programa OpenGL que exemplifica a visualização 
// de objetos 3D com a inserção de uma fonte de luz.
// Este código está baseado nos exemplos disponíveis no livro 
// "OpenGL SuperBible", 2nd Edition, de Richard S. e Wright Jr.

//gcc cubo.c -o cubo -lfreeglut -lopengl32 -lglu32
//gcc cubo.c -o cubo -lglut -lGL -lGLU -lm

#include <GL/glut.h>
#include <math.h>
#define PI 3.14159265

GLfloat angle, fAspect, rotX, rotY;

            
// Função callback chamada para fazer o desenho
void Desenha(void)
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Boto a normal de todos pra frente e faço as rotações e translações necessárias
	glPushMatrix();
		glColor3f(1.0f, 0.0f, 0.0f); // RED
		glTranslatef(0,0,20);
		glRotatef(0,0,1,0);
		glNormal3f(0,0,1);
		glBegin(GL_QUADS);
			glVertex3f(-20.0f, -20.0f, 0.0f); // Vértice 1
			glVertex3f( 20.0f, -20.0f, 0.0f); // Vértice 2
			glVertex3f( 20.0f,  20.0f, 0.0f); // Vértice 3
			glVertex3f(-20.0f,  20.0f, 0.0f); // Vértice 4
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.0f, 1.0f, 0.0f); // GREEN
		glTranslatef(0,0,-20);
		glRotatef(180,0,1,0);
		glNormal3f(0,0,1);
		glBegin(GL_QUADS);
			glVertex3f(-20.0f, -20.0f, 0.0f); // Vértice 1
			glVertex3f( 20.0f, -20.0f, 0.0f); // Vértice 2
			glVertex3f( 20.0f,  20.0f, 0.0f); // Vértice 3
			glVertex3f(-20.0f,  20.0f, 0.0f); // Vértice 4
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.0f, 0.0f, 1.0f); // BLUE
		glTranslatef(20,0,0);
		glRotatef(90,0,1,0);
		glNormal3f(0,0,1);
		glBegin(GL_QUADS);
			glVertex3f(-20.0f, -20.0f, 0.0f); // Vértice 1
			glVertex3f( 20.0f, -20.0f, 0.0f); // Vértice 2
			glVertex3f( 20.0f,  20.0f, 0.0f); // Vértice 3
			glVertex3f(-20.0f,  20.0f, 0.0f); // Vértice 4
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glColor3f(1.0f, 1.0f, 0.0f); // AMARELO
		glTranslatef(-20,0,0);
		glRotatef(270,0,1,0);
		glNormal3f(0,0,1);
		glBegin(GL_QUADS);
			glVertex3f(-20.0f, -20.0f, 0.0f); // Vértice 1
			glVertex3f( 20.0f, -20.0f, 0.0f); // Vértice 2
			glVertex3f( 20.0f,  20.0f, 0.0f); // Vértice 3
			glVertex3f(-20.0f,  20.0f, 0.0f); // Vértice 4
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.0f, 1.0f, 1.0f); // CYAN
		glTranslatef(0,20,0);
		glRotatef(270,1,0,0);
		glNormal3f(0,0,1);
		glBegin(GL_QUADS);
			glVertex3f(-20.0f, -20.0f, 0.0f); // Vértice 1
			glVertex3f( 20.0f, -20.0f, 0.0f); // Vértice 2
			glVertex3f( 20.0f,  20.0f, 0.0f); // Vértice 3
			glVertex3f(-20.0f,  20.0f, 0.0f); // Vértice 4
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glColor3f(1.0f, 0.0f, 1.0f); // ROXO
		glTranslatef(0,-20,0);
		glRotatef(90,1,0,0);
		glNormal3f(0,0,1);
		glBegin(GL_QUADS);
			glVertex3f(-20.0f, -20.0f, 0.0f); // Vértice 1
			glVertex3f( 20.0f, -20.0f, 0.0f); // Vértice 2
			glVertex3f( 20.0f,  20.0f, 0.0f); // Vértice 3
			glVertex3f(-20.0f,  20.0f, 0.0f); // Vértice 4
		glEnd();
	glPopMatrix();

	glutSwapBuffers();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{ 
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0}; 
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};		 // "cor" 
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho" 
	GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
	GLint especMaterial = 60;

 	// Especifica que a cor de fundo da janela será preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material 
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);  
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

    angle=45;
	rotY=0;
	rotX=0;
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
    	gluPerspective(angle,fAspect,0.4,500);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	float radY = rotY * PI / 180.0;  // longitude
	float radX = rotX * PI / 180.0;  // latitude

	float raio = 200;
	float camX = raio * cos(radX) * sin(radY);
	float camY = raio * sin(radX);
	float camZ = raio * cos(radX) * cos(radY);

	gluLookAt(camX, camY, camZ, 0, 0, 0, 0, 1, 0);

	// Especifica posição do observador e do alvo
    	//gluLookAt(rot,80,200, 0,0,0, 0,1,0);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
    glViewport(0, 0, w, h);
 
	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {   
				rotY += 10;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {   
			rotX += 10;
		}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

// Programa Principal
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400,350);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	Inicializa();
	glutMainLoop();
}

