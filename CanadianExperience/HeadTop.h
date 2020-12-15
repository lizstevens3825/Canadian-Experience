/**
 * \file HeadTop.h
 *
 * \author Elizabeth Stevens
 *
 * A drawable of the head top based on images.
 */

#pragma once

#include "ImageDrawable.h"
#include "AnimChannelPosition.h"

 /**
  * A drawable of the head based on images.
  *
  * This class has a list of points and draws a head top
  * drawable based on those points.
  */
class CHeadTop : public CImageDrawable
{
public:
    virtual ~CHeadTop();

    /** Default constructor disabled */
    CHeadTop() = delete;
    /** Copy constructor disabled */
    CHeadTop(const CHeadTop&) = delete;
    /** Assignment operator disabled */
    void operator=(const CHeadTop&) = delete;

    CHeadTop(const std::wstring& name, const std::wstring& filename);
    void Draw(Gdiplus::Graphics* graphics) override;
    Gdiplus::Point TransformPoint(Gdiplus::Point p);
    virtual void SetTimeline(CTimeline* timeline);
    virtual void SetKeyframe() override;
    virtual void GetKeyframe() override;

    /** Set the drawing to not be moveable
    * \returns boolean indicating not moveable*/
    bool IsMovable() override { return true; }

private:
    /// The animation channel for animating the position of this drawable
    CAnimChannelPosition mPosChannel;
};

