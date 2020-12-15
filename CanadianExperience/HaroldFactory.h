/**
 * \file HaroldFactory.h
 *
 * \author Elizabeth Stevens
 *
 * Factory class that builds the Harold character
 */

#pragma once

#include "ActorFactory.h"

/**
 * Factory class that builds the Harold character
 */
class CHaroldFactory : public CActorFactory
{
public:
    virtual ~CHaroldFactory();
    CHaroldFactory();
    /** Copy constructor disabled */
    CHaroldFactory(const CHaroldFactory&) = delete;
    /** Assignment operator disabled */
    void operator=(const CHaroldFactory&) = delete;

    virtual std::shared_ptr<CActor> Create() override;
};

