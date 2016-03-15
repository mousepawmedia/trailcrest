#ifndef CFORGE_HPP
#define CFORGE_HPP

/* This part is dependent on the future file structure
#include "../objects/content.hpp"
#include "../objects/argList.hpp"
#include "../objects/bundle.hpp"
#include "../objects/clist.hpp"
#include "../objects/cgroup.hpp"
#include "../objects/wordlist.hpp"
#include "../objects/cguide.hpp" */
#include <iostream>

// Make CForge inside the trailcrest.contentEngine package
namespace trailcrest
{
    class CForge
    {
        public:
            CForge();
            void build(std::string newMode);
            void deploy();
            /*
            * loadContent will take a content type and load it to tempObject
            */
            void loadContent(Content newCont);
            /*
            * addContent will add tempObject to the bundle to be sent to the game.
            * tempObject will be cleared afterwards
            */
            void addContent(std::string tag = "", std::string source = "");
            /*
             * Given a special op code and a list of arguments, CForge will pass
             * the arguments to tempObject's rscp function which will in turn
             * call the function represented by the op code
             */
            void sendCommand(int op, ArgList args);
            int getMode();
            void setMode(int newMode);
            void clearTemp();
            std::string getStatus();
        private:
            //Bundle finalObject;
            int mode;
            //Content* tempObject;
            std::string status;
    };
}

#endif // CFORGE_HPP

