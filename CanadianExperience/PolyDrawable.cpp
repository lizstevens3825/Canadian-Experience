/**
 * \file PolyDrawable.cpp
 *
 * \author Elizabeth Stevens
 */

#include "pch.h"
#include <vector>

#include "PolyDrawable.h"

using namespace Gdiplus;
using namespace std;

 /**
  * Constructor
  * \param name The drawable name
  */
CPolyDrawable::CPolyDrawable(const std::wstring& name) : CDrawable(name)
{
}


/** Destructor */
CPolyDrawable::~CPolyDrawable()
{
}


/** Draw this polydrawable
* \param graphics The Graphics object we are drawing on */
void CPolyDrawable::Draw(Gdiplus::Graphics* graphics)
{
    SolidBrush brush(mColor);

    // Transform the points
    vector<Point> points;
    for (auto point : mPoints)
    {
        points.push_back(RotatePoint(point, mPlacedR) + mPlacedPosition);
    }

    graphics->FillPolygon(&brush, &points[0], (int)points.size());
}


/**
* Test to see if a mouse click is on this polydrawable.
* \param pos Mouse position on drawing
* \returns A boolean indicating if the polydrawable is clicked on.
*/
bool CPolyDrawable::HitTest(Gdiplus::Point pos)
{
    // Transform the points
    vector<Point> points;
    for (auto point : mPoints)
    {
        points.push_back(RotatePoint(point, mPlacedR) + mPlacedPosition);
    }

    GraphicsPath path;
    path.AddPolygon(&points[0], (int)points.size());
    return path.IsVisible(pos) ? true : false;
}


/**
 * Add a point to this polydrawable
 * \param point The position point to add
 */
void CPolyDrawable::AddPoint(Gdiplus::Point point)
{
    mPoints.push_back(point);
}
