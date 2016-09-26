#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "math.h"
#include <Windows.h>

const int width = 1280;
const int height = 960;
GLFWwindow* window;
float* pixels = new float[width*height * 3];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

// scratched from https://courses.engr.illinois.edu/ece390/archive/archive-f2000/mp/mp4/anti.html
// see 'Rasterization' part.
void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

void drawverticalLine(const int& j0, const int& i0, const int& j1, const int& i1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}
void DrawCircle(float cx, float cy, float r, int num_segments, const float& red, const float& green, const float& blue)
{
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component

		drawPixel(x + cx, y + cy, red, green, blue);//output vertex

	}
}
void drawOnPixelBuffer()
{
	//std::memset(pixels, 1.0f, sizeof(float)*width*height * 3); // doesn't work
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background

													//for (int i = 0; i<width*height; i++) {
													//	pixels[i * 3 + 0] = 1.0f; // red 
													//	pixels[i * 3 + 1] = 1.0f; // green
													//	pixels[i * 3 + 2] = 1.0f; // blue
													//}

	const int i = rand() % width, j = rand() % height;
	drawPixel(i, j, 0.0f, 0.0f, 0.0f);

	// drawing a line
	//TODO: anti-aliasing
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	if (xpos > 2 && xpos < 254 && ypos<765 && ypos>445)
	{
			DrawCircle(128, 320, 125, 1020, 0.0f, 0.0f, 1.0f);
			DrawCircle(384, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
			DrawCircle(640, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
			DrawCircle(896, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
			DrawCircle(1152, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
			DrawCircle(128, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
			DrawCircle(384, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
			DrawCircle(640, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
			DrawCircle(896, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
			DrawCircle(1152, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
	}
	else if(xpos > 258 && xpos<510 && ypos<765 && ypos>445)
	{
		DrawCircle(128, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(384, 320, 125, 1020, 0.0f, 0.0f, 1.0f);
		DrawCircle(640, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(896, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(1152, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(128, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(384, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(640, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(896, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(1152, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
	}
	else if (xpos > 515 && xpos<765 && ypos<765 && ypos>445)
	{
		DrawCircle(128, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(384, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(640, 320, 125, 1020, 0.0f, 0.0f, 1.0f);
		DrawCircle(896, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(1152, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(128, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(384, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(640, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(896, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(1152, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
	}
	else if (xpos > 771 && xpos<1021 && ypos<765 && ypos>445)
	{
		DrawCircle(128, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(384, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(640, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(896, 320, 125, 1020, 0.0f, 0.0f, 1.0f);
		DrawCircle(1152, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(128, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(384, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(640, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(896, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(1152, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
	}
	else if (xpos > 1027 && xpos<1277 && ypos<765 && ypos>445)
	{
		DrawCircle(128, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(384, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(640, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(896, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(1152, 320, 125, 1020, 0.0f, 0.0f, 1.0f);
		DrawCircle(128, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(384, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(640, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(896, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(1152, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
	}
	else if (xpos > 2 && xpos<253 && ypos<445 && ypos>195)
	{
		DrawCircle(128, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(384, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(640, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(896, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(1152, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(128, 640, 125, 1020, 0.0f, 0.0f, 1.0f);
		DrawCircle(384, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(640, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(896, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(1152, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
	}
	else if (xpos > 258 && xpos<510 && ypos<445 && ypos>195)
	{
		DrawCircle(128, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(384, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(640, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(896, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(1152, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(128, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(384, 640, 125, 1020, 0.0f, 0.0f, 1.0f);
		DrawCircle(640, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(896, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(1152, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
	}
	else if (xpos > 515 && xpos<765 && ypos<445 && ypos>195)
	{
		DrawCircle(128, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(384, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(640, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(896, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(1152, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(128, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(384, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(640, 640, 125, 1020, 0.0f, 0.0f, 1.0f);
		DrawCircle(896, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(1152, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
	}
	else if (xpos > 771 && xpos<1021 && ypos<445 && ypos>195)
	{
		DrawCircle(128, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(384, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(640, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(896, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(1152, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(128, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(384, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(640, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(896, 640, 125, 1020, 0.0f, 0.0f, 1.0f);
		DrawCircle(1152, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
	}
	else if (xpos > 1027 && xpos<1277 && ypos<445 && ypos>195)
	{
		DrawCircle(128, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(384, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(640, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(896, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(1152, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(128, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(384, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(640, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(896, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(1152, 640, 125, 1020, 0.0f, 0.0f, 1.0f);
	}
	else
	{
		DrawCircle(128, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(128, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(384, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(640, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(896, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(1152, 320, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(128, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(384, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(640, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(896, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
		DrawCircle(1152, 640, 125, 1020, 1.0f, 0.0f, 0.0f);
	}
	
	drawLine(80, 320, 176, 320, 1.0f, 0.0f, 0.0f);
	drawLine(128, 272, 176, 320, 1.0f, 0.0f, 0.0f);
	drawverticalLine(368, 128, 320, 176, 1.0f, 0.0f, 0.0f);

	drawLine(350, 320, 418, 320, 1.0f, 0.0f, 0.0f);
	drawLine(316, 286, 384, 354, 1.0f, 0.0f, 0.0f);
	drawverticalLine(354, 384, 286, 452, 1.0f, 0.0f, 0.0f);

		
	for (int y = 240; y < 401; y++)
	{
		drawPixel(640, y, 1.0f, 0.0f, 0.0f);
	}
		
	drawLine(848, 320, 944, 320, 1.0f, 0.0f, 0.0f);
	drawverticalLine(320, 848, 272, 896, 1.0f, 0.0f, 0.0f);
	drawLine(848, 320, 896, 368, 1.0f, 0.0f, 0.0f);

	for (int y = 240; y < 401; y++)
	{
		drawPixel(1152, y, 1.0f, 0.0f, 0.0f);
	}
	drawLine(1112, 360, 1152, 400, 1.0f, 0.0f, 0.0f);
	drawverticalLine(400, 1152, 360, 1192, 1.0f, 0.0f, 0.0f);
	
	drawLine(88, 600, 168, 680, 1.0f, 0.0f, 0.0f);

	
	for (int i = 0; i < 3; i++)
	{
		DrawCircle(384, 640, 50 + i, 1020, 1.0f, 0.0f, 0.0f);
	}

	
	drawLine(600, 600, 680, 600, 1.0f, 0.0f, 0.0f);
	drawLine(600, 680, 680, 680, 1.0f, 0.0f, 0.0f);
	for (int y = 600; y < 681; y++)
	{
		drawPixel(600, y, 1.0f, 0.0f, 0.0f);
	}
	for (int y = 600; y < 681; y++)
	{
		drawPixel(680, y, 1.0f, 0.0f, 0.0f);
	}

	drawLine(856, 600, 936, 680, 1.0f, 0.0f, 0.0f);
	drawverticalLine(680, 856, 600, 936, 1.0f, 0.0f, 0.0f);

	for (int y = 600; y < 681; y++)
	{
		drawPixel(1152, y, 1.0f, 0.0f, 0.0f);
	}
	drawLine(1152, 600, 1192, 640, 1.0f, 0.0f, 0.0f);
	drawverticalLine(640, 1112, 600, 1152, 1.0f, 0.0f, 0.0f);

	//TODO: try moving object
}

int main(void)
{


	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background

							  /* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		//glClear(GL_COLOR_BUFFER_BIT);

		drawOnPixelBuffer();

		//TODO: RGB struct
		//Make a pixel drawing function
		//Make a line drawing function

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}