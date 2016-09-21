#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "math.h"
#include <time.h>

const int width = 640;
const int height = 480;
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

void drawOnPixelBuffer()
{
	srand((unsigned)time(NULL));	
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
	const int i0 = 100, i1 = 200;
	const int j0 = 50, j1 = 80;
	
	
	for (int x = 0; x < 20; x++)
	{
		drawLine(i0, j0+x, i1, j1+x, 1.0f, 0.0f, 0.0f);
	}
	/*drawLine(250, 50, 350, 50, 1.0f, 0.0f, 0.0f);
	drawLine(250, 150, 350, 150, 1.0f, 0.0f, 0.0f);
	drawLine(250, 50, 250, 150, 1.0f, 0.0f, 0.0f);
	drawLine(350, 50, 350, 150, 1.0f, 0.0f, 0.0f);
	*/
	for (int x = 0; x < 100; x++)
	{
		drawLine(250, 50+x, 350, 50+x, 1.0f, 0.0f, 0.0f);
	}
	drawLine(450,50, 550, 50, 1.0f, 0.0f, 0.0f);
	drawLine(450, 50, 500,150, 1.0f, 0.0f, 0.0f);
	drawLine(500, 150, 550, 50, 1.0f, 0.0f, 0.0f);


	for (int x = 0; x < 100;x++)
	{ 
		drawPixel(100, 250 + x, 1.0f, 0.0f, 0.0f);
	}
	for (int x = 0; x < 100; x++)
	{
		drawPixel(100+x, 250, 1.0f, 0.0f, 0.0f);
	}
	for (int x = 0; x < 100; x++)
	{
		drawPixel(200, 250 + x, 1.0f, 0.0f, 0.0f);
	}
	for (int x = 0; x < 100; x++)
	{
		drawPixel(100+x, 350,  1.0f, 0.0f, 0.0f);
	}

	drawLine(300, 250, 375, 250, 1.0f, 0.0f, 0.0f);
	for (int x = 0; x < 16; x++)
	{
		drawPixel(375 + x, 250+4*x, 1.0f, 0.0f, 0.0f);
	}
	for (int x = 0; x < 16; x++)
	{
		drawPixel(300 - x, 250 + 4 * x, 1.0f, 0.0f, 0.0f);
	}
	for (int x = 0; x < 53; x++)
	{
		drawPixel(285 + x, 310 + x/2, 1.0f, 0.0f, 0.0f);
	}
	for (int x = 0; x < 53; x++)
	{
		drawPixel(390 - x, 310 + x / 2, 1.0f, 0.0f, 0.0f);
	}

	
	


	//TODO: try moving object
}

int main(void)
{
	GLFWwindow* window;

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
