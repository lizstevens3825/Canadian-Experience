/**
 * \file CDrawableTest.cpp
 *
 * \author Elizabeth Stevens
 */

#include "pch.h"
#include "CppUnitTest.h"

#include "Drawable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Gdiplus;

namespace Testing
{
    class CDrawableMock : public CDrawable
    {
    public:
        CDrawableMock(const std::wstring& name) : CDrawable(name) {}

        virtual void Draw(Gdiplus::Graphics* graphics) override {}
        virtual bool HitTest(Gdiplus::Point pos) override { return false; }

    };

    TEST_CLASS(CDrawableTest)
    {
    public:
        TEST_METHOD_INITIALIZE(methodName)
        {
            extern wchar_t g_dir[];
            ::SetCurrentDirectory(g_dir);
        }

        TEST_METHOD(TestCDrawableConstruct)
        {
            // Create drawable with a name
            CDrawableMock drawable(L"Hand");

            // Test name is correct
            Assert::AreEqual(std::wstring(L"Hand"), drawable.GetName());
        }

        TEST_METHOD(TestCDrawablePosition)
        {
            // Create drawable with a name
            CDrawableMock drawable(L"Hand");

            // Test our default position with getters
            Assert::AreEqual(0, drawable.GetPosition().X);
            Assert::AreEqual(0, drawable.GetPosition().Y);

            // Try setting the position
            drawable.SetPosition(Point(1, 1));

            // Test if our setter worked with getter
            Assert::AreEqual(1, drawable.GetPosition().X);
            Assert::AreEqual(1, drawable.GetPosition().Y);
        }

        TEST_METHOD(TestCDrawableRotation)
        {
            // Create drawable with a name
            CDrawableMock drawable(L"Hand");

            // Test our default rotation with getters
            Assert::AreEqual(0, drawable.GetRotation(), 0.000000001);

            double r = 0.333;

            // Try setting the rotation
            drawable.SetRotation(r);

            // Test if our setter worked with getter
            Assert::AreEqual(r, drawable.GetRotation(), 0.000000001);
        }

        TEST_METHOD(TestCDrawableAssociation)
        {
            CDrawableMock body(L"Body");
            auto arm = std::make_shared<CDrawableMock>(L"Arm");
            auto leg = std::make_shared<CDrawableMock>(L"Leg");

            Assert::IsNull(arm->GetParent());
            Assert::IsNull(leg->GetParent());

            body.AddChild(arm);
            body.AddChild(leg);

            Assert::IsTrue(arm->GetParent() == &body);
            Assert::IsTrue(leg->GetParent() == &body);
        }

    };
}