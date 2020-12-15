/**
 * \file PictureFactory.h
 *
 * \author Charles B. Owen
 *
 * \brief A factory class that builds our picture.
 */

#pragma once

#include <memory>

#include "Picture.h"

class CMachineDrawable;
class CBasketDrawable;

/**
 * \brief A factory class that builds our picture.
 */
class CPictureFactory
{
public:
    CPictureFactory();
    virtual ~CPictureFactory();

    std::shared_ptr<CPicture> Create();

    std::shared_ptr<CMachineDrawable> GetTree1() { return mTree1; }
    std::shared_ptr<CMachineDrawable> GetTree2() { return mMachine2; }
    std::shared_ptr<CBasketDrawable> GetBasket() { return mBasket; }

private:
    std::shared_ptr<CMachineDrawable> mTree1;
    std::shared_ptr<CMachineDrawable> mMachine2;
    std::shared_ptr<CBasketDrawable> mBasket;
};

