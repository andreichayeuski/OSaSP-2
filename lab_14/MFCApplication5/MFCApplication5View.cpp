
// MFCApplication5View.cpp: реализация класса CMFCApplication5View
//

#include "pch.h"
#include <cmath>
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MFCApplication5.h"
#endif

#include "MFCApplication5Doc.h"
#include "MFCApplication5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication5View

IMPLEMENT_DYNCREATE(CMFCApplication5View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication5View, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication5View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Создание или уничтожение CMFCApplication5View

CMFCApplication5View::CMFCApplication5View() noexcept
{
	// TODO: добавьте код создания

}

CMFCApplication5View::~CMFCApplication5View()
{
}

BOOL CMFCApplication5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CMFCApplication5View

void CMFCApplication5View::OnDraw(CDC* pDC)
{
	//CMFCApplication5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDC);
	static DWORD dwColor[9] = {
	RGB(0,0,0),
	//черный 
   RGB(255,0,0),       //красный 
   RGB(0,255,0),       //зеленый 
   RGB(0,0,255),       //синий 
   RGB(255,255,0),       //желтый  
   RGB(255,0,255),       //пурпурный 
   RGB(0,255,255),       //голубой 
   RGB(127,127,127),      //серый 
   RGB(255,255,255) };      //белый 

	int xcoord;
	double xcoord1;
	POINT polylpts[4], polygpts[5];
	CBrush newbrush;
	CBrush* oldbrush;
	CPen newpen;
	CPen* oldpen;
	// рисование толстой диагональной линии 
	newpen.CreatePen(PS_SOLID, 6, dwColor[0]);
	oldpen = pDC->SelectObject(&newpen);
	pDC->MoveTo(0, 0);
	pDC->LineTo(640, 430);
	//pDC->TextOut(70,20,"<-diagonalline",15);  
	// удаление пера  
	pDC->SelectObject(oldpen);
	newpen.DeleteObject();

	// рисование синей дуги 
	newpen.CreatePen(PS_DASH, 1, dwColor[3]);
	oldpen = pDC->SelectObject(&newpen);
	pDC->Arc(100, 100, 200, 200, 150, 175, 175, 150);
	//pDC->TextOut(80,180,"smal1 arc->",11); 
	// удаление пера 
	pDC->SelectObject(oldpen);
	newpen.DeleteObject();

	// рисование сегмента с толстым зеленым контуром 
	newpen.CreatePen(PS_SOLID, 8, dwColor[2]);
	oldpen = pDC->SelectObject(&newpen);
	pDC->Chord(550, 20, 630, 80, 555, 25, 625, 70);
	//pDC->TextOut(485,30,"chord->",7); 
	// удаление пера 
	pDC->SelectObject(oldpen);
	newpen.DeleteObject();

	// рисование эллипса и заливка его красным цветом 
	CreatePen(PS_SOLID, 1, dwColor[1]);
	oldpen = pDC->SelectObject(&newpen);
	newbrush.CreateSolidBrush(dwColor[6]);
	oldbrush = pDC->SelectObject(&newbrush);
	pDC->Ellipse(180, 180, 285, 260);
	//pDC->TextOut(210,215, "ellipse", 7);  
	// удаление кисти  
	pDC->SelectObject(oldbrush);
	newbrush.DeleteObject();
	// удаление пера  
	pDC->SelectObject(oldpen);
	newpen.DeleteObject();

	// рисование  круга и заливка его синим цветом 
	newpen.CreatePen(PS_SOLID, 8, dwColor[3]);
	oldpen = pDC->SelectObject(&newpen);
	newbrush.CreateSolidBrush(dwColor[4]);
	oldbrush = pDC->SelectObject(&newbrush);
	pDC->Ellipse(380, 180, 570, 370);
	//pDC->TextOut(450,265,"circle",6);  
	// удаление кисти  
	pDC->SelectObject(oldbrush);
	newbrush.DeleteObject();
	// удаление пера  
	pDC->SelectObject(oldpen);
	newpen.DeleteObject();

	// рисование сектора и заливка его зеленым цветом 
	newpen.CreatePen(PS_SOLID, 1, dwColor[2]);
	oldpen = pDC->SelectObject(&newpen);
	newbrush.CreateSolidBrush(dwColor[5]);
	oldbrush = pDC->SelectObject(&newbrush);
	pDC->Pie(300, 50, 400, 150, 300, 50, 300, 100);
	pDC->TextOut(350, 80, TEXT("<-pie wedge"), 11);
	// удаление кисти 
	pDC->SelectObject(oldbrush);
	newbrush.DeleteObject();
	//удаление пера 
	pDC->SelectObject(oldpen);
	newpen.DeleteObject();

	// рисование прямоугольника и заливка его серым цветом 
	newbrush.CreateSolidBrush(dwColor[7]);
	oldbrush = pDC->SelectObject(&newbrush);
	pDC->Rectangle(50, 300, 150, 400);
	pDC->TextOut(160, 350, TEXT("<-rectangle"), 11);
	// удаление кисти  
	pDC->SelectObject(oldbrush);
	newbrush.DeleteObject();

	// рисование закругленного прямоугольника 
	// и заливка его синим цветом 
	newbrush.CreateHatchBrush(HS_CROSS, dwColor[4]);
	oldbrush = pDC->SelectObject(&newbrush);
	pDC->RoundRect(60, 310, 110, 350, 20, 20);
	pDC->TextOut(120, 310, TEXT("<-rounded rectangle"), 19);
	// удаление кисти 
	pDC->SelectObject(oldbrush);
	newbrush.DeleteObject();

	//// рисование нескольких точек 
	//for (xcoord = 400; xcoord < 850; xcoord += 3)
	//	pDC->SetPixel(xcoord, 150, 0L);
	////pDC->TextOut(455,145,"<-pixels",8); 

	////////////////
	// рисование нескольких точек синусоиды
	for (xcoord1 = 400; xcoord1 < 800; xcoord1 += 2)
	{
		int x, y;
		x = xcoord1;
		y = (int)(std::sin(x) * 20) + 170;
		pDC->SetPixel(xcoord1, y, 0L);
	}

	for (xcoord1 = 400; xcoord1 < 800; xcoord1 += 2)
	{
		int x, y;
		x = xcoord1;
		y = x + 3;
		pDC->SetPixel(xcoord1, y, 0L);
	}
	//pDC->TextOut(455,145,"<-pixels",8); 
	///////////////
	int x1 = 320, y1 = 240, r = 2;
	// рисование нескольких точек спирали
	for (xcoord1 = 0; xcoord1 < 360; xcoord1 += 0.1)
	{
		pDC->SetPixel(x1, y1, 0L);
		newpen.CreatePen(PS_SOLID, 6, dwColor[0]);
		oldpen = pDC->SelectObject(&newpen);
		pDC->MoveTo(x1, y1);


		newpen.DeleteObject();
		x1 = x1 - (r * xcoord1 * sin(xcoord1));
		y1 = y1 + (r * xcoord1 * cos(xcoord1));
		pDC->LineTo(x1, y1);
		//pDC->TextOut(70,20,"<-diagonalline",15);  
		// удаление пера  
		pDC->SelectObject(oldpen);
	}
	//pDC->TextOut(455,145,"<-pixels",8); 
	///////////////
	// рисование толстой ломаной линии пурпурного цвета 
	newpen.CreatePen(PS_SOLID, 3, dwColor[5]);  oldpen = pDC->SelectObject(&newpen);
	polylpts[0].x = 10;
	polylpts[0].y = 30;
	polylpts[1].x = 10;
	polylpts[1].y = 100;
	polylpts[2].x = 50;
	polylpts[2].y = 100;
	polylpts[3].x = 10;
	polylpts[3].y = 30;
	pDC->Polyline(polylpts, 4);
	pDC->TextOut(10, 110, TEXT("polyline"), 8);
	// удаление пера 
	pDC->SelectObject(oldpen);
	newpen.DeleteObject();

	// рисование многоугольника с голубым контуром 
	// и заливка его диагональной желтой штриховкой 
	newpen.CreatePen(PS_SOLID, 4, dwColor[6]);
	oldpen = pDC->SelectObject(&newpen);
	newbrush.CreateHatchBrush(HS_FDIAGONAL, dwColor[4]);
	oldbrush = pDC->SelectObject(&newbrush);
	polygpts[0].x = 40;
	polygpts[0].y = 200;
	polygpts[1].x = 100;
	polygpts[1].y = 270;
	polygpts[2].x = 80;
	polygpts[2].y = 290;
	polygpts[3].x = 20;
	polygpts[3].y = 220;
	polygpts[4].x = 40;
	polygpts[4].y = 200;
	pDC->Polygon(polygpts, 5);
	pDC->TextOut(70, 210, TEXT("<-polygon"), 9);
	// удаление кисти 
	pDC->SelectObject(oldbrush);
	newbrush.DeleteObject();
	// удаление пера 
	pDC->SelectObject(oldpen);
	newpen.DeleteObject();

	// TODO: добавьте здесь код отрисовки для собственных данных
}


// Печать CMFCApplication5View


void CMFCApplication5View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CMFCApplication5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CMFCApplication5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void CMFCApplication5View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication5View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Диагностика CMFCApplication5View

#ifdef _DEBUG
void CMFCApplication5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication5Doc* CMFCApplication5View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication5Doc)));
	return (CMFCApplication5Doc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CMFCApplication5View
