#include <Windows.h>

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	const auto pClassName = "Magin Engine Audio";
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

	// create window
	HWND hWnd = CreateWindowEx( 0, pClassName, 
		"Magin Engine Audio", // Window title name
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, // styles added to window. for more refer to: 
													//https://learn.microsoft.com/en-us/windows/win32/winmsg/window-styles
		200, 200, // window position on startup
		640, 480, // window size
		nullptr, nullptr, hInstance, nullptr);

	// display window
	ShowWindow (hWnd, SW_SHOW);

	while (true);
	return 0;	
}
