#include <window.h>


// コンストラクタ
Window::Window(int width, int height, const char *title)
  : window(glfwCreateWindow(width, height, title, NULL, NULL))
{
  if (window==NULL)
  {
    // ウィンドウが作成できなかった
    std::cerr << "Can't create GLFW window." << std::endl;
  }

  // 現在のウィンドウを処理対象にする
  glfwMakeContextCurrent(window);

  // GLEW を初期化する
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK)
  {
    // GLEW の初期化に失敗した
    std::cerr << "Can't initialize GLEW" << std::endl;
    exit(1);
  }

  // 垂直同期のタイミングを待つ
  glfwSwapInterval(1);

  // ウィンドウのサイズ変更時に呼び出す処理の登録
  glfwSetWindowSizeCallback(window, resize);

  // 開いたウィンドウの初期設定
  resize(window, width, height);

}


// デストラクタ
Window::~Window()
{
  glfwDestroyWindow(window);
}


// 描画ループの継続判定
Window::operator bool() const
{
  // イベントを取り出す
  glfwWaitEvents();

  // ウィンドウを閉じる必要がなければ true を返す
  return !glfwWindowShouldClose(window);
}


// ダブルバッファリング
void Window::swapBuffers() const
{
  // カラーバッファを入れ替える
  glfwSwapBuffers(window);
}


// ウィンドウのサイズ変更時の処理
void Window::resize(GLFWwindow *const window, int width, int height)
{
  // フレームバッファのサイズを調べる
  int fb_width, fb_height;
  glfwGetFramebufferSize(window, &fb_width, &fb_height);

  // フレームバッファ全体をビューポートに設定する
  glViewport(0, 0, fb_width, fb_height);
}
