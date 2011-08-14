/*
    Copyright (c) 2011 Jamie Klassen, Alastair Porter, Mahtab Ghamsari-Esfahani, Andrew Hankinson

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
    
#ifndef EDITTRANS_H_
#define EDITTRANS_H_

#include "facsimilemixins.h"
#include "sharedmixins.h"
#include "critappmixins.h"
#include "edittransmixins.h"
using namespace std;
/** \brief  addition ― Marks an addition to the text.
 *
 * The add element contains material inserted by an author, scribe, annotator, or          
 *          corrector. The agent responsible for the addition may be encoded using the hand          
 *          attribute, while the resp attribute records the editor or transcriber          
 *          responsible for identifying the hand of the addition. The cert attribute          
 *          signifies the degree of certainty ascribed to the identification of the hand of          
 *          the addition. The editor(s) responsible for asserting this particular reading          
 *          may be recorded in the resp attribute. The value of resp must point to one or          
 *          more identifiers declared in the document header. This element is modelled on an          
 *          element in the Text Encoding Initiative (TEI)..
 */
struct Add : public BaseMeiElement{
    Add();
    virtual ~Add() {};

    CommonMixIn    m_Common;
    EditMixIn    m_Edit;
    TransMixIn    m_Trans;
    FacsimileMixIn    m_Facsimile;
    private:
        //REGISTER_DECLARATION(Add);
};

/** \brief  choice ― Groups a number of alternative encodings for the same point in a text.
 *
 * Because the children of a choice element all represent alternative ways of          
 *          encoding the same sequence, it is natural to think of them as mutually          
 *          exclusive. However, there may be cases where a full representation of a text          
 *          requires the alternative encodings to be considered as parallel. Note also that          
 *          choice elements may be recursively nested. This element is modelled on an          
 *          element in the Text Encoding Initiative (TEI)..
 */
struct Choice : public BaseMeiElement{
    Choice();
    virtual ~Choice() {};

    CommonMixIn    m_Common;
    private:
        //REGISTER_DECLARATION(Choice);
};

/** \brief  correction ― Contains the correct form of an apparent erroneous passage.
 *
 * The cert attribute signifies the degree of certainty ascribed to correction. The          
 *          resp attribute contains an ID reference to an element containing the name of the          
 *          editor or transcriber responsible for suggesting the correction held as the          
 *          content of the <corr> element. If the correction was made in the source, resp          
 *          should be used to identify the hand of the corrector. The value of resp must          
 *          point to one or more identifiers declared in the document header. This element          
 *          is modelled on an element in the Text Encoding Initiative (TEI)..
 */
struct Corr : public BaseMeiElement{
    Corr();
    virtual ~Corr() {};

    CommonMixIn    m_Common;
    EditMixIn    m_Edit;
    TransMixIn    m_Trans;
    private:
        //REGISTER_DECLARATION(Corr);
};

/** \brief  damage ― Contains an area of damage to the carrier.
 *
 * In the case of damage resulting from an identifiable cause, the agent attribute          
 *          signifies the causative agent. The degree attribute signifies the degree of          
 *          damage according to a convenient scale. A <damage> tag with this attribute          
 *          should only be used where the text may be read with some confidence; data          
 *          supplied from other sources should be tagged as <supplied>. The extent attribute          
 *          indicates approximately how much text is in the damaged area, in notes,          
 *          measures, inches, or any appropriate unit, where this cannot be deduced from the          
 *          contents of the tag. For example, the damage may span structural divisions in          
 *          the text so that the tag must then be empty of content. In the case of damage          
 *          (deliberate defacement, etc.) assignable to an identifiable hand, the hand          
 *          attribute signifies the hand responsible for the damage. This element is          
 *          modelled on an element in the Text Encoding Initiative (TEI)..
 */
struct Damage : public BaseMeiElement{
    Damage();
    virtual ~Damage() {};

    string getDegreeValue() throw (AttributeNotFoundException);

    MeiAttribute* getDegree() throw (AttributeNotFoundException);
    void setDegree(string _degree);
    bool hasDegree();

