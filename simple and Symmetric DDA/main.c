//
//  main.c
//  simple and Symmetric DDA
//
//  Created by B Raghu Ram Reddy  on 16/01/17.
//  Copyright © 2017 B Raghu Ram Reddy . All rights reserved.
//

#include <stdio.h>
#include<GLUT/GLUT.h>
#include <OpenGL/gl.h>
#include<stdlib.h>
#define ROUND(x) ((int)(x+0.5))
int xa,xb,ya,yb;
void display1 (void)
{
    int dx=xb-xa,dy=yb-ya,steps,k;
    float xIncrement,yIncrement,x=xa,y=ya;
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    if(abs(dx)>abs(dy))
        steps=abs(dx);
    else steps=abs(dy);
    xIncrement=dx/(float)steps;
    yIncrement=dy/(float)steps;
    glBegin(GL_POINTS);
    glVertex2s(ROUND(x),ROUND(y));
    for(k=0;k<steps;k++)
    {
        x+=xIncrement;
        y+=yIncrement;
        glVertex2s(ROUND(x),ROUND(y));
        printf("%lf %lf\n",x,y);
    }
    
    glColor3f (1.0, 1.0, 1.0);
    for(int i=-100 ; i<=100 ; i++)
    {
        glVertex2s(i,0);
        glVertex2s(0,i);
    }
    
    glEnd();
    glFlush();
}
void display2 (void)
{
    int dx=xb-xa,dy=yb-ya,steps,k;
    float xIncrement,yIncrement,x=xa,y=ya;
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    xIncrement = dx; yIncrement= dy;
    
    while((xIncrement>1)||(yIncrement>1)){
        xIncrement = xIncrement/2;
        yIncrement = yIncrement/2;
    }
    glBegin(GL_POINTS);
    glVertex2s(ROUND(x),ROUND(y));
    while((x<xb)||(y<yb))
    {
        x+=xIncrement;
        y+=yIncrement;
        glVertex2s(ROUND(x),ROUND(y));
        printf("%lf %lf\n",x,y);
    }
    
    glColor3f (1.0, 1.0, 1.0);
    for(int i=-100 ; i<=100 ; i++)
    {
        glVertex2s(i,0);
        glVertex2s(0,i);
    }
    
    glEnd();
    glFlush();
}

void midPoint (void){
    int x = xa, y = ya, dy = yb-ya, dx = xb-xa;
    float d = 2*dy-dx, dde = 2*dy, ddne = 2*(dy-dx);
    
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    
    while(x<xb){
        glVertex2s(x,y);
        printf("%d %d\n",x,y);
        
        if(d<0)
            d = d+dde;
        else{
                d = d+ddne;
                y = y+1;
        }
        x++;
    }
    glColor3f (1.0, 1.0, 1.0);
    for(int i=-100 ; i<=100 ; i++)
    {
        glVertex2s(i,0);
        glVertex2s(0,i);
    }
    
    glEnd();
    glFlush();

}

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    int choice;
    printf("Enter the points\n");
    printf("(X1,Y1)\n");
    scanf("%d %d",&xa,&ya);
    printf("(X1,Y1)\n");
    scanf("%d %d",&xb,&yb);
    printf("Select mechanism : \n\t 1. Simpe DDA \n\t 2. Symmetric DDA \n\t 3. MID-POINT(1st Octant)");
    scanf("%d",&choice);
    if(!((choice == 1 )||(choice == 2)||(choice == 3))){
        printf("Wrong Input");
        return 0;
    }
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("DDA");
    init ();
    if(choice == 1){
        printf("\n simple DDA");
        glutDisplayFunc(display1);
    }
    else if(choice == 2){
        printf("\n symmetric DDA");
        glutDisplayFunc(display2);
    }
    else if(choice == 3){
        printf("\n MID-POINT(1st octant)");
        glutDisplayFunc(midPoint);
    }
    glutMainLoop();
    return 0;
}
