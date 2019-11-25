#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


/// ウィンドウ
class Window
{
public:
  /// コンストラクタ
  Window(int width=640, int height=480, const char *title="Hello");

  /// デストラクタ
  virtual ~Window();

  /// 描画ループの継続判定
  explicit operator bool() const;

  /// ダブルバッファリング
  void swapBuffers() const;

  /// ウィンドウのサイズ変更時の処理
  static void resize(GLFWwindow *const window, int width, int height);

private:
  /// ウィンドウのハンドル
  GLFWwindow *const window;

  /// 縦横比
  GLfloat aspect;
};