    CommonMixIn    m_Common;
    HandidentMixIn    m_Handident;
    TypedMixIn    m_Typed;
    CritMixIn    m_Crit;
    AgentidentMixIn    m_Agentident;
    ExtentMixIn    m_Extent;
    TransMixIn    m_Trans;
    FacsimileMixIn    m_Facsimile;
    private:
        //REGISTER_DECLARATION(Damage);
};

/** \brief  deletion ― Contains information deleted, marked as deleted, or otherwise
 *          indicated as superfluous or spurious in the copy text by an author,
 *          scribe, annotator, or corrector.
 *
 * The resp attribute contains an ID reference to an element containing the name of          
 *          the editor or transcriber responsible for identifying the hand of the deletion.          
 *          The cert attribute signifies the degree of certainty ascribed to the          
 *          identification of the hand of the deletion. The hand of the agent which made the          
 *          deletion should be pointed to using the hand attribute. The rend attribute may          
 *          be used to record the method used to make the deletion (overstrike,          
 *          strike[through], etc.) or how the deleted matter should be displayed. This          
 *          element is modelled on an element in the Text Encoding Initiative (TEI)..
 */
struct Del : public BaseMeiElement{
    Del();
    virtual ~Del() {};

    string getRendValue() throw (AttributeNotFoundException);

    MeiAttribute* getRend() throw (AttributeNotFoundException);
    void setRend(string _rend);
    bool hasRend();

    CommonMixIn    m_Common;
    TransMixIn    m_Trans;
    FacsimileMixIn    m_Facsimile;
    private:
        //REGISTER_DECLARATION(Del);
};

/** \brief  gap ― Indicates a point where material has been omitted in a transcription,
 *          whether as part of sampling practice or for editorial reasons
 *          described in the MEI header.
 *
 * When material is omitted because it is illegible or inaudible, <unclear> should          
 *          be used instead. Similarly, use <damage> if the omission is due to damage and          
 *          <del> if the omission is because the material is marked as deleted, or otherwise          
 *          indicated as superfluous or spurious in the copy text by an author, scribe,          
 *          annotator, or corrector. An indication of how much material has been omitted          
 *          from the transcription may be recorded in the extent attribute. The unit          
 *          attribute names the unit used for describing the extent of the gap. The reason          
 *          attribute gives the reason for omission. Sample values include 'sampling',          
 *          'irrelevant', 'cancelled'. The resp attribute contains an ID reference to an          
 *          element containing the name of the editor, transcriber or encoder responsible          
 *          for the decision not to provide any transcription of the material and hence the          
 *          application of the <gap> tag. The hand attribute signifies the hand which made          
 *          the deletion in the case of text omitted from the transcription because of          
 *          deliberate deletion by an identifiable hand. The cert attribute signifies the          
 *          degree of certainty ascribed to the identification of the extent of the missing          
 *          material. This element is modelled on an element in the Text Encoding Initiative          
 *          (TEI)..
 */
struct Gap : public BaseMeiElement{
    Gap();
    virtual ~Gap() {};

    CommonMixIn    m_Common;
    HandidentMixIn    m_Handident;
    MeasurementMixIn    m_Measurement;
    CritMixIn    m_Crit;
    ExtentMixIn    m_Extent;
    ReasonidentMixIn    m_Reasonident;
    EditMixIn    m_Edit;
    TransMixIn    m_Trans;
    private:
        //REGISTER_DECLARATION(Gap);
};

/** \brief  hand shift ― Marks the beginning of a passage written in a new hand, or of a
 *          change in the scribe, writing style, ink or character of the
 *          document hand.
 *
 * The character attribute describes characteristics of the hand, particularly          
 *          those related to the quality of the writing, e.g., 'shaky', 'thick', regular'. A          
 *          description of the tint or type of ink, e.g. 'brown' or the writing medium, e.g.          
 *          'pencil', may be placed in the medium attribute. The new hand may be identified          
 *          using the new attribute, while the previous hand may be recorded in the old          
 *          attribute. The resp attribute contains an ID reference to an element containing          
 *          the name of the editor or transcriber responsible for identifying the change of          
 *          hand. The cert attribute signifies the degree of certainty ascribed to the          
 *          identification of the new hand. This element is modelled on an element in the          
 *          Text Encoding Initiative (TEI)..
 */
