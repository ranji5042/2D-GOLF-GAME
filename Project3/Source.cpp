#include <GL/glut.h>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <iostream>
#define M_PI 22 / 7
float ballX = 0.0f;
float ballY = -0.6f;
float ballRadius = 0.02f;
float ballVelocityX = 0.0f;
float ballVelocityY = 0.0f;
float holeX = 0.0f;
float holeY = 0.6f;
float holeRadius = 0.03f;
int gameOver = 0;
int currentLevel = 0;
int isIdle = 1;
int showingLevelCompletion = 0;
void init() {
    glClearColor(0.6, 0.8, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}


void drawBall() {
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(ballX, ballY);
    for (float angle = 0.0; angle <= 2 * M_PI + 1; angle += 0.1) {
        float x = ballX + ballRadius * cos(angle);
        float y = ballY + ballRadius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawHole() {
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(holeX, holeY);
    for (float angle = 0.0; angle <= 2 * M_PI + 1; angle += 0.1) {
        float x = holeX + holeRadius * cos(angle);
        float y = holeY + holeRadius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}
void level1obs()
{
    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.1, -0.1);
    glVertex2f(0.1, 0.1);
    glVertex2f(0.1, -0.1);
    glVertex2f(-0.1, -0.1);
    glVertex2f(-0.1, 0.1);
    glVertex2f(0.1, 0.1);
   
    glEnd();

}
void level2obs() {
    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.5, -0.1);
    glVertex2f(0.5, 0.1);
    glVertex2f(0.5, -0.1);
    glVertex2f(-0.5, -0.1);
    glVertex2f(-0.5, 0.1);
    glVertex2f(0.5, 0.1);

    glEnd();
}
void border() {
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(4.0);

    glBegin(GL_LINES);
    glVertex2f(0.99, -0.9);
    glVertex2f(0.99, 0.8);
    glVertex2f(0.99, -0.9);
    glVertex2f(-0.99, -0.9);
    glVertex2f(-0.99, -0.9);
    glVertex2f(-0.99, 0.8);
    glVertex2f(0.99, 0.8);
    glVertex2f(-0.99, 0.8);
    glEnd();
    glColor3f(0.0, 1, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.99, -0.9);
    glVertex2f(0.99, 0.8);
    glVertex2f(0.99, -0.9);
    glVertex2f(-0.99, -0.9);
    glVertex2f(-0.99, -0.9);
    glVertex2f(-0.99, 0.8);
    glVertex2f(0.99, 0.8);
    glVertex2f(-0.99, 0.8);
    glEnd();
}


void draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.6, 0.8, 1.0, 0.0);
    border();
    drawBall();
    drawHole();
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(-0.15, 0.809);
    std::string levelText = "LEVEL " + std::to_string(currentLevel);
    for (char c : levelText) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
    glFlush();
    glutSwapBuffers();
}

void draw1() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.6, 0.8, 1.0, 0.0);
    border();
    drawBall();
    drawHole();
    level1obs();
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(-0.15, 0.809);
    std::string levelText = "LEVEL " + std::to_string(currentLevel);
    for (char c : levelText) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
    glFlush();
    glutSwapBuffers();
}
void draw2() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.6, 0.8, 1.0, 0.0);
    border();
    drawBall();
    drawHole();
    level2obs();
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(-0.15, 0.809);
    std::string levelText = "LEVEL " + std::to_string(currentLevel);
    for (char c : levelText) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
    glFlush();
    glutSwapBuffers();
}
void sta() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.6, 0.8, 1.0, 0.0);
    border();
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(-0.25, 0.5);
    const char* defaultText = "2D GOLF GAME";
    for (int i = 0; defaultText[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, defaultText[i]);
    }
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(-0.3, 0.0);
    defaultText = "TO START GAME PRESS S";
    for (int i = 0; defaultText[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, defaultText[i]);
    }
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(-0.24, -0.2);
    defaultText = "TO EXIT PRESS X";
    for (int i = 0; defaultText[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, defaultText[i]);
    }
    glFlush();
    glutSwapBuffers();
}

