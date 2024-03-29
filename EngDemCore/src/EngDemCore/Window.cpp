#include "EngDemCore/Window.hpp"
#include "EngDemCore/Log.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace EngDem 
{
    static bool s_GLFW_initialized = false;

    Window::Window(std::string title, const unsigned int width, const unsigned int height)
        : m_title(std::move(title))
        , m_width(width)
        , m_height(height)
    {
        int resultCode = init();
    }
    Window::~Window()
    {
        shutdown();
    }
    
    
    int Window::init()
    {
        LOG_INFO("Creating window '{0}' width size {1}x{2}", m_title, m_width, m_height);

        if(!s_GLFW_initialized)
        {
            if (!glfwInit())
            {
                LOG_CRITICAL("Can't initialize GLFW!");
                return -1;
            }
            s_GLFW_initialized = true;    
        }
        
        m_pWindow = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
        if (!m_pWindow)
        {
            LOG_CRITICAL("Can't create window {0} width size {1}x{2}", m_title, m_width, m_height);
            glfwTerminate();
            return -1;
        }

        
        glfwMakeContextCurrent(m_pWindow);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            LOG_CRITICAL("Failed to initialize GLAD");
            return -3;
        }

        return 0;
    }


    void Window::shutdown()
    {
        glfwDestroyWindow(m_pWindow);
        glfwTerminate();
    }

    void Window::on_update()
    {
        glClearColor(0,1,0,0);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(m_pWindow);
        glfwPollEvents();
    }

}
