#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


int window_width = 640;
int window_height = 480;


int main(int argc, const char *argv[])
{
  // GLFWの初期化
  if (!glfwInit())
  {
    // 初期化に失敗
    std::cerr << "Can't initialize GLFW." << std::endl;
    exit(EXIT_FAILURE);
  }

  // ウインドウの作成
  GLFWwindow* window = glfwCreateWindow(window_width, window_height, "Simple", NULL, NULL);
  if (!window)
  {
    std::cerr << "Can't opwn window." << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0f, window_width, 0.0f, window_height, -1.0f, 1.0f);

  // 描画のループ
  while (!glfwWindowShouldClose(window))
  {
    // バッファのクリア
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

      // 四角形
      static const GLfloat vtx4[] = {450.0f, 300.0f,
                                     450.0f, 200.0f,
                                     550.0f, 200.0f,
                                     550.0f, 300.0f};
      glVertexPointer(2, GL_FLOAT, 0, vtx4);
      glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

      glEnableClientState(GL_VERTEX_ARRAY);
      glDrawArrays(GL_LINE_LOOP, 0, 4);
      glDisableClientState(GL_VERTEX_ARRAY);

    // ダブルバッファのスワップ
    glfwSwapBuffers(window);
    // 受け取ったイベント（キーボードやマウス入力）を処理する
    glfwPollEvents();
  }

  // GLFWの終了処理
  glfwTerminate();

  return 0;
}
