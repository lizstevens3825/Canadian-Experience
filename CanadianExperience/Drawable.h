/**
 * \file Drawable.h
 *
 * \author Elizabeth Stevens
 *
 * Abstract base class for drawable elements of our picture.
 */

#pragma once

#include <string>
#include <memory>
#include <vector>
#include "AnimChannelAngle.h"

class CActor;

 /**
  * Abstract base class for drawable elements of our picture.
  *
  * A drawable is one part of an actor. Drawable parts can be moved
  * independently.
  */
class CDrawable
{
public:
    virtual ~CDrawable();

    /** Default constructor disabled */
    CDrawable() = delete;
    /** Copy constructor disabled */
    CDrawable(const CDrawable&) = delete;
    /** Assignment operator disabled */
    void operator=(const CDrawable&) = delete;

    void SetActor(CActor* actor);
    void Place(Gdiplus::Point offset, double rotate);
    void AddChild(std::shared_ptr<CDrawable> child);
    void Move(Gdiplus::Point delta);
    virtual void SetTimeline(CTimeline* timeline);
    virtual void SetKeyframe();
    virtual void GetKeyframe();

    /**
     * Draw the drawable
     * \param graphics Graphics context to draw on
     */
    virtual void Draw(Gdiplus::Graphics* graphics) = 0;

    /**
     * Test to see if we clicked on the drawable.
     * \param pos Position to test
     * \returns True if clicked on
     */
    virtual bool HitTest(Gdiplus::Point pos) = 0;

    /** Set the drawing to not be moveable
     * \returns boolean indicating not moveable*/
    virtual bool IsMovable() { return false; }

    /** Set the drawable position
     * \param pos The new drawable position*/
    void SetPosition(Gdiplus::Point pos) { mPosition = pos; }

    /** Get the drawable position
     * \returns The drawable position*/
    Gdiplus::Point GetPosition() const { return mPosition; }

    /** Set the rotation angle in radians
    * \param r The new rotation angle in radians*/
    void SetRotation(double r) { mRotation = r; }

    /** Get the rotation angle in radians
    * \returns The rotation angle in radians*/
    double GetRotation() const { return mRotation; }

    /** Get the drawable name
    * \returns The drawable name */
    std::wstring GetName() const { return mName; }

    /** Set the drawable parent
    * \param parent The drawable parent */
    void SetParent(CDrawable* parent) { mParent = parent; }

    /** Get the drawable parent
    * \returns The drawable parent */
    CDrawable* GetParent() { return mParent; }

    /** The angle animation channel
    * \returns Pointer to animation channel */
    CAnimChannelAngle* GetAngleChannel() { return &mChannel; }

protected:
    CDrawable(const std::wstring& name);
    Gdiplus::Point RotatePoint(Gdiplus::Point point, double angle);

    /// The actual postion in the drawing
    Gdiplus::Point mPlacedPosition = Gdiplus::Point(0, 0);

    /// The actual rotation in the drawing
    double mPlacedR = 0;

private:
    /// The animation channel for animating the angle of this drawable
    CAnimChannelAngle mChannel;

    /// The parent drawable of this drawable
    CDrawable* mParent = nullptr;

    /// The children drawables of this parent drawable
    std::vector<std::shared_ptr<CDrawable>> mChildren;

    /// The actor using this drawable
    CActor* mActor = nullptr;

    /// The drawable name
    std::wstring mName;

    /// The position of this drawable relative to its parent
    Gdiplus::Point mPosition = Gdiplus::Point(0, 0);

    /// The rotation of this drawable relative to its parent
    double mRotation = 0;
};

