
/*
    Copyright (c) 2011 Andrew Hankinson, Alastair Porter, Jamie Klassen, Mahtab Ghamsari-Esfahani
    
    Permission is hereby granted, free of charge, to any person obtaining
    a copy of this software and associated documentation files (the
    "Software"), to deal in the Software without restriction, including
    without limitation the rights to use, copy, modify, merge, publish,
    distribute, sublicense, and/or sell copies of the Software, and to
    permit persons to whom the Software is furnished to do so, subject to
    the following conditions:
    
    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
    LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
    OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef LINKALIGNMIXIN_H_
#define LINKALIGNMIXIN_H_

#include "meielement.h"
#include "exceptions.h"



struct AlignmentMixIn {
    AlignmentMixIn(BaseMeiElement *b);
    virtual ~AlignmentMixIn() {};
    
    /** \brief   indicates the point of occurrence of this feature along a time line. Its value
    * must be the ID of a <when> element.
    */

    string getWhenValue() throw (AttributeNotFoundException);
    MeiAttribute* getWhen() throw (AttributeNotFoundException);
    void setWhen(std::string _when);
    bool hasWhen();
    void removeWhen();

    private:
        BaseMeiElement *b;
};


#endif // LINKALIGNMIXIN_H_