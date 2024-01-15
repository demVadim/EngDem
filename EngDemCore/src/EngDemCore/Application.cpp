#include "EngDemCore/Application.hpp"
#include "EngDemCore/Log.hpp"
#include "EngDemCore/Window.hpp"

#include <iostream>

namespace EngDem 
{
    Application::Application()
    {
        LOG_INFO("Starting application!");
        
        
    }
    Application::~Application()
    {
        LOG_INFO("Closing application!");
    }

    int Application::start(unsigned int window_with, unsigned int window_height, const char *title)
    {
        m_pWindow = std::make_unique<Window>(title, window_with, window_height);

        while(true)
        {
            m_pWindow->on_update();
            on_update();
        }
        return 0;
    }
}

