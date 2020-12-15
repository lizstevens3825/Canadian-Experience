/**
 * \file AnimChannelPosition.h
 *
 * \author Elizabeth Stevens
 *
 * Animation channel for position.
 */

#pragma once
#include "AnimChannel.h"

/**
 * Animation channel for position.
 */
class CAnimChannelPosition : public CAnimChannel
{
public:
    CAnimChannelPosition();
    virtual ~CAnimChannelPosition();

    /** Copy constructor disabled */
    CAnimChannelPosition(const CAnimChannelPosition&) = delete;
    /** Assignment operator disabled */
    void operator=(const CAnimChannelPosition&) = delete;

    /** Get the animation channel position
    * \returns Animation channel position */
    Gdiplus::Point GetPosition() const { return mPosition; }

    void SetKeyframe(Gdiplus::Point position);

    /** Class that represents a keyframe position */
    class KeyframePosition : public Keyframe
    {
    public:
        /** Constructor
         * \param channel The channel we are for
         * \param position The position for the keyframe */
        KeyframePosition(CAnimChannelPosition* channel, Gdiplus::Point position) :
            Keyframe(channel), mChannel(channel), mPosition(position) {}

        /** Default constructor disabled */
        KeyframePosition() = delete;
        /** Copy constructor disabled */
        KeyframePosition(const KeyframePosition&) = delete;
        /** Assignment operator disabled */
        void operator=(const KeyframePosition&) = delete;

        /** Get the keyframe position
        * \returns The Keyframe position */
        Gdiplus::Point GetPosition() const { return mPosition; }

        /** Use this keyframe as keyframe 1 */
        virtual void UseAs1() override { mChannel->mKeyframe1 = this; }

        /** Use this keyframe as keyfraem 2 */
        virtual void UseAs2() override { mChannel->mKeyframe2 = this; }

        /** Use this keyframe as the position */
        virtual void UseOnly() override { mChannel->mPosition = mPosition; }

    private:
        /// The keyframe position
        Gdiplus::Point mPosition;

        /// The channel this keyframe is associated with
        CAnimChannelPosition* mChannel;
    };

protected:
    virtual void Tween(double t) override;

private:
    /// The position at which the animation channel is
    Gdiplus::Point mPosition = Gdiplus::Point(0,0);

    /// The first position keyframe
    KeyframePosition* mKeyframe1 = nullptr;

    /// The second position keyframe
    KeyframePosition* mKeyframe2 = nullptr;
};

