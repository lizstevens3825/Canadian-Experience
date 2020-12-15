/**
 * \file HeadTop.cpp
 *
 * \author Elizabeth Stevens
 */

#include "pch.h"
#include "HeadTop.h"
#include "Timeline.h"

using namespace Gdiplus;
using namespace std;

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;

 /** Constructor
  * \param name The drawable name
  * \param filename The filename for the image */
CHeadTop::CHeadTop(const std::wstring& name, const std::wstring& filename) : CImageDrawable(name, filename)
{
}


/** Destructor */
CHeadTop::~CHeadTop()
{
}

/** Transform a point from a location on the bitmap to
*  a location on the screen.
* \param  p Point to transform
* \returns Transformed point
*/
Gdiplus::Point CHeadTop::TransformPoint(Gdiplus::Point p)
{
    // Make p relative to the image center
    p = p - GetCenter();

    // Rotate as needed and offset
    return RotatePoint(p, mPlacedR) + mPlacedPosition;
}

/** Add the channels for this drawable to a timeline
 * \param timeline The timeline class.
 */
void CHeadTop::SetTimeline(CTimeline* timeline)
{
    CDrawable::SetTimeline(timeline);
    timeline->AddChannel(&mPosChannel);
}

/** Set the keyframe based on the current status.
*/
void CHeadTop::SetKeyframe()
{
    CDrawable::SetKeyframe();
    mPosChannel.SetKeyframe(GetPosition());
}

/** Get the current channel from the animation system.
*/
void CHeadTop::GetKeyframe()
{
    CDrawable::GetKeyframe();
    if (mPosChannel.IsValid())
        SetPosition(mPosChannel.GetPosition());
}

/**
 * Draw the head top drawable
 * \param graphics Graphics context to draw on
 */
void CHeadTop::Draw(Gdiplus::Graphics* graphics)
{
    CImageDrawable::Draw(graphics);

    Pen pen(Color::Black, 2);
    SolidBrush brush(Color::Black);

    double x = GetCenter().X;
    double y = GetCenter().Y;

    double xL = x - 12;
    double yL = y - 27;
    double xR = x + 12;
    double yR = y - 27;

    float wid = 15.0f;
    float hit = 20.0f;

    Point p = TransformPoint(Point(xL, yL));
    Point q = TransformPoint(Point(xR, yR));

    auto state = graphics->Save();
    graphics->TranslateTransform(p.X, p.Y);
    graphics->RotateTransform((float)(-mPlacedR * RtoD));
    graphics->FillEllipse(&brush, -wid / 2, -hit / 2, wid, hit);
    graphics->Restore(state);

    state = graphics->Save();
    graphics->TranslateTransform(q.X, q.Y);
    graphics->RotateTransform((float)(-mPlacedR * RtoD));
    graphics->FillEllipse(&brush, -wid / 2, -hit / 2, wid, hit);
    graphics->Restore(state);

    p = TransformPoint(Point(xL - 6, yL - 15));
    q = TransformPoint(Point(xR - 6, yR - 15));

    graphics->DrawLine(&pen, p, Point(p.X + 15 , p.Y));
    graphics->DrawLine(&pen, q, Point(q.X + 15, q.Y));
}



