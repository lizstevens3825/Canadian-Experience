/**
 * \file PictureFactory.h
 *
 * \author Elizabeth Stevens
 *
 * A factory class that builds our picture.
 */

#pragma once

#include <memory>

class CPicture;

/**
 * A factory class that builds our picture.
 */
class CPictureFactory
{
public:
    /** Default constructor */
    CPictureFactory() {}
    /** Default destructor */
    ~CPictureFactory() {}
    /** Copy constructor disabled */
    CPictureFactory(const CPictureFactory&) = delete;
    /** Assignment operator disabled */
    void operator=(const CPictureFactory&) = delete;

    std::shared_ptr<CPicture> Create();
};