struct HandShift : public BaseMeiElement{
    HandShift();
    virtual ~HandShift() {};

    string getCharacterValue() throw (AttributeNotFoundException);

    MeiAttribute* getCharacter() throw (AttributeNotFoundException);
    void setCharacter(string _character);
    bool hasCharacter();

    string getNewValue() throw (AttributeNotFoundException);

    MeiAttribute* getNew() throw (AttributeNotFoundException);
    void setNew(string _new);
    bool hasNew();

    string getOldValue() throw (AttributeNotFoundException);

    MeiAttribute* getOld() throw (AttributeNotFoundException);
    void setOld(string _old);
    bool hasOld();

    CommonMixIn    m_Common;
    MediumMixIn    m_Medium;
    EditMixIn    m_Edit;
    FacsimileMixIn    m_Facsimile;
    private:
        //REGISTER_DECLARATION(HandShift);
};

/** \brief  original ― Contains a reading which is marked as following the original,
 *          rather than being normalized or corrected.
 *
 * This element will often be combined with a regularized form within a choice          
 *          element. The editor(s) responsible for asserting that the material is original          
 *          may be recorded in the resp attribute. The value of resp must point to one or          
 *          more identifiers declared in the document header. The cert attribute signifies          
 *          the degree of certainty ascribed to the transcription of the original text. This          
 *          element is modelled on an element in the Text Encoding Initiative (TEI)..
 */
struct Orig : public BaseMeiElement{
    Orig();
    virtual ~Orig() {};

    CommonMixIn    m_Common;
    TypedMixIn    m_Typed;
    EditMixIn    m_Edit;
    FacsimileMixIn    m_Facsimile;
    private:
        //REGISTER_DECLARATION(Orig);
};

/** \brief  regularization ― Contains a reading which has been regularized or normalized
 *          in some sense.
 *
 * It is possible to identify the individual responsible for the regularization,          
 *          and, using the choice and orig elements, to provide both original and          
 *          regularized readings. The editor(s) responsible for asserting the regularized          
 *          material may be recorded in the resp attribute. The value of resp must point to          
 *          one or more identifiers declared in the document header. The cert attribute          
 *          signifies the degree of certainty ascribed to the regularized reading. This          
 *          element is modelled on an element in the Text Encoding Initiative (TEI)..
 */
struct Reg : public BaseMeiElement{
    Reg();
    virtual ~Reg() {};

    AuthorizedMixIn    m_Authorized;
    CommonMixIn    m_Common;
    NameMixIn    m_Name;
    EditMixIn    m_Edit;
    private:
        //REGISTER_DECLARATION(Reg);
};

/** \brief  restore ― Indicates restoration of musical material to an earlier state by
 *          cancellation of an editorial or authorial marking or instruction.
 *
 * The desc (description) attribute gives a prose description of the means of          
 *          restoration, 'stet' or 'strike-down', for example. The cert attribute signifies          
 *          the degree of certainty ascribed to the identification of the hand of the          
 *          restoration. The type attribute may be used to indicate the action cancelled by          
 *          the restoration. The resp attribute contains an ID reference to an element          
 *          containing the name of the editor or transcriber responsible for identifying the          
 *          hand of the restoration. The hand attribute signifies the hand of the agent          
 *          which made the restoration. This element is modelled on an element in the Text          
 *          Encoding Initiative (TEI)..
 */
struct Restore : public BaseMeiElement{
    Restore();
    virtual ~Restore() {};

    string getDescValue() throw (AttributeNotFoundException);

    MeiAttribute* getDesc() throw (AttributeNotFoundException);
    void setDesc(string _desc);
    bool hasDesc();

