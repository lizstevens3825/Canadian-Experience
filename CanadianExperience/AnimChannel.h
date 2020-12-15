/**
 * \file AnimChannel.h
 *
 * \author Elizabeth Stevens
 *
 * Base class for animation channels
 */

#pragma once

#include <string>
#include <vector>
#include <memory>

class CTimeline;

/**
 * Base class for animation channels
 *
 * This class provides basic functionality and a polymorphic
 * representation for animation channels.
 */
class CAnimChannel
{
public:
    CAnimChannel();
    virtual ~CAnimChannel();

    /** Copy constructor disabled */
    CAnimChannel(const CAnimChannel&) = delete;
    /** Assignment operator disabled */
    void operator=(const CAnimChannel&) = delete;

    bool IsValid();
    void SetFrame(int currFrame);
    void DeleteKeyframe(int currFrame);

    /** Set the animation channel name
    * \param name The animation channel name */
    void SetName(const std::wstring& name) { mName = name; }

    /** Get the animation channel name
     * \returns Animation channel name */
    std::wstring GetName() const { return mName; }

    /** Set the timeline for this animation channel
    * \param timeline The timeline */
    void SetTimeline(CTimeline* timeline) { mTimeline = timeline; }

    /** Get the timeline for this animation channel
     * \returns The timeline */
    CTimeline* GetTimeline() const { return mTimeline; }

    /** Class that represents a keyframe */
    class Keyframe
    {
    public:
        /** Default constructor disabled */
        Keyframe() = delete;
        /** Copy constructor disabled */
        Keyframe(const Keyframe&) = delete;
        /** Assignment operator disabled */
        void operator=(const Keyframe&) = delete;

        /** Use as first Keyframe */
        virtual void UseAs1() {}

        /** Use as second Keyframe */
        virtual void UseAs2() {}

        /** Only use this Keyframe */
        virtual void UseOnly() {}

        /** Get the frame of this keyframe
         * \return The frame */
        int GetFrame() { return mFrame; }

        /** Set the frame for this keyframe
         * \param currFrame The current frame */
        void SetFrame(int currFrame) { mFrame = currFrame; }

    protected:
        /** Constructor
        * \param channel Channel we are associated with */
        Keyframe(CAnimChannel* channel) : mChannel(channel) {}

        /// The frame this keyframe is associated with
        int mFrame;

    private:
        /// The channel this keyframe is associated with
        CAnimChannel* mChannel;
    };

protected:
    void InsertKeyframe(std::shared_ptr<Keyframe> keyframe);

    /** Tween the animation
     * \param t Tweening by this variable */
    virtual void Tween(double t) = 0;

private:
    /// The timeline object
    CTimeline* mTimeline = nullptr;

    /// The collection of keyframes for this channel
    std::vector<std::shared_ptr<Keyframe>> mKeyframes;

    std::wstring mName;     ///< The channel name
    int mKeyframe1 = -1;    ///< The first keyframe
    int mKeyframe2 = -1;    ///< The second keyframe
};

