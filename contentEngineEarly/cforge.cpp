/* Most of this is commented out since the classes from
the objects directory don't exist yet.

This part is dependent on the future file structure
#include "../objects/content.hpp"
#include "../objects/argList.hpp"
#include "../objects/bundle.hpp"
#include "../objects/clist.hpp"
#include "../objects/cgroup.hpp"
#include "../objects/wordlist.hpp"
#include "../objects/cguide.hpp" */
#include "cforge.hpp"
#include <iostream>

// Make CForge inside the trailcrest.contentEngine package
namespace trailcrest
{
    CForge::CForge(): mode(0), status("Empty") //, tempObject(NULL)
    {
        // Boot up message in osr
        //osr.BOOT_MSG("Content Engine: Caminus --- ONLINE");

    }

    void CForge::build(std::string newMode)
    {
        //Set object and mode appropriately
        //finalObject = bundle(newMode);
        //mode = finalObject.mode;
    }

    void CForge::deploy()
    {
        mode = 0; //clear the mode
        clearTemp();
    }

    void CForge::loadContent(Content newCont)
    {
        // This if only works if input is statically declared.
        //Dynamic would be "*input"
        //Three if cases in order to set the status
       /* if(newCont.getClass() == "Wordlist")
        {
            tempObject = &newCont;
            status = "Wordlist";
        }
        else if(newCont.getClass() == "Clist")
        {
            tempObject = &newCont;
            status = "Clist";
        }
        else if(newCont.getClass() == "CGroup")
        {
            tempObject = &newCont;
            status = "CGroup";
        }
        else
        {
            osr.BROADCAST("CForge.loadContent[]: Content must be wordlist, clist
                          , or cgroup. loadContent failed.", true);
        }*/
    }
    void CForge::addContent(std::string tag , std::string source  )
    {
        // Can only add to bundle if tempObject has been set
        /*if(tempObject != NULL)
        {
            if(mode != 0)
            {
                //Add the tempObject to the bundle and clear.
                finalObject._addContent(*tempObject, tag, source);
                tempObject = NULL;
                status = "Empty";
            }
            else
            {
                if(source == "Lingua" || source == "Verbum")
                {
                    osr.BROADCAST(source + ".DEPLOY[]: No CForge Bundle has been
                                  built. Deploy failed.", true);
                }
                else
                {
                    osr.BROADCAST("CForge.addContent[]: No CForge Bundle has 
                                  been built. addContent failed.", true);
                }
            }
        }
        else
        {
            osr.BROADCAST("CForge.addContent[]: Can only accept Wordlist, CList, and CGroup objects.", true);
        }*/
    }
    
    void sendCommand(int op, Arglist args)
    {
		//tempObject->rscp(op, args);
	}
	
    int CForge::getMode()
    {
        return mode;
    }

    void CForge::setMode(int newMode)
    {
        mode = newMode;
    }

    void CForge::clearTemp()
    {
        //tempObject = NULL;
        status = "Empty";
    }

    std::string CForge::getStatus()
    {
        return status;
    }
}


