#include <GL/glut.h> //O arquivo glut.h inclui, além dos protótipos das funções GLUT, os arquivos gl.h e glu.h,
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int R = 255, G=255, B = 255;
GLfloat dx=0, dy=0.0;

void display(void);
void keyboard(unsigned char key, int x, int y);
void Special_keyboard(GLint tecla, int x, int y);
void DesenhaTexto(char *string);

//Função de tratamento de eventos do teclado com código ASCII
void Teclado(unsigned char tecla, int x, int y){
  switch (tecla) { //quando a tecla ESC (keycode=27) for pressionada
    case 27:       //o programa deverá ser finalizado
         exit(0);
    break;
  }
}

//Função de tratamento de eventos do teclado com código não-ASCII
void TeclasEspeciais(int tecla, int x, int y){
     GLfloat desloc=1;
	 switch (tecla) 		{   //Verifica se alguma tecla é pressionada
		case GLUT_KEY_RIGHT: //Seta direcional direita
		   dx+=desloc;
		   break;

       case GLUT_KEY_LEFT: //seta direcional esquerda
           dx-=desloc;
		   break;
        case GLUT_KEY_UP: //Seta direcional cima
		   dy+=desloc;
		   break;
        case GLUT_KEY_DOWN: //seta direcional baixo
           dy-=desloc;
		   break;
     }
     glutPostRedisplay(); // Chama a função display novamente, fazendo com
     //que a janela corrente seja redesenhada
}

float angle = 0.0f;            // ANgulo em radianos
float raio = 20.5f;           // Raio do trajeto circular
float speed = 0.05f;  
float dx_juba = 0;
float dy_juba = 0;
float dx_asa_dentro = 0;
float dy_asa_dentro = 0;
float raio_juba = 30.5f;
float raio_asa_dentro = 50.0f;


void update(int value) {
    angle += speed;
    if (angle > 2 * M_PI) angle -= 2 * M_PI;

    dx = raio * cos(angle);
    dy = raio * sin(angle);
    dx_juba = raio_juba * cos(angle);
    dy_juba = raio_juba * sin(angle);
    dx_asa_dentro = raio_asa_dentro * cos(angle);
    dy_asa_dentro = raio_asa_dentro * sin(angle);

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // ~60 FPS
}

int main(int argc, char** argv){
  glutInit(&argc, argv); //Estabelece contato com sistema de janelas
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); //Cores dos pixels serão expressos em RGB
  glutInitWindowSize (475*2, 475*2); //Estabelece o tamanho (em pixels) da janela a ser criada
  glutInitWindowPosition (0, 0); //Posição inicial do canto superior esquerdo da janela a ser criada
  glutCreateWindow (argv[0]); //Cria uma nova janela com valor de retorno (não usado)
  // que a identifica, caso tenha mais de uma
  glClearColor(0, 0, 1, 0.0); //selecionar cor de fundo (Branco)
  glOrtho (0, 475, 475, 0, 0, 1); //define as coordenadas do volume de recorte (clipping volume),
  glutDisplayFunc(display); //Função callback chamada para fazer o desenho
  glutTimerFunc(0, update, 0); // Começa a animação
  // glutKeyboardFunc(keyboard); //Chamada sempre que uma tecla for precionada
  glutSpecialFunc(Special_keyboard); // Registra a função para tratamento das teclas NÂO ASCII
  glutKeyboardFunc(Teclado); //Trata eventos de teclado
  glutMainLoop(); //Depois de registradas as callbacks, o controle é entregue ao sistema de janelas
  printf("\nTestando... \n");
  return 0;
}

