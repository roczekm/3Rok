#ifdef BUTTON_EXPORTS
#define BUTTON_API __declspec(dllexport) 
#else
#define BUTTON_API __declspec(dllimport) 
#endif


#include <windows.h>
#include <string>

class BUTTON_API MyButton 
{
public:
	MyButton();
	virtual ~MyButton();

	void Create(LPCTSTR _name,int _x,int _y);
	void SetX(const int _x);
	void SetY(const int _y);

	void UpdateWindow();
private:
	HWND hwnd_;
	LPCTSTR name;
	int x;
	int y;

};