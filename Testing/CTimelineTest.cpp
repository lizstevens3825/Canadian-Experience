/**
 * \file CTimelineTest.cpp
 *
 * \author Elizabeth Stevens
 */

#include "pch.h"
#include "CppUnitTest.h"
#include "Timeline.h"
#include "AnimChannelAngle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Gdiplus;

namespace Testing
{
    TEST_CLASS(CTimelineTest)
    {
    public:
        TEST_METHOD_INITIALIZE(methodName)
        {
            extern wchar_t g_dir[];
            ::SetCurrentDirectory(g_dir);
        }

        TEST_METHOD(TestCTimelineConstruct)
        {
            CTimeline timeline;
        }

        TEST_METHOD(TestCTimelineFrameNumber)
        {
            CTimeline timeline;

            // Default value
            Assert::AreEqual(300, timeline.GetNumFrames());

            // Changed frame number
            timeline.SetNumFrames(400);
            Assert::AreEqual(400, timeline.GetNumFrames());
        }

        TEST_METHOD(TestCTimelineFrameRate)
        {
            CTimeline timeline;

            // Default value
            Assert::AreEqual(30, timeline.GetFrameRate());

            // Changed frame rate
            timeline.SetFrameRate(40);
            Assert::AreEqual(40, timeline.GetFrameRate());
        }

        TEST_METHOD(TestCTimelineCurrentTime)
        {
            CTimeline timeline;

            // Default value
            Assert::AreEqual(0, timeline.GetCurrentTime(), 0.0001);

            // Changed current time
            timeline.SetCurrentTime(10);
            Assert::AreEqual(10, timeline.GetCurrentTime(), 0.0001);
        }

        TEST_METHOD(TestCTimelineGetDuration)
        {
            CTimeline timeline;

            // Default value
            Assert::AreEqual(10, timeline.GetDuration(), 0.0001);

            // Changed duration
            timeline.SetFrameRate(375);
            Assert::AreEqual(300.0 / 375.0, timeline.GetDuration(), 0.0001);

            timeline.SetNumFrames(789);
            Assert::AreEqual(789.0 / 375.0, timeline.GetDuration(), 0.0001);
        }

        TEST_METHOD(TestCTimelineGetCurrentFrame)
        {
            CTimeline timeline;

            // Default value
            Assert::AreEqual(0, timeline.GetCurrentFrame());

            // Changed time
            timeline.SetCurrentTime(9.27);
            Assert::AreEqual(278, timeline.GetCurrentFrame());
        }

        TEST_METHOD(TestCTimelineAdd)
        {
            CTimeline timeline;
            CAnimChannelAngle channel;

            timeline.AddChannel(&channel);
            Assert::IsTrue(&timeline == channel.GetTimeline());
        }

        TEST_METHOD(TestCTimelineDeleteKeyframe)
        {
            CTimeline timeline;
            CAnimChannelAngle channel;
            timeline.AddChannel(&channel);

        }
    };
}