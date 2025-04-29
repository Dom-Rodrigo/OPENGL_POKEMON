#include <GL/glut.h> //O arquivo glut.h inclui, além dos protótipos das funções GLUT, os arquivos gl.h e glu.h,
#include <stdlib.h>
#include <stdio.h>

int R = 255, G=255, B = 255;

void display(void);
void keyboard(unsigned char key, int x, int y);
void Special_keyboard(GLint tecla, int x, int y);
void DesenhaTexto(char *string);

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
  glutKeyboardFunc(keyboard); //Chamada sempre que uma tecla for precionada
  glutSpecialFunc(Special_keyboard); // Registra a função para tratamento das teclas NÂO ASCII
  glutMainLoop(); //Depois de registradas as callbacks, o controle é entregue ao sistema de janelas
  printf("\nTestando... \n");
  return 0;
}

void orelha_dentro(){
  // INÍCIO DA ORELHA DE DENTRO
  glColor3ub(189, 172, 79);
  glBegin(GL_POLYGON);
  glVertex2f(109.71f, 137.65f);
  glVertex2f(117.13f, 111.63f);
  glVertex2f(145.11f, 72.11f);
  glVertex2f(244.69f, 23.94f);
  glVertex2f(217.88f, 68.42f);
  glVertex2f(226.30f, 67.92f);
  glVertex2f(209.83f, 87.98f);
  glVertex2f(155.63f, 126.00f);
  glVertex2f(109.71f, 137.65f);
  glEnd();
}
void canela_fundo(){
  glColor3ub(189, 172, 79);
  glBegin(GL_POLYGON);
  glVertex2f(273.90f, 356.64f);
  glVertex2f(251.35f, 393.55f);
  glVertex2f(251.35f, 393.55f);
  glVertex2f(251.35f, 393.55f);
  glVertex2f(263.78f, 406.93f);
  glVertex2f(263.78f, 406.93f);
  glVertex2f(263.78f, 406.93f);
  glVertex2f(302.69f, 363.69f);
  glVertex2f(302.69f, 363.69f);
  glVertex2f(302.69f, 363.69f);
  glVertex2f(289.70f, 347.38f);
  glVertex2f(289.70f, 347.38f);
  glEnd();
}
void asa_dentro(){
  // INÍCIO DA ASA DE DENTRO
    glColor3ub(189, 172, 79);
    glBegin(GL_POLYGON);
    glVertex2f(164.65f, 232.33f);
    glVertex2f(217.01f, 214.18f);
    glVertex2f(237.15f, 222.81f);
    glVertex2f(261.76f, 219.00f);
    glVertex2f(294.80f, 184.04f);
    glVertex2f(292.43f, 197.13f);
    glVertex2f(327.14f, 169.62f);
    glVertex2f(307.99f, 216.57f);
    glVertex2f(353.22f, 215.92f);
    glVertex2f(338.84f, 238.51f);
    glVertex2f(359.26f, 258.83f);
    glVertex2f(319.31f, 277.35f);
    glVertex2f(299.15f, 289.23f);
    glVertex2f(273.07f, 273.02f);
    glVertex2f(261.52f, 280.53f);
    glVertex2f(164.65f, 232.33f);
    glEnd();
}
void corpo(){
    
    glColor3ub(240, 219, 101);
    glBegin(GL_POLYGON);
    glVertex2f(112.08, 275.49);  
    glVertex2f(113.06, 249.84);
    glVertex2f(121.20, 232.84);
    glVertex2f(131.42, 228.61);
    glVertex2f(298.98, 218.12);
    glVertex2f(319.58, 218.43);
    glVertex2f(334.21, 225.60);
    glVertex2f(349.40, 237.09);
    glVertex2f(354.97, 251.58);
    glVertex2f(354.18, 269.90);
    glVertex2f(349.88, 290.62);
    glVertex2f(338.04, 300.30);
    glVertex2f(309.89, 305.47);
    glVertex2f(258.44, 313.29);
    glVertex2f(205.95, 326.66);
    glVertex2f(188.33, 328.14);
    glVertex2f(151.11, 327.06);
    glVertex2f(131.18, 323.98);
    glVertex2f(120.27, 315.67);
    glVertex2f(115.09, 301.94);  

    glEnd();
}
void coxa_traseira_fora() {
    
    glColor3ub(240, 219, 101);
    glBegin(GL_POLYGON); // Inicia o desenho com GL_LINE_STRIP
    // Coordenadas extraídas do caminho SVG
    glVertex2f(266.42, 311.21);  // Ponto inicial
    glVertex2f(281.48, 279.25);
    glVertex2f(298.57, 274.25);
    glVertex2f(326.80, 271.55);
    glVertex2f(343.33, 282.55);
    glVertex2f(346.45, 299.24);
    glVertex2f(350.57, 347.18);
    glVertex2f(339.84, 363.75);
    glVertex2f(313.93, 365.24);
    glVertex2f(302.53, 360.52);  // Ponto final

    glEnd();
} 
void orelha_fora(){
  // INÍCIO DA ORELHA DE FORA
  glColor3ub(240, 219, 101);
  glBegin(GL_POLYGON);
  glVertex2f(140.63f, 148.06f);
  glVertex2f(198.32f, 154.81f);
  glVertex2f(190.78f, 150.51f);
  glVertex2f(182.82f, 149.63f);
  glVertex2f(277.70f, 125.10f);
  glVertex2f(264.00f, 122.03f);
  glVertex2f(260.53f, 123.37f);
  glVertex2f(313.58f, 68.51f);
  glVertex2f(192.72f, 91.89f);
  glVertex2f(166.76f, 109.94f);
  glVertex2f(144.30f, 135.43f);
  glVertex2f(140.63f, 148.06f);

  glEnd();
}
void asa_fora(){
  // INÍCIO DA ASA DE FORA, mesma cor da orelha
    glColor3ub(240, 219, 101);
    glBegin(GL_POLYGON);
    glVertex2f(178.03f, 226.46f);
    glVertex2f(306.48f, 214.74f);
    glVertex2f(388.00f, 174.30f);
    glVertex2f(382.65f, 183.86f);
    glVertex2f(400.57f, 179.65f);
    glVertex2f(353.69f, 227.60f);
    glVertex2f(424.68f, 221.79f);
    glVertex2f(360.17f, 258.23f);
    glVertex2f(399.20f, 275.42f);
    glVertex2f(357.22f, 278.59f);
    glVertex2f(382.45f, 303.88f);
    glVertex2f(367.63f, 300.15f);
    glVertex2f(381.29f, 314.31f);
    glVertex2f(368.85f, 311.59f);
    glVertex2f(383.74f, 325.01f);
    glVertex2f(293.31f, 292.68f);
    glVertex2f(292.93f, 297.36f);
    glVertex2f(282.82f, 292.23f);
    glVertex2f(278.04f, 287.62f);
    glVertex2f(285.26f, 300.74f);
    glEnd();
}
void juba(){
  // JUBA SEMPRE ANTES DA CABEÇA
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON); 
    glVertex2f(75.82f, 317.69f);
    glVertex2f(100.91f, 254.53f);
    glVertex2f(84.04f, 261.88f);
    glVertex2f(98.84f, 241.56f);
    glVertex2f(93.95f, 241.67f);
    glVertex2f(101.73f, 232.46f);
    glVertex2f(71.45f, 236.41f);
    glVertex2f(135.28f, 189.89f);
    glVertex2f(194.25f, 176.17f);
    glVertex2f(211.19f, 168.23f);
    glVertex2f(209.68f, 175.36f);
    glVertex2f(285.97f, 162.77f);
    glVertex2f(243.96f, 191.81f);
    glVertex2f(264.09f, 189.98f);
    glVertex2f(246.91f, 199.98f);
    glVertex2f(303.12f, 214.97f);
    glVertex2f(230.61f, 223.88f);
    glVertex2f(237.30f, 228.30f);
    glVertex2f(223.98f, 232.75f);
    glVertex2f(242.98f, 253.51f);
    glVertex2f(221.36f, 247.56f);
    glVertex2f(253.55f, 295.48f);
    glVertex2f(189.72f, 257.84f);
    glVertex2f(201.58f, 288.62f);
    glVertex2f(192.65f, 281.57f);
    glVertex2f(207.16f, 323.40f);
    glVertex2f(163.61f, 283.97f);
    glVertex2f(163.97f, 303.08f);
    glVertex2f(148.34f, 280.94f);
    glVertex2f(137.15f, 345.97f);
    glVertex2f(116.70f, 271.06f);
    glVertex2f(75.82f, 317.69f);

