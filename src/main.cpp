#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

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
  GLFWwindow* window = glfwCreateWindow(640, 480, "Simple", NULL, NULL);
  if (!window)
  {
    std::cerr << "Can't opwn window." << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);


  // 描画のループ
  while (!glfwWindowShouldClose(window))
  {
    // バッファのクリア
    glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // ダブルバッファのスワップ
    glfwSwapBuffers(window);
    // 受け取ったイベント（キーボードやマウス入力）を処理する
    glfwPollEvents();
  }

  // GLFWの終了処理
  glfwTerminate();

  return 0;
}
