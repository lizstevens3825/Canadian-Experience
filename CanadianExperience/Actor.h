/**
 * \file Actor.h
 *
 * \author Elizabeth Stevens
 *
 * Class for actors in our drawings.
 */

#pragma once

#include <string>
#include <memory>
#include <vector>
#include "Drawable.h"
#include "AnimChannelPosition.h"

class CPicture;

 /**
  * Class for actors in our drawings.
  *
  * An actor is some graphical object that consists of
  * one or more parts. Actors can be animated.
  */
class CActor
{
public:
    CActor(const std::wstring& name);

    /** Default constructor disabled */
    CActor() = delete;
    /** Copy constructor disabled */
    CActor(const CActor&) = delete;
    /** Assignment operator disabled */
    void operator=(const CActor&) = delete;

    virtual ~CActor();

    void SetRoot(std::shared_ptr<CDrawable> root);
    void Draw(Gdiplus::Graphics* graphics);
    std::shared_ptr<CDrawable> HitTest(Gdiplus::Point pos);
    void AddDrawable(std::shared_ptr<CDrawable> drawable);
    void SetPicture(CPicture* picture);
    void SetKeyframe();
    void GetKeyframe();

    /** Get the actor position channel
     * \returns Pointer to the position channel */
    CAnimChannelPosition* GetPositionChannel() { return &mChannel; }

    /** Get the actor name
     * \returns Actor name */
    std::wstring GetName() const { return mName; }

    /** The actor position
    * \returns The actor position as a point */
    Gdiplus::Point GetPosition() const { return mPosition; }

    /** The actor position
    * \param pos The new actor position */
    void SetPosition(Gdiplus::Point pos) { mPosition = pos; }

    /** The actor picture
    * \returns The actor picture */
    CPicture* GetPicture() { return mPicture; }

    /** Actor is enabled
    * \returns enabled status */
    bool IsEnabled() const { return mEnabled; }

    /** Set Actor Enabled
    * \param enabled New enabled status */
    void SetEnabled(bool enabled) { mEnabled = enabled; }

    /** Actor is clickable
    * \returns true if actor is clickable */
    bool IsClickable() const { return mClickable; }

    /** Actor clickable
    * \param clickable New clickable status */
    void SetClickable(bool clickable) { mClickable = clickable; }

private:
    /// The animation channel for animating the position of this actor
    CAnimChannelPosition mChannel;

    /// The picture associate with this actor
    CPicture* mPicture = nullptr;

    /// The root drawable
    std::shared_ptr<CDrawable> mRoot;

    /// The drawables in drawing order
    std::vector<std::shared_ptr<CDrawable>> mDrawablesInOrder;

    /// Name of our actor
    std::wstring mName;

    /// Actor's status
    bool mEnabled = true;

    /// Position of the actor
    Gdiplus::Point mPosition = Gdiplus::Point(0, 0);

    /// Indicates if Actor is clickable
    bool mClickable = true;
};

