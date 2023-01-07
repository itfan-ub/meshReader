#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );

}


TEST_CASE("OpenGL window test") {
  // Initialize GLFW
  REQUIRE(glfwInit() == GLFW_TRUE);

  // Create a GLFW window
  GLFWwindow* window = glfwCreateWindow(640, 480, "My Window", nullptr, nullptr);
  REQUIRE(window != nullptr);

  // Make the window's context current
  glfwMakeContextCurrent(window);

  // Initialize Glad
  REQUIRE(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));

  // Verify that the window was created correctly
  int width, height;
  glfwGetFramebufferSize(window, &width, &height);
  REQUIRE(width == 640);
  REQUIRE(height == 480);

  // Destroy the window
  glfwDestroyWindow(window);

  // Terminate GLFW
  glfwTerminate();
}