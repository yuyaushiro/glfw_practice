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
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

  // 描画のループ
  while (!glfwWindowShouldClose(window))
  {
    // 画面を塗りつぶす
    glClear(GL_COLOR_BUFFER_BIT);

    // 描画する点のX座標とY座標を配列で用意
    static const GLfloat vtx[] = {0.0f, 0.0f};

    // 描画に使う頂点の配列をOpenGLに指示
    glVertexPointer(2, GL_FLOAT, 0, vtx);

    // 描画する店の大きさを指定
    glPointSize(4.0f);

    // 頂点配列で描画するモードに切り替えて点の描画を開始
    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawArrays(GL_POINTS, 0, 1);

    // 描画が終わったら描画モードをもとに戻す
    glDisableClientState(GL_VERTEX_ARRAY);

    // 上記描画した図形を表画面のバッファにスワップする
    glfwSwapBuffers(window);

    // 受け取ったイベント（キーボードやマウス入力）を処理する
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
