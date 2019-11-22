#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(int argc, const char *argv[])
{
  // ライブラリglfw の初期化
  if (!glfwInit())
  {
    // 初期化に失敗した
    std::cerr << "Can't initialize GLFW." << std::endl;
    exit(EXIT_FAILURE);
  }

  // ウィンドウを作成
  GLFWwindow* window = glfwCreateWindow(640, 480, "Hello FLFW", NULL, NULL);

  if (!window)
  {
    glfwTerminate();
    return -1;
  }

  // 作成したウィンドウを，OpenGLの描画関数のターゲットにする
  glfwMakeContextCurrent(window);

  // ライブラリGLEWの初期化
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK)
  {
    // 失敗
    std::cerr << "Can't initialize GLEW." << std::endl;
    return 1;
  }

  // 背景色設定
  glClearColor(1.0, 1.0, 1.0, 0.0);

  // ビューポートを設定する
  glViewport(100, 50, 300, 300);

  // 描画のループ
  while (!glfwWindowShouldClose(window))
  {

    // 画面を塗りつぶす
    glClear(GL_COLOR_BUFFER_BIT);

    // 描画
    {
      glColor3d(0.0, 0.0, 0.0);
      glLineWidth(2.0f);
      glBegin(GL_LINE_LOOP);
      glVertex2d(-0.5, -0.5);
      glVertex2d(0.5, -0.5);
      glVertex2d(0.5, 0.5);
      glVertex2d(-0.5, 1.0);
      glEnd();
    }

    // 上記描画した図形を表画面のバッファにスワップする
    glfwSwapBuffers(window);

    // 受け取ったイベント（キーボードやマウス入力）を処理する
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
