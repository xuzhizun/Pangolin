/* This file is part of the Pangolin Project.
 * http://github.com/stevenlovegrove/Pangolin
 *
 * Copyright (c) 2011 Steven Lovegrove
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef PANGOLIN_VIDEO_H
#define PANGOLIN_VIDEO_H

#include "pangolin.h"

namespace pangolin
{

    struct VideoException : std::exception
    {
        VideoException(std::string str) : desc(str) {}
        VideoException(std::string str, std::string detail) {
            desc = str + "\n\t" + detail;
        }
        ~VideoException() throw() {}
        const char* what() const throw() { return desc.c_str(); }
        std::string desc;
    };

    //! Interface to video capture sources
    struct VideoSource
    {
        virtual unsigned Width() const = 0;
        virtual unsigned Height() const = 0;

        virtual void Start() = 0;
        virtual void Stop() = 0;

        //! Copy the next frame from the camera to image.
        //! Optionally wait for a frame if one isn't ready
        //! Returns true iff image was copied
        virtual bool GrabNext( unsigned char* image, bool wait = true ) = 0;

        //! Copy the newest frame from the camera to image
        //! discarding all older frames.
        //! Optionally wait for a frame if one isn't ready
        //! Returns true iff image was copied
        virtual bool GrabNewest( unsigned char* image, bool wait = true ) = 0;
    };

}

#endif // PANGOLIN_VIDEO_H
