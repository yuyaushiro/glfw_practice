#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "window.h"

int main(int argc, const char *argv[])
{
  // ライブラリglfw の初期化
  if (!glfwInit())
  {
    // 初期化に失敗した
    std::cerr << "Can't initialize GLFW." << std::endl;
    exit(EXIT_FAILURE);
  }

  Window window;

  // ライブラリGLEWの初期化
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK)
  {
    // 失敗
    std::cerr << "Can't initialize GLEW." << std::endl;
    return 1;
  }


  // 背景色設定
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

  // 描画のループ
  while (window)
  {
    // 画面を塗りつぶす
    glClear(GL_COLOR_BUFFER_BIT);

      static const GLfloat vtx[] = {-0.9f, -0.9f,
                                    0.9f, -0.9f,
                                    0.9f, 0.9f,
                                    -0.9f, 0.9f};
      glVertexPointer(2, GL_FLOAT, 0, vtx);
      glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

      glEnableClientState(GL_VERTEX_ARRAY);
      glDrawArrays(GL_LINE_LOOP, 0, 4);
      glDisableClientState(GL_VERTEX_ARRAY);

    // カラーバッファを入れ替える
    window.swapBuffers();

    // 受け取ったイベント（キーボードやマウス入力）を処理する
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
