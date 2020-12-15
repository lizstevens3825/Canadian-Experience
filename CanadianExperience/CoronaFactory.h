/**
 * \file CoronaFactory.h
 *
 * \author Elizabeth Stevens
 *
 * Factory class that builds the Corona character
 */

#pragma once

#include "ActorFactory.h"

 /**
  * Factory class that builds the Corona character
  */
class CCoronaFactory : public CActorFactory
{
public:
    virtual ~CCoronaFactory();
    CCoronaFactory();
    /** Copy constructor disabled */
    CCoronaFactory(const CCoronaFactory&) = delete;
    /** Assignment operator disabled */
    void operator=(const CCoronaFactory&) = delete;

    virtual std::shared_ptr<CActor> Create() override;
};

