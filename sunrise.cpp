#include <GL/glut.h>
#include <math.h>

float sunY = -0.9;     // Initial Y position of the sun
bool rising = true;    // Boolean to control the sun's movement direction

// Function to draw a circle (sun)
void drawSun(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 0.0); // Yellow color for the sun
    glVertex2f(x, y);         // Center of the sun
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

// Function to render the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Change background color based on sun position
    if (sunY > 0.0) {
        glClearColor(1.0, 0.5, 0.0, 1.0); // Sunset/Sunrise - Orange sky
    } else {
        glClearColor(0.5, 0.8, 1.0, 1.0); // Daytime - Blue sky
    }

    // Draw the sun
    drawSun(0.0, sunY, 0.1);

    glutSwapBuffers();
}

// Function to update the sun's position
void update(int value) {
    if (rising) {
        sunY += 0.01; // Move the sun up
        if (sunY >= 0.9) rising = false; // Switch direction at the top
    } else {
        sunY -= 0.01; // Move the sun down
        if (sunY <= -0.9) rising = true; // Switch direction at the bottom
    }

    glutPostRedisplay();           // Request a redraw
    glutTimerFunc(25, update, 0);  // Schedule the next update
}

// Function to set up the OpenGL environment
void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set coordinate system
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Sunrise and Sunset");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0); // Start the timer function
    glutMainLoop();

    return 0;
}