void orelha_dentro(GLfloat dx, GLfloat dy){
  // INÍCIO DA ORELHA DE DENTRO
  glColor3ub(189, 172, 79);
  glBegin(GL_POLYGON);
  glVertex2f(109.71f+dx, 137.65f+dy);
  glVertex2f(117.13f+dx, 111.63f+dy);
  glVertex2f(145.11+dx, 72.11f+dy);
  glVertex2f(244.69f+dx, 23.94f+dy);
  glVertex2f(217.88f+dx, 68.42f+dy);
  glVertex2f(226.30f+dx, 67.92f+dy);
  glVertex2f(209.83f+dx, 87.98f+dy);
  glVertex2f(155.63f+dx, 126.00f+dy);
  glVertex2f(109.71f+dx, 137.65f+dy);
  glEnd();
}
void canela_fundo(GLfloat dx, GLfloat dy){
  glColor3ub(189, 172, 79);
  glBegin(GL_POLYGON);
  glVertex2f(273.90f+dx, 356.64f+dy);
  glVertex2f(251.35f+dx, 393.55f+dy);
  glVertex2f(251.35f+dx, 393.55f+dy);
  glVertex2f(251.35f+dx, 393.55f+dy);
  glVertex2f(263.78f+dx, 406.93f+dy);
  glVertex2f(263.78f+dx, 406.93f+dy);
  glVertex2f(263.78f+dx, 406.93f+dy);
  glVertex2f(302.69f+dx, 363.69f+dy);
  glVertex2f(302.69f+dx, 363.69f+dy);
  glVertex2f(302.69f+dx, 363.69f+dy);
  glVertex2f(289.70f+dx, 347.38f+dy);
  glVertex2f(289.70f+dx, 347.38f+dy);
  glEnd();
}
void asa_dentro(GLfloat dx, GLfloat dy){
  // INÍCIO DA ASA DE DENTRO
    glColor3ub(189, 172, 79);
    glBegin(GL_POLYGON);
    glVertex2f(164.65f+dx, 232.33f+dy);
    glVertex2f(217.01f+dx, 214.18f+dy);
    glVertex2f(237.15f+dx, 222.81f+dy);
    glVertex2f(261.76f+dx, 219.00f+dy);
    glVertex2f(294.80f+dx, 184.04f+dy);
    glVertex2f(292.43f+dx, 197.13f+dy);
    glVertex2f(327.14f+dx, 169.62f+dy);
    glVertex2f(307.99f+dx, 216.57f+dy);
    glVertex2f(353.22f+dx, 215.92f+dy);
    glVertex2f(338.84f+dx, 238.51f+dy);
    glVertex2f(359.26f+dx, 258.83f+dy);
    glVertex2f(319.31f+dx, 277.35f+dy);
    glVertex2f(299.15f+dx, 289.23f+dy);
    glVertex2f(273.07f+dx, 273.02f+dy);
    glVertex2f(261.52f+dx, 280.53f+dy);
    glVertex2f(164.65f+dx, 232.33f+dy);
    glEnd();
}
void corpo(GLfloat dx, GLfloat dy){
    
    glColor3ub(240, 219, 101);
    glBegin(GL_POLYGON);
    glVertex2f(112.08+dx, 275.49+dy);
    glVertex2f(113.06+dx, 249.84+dy);
    glVertex2f(121.20+dx, 232.84+dy);
    glVertex2f(131.42+dx, 228.61+dy);
    glVertex2f(298.98+dx, 218.12+dy);
    glVertex2f(319.58+dx, 218.43+dy);
    glVertex2f(334.21+dx, 225.60+dy);
    glVertex2f(349.40+dx, 237.09+dy);
    glVertex2f(354.97+dx, 251.58+dy);
    glVertex2f(354.18+dx, 269.90+dy);
    glVertex2f(349.88+dx, 290.62+dy);
    glVertex2f(338.04+dx, 300.30+dy);
    glVertex2f(309.89+dx, 305.47+dy);
    glVertex2f(258.44+dx, 313.29+dy);
    glVertex2f(205.95+dx, 326.66+dy);
    glVertex2f(188.33+dx, 328.14+dy);
    glVertex2f(151.11+dx, 327.06+dy);
    glVertex2f(131.18+dx, 323.98+dy);
    glVertex2f(120.27+dx, 315.67+dy);
    glVertex2f(115.09+dx, 301.94+dy);

    glEnd();
}
void coxa_traseira_fora(GLfloat dx, GLfloat dy) {
    
    glColor3ub(240, 219, 101);
    glBegin(GL_POLYGON); // Inicia o desenho com GL_LINE_STRIP
    // Coordenadas extraídas do caminho SVG
    glVertex2f(266.42f+dx, 311.21f+dy);  // Ponto inicial
    glVertex2f(281.48f+dx, 279.25f+dy);
    glVertex2f(298.57f+dx, 274.25f+dy);
    glVertex2f(326.80f+dx, 271.55f+dy);
    glVertex2f(343.33f+dx, 282.55f+dy);
    glVertex2f(346.45f+dx, 299.24f+dy);
    glVertex2f(350.57f+dx, 347.18f+dy);
    glVertex2f(339.84f+dx, 363.75f+dy);
    glVertex2f(313.93f+dx, 365.24f+dy);
    glVertex2f(302.53f+dx, 360.52f+dy);  // Ponto final

    glEnd();
} 
void orelha_fora(GLfloat dx, GLfloat dy){
  // INÍCIO DA ORELHA DE FORA
  glColor3ub(240, 219, 101);
  glBegin(GL_POLYGON);
  glVertex2f(140.63f+dx, 148.06f+dy);
  glVertex2f(198.32f+dx, 154.81f+dy);
  glVertex2f(190.78f+dx, 150.51f+dy);
  glVertex2f(182.82f+dx, 149.63f+dy);
  glVertex2f(277.70f+dx, 125.10f+dy);
  glVertex2f(264.00f+dx, 122.03f+dy);
  glVertex2f(260.53f+dx, 123.37f+dy);
  glVertex2f(313.58+dx, 68.51f+dy);
  glVertex2f(192.72+dx, 91.89f+dy);
  glVertex2f(166.76f+dx, 109.94f+dy);
  glVertex2f(144.30f+dx, 135.43f+dy);
  glVertex2f(140.63f+dx, 148.06f+dy);

  glEnd();
}
void asa_fora(GLfloat dx, GLfloat dy){
  // INÍCIO DA ASA DE FORA, mesma cor da orelha
    glColor3ub(240, 219, 101);
    glBegin(GL_POLYGON);
    glVertex2f(178.03f+dx, 226.46f+dy);
    glVertex2f(306.48f+dx, 214.74f+dy);
    glVertex2f(388.00f+dx, 174.30f+dy);
    glVertex2f(382.65f+dx, 183.86f+dy);
    glVertex2f(400.57f+dx, 179.65f+dy);
    glVertex2f(353.69f+dx, 227.60f+dy);
    glVertex2f(424.68f+dx, 221.79f+dy);
    glVertex2f(360.17f+dx, 258.23f+dy);
    glVertex2f(399.20f+dx, 275.42f+dy);
    glVertex2f(357.22f+dx, 278.59f+dy);
    glVertex2f(382.45f+dx, 303.88f+dy);
    glVertex2f(367.63f+dx, 300.15f+dy);
    glVertex2f(381.29f+dx, 314.31f+dy);
    glVertex2f(368.85f+dx, 311.59f+dy);
    glVertex2f(383.74f+dx, 325.01f+dy);
    glVertex2f(293.31f+dx, 292.68f+dy);
    glVertex2f(292.93f+dx, 297.36f+dy);
    glVertex2f(282.82f+dx, 292.23f+dy);
    glVertex2f(278.04f+dx, 287.62f+dy);
    glVertex2f(285.26f+dx, 300.74f+dy);
    glEnd();
}
void juba(GLfloat dx, GLfloat dy){
  // JUBA SEMPRE ANTES DA CABEÇA
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON); 
    glVertex2f(75.82f+dx, 317.69f+dy);
    glVertex2f(100.91f+dx, 254.53f+dy);
    glVertex2f(84.04f+dx, 261.88f+dy);
    glVertex2f(98.84f+dx, 241.56f+dy);
    glVertex2f(93.95f+dx, 241.67f+dy);
    glVertex2f(101.73f+dx, 232.46f+dy);
    glVertex2f(71.45f+dx, 236.41f+dy);
    glVertex2f(135.28f+dx, 189.89f+dy);
    glVertex2f(194.25f+dx, 176.17f+dy);
    glVertex2f(211.19f+dx, 168.23f+dy);
    glVertex2f(209.68f+dx, 175.36f+dy);
    glVertex2f(285.97f+dx, 162.77f+dy);
    glVertex2f(243.96f+dx, 191.81f+dy);
    glVertex2f(264.09f+dx, 189.98f+dy);
    glVertex2f(246.91f+dx, 199.98f+dy);
    glVertex2f(303.12f+dx, 214.97f+dy);
    glVertex2f(230.61f+dx, 223.88f+dy);
    glVertex2f(237.30f+dx, 228.30f+dy);
    glVertex2f(223.98f+dx, 232.75f+dy);
    glVertex2f(242.98f+dx, 253.51f+dy);
    glVertex2f(221.36f+dx, 247.56f+dy);
    glVertex2f(253.55f+dx, 295.48f+dy);
    glVertex2f(189.72f+dx, 257.84f+dy);
    glVertex2f(201.58f+dx, 288.62f+dy);
    glVertex2f(192.65f+dx, 281.57f+dy);
    glVertex2f(207.16f+dx, 323.40f+dy);
    glVertex2f(163.61f+dx, 283.97f+dy);
    glVertex2f(163.97f+dx, 303.08f+dy);
    glVertex2f(148.34f+dx, 280.94f+dy);
    glVertex2f(137.15f+dx, 345.97f+dy);
    glVertex2f(116.70f+dx, 271.06f+dy);
    glVertex2f(75.82f+dx, 317.69f+dy);

