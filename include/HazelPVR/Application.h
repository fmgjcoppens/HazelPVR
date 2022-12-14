#pragma once

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"
#include "Events/ApplicationEvent.h"

#include "ImGui/ImGuiLayer.h"

namespace HazelPVR {

    class HAZELPVR_API Application {
    public:
        Application();
        virtual ~Application();
        void Run();
        void onEvent(Event& event);
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);
        inline Window& GetWindow() { return *m_Window; }
        inline static Application& Get() { return *s_Instance; }

    private:
        bool onWindowClose(WindowCloseEvent& event);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack  m_LayerStack;
        static Application* s_Instance;
    };

    // To be defined in the CLIENT
    Application* CreateApplication();

}
