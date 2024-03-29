#pragma once

#include "HazelPVR/Core/Core.hpp"
#include "HazelPVR/Core/Timestep.hpp"
#include "HazelPVR/Events/Event.hpp"

namespace HazelPVR
{
    class HAZELPVR_API Layer
    {
        public:
            explicit Layer(const std::string& name = "Layer");
            virtual ~Layer();

            virtual void OnAttach() {}
            virtual void OnDetach() {}
            virtual void OnUpdate(Timestep ts) {}
            virtual void OnImGuiRender() {}
            virtual void OnEvent(Event& event) {}

            inline const std::string& GetName() const
            {
                return m_DebugName;
            }

        protected:
            std::string m_DebugName;
    };
} // namespace HazelPVR
