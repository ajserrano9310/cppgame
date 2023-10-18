#include <iostream>
#include <functional>
#include <unordered_map>

using EventListener = std::function<void>();
class ColEv
{
public:
    void addEventListener(const std::string &eventName, EventListener listener);
    void triggerEvent(const std::string &eventName);
    std::unordered_map<std::string, std::vector<EventListener>> eventListeners;
};