void update(int value) {
    if (!gameOver)
    {
        if (1) {
            if (!isIdle) {
                ballX += ballVelocityX;
                ballY += ballVelocityY;
                if (currentLevel == 1) {
                    if (ballX + ballRadius > 1.0f || ballX - ballRadius < -1.0f) {
                        ballVelocityX *= -1;
                    }
                    if (ballY + ballRadius > 0.8f || ballY - ballRadius < -0.9f) {
                        ballVelocityY *= -1;
                    }
                }
                if (currentLevel == 2) {
                    if (ballX + ballRadius > 1.0f || ballX - ballRadius < -1.0f) {

                        ballVelocityX *= -1;

                    }
                    if (ballY + ballRadius > 0.8f || ballY - ballRadius < -0.9f) {
                        ballVelocityY *= -1;
                    }
                    if (!(ballY + ballRadius > 0.1f || ballY - ballRadius < -0.1f)) {
                        if (!(ballX + ballRadius > 0.1f || ballX - ballRadius < -0.1f)) {
                            ballVelocityY *= -1;

                        }
                    }
                    if (!(ballX + ballRadius > 0.1f || ballX - ballRadius < -0.1f)) {
                        if (!(ballY + ballRadius > 0.1f || ballY - ballRadius < -0.1f)) {
                            ballVelocityX*= -1;

                        }
                    }
                }
                    if (currentLevel == 3) {

                        if (ballX + ballRadius > 1.0f || ballX - ballRadius < -1.0f) {

                            ballVelocityX *= -1;

                        }
                       if (ballY + ballRadius > 0.8f || ballY - ballRadius < -0.9f) {
                            ballVelocityY *= -1;
                        }
                       int a = ballVelocityX;
                       int b = ballVelocityY;
                       if (!(ballY + ballRadius > 0.1f || ballY - ballRadius < -0.1f)) {
                           if (!(ballX + ballRadius > 0.5f || ballX - ballRadius < -0.5f)) {
                                ballVelocityY *= -1;

                               
                           }
                       }
                        //if(!(ballX + ballRadius > 0.5f || ballX - ballRadius < -0.5f)) {
                    //        if (!(ballY + ballRadius > 0.1f || ballY - ballRadius < -0.1f)) 
                     //           ballVelocityX *= -1;
                          

                     //       }
                      //  }
                        //else;
                       
                       // for(double i=-0.5;i<=0.5;i=+0.00001)
                            
            
                    
                }
                float distance = sqrt(pow(ballX - holeX, 2) + pow(ballY - holeY, 2));
                if (distance < holeRadius - ballRadius) {
                    currentLevel++;
                    ballX = 0.0f;
                    ballY = -0.6f;
                    ballVelocityX = 0.0f;
                    ballVelocityY = 0.0f;
                    isIdle = 1;
                }

                glutPostRedisplay();
            }
            glutTimerFunc(10, update, 0);
        }
    }
}




void handleMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        float clickX = (x / (float)glutGet(GLUT_WINDOW_WIDTH)) * 2 - 1;
        float clickY = (1 - y / (float)glutGet(GLUT_WINDOW_HEIGHT)) * 2 - 1;
        float deltaX = clickX - ballX;
        float deltaY = clickY - ballY;
        float magnitude = sqrt(deltaX * deltaX + deltaY * deltaY);
        ballVelocityX = 0.01 * deltaX / magnitude;
        ballVelocityY = 0.01 * deltaY / magnitude;
        isIdle = 0;
    }
}


void resize(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspectRatio = (float)width / (float)height;
    if (aspectRatio >= 1.0) {
        gluOrtho2D(-aspectRatio, aspectRatio, -1.0, 1.0);
    }
    else {
        gluOrtho2D(-1.0, 1.0, -1.0 / aspectRatio, 1.0 / aspectRatio);
    }

    glMatrixMode(GL_MODELVIEW);
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.6, 0.8, 1.0, 0.0);
    border();
    switch (currentLevel) {
    case 0:
        sta();
        break;
    case 1:
        draw();
     
        break;

    case 2:
        draw1();

        break;
    case 3:
        draw2();
        break;
    default:
        
        glColor3f(0.0, 0.0, 0.0);
        glRasterPos2f(-0.18, 0.2);
        currentLevel = 0;
        const char* defaultText = "YOU WON";
        for (int i = 0; defaultText[i] != '\0'; i++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, defaultText[i]);
        }
        glColor3f(0.0, 0.0, 0.0);
        glRasterPos2f(-0.3, 0.0);
        defaultText = "TO START AGAIN S";
        for (int i = 0; defaultText[i] != '\0'; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, defaultText[i]);
        }
        glColor3f(0.0, 0.0, 0.0);
        glRasterPos2f(-0.24, -0.2);
        defaultText = "TO EXIT PRESS X";
        for (int i = 0; defaultText[i] != '\0'; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, defaultText[i]);
        }
    }
    if (showingLevelCompletion) {
        glColor3f(0.0, 0.0, 0.0);
        glRasterPos2f(-0.2, 0.0);
        const char* completionText = "Level Completed!";
        for (int i = 0; completionText[i] != '\0'; i++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, completionText[i]);
        }
    }

    glFlush();
    glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y) {
    if (key == 's' || key == 'S')
    {   if(currentLevel==0|| currentLevel==4)
        currentLevel++;
        draw();

    }
    if (key == 'x' || key == 'X')
    {
        if (currentLevel == 0 || currentLevel == 4)
        exit(0);
    }
}

void option(int ch) {
    if (ch == 1) {
        exit(0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Simple Golf Game");
    glutFullScreen();
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutMouseFunc(handleMouseClick);
    glutKeyboardUpFunc(keyboard);
    init();
    glutTimerFunc(10, update, 0);
    glutCreateMenu(option);
    glutAddMenuEntry("Exit", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}