    CommonMixIn    m_Common;
    TypedMixIn    m_Typed;
    TransMixIn    m_Trans;
    FacsimileMixIn    m_Facsimile;
    private:
        //REGISTER_DECLARATION(Restore);
};

/** \brief  sic ― Contains apparently incorrect or inaccurate musical material.
 *
 * A correction for the apparent error may be given in an accompanying child or          
 *          sibling corr element. This element is modelled on an element in the Text          
 *          Encoding Initiative (TEI)..
 */
struct Sic : public BaseMeiElement{
    Sic();
    virtual ~Sic() {};

    CommonMixIn    m_Common;
    FacsimileMixIn    m_Facsimile;
    private:
        //REGISTER_DECLARATION(Sic);
};

/** \brief  substitution ― Groups transcriptional elements when the combination is to be
 *          regarded as a single intervention in the text.
 *
 * This element is modelled on an element in the Text Encoding Initiative (TEI)..
 */
struct Subst : public BaseMeiElement{
    Subst();
    virtual ~Subst() {};

    CommonMixIn    m_Common;
    EditMixIn    m_Edit;
    TransMixIn    m_Trans;
    private:
        //REGISTER_DECLARATION(Subst);
};

/** \brief  supplied ― Contains musical material supplied by the transcriber or editor in
 *          place of text which cannot be read, either because of physical
 *          damage or loss in the original or because it is illegible for any reason.
 *
 * When the presumed loss of text arises from an identifiable cause, agent          
 *          signifies the causative agent. When the presumed loss of text arises from action          
 *          (partial deletion, etc.) assignable to an identifiable hand, the hand attribute          
 *          signifies the hand responsible for the action. The reason attribute indicates          
 *          why the text has to be supplied, e.g. 'overbinding', 'faded ink', 'lost folio',          
 *          'omitted in original', etc. The source attribute contains the source of the          
 *          supplied text. The editor(s) responsible for supplied material may be recorded          
 *          in the resp attribute. The value of resp must point to one or more identifiers          
 *          declared in the document header. The cert attribute signifies the degree of          
 *          certainty ascribed to the supplied material. This element is modelled on an          
 *          element in the Text Encoding Initiative (TEI)..
 */
struct Supplied : public BaseMeiElement{
    Supplied();
    virtual ~Supplied() {};

    CommonMixIn    m_Common;
    AgentidentMixIn    m_Agentident;
    ReasonidentMixIn    m_Reasonident;
    EditMixIn    m_Edit;
    FacsimileMixIn    m_Facsimile;
    private:
        //REGISTER_DECLARATION(Supplied);
};

/** \brief  unclear ― Contains musical material that cannot be transcribed with certainty
 *          because it is illegible or inaudible in the source.
 *
 * Where the difficulty in transcription arises from an identifiable cause, the          
 *          agent attribute signifies the causative agent. The cert attribute signifies the          
 *          degree of certainty ascribed to the transcription of the text contained within          
 *          the <unclear> element. Where the difficulty in transcription arises from action          
 *          (partial deletion, etc.) assignable to an identifiable hand, the hand attribute          
 *          signifies the hand responsible for the action. The reason attribute indicates          
 *          why the material is difficult to transcribe. The resp attribute indicates the          
 *          individual responsible for the transcription of the word, phrase, or passage          
 *          contained with the <unclear> element. The value of resp must point to one or          
 *          more identifiers declared in the document header. This element is modelled on an          
 *          element in the Text Encoding Initiative (TEI)..
 */
struct Unclear : public BaseMeiElement{
    Unclear();
    virtual ~Unclear() {};

    CommonMixIn    m_Common;
    HandidentMixIn    m_Handident;
    CritMixIn    m_Crit;
    AgentidentMixIn    m_Agentident;
    ReasonidentMixIn    m_Reasonident;
    EditMixIn    m_Edit;
    TransMixIn    m_Trans;
    FacsimileMixIn    m_Facsimile;
    private:
        //REGISTER_DECLARATION(Unclear);
};

#endif // EDITTRANS_H_