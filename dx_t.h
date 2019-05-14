#ifndef DX_T_H
#define DX_T_H
#include <d3dx9.h>

class dx_t
{
public:
    dx_t();
};


VOID SetupMatrices();
HRESULT InitD3D(HWND hWnd);
VOID SetupLight();
HRESULT InitGeometry();
VOID Cleanup();
VOID Render();
LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

#endif // DX_T_H
