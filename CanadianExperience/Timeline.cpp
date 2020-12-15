/**
 * \file Timeline.cpp
 *
 * \author Elizabeth Stevens
 */

#include "pch.h"
#include "Timeline.h"
#include "AnimChannel.h"

/** Default constructor */
CTimeline::CTimeline()
{
}

/** Function to add a channel to this timeline
* \param channel The channel to add */
void CTimeline::AddChannel(CAnimChannel* channel)
{
    mChannels.push_back(channel);
    channel->SetTimeline(this);
}

/** Deletes the keyframe
*
* Ensures all of the keyframes are
* adjusted accordingly for the channels
*/
void CTimeline::DeleteKeyframe()
{
    for (auto channel : mChannels)
    {
        channel->DeleteKeyframe(GetCurrentFrame());
    }
}

/** Sets the current time
*
* Ensures all of the channels are
* valid for that point in time.
* \param t Calculated time
*/
void CTimeline::SetCurrentTime(double t)
{
    // Set the time
    mCurrentTime = t;

    for (auto channel : mChannels)
    {
        channel->SetFrame(GetCurrentFrame());
    }
}
