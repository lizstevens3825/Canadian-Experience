/**
 * \file PictureFactory.cpp
 *
 * \author Elizabeth Stevens
 */

#include "pch.h"

#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "ImageDrawable.h"
#include "CoronaFactory.h"

using namespace Gdiplus;
using namespace std;

 /** Factory method to create a new picture.
 * \returns The created picture
 */
std::shared_ptr<CPicture> CPictureFactory::Create()
{
    shared_ptr<CPicture> picture = make_shared<CPicture>();

    // Create the background and add it
    auto background = make_shared<CActor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(Point(-100, 0));
    auto backgroundI =
        make_shared<CImageDrawable>(L"Background", L"images/Background.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    // Create and add Harold
    CHaroldFactory hFactory;
    auto harold = hFactory.Create();

    // This is where Harold will start out.
    harold->SetPosition(Point(400, 500));

    picture->AddActor(harold);

    // Create and add Corona
    CCoronaFactory cFactory;
    auto corona = cFactory.Create();

    // This is where Corona will start out.
    corona->SetPosition(Point(600, 450));

    picture->AddActor(corona);

    return picture;
}
