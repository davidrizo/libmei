/*
 *  libmei: Music Encoding Initiative
 *
 *  A simple example to demonstrate using libmei to read an MEI file.
 */

#include <iostream>
using std::cout;
using std::endl;

#include <mei/meielement.h>
#include <mei/meidocument.h>
#include <libxml/xmlreader.h>

int main(int argc, char **argv) {
    vector<MeiNs> ns;
    MeiNs ns1;
    MeiNs ns2;
    
    ns1.href = "http://www.example1.com";
    ns1.prefix = "link";
    
    ns2.href = "http://example12.ca";
    ns2.prefix = "show";
    
    ns.push_back(ns1);
    ns.push_back(ns2);
    
    MeiElement* el = new MeiElement("mei", ns);
    MeiElement neume = MeiElement("neume", ns);
	MeiElement n = MeiElement("note", ns); 
	MeiElement o = MeiElement("octave", ns);
    
    MeiAttribute a1 = MeiAttribute("accid", "s");
    MeiAttribute a2 = MeiAttribute("artic", "stacc");
    MeiAttribute ver = MeiAttribute("meiversion", "2011-04");
    
    MeiAttribute b1 = MeiAttribute("accid", "f");

    n.addAttribute(a1);
    n.addAttribute(a2);
    o.addAttribute(b1);
    
    neume.addChild(n);
	neume.addChild(o);
        
    el->addChild(neume);
   // el->print(4);
    el->addAttribute(ver);
    
    MeiDocument* meidoc = new MeiDocument("example1.xml","UTF-8");
    meidoc->setRootElement(el);
    
    meidoc->WriteToXml(meidoc);
    
   // if (argc > 1) {
    
    MeiDocument* Doc = MeiDocument::ReadFromXml("example1.xml","UTF-8");
    Doc->getRootElement()->print(4);
    
  //  }
	
    
	return 0;
}