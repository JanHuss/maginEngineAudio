#include <Windows.h>

int CALLBACK WinMain(
	HINSTANCE hInstance, // handle to an instance or handle to a module
	HINSTANCE hPrevInstance, // depracated since 16 bit was phased out, but still lingering in the operating system
	LPSTR lpCmdLine, // contains the commandline arguments as a Unicode-string
	int nCmdShow) // flag to indicate if the main window is minimized, maximized or in its regular dimensions
{
	const auto pClassName = L"Magin Engine Audio";
	// register window class
	WNDCLASSEX wc = {0};
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = DefWindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;

	RegisterClassEx(&wc);

	// create window. HWND handles window functionality
	HWND hWnd = CreateWindowEx( 
		0, 
		pClassName, 
		L"Magin Engine Audio", // Window title name 
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, // styles added to window. for more refer to: 
													//https://learn.microsoft.com/en-us/windows/win32/winmsg/window-styles
		200, 200, // window position on startup
		640, 480, // window size
		nullptr, nullptr, hInstance, nullptr);

	// display window
	ShowWindow (hWnd, // parameter for the window that needs to be displayed
				SW_SHOW); // how the window is shown on screen

	while (true);
	return 0; // isn't used by the OS but can be used to indicate other apps of this app's status
}
