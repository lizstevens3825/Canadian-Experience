/**
 * \file ImageDrawable.h
 *
 * \author Elizabeth Stevens
 *
 * A drawable based on images.
 */

#pragma once

#include <memory>
#include <string>

#include "Drawable.h"

using namespace Gdiplus;

 /**
  * A drawable based on images.
  *
  * This class has a list of points and draws a image
  * drawable based on those points.
  */
class CImageDrawable : public CDrawable
{
public:
    virtual ~CImageDrawable();

    /** Default constructor disabled */
    CImageDrawable() = delete;
    /** Copy constructor disabled */
    CImageDrawable(const CImageDrawable&) = delete;
    /** Assignment operator disabled */
    void operator=(const CImageDrawable&) = delete;

    CImageDrawable(const std::wstring& name, const std::wstring& filename);
    void Draw(Gdiplus::Graphics* graphics) override;
    bool HitTest(Gdiplus::Point pos);

    /** Set the drawable center
     * \param pos The new drawable center*/
    void SetCenter(Gdiplus::Point pos) { mCenter = pos; }

    /** Get the drawable center
     * \returns The drawable center*/
    Gdiplus::Point GetCenter() const { return mCenter; }

protected:
    /// The image for this drawable
    std::unique_ptr<Gdiplus::Bitmap> mImage;

private:
    /// The center of our image drawable
    Gdiplus::Point mCenter = Gdiplus::Point(0, 0);
};

