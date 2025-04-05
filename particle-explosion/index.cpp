#include <GLFW/glfw3.h>
#include <cstdlib>
#include <ctime>

struct Particle {
    float x, y;
    float dx, dy;
};

const int NUM_PARTICLES = 100;
Particle particles[NUM_PARTICLES];

void initParticles() {
    srand(time(0));
    for (int i = 0; i < NUM_PARTICLES; i++) {
        particles[i].x = 0;
        particles[i].y = 0;
        particles[i].dx = (rand() % 100 - 50) / 500.0f;
        particles[i].dy = (rand() % 100 - 50) / 500.0f;
    }
}

void drawParticles() {
    glBegin(GL_POINTS);
    for (int i = 0; i < NUM_PARTICLES; i++) {
        glVertex2f(particles[i].x, particles[i].y);
        particles[i].x += particles[i].dx;
        particles[i].y += particles[i].dy;
    }
    glEnd();
}

int main() {
    if (!glfwInit()) return -1;
    GLFWwindow* window = glfwCreateWindow(800, 600, "Particle Explosion", NULL, NULL);
    if (!window) { glfwTerminate(); return -1; }
    glfwMakeContextCurrent(window);
    glPointSize(5);

    initParticles();
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        drawParticles();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
