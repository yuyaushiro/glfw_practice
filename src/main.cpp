#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "window.h"


int window_width = 800;
int window_height = 800;


int main(int argc, const char *argv[])
{
  // GLFWの初期化
  if (!glfwInit())
  {
    // 初期化に失敗
    std::cerr << "Can't initialize GLFW." << std::endl;
    exit(EXIT_FAILURE);
  }

  Window window;

  // 描画のループ
  while (window)
  {
    // バッファのクリア
    glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

      // 四角形
      static const GLfloat vtx4[] = {4.0f, -4.0f,
                                     4.0f, 4.0f,
                                     -4.0f, 4.0f,
                                     -4.0f, -4.0f};
      glVertexPointer(2, GL_FLOAT, 0, vtx4);
      glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

      glEnableClientState(GL_VERTEX_ARRAY);
      glDrawArrays(GL_POLYGON, 0, 4);
      glDisableClientState(GL_VERTEX_ARRAY);

    // ダブルバッファのスワップ
    window.swapBuffers();
  }

  // GLFWの終了処理
  glfwTerminate();

  return 0;
}
