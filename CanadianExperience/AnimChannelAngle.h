/**
 * \file AnimChannelAngle.h
 *
 * \author Elizabeth Stevens
 *
 * Animation channel for angles.
 */

#pragma once

#include "AnimChannel.h"

/**
 * Animation channel for angles.
 */
class CAnimChannelAngle : public CAnimChannel
{
public:
    CAnimChannelAngle();
    virtual ~CAnimChannelAngle();

    /** Copy constructor disabled */
    CAnimChannelAngle(const CAnimChannelAngle&) = delete;
    /** Assignment operator disabled */
    void operator=(const CAnimChannelAngle&) = delete;

    /** Get the animation channel angle
     * \returns Animation channel angle */
    double GetAngle() const { return mAngle; }

    void SetKeyframe(double angle);

    /** Class that represents a keyframe angle */
    class KeyframeAngle : public Keyframe
    {
    public:
        /** Constructor
         * \param channel The channel we are for
         * \param angle The angle for the keyframe */
        KeyframeAngle(CAnimChannelAngle* channel, double angle) :
            Keyframe(channel), mChannel(channel), mAngle(angle) {}

        /** Default constructor disabled */
        KeyframeAngle() = delete;
        /** Copy constructor disabled */
        KeyframeAngle(const KeyframeAngle&) = delete;
        /** Assignment operator disabled */
        void operator=(const KeyframeAngle&) = delete;

        /** Get the keyframe angle
        * \returns The Keyframe angle */
        double GetAngle() const { return mAngle; }

        /** Use this keyframe as keyframe 1 */
        virtual void UseAs1() override { mChannel->mKeyframe1 = this; }

        /** Use this keyframe as keyframe 2 */
        virtual void UseAs2() override { mChannel->mKeyframe2 = this; }

        /** Use this keyframe as the angle */
        virtual void UseOnly() override { mChannel->mAngle = mAngle; }

    private:
        /// The keyframe angle
        double mAngle;

        /// The channel this keyframe is associated with
        CAnimChannelAngle* mChannel;
    };

protected:
    virtual void Tween(double t) override;

private:
    /// The angle at which the animation channel is
    double mAngle = 0;

    /// The first angle keyframe
    KeyframeAngle* mKeyframe1 = nullptr;

    /// The second angle keyframe
    KeyframeAngle* mKeyframe2 = nullptr;

};

