/**
 * \file CPictureObserverTest.cpp
 *
 * \author Elizabeth Stevens
 */

#include "pch.h"
#include "CppUnitTest.h"

#include "PictureObserver.h"
#include "Picture.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
    class CPictureObserverMock : public CPictureObserver
    {
    public:
        CPictureObserverMock() : CPictureObserver() {}
        virtual void UpdateObserver() override { mUpdated = true; }
        bool mUpdated = false;
    };

    TEST_CLASS(CPictureObserverTest)
    {
    public:
        TEST_METHOD_INITIALIZE(methodName)
        {
            extern wchar_t g_dir[];
            ::SetCurrentDirectory(g_dir);
        }

        TEST_METHOD(TestCPictureObserverConstruct)
        {
            CPictureObserverMock observer;
        }

        TEST_METHOD(TestCPictureObserverOneObserver)
        {
            // Allocate a CPicture object
            shared_ptr<CPicture> picture = make_shared<CPicture>();

            // Create a mock observer object
            CPictureObserverMock observer;

            // And set it for the observer:
            observer.SetPicture(picture);

            picture->UpdateObservers();

            Assert::IsTrue(observer.mUpdated);
        }

        TEST_METHOD(TestCPictureObserverTwoObservers)
        {
            // Allocate a CPicture object
            shared_ptr<CPicture> picture = make_shared<CPicture>();

            // Create first mock observer object
            CPictureObserverMock observer1;

            // And set it for the observers:
            observer1.SetPicture(picture);

            // The same is done for second observer but destroyed
            // when the block ends
            {
                CPictureObserverMock observer2;

                observer2.SetPicture(picture);

                picture->UpdateObservers();

                // Test UpdateObservers is called on both
                Assert::IsTrue(observer1.mUpdated);
                Assert::IsTrue(observer2.mUpdated);
            }

            picture->UpdateObservers();

            // Test remaining observer works fine
            Assert::IsTrue(observer1.mUpdated);
        }

        TEST_METHOD(TestCPictureObserverGetPicture)
        {
            // Allocate a CPicture object
            shared_ptr<CPicture> picture = make_shared<CPicture>();

            // Create a mock observer object
            CPictureObserverMock observer;

            // And set it for the observer:
            observer.SetPicture(picture);

            Assert::IsTrue(picture == observer.GetPicture());
        }

    };
}
