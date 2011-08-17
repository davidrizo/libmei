
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

#ifndef LYRICSMIXIN_H_
#define LYRICSMIXIN_H_

#include "meielement.h"
#include "exceptions.h"



struct VerseLogMixIn {
    VerseLogMixIn(BaseMeiElement *b);
    virtual ~VerseLogMixIn() {};
    
    /** \brief   used to indicate a common, usually centered, refrain (Mup User's Guide, p. 44).
    */

    string getRefrainValue() throw (AttributeNotFoundException);
    MeiAttribute* getRefrain() throw (AttributeNotFoundException);
    void setRefrain(std::string _refrain);
    bool hasRefrain();
    void removeRefrain();

    /** \brief   used to specify a rhythm for the lyric syllables that differs from that of the
    * notes on the staff, e.g. '4,4,4,4' when the rhythm of the notes is '4.,8,4.,8'.
    */

    string getRhythmValue() throw (AttributeNotFoundException);
    MeiAttribute* getRhythm() throw (AttributeNotFoundException);
    void setRhythm(std::string _rhythm);
    bool hasRhythm();
    void removeRhythm();

    private:
        BaseMeiElement *b;
};


#endif // LYRICSMIXIN_H_