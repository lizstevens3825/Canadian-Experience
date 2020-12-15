/**
 * \file Picture.h
 *
 * \author Elizabeth Stevens
 *
 * The picture we are drawing.
 */

#pragma once

#include <vector>
#include <memory>
#include "PictureObserver.h"
#include "Actor.h"
#include "Timeline.h"

 /**
  * The picture we are drawing.
  *
  * There will be one picture object that contains all of
  * our actors, which then contains the drawables.
  */
class CPicture
{
public:
    /// Constructor
    CPicture() {}
    /// Destructor
    virtual ~CPicture() {}

    /// Copy Constructor (Disabled)
    CPicture(const CPicture&) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const CPicture&) = delete;

    /** The picture size
    * \returns Size */
    Gdiplus::Size GetSize() { return mSize; }

    /** The picture size
    * \param size The new picture size */
    void SetSize(Gdiplus::Size size) { mSize = size; }

    void AddObserver(CPictureObserver* observer);
    void RemoveObserver(CPictureObserver* observer);
    void UpdateObservers();
    void AddActor(std::shared_ptr<CActor> actor);
    void Draw(Gdiplus::Graphics* graphics);
    void SetAnimationTime(double time);

    /** Get a pointer to the Timeline object
    * \returns Pointer to the Timeline object
    */
    CTimeline* GetTimeline() { return &mTimeline; }

    /** Iterator that iterates over the Picture actors */
    class ActorIter
    {
    public:
        /** Constructor
         * \param pos The position in the collection
         * \param picture The Picture we are iterating over */
        ActorIter(CPicture* picture, int pos) : mPicture(picture), mPos(pos) {}

        /** Test for end of the iterator
         * \param other The iterator
         * \returns True if we this position equals not equal to the other position */
        bool operator!=(const ActorIter& other) const
        {
            return mPos != other.mPos;
        }

        /** Get value at current position
         * \returns Value at mPos in the collection */
        std::shared_ptr<CActor> operator *() const { return mPicture->mActors[mPos]; }

        /** Increment the iterator
         * \returns Reference to this iterator */
        const ActorIter& operator++()
        {
            mPos++;
            return *this;
        }


    private:
        CPicture* mPicture;   ///< Picture we are iterating over
        int mPos;       ///< Position in the collection
    };

    /** Get an iterator for the beginning of the collection
     * \returns Iter object at position 0 */
    ActorIter begin() { return ActorIter(this, 0); }

    /** Get an iterator for the end of the collection
     * \returns Iter object at position past the end */
    ActorIter end() { return ActorIter(this, mActors.size()); }

private:
    /// The picture size
    Gdiplus::Size mSize = Gdiplus::Size(800, 600);

    /// The observers of this picture
    std::vector<CPictureObserver*> mObservers;

    /// The actors of this picture
    std::vector<std::shared_ptr<CActor>> mActors;

    /// The animation timeline
    CTimeline mTimeline;
};

