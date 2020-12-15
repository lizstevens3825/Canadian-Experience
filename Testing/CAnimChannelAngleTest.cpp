/**
 * \file CAnimChannelAngleTest.cpp
 *
 * \author Elizabeth Stevens
 */

#include "pch.h"
#include "CppUnitTest.h"

#include "AnimChannelAngle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
    TEST_CLASS(CAnimChannelAngleTest)
    {
    public:
        TEST_METHOD_INITIALIZE(methodName)
        {
            extern wchar_t g_dir[];
            ::SetCurrentDirectory(g_dir);
        }

        TEST_METHOD(TestCAnimChannelAngleConstruct)
        {
            CAnimChannelAngle animChannelAngle;
        }

        TEST_METHOD(TestCAnimChannelAngleName)
        {
            CAnimChannelAngle animChannelAngle;

            // Test deafult name is correct
            Assert::AreEqual(std::wstring(L""), animChannelAngle.GetName());

            // Set the name
            animChannelAngle.SetName(L"something");

            // Test deafult name is correct
            Assert::AreEqual(std::wstring(L"something"), animChannelAngle.GetName());
        }

    };
}