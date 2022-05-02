#include <GL/freeglut.h>

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello OpenGL and FreeGLUT");

    InitializeGlutCallbacks();

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glutMainLoop();

    return 0;
}
