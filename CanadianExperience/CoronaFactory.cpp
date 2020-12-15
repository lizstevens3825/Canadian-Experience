/**
 * \file CoronaFactory.cpp
 *
 * \author Elizabeth Stevens
 */

#include "pch.h"

#include "CoronaFactory.h"
#include "Actor.h"
#include "PolyDrawable.h"
#include "ImageDrawable.h"
#include "HeadTop.h"

using namespace std;
using namespace Gdiplus;

/** Constructor */
CCoronaFactory::CCoronaFactory() : CActorFactory()
{
}


/** Destructor */
CCoronaFactory::~CCoronaFactory()
{
}


/** This is a concrete factory method that creates our Corona actor.
 * \returns Pointer to an actor object.
 */
std::shared_ptr<CActor> CCoronaFactory::Create()
{
    shared_ptr<CActor> actor = make_shared<CActor>(L"Corona");

    auto body = make_shared<CImageDrawable>(L"VirusBody", L"images/virus_body.png");
    body->SetCenter(Point(185, 138));
    body->SetPosition(Point(100, 0));
    actor->SetRoot(body);

    auto head = make_shared<CHeadTop>(L"VirusHead", L"images/virus_head.png");
    head->SetCenter(Point(185, 185));
    head->SetPosition(Point(0, -142));
    body->AddChild(head);

    auto larm = make_shared<CPolyDrawable>(L"Left Arm");
    larm->SetColor(Color::Black);
    larm->SetPosition(Point(-120, -130));
    larm->AddPoint(Point(-7, -7));
    larm->AddPoint(Point(-7, 96));
    larm->AddPoint(Point(8, 96));
    larm->AddPoint(Point(8, -7));
    body->AddChild(larm);

    auto rarm = make_shared<CPolyDrawable>(L"Right Arm");
    rarm->SetColor(Color::Black);
    rarm->SetPosition(Point(145, -130));
    rarm->AddPoint(Point(-7, -7));
    rarm->AddPoint(Point(-7, 96));
    rarm->AddPoint(Point(8, 96));
    rarm->AddPoint(Point(8, -7));
    body->AddChild(rarm);

    auto lleg = make_shared<CPolyDrawable>(L"Left Leg");
    lleg->SetColor(Color::Black);
    lleg->SetPosition(Point(-45, -20));
    lleg->AddPoint(Point(-7, -7));
    lleg->AddPoint(Point(-7, 96));
    lleg->AddPoint(Point(8, 96));
    lleg->AddPoint(Point(8, -7));
    body->AddChild(lleg);

    auto rleg = make_shared<CPolyDrawable>(L"Right Leg");
    rleg->SetColor(Color::Black);
    rleg->SetPosition(Point(65, -20));
    rleg->AddPoint(Point(-7, -7));
    rleg->AddPoint(Point(-7, 96));
    rleg->AddPoint(Point(8, 96));
    rleg->AddPoint(Point(8, -7));
    body->AddChild(rleg);

    actor->AddDrawable(body);
    actor->AddDrawable(head);
    actor->AddDrawable(larm);
    actor->AddDrawable(rarm);
    actor->AddDrawable(lleg);
    actor->AddDrawable(rleg);

    return actor;
}