#include <cstdlib>
#include <iostream>

#ifdef WIN32

#include <windows.h>

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MessageBox(nullptr, "Hello World!", "Generic notification", MB_OK);
	std::cout << "Hello World!" << std::endl;
	return EXIT_SUCCESS;
}

#else

int main(int argc, char *argv[])
{
	std::cout << "Hello World!" << std::endl;
	return EXIT_SUCCESS;
}

#endif
