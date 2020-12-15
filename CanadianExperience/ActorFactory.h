/**
 * \file ActorFactory.h
 *
 * \author Elizabeth Stevens
 *
 * Abstract base class for actor factories.
 */

#pragma once

#include <memory>

class CActor;

/**
 * Abstract base class for actor factories.
 */
class CActorFactory
{
public:
    virtual ~CActorFactory();

    /** Default constructor */
    CActorFactory() {}
    /** \brief Copy constructor disabled */
    CActorFactory(const CActorFactory&) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CActorFactory&) = delete;

    /** This is a concrete factory method that creates our actor.
     * \returns Pointer to an actor object.
     */
    virtual std::shared_ptr<CActor> Create() = 0;
};

