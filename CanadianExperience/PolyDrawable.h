/**
 * \file PolyDrawable.h
 *
 * \author Elizabeth Stevens
 *
 * A drawable based on polygon images.
 */

#pragma once

#include "Drawable.h"

#include <vector>

 /**
  * A drawable based on polygon images.
  *
  * This class has a list of points and draws a polygon
  * drawable based on those points.
  */
class CPolyDrawable : public CDrawable
{
public:
    virtual ~CPolyDrawable();

    /** Default constructor disabled */
    CPolyDrawable() = delete;
    /** Copy constructor disabled */
    CPolyDrawable(const CPolyDrawable&) = delete;
    /** Assignment operator disabled */
    void operator=(const CPolyDrawable&) = delete;

    CPolyDrawable(const std::wstring& name);
    void Draw(Gdiplus::Graphics* graphics) override;
    bool HitTest(Gdiplus::Point pos) override;
    void AddPoint(Gdiplus::Point point);

    /** Set the polydrawable color
    * \param color The new polydrawable color*/
    void SetColor(Gdiplus::Color color) { mColor = color; }

    /** Get the polydrawable color
    * \returns The polydrawable color*/
    Gdiplus::Color GetColor() { return mColor; }

private:
    /// The polygon color
    Gdiplus::Color mColor = Gdiplus::Color::Black;

    /// The array of point objects
    std::vector<Gdiplus::Point> mPoints;
};