glEnd();
}
void cabeca(GLfloat dx, GLfloat dy){


    // INÍCIO DA CABEÇA
    glColor3ub(240, 219, 101);
    glBegin(GL_POLYGON);
    glVertex2f(131.07f+dx, 240.69f+dy);
    glVertex2f(116.77f+dx, 225.69f+dy);
    glVertex2f(111.62f+dx, 238.01f+dy);
    glVertex2f(105.78f+dx, 220.61f+dy);
    glVertex2f(87.64f+dx, 214.33f+dy);
    glVertex2f(76.22f+dx, 208.47f+dy);
    glVertex2f(65.04f+dx, 199.33f+dy);
    glVertex2f(59.60f+dx, 187.62f+dy);
    glVertex2f(50.47f+dx, 178.83f+dy);
    glVertex2f(48.00f+dx, 166.21f+dy);
    glVertex2f(55.07f+dx, 159.10f+dy);
    glVertex2f(68.00f+dx, 154.87f+dy);
    glVertex2f(85.71f+dx, 127.44f+dy);
    glVertex2f(94.73f+dx, 124.80f+dy);
    glVertex2f(110.60f+dx, 123.19f+dy);
    glVertex2f(153.46f+dx, 92.86f+dy);
    glVertex2f(142.15f+dx, 113.83f+dy);
    glVertex2f(154.63f+dx, 109.19f+dy);
    glVertex2f(144.57f+dx, 119.67f+dy);
    glVertex2f(154.44f+dx, 119.10f+dy);
    glVertex2f(183.94f+dx, 148.97f+dy);
    glVertex2f(198.41f+dx, 154.28f+dy);
    glVertex2f(157.30f+dx, 151.80f+dy);
    glVertex2f(178.62f+dx, 154.94f+dy);
    glVertex2f(193.63f+dx, 167.90f+dy);
    glVertex2f(183.65f+dx, 169.20f+dy);
    glVertex2f(202.88f+dx, 182.94f+dy);
    glVertex2f(169.24f+dx, 182.41f+dy);
    glVertex2f(179.73f+dx, 184.97f+dy);
    glVertex2f(191.30f+dx, 196.56f+dy);
    glVertex2f(180.94f+dx, 196.31f+dy);
    glVertex2f(195.79f+dx, 204.14f+dy);
    glVertex2f(159.44f+dx, 203.22f+dy);
    glVertex2f(165.76f+dx, 210.26f+dy);
    glVertex2f(152.95f+dx, 205.89f+dy);
    glVertex2f(159.52f+dx, 226.32f+dy);
    glVertex2f(136.37f+dx, 217.78f+dy);
    glVertex2f(141.50f+dx, 225.87f+dy);
    glVertex2f(127.03f+dx, 216.72f+dy);
    glVertex2f(131.07f+dx, 240.69f+dy);
    glEnd();
}
void olho_preto(GLfloat dx, GLfloat dy){
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(88.16+dx, 167.86+dy);  // Ponto inicial
    glVertex2f(99.98+dx, 173.04+dy);
    glVertex2f(109.24+dx, 175.18+dy);
    glVertex2f(114.23+dx, 174.89+dy);
    glVertex2f(119.56+dx, 171.93+dy);
    glVertex2f(124.58+dx, 164.00+dy);
    glVertex2f(128.55+dx, 155.97+dy);
    glVertex2f(128.20+dx, 154.19+dy);
    glVertex2f(124.81+dx, 152.74+dy);
    glVertex2f(118.62+dx, 152.11+dy);
    glVertex2f(112.59+dx, 152.40+dy);
    glVertex2f(105.93+dx, 153.23+dy);
    glVertex2f(100.14+dx, 155.43+dy);
    glVertex2f(95.59+dx, 157.85+dy);
    glVertex2f(92.37+dx, 160.77+dy);
    glEnd();

}
void olho_pupila(GLfloat dx, GLfloat dy){

    glColor3ub(35, 21, 46);
    glBegin(GL_POLYGON);
    // Coordenadas extraídas do caminho SVG
    glVertex2f(104.98+dx, 167.93+dy);  // Ponto inicial
    glVertex2f(104.22+dx, 170.58+dy);
    glVertex2f(105.44+dx, 172.79+dy);
    glVertex2f(107.76+dx, 174.03+dy);
    glVertex2f(111.63+dx, 174.00+dy);
    glVertex2f(115.61+dx, 172.34+dy);
    glVertex2f(117.27+dx, 170.62+dy);
    glVertex2f(117.47+dx, 168.73+dy);
    glVertex2f(114.31+dx, 165.90+dy);
    glVertex2f(111.11+dx, 165.66+dy);  // Ponto final

    glEnd();
}
void olho_brilho(GLfloat dx, GLfloat dy){
    // Coordenadas extraídas do caminho SVG
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2f(99.74+dx, 162.19+dy);  // Ponto inicial
    glVertex2f(100.08+dx, 158.32+dy);
    glVertex2f(103.55+dx, 156.30+dy);
    glVertex2f(108.03+dx, 155.82+dy);
    glVertex2f(109.10+dx, 158.16+dy);
    glVertex2f(103.48+dx, 163.06+dy);  // Ponto final

    glEnd();
}
void canela_traseira_fora(GLfloat dx, GLfloat dy){

  glColor3ub(240, 219, 101);

  glBegin(GL_POLYGON);

    glVertex2f(324.17f+dx, 417.55f+dy);
    glVertex2f(341.32f+dx, 384.91f+dy);
    glVertex2f(369.68f+dx, 383.11f+dy);
    glVertex2f(369.75f+dx, 390.95f+dy);
    glVertex2f(347.44f+dx, 431.16f+dy);

  glEnd();
}
void joelho_traseiro_fora(GLfloat dx, GLfloat dy){
  glColor3ub(240, 219, 101);
  glBegin(GL_POLYGON);

    glVertex2f(313.07f+dx, 365.05f+dy);
    glVertex2f(349.69f+dx, 350.92f+dy);
    glVertex2f(370.19f+dx, 382.81f+dy);
    glVertex2f(341.50f+dx, 385.88f+dy);

    glEnd();
}
void perna_frente_esquerda(GLfloat dx, GLfloat dy){

    glColor3ub(240, 219, 101);
    glBegin(GL_POLYGON);

    glVertex2f(135.22f+dx, 426.29f+dy);
    glVertex2f(162.15f+dx, 436.80f+dy);
    glVertex2f(171.29f+dx, 396.18f+dy);
    glVertex2f(179.92f+dx, 357.85f+dy);
    glVertex2f(189.60f+dx, 326.08f+dy);
    glVertex2f(169.20f+dx, 307.26f+dy);
    glVertex2f(147.56f+dx, 320.78f+dy);
    glVertex2f(137.50f+dx, 422.26f+dy);

    glEnd();
}
void perna_frente_direita(GLfloat dx, GLfloat dy){
    glColor3ub(240, 219, 101);
    glBegin(GL_POLYGON);

    glVertex2f(141.80f+dx, 425.72f+dy);
    glVertex2f(166.31f+dx, 286.58f+dy);
    glVertex2f(143.94f+dx, 269.20f+dy);
    glVertex2f(120.13f+dx, 294.95f+dy);
    glVertex2f(120.56f+dx, 415.26f+dy);

    glEnd();
}
void boca_fora(GLfloat dx, GLfloat dy){
  glLineWidth(3.0f); // Aumenta a grossura da linha
  glColor3ub(0, 0, 0);
  glBegin(GL_LINE_STRIP);
  glVertex2f(99.94f+dx, 194.85f+dy);
  glVertex2f(93.40f+dx, 196.11f+dy);
  glVertex2f(86.38f+dx, 196.53f+dy);
  glVertex2f(78.84f+dx, 195.35f+dy);
  glVertex2f(72.19f+dx, 192.19f+dy);
  glVertex2f(66.91f+dx, 188.44f+dy);
  glVertex2f(62.57f+dx, 184.75f+dy);
  glVertex2f(60.57f+dx, 182.85f+dy);
  glVertex2f(58.93f+dx, 187.64f+dy);
  glEnd();
}
void orelha_parte_dentro_1(GLfloat dx, GLfloat dy){
  glColor3ub(0, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2f(158.40f+dx, 144.07f+dy);
  glVertex2f(229.07f+dx, 131.53f+dy);
  glVertex2f(229.07f+dx, 131.53f+dy);
  glVertex2f(229.07f+dx, 131.53f+dy);
  glVertex2f(286.50f+dx, 80.91f+dy);
  glVertex2f(286.50f+dx, 80.91f+dy);
  glVertex2f(286.50f+dx, 80.91f+dy);
  glVertex2f(235.43f+dx, 89.99f+dy);
  glVertex2f(235.43f+dx, 89.99f+dy);
  glVertex2f(235.43f+dx, 89.99f+dy);
  glVertex2f(205.19f+dx, 99.24f+dy);
  glVertex2f(205.19f+dx, 99.24f+dy);
  glEnd();
}
void orelha_parte_dentro_2(GLfloat dx, GLfloat dy){
  glColor3ub(0, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2f(152.60f+dx, 137.59f+dy);
  glVertex2f(201.58f+dx, 118.55f+dy);
  glVertex2f(201.58f+dx, 118.55f+dy);
  glVertex2f(201.58f+dx, 118.55f+dy);
  glVertex2f(208.34f+dx, 99.17f+dy);
  glVertex2f(208.34f+dx, 99.17f+dy);
  glVertex2f(208.34f+dx, 99.17f+dy);
  glVertex2f(191.15f+dx, 103.78f+dy);
  glVertex2f(191.15f+dx, 103.78f+dy);
  glEnd();


}
void nariz(GLfloat dx, GLfloat dy){
  glColor3ub(0, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2f(50.75f+dx, 168.66f+dy);
  glVertex2f(54.66f+dx, 171.93f+dy);
  glVertex2f(59.00f+dx, 169.57f+dy);
  glVertex2f(56.56f+dx, 167.32f+dy);
  glVertex2f(53.19f+dx, 166.98f+dy);
  glEnd();
}
void coxa_fundo(GLfloat dx, GLfloat dy){

  glColor3ub(189, 172, 79);
  glBegin(GL_POLYGON);
  glVertex2f(255.86f+dx, 313.21f+dy);
  glVertex2f(290.98f+dx, 279.27f+dy);
  glVertex2f(290.98f+dx, 279.27f+dy);
  glVertex2f(290.98f+dx, 279.27f+dy);
  glVertex2f(317.26f+dx, 319.24f+dy);
  glVertex2f(317.26f+dx, 319.24f+dy);
  glVertex2f(317.26f+dx, 319.24f+dy);
  glVertex2f(306.55f+dx, 361.73f+dy);
  glVertex2f(306.55f+dx, 361.73f+dy);
  glVertex2f(306.55f+dx, 361.73f+dy);
  glVertex2f(272.73f+dx, 359.47f+dy);
  glVertex2f(272.73f+dx, 359.47f+dy);
  glEnd();
}
void pata_traseira_1(GLfloat dx, GLfloat dy){
glColor3ub(240, 219, 101);
glBegin(GL_POLYGON);
glVertex2f(354.61f+dx, 414.95f+dy);
glVertex2f(331.31f+dx, 409.66f+dy);
glVertex2f(331.31f+dx, 409.66f+dy);
glVertex2f(331.31f+dx, 409.66f+dy);
glVertex2f(305.69f+dx, 426.12f+dy);
glVertex2f(305.69f+dx, 426.12f+dy);
glVertex2f(305.69f+dx, 426.12f+dy);
glVertex2f(303.96f+dx, 432.17f+dy);
glVertex2f(303.96f+dx, 432.17f+dy);
glVertex2f(303.96f+dx, 432.17f+dy);
glVertex2f(305.15f+dx, 437.79f+dy);
glVertex2f(305.15f+dx, 437.79f+dy);
glVertex2f(305.15f+dx, 437.79f+dy);
glVertex2f(308.32f+dx, 441.67f+dy);
glVertex2f(308.32f+dx, 441.67f+dy);
glVertex2f(308.32f+dx, 441.67f+dy);
glVertex2f(312.59f+dx, 445.00f+dy);
glVertex2f(312.59f+dx, 445.00f+dy);
glVertex2f(312.59f+dx, 445.00f+dy);
glVertex2f(318.15f+dx, 445.48f+dy);
glVertex2f(318.15f+dx, 445.48f+dy);
glVertex2f(318.15f+dx, 445.48f+dy);
glVertex2f(330.47f+dx, 443.00f+dy);
glVertex2f(330.47f+dx, 443.00f+dy);
glVertex2f(330.47f+dx, 443.00f+dy);
glVertex2f(342.54f+dx, 435.39f+dy);
glVertex2f(342.54f+dx, 435.39f+dy);
glVertex2f(342.54f+dx, 435.39f+dy);
glVertex2f(355.13f+dx, 415.50f+dy);
glVertex2f(355.13f+dx, 415.50f+dy);
glEnd();
}
void pata_traseira_2(GLfloat dx, GLfloat dy){
  glColor3ub(189, 172, 79);
  glBegin(GL_POLYGON);
  glVertex2f(253.51f+dx, 389.78f+dy);
  glVertex2f(232.28f+dx, 394.47f+dy);
  glVertex2f(232.28f+dx, 394.47f+dy);
  glVertex2f(232.28f+dx, 394.47f+dy);
  glVertex2f(230.65f+dx, 402.42f+dy);
  glVertex2f(230.65f+dx, 402.42f+dy);
  glVertex2f(230.65f+dx, 402.42f+dy);
  glVertex2f(231.31f+dx, 407.04f+dy);
  glVertex2f(231.31f+dx, 407.04f+dy);
  glVertex2f(231.31f+dx, 407.04f+dy);
  glVertex2f(234.84f+dx, 411.53f+dy);
  glVertex2f(234.84f+dx, 411.53f+dy);
  glVertex2f(234.84f+dx, 411.53f+dy);
  glVertex2f(240.03f+dx, 412.02f+dy);
  glVertex2f(240.03f+dx, 412.02f+dy);
  glVertex2f(240.03f+dx, 412.02f+dy);
  glVertex2f(254.25f+dx, 410.81f+dy);
  glVertex2f(254.25f+dx, 410.81f+dy);
  glVertex2f(254.25f+dx, 410.81f+dy);
  glVertex2f(269.34f+dx, 405.69f+dy);
  glVertex2f(269.34f+dx, 405.69f+dy);
  glEnd();

}
void pata_frente_1(GLfloat dx, GLfloat dy){
  glColor3ub(240, 219, 101);
  glBegin(GL_POLYGON);
  glVertex2f(136.08f+dx, 421.63f+dy);
  glVertex2f(125.97f+dx, 434.56f+dy);
  glVertex2f(125.97f+dx, 434.56f+dy);
  glVertex2f(125.97f+dx, 434.56f+dy);
  glVertex2f(126.60f+dx, 440.95f+dy);
  glVertex2f(126.60f+dx, 440.95f+dy);
  glVertex2f(126.60f+dx, 440.95f+dy);
  glVertex2f(132.05f+dx, 448.05f+dy);
  glVertex2f(132.05f+dx, 448.05f+dy);
  glVertex2f(132.05f+dx, 448.05f+dy);
  glVertex2f(141.94f+dx, 452.87f+dy);
  glVertex2f(141.94f+dx, 452.87f+dy);
  glVertex2f(141.94f+dx, 452.87f+dy);
  glVertex2f(154.02f+dx, 448.03f+dy);
  glVertex2f(154.02f+dx, 448.03f+dy);
  glVertex2f(154.02f+dx, 448.03f+dy);
  glVertex2f(164.90f+dx, 435.63f+dy);
  glVertex2f(164.90f+dx, 435.63f+dy);
  glVertex2f(164.90f+dx, 435.63f+dy);
  glVertex2f(164.71f+dx, 425.34f+dy);
  glVertex2f(164.71f+dx, 425.34f+dy);
  glVertex2f(164.71f+dx, 425.34f+dy);
  glVertex2f(153.58f+dx, 407.03f+dy);
  glVertex2f(153.58f+dx, 407.03f+dy);
  glEnd();

}
void pata_frente_2(GLfloat dx, GLfloat dy){
  glColor3ub(240, 219, 101);
  glBegin(GL_POLYGON);
  glVertex2f(124.58f+dx, 442.24f+dy);
  glVertex2f(117.01f+dx, 440.98f+dy);
  glVertex2f(117.01f+dx, 440.98f+dy);
  glVertex2f(117.01f+dx, 440.98f+dy);
  glVertex2f(112.01f+dx, 437.49f+dy);
  glVertex2f(112.01f+dx, 437.49f+dy);
  glVertex2f(112.01f+dx, 437.49f+dy);
  glVertex2f(110.22f+dx, 430.42f+dy);
  glVertex2f(110.22f+dx, 430.42f+dy);
  glVertex2f(110.22f+dx, 430.42f+dy);
  glVertex2f(116.38f+dx, 421.18f+dy);
  glVertex2f(116.38f+dx, 421.18f+dy);
  glVertex2f(116.38f+dx, 421.18f+dy);
  glVertex2f(124.64f+dx, 414.89f+dy);
  glVertex2f(124.64f+dx, 414.89f+dy);
  glVertex2f(124.64f+dx, 414.89f+dy);
  glVertex2f(135.70f+dx, 413.47f+dy);
  glVertex2f(135.70f+dx, 413.47f+dy);
  glVertex2f(135.70f+dx, 413.47f+dy);
  glVertex2f(136.50f+dx, 423.04f+dy);
  glVertex2f(136.50f+dx, 423.04f+dy);
  glEnd();
}
void detalhe_orelha(GLfloat dx, GLfloat dy){
  glColor3ub(35, 21, 46);
  glBegin(GL_POLYGON);
  glVertex2f(171.70f+dx, 139.94f+dy);
  glVertex2f(177.20f+dx, 128.30f+dy);
  glVertex2f(177.20f+dx, 128.30f+dy);
  glVertex2f(177.20f+dx, 128.30f+dy);
  glVertex2f(199.80f+dx, 113.75f+dy);
  glVertex2f(199.80f+dx, 113.75f+dy);
  glVertex2f(199.80f+dx, 113.75f+dy);
  glVertex2f(251.88f+dx, 100.68f+dy);
  glVertex2f(251.88f+dx, 100.68f+dy);
  glVertex2f(251.88f+dx, 100.68f+dy);
  glVertex2f(227.69f+dx, 116.04f+dy);
  glVertex2f(227.69f+dx, 116.04f+dy);
  glVertex2f(227.69f+dx, 116.04f+dy);
  glVertex2f(240.79f+dx, 114.41f+dy);
  glVertex2f(240.79f+dx, 114.41f+dy);
  glVertex2f(240.79f+dx, 114.41f+dy);
  glVertex2f(217.41f+dx, 130.62f+dy);
  glVertex2f(217.41f+dx, 130.62f+dy);
  glEnd();
}
void juba_cinza(GLfloat dx, GLfloat dy){
  glColor3ub(212, 212,212);
  glBegin(GL_POLYGON);
  glVertex2f(111.44f+dx, 214.05f+dy);
  glVertex2f(113.99f+dx, 247.34f+dy);
  glVertex2f(113.99f+dx, 247.34f+dy);
  glVertex2f(113.99f+dx, 247.34f+dy);
  glVertex2f(118.78f+dx, 243.52f+dy);
  glVertex2f(118.78f+dx, 243.52f+dy);
  glVertex2f(118.78f+dx, 243.52f+dy);
  glVertex2f(124.37f+dx, 265.60f+dy);
  glVertex2f(124.37f+dx, 265.60f+dy);
  glVertex2f(124.37f+dx, 265.60f+dy);
  glVertex2f(128.55f+dx, 256.79f+dy);
  glVertex2f(128.55f+dx, 256.79f+dy);
  glVertex2f(128.55f+dx, 256.79f+dy);
  glVertex2f(131.90f+dx, 259.85f+dy);
  glVertex2f(131.90f+dx, 259.85f+dy);
  glVertex2f(131.90f+dx, 259.85f+dy);
  glVertex2f(133.52f+dx, 243.41f+dy);
  glVertex2f(133.52f+dx, 243.41f+dy);
  glVertex2f(133.52f+dx, 243.41f+dy);
  glVertex2f(140.48f+dx, 260.45f+dy);
  glVertex2f(140.48f+dx, 260.45f+dy);
  glVertex2f(140.48f+dx, 260.45f+dy);
  glVertex2f(146.60f+dx, 248.33f+dy);
  glVertex2f(146.60f+dx, 248.33f+dy);
  glVertex2f(146.60f+dx, 248.33f+dy);
  glVertex2f(157.74f+dx, 267.76f+dy);
  glVertex2f(157.74f+dx, 267.76f+dy);
  glVertex2f(157.74f+dx, 267.76f+dy);
  glVertex2f(158.83f+dx, 261.76f+dy);
  glVertex2f(158.83f+dx, 261.76f+dy);
  glVertex2f(158.83f+dx, 261.76f+dy);
  glVertex2f(171.04f+dx, 273.18f+dy);
  glVertex2f(171.04f+dx, 273.18f+dy);
  glVertex2f(171.04f+dx, 273.18f+dy);
  glVertex2f(166.27f+dx, 250.06f+dy);
  glVertex2f(166.27f+dx, 250.06f+dy);
  glVertex2f(166.27f+dx, 250.06f+dy);
  glVertex2f(173.86f+dx, 257.26f+dy);
  glVertex2f(173.86f+dx, 257.26f+dy);
  glVertex2f(173.86f+dx, 257.26f+dy);
  glVertex2f(174.81f+dx, 253.09f+dy);
  glVertex2f(174.81f+dx, 253.09f+dy);
  glVertex2f(174.81f+dx, 253.09f+dy);
  glVertex2f(177.50f+dx, 254.07f+dy);
  glVertex2f(177.50f+dx, 254.07f+dy);
  glVertex2f(177.50f+dx, 254.07f+dy);
  glVertex2f(178.25f+dx, 249.98f+dy);
  glVertex2f(178.25f+dx, 249.98f+dy);
  glVertex2f(178.25f+dx, 249.98f+dy);
  glVertex2f(180.37f+dx, 250.99f+dy);
  glVertex2f(180.37f+dx, 250.99f+dy);
  glVertex2f(180.37f+dx, 250.99f+dy);
  glVertex2f(181.66f+dx, 245.96f+dy);
  glVertex2f(181.66f+dx, 245.96f+dy);
  glVertex2f(181.66f+dx, 245.96f+dy);
  glVertex2f(201.48f+dx, 252.03f+dy);
  glVertex2f(201.48f+dx, 252.03f+dy);
  glVertex2f(201.48f+dx, 252.03f+dy);
  glVertex2f(191.33f+dx, 235.45f+dy);
  glVertex2f(191.33f+dx, 235.45f+dy);
  glVertex2f(191.33f+dx, 235.45f+dy);
  glVertex2f(189.92f+dx, 225.21f+dy);
  glVertex2f(189.92f+dx, 225.21f+dy);
  glVertex2f(189.92f+dx, 225.21f+dy);
  glVertex2f(197.41f+dx, 227.22f+dy);
  glVertex2f(197.41f+dx, 227.22f+dy);
  glVertex2f(197.41f+dx, 227.22f+dy);
  glVertex2f(210.50f+dx, 231.35f+dy);
  glVertex2f(210.50f+dx, 231.35f+dy);
  glVertex2f(210.50f+dx, 231.35f+dy);
  glVertex2f(203.17f+dx, 223.05f+dy);
  glVertex2f(203.17f+dx, 223.05f+dy);
  glVertex2f(203.17f+dx, 223.05f+dy);
  glVertex2f(199.19f+dx, 216.31f+dy);
  glVertex2f(199.19f+dx, 216.31f+dy);
  glVertex2f(199.19f+dx, 216.31f+dy);
  glVertex2f(202.49f+dx, 216.79f+dy);
  glVertex2f(202.49f+dx, 216.79f+dy);
  glVertex2f(202.49f+dx, 216.79f+dy);
  glVertex2f(196.13f+dx, 210.07f+dy);
  glVertex2f(196.13f+dx, 210.07f+dy);
  glVertex2f(196.13f+dx, 210.07f+dy);
  glVertex2f(205.20f+dx, 211.06f+dy);
  glVertex2f(205.20f+dx, 211.06f+dy);
  glVertex2f(205.20f+dx, 211.06f+dy);
  glVertex2f(214.28f+dx, 209.97f+dy);
  glVertex2f(214.28f+dx, 209.97f+dy);
  glVertex2f(214.28f+dx, 209.97f+dy);
  glVertex2f(201.07f+dx, 201.14f+dy);
  glVertex2f(201.07f+dx, 201.14f+dy);
  glVertex2f(201.07f+dx, 201.14f+dy);
  glVertex2f(211.10f+dx, 202.84f+dy);
  glVertex2f(211.10f+dx, 202.84f+dy);
  glVertex2f(211.10f+dx, 202.84f+dy);
  glVertex2f(216.66f+dx, 201.33f+dy);
  glVertex2f(216.66f+dx, 201.33f+dy);
  glVertex2f(216.66f+dx, 201.33f+dy);
  glVertex2f(224.35f+dx, 201.79f+dy);
  glVertex2f(224.35f+dx, 201.79f+dy);
  glVertex2f(224.35f+dx, 201.79f+dy);
  glVertex2f(217.30f+dx, 198.95f+dy);
  glVertex2f(217.30f+dx, 198.95f+dy);
  glVertex2f(217.30f+dx, 198.95f+dy);
  glVertex2f(205.72f+dx, 188.72f+dy);
  glVertex2f(205.72f+dx, 188.72f+dy);
  glVertex2f(205.72f+dx, 188.72f+dy);
  glVertex2f(217.31f+dx, 186.85f+dy);
  glVertex2f(217.31f+dx, 186.85f+dy);
  glVertex2f(217.31f+dx, 186.85f+dy);
  glVertex2f(198.03f+dx, 179.19f+dy);
  glVertex2f(198.03f+dx, 179.19f+dy);
  glVertex2f(198.03f+dx, 179.19f+dy);
  glVertex2f(173.46f+dx, 181.45f+dy);
  glVertex2f(173.46f+dx, 181.45f+dy);
  glVertex2f(173.46f+dx, 181.45f+dy);
  glVertex2f(153.27f+dx, 182.54f+dy);
  glVertex2f(153.27f+dx, 182.54f+dy);
  glVertex2f(153.27f+dx, 182.54f+dy);
  glVertex2f(137.55f+dx, 191.04f+dy);
  glVertex2f(137.55f+dx, 191.04f+dy);
  glVertex2f(137.55f+dx, 191.04f+dy);
  glVertex2f(114.31f+dx, 211.84f+dy);
  glVertex2f(114.31f+dx, 211.84f+dy);
  glEnd();

}

float scale = 1.0f; // Current zoom level

void display(void){
  glClear(GL_COLOR_BUFFER_BIT); ////Limpa a janela de visualização com a cor de fundo especificada
  DesenhaTexto("Exemplo de texto para a atividade 2");
  //glBegin(GL_POINTS);
  //glBegin(GL_LINES);
  //glBegin(GL_LINE_STRIP);
  //glBegin(GL_QUADS);
  //glBegin(GL_QUAD_STRIP);
  //glBegin(GL_TRIANGLES);
  //glBegin(GL_TRIANGLE_STRIP);
  //glBegin(GL_TRIANGLE_FAN);

  glPushMatrix();
  glTranslatef(219.58+dx, 218.43+dy, 0); 
  glScalef(scale, scale, 1.0f);
  glTranslatef(-219.58+dx, -218.43+dy, 0); // Ajusta a escala pro centro do pokemon 
  asa_dentro(dx_asa_dentro, dy_asa_dentro);
  corpo(dx, dy);
  coxa_fundo(dx, dy);
  canela_fundo(dx, dy);
  pata_traseira_1(dx, dy);
  pata_frente_1(dx, dy);
  pata_traseira_2(dx, dy);
  pata_frente_2(dx, dy);
  coxa_traseira_fora(dx, dy);
  canela_traseira_fora(dx, dy);
  joelho_traseiro_fora(dx, dy);
  perna_frente_esquerda(dx, dy);
  perna_frente_direita(dx, dy);
  orelha_dentro(dx, dy);
  orelha_fora(dx, dy);
  asa_fora(dx_juba, dy_juba);
  juba(dx_juba, dy_juba);
  juba_cinza(dx_juba, dy_juba);
  cabeca(dx, dy);
  boca_fora(dx, dy);
  nariz(dx, dy);
  orelha_parte_dentro_1(dx, dy);
  orelha_parte_dentro_2(dx, dy);
  detalhe_orelha(dx, dy);
  olho_preto(dx, dy);
  olho_pupila(dx, dy);
  olho_brilho(dx, dy);

  glPopMatrix();
  glutSwapBuffers();
  glFlush(); ////Executa os comandos OpenGL para renderização
}

void keyboard(unsigned char key, int x, int y){
  printf("*** Tratamento de teclas comuns\n");
	printf(">>> Tecla pressionada: %c\n",key);
  switch (key) {
    case 27: exit(0); // ESC
    case 32: R = 0; G += 50; B = 0; glutPostRedisplay(); break;
  }
}

void Special_keyboard(GLint tecla, int x, int y) {
  switch (tecla) { // GLUT_KEY_RIGHT GLUT_KEY_DOWN GLUT_KEY_PAGE_UP GLUT_KEY_PAGE_DOWN GLUT_KEY_F1...
    case GLUT_KEY_F12: R = 0; G = 200; B = 200; glutPostRedisplay(); break;
    case GLUT_KEY_F10: R = 0; G = 100; B = 200; glutPostRedisplay(); break;
    case GLUT_KEY_PAGE_UP:
            scale += 0.05f; // Zoom in
            if (scale > 3.0f) scale = 3.0f;
            break;
        case GLUT_KEY_PAGE_DOWN:
            scale -= 0.05f; // Zoom out
            if (scale < 0.1f) scale = 0.1f;
            break;
  }
  glutPostRedisplay(); // Redraw with new scale

}

void DesenhaTexto(char *string) {
  	glColor3ub(150,200,250);
  	glPushMatrix();
        // Posição no universo onde o texto será colocado
        glRasterPos2f(-0.4,-0.4);
        // Exibe caracter a caracter
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++);
	glPopMatrix();
	glColor3ub(255,255,255);
}