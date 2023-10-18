
#include "colev.h"

void ColEv::addEventListener(const std::string &eventName, EventListener listener)
{
    eventListeners[eventName].push_back(listener);
}

void ColEv::triggerEvent(const std::string &eventName)
{
    if (eventListeners.find(eventName) != eventListeners.end())
    {
        for (const auto &listener : eventListeners[eventName])
        {
            listener();
        }
    }
}