glEnd();
}
void cabeca(){


    // INÍCIO DA CABEÇA
    glColor3ub(240, 219, 101);
    glBegin(GL_POLYGON);
    glVertex2f(131.07f, 240.69f);
    glVertex2f(116.77f, 225.69f);
    glVertex2f(111.62f, 238.01f);
    glVertex2f(105.78f, 220.61f);
    glVertex2f(87.64f, 214.33f);
    glVertex2f(76.22f, 208.47f);
    glVertex2f(65.04f, 199.33f);
    glVertex2f(59.60f, 187.62f);
    glVertex2f(50.47f, 178.83f);
    glVertex2f(48.00f, 166.21f);
    glVertex2f(55.07f, 159.10f);
    glVertex2f(68.00f, 154.87f);
    glVertex2f(85.71f, 127.44f);
    glVertex2f(94.73f, 124.80f);
    glVertex2f(110.60f, 123.19f);
    glVertex2f(153.46f, 92.86f);
    glVertex2f(142.15f, 113.83f);
    glVertex2f(154.63f, 109.19f);
    glVertex2f(144.57f, 119.67f);
    glVertex2f(154.44f, 119.10f);
    glVertex2f(183.94f, 148.97f);
    glVertex2f(198.41f, 154.28f);
    glVertex2f(157.30f, 151.80f);
    glVertex2f(178.62f, 154.94f);
    glVertex2f(193.63f, 167.90f);
    glVertex2f(183.65f, 169.20f);
    glVertex2f(202.88f, 182.94f);
    glVertex2f(169.24f, 182.41f);
    glVertex2f(179.73f, 184.97f);
    glVertex2f(191.30f, 196.56f);
    glVertex2f(180.94f, 196.31f);
    glVertex2f(195.79f, 204.14f);
    glVertex2f(159.44f, 203.22f);
    glVertex2f(165.76f, 210.26f);
    glVertex2f(152.95f, 205.89f);
    glVertex2f(159.52f, 226.32f);
    glVertex2f(136.37f, 217.78f);
    glVertex2f(141.50f, 225.87f);
    glVertex2f(127.03f, 216.72f);
    glVertex2f(131.07f, 240.69f);
    glEnd();
}
void olho_preto(){
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(88.16, 167.86);  // Ponto inicial
    glVertex2f(99.98, 173.04);
    glVertex2f(109.24, 175.18);
    glVertex2f(114.23, 174.89);
    glVertex2f(119.56, 171.93);
    glVertex2f(124.58, 164.00);
    glVertex2f(128.55, 155.97);
    glVertex2f(128.20, 154.19);
    glVertex2f(124.81, 152.74);
    glVertex2f(118.62, 152.11);
    glVertex2f(112.59, 152.40);
    glVertex2f(105.93, 153.23);
    glVertex2f(100.14, 155.43);
    glVertex2f(95.59, 157.85);
    glVertex2f(92.37, 160.77);
    glEnd();

}
void olho_pupila(){

    glColor3ub(35, 21, 46);
    glBegin(GL_POLYGON);
    // Coordenadas extraídas do caminho SVG
    glVertex2f(104.98, 167.93);  // Ponto inicial
    glVertex2f(104.22, 170.58);
    glVertex2f(105.44, 172.79);
    glVertex2f(107.76, 174.03);
    glVertex2f(111.63, 174.00);
    glVertex2f(115.61, 172.34);
    glVertex2f(117.27, 170.62);
    glVertex2f(117.47, 168.73);
    glVertex2f(114.31, 165.90);
    glVertex2f(111.11, 165.66);  // Ponto final

    glEnd();
}
void olho_brilho(){
    // Coordenadas extraídas do caminho SVG
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2f(99.74, 162.19);  // Ponto inicial
    glVertex2f(100.08, 158.32);
    glVertex2f(103.55, 156.30);
    glVertex2f(108.03, 155.82);
    glVertex2f(109.10, 158.16);
    glVertex2f(103.48, 163.06);  // Ponto final

    glEnd();
}
void canela_traseira_fora(){

  glColor3ub(240, 219, 101);

  glBegin(GL_POLYGON);

    glVertex2f(324.17f, 417.55f);
    glVertex2f(341.32f, 384.91f);
    glVertex2f(369.68f, 383.11f);
    glVertex2f(369.75f, 390.95f);
    glVertex2f(347.44f, 431.16f);

  glEnd();
}
void joelho_traseiro_fora(){
  glColor3ub(240, 219, 101);
  glBegin(GL_POLYGON);

    glVertex2f(313.07f, 365.05f);
    glVertex2f(349.69f, 350.92f);
    glVertex2f(370.19f, 382.81f);
    glVertex2f(341.50f, 385.88f);

    glEnd();
}
void perna_frente_esquerda(){

    glColor3ub(240, 219, 101);
    glBegin(GL_POLYGON);

    glVertex2f(135.22f, 426.29f);
    glVertex2f(162.15f, 436.80f);
    glVertex2f(171.29f, 396.18f);
    glVertex2f(179.92f, 357.85f);
    glVertex2f(189.60f, 326.08f);
    glVertex2f(169.20f, 307.26f);
    glVertex2f(147.56f, 320.78f);
    glVertex2f(137.50f, 422.26f);

    glEnd();
}
void perna_frente_direita(){
    glColor3ub(240, 219, 101);
    glBegin(GL_POLYGON);

    glVertex2f(141.80f, 425.72f);
    glVertex2f(166.31f, 286.58f);
    glVertex2f(143.94f, 269.20f);
    glVertex2f(120.13f, 294.95f);
    glVertex2f(120.56f, 415.26f);

    glEnd();
}
void boca_fora(){
  glLineWidth(3.0f); // Aumenta a grossura da linha
  glColor3ub(0, 0, 0);
  glBegin(GL_LINE_STRIP);
  glVertex2f(99.94f, 194.85f);
  glVertex2f(93.40f, 196.11f);
  glVertex2f(86.38f, 196.53f);
  glVertex2f(78.84f, 195.35f);
  glVertex2f(72.19f, 192.19f);
  glVertex2f(66.91f, 188.44f);
  glVertex2f(62.57f, 184.75f);
  glVertex2f(60.57f, 182.85f);
  glVertex2f(58.93f, 187.64f);
  glEnd();
}
void orelha_parte_dentro_1(){
  glColor3ub(0, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2f(158.40f, 144.07f);
  glVertex2f(229.07f, 131.53f);
  glVertex2f(229.07f, 131.53f);
  glVertex2f(229.07f, 131.53f);
  glVertex2f(286.50f, 80.91f);
  glVertex2f(286.50f, 80.91f);
  glVertex2f(286.50f, 80.91f);
  glVertex2f(235.43f, 89.99f);
  glVertex2f(235.43f, 89.99f);
  glVertex2f(235.43f, 89.99f);
  glVertex2f(205.19f, 99.24f);
  glVertex2f(205.19f, 99.24f);
  glEnd();
}
void orelha_parte_dentro_2(){
  glColor3ub(0, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2f(152.60f, 137.59f);
  glVertex2f(201.58f, 118.55f);
  glVertex2f(201.58f, 118.55f);
  glVertex2f(201.58f, 118.55f);
  glVertex2f(208.34f, 99.17f);
  glVertex2f(208.34f, 99.17f);
  glVertex2f(208.34f, 99.17f);
  glVertex2f(191.15f, 103.78f);
  glVertex2f(191.15f, 103.78f);
  glEnd();


}
void nariz(){
  glColor3ub(0, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2f(50.75f, 168.66f);
  glVertex2f(54.66f, 171.93f);
  glVertex2f(59.00f, 169.57f);
  glVertex2f(56.56f, 167.32f);
  glVertex2f(53.19f, 166.98f);
  glEnd();
}
void coxa_fundo(){

  glColor3ub(189, 172, 79);
  glBegin(GL_POLYGON);
  glVertex2f(255.86f, 313.21f);
  glVertex2f(290.98f, 279.27f);
  glVertex2f(290.98f, 279.27f);
  glVertex2f(290.98f, 279.27f);
  glVertex2f(317.26f, 319.24f);
  glVertex2f(317.26f, 319.24f);
  glVertex2f(317.26f, 319.24f);
  glVertex2f(306.55f, 361.73f);
  glVertex2f(306.55f, 361.73f);
  glVertex2f(306.55f, 361.73f);
  glVertex2f(272.73f, 359.47f);
  glVertex2f(272.73f, 359.47f);
  glEnd();
}
void pata_traseira_1(){
glColor3ub(240, 219, 101);
glBegin(GL_POLYGON);
glVertex2f(354.61f, 414.95f);
glVertex2f(331.31f, 409.66f);
glVertex2f(331.31f, 409.66f);
glVertex2f(331.31f, 409.66f);
glVertex2f(305.69f, 426.12f);
glVertex2f(305.69f, 426.12f);
glVertex2f(305.69f, 426.12f);
glVertex2f(303.96f, 432.17f);
glVertex2f(303.96f, 432.17f);
glVertex2f(303.96f, 432.17f);
glVertex2f(305.15f, 437.79f);
glVertex2f(305.15f, 437.79f);
glVertex2f(305.15f, 437.79f);
glVertex2f(308.32f, 441.67f);
glVertex2f(308.32f, 441.67f);
glVertex2f(308.32f, 441.67f);
glVertex2f(312.59f, 445.00f);
glVertex2f(312.59f, 445.00f);
glVertex2f(312.59f, 445.00f);
glVertex2f(318.15f, 445.48f);
glVertex2f(318.15f, 445.48f);
glVertex2f(318.15f, 445.48f);
glVertex2f(330.47f, 443.00f);
glVertex2f(330.47f, 443.00f);
glVertex2f(330.47f, 443.00f);
glVertex2f(342.54f, 435.39f);
glVertex2f(342.54f, 435.39f);
glVertex2f(342.54f, 435.39f);
glVertex2f(355.13f, 415.50f);
glVertex2f(355.13f, 415.50f);
glEnd();
}
void pata_traseira_2(){
  glColor3ub(189, 172, 79);
  glBegin(GL_POLYGON);
  glVertex2f(253.51f, 389.78f);
  glVertex2f(232.28f, 394.47f);
  glVertex2f(232.28f, 394.47f);
  glVertex2f(232.28f, 394.47f);
  glVertex2f(230.65f, 402.42f);
  glVertex2f(230.65f, 402.42f);
  glVertex2f(230.65f, 402.42f);
  glVertex2f(231.31f, 407.04f);
  glVertex2f(231.31f, 407.04f);
  glVertex2f(231.31f, 407.04f);
  glVertex2f(234.84f, 411.53f);
  glVertex2f(234.84f, 411.53f);
  glVertex2f(234.84f, 411.53f);
  glVertex2f(240.03f, 412.02f);
  glVertex2f(240.03f, 412.02f);
  glVertex2f(240.03f, 412.02f);
  glVertex2f(254.25f, 410.81f);
  glVertex2f(254.25f, 410.81f);
  glVertex2f(254.25f, 410.81f);
  glVertex2f(269.34f, 405.69f);
  glVertex2f(269.34f, 405.69f);
  glEnd();

}
void pata_frente_1(){
  glColor3ub(240, 219, 101);
  glBegin(GL_POLYGON);
  glVertex2f(136.08f, 421.63f);
  glVertex2f(125.97f, 434.56f);
  glVertex2f(125.97f, 434.56f);
  glVertex2f(125.97f, 434.56f);
  glVertex2f(126.60f, 440.95f);
  glVertex2f(126.60f, 440.95f);
  glVertex2f(126.60f, 440.95f);
  glVertex2f(132.05f, 448.05f);
  glVertex2f(132.05f, 448.05f);
  glVertex2f(132.05f, 448.05f);
  glVertex2f(141.94f, 452.87f);
  glVertex2f(141.94f, 452.87f);
  glVertex2f(141.94f, 452.87f);
  glVertex2f(154.02f, 448.03f);
  glVertex2f(154.02f, 448.03f);
  glVertex2f(154.02f, 448.03f);
  glVertex2f(164.90f, 435.63f);
  glVertex2f(164.90f, 435.63f);
  glVertex2f(164.90f, 435.63f);
  glVertex2f(164.71f, 425.34f);
  glVertex2f(164.71f, 425.34f);
  glVertex2f(164.71f, 425.34f);
  glVertex2f(153.58f, 407.03f);
  glVertex2f(153.58f, 407.03f);
  glEnd();

}
void pata_frente_2(){
  glColor3ub(240, 219, 101);
  glBegin(GL_POLYGON);
  glVertex2f(124.58f, 442.24f);
  glVertex2f(117.01f, 440.98f);
  glVertex2f(117.01f, 440.98f);
  glVertex2f(117.01f, 440.98f);
  glVertex2f(112.01f, 437.49f);
  glVertex2f(112.01f, 437.49f);
  glVertex2f(112.01f, 437.49f);
  glVertex2f(110.22f, 430.42f);
  glVertex2f(110.22f, 430.42f);
  glVertex2f(110.22f, 430.42f);
  glVertex2f(116.38f, 421.18f);
  glVertex2f(116.38f, 421.18f);
  glVertex2f(116.38f, 421.18f);
  glVertex2f(124.64f, 414.89f);
  glVertex2f(124.64f, 414.89f);
  glVertex2f(124.64f, 414.89f);
  glVertex2f(135.70f, 413.47f);
  glVertex2f(135.70f, 413.47f);
  glVertex2f(135.70f, 413.47f);
  glVertex2f(136.50f, 423.04f);
  glVertex2f(136.50f, 423.04f);
  glEnd();
}
void detalhe_orelha(){
  glColor3ub(35, 21, 46);
  glBegin(GL_POLYGON);
  glVertex2f(171.70f, 139.94f);
  glVertex2f(177.20f, 128.30f);
  glVertex2f(177.20f, 128.30f);
  glVertex2f(177.20f, 128.30f);
  glVertex2f(199.80f, 113.75f);
  glVertex2f(199.80f, 113.75f);
  glVertex2f(199.80f, 113.75f);
  glVertex2f(251.88f, 100.68f);
  glVertex2f(251.88f, 100.68f);
  glVertex2f(251.88f, 100.68f);
  glVertex2f(227.69f, 116.04f);
  glVertex2f(227.69f, 116.04f);
  glVertex2f(227.69f, 116.04f);
  glVertex2f(240.79f, 114.41f);
  glVertex2f(240.79f, 114.41f);
  glVertex2f(240.79f, 114.41f);
  glVertex2f(217.41f, 130.62f);
  glVertex2f(217.41f, 130.62f);
  glEnd();
}
void juba_cinza(){
  glColor3ub(212, 212,212);
  glBegin(GL_POLYGON);
  glVertex2f(111.44f, 214.05f);
  glVertex2f(113.99f, 247.34f);
  glVertex2f(113.99f, 247.34f);
  glVertex2f(113.99f, 247.34f);
  glVertex2f(118.78f, 243.52f);
  glVertex2f(118.78f, 243.52f);
  glVertex2f(118.78f, 243.52f);
  glVertex2f(124.37f, 265.60f);
  glVertex2f(124.37f, 265.60f);
  glVertex2f(124.37f, 265.60f);
  glVertex2f(128.55f, 256.79f);
  glVertex2f(128.55f, 256.79f);
  glVertex2f(128.55f, 256.79f);
  glVertex2f(131.90f, 259.85f);
  glVertex2f(131.90f, 259.85f);
  glVertex2f(131.90f, 259.85f);
  glVertex2f(133.52f, 243.41f);
  glVertex2f(133.52f, 243.41f);
  glVertex2f(133.52f, 243.41f);
  glVertex2f(140.48f, 260.45f);
  glVertex2f(140.48f, 260.45f);
  glVertex2f(140.48f, 260.45f);
  glVertex2f(146.60f, 248.33f);
  glVertex2f(146.60f, 248.33f);
  glVertex2f(146.60f, 248.33f);
  glVertex2f(157.74f, 267.76f);
  glVertex2f(157.74f, 267.76f);
  glVertex2f(157.74f, 267.76f);
  glVertex2f(158.83f, 261.76f);
  glVertex2f(158.83f, 261.76f);
  glVertex2f(158.83f, 261.76f);
  glVertex2f(171.04f, 273.18f);
  glVertex2f(171.04f, 273.18f);
  glVertex2f(171.04f, 273.18f);
  glVertex2f(166.27f, 250.06f);
  glVertex2f(166.27f, 250.06f);
  glVertex2f(166.27f, 250.06f);
  glVertex2f(173.86f, 257.26f);
  glVertex2f(173.86f, 257.26f);
  glVertex2f(173.86f, 257.26f);
  glVertex2f(174.81f, 253.09f);
  glVertex2f(174.81f, 253.09f);
  glVertex2f(174.81f, 253.09f);
  glVertex2f(177.50f, 254.07f);
  glVertex2f(177.50f, 254.07f);
  glVertex2f(177.50f, 254.07f);
  glVertex2f(178.25f, 249.98f);
  glVertex2f(178.25f, 249.98f);
  glVertex2f(178.25f, 249.98f);
  glVertex2f(180.37f, 250.99f);
  glVertex2f(180.37f, 250.99f);
  glVertex2f(180.37f, 250.99f);
  glVertex2f(181.66f, 245.96f);
  glVertex2f(181.66f, 245.96f);
  glVertex2f(181.66f, 245.96f);
  glVertex2f(201.48f, 252.03f);
  glVertex2f(201.48f, 252.03f);
  glVertex2f(201.48f, 252.03f);
  glVertex2f(191.33f, 235.45f);
  glVertex2f(191.33f, 235.45f);
  glVertex2f(191.33f, 235.45f);
  glVertex2f(189.92f, 225.21f);
  glVertex2f(189.92f, 225.21f);
  glVertex2f(189.92f, 225.21f);
  glVertex2f(197.41f, 227.22f);
  glVertex2f(197.41f, 227.22f);
  glVertex2f(197.41f, 227.22f);
  glVertex2f(210.50f, 231.35f);
  glVertex2f(210.50f, 231.35f);
  glVertex2f(210.50f, 231.35f);
  glVertex2f(203.17f, 223.05f);
  glVertex2f(203.17f, 223.05f);
  glVertex2f(203.17f, 223.05f);
  glVertex2f(199.19f, 216.31f);
  glVertex2f(199.19f, 216.31f);
  glVertex2f(199.19f, 216.31f);
  glVertex2f(202.49f, 216.79f);
  glVertex2f(202.49f, 216.79f);
  glVertex2f(202.49f, 216.79f);
  glVertex2f(196.13f, 210.07f);
  glVertex2f(196.13f, 210.07f);
  glVertex2f(196.13f, 210.07f);
  glVertex2f(205.20f, 211.06f);
  glVertex2f(205.20f, 211.06f);
  glVertex2f(205.20f, 211.06f);
  glVertex2f(214.28f, 209.97f);
  glVertex2f(214.28f, 209.97f);
  glVertex2f(214.28f, 209.97f);
  glVertex2f(201.07f, 201.14f);
  glVertex2f(201.07f, 201.14f);
  glVertex2f(201.07f, 201.14f);
  glVertex2f(211.10f, 202.84f);
  glVertex2f(211.10f, 202.84f);
  glVertex2f(211.10f, 202.84f);
  glVertex2f(216.66f, 201.33f);
  glVertex2f(216.66f, 201.33f);
  glVertex2f(216.66f, 201.33f);
  glVertex2f(224.35f, 201.79f);
  glVertex2f(224.35f, 201.79f);
  glVertex2f(224.35f, 201.79f);
  glVertex2f(217.30f, 198.95f);
  glVertex2f(217.30f, 198.95f);
  glVertex2f(217.30f, 198.95f);
  glVertex2f(205.72f, 188.72f);
  glVertex2f(205.72f, 188.72f);
  glVertex2f(205.72f, 188.72f);
  glVertex2f(217.31f, 186.85f);
  glVertex2f(217.31f, 186.85f);
  glVertex2f(217.31f, 186.85f);
  glVertex2f(198.03f, 179.19f);
  glVertex2f(198.03f, 179.19f);
  glVertex2f(198.03f, 179.19f);
  glVertex2f(173.46f, 181.45f);
  glVertex2f(173.46f, 181.45f);
  glVertex2f(173.46f, 181.45f);
  glVertex2f(153.27f, 182.54f);
  glVertex2f(153.27f, 182.54f);
  glVertex2f(153.27f, 182.54f);
  glVertex2f(137.55f, 191.04f);
  glVertex2f(137.55f, 191.04f);
  glVertex2f(137.55f, 191.04f);
  glVertex2f(114.31f, 211.84f);
  glVertex2f(114.31f, 211.84f);
  glEnd();

}
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

  corpo();
  coxa_fundo();
  canela_fundo();
  pata_traseira_1();
  pata_frente_1();
  pata_traseira_2();
  pata_frente_2();
  coxa_traseira_fora();
  canela_traseira_fora();
  joelho_traseiro_fora();
  perna_frente_esquerda();
  perna_frente_direita();
  orelha_dentro();
  asa_dentro();
  orelha_fora();
  asa_fora();
  juba();
  juba_cinza();
  cabeca();
  boca_fora();
  nariz();
  orelha_parte_dentro_1();
  orelha_parte_dentro_2();
  detalhe_orelha();
  olho_preto();
  olho_pupila();
  olho_brilho();
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
  }
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